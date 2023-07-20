#include <esp_camera.h>
#include <driver/i2s.h>
#define CAMERA_MODEL_ELECROW
#include "camera_pins.h"
#include <Digital_Light_TSL2561.h>
#include <lvgl.h>
#define LGFX_USE_V1
#include <LovyanGFX.hpp>
#include <SPI.h>
#include <SD.h> 
#include <FS.h>
#include "FT6236.h"
#include <Ticker.h>          //Call the ticker. H Library
Ticker ticker1;
Ticker ticker2;
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

const String apiKey = "SprO-LUwqokJ5EL6w";
const String city = "shenzhen";
DynamicJsonDocument doc(1024);

#define NTP1  "ntp1.aliyun.com"
#define NTP2  "ntp2.aliyun.com"
#define NTP3  "ntp3.aliyun.com"
//填写WIFI入网信息
const char* ssid     = "CHENG";     // WIFI账户
const char* password = "lisihai525"; // WIFI密码
char* ssid1     = "CHENG";     // WIFI账户
char* password1 = "lisihai525"; // WIFI密码
char* ssid2    ;     // WIFI账户
char* password2    ; // WIFI密码
//char* ssid2     = "elecrow888";     // WIFI账户
//char* password2 = "elecrow2014"; // WIFI密码
//#include <Adafruit_Sensor.h>

#include <Wire.h>
#include "paj7620.h"

#include "DHT.h"
//#include <DHT_U.h>
#define DHTPIN 40     // what pin we're connected to

// Uncomment whatever type you're using!
#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT22   // DHT 22  (AM2302)
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

DHT dht(DHTPIN, DHTTYPE);

#include <AudioInI2S.h>
#define SAMPLE_SIZE 1024  // Buffer size of read samples
#define SAMPLE_RATE 44100 // Audio Sample Rate
/* Required defines for audio analysis */
#define BAND_SIZE 8 // powers of 2 up to 64, defaults to 8
#include <AudioAnalysis.h>
AudioAnalysis audioInfo;
// ESP32 S2 Mini
#define BCK_PIN 39             // Clock pin from the mic.
#define WS_PIN 38             // WS pin from the mic.
#define DATA_PIN 41            // Data pin from the mic.
#define CHANNEL_SELECT_PIN -1 // Pin to select the channel output from the mic.
AudioInI2S mic(BCK_PIN, WS_PIN, DATA_PIN, CHANNEL_SELECT_PIN); // defaults to RIGHT channel.

int32_t samples[SAMPLE_SIZE]; // I2S sample data is stored here

//#include"AirQuality.h"
//AirQuality airqualitysensor;
int current_quality = -1;
/*
   If you want to use the LVGL examples,
  make sure to install the lv_examples Arduino library
  and uncomment the following line.
*/
#include <examples/lv_examples.h>
#include <demos/lv_demos.h>
const int i2c_touch_addr = TOUCH_I2C_ADD;


#include <ui.h>
static lv_obj_t * ui_Tem;//
static lv_obj_t * ui_Weather;

#define LCD_MOSI 13
#define LCD_MISO 14 // 12
#define LCD_SCK 12
#define LCD_CS 3
#define LCD_RST -1 // 26
#define LCD_DC 42  // 33
#define LCD_BL 46


#define SDA_FT6236 2
#define SCL_FT6236 1

#define SD_MOSI 13
#define SD_MISO 14
#define SD_SCK 12
#define SD_CS 10

#define G4 392
#define A4 440
#define B4 494
#define C5 523
#define D5 587
#define E5 659
#define F5 698
#define G5 784
int Tone[] = { B4, B4, B4, B4, B4, B4,
               B4, D5, G4, A4, B4,
               C5, C5, C5, C5, C5, B4, B4, B4,
               D5, D5, C5, A4, G4, G5
             };
class LGFX : public lgfx::LGFX_Device
{
    lgfx::Panel_ILI9488 _panel_instance;
    lgfx::Bus_SPI _bus_instance;

