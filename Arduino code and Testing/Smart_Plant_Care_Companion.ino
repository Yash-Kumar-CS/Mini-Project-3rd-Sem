
int moisture = 0;

void setup()
{
  pinMode(A0, OUTPUT);
  pinMode(A1, INPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  // Apply power to the soil moisture sensor
  digitalWrite(A0, HIGH);
  analogWrite(13, LOW);
  delay(10); // Wait for 10 millisecond(s)
  moisture = analogRead(A1);
  // Turn off the sensor to reduce metal corrosion
  // over time
  digitalWrite(A0, LOW);
  Serial.println(moisture);
  if (moisture < 200) {
    
    Serial.println(moisture);
    Serial.println("no water needed");
  }
  else if (moisture > 400) {
      
      Serial.println(moisture);
      Serial.println("need water");
      Serial.println("motor on");
      analogWrite(13, HIGH);
      delay(3000);
      Serial.println("motor off");
    } 
  
  delay(2000);
  
}
