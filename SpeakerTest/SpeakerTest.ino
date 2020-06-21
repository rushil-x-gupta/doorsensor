const int light = 5; //indicator LED pin
const int sensor = 4; //sensor pin
const int buzzer = 3; //speaker pin
const int soundTime = 1000; //length of sound in ms
const int offTime = 1000; //length of silence in ms
const int loopDelay = 200; 
int state; //circuit status ON/OFF
float duration = 0; //base value
float beepTrigger = 0.1; //in minutes

//bing bong ding dong

// MAKE SURE DTR is connected properly

void setup() 
{
  // put your setup code here, to run once:
    pinMode(sensor, INPUT);
    Serial.begin(9600);
    beepTrigger = beepTrigger * 60000; //converts beepTrigger to ms
}

void loop() 
{
    state = digitalRead(sensor); //checks status of sensor
    Serial.println(state); //prints status in serial monitor
    

    if (state == LOW) { //LOW means door is open
      if (duration >= beepTrigger){
        duration = beepTrigger;  
      }
      else{
        duration = duration + loopDelay;  
      }
      Serial.print("duration = ");
      Serial.println(duration);  
      Serial.println("Door open");
    }
    else{
      noTone(buzzer);
      Serial.println("Door close");
      duration = 0;
    }

    if (duration >= beepTrigger){
      tone(buzzer, 400);
      digitalWrite(light, HIGH);  
      delay(soundTime);
      noTone(buzzer);
      digitalWrite(light, LOW);
      delay(offTime);  
    }  


    
    delay(loopDelay);
}
