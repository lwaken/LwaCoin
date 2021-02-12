/*
  
*/
byte cursor = 0;
  char cursor_symbol = '>';

String settings_lines[4]{
  "Clear memory",
  "Calibrate",
  "Goal",
  "test 4"
};

#define NONE        0
#define NORMAL      1
#define CALIBRATION 2
#define SETTINGS    3
#define ERROR       4
#define DEBUG       5
#define CLEAR       6
#define STATS       7

#define CLEAR_MEMORY  0
#define CALIBRATE     1
#define GOAL          2
#define TEST4         3


byte prev_mode = NONE;
byte mode = NORMAL;


const uint8_t logo[] PROGMEM = {
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0x03, 0x01, 0xE0, 0xF0, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0x78, 0x78, 0x78, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF0, 0x00, 0x01, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0x0F, 0x0F, 0x1F, 0xFF, 0xFF, 0x7F, 0x1F, 0x0F, 0x0F, 0x1F, 0x3F, 0xFF, 0x7F, 0x1F, 0x0F, 0x0F, 0x0F, 0xBF, 0xFF, 0x3F, 0x3F, 0x1F, 0x1F, 0x0F, 0x0F, 0x0F, 0x1F, 0x1F, 0x3F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x80, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x1F, 0xFF, 0xFC, 0xF0, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x80, 0xE0, 0xF0, 0xC0, 0x00, 0x01, 0x00, 0x00, 0xC0, 0xF0, 0xFE, 0xFF, 0xE0, 0x80, 0x80, 0x00, 0x00, 0x0E, 0x0E, 0x0E, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x7F, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xE0, 0xF0, 0xF8, 0x78, 0x7C, 0x3C, 0x3C, 0x3C, 0x7C, 0x78, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x1F, 0x7F, 0xFF, 0xFF, 0xE1, 0xC0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x70, 0xFC, 0xFE, 0xFF, 0x8F, 0x87, 0x07, 0x8F, 0xFF, 0xFF, 0xFE, 0xF8, 0x00, 0xFE, 0xFF, 0xFF, 0xFF, 0x0F, 0x07, 0x07, 0x00, 0xFE, 0xFF, 0xFF, 0xFF, 0x8F, 0x87, 0x87, 0x8F, 0xFF, 0xFF, 0xFE, 0xF8, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0x00, 0x00, 0x01, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0x01, 0x00, 0x00, 0x03, 0x07, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x7F, 0xFF, 0xFF, 0x7F, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0, 0xC0, 0x80, 0x87, 0x0F, 0x1F, 0x1E, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1E, 0x1F, 0x0F, 0x0F, 0x80, 0xC0, 0xE0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
};


//-------НАСТРОЙКИ---------
#define coin_amount 4    // число монет, которые нужно распознать
float coin_value[coin_amount] = {1, 2, 5, 10};  // стоимость монет
String currency = "rub"; // валюта (английские буквы!!!)
int stb_time = 10000;    // время бездействия, через которое система уйдёт в сон (миллисекунды)
//int screen_time = 10000;
String label = "сумма"; //надпись над суммой
//-------НАСТРОЙКИ---------

#define USE_MICRO_WIRE

byte amount = 0;
#define calib_iter 1 
int coin_signal_min[coin_amount];
int coin_signal_max[coin_amount];
int coin_signal_array[coin_amount][calib_iter]; //массив калибровочных значений для вычисления среднего
int coin_quantity[coin_amount];  // количество монет
byte empty_signal;               // храним уровень пустого сигнала
unsigned long standby_timer, reset_timer, screen_timer, clock_timer; // таймеры
int summ_money = 0;            // сумма монет в копилке
int money_quantity = 0;
<<<<<<< Updated upstream
byte delt = 60;                  //трешхолд значения с датчика
byte empty_treshold = 5;
=======
byte delt = 50;                  //трешхолд значения с датчика
byte empty_treshold = 3;
>>>>>>> Stashed changes
byte coin_pass = 4;
boolean calibrated = false;

