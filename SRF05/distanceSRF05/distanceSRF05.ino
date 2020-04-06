#define TRIG_PIN 8
#define ECHO_PIN 7
#define TIME_OUT 5000
 
float GetDistance()
{
  long duration, distanceCm;
   
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  duration = pulseIn(ECHO_PIN, HIGH, TIME_OUT);
  distanceCm = duration / 29.1 / 2;
  
  return distanceCm;
}
 
void setup() {  
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  logoConsole();
  
}
 
void loop() {
  long distance = GetDistance();
 
  if (distance <= 0)
  {
    Serial.println("Time out !");
  }
  else
  {   
    Serial.print("Distance(cm): ");
    Serial.println(distance);
  }
  delay(1000);
}

void logoConsole() {
  Serial.printf("----------------------\\\\\n");
  Serial.printf("|| EPCBTechEPCBTechEPCB ||\n");
  Serial.printf("|| P                  T ||\n");
  Serial.printf("|| C      .*.         e ||\n");
  Serial.printf("|| B      * *  .*.    c ||\n");
  Serial.printf("|| T***.  * *  * `****h ||\n");
  Serial.printf("|| e   `**' *  *      E ||\n");
  Serial.printf("|| c        `**'      P ||\n");
  Serial.printf("|| h                  C ||\n");
  Serial.printf("|| EPCBTechEPCBTechEPCB ||\n");
  Serial.printf("----------------------//\n");
  Serial.printf("//---------------------------------------------------------------------------------\\\\\n");
  Serial.printf("||   __ _                            _   _  _             _ _                          ||\n");
  Serial.printf("||  / __| |_   _ _ _ _  _ _   ___| | |  \\/  | __  _ _ () |_ _  _ __                   ||\n");
  Serial.printf("|| | |   | '_ \\ / ` | ' \\| '_ \\ / _ \\ | | |\\/| |/ _ \\| '_ \\| | __/ _ \\| '__|   ||\n");
  Serial.printf("|| | |___| | | | (| | | | | | | |  __/ | | |  | | () | | | | | || (_) | | \            ||\n");
  Serial.printf("||  \\____|_| |_|\\__,_|_| |_|_| |_|\\___|_| |_|  |_|\\___/|_| |_|_|\\__\\___/|_|      ||\n");
  Serial.printf("\\\\---------------------------------------------------------------------------------//  \n");
}
