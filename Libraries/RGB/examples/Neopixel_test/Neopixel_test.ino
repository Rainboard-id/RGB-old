//--- Ini merupakan program basic untuk
//--- menguji fungsi dasar rainbotRGB
//--- sebelum memasukan program cabut sebuah kabel tambahan
//--- kemudian pindahkan jumper ke mode RGB (ke kanan)
//--- jumper akan mengaktifkan pushbutton(12) dan
//--- WS2812b(RGB(11))
//--- Bila LED RGB dan pushbutton tidak diperlukan lagi
//--- kembalikan jumper ke posisi normal (kiri) untuk
//--- mengembalikan pin 11 dan 12 ke mode I/O

//--- pastikan kamu sudah mendownload library
//--- Adafruit_neopixel
#include <Adafruit_NeoPixel.h>
#define LED_PIN 11
#define LED_COUNT 1
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

const int ledPin = 0;
const int ledPin2 = 13;
const int buttonPin = 12;

unsigned long previousMillis = 0;
const long interval = 200;  

int buttonState;
int ledState;
int a,b,c = 0;

void setup() {
  strip.begin();
  strip.setBrightness(40);
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

void loop() {
buttonState = digitalRead(buttonPin);
unsigned long currentMillis = millis();

if (currentMillis - previousMillis >= interval) {
  previousMillis = currentMillis;
  if (ledState == LOW) {
    ledState = HIGH;
  } else {
    ledState = LOW;
  }
  digitalWrite(ledPin, ledState);
  digitalWrite(ledPin2, ledState);
}

if (buttonState == LOW) {
  digitalWrite(ledPin, HIGH);
  digitalWrite(ledPin2, LOW);
  b = 255;
  c++;
  
  if(c==1){
   for(int a=0;a<255;a++){
    strip.setPixelColor(0, strip.Color(a,b,0));
    strip.show();
    delay(10);
    b--;
    }
  }
  
  else if(c==2){
    for(int a=0;a<255;a++){
    strip.setPixelColor(0, strip.Color(b,0,a));
    strip.show();
    delay(10);
    b--;
    }
  }
  
  else{
    c=0;
    for(int a=0;a<255;a++){
    strip.setPixelColor(0, strip.Color(0,a,b));
    strip.show();
    delay(10);
    b--;
    }
  }
strip.clear();
strip.show();
}
delay(1);
}
