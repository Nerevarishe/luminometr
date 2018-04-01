// Пин аналогового хода к которому подсоединяется люминометр
#define LUMINOMETR_PIN 0

// Скорость на которой общается контроллер с ком терменалом
#define BAUD 9600

// Множитель для отображения значения:
// 0 - в промежутке между 0 и 1023
// 1 - в вольтах
// 1000 - в миливольтах
// 1000000 - в микровольтах
#define MULTIPLIER 1

// Задержка между измерениями в мс
#define DELAY 2000

// Функция переводящая значения c аналогового пина в вольты
float analogToVolt(int data);

// Функция выводящая значение на lcd дисплей
void printToLCD(float volt);


void setup() {
  Serial.begin(BAUD);
}

void loop() {
  int data = analogRead(LUMINOMETR_PIN);
  if ( MULTIPLIER == 0){
    Serial.println(data);
  }
  else {
    float volt = analogToVolt(data);
    Serial.println(volt);
  }

  // Задержка цикла в мс
  delay(DELAY);
}

// Функция переводящая значения c аналогового пина в вольты
float analogToVolt(int data){
  float volt = data * (5.0 / 1023.0);
  volt *= MULTIPLIER;
  return volt;
  }

// Функция выводящая значение на lcd дисплей
void printToLCD(float volt){

  }


