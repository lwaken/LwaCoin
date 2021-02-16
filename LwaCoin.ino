#ifdef SERIAL_DEBUG
#define DEBUG(x) Serial.print(x)
#define DEBUGLN(x) Serial.println(x)
#else
#define DEBUG(x)
#define DEBUGLN(x)
#endif

byte cursor = 0;
char cursor_symbol = '>';

String settings_lines[4]{
  "Обнулить сумму",
  "калибровать",
  "Цель",
  "СТРОКА 4"
};

#define NONE        0
#define NORMAL      1
#define CALIBRATION 2
#define SETTINGS    3
#define ERROR       4
//#define DEBUG       5
#define CLEAR       6
#define STATS       7

#define LINE_0  0
#define LINE_1  1
#define LINE_2  2
#define LINE_3  3


byte prev_mode = NONE;
byte mode = NORMAL;

/*
const uint8_t logo[] PROGMEM = {
  0x1F, 0x07, 0x03, 0x01, 0xC1, 0xE0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xE0, 0xC1, 0x01, 0x03, 0x07, 0x1F, 
  0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x1F, 0x1F, 0x1F, 0x1F, 0xFF, 0xFF, 0xFF, 0x7F, 0x1F, 0x1F, 0x1F, 0x1F, 0x7F, 0xFF, 0xFF, 0x1F, 0x1F, 0x1F, 0x1F, 0xFF, 0xFF, 0xFF, 0x3F, 0x3F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x3F, 0x3F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x38, 0x80, 0x00, 0x03, 0x1F, 0x03, 0x80, 0xF0, 0xFE, 0xF0, 0x80, 0x00, 0x0F, 0x03, 0x00, 0x80, 0xF8, 0xFF, 0xFF, 0xFF, 0x87, 0x02, 0x03, 0x03, 0x31, 0x39, 0x99, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x7F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3E, 0x3E, 0x3E, 0x3E, 0x3E, 0x3E, 0x3E, 0x3E, 0x3E, 0x3E, 0x3F, 0x3E, 0x3E, 0x3E, 0x3E, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3E, 0x3E, 0x3E, 0x3E, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3E, 0x3E, 0x3E, 0x3F, 0x3F, 0x3E, 0x3E, 0x3E, 0x3E, 0x3F, 0x3F, 0x3F, 0x3F, 0x7F, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x80, 0xE0, 0xF0, 0xF8, 0x38, 0x3C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x00, 0x80, 0x80, 0x80, 0x00, 0x80, 0x80, 0x80, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x1F, 0x7F, 0xFF, 0xF0, 0xC0, 0xC0, 0x80, 0x80, 0x80, 0x80, 0x80, 0xC0, 0x00, 0x7C, 0xFF, 0xFF, 0xC7, 0x83, 0x83, 0x83, 0xC7, 0xFF, 0xFF, 0x7C, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x07, 0x03, 0x03, 0x03, 0x00, 0xFF, 0xFF, 0xFF, 0xC6, 0x83, 0x83, 0x83, 0xC7, 0xFF, 0xFF, 0x7E, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x01, 0x00, 0x00, 0x01, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0x7F, 0x7F, 0x01, 0x03, 0x03, 0x03, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 
  0xF8, 0xE0, 0xC0, 0x80, 0x83, 0x07, 0x0F, 0x0E, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0E, 0x0F, 0x07, 0x83, 0x80, 0xC0, 0xE0, 0xF8, 
};*/


//-------НАСТРОЙКИ---------
#define SERIAL_DEBUG 1 //закомментировать чтобы убрать сериал дебаг
#define coin_amount 4    // число монет, которые нужно распознать
float coin_value[coin_amount] = {1, 2, 5, 10};  // стоимость монет
String currency = "рублей";
int stb_time = 30000;    // время бездействия, через которое система уйдёт в сон (миллисекунды)
//int screen_time = 10000;
String label = "summ"; //надпись над суммой
//-------НАСТРОЙКИ---------

#define USE_MICRO_WIRE

byte amount = 0;
#define calib_iter 5 
int coin_signal_min[coin_amount];
int coin_signal_max[coin_amount];
int coin_signal_array[coin_amount][calib_iter]; //массив калибровочных значений для вычисления среднего
int coin_quantity[coin_amount];  // количество монет
byte empty_signal;               // храним уровень пустого сигнала
unsigned long standby_timer, reset_timer, screen_timer, clock_timer; // таймеры
int summ_money = 0;            // сумма монет в копилке
int money_quantity = 0;
byte delt = 30;                  //трешхолд значения с датчика
byte empty_treshold = 3;
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
//boolean first_start = false;
boolean serial_debug = false;
//boolean debug = false;
boolean isGoal = false;
byte goall = 10;

