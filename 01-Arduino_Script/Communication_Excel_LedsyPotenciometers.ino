//Inputs
const int Analogic1 = 15, Analogic2 = 19;   

//Outputs
  const int Led1 =  3, Led2 =  5, Led3 =  6;
  const int Tension = 8;
  
  String myStrL, myStrR;
  int VpwmL, VpwmR ;
  int EntradaL=2000, EntradaR=2001;
  int LecturaAnalogL, LecturaAnalogR;
  int serialByte;
  int Entrada=0;
  int SendLineal=0, SendRotational=0;
void setup() {
    Serial.begin(9600);
    //OUTPUTS  
    pinMode(Led1, OUTPUT);  
    pinMode(Led2, OUTPUT); 
    pinMode(Led3, OUTPUT);   
    digitalWrite(Led1, LOW);  
    digitalWrite(Led2, LOW);  
    digitalWrite(Led3, LOW);  
    pinMode(Tension, OUTPUT);  
    digitalWrite(Tension, HIGH);  
}
void loop() {    
     serialByte=Serial.read();
     LecturaAnalogL=analogRead(Analogic1);
     VpwmL = map (LecturaAnalogL, 0, 1100, 0, 255);            
     if (serialByte!= -1){
        Entrada=serialByte ;
     }

//---LEDS-----------------------
     if (Entrada==51){
       analogWrite(Led1, VpwmL);
       digitalWrite(Led2, LOW);  
       digitalWrite(Led3, LOW);        
     }  
     else if (Entrada==53){
       analogWrite(Led2, VpwmL);
       digitalWrite(Led1, LOW);  
       digitalWrite(Led3, LOW);        
     }         
     else if (Entrada==54){
       analogWrite(Led3, VpwmL);
       digitalWrite(Led1, LOW);  
       digitalWrite(Led2, LOW);        
     } 
     else if (Entrada==55){
       analogWrite(Led1, LOW);   
     } 
     else if (Entrada==56){
       analogWrite(Led2, LOW);      
     } 
     else if (Entrada==57){
       analogWrite(Led3, LOW);       
     }      
//--POTENCIOMETRES------------
    //Lineal
     else if (Entrada==65){
       SendLineal=1;     
     }     
     else if (Entrada==66){
       SendLineal=0;      
     }  
     else if (Entrada==67){
       SendRotational=1;     
     }     
     else if (Entrada==68){
       SendRotational=0;      
     }
     else if (Entrada==69){
       SendLineal=1;     
       SendRotational=1;      
     }  
     else if (Entrada==70){
       SendLineal=0;      
       SendRotational=0;      
     }        
     
     if (SendLineal==1){
       LecturaAnalogL=analogRead(Analogic1);
       VpwmL = map (LecturaAnalogL, 0, 1100, 0, 255);       
         if (VpwmL < (EntradaL - 2)){         
           EntradaL=VpwmL;
           myStrL=String(EntradaL,BIN);
           while (myStrL.length()<8){
             myStrL="0" + myStrL;
           }
           myStrL = "2" + myStrL;
           Serial.print(myStrL);
         }
         else if (VpwmL > (EntradaL + 2)){         
           EntradaL=VpwmL;
           myStrL=String(EntradaL,BIN);
           while (myStrL.length()<8){
             myStrL="0" + myStrL;
           }
           myStrL = "2" + myStrL;
           Serial.print(myStrL);           
         } 
     }  
     if (SendRotational==1){
       LecturaAnalogR=analogRead(Analogic2);
       VpwmR = map (LecturaAnalogR, 0, 1100, 0, 255);  
         if (VpwmR < (EntradaR - 2)){         
           EntradaR=VpwmR;
           myStrR=String(EntradaR,BIN);
           while (myStrR.length()<8){
             myStrR="0" + myStrR;
           }
           myStrR = "3" + myStrR;
           Serial.print(myStrR);
         }
         else if (VpwmR > (EntradaR + 2)){         
           EntradaR=VpwmR;
           myStrR=String(EntradaR,BIN);
           while (myStrR.length()<8){
             myStrR="0" + myStrR;
           }
           myStrR = "3" + myStrR;
           Serial.print(myStrR);         }                
     }    
     
    delay(100);
}
