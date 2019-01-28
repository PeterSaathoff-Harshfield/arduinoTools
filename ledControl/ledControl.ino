// digital pins with pwm
int bluePin = 3;
int redPin = 5;
int greenPin = 6;

void setup() {
  Serial.begin(9600);
}

void loop() {
//  cycleBrightness();
//  cycleBlueGreen();
//  dimRed();
//  redPulse();
  spectrum(200, 15);
}

// various color patterns

void spectrum(int high, int rate) {
  for (int i = 0; i < high; i++) {
    light(high - i, i, 0);
    delay(rate);
  }
  for (int i = 0; i < high; i++) {
    light(0, high - i, i);
    delay(rate);
  }
  for (int i = 0; i < high; i++) {
    light(i, 0, high - i);
    delay(rate);
  }
}

void dimRed() {
  light(30, 0, 0);
}

void redPulse() {
  int minBrightness = 25;
  int maxBrightness = 100;
  for (int i = minBrightness; i < maxBrightness; i++) {
    light(i, 0, 0);
    delay(90);
  }
  for (int i = maxBrightness; i >= minBrightness; i--) {
    light(i, 0, 0);
    delay(90);
  }
}

void cycleBrightness() {
  int maxBrightness = 256;
  int delayTime = 15; // ms
  for (int x = 0; x < maxBrightness; x++) {
    light(x, x, x);
    delay(delayTime);
  }
  for (int x = maxBrightness-1; x >= 0; x--) {
    light(x, x, x);
    delay(delayTime);
  }
}

void cycleBlueGreen() {
  for (int i = 0; i < 255; i++) {
    light(0, i, 255-i);
    delay(50);
  } 
  for (int i = 255; i >= 0; i--) {
    light(0, i, 255-i);
    delay(50);
  }
}

// bends the brightness curve to act more linear on LEDs
int brightness(int raw) {
  if (raw < 0) {
    raw = 0;
  }
  if (raw > 255) {
    raw = 255;
  }

  float scale = 0.00025;
  float expo = 2.492;
  
  float y = scale * pow((3 + raw), expo);
  if (y < 0) {
    y = 0;
  }

  return y;
}

// displays color giveb in RGB
void light(int r, int g, int b) {
  
  analogWrite(redPin, brightness(r));
  analogWrite(greenPin, brightness(g));
  analogWrite(bluePin, brightness(b));
  
  // monitor color levels
  // char buffer[64];
  // sprintf(buffer, "%03d %s", brightness, String(y).c_str());
  // Serial.println(buffer);
}
