void setup()
{
  Serial.begin(9600);
}

void loop() {

  int sensorValue = analogRead(A0);
  Serial.println(sensorValue);

  if (sensorValue < 420) {
    Serial.println(" SHOOT!");
    digitalWrite(13, HIGH);
  }
  else {
    digitalWrite(13, LOW);
  }

  delay(1);
}
