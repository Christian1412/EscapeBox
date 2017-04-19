/***************************************************
    FileName: EscapeBox_Mega
    FileTyp:  Ardunio Sketch
    Author:   Christian Schmittutz

    Description:
    This is the sketch for the defuse box

****************************************************/
// Support fuer Keypad
#include "Arduino.h"
#include "Keypad.h"

// Support fuer TM1637Display
#include <TM1637Display.h>

// Module connection pins (Digital Pins)
#define CLK 2
#define DIO 3

TM1637Display display(CLK, DIO);

const uint8_t SEG_CLEAR[] = {
  SEG_G,
  SEG_G,
  SEG_G,
  SEG_G,
};

const uint8_t SEG_SINGLE_CLEAR[] = {
  SEG_G,
};

const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};
byte rowPins[ROWS] = {39, 40, 41, 42}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {36, 37, 38}; //connect to the column pinouts of the keypad

Keypad customKeypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

// Pin-Belegung Kippschalter (Aussenansicht)
// 31   32   33
// 28   29   30
// 25   26   27
// 22   23   24

// Pin-Belegung Kippschalter (Innenansicht)
// 22   23   24
// 25   26   27
// 28   29   30
// 31   32   33

const byte tIn1  = 22, tIn2  = 23, tIn3  = 24, tIn4  = 25, tIn5  = 26, tIn6  = 27,
           tIn7  = 28, tIn8  = 29, tIn9  = 30, tIn10 = 31, tIn11 = 32, tIn12 = 33;

// Status HIGH oder LOW für jeden Kippschalter
boolean tState1, tState2, tState3, tState4,  tState5,  tState6,
        tState7, tState8, tState9, tState10, tState11, tState12;

boolean tState[12];