//-------БИБЛИОТЕКИ---------//
#include "LowPower.h"
#include "EEPROMex.h"
#include "GyverButton.h"
//#include "Wire.h"
#include "GyverOLED.h"
//#include "GyverPower.h"
//-------БИБЛИОТЕКИ---------//

boolean recogn_flag = false;
volatile boolean sleep_flag = false;

//-------ПИНЫ---------//
#define BTN 2            // кнопка
#define BTNpower 5       // питание кнопки
#define disp_power 9     // питание дисплея
#define LEDpin 11        // питание светодиода
#define IRpin A3         // питание фототранзистора
#define IRsens A0        // сигнал фототранзистора
//-------ПИНЫ---------//

GButton btn(BTN, LOW_PULL, NORM_OPEN);        //создать кнопку

GyverOLED<SSD1306_128x64> dsp; //создать дисплей

int sens_signal, last_sens_signal;
boolean coin_flag = false;
boolean coin_recogn = false;
boolean first_start = false;
boolean serial_debug = false;
boolean debug = false;
//boolean is_goal = false;
//int goal = 100;

byte last_coin = 0;




void setup() {
  //power.setSystemPrescaler(PRESCALER_2);
  Serial.begin(9600);                   // открыть порт для связи с ПК для отладки
  //Serial.setTimeout(100);
  
<<<<<<< Updated upstream
  //delay(500);
=======
  delay(100);
>>>>>>> Stashed changes

  //btn.setTimeout(300);
  
  attachInterrupt(0, isr, RISING);

  // пины питания как выходы
  //pinMode(9, OUTPUT);
  pinMode(disp_power, OUTPUT);
  pinMode(BTNpower, OUTPUT);
  pinMode(LEDpin, OUTPUT);
  pinMode(IRpin, OUTPUT);

  // подать питание на дисплей и датчик
  digitalWrite(disp_power, 1);
  digitalWrite(LEDpin, 1);
  digitalWrite(IRpin, 1);
  digitalWrite(BTNpower, 1);

<<<<<<< Updated upstream
  delay(1000);
  
  
  empty_signal = analogRead(IRsens);  // считать пустой (опорный) сигнал
 // Serial.println(empty_signal);
=======
  delay(100);
>>>>>>> Stashed changes
  

  dsp.init();

  Wire.setClock(600000L);

  dsp.autoPrintln(false);
  dsp.clear();
  dsp.update();
  dsp.flipV(1);
  dsp.flipH(1);
  dsp.setContrast(255);
  //dsp.setCursor(0,0);
  //dsp.setScale(3);
  dsp.drawBitmap(31, 0, logo, 64, 64, 1);
  dsp.update();

  calibrated = EEPROM.readInt(2);
  //Serial.print("calibrated - ");
  //Serial.println(calibrated);
  
  for (byte i = 0; i < coin_amount; i++) {
    coin_signal_min[i] = EEPROM.readInt(40 + i * 2);
    coin_signal_max[i] = EEPROM.readInt(60 + i * 2);
    
    coin_quantity[i] = EEPROM.readInt(20 + i * 2);
    summ_money += coin_quantity[i] * coin_value[i];  // ну и сумму сразу посчитать, как произведение цены монеты на количество
    money_quantity += coin_quantity[i];

  }
  Serial.print("SUMM: ");
  Serial.print(summ_money);
  Serial.print(" ");
  Serial.println(currency);
<<<<<<< Updated upstream
  //Serial.println(money_quantity);
  //dsp.setFont(&FreeMonoBold9pt7b);
  //dsp.clearDisplay();
  //dsp.fillScreen(1);

  dsp.init();

  Wire.setClock(400000L);
  
  dsp.clear();
  dsp.update();
  dsp.flipV(1);
  dsp.flipH(1);
  delay(500);

  //dsp.setCursor(0,0);
  //dsp.setScale(3);
  dsp.drawBitmap(0, 0, logo, 128, 64, 1);
  dsp.update();

  delay(4000);
=======
  delay(1000);
>>>>>>> Stashed changes
  
  summ();

  standby_timer = millis();  // обнулить таймер ухода в сон
  clock_timer = millis();
  empty_signal = analogRead(IRsens);
}

