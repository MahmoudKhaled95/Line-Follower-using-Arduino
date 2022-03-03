#define RS 12     // right sensor 
#define MS 8     // Middel sensor 
#define LS 13    // left sensor 

int M_R_Enable = 3;   //(EN B)
int M_R_Forward = 4; //in3 (H_bridge)
int M_R_Reverse = 5;  //in4 (H_bridge)

int M_L_Enable = 6; //(EN A)
int M_L_Forward = 7;  //in2 (H_bridge)
int M_L_Reverse = 2;  //in1 (H_bridge)


void setup()
{
  pinMode(RS, INPUT);
  pinMode(MS, INPUT);
  pinMode(LS, INPUT);
  
  pinMode(M_R_Enable , OUTPUT);
  pinMode(M_R_Forward, OUTPUT);
  pinMode(M_R_Reverse, OUTPUT);
  
  pinMode(M_L_Enable , OUTPUT);
  pinMode(M_L_Forward, OUTPUT);
  pinMode(M_L_Reverse, OUTPUT);
  
}

void loop()
{
  if(!(digitalRead(LS)) && digitalRead(MS)&& !(digitalRead(RS)))     // FORWARD 
  {

      analogWrite(M_R_Enable ,100);
      analogWrite(M_L_Enable ,100);
      digitalWrite(M_R_Forward , HIGH);
      digitalWrite(M_L_Forward , HIGH);
      digitalWrite(M_R_Reverse  , LOW);
      digitalWrite(M_L_Reverse  , LOW);

  }
  
  if(!(digitalRead(LS)) && digitalRead(MS)&& digitalRead(RS))     // Turn right
  {
      analogWrite(M_R_Enable ,150);
      analogWrite(M_L_Enable ,150);
      digitalWrite(M_R_Forward , LOW);
      digitalWrite(M_L_Forward , HIGH);
      digitalWrite(M_R_Reverse, HIGH);
      digitalWrite(M_L_Reverse, LOW);
      
  }

if (!(digitalRead(LS))&&!(digitalRead(MS))&&(digitalRead(RS)))
{
      analogWrite(M_R_Enable ,150);
      analogWrite(M_L_Enable ,150);
      digitalWrite(M_R_Forward , LOW);
      digitalWrite(M_L_Forward , HIGH);
      digitalWrite(M_R_Reverse, HIGH);
      digitalWrite(M_L_Reverse, LOW);
      
  }


  
  if(digitalRead(LS)&& digitalRead(MS) && !(digitalRead(RS)))     // turn left
  {
      analogWrite(M_R_Enable ,150);
      analogWrite(M_L_Enable ,150);
      digitalWrite(M_R_Forward,HIGH);
      digitalWrite(M_L_Forward, LOW);
      digitalWrite(M_R_Reverse , LOW);
      digitalWrite(M_L_Reverse , HIGH);
  }

if ((digitalRead(LS))&&!(digitalRead(MS))&&(!digitalRead(RS)))
{
      analogWrite(M_R_Enable ,150);
      analogWrite(M_L_Enable ,150);
      digitalWrite(M_R_Forward,HIGH);
      digitalWrite(M_L_Forward, LOW);
      digitalWrite(M_R_Reverse , LOW);
      digitalWrite(M_L_Reverse , HIGH);
  }

  
  if(digitalRead(LS) && digitalRead(RS) && digitalRead(MS))     // STOP (READ BLACK LINE)
  {
      analogWrite(M_R_Enable ,0);
      analogWrite(M_L_Enable ,0);
      digitalWrite(M_R_Forward  , LOW);
      digitalWrite(M_L_Forward  , LOW);
      digitalWrite(M_R_Reverse , LOW);
      digitalWrite(M_L_Reverse  , LOW);
  } 
  
}
