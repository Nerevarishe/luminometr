// Пин аналогового хода к которому подсоединяется люминометр
#define LUMINOMETR_PIN 0

// Пин, к которому подключена кнопка
#define BUTTON 12

// Скорость на которой общается контроллер с ком терменалом
#define BAUD 9600

// Множитель для отображения значения:
// 0 - в промежутке между 0 и 1023
// 1 - в вольтах
// 1000 - в миливольтах
// 1000000 - в микровольтах
#define MULTIPLIER 1

// Выборка для вычисления среднего значения
#define SELECTION 100

// Задержка между измерениями при добавлении данных в массив в мс
#define DELAY 200

// Функция переводящая значения c аналогового пина в вольты
float analogToVolt(int data);

// Функция выводящая значение на lcd дисплей
void printToLCD(float volt);


void setup() {
  Serial.begin(BAUD);
  //analogReference(INTERNAL);
  pinMode(12, INPUT_PULLUP);
}

void loop() {  
  // Массив в котором хранятся измерения с аналогово пина
  int data[SELECTION];

  // Переменная хранящая сумму всех чисел в массиве data
  int sum = 0;

  // Цикл, записывающий значения измерений в массив и высчитывающий сумму всех его значений
  for (int i = 0; i < SELECTION; i++){
    data[i] = analogRead(LUMINOMETR_PIN);
    sum += data[i];
    delay(DELAY);
  }
  
  // Вывод среднеарифметического значения в серийный порт в заданных единицах
  if(MULTIPLIER == 0){
    Serial.println(sum / SELECTION);
  }
  else Serial.println(analogToVolt(sum / SELECTION));

  // Цикл, ожидающий нажатия кнопки для повторного измерения
  while(true) {
    boolean button = !digitalRead(BUTTON);
    if(button == 1){
      Serial.println("NEW_MEASUREMENT");
      break;
    }
  }
}

// Функция переводящая значения c аналогового пина в вольты
float analogToVolt(int data){
  //float volt = (data * 1.1) / 1023;
  float volt = data * (5.0 / 1023.0);
  volt *= MULTIPLIER;
  return volt;
  }

// Функция выводящая значение на lcd дисплей
void printToLCD(float volt){

  }
