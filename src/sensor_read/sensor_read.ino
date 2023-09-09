void setup()
{
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(A0, INPUT);
  
}

const int THRESHOLD = 500;

void loop()
{
  
  int soilDryness = analogRead(A0);
  delay(100);
  
  Serial.print("Soil Dryness is : ");
  Serial.print(soilDryness);
  Serial.print("\t");
  
  if (soilDryness > THRESHOLD)
  {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(2000);
    Serial.println("WATER PUMP IS ON !!");
    
  }
  else
  {
    digitalWrite(LED_BUILTIN, LOW);
    delay(2000);
    Serial.println("WATER PUMP IS OFF !!");
  }
  
  
}
