#define ledA1 2 //Green
#define ledA2 3 //Yellow
#define ledA3 4 //Red

#define ledB1 8
#define ledB2 9
#define ledB3 10

#define ledC1 52
#define ledC2 50
#define ledC3 48

#define ledD1 22
#define ledD2 24
#define ledD3 26

int a1, b1, c1, d1;

void setup() {
  
  Serial.begin(9600);

  pinMode(ledA1, OUTPUT);
  pinMode(ledA2, OUTPUT);
  pinMode(ledA3, OUTPUT);

  pinMode(ledB1, OUTPUT);
  pinMode(ledB2, OUTPUT);
  pinMode(ledB3, OUTPUT);

  pinMode(ledC1, OUTPUT);
  pinMode(ledC2, OUTPUT);
  pinMode(ledC3, OUTPUT);

  pinMode(ledD1, OUTPUT);
  pinMode(ledD2, OUTPUT);
  pinMode(ledD3, OUTPUT);
}

void readSensor()
{
  a1 = analogRead(A1);
  b1 = analogRead(A4);
  c1 = analogRead(A5);
  d1 = analogRead(A6);

if (a1 < 50) a1 = 1; else a1 = 0; 
if (b1 < 50) b1 = 1; else b1 = 0; 
if (c1 < 50) c1 = 1; else c1 = 0; 
if (d1 < 50) d1 = 1; else d1 = 0; 

Serial.print(a1);
Serial.print("\t");
Serial.print(b1);
Serial.print("\t");
Serial.print(c1);
Serial.print("\t");
Serial.print(d1);
Serial.print("\t");
}

void roadAopen()
{
  readSensor();
  
  digitalWrite(ledA3, LOW);

  digitalWrite(ledA1, HIGH);
  digitalWrite(ledB3, HIGH);
  digitalWrite(ledC3, HIGH);
  digitalWrite(ledD3, HIGH);
  delay(18000);
  digitalWrite(ledA1, LOW);
  digitalWrite(ledA2, HIGH);
  delay(8000);
  digitalWrite(ledA2, LOW);
  
}

void roadBopen()
{
  readSensor();

  digitalWrite(ledB3, LOW);

  digitalWrite(ledA3, HIGH);
  digitalWrite(ledB1, HIGH);
  digitalWrite(ledC3, HIGH);
  digitalWrite(ledD3, HIGH);
  delay(18000);
  digitalWrite(ledB1, LOW);
  digitalWrite(ledB2, HIGH);
  delay(8000);
  digitalWrite(ledB2, LOW);
  
}

void roadCopen()
{
  readSensor();
  digitalWrite(ledC3, LOW);

  digitalWrite(ledA3, HIGH);
  digitalWrite(ledB3, HIGH);
  digitalWrite(ledC1, HIGH);
  digitalWrite(ledD3, HIGH);
  delay(18000);
  digitalWrite(ledC1, LOW);
  digitalWrite(ledC2, HIGH);
  delay(8000);
  digitalWrite(ledC2, LOW);
  
}

void roadDopen()
{
  readSensor();
  digitalWrite(ledD3, LOW);

  digitalWrite(ledA3, HIGH);
  digitalWrite(ledB3, HIGH);
  digitalWrite(ledC3, HIGH);
  digitalWrite(ledD1, HIGH);
  delay(18000);
  digitalWrite(ledD1, LOW);
  digitalWrite(ledD2, HIGH);
  delay(8000);
  digitalWrite(ledD2, LOW);
  
}

