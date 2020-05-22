//
//  acordes.h
//  Proyecto Integrador
//
//  Created by Jose Antonio Lopez on 5/21/20.
//  Copyright © 2020 Jose Antonio Lopez. All rights reserved.
//

#ifndef acordes_h
#define acordes_h
#include <iostream>
#include <string>
#include "nota.h"

using namespace std;


class acordes {     //Acordes se complementará con 3 clases que se encargarán de formar los acordes mayores, menores y el disminuido.
private:
    int esca;
    int nota1;
    int ntEscala;
    int lugar = 0;
    int form = 0;
    int n;
    
    
public:
    void Escala(int nota1);
    int e[8];
};


void acordes :: Escala(int nota1) {
    n = nota1;
    while (lugar < 3) {     //Se agregan las 3 primeras notas a nuestra escala
        ntEscala = n+form;
        e[lugar] =  ntEscala;
        lugar++;
        form = form + 2;
    }
    
    form = form - 1;    //Se suma el medio tono
    e[lugar] = n+form;
    lugar++;
    
    while (lugar < 7) { //Se agregan las siguientes 3 notas a la escala
        form = form + 2;
        e[lugar] = n+form;
        lugar++;
    }
    
    form = form + 1;    //Se agrega la última nota a nuestra escala.
    e[7] = n+form;
   // int *es = new int[8];
}



class mayores : public acordes { // Aqui se crean los acordes mayores. La idea es que haya más conexión entre "acordes" y sus herederas, una vez que sepa como trabajar con los números obtenidos en la escala.
private:
    string Mchords;
    
    int ac1[3];

public:
    string creaAcordes(int e[0]);

};


string mayores :: creaAcordes(<#int *e#>) {
 
    int note = *e;
    
    ac1[0] = note;
    ac1[1] = note + 4;
    ac1[2] = ac1[1] + 3;
    
    switch (note) {
        case 1:
            Mchords = "Acorde 1: C, E, G; Acorde 4: F, A, C; Acorde 5: G, B, D";
            break;

        case 2:
            Mchords = "Acorde 1: C#, F, G# Acorde 4: F#, A#, C#; Acorde 5: G# C, D#";
            break;
            
        case 3:
            Mchords = "Acorde 1: D, F#, A; Acorde 4: G, B, D; Acrode 5: A, C#, E";
            break;
            
        case 4:
            Mchords = "Acorde 1: D#, G, A#; Acorde 4: G#, C, D#; Acrode 5: A#, D, F";
            break;
            
        case 5:
            Mchords = "Acorde 1: E, G#, B; Acorde 4: A, C#, E; Acrode 5: B, D#, F#";
            break;
            
        case 6:
            Mchords = "Acorde 1: F, A, C; Acorde 4: A#, D, F; Acrode 5: C, E, G";
            break;
            
        case 7:
            Mchords = "Acorde 1: F#, A#, C#; Acorde 4: B, D#, F#; Acrode 5: C#, F, G#";
            break;
            
        case 8:
            Mchords = "Acorde 1: G, B, D; Acorde 4: C, E, G; Acrode 5: D, F#, A";
            break;
            
        case 9:
            Mchords = "Acorde 1: G#, C, D#; Acorde 4: C#, F, G#; Acrode 5: D#, G, A#";
            break;
            
        case 10:
            Mchords = "Acorde 1: A, C#, E; Acorde 4: D, F#, A; Acrode 5: E, G#, B";
            break;
            
        case 11:
            Mchords = "Acorde 1: A#, D, F; Acorde 4: D#, G, A#; Acrode 5: F, A, C";
            break;
            
        case 12:
            Mchords = "Acorde 1: B, D#, F#; Acorde 4: E, G#, B; Acrode 5: F#, A#, C#";
            break;

    }
    
    return Mchords;
}





class menores : public acordes { // Aqui se crean los acordes 2, 3 y 6, que son los menores de la escala.
private:
    string mchords;
    
public:
    string creaAcordes(int e[1]);

};

string menores :: creaAcordes(<#int *e#>) {
    
    int note = *e;
    
  //  ac1[0] = note;
   // ac1[1] = note + 3;
  //  ac1[2] = ac1[1] + 4;
    
    switch (note) {
        case 1:
            mchords = "Acorde 2: D, F, A; Acorde 3: E, G, B; Acorde 6: A, C, E";
            break;
            
        case 2:
            mchords = "Acorde 2: D#, F#, A#; Acorde 3: F, G#, C; Acorde 6: A# C#, F";
            break;
            
        case 3:
            mchords = "Acorde 2: E, G, B; Acorde 3: F#, A, C#; Acrode 6: B, D, F#";
            break;
            
        case 4:
            mchords = "Acorde 2: F, G#, C; Acorde 3: G, A#, D; Acrode 6: C, D#, G";
            break;
            
        case 5:
            mchords = "Acorde 2: F#, A, C#; Acorde 3: G#, B, D#; Acrode 6: C#, E, G#";
            break;
            
        case 6:
            mchords = "Acorde 2: G, A#, D; Acorde 3: A, C, E; Acrode 6: D, F, A";
            break;
            
        case 7:
            mchords = "Acorde 2: G#, B, D#; Acorde 3: A#, C#, F; Acrode 6: D#, F#, A#";
            break;
            
        case 8:
            mchords = "Acorde 2: A, C, E; Acorde 3: B, D, F#; Acrode 6: E, G, B";
            break;
            
        case 9:
            mchords = "Acorde 2: A#, C#, F; Acorde 3: C, D#, G; Acrode 6: F, G#, C";
            break;
            
        case 10:
            mchords = "Acorde 2: B, D, F#; Acorde 3: C#, E, G#; Acrode 6: F#, A, C#";
            break;
            
        case 11:
            mchords = "Acorde 2: C, D#, G; Acorde 3: D, F, A; Acrode 6: G, A#, D";
            break;
            
        case 12:
            mchords = "Acorde 2: C#, E, G#; Acorde 3: D#, F#, A#; Acrode 6: G#, B, D#";
            break;
    }
    return mchords;

    }

class disminuido : public acordes { // Aqui se escribe el único disminuido: el 7o.
private:
    string dchord;
    
    
public:
    string creaAcorde7(int e[6]){
        int note = *e;
        
        //  ac1[0] = note;
        // ac1[1] = note + 3;
        //  ac1[2] = ac1[1] + 3;
        
        switch (note) {
            case 1:
                dchord = "Acorde 7: B, D, F";
                break;
                
            case 2:
                dchord = "Acorde 7: C, D#, F#";
                break;
                
            case 3:
                dchord = "Acorde 7: C#, E, G";
                break;
                
            case 4:
                dchord = "Acorde 7: D, F, G#";
                break;
                
            case 5:
                dchord = "Acorde 7: D#, F#, A";
                break;
                
            case 6:
                dchord = "Acorde 7: E, G, A#";
                break;
                
            case 7:
                dchord = "Acorde 7: F, G#, B";
                break;
                
            case 8:
                dchord = "Acorde 7: F#, A, C";
                break;
                
            case 9:
                dchord = "Acorde 7: G, A#, C#";
                break;
                
            case 10:
                dchord = "Acorde 7: G#, B, D";
                break;
                
            case 11:
                dchord = "Acorde 7: A, C, D#";
                break;
                
            case 12:
                dchord = "Acorde 7: A#, C#, E";
                break;
                
        }
                return dchord;
    
    }
};
    

#endif /* acordes_h */

