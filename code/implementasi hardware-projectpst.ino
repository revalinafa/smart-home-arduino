  #include <Wire.h>
  #include <LiquidCrystal_I2C.h>
  #include <Servo.h>

  // ======================
  // LCD I2C
  // ======================
  LiquidCrystal_I2C lcd(0x27, 16, 2);

  // ======================
  // PIN
  // ======================
  int ldrPin = A1;
  int lampPin = 12;

  int servoPin = 11;
  Servo fanServo;

  int gasPin = A0;
  int buzzerPin = 10;

  int ledHijau = 9;
  int ledBiru  = 8;
  int ledMerah = 7;

  int buttonMode = 2;
  int buttonLamp = 6;
  int buttonFan  = 5;

  // ======================
  // STATUS
  // ======================
  bool autoMode = true;

  bool lampManual = false;
  bool fanManual  = false;

  bool lampStatus = false;
  bool fanStatus  = false;

  bool lastLampState = HIGH;
  bool lastFanState  = HIGH;

  // ======================
  // TIMER
  // ======================
  unsigned long lastInterrupt = 0;
  unsigned long lastLCD = 0;
  unsigned long lastServo = 0;

  // ======================
  // SERVO CONTROL
  // ======================
  int servoPos = 0;
  int arahServo = 1;

  // ======================
  // SETUP
  // ======================
  void setup() {

    pinMode(lampPin, OUTPUT);
    pinMode(buzzerPin, OUTPUT);

    pinMode(ledHijau, OUTPUT);
    pinMode(ledBiru, OUTPUT);
    pinMode(ledMerah, OUTPUT);

    pinMode(buttonMode, INPUT_PULLUP);
    pinMode(buttonLamp, INPUT_PULLUP);
    pinMode(buttonFan, INPUT_PULLUP);

    fanServo.attach(servoPin);

    Serial.begin(9600);

    attachInterrupt(digitalPinToInterrupt(buttonMode), gantiMode, FALLING);

    lcd.init();
    lcd.backlight();
    lcd.clear();
  }

  // ======================
  // LOOP
  // ======================
  void loop() {

    // ======================
    // SENSOR
    // ======================
    int cahaya = analogRead(ldrPin);

    // sensor gas belum dipasang
    int gasValue = analogRead(gasPin);

    // sensor suhu tidak digunakan
    float suhu = 0;

    // ======================
    // LED MODE
    // ======================
    digitalWrite(ledHijau, autoMode);
    digitalWrite(ledBiru, !autoMode);

    // ======================
    // MODE AUTO
    // ======================
    if (autoMode) {

      lampManual = false;
      fanManual = false;

      // ======================
      // SENSOR CAHAYA
      // ======================
      // GELAP -> lampu nyala
      if (cahaya < 200) {

        digitalWrite(lampPin, HIGH);
        lampStatus = true;

      }
      // TERANG -> lampu mati
      else {

        digitalWrite(lampPin, LOW);
        lampStatus = false;

      }

      // ======================
      // SERVO OTOMATIS
      // ======================
      if (millis() - lastServo > 2) {

        servoPos += arahServo * 10;

        if (servoPos >= 180) {
          
          arahServo = -1;
        }

        if (servoPos <= 0) {
          servoPos = 0;
          arahServo = 1;
        }

        fanServo.write(servoPos);

        lastServo = millis();
      }

      fanStatus = true;
    }

    // ======================
    // MODE MANUAL
    // ======================
    else {

      bool bacaLamp = digitalRead(buttonLamp);
      bool bacaFan  = digitalRead(buttonFan);

      // ======================
      // BUTTON LAMPU
      // ======================
      if (lastLampState == HIGH && bacaLamp == LOW) {

        delay(50);

        if (digitalRead(buttonLamp) == LOW) {
          lampManual = !lampManual;
        }
      }

      // ======================
      // BUTTON SERVO
      // ======================
      if (lastFanState == HIGH && bacaFan == LOW) {

        delay(50);

        if (digitalRead(buttonFan) == LOW) {
          fanManual = !fanManual;
        }
      }

      lastLampState = bacaLamp;
      lastFanState  = bacaFan;

      // ======================
      // LAMPU MANUAL
      // ======================
      digitalWrite(lampPin, lampManual);
      lampStatus = lampManual;

      // ======================
      // SERVO MANUAL
      // ======================
      if (fanManual) {

        if (millis() - lastServo > 2) {

          servoPos += arahServo * 10;

          if (servoPos >= 180) {
            
            arahServo = -1;
          }

          if (servoPos <= 0) {
            servoPos = 0;
            arahServo = 1;
          }

          fanServo.write(servoPos);

          lastServo = millis();
        }

        fanStatus = true;
      }
      else {

        fanServo.write(90);
        fanStatus = false;
      }
    }

    // ======================
// SENSOR GAS MQ135
// ======================

String gasText = "SAFE";

// WARNING
if (gasValue > 250) {

  digitalWrite(ledMerah, HIGH);
  gasText = "WARNING";

}
else {

  digitalWrite(ledMerah, LOW);

}

// DANGER
if (gasValue > 500) {

  tone(buzzerPin, 1000);
  gasText = "DANGER";

}
else {

  noTone(buzzerPin);

}

    // ======================
    // LCD UPDATE
    // ======================
    if (millis() - lastLCD > 200) {

      lcd.setCursor(0, 0);
      lcd.print("Mode: ");

      if (autoMode)
        lcd.print("AUTO   ");
      else
        lcd.print("MANUAL ");

      lcd.setCursor(0, 1);

      lcd.print("L:");
      lcd.print(cahaya);
      lcd.print(" ");

      lcd.print("G:");
      lcd.print(gasText);
      lcd.print("   ");

      lastLCD = millis();
    }

    // ======================
    // SERIAL MONITOR
    // ======================
    Serial.print("Mode: ");
    Serial.print(autoMode ? "AUTO" : "MANUAL");

    Serial.print(" | Cahaya: ");
    Serial.print(cahaya);

    Serial.print(" | Lampu: ");
    Serial.print(lampStatus);

    Serial.print(" | Servo: ");
    Serial.print(fanStatus);

    Serial.print("| gas : ");
    Serial.println(gasValue);

    delay(10);
  }

  // ======================
  // INTERRUPT MODE
  // ======================
  void gantiMode() {

    if (millis() - lastInterrupt > 300) {

      autoMode = !autoMode;

      lastInterrupt = millis();
    }
  }