#include <Keypad.h>
#include <LiquidCrystal.h>

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
Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM );
int r;
int sum = 0;
int a = 0;
int b = 0;
int c = 0;
int d = 0;
int aa = 4;
int bb = 10;
int cc = 16;
int dd = 8;
void setup() {
  
  Serial.begin(9600);
  Serial1.begin(9600);
  Serial2.begin(9600);
  Serial3.begin(9600);
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
  pinMode(A6, OUTPUT);
  pinMode(A7, OUTPUT);
  pinMode(A8, OUTPUT);
  pinMode(A9, OUTPUT);
  pinMode(A10, OUTPUT);
  pinMode(A11, OUTPUT);
  pinMode(A12, OUTPUT);
  pinMode(A13, OUTPUT);
  pinMode(A14, OUTPUT);
  pinMode(A15, OUTPUT);
  digitalWrite(A0, LOW);
  digitalWrite(A1, LOW);
  digitalWrite(A2, LOW);
  digitalWrite(A3, LOW);
  digitalWrite(A4, LOW);
  digitalWrite(A5, LOW);
  digitalWrite(A6, LOW);
  digitalWrite(A7, LOW);
  digitalWrite(A8, LOW);
  digitalWrite(A9, LOW);
  digitalWrite(A10, LOW);
  digitalWrite(A11, LOW);
  digitalWrite(A12, LOW);
  digitalWrite(A13, LOW);
  digitalWrite(A14, LOW);
  digitalWrite(A15, LOW);
  lcd.begin(16,2);
  lcd.clear();
  lcd.print("Loading ...");
  delay(100);
  lcd.clear();
   
}

void loop() {
  if(Serial.available() > 0){
    int x = Serial.read();
    if(x == 49){
      int value = EEPROM.read(4);
      if(value == 255) value = 0;
      value = value + 1;
      EEPROM.write(4, value);
    }
    if(x == 50){
      int value = EEPROM.read(5);
      if(value == 255) value = 0;
      value = value + 1;
      EEPROM.write(5, value);
    }
  }
    
  
  if(Serial1.available() > 0){
    int x = Serial1.read();
    if(x == 49){
      int value = EEPROM.read(6);
      if(value == 255) value = 0;
      value = value + 1;
      EEPROM.write(6, value);
    }
    if(x == 50){
      int value = EEPROM.read(7);
      if(value == 255) value = 0;
      value = value + 1;
      EEPROM.write(7, value);
    }
    
  }
  if(Serial2.available() > 0){
    int x = Serial2.read();
    if(x == 49){
      int value = EEPROM.read(8);
      if(value == 255) value = 0;
      value = value + 1;
      EEPROM.write(8, value);
    }
    else if(x == 50){
      int value = EEPROM.read(9);
      if(value == 255) value = 0;
      value = value + 1;
      EEPROM.write(9, value);
    }
    
  }
  if(Serial3.available() > 0){
    int x = Serial3.read();
    if(x == 49){
      int value = EEPROM.read(10);
      if(value == 255) value = 0;
      value = value + 1;
      EEPROM.write(10, value);
    }
    else if(x == 50){
      int value = EEPROM.read(11);
      if(value == 255) value = 0;
      value = value + 1;
      EEPROM.write(11, value);
    }
    
    }

    
    
  char key = keypad.getKey();
  if (key && key=='='){
      tone(8, 4000); 
      delay(20);        
      noTone(8);
      int trump_a = EEPROM.read(4);
      if(trump_a == 255) trump_a = 0;
      int biden_a = EEPROM.read(5);
      if(biden_a == 255) biden_a = 0;
      r = calculate(trump_a, biden_a, aa);
      sum += r ;
      int trump_b = EEPROM.read(6);
      if(trump_b == 255) trump_b = 0;
      int biden_b = EEPROM.read(7);
      if(biden_b == 255) biden_b = 0;
      r = calculate(trump_b, biden_b, bb);
      sum += r ;
      int trump_c = EEPROM.read(8);
      if(trump_c == 255) trump_c = 0;
      int biden_c = EEPROM.read(9);
      if(biden_c == 255) biden_c = 0;
      r = calculate(trump_c,biden_c, cc);
      sum += r ;
      int trump_d = EEPROM.read(10);
      if(trump_d == 255) trump_d = 0;
      int biden_d = EEPROM.read(11);
      if(biden_d == 255) biden_d = 0;
      r = calculate(trump_d, biden_d, dd);
      sum += r ;
      lcd.clear();
      if (sum > 0) lcd.print("Biden Win !");
      else if (sum < 0) lcd.print("Trump Win !");
      else lcd.print("DRAW");
      if (sum != 0){
        //singing();
        lighting();
      }
  }
  else if (key && key=='*'){
      tone(8, 4000); 
      delay(20);        
      noTone(8);
      int trump_a = EEPROM.read(4);
      int biden_a = EEPROM.read(5);
      int trump_b = EEPROM.read(6);
      int biden_b = EEPROM.read(7);
      int trump_c = EEPROM.read(8);
      int biden_c = EEPROM.read(9);
      int trump_d = EEPROM.read(10);
      int biden_d = EEPROM.read(11);
      if(trump_a == 255) trump_a = 0;
      if(trump_b == 255) trump_b = 0;
      if(trump_c == 255) trump_c = 0;
      if(trump_d == 255) trump_d = 0;
      if(biden_a == 255) biden_a = 0;
      if(biden_b == 255) biden_b = 0;
      if(biden_c == 255) biden_c = 0;
      if(biden_d == 255) biden_d = 0;
      int trump_count = trump_a + trump_b +trump_c + trump_d;
      int biden_count = biden_a + biden_b + biden_c + biden_d;
      lcd.clear();
      lcd.print("Trump : ");
      lcd.print(trump_count);
      lcd.setCursor(0,1);
      lcd.print("Biden : ");
      lcd.print(biden_count);
  }
  else if (key && key=='C'){
      tone(8, 4000); 
      delay(20);        
      noTone(8);
      lcd.clear();
      lcd.print("Erase Memory ");
      delay(500);
      EEPROM.write(4,255);
      EEPROM.write(5,255);
      EEPROM.write(6,255);
      EEPROM.write(7,255);
      EEPROM.write(8,255);
      EEPROM.write(9,255);
      EEPROM.write(10,255);
      EEPROM.write(11,255);
      lcd.clear();
      
  }
}