// Bonus-Muster
boolean p1[] = { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
boolean p2[] = { 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
boolean p3[] = { 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
boolean p4[] = { 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1 };
boolean p5[] = { 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1 };
boolean p6[] = { 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1 };

// Pin-Belegung für Schlüsselschalter
const byte kInL = 43, kInR = 44;

// Status-Variablen Schlüsselschalter
boolean leftKeyState = false, rightKeyState = false;

// SEND-Button Variablen for Zeitbonus
boolean button4_prevState = false, button4_pressed = false;
const byte inPin4 = 4;

// Pin-Belegung für Button-Status-LEDs
const byte tLedRot = 34, tLedGruen = 35;

// Buzzer-Pin
const byte buzzer  = 9;

// Musterstatus
boolean tPattern, tPattern1, tPattern2, tPattern3, tPattern4, tPattern5, tPattern6;

const String patternCode_1 = "AAAA";
const String patternCode_2 = "BBBB";
const String patternCode_3 = "CCCC";
const String patternCode_4 = "DDDD";
const String patternCode_5 = "EEEE";
const String patternCode_6 = "FFFF";

#define Password_Lenght 5
char Data[Password_Lenght];
char Master[Password_Lenght] = "5555";
byte data_count = 0;
char customKey;

void setup() {

  Serial.begin(9600);
  //Serial.println("Hello, may I introduce myselft to you. My name is Defuse-Box.");

  pinMode(inPin4, INPUT);

  pinMode(tIn1, INPUT);
  pinMode(tIn2, INPUT);
  pinMode(tIn3, INPUT);
  pinMode(tIn4, INPUT);
  pinMode(tIn5, INPUT);
  pinMode(tIn6, INPUT);
  pinMode(tIn7, INPUT);
  pinMode(tIn8, INPUT);
  pinMode(tIn9, INPUT);
  pinMode(tIn10, INPUT);
  pinMode(tIn11, INPUT);
  pinMode(tIn12, INPUT);

  digitalWrite (tIn1, HIGH) ; // Activate intern Pull-Up-Resistor
  digitalWrite (tIn2, HIGH) ; // Activate intern Pull-Up-Resistor
  digitalWrite (tIn3, HIGH) ; // Activate intern Pull-Up-Resistor
  digitalWrite (tIn4, HIGH) ; // Activate intern Pull-Up-Resistor
  digitalWrite (tIn5, HIGH) ; // Activate intern Pull-Up-Resistor
  digitalWrite (tIn6, HIGH) ; // Activate intern Pull-Up-Resistor
  digitalWrite (tIn7, HIGH) ; // Activate intern Pull-Up-Resistor
  digitalWrite (tIn8, HIGH) ; // Activate intern Pull-Up-Resistor
  digitalWrite (tIn9, HIGH) ; // Activate intern Pull-Up-Resistor
  digitalWrite (tIn10, HIGH) ; // Activate intern Pull-Up-Resistor
  digitalWrite (tIn11, HIGH) ; // Activate intern Pull-Up-Resistor
  digitalWrite (tIn12, HIGH) ; // Activate intern Pull-Up-Resistor

  pinMode(tLedGruen, OUTPUT);
  pinMode(tLedRot, OUTPUT);

  pinMode(kInL, INPUT);
  pinMode(kInR, INPUT);

  display.setBrightness(0x0f);
}

void loop() {

  // Funktion für die rote Bonus LED
  if (tPattern == false && button4_pressed == true) {
    digitalWrite(tLedRot, HIGH);
    delay(150);
    digitalWrite(tLedRot, LOW);
  }

  // Funktion für die gruene Bonus LED
  if (tPattern == true && button4_pressed == true) {
    digitalWrite(tLedGruen, HIGH);
    delay(150);
    digitalWrite(tLedGruen, LOW);
  }

  // Merkt sich vorherigen Button state
  button4_prevState = button4_pressed;
  // Drucktaster auf InputPin4 => Bonus
  button4_pressed = checkState(inPin4);

  // Wird nur einmal ausgeführt nicht wenn der Button gedrückt wird
  if (button4_pressed == true && button4_prevState == !button4_pressed) {

    if (tPattern1 == true) {
      Serial.println(patternCode_1);
    }
    if (tPattern2 == true) {
      Serial.println(patternCode_2);
    }
    if (tPattern3 == true) {
      Serial.println(patternCode_3);
    }
    if (tPattern4 == true) {
      Serial.println(patternCode_4);
    }
    if (tPattern5 == true) {
      Serial.println(patternCode_5);
    }
    if (tPattern6 == true) {
      Serial.println(patternCode_6);
    }
  }

  /*----------------------------------------------------------------------------*/
  /*----------------------------- KeyPad-Handling ------------------------------*/
  /*----------------------------------------------------------------------------*/


  // Überprüft den Status der Schlüsselschalter
  leftKeyState = checkState(kInL);
  rightKeyState = checkState(kInR);

  if (rightKeyState == true && leftKeyState == true) {
    display.setBrightness(7, true); // Turn on
    checkKeyPad();
    clearDisplay();
  }
  else {
    display.setBrightness(7, false);
    display.setSegments(SEG_CLEAR);
    clearData();
  }

  /*----------------------------------------------------------------------------*/
  /*-------------------------- Toggle-Switch-Handling --------------------------*/
  /*----------------------------------------------------------------------------*/

  // Speichere aktuellen Status jedes Kippschalters
  tState1 = checkState(tIn1);
  tState2 = checkState(tIn2);
  tState3 = checkState(tIn3);
  tState4 = checkState(tIn4);
  tState5 = checkState(tIn5);
  tState6 = checkState(tIn6);
  tState7 = checkState(tIn7);
  tState8 = checkState(tIn8);
  tState9 = checkState(tIn9);
  tState10 = checkState(tIn10);
  tState11 = checkState(tIn11);
  tState12 = checkState(tIn12);

  // und speicher alle Werte in Array
  storeToggleArray();

  /*----------------------------------------------------------------------------*/
  /*----------------------- Pattern-Recognition-Handling -----------------------*/
  /*----------------------------------------------------------------------------*/

  tPattern1 = checkPattern(p1);
  tPattern2 = checkPattern(p2);
  tPattern3 = checkPattern(p3);
  tPattern4 = checkPattern(p4);
  tPattern5 = checkPattern(p5);
  tPattern6 = checkPattern(p6);

  if (tPattern1 == true ||
      tPattern2 == true ||
      tPattern3 == true ||
      tPattern4 == true ||
      tPattern5 == true ||
      tPattern6 == true)
  {
    tPattern = true;
  }
  else {
    tPattern = false;
  }

}

boolean checkPattern(boolean pattern[]) {

  boolean result;
  for (int i = 0; i < 12; i++) {
    if (tState[i] == pattern[i]) {
      result = true;
    }
    else {
      result = false;
      break;
    }
  }
  return result;
}

void checkKeyPad() {

  customKey = customKeypad.getKey();

  if (customKey) // makes sure a key is actually pressed, equal to (customKey != NO_KEY)
  {

    if (customKey != '*' && customKey != '#' && data_count <= 3) { // data_count <= 3 stoppt auffüllen des Arrays, wenn 4 Ziffern eingegeben sind

      // Piepsen der Tasten bei Eingabe
      beeb(4186, 50);

      Data[data_count] = customKey; // store char into data array

      // Prüfe für jede einzelnes Digit ob es leer ist (Vermeiden von Flackereffekten)
      if (Data[0] == '\0') {
        display.showNumberDec(SEG_SINGLE_CLEAR, false, 1, 3);
      } else {
        display.showNumberDec((Data[data_count] - '0'), false, 1, 3);
      }
      if (Data[1] == '\0') {
        display.setSegments(SEG_SINGLE_CLEAR, 1, 2);
      } else {
        display.showNumberDec((Data[data_count - 1] - '0'), false, 1, 2);
      }
      if (Data[2] == '\0') {
        display.setSegments(SEG_SINGLE_CLEAR, 1, 1);
      } else {
        display.showNumberDec((Data[data_count - 2] - '0'), false, 1, 1);
      }
      if (Data[3] == '\0') {
        display.setSegments(SEG_SINGLE_CLEAR, 1, 0);
      } else {
        display.showNumberDec((Data[data_count - 3] - '0'), false, 1, 0);
      }

      data_count++;
    }

    if (customKey == '*') {
      display.setSegments(SEG_CLEAR);
      clearData();
      beeb(4186, 50);
      //Serial.println("Clear Array");
    }

    if (customKey == '#' && data_count == Password_Lenght - 1) { // schickt nur Daten wenn 4 Ziffern eingegeben wurden

      String d = Data;
      String m = Master;

      if (d == m) {
        beeb(2093, 1000);
        Serial.println(Data);
        delay(500);
        clearData();
        clearDisplay();
      }
      else {
        noisyBlink(120, 3);
        clearData();
        clearDisplay();
      }
    }
  }
}

void clearData() {
  while (data_count != 0)
  {
    Data[data_count - 1] = 0;
    data_count--;
  }
  return;
}

void clearDisplay() {

  if (Data[0] == '\0') {
    display.setSegments(SEG_SINGLE_CLEAR, 1, 3);
  }
  if (Data[1] == '\0') {
    display.setSegments(SEG_SINGLE_CLEAR, 1, 2);
  }
  if (Data[2] == '\0') {
    display.setSegments(SEG_SINGLE_CLEAR, 1, 1);
  }
  if (Data[3] == '\0') {
    display.setSegments(SEG_SINGLE_CLEAR, 1, 0);
  }
}

boolean checkState(int pin) {

  boolean state;
  if (digitalRead(pin) == HIGH) {
    state = true;
  }
  else {
    state = false;
  }
  return state;
}

void storeToggleArray() {
  tState[0] = tState1;
  tState[1] = tState2;
  tState[2] = tState3;
  tState[3] = tState4;
  tState[4] = tState5;
  tState[5] = tState6;
  tState[6] = tState7;
  tState[7] = tState8;
  tState[8] = tState9;
  tState[9] = tState10;
  tState[10] = tState11;
  tState[11] = tState12;
}

void beeb(int note, int duration) {
  tone(buzzer, note, duration);
  delay(duration);
  noTone(buzzer);
}

// t ist die pause zwischen den Piepsern, c ist die Anzahl der Piepser
// Bsp: 4x Blinken, Pause 150ms: -> noisyBlink(150, 4)
void noisyBlink (int t, int c) {
  
  for (int i = 0; i < c; i++) {

    display.setBrightness(7, false);
    display.setSegments(SEG_CLEAR);
    delay(t);

    display.setBrightness(7, true);
    display.setSegments(SEG_CLEAR);
    beeb(2093, t);
  }
}
/* Notizen

    Serial.println("Pattern: ");
    Serial.print(pattern[i]);
    Serial.println("Zustand: ");
    Serial.print(tState[i]);


    for (int i = 0; i < 12; i++) {
      Serial.print(tState[i]);
    }
    Serial.println();

*/

