byte last_coin = 0;

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
  delay(1000);
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
  dsp.setCursor((127 - 10 * 12)/2, 2);
  dsp.print("Калибровка");
  dsp.setCursor((127 - 9 * 12)/2, 4);
  dsp.print("завершена");
  dsp.update();
  delay(1000);
  summ();
  //ВОЗМОЖНО ЛИШНЕЕ
  last_sens_signal = empty_signal;
  //НУ ТИПА
  DEBUGLN("Calibration done");
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
  dsp.print("очищена");
  dsp.update();
  delay(1000);
  Serial.println("Memory cleared");
  summ();
}





void isr() {
  btn.tick();  // опрашиваем в прерывании, чтобы поймать нажатие в любом случае
}

/*
void debub() {
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
}*/

void goal(){
  byte count = goall;
  delay(400);
  dsp.clear();
  dsp.setCursor((127-12*9)/2, 1);
  dsp.print("Настройка");
  dsp.setCursor((127-12*4)/2, 3);
  dsp.print("цели");
  //dsp.update();
  while(1){
    btn.tick();
    //
    if (btn.isDouble()){
      EEPROM.updateInt(12, count);
      goall = count;
      summ();
      break;
    }
    if (btn.isSingle())count++;
    if (btn.isHold()){
      count++;
      delay(100);
    }
    if (count>100)count = 0;
    dsp.clear(0, 40, 127, 56);
    dsp.setCursor((127-12*numDigits(count*10))/2, 5);
    dsp.print(count*10);
    dsp.update();
  }
  delay(1000);
  standby_timer = millis();
}
/*
void setCoins(){
  
  dsp.clear();
  dsp.setScale(2);
  dsp.setCursor((128-12*9)/2, 1);
  dsp.print("Настройка");
  dsp.setCursor((128-12*9)/2, 3);
  dsp.print("номиналов");
  dsp.setCursor((128-12*5)/2, 5);
  dsp.print("монет");
  dsp.update();
  delay(500);
  dsp.clear();
  for (byte i=0; i<=5; i++){
    dsp.setScale(1);
    dsp.setCursor(4+20*i, 0);
//    dsp.print(coinAmountsArray[i]);
  }
  dsp.update();
  delay(1000);
}
*/

void settings(boolean doIn = false){
  
  if (doIn)cursor++;
  else cursor = 0;
  if (cursor>=3)cursor = 0;
  dsp.clear();
  //for (byte i = 0; i<=3; i++){
  dsp.setScale(2);
  dsp.setCursor(12, 1);
  dsp.print("Обнулить");
  dsp.setCursor(12, 3);
  dsp.print("Цель");
  dsp.setCursor(12, 5);
  dsp.print("Калибр.");
  
  dsp.setCursor(0, 1+2*cursor);
  dsp.print(cursor_symbol);
  dsp.update();
  standby_timer = millis();
}


void summ() {
  dsp.clear();
  dsp.setScale(2);
  if (isGoal && goall*10-summ_money >= 0){
    dsp.setCursor((128 - 7*12)/2, 1);
    dsp.print("До цели");
    //Serial.println(label);
    dsp.setScale(4);
    dsp.setCursor((128 - numDigits(goall*10 - summ_money)*24)/2, 3);
    dsp.print(goall*10 - summ_money);
  }
  else if (isGoal && goall*10-summ_money<0){
    dsp.setCursor((128 - 10*12)/2, 1);
    dsp.print("Сверх цели");
    dsp.setScale(4);
    dsp.setCursor((128 - numDigits(abs(goall*10 - summ_money))*24)/2, 3);
    dsp.print(abs(goall*10 - summ_money));
  }
  else {
    dsp.setCursor((128 - 5*12)/2, 1);
    dsp.print("Сумма");
    //Serial.println(label);
    dsp.setScale(4);
    dsp.setCursor((128 - numDigits(summ_money)*24)/2, 3);
    dsp.print(summ_money);
  }
  dsp.setScale(2);
  dsp.setCursor((128 - 6*12)/2, 7);
  dsp.print("рублей");
  //dsp.setScale(2);
  //Serial.println(128 - numDigits(last_coin)*14);
  //dsp.setCursor(126 - numDigits(last_coin)*12, 0);
  //dsp.print(last_coin);
  dsp.update();
}






