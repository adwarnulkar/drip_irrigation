void setup()
{
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(12, OUTPUT);
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
    digitalWrite(LED_BUILTIN, LOW); // Goes to active low relay (normally open gets closed)
    delay(2000);
    Serial.println("WATER PUMP IS ON !!");
    digitalWrite(12,HIGH); //Indicates water pump is on
    
  }
  else
  {
    digitalWrite(LED_BUILTIN, HIGH); // Goes to active low relay (normally open gets opened)
    delay(2000);
    Serial.println("WATER PUMP IS OFF !!");
    digitalWrite(12,LOW); //Indicates water pump is off
  }
  
  
}