  public:
    LGFX(void)
    {
      {
        auto cfg = _bus_instance.config();
        cfg.spi_host = SPI3_HOST;
        cfg.spi_mode = 0;
        cfg.freq_write = 60000000;
        cfg.freq_read = 16000000;
        cfg.spi_3wire = true;
        cfg.use_lock = true;
        cfg.dma_channel = SPI_DMA_CH_AUTO;
        cfg.pin_sclk = LCD_SCK;
        cfg.pin_mosi = LCD_MOSI;
        cfg.pin_miso = LCD_MISO;
        cfg.pin_dc = LCD_DC;
        _bus_instance.config(cfg);
        _panel_instance.setBus(&_bus_instance);
      }

      {
        auto cfg = _panel_instance.config();

        cfg.pin_cs = LCD_CS;
        cfg.pin_rst = LCD_RST;
        cfg.pin_busy = -1;
        cfg.memory_width = 320;
        cfg.memory_height = 480;
        cfg.panel_width = 320;
        cfg.panel_height = 480;
        cfg.offset_x = 0;
        cfg.offset_y = 0;
        cfg.offset_rotation = 0;
        cfg.dummy_read_pixel = 8;
        cfg.dummy_read_bits = 1;
        cfg.readable = true;
        cfg.invert = false;
        cfg.rgb_order = false;
        cfg.dlen_16bit = false;
        cfg.bus_shared = true;
        _panel_instance.config(cfg);
      }

      setPanel(&_panel_instance);
    }
};

LGFX tft;
/*Change to your screen resolution*/
static const uint16_t screenWidth  = 480;
static const uint16_t screenHeight = 320;
static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[ screenWidth * screenHeight / 8 ];


/* Display flushing */
void my_disp_flush( lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p )
{
  uint32_t w = ( area->x2 - area->x1 + 1 );
  uint32_t h = ( area->y2 - area->y1 + 1 );

  tft.startWrite();
  tft.setAddrWindow( area->x1, area->y1, w, h );
  tft.writePixels((lgfx::rgb565_t *)&color_p->full, w * h);
  tft.endWrite();

  lv_disp_flush_ready( disp );
}

void my_touchpad_read( lv_indev_drv_t * indev_driver, lv_indev_data_t * data )
{
  int pos[2] = {0, 0};

  ft6236_pos(pos);
  if (pos[0] > 0 && pos[1] > 0)
  {
    data->state = LV_INDEV_STATE_PR;
    //    data->point.x = tft.width()-pos[1];
    //    data->point.y = pos[0];
    data->point.x = tft.width() - pos[1];
    data->point.y = pos[0];
    //        Serial.printf("x-%d,y-%d\n", data->point.x, data->point.y);
  }
  else {
    data->state = LV_INDEV_STATE_REL;
  }
}


void touch_init()
{
  // I2C init
  Wire.begin(SDA_FT6236, SCL_FT6236);
  byte error, address;

  Wire.beginTransmission(i2c_touch_addr);
  error = Wire.endTransmission();

  if (error == 0)
  {
    Serial.print("I2C device found at address 0x");
    Serial.print(i2c_touch_addr, HEX);
    Serial.println("  !");
  }
  else if (error == 4)
  {
    Serial.print("Unknown error at address 0x");
    Serial.println(i2c_touch_addr, HEX);
  }
}




