#include <Keypad.h>
#include <LiquidCrystal.h>
#include<Wire.h>
#include <EEPROM.h> 


#define DA 0b1010000
LiquidCrystal lcd(13,12, 4, 5, 6, 7);
const int ROW_NUM = 4; 
const int COLUMN_NUM = 4; 
  char keys[ROW_NUM][COLUMN_NUM] = 
  {
  {'7','8','9','/'},
  {'4','5','6','*'},
  {'1','2','3','-'},
  {'C','0','=','+'}
  };
byte pin_rows[ROW_NUM] = {23,24,25,26}; 
byte pin_column[COLUMN_NUM] = {30,31,32,33};
int flag;
String str="";
int sum = 0;
Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM );

uint8_t Biden_counter;
uint8_t Trump_counter;
int electoral = 1;
void setup() {
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  Wire.begin();
  Serial.begin(9600);
  digitalWrite(10, HIGH);
  pinMode(8, OUTPUT);
  lcd.begin(16, 2);
  lcd.print("OFF");
  //EEPROM.write(0,0);
}

void loop() {
  // put your main code here, to run repeatedly:
  char key = keypad.waitForKey();
  if (key=='+'){
    lcd.clear();
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
    lcd.print("Welcome");
    tone(8, 4000); 
    delay(20);        
    noTone(8);     
    delay(200);
    lcd.clear();
    lcd.print("ID");
    lcd.setCursor(0,1);
    //lcd.print("1.Trump  2.Biden");
  }
  else if (key=='='){
    lcd.clear();
    lcd.print("Thanks !"); 
    //delay(1000);
    
    int choice = str.toInt();
    if(choice == 1){
      int value = EEPROM.read(3);
      delay(100);
      if(value == 255) value = 0;
      value += 1;
      EEPROM.write(3, value);
      Serial.print(choice);
      
    }
    else if(choice == 2){
      int value2 = EEPROM.read(1);
      delay(100);
      if(value2 == 255) value2 = 0;
      value2 += 1;
      lcd.setCursor(1,0);
      lcd.print(choice);
      EEPROM.write(1, value2);
      Serial.print(choice);
      
    }
    lcd.clear();
   
    
    
    if (choice > 2){
      lcd.print("Invalid");
      delay(300);
      lcd.clear();
    
    }
    
    str = "";
    lcd.print("ID");
    lcd.setCursor(0,1);
    //lcd.print("1.Trump  2.Biden");
    
  }
  else if (key == '/'){
    lcd.clear();
    int x = str.toInt();
    flag = EEPROM.read(x);
    if(flag == 255) flag = 0;
    if (flag == 1){
        lcd.print("repetitive ID");
        delay(200);
        lcd.clear();
        str = "";
        lcd.print("ID");
        lcd.setCursor(0,1);
        //lcd.print("1.Trump  2.Biden");
    }
    if (flag == 0){
        lcd.print("valid ID");
        EEPROM.write(x, 1);
        delay(200);
        lcd.clear();
        str = "";
        lcd.print("Which candidate?");
        lcd.setCursor(0,1);
        lcd.print("1.Trump  2.Biden");
    }
    delay(200);
    lcd.clear();
    str = "";
    lcd.print("Which candidate?");
    lcd.setCursor(0,1);
    lcd.print("1.Trump  2.Biden");
    
    
  }
  else if (key == '-'){
     lcd.clear();
     digitalWrite(10, HIGH);
     digitalWrite(9, LOW);
     tone(8, 400); 
     lcd.print("OFF");
     delay(200);        
     noTone(8);
  }
  else if(key == 'C'){
       tone(8, 4000); 
       delay(20);        
       noTone(8);
       lcd.clear();
       lcd.print("Erase Memory ");
       delay(200);
       EEPROM.write(3, 0);
       EEPROM.write(1,0);
       lcd.clear();
       lcd.print("ID");
      lcd.setCursor(0,1);
      //lcd.print("1.Trump  2.Biden");
       
  }
  else if(isDigit(key)){
    
    lcd.clear();
    str+=key;
    lcd.print(str);  
  }  
  else if(key == '*'){
    lcd.clear();
    int trump_count = EEPROM.read(3);
    if(trump_count == 255) trump_count = 0;
    int biden_count = EEPROM.read(1);
    if(biden_count == 255) biden_count = 0;
    lcd.print("Trump:");
    lcd.setCursor(8,0);
    lcd.print(trump_count);
    lcd.setCursor(0,1);
    lcd.print("Biden:");
    lcd.setCursor(8,1);
    lcd.print(biden_count);
    delay(800);
    lcd.clear();
    lcd.print("ID");
    lcd.setCursor(0,1);
    //lcd.print("1.Trump  2.Biden");
  }
  
   
}
