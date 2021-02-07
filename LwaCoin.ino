/*
  
*/

const uint8_t logo[] PROGMEM = {
  0x1F, 0x07, 0x03, 0x01, 0xC1, 0xE0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xE0, 0xC1, 0x01, 0x03, 0x07, 0x1F, 
  0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x1F, 0x1F, 0x1F, 0x1F, 0xFF, 0xFF, 0xFF, 0x7F, 0x1F, 0x1F, 0x1F, 0x1F, 0x7F, 0xFF, 0xFF, 0x1F, 0x1F, 0x1F, 0x1F, 0xFF, 0xFF, 0xFF, 0x3F, 0x3F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x3F, 0x3F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x38, 0x80, 0x00, 0x03, 0x1F, 0x03, 0x80, 0xF0, 0xFE, 0xF0, 0x80, 0x00, 0x0F, 0x03, 0x00, 0x80, 0xF8, 0xFF, 0xFF, 0xFF, 0x87, 0x02, 0x03, 0x03, 0x31, 0x39, 0x99, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x7F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3E, 0x3E, 0x3E, 0x3E, 0x3E, 0x3E, 0x3E, 0x3E, 0x3E, 0x3E, 0x3F, 0x3E, 0x3E, 0x3E, 0x3E, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3E, 0x3E, 0x3E, 0x3E, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3E, 0x3E, 0x3E, 0x3F, 0x3F, 0x3E, 0x3E, 0x3E, 0x3E, 0x3F, 0x3F, 0x3F, 0x3F, 0x7F, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x80, 0xE0, 0xF0, 0xF8, 0x38, 0x3C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x00, 0x80, 0x80, 0x80, 0x00, 0x80, 0x80, 0x80, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x1F, 0x7F, 0xFF, 0xF0, 0xC0, 0xC0, 0x80, 0x80, 0x80, 0x80, 0x80, 0xC0, 0x00, 0x7C, 0xFF, 0xFF, 0xC7, 0x83, 0x83, 0x83, 0xC7, 0xFF, 0xFF, 0x7C, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x07, 0x03, 0x03, 0x03, 0x00, 0xFF, 0xFF, 0xFF, 0xC6, 0x83, 0x83, 0x83, 0xC7, 0xFF, 0xFF, 0x7E, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x01, 0x00, 0x00, 0x01, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0x7F, 0x7F, 0x01, 0x03, 0x03, 0x03, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 
  0xF8, 0xE0, 0xC0, 0x80, 0x83, 0x07, 0x0F, 0x0E, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0E, 0x0F, 0x07, 0x83, 0x80, 0xC0, 0xE0, 0xF8, 
};


//-------НАСТРОЙКИ---------
#define coin_amount 4    // число монет, которые нужно распознать
float coin_value[coin_amount] = {1, 2, 5, 10};  // стоимость монет
String currency = "rub"; // валюта (английские буквы!!!)
int stb_time = 250000;    // время бездействия, через которое система уйдёт в сон (миллисекунды)
int screen_time = 10000;
String label = "summ"; //надпись над суммой
//-------НАСТРОЙКИ---------

byte amount = 0;
#define calib_iter 6 
int coin_signal_min[coin_amount];
int coin_signal_max[coin_amount];
int coin_signal_array[coin_amount][calib_iter]; //массив калибровочных значений для вычисления среднего
int coin_quantity[coin_amount];  // количество монет
byte empty_signal;               // храним уровень пустого сигнала
unsigned long standby_timer, reset_timer, screen_timer; // таймеры
int summ_money = 0;            // сумма монет в копилке
int money_quantity = 0;
byte delt = 45;                  //трешхолд значения с датчика
byte empty_treshold = 3;
byte coin_pass = 4;
boolean calibrated = false;
byte calib_count = 0;

//-------БИБЛИОТЕКИ---------//
#include "LowPower.h"
#include "EEPROMex.h"
#include "GyverButton.h"
//#include "Wire.h"
#include "GyverOLED.h"
//-------БИБЛИОТЕКИ---------//

boolean recogn_flag, sleep_flag = true;