void loop() {  
<<<<<<< Updated upstream

=======
>>>>>>> Stashed changes
  
  last_sens_signal = empty_signal;
  while (1) {

   // Serial.println("tick");
    
    btn.tick();
    if (btn.state() && sleep_flag){
      //delay(100);
      wake_up();
    }
    if (btn.state()){
      standby_timer = millis();
    }
    //btn.tick();
    if (btn.isHolded()){
      Serial.println("HOLDED");
      if (mode==SETTINGS){
        switch (cursor){
          case CLEAR_MEMORY:
            Serial.println("CLEAR_MEMORY");
            clearCoins();
            mode = NORMAL;
            break;
          case CALIBRATE:
            Serial.println("CALIBRATE");
            calibrate();
            mode = NORMAL;
            summ();
            break;
          case GOAL:
            Serial.println(cursor);
            break;
          case TEST4:
            Serial.println(cursor);
            break;
        }
        
      }
    }
    if (btn.isTriple()){
      Serial.println("TRIPLE");
      //calibrate();
      if (mode == SETTINGS){
        mode = NORMAL;
        summ();
      }
      else {
        mode = SETTINGS;
        settings();
      }
      
    }
    if (btn.isSingle()){
      Serial.println("SINGLE");
      if (mode==DEBUG){
        Serial.println("ban");
        mode = NORMAL;
        summ();
      }
      else if (mode==SETTINGS){
        settings(1);
        Serial.println("CRSR UPD");
      }
    }
    /*if (btn.getClicks() == 5 && mode==NORMAL){
      //delay(100);
      mode = DEBUG;
      debug = true;
    }*/



    
    //btn.tick();
    /*if (btn.isDouble()){
      
      delay(100);
      Serial.println("//");
      for (byte i = 0; i < coin_amount; i++) {
        Serial.print(round(coin_value[i]));
        Serial.print(" : ");
        Serial.println(coin_quantity[i]);
        }
      Serial.println("//");
    }*/
    sens_signal = analogRead(IRsens);  // далее такой же алгоритм, как при калибровке
    //Serial.println(sens_signal);
    if (sens_signal > last_sens_signal && sens_signal - empty_signal > 6) last_sens_signal = sens_signal;
    if (sens_signal - empty_signal > coin_pass) coin_flag = true;

    if (mode == NORMAL){
    dsp.rect(0,0,24,15, OLED_CLEAR);
    dsp.setScale(2);
    dsp.setCursor(0, 0);
    dsp.print(coin_flag);
    btn.tick();
    dsp.print(btn.state());
    dsp.update();
    }
    /*switch (mode){
      case NORMAL:
        break;
      case NONE:
        break;
      case STATS:
        break;
      case DEBUG:
        break;
    }*/

    //Serial.println("A");
    
    
    
    if (coin_flag && (abs(sens_signal - empty_signal)) < empty_treshold) {
      recogn_flag = false;  // флажок ошибки
      // в общем нашли максимум для пролетевшей монетки, записали в last_sens_signal
      // далее начинаем сравнивать со значениями для монет, хранящимися в памяти
      //Serial.println(last_sens_signal);

      
      
      for (byte i = 0; i < coin_amount; i++) {

        if ((last_sens_signal < coin_signal_min[i]
          and coin_signal_min[i] - last_sens_signal <= delt)
          or 
          (last_sens_signal > coin_signal_max[i]
          and last_sens_signal - coin_signal_max[i] <= delt)
          or
          (last_sens_signal >= coin_signal_min[i] and last_sens_signal <= coin_signal_max[i])
          ){
            // и вот тут если эта разность попадает в диапазон, то считаем монетку распознанной
          summ_money += coin_value[i];  // к сумме тупо прибавляем цену монетки (дада, сумма считается двумя разными способами. При старте системы суммой всех монет, а тут прибавление
          last_coin = coin_value[i];
          //Serial.println(last_sens_signal);
          //Serial.println(coin_value[i]);
          Serial.print("+ ");
          Serial.print(coin_value[i]);
          Serial.print(" SUMM: ");
          Serial.print(summ_money);
          Serial.print(" ");
          Serial.println(currency);

          Serial.println(mode);
          
          if (mode == NORMAL)summ();
          
          coin_quantity[i]++;  // для распознанного номера монетки прибавляем количество
          EEPROM.updateInt(20 + i * 2, coin_quantity[i]);
          
          recogn_flag = true;
          break;
        }
      }
      if (!recogn_flag){
        Serial.print("ERROR coin not recognised: ");
        Serial.println(last_sens_signal);
      }
      coin_flag = false;
      standby_timer = millis();  // сбросить таймер
      break;
    }
    //if (wake_up_flag){
      
    //}
    // если ничего не делали, время таймера вышло, спим
    if (millis() - standby_timer > stb_time && !sleep_flag) {
      sleep();
    } 
    
    
  } 

  
}