void setClock() {
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo))
  { //如果获取失败，就开启联网模式，获取时间
    Serial.println("Failed to obtain time");
    //    WiFi.disconnect(false);
    //    WiFi.mode(WIFI_STA);//开启网络
    //
    //    WiFi.begin(ssid1, password1);
    //    while (WiFi.status() != WL_CONNECTED)
    //    {
    //      delay(50);
    //      Serial.print(".");
    //    }
    configTime(8 * 3600, 0, NTP1, NTP2, NTP3);
    return;
  }
  //  Serial.println(&timeinfo, "%R"); // 格式化输出:2021-10-24 23:00:44 Sunday
  //  Serial.print(asctime(&timeinfo));//默认打印格式：Mon Oct 25 11:13:29 2021
  int  time_hour = timeinfo.tm_hour ; //时
  int  time_min = timeinfo.tm_min ;//分

  int  time_year = timeinfo.tm_year ; //年
  int  time_mon = timeinfo.tm_mon ; //月
  int  time_mday = timeinfo.tm_mday ; //日
  int  time_wday = timeinfo.tm_wday ; //星期

  lv_label_set_text_fmt(ui_HOUR, "%d", time_hour);
  lv_label_set_text_fmt(ui_YEAR, "%d", time_year + 1900);
  lv_label_set_text_fmt(ui_MON, "%d", time_mon + 1);
  lv_label_set_text_fmt(ui_DAY, "%d", time_mday);
  switch (time_wday)
  {
    case 1:
      lv_label_set_text(ui_WEEK, "Monday");
      break;
    case 2:
      lv_label_set_text(ui_WEEK, "Tuesday");
      break;
    case 3:
      lv_label_set_text(ui_WEEK, "Wednesday");
      break;
    case 4:
      lv_label_set_text(ui_WEEK, "Thursday");
      break;
    case 5:
      lv_label_set_text(ui_WEEK, "Firday");
      break;
    case 6:
      lv_label_set_text(ui_WEEK, "Saturday");
      break;
    case 0:
      lv_label_set_text(ui_WEEK, "Sunday");
      break;
  }

  switch (time_min)
  {
    case 1:
      lv_label_set_text(ui_MIN, "01");
      break;
    case 2:
      lv_label_set_text(ui_MIN, "02");
      break;
    case 3:
      lv_label_set_text(ui_MIN, "03");
      break;
    case 4:
      lv_label_set_text(ui_MIN, "04");
      break;
    case 5:
      lv_label_set_text(ui_MIN, "05");
      break;
    case 6:
      lv_label_set_text(ui_MIN, "06");
      break;
    case 7:
      lv_label_set_text(ui_MIN, "07");
      break;
    case 8:
      lv_label_set_text(ui_MIN, "08");
      break;
    case 9:
      lv_label_set_text(ui_MIN, "09");
      break;
    case 0:
      lv_label_set_text(ui_MIN, "00");
      break;
  }
  if (time_min > 9)
  {
    lv_label_set_text_fmt(ui_MIN, "%d", time_min);
  }
}

int sensorValue = 0;
float t = 0;
int iic_value = 0;
const int  Flame_Sensor = 11;
static int airvalue = 0;
void callback1()  //Callback function
{
  //  String str1 = "@#";
  //  String str2 = "#";
  //  String str3 = "#@";
  //  Serial.print(str1 + (int)sensorValue + str2 + (int)t + str2 + (int)iic_value + str3);
  //  Serial.println("");
  airvalue = analogRead(20);
  //    Serial.print("airvalue:");
  //    Serial.println(airvalue);

}

char CloseData = 0;
static int NUM = 0;
char buf_lora[128] = {};
int bufindex = 0;
char *info[128] = {};
int Bengin_flag = 0;



//UV
int UVOUT = 1; //Output from the sensor
int REF_3V3 = 2; //3.3V power on the Arduino board

uint8_t data = 0;  // Read Bank_0_Reg_0x43/0x44 for gesture result.

int go_camer_flag = 0;
static int go_home_flag = 0;
int MINI_OR_CAMER = 0;
int open_MINI_flag = 0;

float vuMeter = 0;

unsigned long previousBlinkTime = 0;


float values[5];

int values1[5]; // 保存大于10的值
int numReadings = 0; // 已保存的值的数量

const int numReadings1 = 5; // 设置读取次数
const int maxDiff = 30; // 设置最大误差
int readings[numReadings1]; // 保存读取值的数组
int index1 = 0; // 当前读取值的索引
int total1 = 0; // 读取值的总和
int average1 = 0; // 平均值


