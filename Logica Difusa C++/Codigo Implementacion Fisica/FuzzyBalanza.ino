#include <FuzzyRule.h>
#include <FuzzyComposition.h>
#include <Fuzzy.h>
#include <FuzzyRuleConsequent.h>
#include <FuzzyOutput.h>
#include <FuzzyInput.h>
#include <FuzzyIO.h>
#include <FuzzySet.h>
#include <FuzzyRuleAntecedent.h>
#include <LiquidCrystal.h>
#include <Servo.h>



Servo myservo;
LiquidCrystal lcd(20, 21, 22, 23, 24, 25);

int valor_pasado = 0;
int prueba1 = 868;


class Balanza_Potenciometro {
    int sensorValue;
    double peso;
    double calculo;
  public:
    double getCalculo(){ return calculo;}
    Balanza_Potenciometro() {
      sensorValue = 0;
    }
    // Se Muestra el valor por el puerto Serial

    void mostrar_Valor_Balanza() {
      calculo = 0;
      sensorValue = analogRead(A0);
      calculo+=sensorValue;
      sensorValue = analogRead(A0);
      calculo+=sensorValue;
      sensorValue = analogRead(A0);
      calculo+=sensorValue;
      sensorValue = analogRead(A0);
      calculo=(sensorValue+calculo)/4.0;

      peso = (512.0 - (sensorValue / 2.0));
      calculo = 0.153674 * peso * peso * peso - 41.0502 * peso * peso + 3665.66 * peso - 108848.0;
      calculo *= (calculo >= 0);
      calculo = (int)calculo - (int)calculo%25;
      lcd.clear();
      lcd.print("P:");
      lcd.print(calculo);
      lcd.print("g Aprox.");
   //   lcd.print(peso);
      Serial.println(peso);
      Serial.print(calculo);    
      Serial.printf(" %d —---\n\n", sensorValue);
      //  lcd.print(sensorValue);
    }


    float obtener_Peso(){
        sensorValue = analogRead(A0);
        peso = (512.0 - (sensorValue / 2.0));
        calculo = 0.153674 * peso * peso * peso - 41.0502 * peso * peso + 3665.66 * peso - 108848.0;
        calculo *= (calculo >= 0);
        return calculo;
    }


    int lectura_Potenciometro() {
      sensorValue = analogRead(A0);
      return sensorValue;
    }

}*balanza;

class Fuzzy_Balanza {
    Fuzzy ** fuzzy, **fuzzy2;
    int flagy;
  public:
    Fuzzy_Balanza() {
      flagy =0;
       fuzzy = new Fuzzy*;
       fuzzy2 = new Fuzzy*;
       init(fuzzy, 1);
       init(fuzzy2, 0);
    }

