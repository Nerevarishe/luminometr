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
#define DELAY 20

// Функция переводящая значения c аналогового пина в вольты
float analogToVolt(int data);

void setup() {
  Serial.begin(BAUD);
  //analogReference(INTERNAL);
  pinMode(BUTTON, INPUT_PULLUP);
}

void loop() {  
  // Массив в котором хранятся измерения с аналогово пина
  double data = 0;

  // Цикл, записывающий значения измерений в массив и высчитывающий сумму всех его значений
  for (int i = 0; i < SELECTION; i++){
    data += analogRead(LUMINOMETR_PIN);
    delay(DELAY);
  }
  // Находим среднее значение
  data /= 100;
  
  // Вывод среднеарифметического значения в серийный порт в заданных единицах
  if(MULTIPLIER == 0){
    Serial.println(data);
  }
  else Serial.println(analogToVolt(data));

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
float analogToVolt(double data){
  //float volt = (data * 1.1) / 1023;
  float volt = data * (5.0 / 1023.0);
  volt *= MULTIPLIER;
  return volt;
  }
