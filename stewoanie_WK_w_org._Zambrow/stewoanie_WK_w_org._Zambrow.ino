/* Sterowanie kombinacjami w organach w Zambrowie
 *  Kemper Organ - Lubeck
 *  Author: Romuald Milewski
 *  
 */
void setup() {
  // ustawianie wejśc i wyjśc
  for (int a=2; a<10; a++)
{
pinMode(a, INPUT_PULLUP); // ustawia piny 2-9 jako wejścia i podciaga do High
}

// ustawianie wyjść 
pinMode(10, OUTPUT);
digitalWrite(10, LOW);
pinMode(11, OUTPUT);
digitalWrite(11, LOW);
pinMode(12, OUTPUT);
digitalWrite(12, LOW);
pinMode(13, OUTPUT);
digitalWrite(13, LOW);
pinMode(A0, OUTPUT);
digitalWrite(A0, LOW);
pinMode(A1, OUTPUT);
digitalWrite(A1, LOW);
pinMode(A2, OUTPUT);
digitalWrite(A2, LOW);
pinMode(A3, OUTPUT);
digitalWrite(A3, LOW);
pinMode(A4, OUTPUT);
digitalWrite(A4, LOW);
pinMode(A5, OUTPUT);
digitalWrite(A5, LOW);
  
}

void loop() {
  while (digitalRead(2) == HIGH && digitalRead(3) == HIGH && digitalRead(4) == HIGH && digitalRead(5) == HIGH && digitalRead(6) == HIGH && digitalRead(7) == HIGH && digitalRead(8) == HIGH && digitalRead(9) == HIGH) { 
    // Nie robi nic - czeka na naciśniecie przycisku
  }
  
// włączenie przycisku na pinie 2 - Tutti (przewód żółty)
 if (digitalRead(2) == LOW){
    digitalWrite (10, HIGH); // Tutti - ON
    digitalWrite (11, LOW);
    digitalWrite (12, LOW);
    digitalWrite (13, LOW);
   // digitalWrite (A0, LOW);
    digitalWrite (A1, LOW);
    while (digitalRead(2) == LOW){
      // czeka aż puśćimy prycisk
      delay(10);
    }
    
    delay(50);
    
  }
//******************************************************************


// włączenie przycisku na pinie 3 - Free Komb. II 
 if (digitalRead(3) == LOW){
    digitalWrite (10, LOW);
    digitalWrite (11, HIGH); // Komb. II - ON
    digitalWrite (12, LOW);
    digitalWrite (13, LOW);
   // digitalWrite (A0, LOW);
    digitalWrite (A1, LOW);
    while (digitalRead(3) == LOW){
      // czeka aż puśćimy prycisk
      delay(10);
   }
    
    delay(50);
    }  
//****************************************************************

    
// włączenie przycisku na pinie 4 - Free Komb. I     
  if (digitalRead(4) == LOW){
     digitalWrite (10, LOW);
     digitalWrite (11, LOW);
     digitalWrite (12, HIGH); // Komb. I - ON
     digitalWrite (13, LOW);
    // digitalWrite (A0, LOW);
     digitalWrite (A1, LOW);
     while (digitalRead(4) == LOW){
      // czeka aż puśćimy prycisk
      delay(10);
   }
    
    delay(50);
    }  
//******************************************************************
    
    // włączenie przycisku na pinie 5 - Haupt Register 
  if (digitalRead(5) == LOW){
     digitalWrite (10, LOW);
     digitalWrite (11, LOW);
     digitalWrite (12, LOW); 
     digitalWrite (13, HIGH); // Haupt Register - ON
    // digitalWrite (A0, LOW);
     digitalWrite (A1, LOW);
     while (digitalRead(5) == LOW){
      // czeka aż puśćimy prycisk
      delay(10);
   }
    
    delay(50);
    } 
 //**************************************************************    

    // włączenie przycisku na pinie 6 - Fr. ped. Einst
  if (digitalRead(6) == LOW){
     // digitalWrite (10, LOW);
    // digitalWrite (11, LOW);
    // digitalWrite (12, LOW); 
    // digitalWrite (13, LOW);
     digitalWrite (A0, HIGH);//  Ped. Reg. an -ON
    // digitalWrite (A1, LOW);
     while (digitalRead(6) == LOW){
      // czeka aż puśćimy prycisk
      delay(10);
   }
    
    delay(50);
    }
//************************************************************  

 // włączenie przycisku na pinie 7 - Anuluj
  if (digitalRead(7) == LOW){
     digitalWrite (10, LOW);
     digitalWrite (11, LOW);
     digitalWrite (12, LOW); 
     digitalWrite (13, LOW);
     digitalWrite (A0, LOW);
     digitalWrite (A1, LOW); // Anuluj
     digitalWrite (A2, LOW); // Anuluj
     digitalWrite (A3, LOW); // Anuluj
     digitalWrite (A4, LOW); // Anuluj
     digitalWrite (A5, LOW); // Anuluj
     
     while (digitalRead(7) == LOW){
      // czeka aż puśćimy prycisk
      delay(10);
   }
    
    delay(50);
    }  
  //******************************************************

    // włączenie przycisku na pinie 8 -  Ped. Reg. an
  if (digitalRead(8) == LOW){
     //digitalWrite (10, LOW);
     //digitalWrite (11, LOW);
     //digitalWrite (12, LOW); 
     //digitalWrite (13, LOW);
     digitalWrite (A0, LOW);  // Ped. Reg. an 
     //digitalWrite (A1, LOW); 
     while (digitalRead(8) == LOW){
      // czeka aż puśćimy prycisk
      delay(10);
   }
    
    delay(50);
    }  
//*****************************************************

// dodatkowy 9 pin    
  if (digitalRead(9) == LOW){
    digitalWrite (A3, !digitalRead(A3));
    while (digitalRead(9) == LOW){
      // czeka aż puśćimy prycisk
      delay(10);
   }
    
    delay(50);
    }  

 
}
      
