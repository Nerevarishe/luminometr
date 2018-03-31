// Пин аналогового хода к которому подсоединяется люминометр
#define LUMINOMETR_PIN 0

// Скорость на которой общается контроллер с ком терменалом
#define BAUD 9600

// Множитель для отображения значения:
// 1 - в вольтах
// 1000 - в миливольтах
// 1000000 - в микровольтах
#define MULTIPLIER 1

// Задержка между измерениями в мс
#define DELAY 2000

void setup() {
  Serial.begin(BAUD);
}

void loop() {
  // Писать в ком порт значения с аналогового пина
  printToSerial();

  // Выводить значения на экран
  // printToLCD();

  // Задержка цикла в мс
  delay(DELAY);
}

// Функция переводящая значения аналогового пина в вольты 
float analogToVolt(int data){
  float volt = data * (5.0 / 1023.0);
  volt *= MULTIPLIER;
  return volt;
  }

// Функция, пишущая значения в серийный порт 
void printToSerial(){
  
  }

// Функция выводящая значение на lcd дисплей
void printToLCD(){

  }


