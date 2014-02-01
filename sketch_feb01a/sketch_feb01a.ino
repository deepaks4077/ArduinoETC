    const int switchPin = 2;// switch input; redundant
      const int right_motor1Pin = 3;// Right motor: H-bridge leg 1 (pin 2, 1A)
      const int right_motor2Pin = 4;// Right motor: H-bridge leg 2 (pin 7, 2A)
      const int enablePin = 9;// H-bridge enable pin
      const int left_motor1Pin = 6; // Left motor: H-bridge leg (pin 15, 4A)
      const int left_motor2Pin = 7; // Left motor: H-bridge leg ()
        
      
       void setup() {
        // set the switch as an input (redundant; delete?):
        pinMode(switchPin, INPUT);  
    
        // set all the other pins you're using as outputs:
        pinMode(right_motor1Pin, OUTPUT); 
        pinMode(right_motor2Pin, OUTPUT);
        pinMode(left_motor1Pin,OUTPUT); 
        pinMode(left_motor2Pin,OUTPUT); 
        pinMode(enablePin, OUTPUT);
        
        
        // set enablePin high so that motor can turn on:
        delay(5000);
        digitalWrite(enablePin, HIGH); 
      }
      
    void loop() {
        // Testing locomotion functions
        if(digitalRead(switchPin)==HIGH){
        leftOrRight(true,500);
        upOrDown(true,2000);
        leftOrRight(false,500);
        upOrDown(true,2000);
        leftOrRight(true,500);
        upOrDown(true,2000);
        leftOrRight(false,500);
        upOrDown(true,2000);
        }
        else{
         brake(true);
          
        }
        }
      
      
      void brake(boolean applyBrakes){
        if(applyBrakes){
          digitalWrite(right_motor1Pin, LOW);   
          digitalWrite(right_motor2Pin, LOW);  
          digitalWrite(left_motor1Pin, LOW);
          digitalWrite(left_motor2Pin, LOW);      
        }   
      }
      
      void leftOrRight(boolean right, int time){
         if(right){
          digitalWrite(right_motor1Pin, LOW);   // set leg 1 of the H-bridge low
          digitalWrite(right_motor2Pin, LOW);  // set leg 2 of the H-bridge high
          digitalWrite(left_motor1Pin, HIGH);
          digitalWrite(left_motor2Pin, LOW); 
          delay(time);
          brake(true);   
        }
      else {
          digitalWrite(right_motor1Pin, HIGH);   // set leg 1 of the H-bridge low
          digitalWrite(right_motor2Pin, LOW);  // set leg 2 of the H-bridge high
          digitalWrite(left_motor1Pin, LOW);
          digitalWrite(left_motor2Pin, LOW);
          delay(time);
          brake(true);  
      }   
      }
      
      void upOrDown(boolean up, int time){    
        if(up){
          digitalWrite(right_motor1Pin, LOW);   // set  1 of the H-bridge low
          digitalWrite(right_motor2Pin, HIGH);  // set leg 2 of the H-bridge high
          digitalWrite(left_motor1Pin, LOW);
          digitalWrite(left_motor2Pin, HIGH);   
          delay(time);
          brake(true);   
        }
        
      else {
          digitalWrite(right_motor1Pin, HIGH);   // set leg 1 of the H-bridge low
          digitalWrite(right_motor2Pin, LOW);  // set leg 2 of the H-bridge high
          digitalWrite(left_motor1Pin, HIGH);
          digitalWrite(left_motor2Pin, LOW);
          delay(time);
          brake(true);  
        } 
      }
