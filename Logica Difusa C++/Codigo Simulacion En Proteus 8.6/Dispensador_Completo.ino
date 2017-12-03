#include <LiquidCrystal.h>
#include <Servo.h>
LiquidCrystal lcd(20, 21, 22, 23, 24, 25);
Servo myservo;  
int pos = 0;    
int pintar=0;
int envases_llenados=0;
const int ledCount = 10;    
int vaso1=0;
int vaso2=0;
int ledPins[] = {6, 7, 10, 11, 12, 13, 14, 15, 16, 17};  



void setup()  
   {
       lcd.begin(16, 2); 
       lcd.print("GRAMOS"); 
       myservo.attach(0);  
       myservo.write(0);
        
        for (int thisLed = 0; thisLed < ledCount; thisLed++) {
          pinMode(ledPins[thisLed], OUTPUT);
        }
        for (int thisLed = 0; thisLed < ledCount; thisLed++) {   
          digitalWrite(ledPins[thisLed], HIGH);
        }
   }

void loop() 
   {

      //SENSOR LUZ
      int sensorLuz = analogRead(A1);
      int ID_envase=0;
     
    
      
      if(sensorLuz>402){
        ID_envase=1;
        // lcd.print("ENCENDIDO");

        
      }else if(sensorLuz<=402){ 
        ID_envase=2;
      //lcd.print("APAGADO");

      
      }
      
      int sensorValue = analogRead(A0);
      int respaldo=0;
      int contador=0;
     
      lcd.setCursor(0, 8);
      delay(20);
      lcd.clear();
      lcd.print("GRAMOS"); 
      lcd.setCursor(0, 8);
      if(respaldo!=sensorValue){
     
        contador=0;
      }
     

      ////////ENVASE GRANDE////
      
      //PESO DE 0 A 90 GR
      
      if(ID_envase==1){
        
      if(sensorValue==985&&contador==0){
         lcd.print("0");
      }
      if(sensorValue==972&&contador==0){
         lcd.print("20");
         contador=1;myservo.write(40); 
                    
      }
      if(sensorValue==960&&contador==0){
         lcd.print("40");  contador=1;
         myservo.write(43);              
      }
        if(sensorValue==947&&contador==0){
         lcd.print("60");  contador=1;
         myservo.write(46);              
      }
      if(sensorValue==934&&contador==0){
         lcd.print("80");  contador=1;
         myservo.write(49);              
      }
      if(sensorValue==922&&contador==0){
         lcd.print("100");  contador=1;
         myservo.write(52);     
         
                            
      }
      if(sensorValue==909&&contador==0){
         lcd.print("120");  contador=1;
         myservo.write(55);             
      }
        if(sensorValue==896&&contador==0){
         lcd.print("140");  contador=1;
         myservo.write(58);              
      }
       if(sensorValue==884&&contador==0){
         lcd.print("160");myservo.write(61); contador=1;
      }
      if(sensorValue==871&&contador==0){
         lcd.print("180");myservo.write(64); contador=1;
      }
      
      //PESO DE 100 Gr a 190 Gr
      
      if(sensorValue==858&&contador==0){
         lcd.print("200");myservo.write(67); contador=1;
         
      }
       if(sensorValue==846&&contador==0){
         lcd.print("220");myservo.write(70); contador=1;
      }
      if(sensorValue==833&&contador==0){
         lcd.print("240");myservo.write(73); contador=1;
         if(envases_llenados==0){digitalWrite(6, LOW);
         
         }
         if(envases_llenados==1){digitalWrite(13, LOW);
       
         }
      }
      if(sensorValue==820&&contador==0){
         lcd.print("260");myservo.write(76); contador=1;
      }
        if(sensorValue==808&&contador==0){
         lcd.print("280");myservo.write(79); contador=1;
      }
      if(sensorValue==795&&contador==0){
         lcd.print("300");myservo.write(82); contador=1;
      }
      if(sensorValue==782&&contador==0){
         lcd.print("320");myservo.write(90); contador=1;
      }
      if(sensorValue==770&&contador==0){
         lcd.print("340");myservo.write(95); contador=1;
      }
        if(sensorValue==757&&contador==0){
         lcd.print("360");myservo.write(100); contador=1;
      }
       if(sensorValue==744&&contador==0){
         lcd.print("380");myservo.write(105); contador=1;
      }
      
      //PESO de 200gr a 290
      
       if(sensorValue==732&&contador==0){
         lcd.print("400");myservo.write(110); contador=1;
      }
       if(sensorValue==719&&contador==0){
         lcd.print("420");myservo.write(115); contador=1;
      }
      if(sensorValue==706&&contador==0){
         lcd.print("440");myservo.write(120); contador=1;
      }
      if(sensorValue==694&&contador==0){
         lcd.print("460");myservo.write(125); contador=1;
      }
        if(sensorValue==681&&contador==0){
         lcd.print("480");myservo.write(130); contador=1;
      }
      if(sensorValue==669&&contador==0){
         lcd.print("500");myservo.write(135); contador=1;
      }
      if(sensorValue==656&&contador==0){
         lcd.print("520");myservo.write(140); contador=1;
      }
      if(sensorValue==643&&contador==0){
         lcd.print("540");myservo.write(145); contador=1;
      }
        if(sensorValue==631&&contador==0){
         lcd.print("560");myservo.write(150); contador=1;
      }
       if(sensorValue==618&&contador==0){
         lcd.print("580");myservo.write(155); contador=1;
         if(envases_llenados==0){digitalWrite(7, LOW);
         
         }
         if(envases_llenados==1){digitalWrite(14, LOW);
       
         }
      }
    

      //PESO de 300 a 390
       if(sensorValue==605&&contador==0){
         lcd.print("600");myservo.write(160); contador=1;
      }
       if(sensorValue==593&&contador==0){
         lcd.print("620");myservo.write(155); contador=1;
      }
      if(sensorValue==580&&contador==0){
         lcd.print("640");myservo.write(150); contador=1;
      }
      if(sensorValue==567&&contador==0){
         lcd.print("660");myservo.write(145); contador=1;
      }
        if(sensorValue==555&&contador==0){
         lcd.print("680");myservo.write(140); contador=1;
      }
      if(sensorValue==542&&contador==0){
         lcd.print("700");myservo.write(135); contador=1;
      }
      if(sensorValue==530&&contador==0){
         lcd.print("720");myservo.write(130); contador=1;
         if(envases_llenados==0){digitalWrite(10, LOW);
         
         }
         if(envases_llenados==1){digitalWrite(15, LOW);
       
         }

         
      }
      if(sensorValue==517&&contador==0){
         lcd.print("740");myservo.write(125); contador=1;
      }
        if(sensorValue==504&&contador==0){
         lcd.print("760");myservo.write(120); contador=1;
      }
       if(sensorValue==492&&contador==0){
         lcd.print("780");myservo.write(115); contador=1;
      }
      //PESO de 4 a 490
       if(sensorValue==479&&contador==0){
         lcd.print("800");myservo.write(110); contador=1;
         
       
      }
       if(sensorValue==466&&contador==0){
         lcd.print("820");myservo.write(105); contador=1;
      }
      if(sensorValue==454&&contador==0){
         lcd.print("840");myservo.write(100); contador=1;
      }
      if(sensorValue==441&&contador==0){
         lcd.print("860");myservo.write(95); contador=1;
      }
        if(sensorValue==429&&contador==0){
         lcd.print("880");myservo.write(90); contador=1;
      }
      if(sensorValue==416&&contador==0){
         lcd.print("900");myservo.write(82); contador=1;
         
      }
      if(sensorValue==403&&contador==0){
         lcd.print("920");myservo.write(79); contador=1;
      }
      if(sensorValue==391&&contador==0){
         lcd.print("940");myservo.write(76); contador=1;
      }
        if(sensorValue==378&&contador==0){
         
         lcd.print("960");myservo.write(73); contador=1;
         if(envases_llenados==0){digitalWrite(11, LOW);
         
         }
         if(envases_llenados==1){digitalWrite(16, LOW);
       
         }
        }
       if(sensorValue==366&&contador==0){
       
         lcd.print("980");myservo.write(70); contador=1;
      }
      //PESO de 500 a 590
       if(sensorValue==353&&contador==0){
       
         lcd.print("1000");myservo.write(67); contador=1;
        
         
       
      }
       if(sensorValue==340&&contador==0){
   
         lcd.print("1020"); contador=1;myservo.write(64);
      }
      if(sensorValue==328&&contador==0){
         
         lcd.print("1040"); contador=1;myservo.write(61);
      }
      if(sensorValue==315&&contador==0){
         lcd.print("1060"); contador=1;myservo.write(58);
      }
        if(sensorValue==303&&contador==0){
         lcd.print("1080"); contador=1;myservo.write(55);
      }
      if(sensorValue==290&&contador==0){
         lcd.print("1100"); contador=1;myservo.write(52);
      }
      if(sensorValue==277&&contador==0){
         lcd.print("1120");; contador=1;myservo.write(49);
      }
      if(sensorValue==265&&contador==0){
         lcd.print("1140");; contador=1;myservo.write(46);
      }
        if(sensorValue==252&&contador==0){
         lcd.print("1160"); contador=1;myservo.write(43);
      }
       if(sensorValue==240&&contador==0){
         lcd.print("1180"); contador=1;myservo.write(40);
      }
      
      //PESO de 600 a 690
      
      if(sensorValue==227&&contador==0){
         lcd.print("1200"); contador=1;myservo.write(40);
         if(envases_llenados==1&&vaso2==1){
          digitalWrite(17, LOW);
         //Colocar mensaje que se acabo los granos tolva vacia
         lcd.print("Envase LLeno 2 ");
    
         }
         if(envases_llenados==0){
           digitalWrite(12, LOW);
          envases_llenados=envases_llenados+1;
          
         lcd.print("Envase LLeno 2");
         vaso1=1;
         }
         if(vaso1==1){
          lcd.print("Envase LLeno 2");
         }
         
      }
      
      }
      //FIN DE LA EVALUACION SI ES ENVASE GRANDE
       //ENVASE GRANDE
       






      //ENVASE PEQUE:O////
      if(ID_envase==2){
      //PESO DE 0 A 90 GR
      
      if(sensorValue==985&&contador==0){
         lcd.print("0");

         
      
       
      }
      if(sensorValue==972&&contador==0){
         lcd.print("20");
         contador=1;myservo.write(40); 
                    
      }
      if(sensorValue==960&&contador==0){
         lcd.print("40");  contador=1;
         myservo.write(43);             
      }
        if(sensorValue==947&&contador==0){
         lcd.print("60");  contador=1;
         myservo.write(46);              
      }
      if(sensorValue==934&&contador==0){
         lcd.print("80");  contador=1;
         myservo.write(49);           
      }
      if(sensorValue==922&&contador==0){
         lcd.print("100");  contador=1;
         myservo.write(52);     
         
      }
      if(sensorValue==909&&contador==0){
         lcd.print("120");  contador=1;
         myservo.write(55);              
      }
        if(sensorValue==896&&contador==0){
         lcd.print("140");  contador=1;
         myservo.write(58);              
      }
       if(sensorValue==884&&contador==0){
         lcd.print("160");myservo.write(61); contador=1;
      }
      if(sensorValue==871&&contador==0){
         lcd.print("180");myservo.write(64); contador=1;
      }
      
      //PESO DE 100 Gr a 190 Gr
      
      if(sensorValue==858&&contador==0){
         lcd.print("200");myservo.write(67); contador=1;
         if(envases_llenados==0){digitalWrite(6, LOW);
         
         }
         if(envases_llenados==1){digitalWrite(13, LOW);
       
         }
      }
       if(sensorValue==846&&contador==0){
         lcd.print("220");myservo.write(70); contador=1;
      }
      if(sensorValue==833&&contador==0){
         lcd.print("240");myservo.write(73); contador=1;
      }
      if(sensorValue==820&&contador==0){
         lcd.print("260");myservo.write(76); contador=1;
      }
        if(sensorValue==808&&contador==0){
         lcd.print("280");myservo.write(79); contador=1;
      }
      if(sensorValue==795&&contador==0){
         lcd.print("300");myservo.write(88); contador=1;
         
      }
      if(sensorValue==782&&contador==0){
         lcd.print("320");myservo.write(96); contador=1;
      }
      if(sensorValue==770&&contador==0){
         lcd.print("340");myservo.write(104); contador=1;
      }
        if(sensorValue==757&&contador==0){
         lcd.print("360");myservo.write(112); contador=1;
      }
       if(sensorValue==744&&contador==0){
         lcd.print("380");myservo.write(120); contador=1;
      }
      
      //PESO de 200gr a 290
      
       if(sensorValue==732&&contador==0){
         lcd.print("400");myservo.write(128); contador=1;
         if(envases_llenados==0){digitalWrite(7, LOW);
         
         }
         if(envases_llenados==1){digitalWrite(14, LOW);
       
         }
      }
       if(sensorValue==719&&contador==0){
         lcd.print("420");myservo.write(136); contador=1;
      }
      if(sensorValue==706&&contador==0){
         lcd.print("440");myservo.write(144); contador=1;
      }
      if(sensorValue==694&&contador==0){
         lcd.print("460");myservo.write(152); contador=1;
      }
        if(sensorValue==681&&contador==0){
         lcd.print("480");myservo.write(160); contador=1;
      }
      if(sensorValue==669&&contador==0){
         lcd.print("500");myservo.write(160); contador=1;
      }
      if(sensorValue==656&&contador==0){
         lcd.print("520");myservo.write(152); contador=1;
      }
      if(sensorValue==643&&contador==0){
         lcd.print("540");myservo.write(144); contador=1;
      }
        if(sensorValue==631&&contador==0){
         lcd.print("560");myservo.write(136); contador=1;
      }
       if(sensorValue==618&&contador==0){
         lcd.print("580");myservo.write(128); contador=1;
      }
    

      //PESO de 300 a 390
       if(sensorValue==605&&contador==0){
         lcd.print("600");myservo.write(120); contador=1;
         if(envases_llenados==0){digitalWrite(10, LOW);
         
         }
         if(envases_llenados==1){digitalWrite(15, LOW);
       
         }
      }
       if(sensorValue==593&&contador==0){
         lcd.print("620");myservo.write(112); contador=1;
      }
      if(sensorValue==580&&contador==0){
         lcd.print("640");myservo.write(104); contador=1;
      }
      if(sensorValue==567&&contador==0){
         lcd.print("660");myservo.write(96); contador=1;
      }
        if(sensorValue==555&&contador==0){
         lcd.print("680");myservo.write(88); contador=1;
      }
      if(sensorValue==542&&contador==0){
         lcd.print("700");myservo.write(80); contador=1;
      }
      if(sensorValue==530&&contador==0){
         lcd.print("720");myservo.write(76); contador=1;
      }
      if(sensorValue==517&&contador==0){
         lcd.print("740");myservo.write(73); contador=1;
      }
        if(sensorValue==504&&contador==0){
         lcd.print("760");myservo.write(70); contador=1;
      }
       if(sensorValue==492&&contador==0){
         lcd.print("780");myservo.write(67); contador=1;
      }
      //PESO de 4 a 490
       if(sensorValue==479&&contador==0){
         lcd.print("800");myservo.write(64); contador=1;
         if(envases_llenados==0){digitalWrite(11, LOW);
         
         }
         if(envases_llenados==1){digitalWrite(16, LOW);
       
         }
      }
       if(sensorValue==466&&contador==0){
         lcd.print("820");myservo.write(61); contador=1;
      }
      if(sensorValue==454&&contador==0){
         lcd.print("840");myservo.write(58); contador=1;
      }
      if(sensorValue==441&&contador==0){
         lcd.print("860");myservo.write(55); contador=1;
      }
        if(sensorValue==429&&contador==0){
         lcd.print("880");myservo.write(52); contador=1;
      }
      if(sensorValue==416&&contador==0){
         lcd.print("900");myservo.write(49); contador=1;
      }
      if(sensorValue==403&&contador==0){
         lcd.print("920");myservo.write(47); contador=1;
      }
      if(sensorValue==391&&contador==0){
         lcd.print("940");myservo.write(44); contador=1;
      }
        if(sensorValue==378&&contador==0){
         
         lcd.print("960");myservo.write(41); contador=1;
      }
       if(sensorValue==366&&contador==0){
       
         lcd.print("980");myservo.write(40); contador=1;
      }
      //PESO de 500 a 590
       if(sensorValue==353&&contador==0){
       
         lcd.print("1000");myservo.write(40); contador=1;
         if(envases_llenados==1&&vaso1==1){
          digitalWrite(17, LOW);
         
         lcd.print("Envase LLeno 1");
         
       
         } 
          if(envases_llenados==0){
            digitalWrite(12, LOW);
          envases_llenados=envases_llenados+1;
          
         lcd.print("Envase LLeno 1");
         vaso2=1;
         }
         if(vaso2==1){
          lcd.print("Envase LLeno 1");
         }
         
        }
      
      }
      
      //FIn de envase peque;o
      


       
       respaldo=sensorValue;
   }