String gpsData;                   //定义字符串变量，用于存储GPS数据
void setup()
{
  Serial.begin( 9600 ); /* prepare for possible serial debug */

  Serial.println( "START" );

  //AIR
  pinMode(19, INPUT_PULLUP);
  analogReadResolution(12);
  //pinMode(10, INPUT);
  //  airqualitysensor.init(19);

  //camera
  camera_init();

  //Buzzer
  //  pinMode(45, OUTPUT);
  //  ledcSetup(4, 5000, 8);
  //  ledcAttachPin(45, 4);

  //火焰
  pinMode(Flame_Sensor, INPUT);

   Serial.println( "DHT" );
  //DHT
  dht.begin();
  Serial.println( "DHT11" );
  //MIni
  mic.begin(SAMPLE_SIZE, SAMPLE_RATE); // Starts the I2S DMA port.
  // audio analysis setup
  audioInfo.setNoiseFloor(10);       // sets the noise floor
  audioInfo.normalize(true, 0, 100); // normalize all values to range provided.
  // audioInfo.autoLevel(AudioAnalysis::ACCELERATE_FALLOFF, 1); // uncomment this line to set auto level falloff rate
  audioInfo.bandPeakFalloff(AudioAnalysis::EXPONENTIAL_FALLOFF, 0.05); // set the band peak fall off rate
  audioInfo.vuPeakFalloff(AudioAnalysis::EXPONENTIAL_FALLOFF, 0.05);    // set the volume unit peak fall off rate

  //UV
  //  pinMode(UVOUT, INPUT);
  //  pinMode(REF_3V3, INPUT);

  tft.begin();          /* TFT init */
  tft.setRotation( 3 ); /* Landscape orientation, flipped */
  tft.fillScreen(TFT_BLACK);
  delay(200);
  pinMode(LCD_BL, OUTPUT);
  digitalWrite(LCD_BL, HIGH);


  touch_init();

  lv_init();
  lv_disp_draw_buf_init( &draw_buf, buf, NULL, screenWidth * screenHeight / 8 );

  /*Initialize the display*/
  static lv_disp_drv_t disp_drv;
  lv_disp_drv_init( &disp_drv );
  /*Change the following line to your display resolution*/
  disp_drv.hor_res = screenWidth;
  disp_drv.ver_res = screenHeight;
  disp_drv.flush_cb = my_disp_flush;
  disp_drv.draw_buf = &draw_buf;
  lv_disp_drv_register( &disp_drv );

  /*Initialize the (dummy) input device driver*/
  static lv_indev_drv_t indev_drv;
  lv_indev_drv_init( &indev_drv );
  indev_drv.type = LV_INDEV_TYPE_POINTER;
  indev_drv.read_cb = my_touchpad_read;
  lv_indev_drv_register( &indev_drv );

  ui_init();
  label_xy();
  lv_timer_handler();


  

  Wire.setPins(2, 1);
  Wire.begin();

  //手势
  paj7620Init();
  //LIGHT
  TSL2561.init();

  
  Serial.println( "Setup done" );
  lv_scr_load_anim(ui_Screen3, LV_SCR_LOAD_ANIM_NONE, 0, 2000, false);
  while (login_flag == 0 || login_flag == 2)
  {
    lv_label_set_text(ui_Label8, "Fetching weather...");
    while (login_flag == 0)
    {
      lv_timer_handler();
    }
    ssid1 = (char*)lv_textarea_get_text(ui_account);
    password1 = (char*)lv_textarea_get_text(ui_password);
    if (strcmp(ssid1, "") != 0 && strcmp(password1, "") != 0)
    {
      //WIFI - TIME
      WiFi.disconnect();
      WiFi.mode(WIFI_STA);
      WiFi.begin(ssid1, password1);
      unsigned long currentMillis = millis();
      previousBlinkTime = currentMillis;

      lv_label_set_text(ui_Label8, "Connecting...");
      lv_obj_clear_flag(ui_tip, LV_OBJ_FLAG_HIDDEN);
      while (WiFi.status() != WL_CONNECTED)
      {
        unsigned long currentMillis = millis();
        //检查是否到达时间间隔
        if (currentMillis - previousBlinkTime >= 10000)
        { //如果时间间隔达到了
          login_flag = 0;
          lv_obj_add_flag(ui_tip, LV_OBJ_FLAG_HIDDEN);
          lv_obj_clear_flag(ui_connect, LV_OBJ_FLAG_CLICKABLE);
          lv_obj_clear_flag(ui_Panel1, LV_OBJ_FLAG_HIDDEN);                 
          break;
        }
        else if (currentMillis - previousBlinkTime <= 0)
        { // 如果millis时间溢出
          previousBlinkTime = currentMillis;
        }
        Serial.print(".");
        lv_timer_handler();
        delay(10);
      }
    } else
    {
      login_flag = 0;
      lv_obj_clear_flag(ui_connect, LV_OBJ_FLAG_CLICKABLE);
      lv_obj_clear_flag(ui_Panel1, LV_OBJ_FLAG_HIDDEN);
    }
  }
  Serial.println("WiFi connected!");
  
  lv_textarea_set_text(ui_account, "");
  lv_textarea_set_text(ui_password, "");
  lv_label_set_text(ui_Label8, "Fetching weather...");
  lv_obj_clear_flag(ui_tip, LV_OBJ_FLAG_HIDDEN);
  lv_timer_handler();
  delay(300);
  get_weather();
  lv_label_set_text(ui_Label8, "Fetching time...");
  lv_timer_handler();
  configTime(8 * 3600, 0, NTP1, NTP2, NTP3);
  setClock();
  delay(200);
  Serial.println("Screen");
  lv_obj_add_flag(ui_tip, LV_OBJ_FLAG_HIDDEN);
  lv_scr_load_anim(ui_Screen1, LV_SCR_LOAD_ANIM_NONE, 0, 100, false);


}

