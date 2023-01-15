     //Sıcaklık ve nem sensörü olan dht11 kütüphanesi eklemeyi unutma!!!
#include <dht11.h> // Sıcaklık ve nem sensörü olan dht11 kütüphanesi ekliyoruz.
#include <LiquidCrystal_I2C_AvrI2C.h>
int sensor=2; // dht11 digital pinini belirliyoruz.
dht11 DHT11nesne; // DHT11_sensor adında bir DHT11 nesnesi oluşturduk.
LiquidCrystal_I2C_AvrI2C lcd(0x27,16,2);  //ÖNEMLİ

void setup()
{
Serial.begin(9600); // Seri haberleşmeyi başlatıyoruz.
  lcd.begin(); //Ekranın boyutlarını kütüphane vasıtasıyla ayarlar.
  lcd.backlight(); //lcd arka ışığını açar.
}

void loop()
{
int chk = DHT11nesne.read(sensor); //pinden aldıgımız degeri nesneye tanımlıyoruz.
Serial.print("Sicaklik degeri: "); //Serial ekrana yazı yazdıyoruz.
Serial.print((float)DHT11nesne.temperature, 2);  //Pinden aldıgmız degeri kutuphanede tanımlı olan degere cevririp sicaklik degerini serial ekrana yazdırıyoruz.
Serial.print(" C"); //Serial ekrana yazı yazdırıyoruz. 
Serial.print("  ||  "); //Serial ekrana yazı yazdıyoruz.
Serial.print("Nem Orani: % "); //Serial ekrana yazı yazdıyoruz.
Serial.println((float)DHT11nesne.humidity, 2); //Pinden aldıgmız degeri kutuphanede tanımlı olan degere cevririp nem oranını serial ekrana yazdırıyoruz.
  lcd.clear(); //Ekrandaki tüm verileri siler.
    lcd.setCursor(0,0); //Yazının satır ve sutun yerini belirtiliyor.
  lcd.print("Sicaklik"); //Ekrana yazı yazdırıyoruz.
    lcd.setCursor(9,0);  //Yazının satır ve sutun yerini belirtiliyor.
  lcd.print(":"); //Ekrana yazı yazdırıyoruz.
  lcd.setCursor(10,0);  //Yazının satır ve sütun yerini belirtiliyor.
  lcd.print((float)DHT11nesne.temperature, 2); //Ekrana sıcaklık değerini yazdırıyoruz.
 lcd.setCursor(0,1); //Yazının satır ve sutun yerini belirtiliyor.
  lcd.print("Nem Orani:"); //Ekrana yazı yazdırıyoruz.
  lcd.setCursor(10,1); //Yazının satır ve sutun yerini belirtiliyor.
  lcd.print((float)DHT11nesne.humidity, 2);  //Ekrana nem değerini yazdırıyoruz.
  delay(1000); //Bu işlemler 1 saniyede bir olsun.
}