//-------ПИНЫ---------//
#define BTN 2            // кнопка
#define BTNpower 4       // питание кнопки
#define disp_power 3     // питание дисплея
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
//DEBUG//
boolean debug = false;
//DEBUG//



void setup() {
  Serial.begin(9600);                   // открыть порт для связи с ПК для отладки
  //Serial.setTimeout(100);
  
  delay(500);

  attachInterrupt(0, isr, CHANGE);

  // пины питания как выходы
  //pinMode(9, OUTPUT);
  pinMode(disp_power, OUTPUT);
  pinMode(BTNpower, OUTPUT);
  pinMode(LEDpin, OUTPUT);
  pinMode(IRpin, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(5, OUTPUT);

  // подать питание на дисплей и датчик
  digitalWrite(disp_power, 1);
  digitalWrite(LEDpin, 1);
  digitalWrite(IRpin, 1);
  digitalWrite(BTNpower, 1);
  digitalWrite(5, 1);
  digitalWrite(9, 1);

  delay(500);
  
  
    // считать пустой (опорный) сигнал
 // Serial.println(empty_signal);
  
  // при старте системы считать из памяти сигналы монет для дальнейшей работы, а также их количество в банке
  calibrated = EEPROM.readInt(2);
  //Serial.print("calibrated - ");
  //Serial.println(calibrated);
  
  for (byte i = 0; i < coin_amount; i++) {
    coin_signal_min[i] = EEPROM.readInt(40 + i * 2);
    coin_signal_max[i] = EEPROM.readInt(60 + i * 2);
    
    coin_quantity[i] = EEPROM.readInt(20 + i * 2);
    summ_money += coin_quantity[i] * coin_value[i];  // ну и сумму сразу посчитать, как произведение цены монеты на количество
    money_quantity += coin_quantity[i];
    
    //Serial.print("min ");
    //Serial.println(coin_signal_min[i]);
    //Serial.print("max ");
    //Serial.println(coin_signal_max[i]);
    


    
  }
  Serial.print("SUMM: ");
  Serial.print(summ_money);
  Serial.print(" ");
  Serial.println(currency);
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
  dsp.drawBitmap(31, 0, logo, 64, 64, 1);
  dsp.update();

  delay(2000);
  
  summ();

  standby_timer = millis();  // обнулить таймер ухода в сон

  
}

void loop() {  
  empty_signal = analogRead(IRsens);
  
  last_sens_signal = empty_signal;
  while (1) {

    //Serial.println("tick");
    
    btn.tick();
    if (btn.isTriple()){
      //blnk(500, 100, 1);
      delay(50);
      calibrate();
    }
    if (btn.isSingle()&&debug){
      debug = false;
      Serial.println("ban");
      summ();
    }
    if (btn.getClicks() == 5){
      debug = !debug;
    }



    //btn.tick();
    
    //btn.tick();
    if (btn.isHolded()){
      //delay(500);
      //blnk(200, 100, 2);
      summ_money = 0;
      for (byte i = 0; i < coin_amount; i++) {
        coin_quantity[i] = 0;
        EEPROM.updateInt(20 + i * 2, coin_quantity[i]);
      }
      Serial.println("Memory cleared");
      summ();
    }
    //btn.tick();
    if (btn.isDouble()){
      //delay(50);
      Serial.println("//");
      for (byte i = 0; i < coin_amount; i++) {
        Serial.print(round(coin_value[i]));
        Serial.print(" : ");
        Serial.println(coin_quantity[i]);
        }
      Serial.println("//");
    }
    sens_signal = analogRead(IRsens);  // далее такой же алгоритм, как при калибровке
    //Serial.println(sens_signal);
    if (sens_signal > last_sens_signal) last_sens_signal = sens_signal;
    if (sens_signal - empty_signal > coin_pass) coin_flag = true;

    if (debug){
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
      dsp.print(debug);

      for (byte a=0; a<=coin_amount; a++){
        dsp.setCursor(40,a);
        dsp.print(coin_signal_min[a]);
        dsp.print(' ');
        dsp.print(coin_signal_max[a]);
      }

      
      dsp.update();
      Serial.println("debug");
    }
    
    
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
          //Serial.println(last_sens_signal);
          //Serial.println(coin_value[i]);
          Serial.print("SUMM: ");
          Serial.print(summ_money);
          Serial.print(" ");
          Serial.println(currency);

          if (!debug)summ();
          
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

    // если ничего не делали, время таймера вышло, спим
    /*if (millis() - standby_timer > stb_time) {
      //good_night();

      //Serial.print("Sleep");
      
      dsp.clearDisplay();
      dsp.display();
      digitalWrite(disp_power, 0);
      digitalWrite(LEDpin, 0);
      digitalWrite(IRpin, 0);
      sleep_flag = true;
    } */

    
  }

  
}

// функция сна
void good_night() {
  // перед тем как пойти спать, записываем в EEPROM новые полученные количества монет по адресам начиная с 20го (пук кек)
  //for (byte i = 0; i < coin_amount; i++) {
  //  EEPROM.updateInt(20 + i * 2, coin_quantity[i]);
  //}
  sleep_flag = true;
  // вырубить питание со всех дисплеев и датчиков
  digitalWrite(disp_power, 0);
  digitalWrite(LEDpin, 0);
  digitalWrite(IRpin, 0);
  delay(100);
  // и вот теперь спать
  LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);
}

