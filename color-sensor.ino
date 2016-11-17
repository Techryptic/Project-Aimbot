//Color recognition TCS230

const int s0 = 8;
const int s1 = 9;
const int s2 = 12;
const int s3 = 11;
const int out = 10;

// Variables
int rCount = 0;
int gCount = 0;
int bCount = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(out, INPUT);
  digitalWrite(s0, HIGH);
  digitalWrite(s1, HIGH);
}

void loop()
{
  color();
  Serial.print("R : ");
  Serial.print(rCount, DEC);
  Serial.print(" G : ");
  Serial.print(gCount, DEC);
  Serial.print(" B : ");
  Serial.print(bCount, DEC);
  //Serial.println();

  if (rCount < bCount && rCount < gCount && rCount && rCount < 80)
  {
   Serial.println(" - Red");
   digitalWrite(13, HIGH);
  }
  else if (bCount < rCount && bCount < gCount)
  {
   Serial.println(" - Blue");
   digitalWrite(13, LOW);
  }
  else if (gCount < rCount && gCount < bCount)
  {
   Serial.println(" - Green");
   digitalWrite(13, LOW);
  }
  else{
   Serial.println();
   digitalWrite(13, LOW);
  }
}

void color()
{
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);
  //count OUT, pRed, RED
  rCount = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
  digitalWrite(s3, HIGH);
  //count OUT, pBLUE, BLUE
  bCount = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
  digitalWrite(s2, HIGH);
  //count OUT, pGreen, GREEN
  gCount = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
}
