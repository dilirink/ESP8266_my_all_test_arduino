#include "SSD1306.h"
//https://ardulogic.ru/posts/podkluchenie-oled-displeya-ssd1306-k-wemos-d1
#include "font.h"   // Файл с шрифтом
#include "image.h"  // Файл с картинкой

// Инициализируем дисплей подключенный к пинам D2 и D1
SSD1306  display(0x3c, D6, D5);

void setup() {
  // Первоначальные настройки дисплея
  display.init();
  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_10);
}

void loop() {
  // create more fonts at http://oleddisplay.squix.ch/
  display.clear();                             // Очищаем экран от предыдущих данных
  display.setTextAlignment(TEXT_ALIGN_CENTER); // Выравниваем текст по центру
//  display.setFont(Chewy_24);                   // Подключаем созданный нами шрифт
  display.drawString(64, 8, "ARDULOGIC");      // Первая строка в координаты 64 по оси X и 8 по оси Y
  display.drawString(64, 32, "2017");          // Вторая строка
  display.display();                           // Выводим все на экран
  delay(2000);

  // see http://blog.squix.org/2015/05/esp8266-nodemcu-how-to-create-xbm.html
  display.clear();
  //display.drawXbm(26, 0, Volk_width, Volk_height, Volk_bits);  // Рисуем нашу картинку
  display.display();
  delay(2000);

  display.clear();
  display.setTextAlignment(TEXT_ALIGN_CENTER);
  display.setFont(ArialMT_Plain_24);            // Стандартный шрифт из библиотеки
  display.drawString(64, 8, "GT-VOLK");
  display.drawString(64, 32, "DRIVE2");
  display.display();
  delay(2000);
}
