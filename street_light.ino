int led = 3;
int led1 = 10;
int led2 = 5;
int led3 = 6;
int led4 = 9;

int ldr = A0;

int x1, x2, x3, x4,x5;

void setup() 
{
  Serial.begin (9600);
  pinMode (led,OUTPUT);
  pinMode (led1,OUTPUT);
  pinMode (led2,OUTPUT);
  pinMode (led3,OUTPUT);
  pinMode (led4,OUTPUT);
  
  pinMode (ldr,INPUT);
  
}
void loop() 
{
 
  int ldrStatus = analogRead (ldr);
    if (ldrStatus <=300)
     {
       //digitalWrite(led, HIGH);
       //analogWrite(led,255/5);
       
     //  digitalWrite(led1, HIGH);
      // analogWrite(led1,255/5); 
       
      // digitalWrite(led2, HIGH);
      // analogWrite(led2,255/5);
       
       //digitalWrite(led3, HIGH);
       //analogWrite(led3,255/5);
       
      // digitalWrite(led4, HIGH);
      // analogWrite(led4,255/5);

/*Serial.print("A1");
       Serial.println(analogRead(A1));
Serial.print("A2");
       Serial.println(analogRead(A2));
   Serial.print("A3");
       Serial.println(analogRead(A3));
      Serial.print("A4");
       Serial.println(analogRead(A4));

       Serial.print("A5");
       Serial.println(analogRead(A5));*/
        
       
           if (analogRead(A1)<500)       // IR 1 CODE    
               {
                x1=0;
                x2=1;
                
                digitalWrite(led,HIGH);
                
                digitalWrite(led1,HIGH);
                  delay(100);// micro second
                    
               } 
            else 
                {
                  if(x1==0){
                  digitalWrite(led,HIGH);
                analogWrite(led,255/5); 
                delay(50);  
                  }
                }      
          
          if (analogRead(A2)<500)           // IR 2 CODE
               {
                x2=0;
                x3=1;
                 digitalWrite(led1,HIGH);
                  digitalWrite(led2,HIGH);
                  delay(100);// micro second
               } 
            else 
                {
                  if(x2==0)
                  {
                  digitalWrite(led1,HIGH);
                analogWrite(led1,255/5); 
                delay(50);
                
                  }
                }
           
           if (analogRead(A3)<500)           // IR 3 CODE
               {
                x3=0;
                x4=1;
                  digitalWrite(led2,HIGH);
                   digitalWrite(led3,HIGH);
                  delay(100);// micro second
               } 
            else 
                {
                  if(x3==0)
                  {
                  digitalWrite(led2,HIGH);
                analogWrite(led2,255/5); 
                delay(50);
                  }
                } 
                
                if (analogRead(A4)<500)       // IR 4 CODE      
               {
                x4=0;
                digitalWrite(led3,HIGH);
                  delay(100);// micro second
               } 
            else 
                {
                  if(x4==0){
                    
                  
                 digitalWrite(led3,HIGH);
                analogWrite(led3,255/5); 
                 delay(50);
                  
                  }  
                }
                
                if (analogRead(A5)<500)        // IR 5 CODE    
               {
                  x1=1;
                  digitalWrite(led4,HIGH);
                  
                   digitalWrite(led,HIGH);
                 
                  delay(100);// micro second
               } 
            else 
                {
                 digitalWrite(led4,HIGH);
                analogWrite(led4,255/5); 
                delay(50);
                 
                }
        }     
     else 
       {
         digitalWrite(led, LOW);
         digitalWrite(led1, LOW);
         digitalWrite(led2, LOW);
         digitalWrite(led3, LOW);
         digitalWrite(led4, LOW);
      }
     
}

