int flexs1 = 0;
int flexs2 = 1;
int flexs3 = 2;
int data1 = 0; 
int data2 = 0;
int data3 = 0;

void setup()
{
  Serial.begin(9600); 
  pinMode(flexs1, INPUT);
  pinMode(flexs2, INPUT);
  pinMode(flexs3, INPUT);
}

void loop()
{  
   data1 = analogRead(flexs1); 
   data2 = analogRead(flexs2); 
   data3 = analogRead(flexs3);

   
//   Serial.print("value1:");
//   Serial.println(data1); 
//   Serial.print("value2:");
//   Serial.println(data2); 
//   Serial.print("value3:");
//   Serial.println(data3);
  if(Serial.available()>=0)
  {
 if( (data1>=109&&data1 <115) && data2>110 && data3<56 ) 
  {
    Serial.println("Come Here");
  }

  if( (data1>=109&&data1 <115) && (data2>110 && data3>=56 ) ) 
  {
    Serial.println("Hii");
  }
   if( (data1>=102&&data1 <109) && (data2>110 && data3>=56 ) ) 
  {
    Serial.println("Washroom");
  }
  if( (data1>=102&&data1 <109)  && data3<56 )  
  {
    Serial.println("water");
  }
 
  delay(3000); 
  } 
}   
