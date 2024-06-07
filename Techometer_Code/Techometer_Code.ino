 #Transmit code
 intval;
 intir=A1;
 Long last=0;
 int stat;
 int stat2=LOW;
 int counter=0;
 int rpm;
 intsens=200;
 intmilisec=1000;
 void setup()
 {Serial.begin(38400);
 pinMode(ir,INPUT);}
 void loop(){ val=analogRead(ir); if(val<sens)
 { stat=HIGH; } else {
 stat=LOW; }
 if(stat2!=stat) { counter++; stat2=stat; } if(millis()-last>=milisec)
 { rpm=(counter/2.0);
 Serial.write(rpm);
 counter=0;
 last=millis();
 }
 }
 #Receiver code
 #include <LiquidCrystal.h>
 LiquidCrystallcd(10,12,14,16,18,19);
 int data=0;
 int rpm=0;
 intmilisec=2000;
 if(Serial.available() > 0){
 data = Serial.read();
 
 rpm=data*60000.0/(milisec);
 lcd.clear();
 lcd.setCursor(0,1);
 lcd.print(rpm); }
 }