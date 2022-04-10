//Receiver Code
int pin =A0;
char incomingByte = 0;
int  ascii_value =0;
void setup() {
  Serial.begin(9600); 
  pinMode(pin, INPUT);
  pinMode(7, OUTPUT);
Serial.print(" Data Received:");
}

void loop()
{ 
  Serial.println("");
  Serial.print(" Data transmitted:");    
    while(Serial.available()>0)
    {
  int a = 0;
  incomingByte = Serial.read();
  ascii_value = incomingByte; 
  String thisString = String(ascii_value,BIN);
  a = thisString.length();

  Serial.print(incomingByte);
//  Serial.print("ASCII value is:");
//  Serial.println(ascii_value);
//  Serial.print("Binary form is:");
//  Serial.println(thisString);
//  Serial.print("length of string is:");
//  Serial.println(a);
//  Serial.print("8-bits transmitted after 0 padding: ");
  switch(a)
  {
    case 6:
    digitalWrite(7,HIGH);
   // Serial.print("1");
    delay(10);
    digitalWrite(7,LOW);
   // Serial.print("0");
    delay(10);
    for(int i=0; i<a; i++)
    {
     // Serial.print(thisString[i]);
      if(thisString[i] == '1')
      { 
        digitalWrite(7,HIGH);
        //Serial.println("HIGH");
      }
      else
      {
        digitalWrite(7,LOW);
        //Serial.println("LOW");
      }
      delay(10);
      digitalWrite(7,LOW);
     }
     break;
     
     default:
         digitalWrite(7,HIGH);
     //    Serial.print("1");
         delay(10);
         for(int i=0; i<a; i++)
         {
        //    Serial.print(thisString[i]);
            if(thisString[i] == '1')
            { 
              digitalWrite(7,HIGH);
              //Serial.println("HIGH");
            }
            else
            {
              digitalWrite(7,LOW);
              //Serial.println("LOW");
            }
            delay(10);
            digitalWrite(7,LOW);
          }
   }
  // Serial.print(" ");
  
   delay(10);
    }

   
  int arrayone[] = {0,0,0,0,0,0,0};
  int a;
  int bit = analogRead(pin);
//    Serial.println("");
    
  if(bit >= 130)
  { 
    char data = 0;
    int asciivalue=0;
   // Serial.print("8-Bit data received is:");
    delay(10);

   // Serial.print("1");
    for(int i =0;i<7;i++)
    {
      bit = analogRead(pin);
      if(bit >= 130)
      {
        arrayone[i] = 1;
    //    Serial.print("1");
      }
      else
      {
        arrayone[i] = 0;
      //  Serial.print("0");
      }
      delay(10);
    }
    //  Serial.println(" ");
    //  Serial.print("string is:");
      int m=64;
      for(int i =0;i<7;i++)
        {
          int x = arrayone[i];
          asciivalue = asciivalue+ m*x;
      //    Serial.print(arrayone[i]);
          m=m/2;
        } 
        data = asciivalue;
      //Serial.print("ASCII value is:");
      //Serial.println(asciivalue);
      Serial.print(data);
    }
  else
  {
    a =0;
  }
}