    void setFlagy(int flagy)
    {
     this->flagy = flagy; 
    }
    void init(Fuzzy **fuzzy, int flagy){
      
      *fuzzy = new Fuzzy;
      mensaje = 0;
      // Creando una FuzzyInput Peso
      FuzzyInput* Peso = new FuzzyInput(1);
      FuzzySet* vacio = new FuzzySet(0, 100, 200, 300);
      Peso->addFuzzySet(vacio); 
      FuzzySet* medio_lleno = new FuzzySet(250, 450, 550, 900); 
      Peso->addFuzzySet(medio_lleno); 
      FuzzySet* lleno = new FuzzySet(850, 950,1000, 2000);
      Peso->addFuzzySet(lleno); 

      (*fuzzy)->addFuzzyInput(Peso); //Agregando la FuzzyInput al objeto Fuzzy

      FuzzyOutput* apertura = new FuzzyOutput(1);
      // Creando los FuzzySet que componen la FuzzyOutput apertura
      FuzzySet* cerrada = new FuzzySet(32, 33, 35, 38); // apertura nada
      apertura->addFuzzySet(cerrada); //Agregando la FuzzySet cerrada a apertura
      FuzzySet* casi_cerrado = new FuzzySet(8 , 20, 29, 32); // apertura normal
      apertura->addFuzzySet(casi_cerrado); // Agregando la FuzzySet casi_cerrado a apertura
      FuzzySet* completo = new FuzzySet(0, 7, 8, 12); // apertura completo
      apertura->addFuzzySet(completo); // Agregando la FuzzySet completo a apertura

      (*fuzzy)->addFuzzyOutput(apertura); // Agregando la FuzzyOutput al objeto Fuzzy

      //------------------— Montando las reglas Fuzzy
      FuzzyRuleAntecedent* ifPesoliviano = new FuzzyRuleAntecedent();
      ifPesoliviano->joinSingle(vacio); 
      FuzzyRuleConsequent* thenaperturanada = new FuzzyRuleConsequent(); // Instanciando una consecuencia
      thenaperturanada->addOutput(completo);
      FuzzyRule* fuzzyRule01 = new FuzzyRule(1, ifPesoliviano, thenaperturanada); // Pasando el Antecedente y la Consecuencia
      (*fuzzy)->addFuzzyRule(fuzzyRule01); // Agregando la  FuzzyRule al objeto Fuzzy
      FuzzyRuleAntecedent* ifPesocuarto = new FuzzyRuleAntecedent(); 
      
      ifPesocuarto->joinSingle(medio_lleno); 
      FuzzyRuleConsequent* thenaperturacasi_cerrado = new FuzzyRuleConsequent(); // Instanciando una consecuencia
      if(flagy) thenaperturacasi_cerrado->addOutput(completo);//  Agregando la FuzzySet correspondiente al objeto Consecuente
      else thenaperturacasi_cerrado->addOutput(cerrada);//  Agregando la FuzzySet correspondiente al objeto Consecuente
     
      // Instanciando un objetifo FuzzyRule
      FuzzyRule* fuzzyRule02 = new FuzzyRule(2, ifPesocuarto, thenaperturacasi_cerrado); // Pasando el Antecedente y la Consecuencia
      (*fuzzy)->addFuzzyRule(fuzzyRule02); 
      FuzzyRuleAntecedent* ifPesomedio = new FuzzyRuleAntecedent(); // Instanciando un antecedente
      ifPesomedio->joinSingle(lleno); //Agregando la FuzzySet correspondiente al objeto Antecedente
      FuzzyRuleConsequent* thenaperturacompleto = new FuzzyRuleConsequent(); // Instanciando una consecuencia
      thenaperturacompleto->addOutput(cerrada);
      FuzzyRule* fuzzyRule03 = new FuzzyRule(3, ifPesomedio, thenaperturacompleto); // Pasando el Antecedente y la Consecuencia
      (*fuzzy)->addFuzzyRule(fuzzyRule03); 

    }
    int mensaje; 
    float fuzzy_determinar(int peso) {
     // Serial.print("peso: ");
     // Serial.println(peso);
      ((flagy)?*fuzzy2:*fuzzy2)->setInput(1, peso);

      ((flagy)?*fuzzy2:*fuzzy2)->fuzzify();

      Serial.print("Fuzzy: ");
      Serial.println(((flagy)?*fuzzy2:*fuzzy2)->defuzzify(1));
      if(!flagy){
        mensaje++;
        mensaje%=35;
        lcd.setCursor(0,1);
        lcd.println(&" No Envase!! -> Ready.. UDO ... LAB P.D.A.. "[mensaje]);
      }
      else if(((flagy)?*fuzzy2:*fuzzy2)->defuzzify(1) > 32){
        mensaje++;
        mensaje%=35;
        lcd.setCursor(0,1);
        lcd.println(&" Envace LLeno!! Envace LLeno! Envace LLeno!! "[mensaje]);
      }else {
        mensaje++;
        mensaje%=22;
        lcd.setCursor(0,1);
        lcd.println(&" LLenando !! >>>>>> GRUPO 3 >>>> "[mensaje]);
      }
      return  (!flagy)?35:((!flagy)?*fuzzy2:*fuzzy2)->defuzzify(1);
     /* float output = fuzzy->defuzzify(1);
      //myservo.write(output+0.5);
      Serial.print("Salida: ");
      //lcd.print(peso);
      //Serial.println(output);*/
    }

}*fuzzy;

class Sensor_Luz{
  int value,pin;
  Fuzzy_Balanza *fuzzy;
  public:

  Sensor_Luz(int pin, Fuzzy_Balanza * fuzzy){
    this->pin = pin;
    this->fuzzy = fuzzy;
  }

  
  int obtener_valor()
  {
    value = analogRead(pin);
    Serial.print("Luz :");
    Serial.println(value);
    return value;
  }

  void update(){
      this->fuzzy->setFlagy(obtener_valor() > 1000);
  }
}*sensor_luz;


int k;float angle;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  fuzzy = new Fuzzy_Balanza;
  balanza = new Balanza_Potenciometro;
  sensor_luz = new Sensor_Luz(A1, fuzzy);
  myservo.attach(0);
  
}

void loop(){
   sensor_luz->update();
   balanza->mostrar_Valor_Balanza();
   sensor_luz->update();
   angle = fuzzy->fuzzy_determinar((k =(int)balanza->getCalculo()));
   myservo.write(angle);
   delay(400);
}