void loop()
{
  //***************************************************WIFI_setting********************
  while (login_flag == 0 )
  {
    lv_label_set_text(ui_Label9, "Fetching weather...");
    while (login_flag == 0)
    {
      lv_timer_handler();
    }
    if (login_flag == 1) //如果按下返回
    {
      break;
    }
    ssid2 = (char*)lv_textarea_get_text(ui_account1);
    password2 = (char*)lv_textarea_get_text(ui_password1);
    if (strcmp(ssid2, "") != 0 && strcmp(password2, "") != 0)
    {
      //WIFI - TIME
      WiFi.disconnect();
      WiFi.mode(WIFI_STA);
      //WiFi.begin(ssid2, password2);
      WiFi.begin("C", "12345678");
      unsigned long currentMillis = millis();
      previousBlinkTime = currentMillis;

      lv_label_set_text(ui_Label9, "Connecting...");
      lv_obj_clear_flag(ui_tip2, LV_OBJ_FLAG_HIDDEN);
      while (WiFi.status() != WL_CONNECTED)
      {
        unsigned long currentMillis = millis();
        //Check for arrival time interval
        if (currentMillis - previousBlinkTime >= 10000)
        { //If the time interval is reached
          login_flag = 0;
          lv_obj_add_flag(ui_tip2, LV_OBJ_FLAG_HIDDEN);
          lv_obj_clear_flag(ui_connect1, LV_OBJ_FLAG_CLICKABLE);
          lv_obj_clear_flag(ui_Panel2, LV_OBJ_FLAG_HIDDEN);                  
          break;
        }
        else if (currentMillis - previousBlinkTime <= 0)
        { // If the millis time overflow
          previousBlinkTime = currentMillis;
        }
        Serial.print(".");
        lv_timer_handler();
        delay(20);
      }
      if (WiFi.status() == WL_CONNECTED)
      {
        Serial.println("WiFi connected!");
        //      lv_textarea_set_text(ui_account, "");
        //      lv_textarea_set_text(ui_password, "");    
        lv_label_set_text(ui_Label9, "Fetching weather...");   
        lv_obj_clear_flag(ui_tip2, LV_OBJ_FLAG_HIDDEN);
        lv_timer_handler();
        delay(300);
        get_weather();
        lv_label_set_text(ui_Label9, "Fetching time...");
        lv_timer_handler();
        configTime(8 * 3600, 0, NTP1, NTP2, NTP3);
        setClock();
        delay(250);
        lv_obj_add_flag(ui_tip2, LV_OBJ_FLAG_HIDDEN);       
        lv_scr_load_anim(ui_Screen1, LV_SCR_LOAD_ANIM_NONE, 0, 0, false);
        login_flag = 1;
        
      }
    } else
    {
      login_flag = 0;
      lv_obj_clear_flag(ui_connect1, LV_OBJ_FLAG_CLICKABLE);
      lv_obj_clear_flag(ui_Panel2, LV_OBJ_FLAG_HIDDEN);
    }
  }

  //***************************************************TIME********************
  setClock();


  //***************************************************MINI********************

  mic.read(samples); // Stores the current I2S port buffer into samples.
  audioInfo.computeFFT(samples, SAMPLE_SIZE, SAMPLE_RATE);
  audioInfo.computeFrequencies(BAND_SIZE);

  //  vuMeter = audioInfo.getVolumeUnit();
  //  Serial.print("vuMeter:");
  //  Serial.println(vuMeter);
  // 获取十个float值
  for (int i = 0; i < 5; i++) {
    values[i] = audioInfo.getVolumeUnit(); // 自定义获取float值的函数
  }
  // 找到最大值和最小值的索引
  int maxIndex = 0;
  int minIndex = 0;
  for (int i = 1; i < 5; i++) {
    if (values[i] > values[maxIndex]) {
      maxIndex = i;
    }
    if (values[i] < values[minIndex]) {
      minIndex = i;
    }
  }
  // 计算去掉最大值和最小值后的平均值
  float sum = 0;
  for (int i = 0; i < 5; i++) {
    if (i != maxIndex && i != minIndex) { // 如果不是最大值和最小值
      sum += values[i];
    }
  }
  float average = sum / 3; // 除以8，因为去掉了两个值
    Serial.print("average:");
    Serial.println(average);
  if ((int)average > 0 && (int)average < 5)
  {
    open_MINI_flag = 1;
  }
  if ((int)average > 45 && (int)average < 80 && open_MINI_flag == 1)
  {
    MINI_OR_CAMER = 1;
    go_camer_flag = 1;
    lv_scr_load_anim(ui_Screen2, LV_SCR_LOAD_ANIM_NONE, 0, 0, false);
    lv_timer_handler();
  }

  //***************************************************手势********************
  data = 0;
  paj7620ReadReg(0x43, 1, &data);
  if (data == GES_UP_FLAG)
  {
    Serial.println("GES_UP_FLAG");
  }
  if (data == GES_DOWN_FLAG)
  {
    Serial.println("GES_DOWN_FLAG");
  }
  if (data == GES_FORWARD_FLAG)
  {
    Serial.println("GES_FORWARD_FLAG");
  }
  if (data == GES_BACKWARD_FLAG)
  {
    Serial.println("GES_BACKWARD_FLAG");
  }
  //CAMER
  if ((data == GES_RIGHT_FLAG ||data == GES_LEFT_FLAG)&& MINI_OR_CAMER == 0)
  {
    Serial.println("GES_RIGHT_FLAG");
    go_camer_flag = 1;
    lv_scr_load_anim(ui_Screen2, LV_SCR_LOAD_ANIM_NONE, 0, 0, false);
    lv_timer_handler();
  }
  //HOME
//  if (data == GES_LEFT_FLAG )
//  {
//    Serial.println("GES_LEFT_FLAG");
//  }
//  if (data == GES_LEFT_FLAG && go_home_flag == 0)
//  {
//    go_home_flag = 1;
//    lv_scr_load_anim(ui_Screen1, LV_SCR_LOAD_ANIM_NONE, 0, 0, false);
//  }
  lv_timer_handler();


  //***************************************************摄像头********************
  while (go_camer_flag == 1)
  {
    camera_fb_t *fb = NULL;
    fb = esp_camera_fb_get();
    tft.pushImage(0, 0, fb->width , fb->height, (lgfx::swap565_t *)fb->buf); //75,40
    esp_camera_fb_return(fb);

    data = 0;
    paj7620ReadReg(0x43, 1, &data);
    if (data == GES_LEFT_FLAG||data == GES_RIGHT_FLAG)
    {
      Serial.println("BACK TO GES_LEFT_FLAG");
      go_camer_flag = 0;
      go_home_flag = 2;
      MINI_OR_CAMER = 0;
      lv_scr_load_anim(ui_Screen1, LV_SCR_LOAD_ANIM_NONE, 0, 0, false);
      lv_timer_handler();
      esp_camera_fb_return(fb);
      break;
    }
    lv_timer_handler();
  }


  //***************************************************flame********************
  if (digitalRead( Flame_Sensor)) {
    lv_label_set_text(ui_FIRE, "Normal");
  }
  else {
    lv_label_set_text(ui_FIRE, "Abnormal");
  }



  //*****************************temperature and humidity********************
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);
  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    return;
  }
  lv_label_set_text_fmt(ui_TEM, "%d", (int)t);
  lv_label_set_text_fmt(ui_HUM, "%d", (int)h);
  lv_timer_handler();



  //***************************************************UV********************
  lv_label_set_text_fmt(ui_UV, "%d", (int)TSL2561.readVisibleLux());
  
  //***************************************************lvgl refresh********************
  lv_timer_handler(); /* let the GUI do its work */
