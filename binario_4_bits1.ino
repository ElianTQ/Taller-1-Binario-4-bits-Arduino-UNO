int numeroDecimal = 0;
int bit1 = 0;
int bit2 = 0;
int bit3 = 0;
int bit4 = 0;

bool signoActual = false;

int ledPin1 = 10; 
int ledPin2 = 9;
int ledPin3 = 8;
int ledPin4 = 7;
int ledPin5 = 6;

int botonPin4 = 2;    
int estadoBoton4 = 0;
int botonPin3 = 3;    
int estadoBoton3 = 0; 
int botonPin2 = 4;    
int estadoBoton2 = 0;
int botonPin1 = 5;    
int estadoBoton1 = 0; 

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50; 

void setup() {
  pinMode(botonPin1, INPUT_PULLUP);
  pinMode(botonPin2, INPUT_PULLUP); 
  pinMode(botonPin3, INPUT_PULLUP);
  pinMode(botonPin4, INPUT_PULLUP); 

  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  

  
  
}

void loop() {
  
  
  
  if (signoActual == false){
    calculadorDeBinario(numeroDecimal);
  } else {
    calculadorDeNegativos(numeroDecimal);
  }
  
  if ((millis() - lastDebounceTime) > debounceDelay) {
    estadoBoton1 = digitalRead(botonPin1);
    estadoBoton2 = digitalRead(botonPin2); 
    estadoBoton3 = digitalRead(botonPin3);
    estadoBoton4 = digitalRead(botonPin4);
    
    if (estadoBoton1 == LOW) {
      numeroDecimal += 2;
      delay(200);
    } 
    if (estadoBoton2 == LOW) {
      numeroDecimal += 1;
      delay(200);
    } 
    if (estadoBoton3 == LOW) {
      numeroDecimal = 0;
      digitalWrite(ledPin1, LOW);
      delay(200);
    }
    if (estadoBoton4 == LOW) {
      signoActual = !signoActual;
      delay(200);
    }
    if (signoActual == false){
      if (numeroDecimal >= 16) {
        numeroDecimal = 15;
      	digitalWrite(ledPin1, HIGH);
        delay(200);
      }
    }else {
      if (numeroDecimal >= 9) {
      	numeroDecimal = 8;
      	digitalWrite(ledPin1, HIGH);
        delay(200);
      }
    }
    lastDebounceTime = millis();
  }
  
  
  if (bit1 == 1){
     digitalWrite(ledPin5, HIGH);
  }else{
     digitalWrite(ledPin5, LOW);
  }
  if (bit2 == 1){
  	 digitalWrite(ledPin4, HIGH);
  }else{
      digitalWrite(ledPin4, LOW);
  }
  if (bit3 == 1){ 
    digitalWrite(ledPin3, HIGH);
  }else{ 
    digitalWrite(ledPin3, LOW);
  }
  if (bit4 == 1){
    digitalWrite(ledPin2, HIGH);
  }else{
    digitalWrite(ledPin2, LOW);
  } 
}


void calculadorDeBinario(int num) {
    int iterador = 4;
  
 
  	
    while (iterador > 0) {
      if (iterador == 4){ 
        bit1 = (num % 2);
      }
      if (iterador == 3){ 
        bit2 = (num % 2);
      }
      if (iterador == 2){ 
        bit3 = (num % 2);
      }
      if (iterador == 1){ 
        bit4 = (num % 2);
      }
      num = num / 2;
      iterador -= 1;    
    }
  
}

void calculadorDeNegativos(int num) {
  calculadorDeBinario(num);

  int bit1copia = bit1 == 1 ? 0 : 1;
  int bit2copia = bit2 == 1 ? 0 : 1;
  int bit3copia = bit3 == 1 ? 0 : 1;
  int bit4copia = bit4 == 1 ? 0 : 1;
  
  bit1 = bit1copia;
  bit2 = bit2copia;
  bit3 = bit3copia;
  bit4 = bit4copia;
  

  
  if (bit1copia == 0) {
    bit1 = 1;
  } else {
    bit1 = 0;
    if (bit2copia == 0) {
      bit2 = 1;
    } else {
      bit2 = 0;
      if (bit3copia == 0) {
        bit3 = 1;
      } else {
        bit3 = 0;
        if (bit4copia == 0) {
          bit4 = 1;
        } else {
          bit4 = 0;
        }
      }
    }
  }
}
  
    
  
  
  
  
  
  
  
  
  