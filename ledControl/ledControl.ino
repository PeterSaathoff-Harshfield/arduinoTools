// ledControl.ino

int ledPin = 3;

void setup() {
  Serial.begin(9600);
}

void loop() {

  for (int x = 0; x < 256; x++) {
    light(x);
    delay(10);
  }
  for (int x = 255; x >= 0; x--) {
    light(x);
    delay(10);
  } 
}

void light(int brightness) {
  
  float scale = 0.00025;
  float expo = 2.492;
  
  float y = scale * pow((3 + brightness), expo);
  if (y < 0) {
    y = 0;
  }
  analogWrite(ledPin, y);
  
  char buf[64];
  sprintf(buf, "%03d %s", brightness, String(y).c_str());
  Serial.println(buf);
}