int calculate(int t, int b, int c){
    int res = 1;
    if (t>b)res = c * -1;
    if (t<b)res = c;
    if (t==b)res = 0;
    return res;
}

void celebrate(){
  lighting(); 
  
   
}

void lighting(){
  while(1){
    digitalWrite(A0, HIGH);
    delay(40);
    digitalWrite(A0, LOW);
    digitalWrite(A1, HIGH);
    delay(40);
    digitalWrite(A1, LOW);
    digitalWrite(A2, HIGH);
    delay(40);
    digitalWrite(A2, LOW);
    digitalWrite(A3, HIGH);
    delay(40);
    digitalWrite(A3, LOW);
    digitalWrite(A4, HIGH);
    delay(40);
    digitalWrite(A4, LOW);
    digitalWrite(A8, HIGH);
    delay(40);
    digitalWrite(A8, LOW);
    digitalWrite(A9, HIGH);
    delay(40);
    digitalWrite(A9, LOW);
    digitalWrite(A10, HIGH);
    delay(40);
    digitalWrite(A10, LOW);
    digitalWrite(A11, HIGH);
    delay(40);
    digitalWrite(A11, LOW);
    digitalWrite(A12, HIGH);
    delay(40);
    digitalWrite(A12, LOW);
    digitalWrite(A13, HIGH);
    delay(40);
    digitalWrite(A13, LOW);
    digitalWrite(A14, HIGH);
    delay(40);
    digitalWrite(A14, LOW);
    digitalWrite(A15, HIGH);
    delay(40);
    digitalWrite(A15, LOW);
    digitalWrite(A14, HIGH);
    delay(40);
    digitalWrite(A14, LOW);
    digitalWrite(A13, HIGH);
    delay(40);
    digitalWrite(A13, LOW);
    digitalWrite(A12, HIGH);
    delay(40);
    digitalWrite(A12, LOW);
    digitalWrite(A11, HIGH);
    delay(40);
    digitalWrite(A11, LOW);
    digitalWrite(A10, HIGH);
    delay(40);
    digitalWrite(A10, LOW);
    digitalWrite(A9, HIGH);
    delay(40);
    digitalWrite(A9, LOW);
    digitalWrite(A8, HIGH);
    delay(40);
    digitalWrite(A8, LOW);
    digitalWrite(A4, HIGH);
    delay(40);
    digitalWrite(A4, LOW);
    digitalWrite(A3, HIGH);
    delay(40);
    digitalWrite(A3, LOW);
    digitalWrite(A2, HIGH);
    delay(40);
    digitalWrite(A2, LOW);
    digitalWrite(A1, HIGH);
    delay(40);
    digitalWrite(A1, LOW);digitalWrite(A0, HIGH);
    delay(40);
    digitalWrite(A0, LOW); 
  }
}
