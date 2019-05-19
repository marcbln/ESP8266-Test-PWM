// 05/2019
// 10 bit PWM Fading on ESP8266 of LED-Strip using n-Channel Power-MOSFET IRLB8721 

#define PIN_LED 15 // == D8 == GPIO15
#define SPEED 20 
#define CLIP_10BIT(v) (max(0,min(1023,v)))


int brightness = 0;   
int brightnessInc = SPEED;   

// ---- Setup
void setup() {
  pinMode(PIN_LED,OUTPUT);
}

// ---- Main Loop
void loop() {  
  while(1)
  {
    analogWrite(PIN_LED, CLIP_10BIT(brightness));

    if (brightness <= 0) {
      brightnessInc = SPEED;
    }
    if (brightness >= 1023) {
      brightnessInc = -SPEED;
    }

    brightness += brightnessInc;
  
    delay(40); // == 1000ms / 25fps
  }
}
//=======================================================================
