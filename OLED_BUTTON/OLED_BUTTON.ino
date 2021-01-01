#include "SSD1306.h"
//#include <Wire.h>
//https://ardulogic.ru/posts/podkluchenie-oled-displeya-ssd1306-k-wemos-d1
//https://radioprog.ru/post/875
//https://www.instructables.com/ARDUINO-MENU-DESIGN-With-OLED-UIUSER-INTERFACE/
//https://www.hackster.io/yilmazyurdakul/arduino-oled-encoder-simple-menu-system-f9baa1
//http://wikihandbk.com/wiki/ESP8266:%D0%9F%D1%80%D0%B8%D0%BC%D0%B5%D1%80%D1%8B/%D0%9F%D1%80%D0%BE%D1%88%D0%B8%D0%B2%D0%BA%D0%B0_ESP8266_%D0%BC%D0%B5%D1%82%D0%BE%D0%B4%D0%BE%D0%BC_OTA
// Инициализируем дисплей подключенный к пинам D2 и D1
SSD1306 display(0x3c, D6, D5); //D6-sda D5-SCL
int demoMode = 0;
int counter = 1;
int man = 0;
void setup()
{
	// put your setup code here, to run once:
	display.init();
	display.flipScreenVertically();
	display.setFont(ArialMT_Plain_16);
	pinMode(D7, INPUT_PULLUP);  // D7
	pinMode(D3, INPUT_PULLUP);  // D1
	pinMode(D4, INPUT_PULLUP);  // D2
	pinMode(D0, INPUT_PULLUP);  // RX
	pinMode(D8, OUTPUT);        //D3
}

void loop()
{
	// put your main code here, to run repeatedly:
	byte val = digitalRead(D7); //++
	byte val2 = digitalRead(D3); //--
	byte val3 = digitalRead(D4); //+256
	byte val4 = digitalRead(D0); //-256 RX
	if (val == LOW)
	{
		man++;
		analogWrite(D8, man);
		delay(80);
		if (man > 256)
			man = 255;
		while (val != LOW)
		{
			man++;
			//delay(20);
		}
	}
	if (val2 == LOW)
	{
		man--;
		analogWrite(D8, man);
		delay(20);
	}
	if(val3==LOW)
	{
		man=255;
		analogWrite(D8, man);
	}
	if(val4==LOW)
	{
		man=0;
		analogWrite(D8, man);
	}
	display.drawString(5, 4, "DILIRINK");
	display.drawString(5, 24, "LED = " + String(man) + " ;");
	display.drawProgressBar(0, 55, 127, 8, (int)((man * 100) / 256)); //кординаты х,у, длинна,ширина
	display.display();
	display.clear();
}

void ledinput()
{
}