//  delay(10);
  int reading = analogRead(19); // 
  total1 -= readings[index1]; // 
  readings[index1] = reading; //
  total1 += reading; // 
  index1 = (index1 + 1) % numReadings1; 

  if (index1 == 0) { //
    average1 = total1 / numReadings1; 
    bool useAverage = true; // 

    for (int i = 0; i < numReadings1; i++) {
      int diff = abs(readings[i] - average1); // 计算差值的绝对值
      if (diff > maxDiff) { // 如果差值大于最大误差
        useAverage = false; // 不使用平均值
        break; // 跳出循环
      }
    }

    if (useAverage) { 
      lv_label_set_text_fmt(ui_AIR, "%d", average1);
    } else {
      //      Serial.println("Values not within range"); // 输出错误信息
    }
  }
  //***************************************************UART********************
  while (Serial.available() > 0) {   //如果软串口有数据可读
    char c = Serial.read();           //读取一个字符
    if (c == '\n') {
      //如果读取到换行符，说明读取到了一行数据
      if (gpsData.startsWith("$GNGGA")) { //如果是$GNGGA数据行
        Serial.println("Receiving...");
        int commaIndex1 = gpsData.indexOf(',');  //查找第一个逗号位置
        int commaIndex2 = gpsData.indexOf(',', commaIndex1 + 1); //查找第二个逗号位置
        int commaIndex3 = gpsData.indexOf(',', commaIndex2 + 1); //查找第三个逗号位置
        int commaIndex4 = gpsData.indexOf(',', commaIndex3 + 1); //查找第四个逗号位置
        int commaIndex5 = gpsData.indexOf(',', commaIndex4 + 1); //查找第五个逗号位置
        if (commaIndex3 > commaIndex2 + 1 && commaIndex5 > commaIndex4 + 1) { //确保逗号之间有数据
          float latitude = gpsData.substring(commaIndex2 + 1, commaIndex3).toFloat(); //提取纬度信息并转换为浮点数
          float longitude = gpsData.substring(commaIndex4 + 1, commaIndex5).toFloat(); //提取经度信息并转换为浮点数
          Serial.print("LatitudeLatitudeLatitudeLatitude: ");  //输出纬度信息
          Serial.println(latitude / 100);
          Serial.print("LongitudeLongitudeLongitudeLongitude: "); //输出经度信息
          Serial.println(longitude / 100);
          char value[20];  // 定义一个字符数组来存储转换后的字符串
          sprintf(value, "%.2f", latitude / 100); // 将浮点数转换为字符串，保留两位小数
          char *integer_part_str = strtok(value, ".");  // 使用 "." 作为分隔符，取出整数部分的字符串
          char *decimal_part_str = strtok(NULL, ".");  // 取出小数部分的字符串
          int integer_part = atoi(integer_part_str);  // 将整数部分的字符串转换为整数类型
          int decimal_part = atoi(decimal_part_str);  // 将小数部分的字符串转换为整数类型


          char value2[20];  // 定义一个字符数组来存储转换后的字符串
          sprintf(value2, "%.2f", longitude / 100); // 将浮点数转换为字符串，保留两位小数
          char *integer_part_str2 = strtok(value2, ".");  // 使用 "." 作为分隔符，取出整数部分的字符串
          char *decimal_part_str2 = strtok(NULL, ".");  // 取出小数部分的字符串
          int integer_part2 = atoi(integer_part_str2);  // 将整数部分的字符串转换为整数类型
          int decimal_part2 = atoi(decimal_part_str2);  // 将小数部分的字符串转换为整数类型

          lv_label_set_text_fmt(ui_E1, "%d", integer_part);
          lv_label_set_text_fmt(ui_E2, "%d", decimal_part);
          lv_label_set_text_fmt(ui_N1, "%d", integer_part2);
          lv_label_set_text_fmt(ui_N2, "%d", decimal_part2);

        }
      }
      gpsData = ""; //清空GPS数据
    } else {
      gpsData += c; //将字符添加到GPS数据中
    }
  }
}

