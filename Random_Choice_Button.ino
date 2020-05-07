
#include <LiquidCrystal.h>

//LCD pin to Arduino
const int pin_RS = 8; 
const int pin_EN = 9; 
const int pin_d4 = 4; 
const int pin_d5 = 5; 
const int pin_d6 = 6; 
const int pin_d7 = 7; 

const int pin_BL = 10; 

LiquidCrystal lcd( pin_RS,  pin_EN,  pin_d4,  pin_d5,  pin_d6,  pin_d7);

long randNumber;

char player;

String displayText;

int button;

int nameCounter;
int numberOfCycles = 3;
int delayLength = 100;

int waitCycles = 15000;
int waitCounter;

void setup() {

  pinMode(13, INPUT_PULLUP);
  pinMode(12, OUTPUT);
  digitalWrite(12, LOW);
  
  lcd.begin(16, 2);

  lcd.setCursor(0,0);
  lcd.print("Chooserator");
  lcd.setCursor(0,1);
  lcd.print("Initialising...");
  delay(1000);
  lcd.setCursor(0,0);
  lcd.clear();
  lcd.print("Chooserator");
  lcd.setCursor(0,1);
  lcd.print("Ready...");
  delay(1000);


}

void loop() {

  button = digitalRead(13);
  if (button == 0) {
    lcd.clear();
    lcd.setCursor(0,0);
    //make a fancy display like it's thinking
    nameCycle(); 
    lcd.clear();

    //Randomly select a name & display
    lcd.setCursor(0,0);
    randNumber = random(1, 6);
    if (randNumber == 1) {
    lcd.print ("Dad");
    }
    else if (randNumber == 2) {
      lcd.print ("Mum");
    }
    else if (randNumber == 3) {
      lcd.print ("Autumn");
    }
    else if (randNumber == 4) {
      lcd.print ("Lizzy");
    }
    else if (randNumber == 5) {
      lcd.print ("Charley");
    }
    else {
      lcd.print ("What the hell is going on!");
    }

    //Randomly select a chore & display adjacent
    lcd.setCursor(8,0);
    randNumber = random(1, 6);
    if (randNumber == 1) {
    lcd.print ("Shoes");
    }
    else if (randNumber == 2) {
      lcd.print ("Kitchen");
    }
    else if (randNumber == 3) {
      lcd.print ("Bedroom");
    }
    else if (randNumber == 4) {
      lcd.print ("Living Rm");
    }
    else if (randNumber == 5) {
      lcd.print ("Outside");
    }
    else {
      lcd.print ("What the hell is going on!");
    } 

  //Roll a dice and say the number     
  lcd.setCursor(0,1);
  randNumber = random(1, 7);
  displayText = "Dice Roll " + String(randNumber);
  lcd.print (displayText); 

  waitCounter = 0;
  while (waitCounter <= waitCycles) {
    if (digitalRead(13) == 0) {
      break;
    }
    else {
      waitCounter += 1;
      delay (1);
    }
  }

  //Reset back to the start
  lcd.setCursor(0,0);
  lcd.clear();
  lcd.print("Chooserator");
  lcd.setCursor(0,1);
  lcd.print("Ready...");
  }
  else {
    return 0;
  }

  delay(100);

//  // print a random number from 1 to 5

//  delay(3000);
}

void nameCycle() {
  nameCounter = 0;
  lcd.setCursor(0,0);
  while (nameCounter != numberOfCycles) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Dad");
    delay(delayLength);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Mum");
    delay(delayLength);    
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Autumn");
    delay(delayLength);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Lizzy");
    delay(delayLength);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Charley");
    delay(delayLength);
    nameCounter += 1;
}
}