// просыпаемся по ПРЕРЫВАНИЮ (эта функция - обработчик прерывания)
void wake_up() {
  // возвращаем питание на дисплей и датчик
  digitalWrite(disp_power, 1);
  digitalWrite(LEDpin, 1);
  digitalWrite(IRpin, 1);
  standby_timer = millis();  // и обнуляем таймер
}


void calibrate(){
  Serial.println("Calibrating");
  //delay(500);
  while (1){
    for (byte i = 0; i < coin_amount; i++){
      //coin_signal[i] = 0;
      for (byte j = 0; j < calib_iter; j++){
        Serial.print("Insert ");
        Serial.print(coin_value[i]);
        Serial.print(" ");
        Serial.println(currency);
        last_sens_signal = empty_signal;
        //dsp.setTextColor(1);
        dsp.setScale(2);
        dsp.clear();
        dsp.setCursor(0,0);
        dsp.print("Calibration");
        dsp.setCursor( (128 - 10*6)/2, 3);
        dsp.print("insert");
        dsp.setCursor( (128 - 10 * (numDigits(coin_value[i]) + currency.length()) + 1)/2 - 6, 5);
        dsp.print(coin_value[i]);
        dsp.print(" ");
        dsp.print(currency);
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
            
           
            //dsp.rect(0, 16, 128, 64 - 26, OLED_CLEAR);
            dsp.setScale(2);
            dsp.clear();
            dsp.setCursor(0,0);
            dsp.print("Calibration");
            dsp.setScale(3);
            dsp.setCursor(40, 3);
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
  dsp.rect(0, 16, 128, 64 - 26, OLED_CLEAR);
  dsp.setScale(4);
  //dsp.setCursor(30, 42);
  dsp.setCursor((127 - 4 * 20)/2, 42);
  dsp.print("done");
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
  Serial.println("Memory cleared");
}

void summ()
{
  dsp.clear();
  //dsp.setTextColor(1);
  dsp.setScale(2);
  dsp.setCursor((128 - label.length()*12)/2+1, 0);
  dsp.print(label);
  dsp.setScale(3);
  dsp.setCursor((128 - numDigits(summ_money)*18)/2+1, 2);
  dsp.print(summ_money);
  //dsp.print('!');
  //dsp.print();
  dsp.setScale(2);
  dsp.setCursor((128 - currency.length()*12)/2+1, 5);
  dsp.print(currency);
  dsp.update();
}

int numDigits(int number)
{
    int digits = 0;
    if (number == 0) digits = 1; // remove this line if '-' counts as a digit
    while (number) {
        number /= 10;
        digits++;
    }
    return digits;
}


void isr() {
  btn.tick();  // опрашиваем в прерывании, чтобы поймать нажатие в любом случае
}