//获取天气
int get_weather(void)
{
  HTTPClient http;
  String url = "https://api.seniverse.com/v3/weather/now.json?key=" + apiKey + "&location=" + city + "&language=en&unit=c";

  // HTTPClient init
  http.begin(url);

  // start get
  int http_code = http.GET();

  // handle http code
  if (http_code !=  HTTP_CODE_OK) {
    Serial.printf("GET fail, http code is %s\n", http.errorToString(http_code).c_str());
    return -1;
  }

  // http response
  String response = http.getString();
  //    Serial.printf("response:[%s]\n", response.c_str());

  // extract weather
  deserializeJson(doc, response);
  JsonObject root = doc.as<JsonObject>();
  JsonArray results = root["results"];

  // location
  //    JsonObject location = results[0]["location"];
  //    const char *path = location["path"];
  //    Serial.println(path);

  // now
  JsonObject now = results[0]["now"];
  const char *text = now["text"];
  //    const char *temperature = now["temperature"];
  Serial.println(text);
  lv_label_set_text(ui_Weather, text);
  //    Serial.println(temperature);
  //    // last_update
  //    const char *last_update = results[0]["last_update"];
  //    Serial.println(last_update);

  // close http
  http.end();

  return 0;
}

//Returns the average
int averageAnalogRead(int pinToRead)
{
  byte numberOfReadings = 8;
  unsigned int runningValue = 0;
  for (int x = 0 ; x < numberOfReadings ; x++)
    runningValue += analogRead(pinToRead);
  runningValue /= numberOfReadings;
  return (runningValue);
}