void setup() {
  //power.setSystemPrescaler(PRESCALER_2);
  #ifdef SERIAL_DEBUG
    Serial.begin(9600);                   // открыть порт для связи с ПК для отладки
  #endif
  Serial.begin(9600);
  DEBUGLN("Serial debug is on");
  attachInterrupt(0, isr, RISING); 
  
  pinMode(disp_power, OUTPUT);
  pinMode(BTNpower, OUTPUT);
  pinMode(LEDpin, OUTPUT);
  pinMode(IRpin, OUTPUT);

  digitalWrite(disp_power, 1);
  digitalWrite(LEDpin, 1);
  digitalWrite(IRpin, 1);
  digitalWrite(BTNpower, 1);

  delay(100);
  
  dsp.init();
  Wire.setClock(600000L);
  dsp.autoPrintln(false);
  dsp.clear();
  dsp.flipV(1);
  dsp.flipH(1);
  dsp.setContrast(255);
  dsp.update();

  //calibrated = EEPROM.readInt(2);
  goall = EEPROM.readInt(12);
  
  for (byte i = 0; i < coin_amount; i++) {
    coin_signal_min[i] = EEPROM.readInt(40 + i * 2);
    coin_signal_max[i] = EEPROM.readInt(60 + i * 2);
    DEBUG(coin_signal_min[i]);
    DEBUG(' ');
    DEBUGLN(coin_signal_max[i]);
    
    coin_quantity[i] = EEPROM.readInt(20 + i * 2);
    summ_money += coin_quantity[i] * coin_value[i];  // ну и сумму сразу посчитать, как произведение цены монеты на количество
    money_quantity += coin_quantity[i];

  }
  DEBUG("SUMM: ");
  DEBUG(summ_money);
  DEBUG(" ");
  DEBUGLN(currency);
  
  summ();

  standby_timer = millis();  // обнулить таймер ухода в сон
  clock_timer = millis();
  empty_signal = analogRead(IRsens);
}

void loop() {  
  
  last_sens_signal = empty_signal;
  while (1) {
    btn.tick();
    if (btn.state() && sleep_flag){
      wake_up();
    }
    if (btn.state()){
      standby_timer = millis();
    }
    if (btn.isHolded()){
      Serial.println("HOLDED");
      if (mode==SETTINGS){
        switch (cursor){
          case LINE_0:
            DEBUGLN("CLEAR_MEMORY");
            clearCoins();
            mode = NORMAL;
            break;
          case LINE_1:
            DEBUGLN("GOAL");
            mode = NORMAL;
            goal();
            break;
          case LINE_2:
            DEBUGLN("calibrate");
            calibrate();
            mode = NORMAL;
            summ();
            break;
        }
        
      }
    }
    if (btn.isDouble()){
      DEBUGLN("DOUBLE TAP");
      isGoal = !isGoal;
      summ();
    }
    if (btn.isTriple()){
      DEBUGLN("TRIPLE TAP");
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
      DEBUGLN("SINGLE TAP");
      if (mode==SETTINGS){
        settings(1);
      }
    }
    sens_signal = analogRead(IRsens);  // далее такой же алгоритм, как при калибровке
    //Serial.println(sens_signal);
    if (sens_signal > last_sens_signal && sens_signal - empty_signal > 6) last_sens_signal = sens_signal;
    if (sens_signal - empty_signal > coin_pass) coin_flag = true;    
    if (coin_flag && (abs(sens_signal - empty_signal)) < empty_treshold) {
      recogn_flag = false;  // флажок ошибки
      // в общем нашли максимум для пролетевшей монетки, записали в last_sens_signal
      // далее начинаем сравнивать со значениями для монет, хранящимися в памяти
      //Serial.println(last_sens_signal);
      for (byte i = 0; i < coin_amount; i++) {
        if (
          (abs(coin_signal_min[i] - last_sens_signal) <= delt)
          or 
          (abs(last_sens_signal - coin_signal_max[i]) <= delt)
          or
          (last_sens_signal >= coin_signal_min[i]
          and
          last_sens_signal <= coin_signal_max[i])
          ){
            // и вот тут если эта разность попадает в диапазон, то считаем монетку распознанной
          summ_money += coin_value[i];  // к сумме тупо прибавляем цену монетки (дада, сумма считается двумя разными способами. При старте системы суммой всех монет, а тут прибавление
          last_coin = coin_value[i];
          /*
           * DEBUG("+ ");
           * DEBUG(coin_value[i]);
          *DEBUG(" SUMM: ");
          *DEBUG(summ_money);
          *DEBUG(" ");
          *DEBUGLN(currency);
          */
          if (coin_signal_min[i] - last_sens_signal <= delt)Serial.println(last_sens_signal-coin_signal_min[i]);
          else if (last_sens_signal - coin_signal_max[i] <= delt)Serial.println(coin_signal_max[i]-last_sens_signal);
          else Serial.println("0");
          if (mode == NORMAL)summ();
          
          coin_quantity[i]++;  // для распознанного номера монетки прибавляем количество
          EEPROM.updateInt(20 + i * 2, coin_quantity[i]);
          
          recogn_flag = true;
          break;
        }
      }
      if (!recogn_flag){
        DEBUG("ERROR coin not recognised: ");
        DEBUGLN(last_sens_signal);
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
