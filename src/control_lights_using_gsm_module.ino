

#define Fan 7
#define Light 9
#define TV 10
int temp=0,i=0;
int led=13;
char str[15];
void setup()
{
 
  Serial.begin(9600);
  pinMode(led, OUTPUT);
   pinMode(Fan, OUTPUT);
    pinMode(Light, OUTPUT);
     pinMode(TV, OUTPUT);
  
  
  Serial.println("AT+CNMI=2,2,0,0,0");
  delay(500);
  Serial.println("AT+CMGF=1");
  delay(1000);
   
}
void loop()
{
 
  if(temp==1)
  {
    check();
    temp=0;
    i=0;
    delay(1000);
  }
}
 void serialEvent() 
 {
  while(Serial.available()) 
  {
    if(Serial.find("#A."))
    {
      digitalWrite(led, HIGH);
      delay(1000);
      digitalWrite(led, LOW);
      while (Serial.available()) 
      {
      char inChar=Serial.read();
      str[i++]=inChar;
      if(inChar=='*')
      {
        temp=1;
        return;
      } 
      } 
    }
   }
 }
void check()
{
   if(!(strncmp(str,"tv on",5)))
    {
      digitalWrite(TV, HIGH);
      
      
     
    }  
   
   else if(!(strncmp(str,"tv off",6)))
    {
      digitalWrite(TV, LOW);
       
      
      
    }
  
    else if(!(strncmp(str,"fan on",6)))
    {
      digitalWrite(Fan, HIGH);
       
     
    }
 
    else if(!(strncmp(str,"fan off",7)))
    {
      digitalWrite(Fan, LOW);
      
    }     
 
    else if(!(strncmp(str,"light on",8)))
    {
      digitalWrite(Light, HIGH);
     
    }
 
    else if(!(strncmp(str,"light off",9)))
    {
      digitalWrite(Light, LOW);
      
    } 
    
    else if(!(strncmp(str,"all on",6)))
    {
      digitalWrite(Light, HIGH);
      digitalWrite(Fan, HIGH);
      digitalWrite(TV, HIGH);
      
    }
 
    else if(!(strncmp(str,"all off",7)))
    {
      digitalWrite(Light, LOW);
      digitalWrite(Fan, LOW);
      digitalWrite(TV, LOW);
     
    }     
}