void loop() {
   readSensor();
if (a1 == 1 && (b1 == 0 ||c1 == 0 || d1 == 0))
  {
    roadAopen();
  }
else if (b1 == 1 && (a1 == 0 ||c1 == 0 || d1 == 0))
  {
    roadBopen();
  }
else if (c1 == 1 && (b1 == 0 ||a1 == 0 || d1 == 0))
  {
    roadCopen();
  }
else if (d1 == 1 && (b1 == 0|c1 == 0 || a1 == 0))
  {
    roadDopen();
  }
/////////////////////////Road A=B,C,D////////////////////////////////////////////////
if (a1 == 1 && (b1 == 1 ||c1 == 0 || d1 == 0) )
  {
    roadAopen();
    if (b1 == 1 && (a1 == 1 ||c1 == 0 || d1 == 0) )
    {
      roadBopen();
    }
  }
  else if (a1 == 1 && (b1 == 0 ||c1 == 1 || d1 == 0) )
  {
    roadAopen();
    if (c1 == 1 && (a1 == 1 ||b1 == 0 || d1 == 0) )
    {
      roadCopen();
    }
  }
  else if (a1 == 1 && (b1 == 0 ||c1 == 0 || d1 == 1) )
  {
    roadAopen();
    if (d1 == 1 && (b1 == 0 ||c1 == 0 || a1 == 1) )
    {
      roadDopen();
    }
  }
/////////////////////////Road B=C,D,A////////////////////////////////////////////////
 else if (b1 == 1 && (c1 == 1 ||d1 == 0 || a1 == 0) )
  {
    roadBopen();
    if (c1 == 1 && (b1 == 1 ||c1 == 0 || d1 == 0) )
    {
      roadCopen();
    }
  }
  else if (b1 == 1 && (c1 == 0 ||d1 == 1 || a1 == 0) )
  {
    roadBopen();
    if (d1 == 1 && (b1 == 1 ||a1 == 0 || c1 == 0) )
    {
      roadDopen();
    }
  }
/////////////////////////Road C=D,A,B////////////////////////////////////////////////
 else if (c1 == 1 && (d1 == 1 ||b1 == 0 || a1 == 0) )
  {
    roadCopen();
    if (d1 == 1 && (c1 == 1 ||a1 == 0 || b1 == 0) )
    {
      roadDopen();
    }
  }
////////////////////////Road C=D,A,B////////////////////////////////////////////////
 else if (d1 == 1 && (a1 == 1 ||b1 == 0 || c1 == 0) )
  {
    roadDopen();
    if (a1 == 1 && (d1 == 1 ||c1 == 0 || b1 == 0) )
    {
      roadAopen();
    }
  }
//////////////////////////////////////////////////////////////////////////////////////////
  else if (b1 == 1 && (a1 == 0 ||c1 == 1 || d1 == 1) )
  {
    roadBopen();
    if (c1 == 1 && (a1 == 0 ||b1 == 1 || d1 == 1) )
    {
      roadCopen();
    }
    if (d1 == 1 && (b1 == 1 ||c1 == 1 || a1 == 0) )
    {
      roadDopen();
    }
  }
  else if (d1 == 1 && (b1 == 1 ||c1 == 1 || b1 == 0) )
  {
     roadAopen();
    
    if (c1 == 1 && (a1 == 1 ||d1 == 1 || b1 == 0) )
    {
     roadCopen();
    }
    if (c1 == 1 && (a1 == 0 ||b1 == 1 || b1 == 0) )
    {
      roadDopen();
    }
  else if (a1 == 1 && (b1 == 1 ||d1 == 1 || c1 == 0) )
  {
     roadAopen();
    
    if (b1 == 1 && (a1 == 1 ||d1 == 1 || c1 == 0) )
    {
     roadBopen();
    }
    if (d1 == 1 && (a1 == 1 ||b1 == 1 || c1 == 0) )
    {
      roadCopen();
    }
  }
  }
/////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////

  else if (a1 == 1 && (b1 == 1 ||c1 == 1 || d1 == 0) )
  {
    roadAopen();
    if (b1 == 1 && (a1 == 1 ||c1 == 1 || d1 == 0) )
    {
      roadBopen();
    }
    if (c1 == 1 && (b1 == 1 ||d1 == 0 || a1 == 1) )
    {
      roadCopen();
    }
  }
  else if (b1 == 1 && (a1 == 0 ||c1 == 1 || d1 == 1) )
  {
    roadBopen();
    if (c1 == 1 && (a1 == 0 ||b1 == 1 || d1 == 1) )
    {
      roadCopen();
    }
    if (d1 == 1 && (b1 == 1 ||c1 == 1 || a1 == 0) )
    {
      roadDopen();
    }
  }
  else if (d1 == 1 && (b1 == 1 ||c1 == 1 || b1 == 0) )
  {
     roadAopen();
    
    if (c1 == 1 && (a1 == 1 ||d1 == 1 || b1 == 0) )
    {
     roadCopen();
    }
    if (c1 == 1 && (a1 == 0 ||b1 == 1 || b1 == 0) )
    {
      roadDopen();
    }
  else if (a1 == 1 && (b1 == 1 ||d1 == 1 || c1 == 0) )
  {
     roadAopen();
    
    if (b1 == 1 && (a1 == 1 ||d1 == 1 || c1 == 0) )
    {
     roadBopen();
    }
    if (d1 == 1 && (a1 == 1 ||b1 == 1 || c1 == 0) )
    {
      roadCopen();
    }
  }
  }
/////////////////////////////////////////////////////////////////////////
  
  else if (a1 == 0 && b1 == 0 && c1 == 0 && d1 == 0)
  {
    roadAopen();
    if (a1 == 0 && b1 == 0 && c1 == 0 && d1 == 0)
    {
      roadBopen();
    }
    if (a1 == 0 && b1 == 0 && c1 == 0 && d1 == 0)
    {
      roadCopen();
    }
    if (a1 == 0 && b1 == 0 && c1 == 0 && d1 == 0)
    {
      roadDopen();
    }
  }
  else if (a1 == 1 && (b1 == 1 ||c1 == 1 || d1 == 1) )
  {
    roadAopen();
    if (b1 == 1 && (a1 == 1 ||c1 == 1 || d1 == 1) )
    {
      roadBopen();
    }
    if (c1 == 1 && (b1 == 1 ||d1 == 1 || a1 == 1) )
    {
      roadCopen();
    }
    if (d1 == 1 && (b1 == 1 ||c1 == 1 || a1 == 1) )
    {
      roadDopen();
    }
  }
  
}