void summ() {
  dsp.clear();
  //dsp.setTextColor(1);
  dsp.setScale(2);
  dsp.setCursor((128 - 5*12)/2, 1);
  dsp.print(label);
  dsp.setScale(4);
  dsp.setCursor((128 - numDigits(summ_money)*24)/2, 3);
  dsp.print(summ_money);
  dsp.setScale(2);
  Serial.println(128 - numDigits(last_coin)*14);
  dsp.setCursor(126 - numDigits(last_coin)*12, 0);
  dsp.print(last_coin);
  dsp.update();
}

int numDigits(int number) {
    int digits = 0;
    if (number == 0) digits = 1; // remove this line if '-' counts as a digit
    while (number) {
        number /= 10;
        digits++;
    }
    return digits;
}


// функция сна
void sleep() {
  mode = NORMAL;
  //for (byte i=255; i>0; i--){
  //  dsp.setContrast(i);
  //  delay(50);
  //}
  dsp.clear();
  dsp.update();
  dsp.setPower(0);
  digitalWrite(LEDpin, 0);
  digitalWrite(IRpin, 0);
  sleep_flag = true;
  Serial.println("SLIIIIIP");
  delay(100);
  LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);
}

void wake_up() {
  dsp.setPower(1);
  //standby_timer = millis();
  //wake_up_flag = true;
  Serial.println("WAKEEEEE UPPPPP");
  sleep_flag = false;
  digitalWrite(LEDpin, 1);
  digitalWrite(IRpin, 1);
  //for (byte i=0; i<255; i++){
  //dsp.setContrast(255);
  //  delay(10);
  //}
  Serial.println("WU2");
  standby_timer = millis();
  Serial.println("WU3");
  summ();
  Serial.println("SINGLE WAKE UP");
}

