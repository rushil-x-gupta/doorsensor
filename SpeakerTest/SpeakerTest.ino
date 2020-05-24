const int sensor = 4;
const int buzzer = 3;
const int soundTime = 1000;
const int offTime = 1000;
const int loopDelay = 200;
int state;
float duration = 0;
float beepTrigger = 0.1; //in minutes


void setup() 
{
  // put your setup code here, to run once:
    pinMode(sensor, INPUT);
//    Serial.begin(9600);
    beepTrigger = beepTrigger * 60000; //converts beeptrigger to ms
}

void loop() 
{
    state = digitalRead(sensor);
//    Serial.println(state);
    

    if (state == LOW) { //LOW means door is open
      if (duration >= beepTrigger){
        duration = beepTrigger;  
      }
      else{
        duration = duration + loopDelay;  
      }
//      Serial.print("duration = ");
//      Serial.println(duration);  
//      Serial.println("Door open");
    }
    else{
      noTone(buzzer);
//      Serial.println("Door close");
      duration = 0;
    }

    if (duration >= beepTrigger){
      tone(buzzer, 400);
      digitalWrite(5, HIGH);  
      delay(soundTime);
      noTone(buzzer);
      digitalWrite(5, LOW);
      delay(offTime);  
    }  


    
    delay(loopDelay);
}