//The Arduino Map function but for floats
float mapfloat(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}


//触摸Label控件
void label_xy()
{
  ui_Weather = lv_label_create(ui_Screen1);
  lv_obj_enable_style_refresh(true);
  lv_obj_set_width(ui_Weather, LV_SIZE_CONTENT);   /// 1
  lv_obj_set_height(ui_Weather, LV_SIZE_CONTENT);    /// 1
  lv_obj_set_x(ui_Weather, 143);
  lv_obj_set_y(ui_Weather, -35);
  lv_obj_set_align(ui_Weather, LV_ALIGN_CENTER);
  lv_obj_set_style_text_color(ui_Weather, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_opa(ui_Weather, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_font(ui_Weather, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_label_set_text(ui_Weather, "Cloudy");

  lv_label_set_text(ui_A, "'");

  lv_label_set_text(ui_B, "E");

  lv_label_set_text(ui_C, "'");

  lv_label_set_text(ui_D, "N");
}


//Camera setting
void camera_init()
{
  // camera config
  camera_config_t config;
  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer = LEDC_TIMER_0;
  config.pin_d0 = Y2_GPIO_NUM;
  config.pin_d1 = Y3_GPIO_NUM;
  config.pin_d2 = Y4_GPIO_NUM;
  config.pin_d3 = Y5_GPIO_NUM;
  config.pin_d4 = Y6_GPIO_NUM;
  config.pin_d5 = Y7_GPIO_NUM;
  config.pin_d6 = Y8_GPIO_NUM;
  config.pin_d7 = Y9_GPIO_NUM;
  config.pin_xclk = XCLK_GPIO_NUM;
  config.pin_pclk = PCLK_GPIO_NUM;
  config.pin_vsync = VSYNC_GPIO_NUM;
  config.pin_href = HREF_GPIO_NUM;
  config.pin_sscb_sda = SIOD_GPIO_NUM;
  config.pin_sscb_scl = SIOC_GPIO_NUM;
  config.pin_pwdn = PWDN_GPIO_NUM;
  config.pin_reset = RESET_GPIO_NUM;
  config.xclk_freq_hz = 20000000;
//  config.grab_mode = CAMERA_GRAB_LATEST;
  config.pixel_format = PIXFORMAT_RGB565;
  //  config.frame_size = FRAMESIZE_QVGA;
  config.frame_size = FRAMESIZE_HVGA;

  config.jpeg_quality = 10;
  config.fb_count = 4;

  // camera init
  esp_err_t err = esp_camera_init(&config);
  if (err != ESP_OK)
  {
    Serial.printf("Camera init failed with error 0x%x", err);
    while (1)
      ;
  }

  sensor_t *s = esp_camera_sensor_get();
  // initial sensors are flipped vertically and colors are a bit saturated
  if (s->id.PID == OV2640_PID)
  {
    s->set_vflip(s, 0);   // vertical flip
    s->set_hmirror(s, 1); // Horizontal mirror

    s->set_brightness(s, 0); // up the blightness just a bit
    s->set_saturation(s, 1); // lower the saturation
  }
  // drop down frame size for higher initial frame rate
  s->set_framesize(s, FRAMESIZE_HVGA);

}