void calibrate(){
  Serial.println("Calibrating");
  //delay(500);
  dsp.clear();
  dsp.setScale(2);
  dsp.setCursor((128 - 10*12)/2,3);
  dsp.print("Калибровка");
  dsp.update();
  delay(500);
  while (1){
    for (byte i = 0; i < coin_amount; i++){
      //coin_signal[i] = 0;
      for (byte j = 0; j < calib_iter; j++){
        Serial.print("Insert ");
        Serial.print(coin_value[i]);
        Serial.print(" ");
        Serial.println(currency);
        last_sens_signal = empty_signal;
        dsp.setScale(2);
        dsp.clear();
        
        dsp.setCursor( (128 - 12*8)/2, 2);
        dsp.print("Вставьте");
        dsp.setScale(3);
        dsp.setCursor( (128 - 18 * (numDigits(coin_value[i])))/2, 4);
        dsp.print(int(coin_value[i]));
        //dsp.print(" ");
        //dsp.print(currency);
        dsp.update();
        while (1) {
          //btn.tick();
          //if (btn.state()){
          //  break;
          //}
          sens_signal = analogRead(IRsens);                                    // считать датчик
          if (sens_signal > last_sens_signal) last_sens_signal = sens_signal;  // если текущее значение больше предыдущего
          if (sens_signal - empty_signal > coin_pass) coin_flag = true;                // если значение упало почти до "пустого", считать что монета улетела
          if (coin_flag && (abs(sens_signal - empty_signal)) < empty_treshold) {            // если монета точно улетела
            
            coin_signal_array[i][j] = last_sens_signal; // записать максимальное значение в память
            //dsp.setScale(2);
            dsp.clear();
            dsp.setScale(2);
            dsp.setCursor( (128 - 12*8)/2, 2);
            dsp.print("Вставьте");
            dsp.setScale(3);
            dsp.setCursor(44, 4);
            dsp.print("OK");
            dsp.update();

            Serial.println("OK");
            
            delay(500);
            coin_flag = false;
            break;
          }
        }
      }
      coin_signal_max[i] = coin_signal_array[i][0];
      coin_signal_min[i] = coin_signal_array[i][0];

      for (int k = 0; k < calib_iter; ++k){
        if (coin_signal_array[i][k] < coin_signal_min[i]){
          coin_signal_min[i] = coin_signal_array[i][k];
        }
      }
      for (int k = 0; k < calib_iter; ++k){
        if (coin_signal_array[i][k] > coin_signal_max[i]){
          coin_signal_max[i] = coin_signal_array[i][k];
        }
      }

      //Serial.print("min ");
      //Serial.println(coin_signal_min[i]);
      
      //Serial.print("max ");
      //Serial.println(coin_signal_max[i]);
      //Serial.print(" - ");
      //Serial.println(coin_value[i]);

      EEPROM.updateInt(40 + i * 2, coin_signal_min[i]);
      EEPROM.updateInt(60 + i * 2, coin_signal_max[i]);

      calibrated = true;
      EEPROM.updateInt(2, true);

      standby_timer = millis();
    }
    break;
  }
  
  //reset_timer = millis();
  //dsp.rect(0, 16, 128, 64 - 26, OLED_CLEAR);
  dsp.clear();
  dsp.setScale(2);
  //dsp.setCursor(30, 42);
  dsp.setCursor((127 - 6 * 12)/2, 4);
  dsp.print("Готово");
  dsp.update();
  delay(500);
  summ();
  Serial.println("Calibration done");
}

void clearCoins(){
  for (byte i = 0; i < coin_amount; i++) {
        coin_quantity[i] = 0;
       EEPROM.writeInt(20 + i * 2, 0);
       summ_money = 0;
      }
  dsp.clear();
  dsp.setScale(2);
  dsp.setCursor((128-12*6)/2, 2);
  dsp.print("Память");
  dsp.setCursor((128-12*7)/2, 4);
  dsp.print("Очищена");
  dsp.update();
  delay(500);
  Serial.println("Memory cleared");
  summ();
}

<<<<<<< Updated upstream
int numDigits(int number)
{
    int digits = 0;
    if (number < 0) digits = 0; // remove this line if '-' counts as a digit
    while (number) {
        number /= 10;
        digits++;
    }
    return digits;
}
=======


>>>>>>> Stashed changes


void isr() {
  btn.tick();  // опрашиваем в прерывании, чтобы поймать нажатие в любом случае
  //if (sleep_flag){
  //sleep_flag = false;
  //wake_up_flag = true;
  //Serial.println("WU1");
  //}
}


void debub()
{
  dsp.clear();
  dsp.setCursor(0,0);
  dsp.setScale(1);
  dsp.print(sens_signal);
  dsp.setCursor(0, 1);
  dsp.print(last_sens_signal);
  dsp.setCursor(0,2);
  dsp.print(coin_flag);
  dsp.setCursor(0,3);
  dsp.print(empty_signal);
  dsp.setCursor(0,5);
  dsp.print(last_coin);

  for (byte a=0; a<coin_amount; a++){
    dsp.setCursor(40,a);
    dsp.print(coin_signal_min[a]);
    dsp.print(' ');
    dsp.print(coin_signal_max[a]);
  }

  
  dsp.update();
  //Serial.println("debug");
}

//void 

settings(boolean doIn = false){
  if (doIn)cursor++;
  if (cursor>3)cursor = 0;
  dsp.clear();
  for (byte i = 0; i<=3; i++){
    dsp.setScale(2);
    dsp.setCursor(12, 2*i);
    dsp.print(settings_lines[i]);
  }
  
  dsp.setCursor(0, 2*cursor);
  dsp.print(cursor_symbol);
  dsp.update();
}
