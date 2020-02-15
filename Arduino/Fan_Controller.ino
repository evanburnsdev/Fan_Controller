unsigned char fanaddr_;
unsigned char fanspeed_;

unsigned char fan[7];

unsigned char fan_speed[7];

boolean wroteSerial = false;

void setup()  { 
  fan[1] = 3;
  fan[2] = 5;
  fan[3] = 6;
  fan[4] = 9;
  fan[5] = 10;
  fan[6] = 11;
  fan_speed[1] = 255;
  fan_speed[2] = 255;
  fan_speed[3] = 255;
  fan_speed[4] = 255;
  fan_speed[5] = 255;
  fan_speed[6] = 255;
  TCCR0A = _BV(COM0A1) | _BV(COM0B1) | _BV(WGM00); 
  TCCR0B = _BV(CS00);
  TCCR1B = TCCR1B & 0b11111000 | 0x01;
  TCCR2B = TCCR2B & 0b11111000 | 0x01;
  Serial.begin(115200);
  for(int i = 1; i <= 6; i++){
    pinMode(fan[i], OUTPUT);
    analogWrite(fan[i], fan_speed[i]);
  }
} 

void loop()  { 
  fanaddr_ = 0x00;
  fanspeed_ = 0x00;
  while(Serial.available()) {
    fanaddr_ = Serial.read();
    delay(20);
    fanspeed_ = Serial.read();
    
    if(fanaddr_ == 0x00) {
      for(int i = 0; i <= 6; i++) {
        int fan_int = fanspeed_;
        analogWrite(fan[i], fanspeed_);
      }
    } else if(fanaddr_ == 0x01) {
      analogWrite(fan[1], fanspeed_);
    } else if(fanaddr_ == 0x02) {
      analogWrite(fan[2], fanspeed_);
    } else if(fanaddr_ == 0x03) {
      analogWrite(fan[3], fanspeed_);
    } else if(fanaddr_ == 0x04) {
      analogWrite(fan[4], fanspeed_);
    } else if(fanaddr_ == 0x05) {
      analogWrite(fan[5], fanspeed_);
    } else if(fanaddr_ == 0x06) {
      analogWrite(fan[6], fanspeed_);
    }
  }
  //delay(5);
}
