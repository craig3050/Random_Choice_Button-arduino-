
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
    randNumber = random(1, 16);
    if (randNumber == 1) {
    lcd.print ("Goblet Squats");
    }
    else if (randNumber == 2) {
      lcd.print ("Running Machine");
    }
    else if (randNumber == 3) {
      lcd.print ("Rowing Machine");
    }
    else if (randNumber == 4) {
      lcd.print ("Step Climber");
    }
    else if (randNumber == 5) {
      lcd.print ("Horizontal Row");
    }
    else if (randNumber == 5) {
      lcd.print ("Burpees");
    }
    else if (randNumber == 6) {
      lcd.print ("Shadow Boxing");
    }
    else if (randNumber == 7) {
      lcd.print ("Bicep Curls");
    }
    else if (randNumber == 8) {
      lcd.print ("Kettlebell Swing");
    }
    else if (randNumber == 9) {
      lcd.print ("Kettlebell Press");
    }
    else if (randNumber == 10) {
      lcd.print ("Kettlebell Thrust");
    }
    else if (randNumber == 11) {
      lcd.print ("Sit Ups");
    }
    else if (randNumber == 12) {
      lcd.print ("Press Ups");
    }
    else if (randNumber == 13) {
      lcd.print ("Kettlebell Lunge");
    }
    else if (randNumber == 14) {
      lcd.print ("Cycling Machine");
    }    
    else if (randNumber == 15) {
      lcd.print ("Cross Trainer");
    }
    else {
      lcd.print ("What the hell is going on!");
    }

    // //Randomly select a chore & display adjacent
    // lcd.setCursor(8,0);
    // randNumber = random(1, 6);
    // if (randNumber == 1) {
    // lcd.print ("Shoes");
    // }
    // else if (randNumber == 2) {
    //   lcd.print ("Kitchen");
    // }
    // else if (randNumber == 3) {
    //   lcd.print ("Bedroom");
    // }
    // else if (randNumber == 4) {
    //   lcd.print ("Living Rm");
    // }
    // else if (randNumber == 5) {
    //   lcd.print ("Outside");
    // }
    // else {
    //   lcd.print ("What the hell is going on!");
    // } 

  //Roll a dice and say the number     
  lcd.setCursor(0,1);
  randNumber = random(10, 30);
  displayText = "Reps " + String(randNumber);
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
    lcd.print("Squats");
    delay(delayLength);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Running");
    delay(delayLength);    
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Rowing");
    delay(delayLength);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Cycling");
    delay(delayLength);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Weights");
    delay(delayLength);
    nameCounter += 1;
}
}
