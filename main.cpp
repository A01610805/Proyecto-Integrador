//
//  main.cpp
//  Proyecto Integrador
//
//  Created by Jose Antonio Lopez on 5/21/20.
//  Copyright © 2020 Jose Antonio Lopez. All rights reserved.
//

#include <iostream>
#include "nota.h"
using namespace std;

int main() {
    
    string cancion; // Se declaran variables
    nota nt;
    cout << "Acorde 1" << endl;
    int num = nt.setNota();
    int n = 0;
    Acorde *acordes[99];
    
    while (num != 12){  // mun será igual a 12 cuando el usuario teclee "Fin" (ver función setNota)
        int type = 6;   // Para entrar en el while. Esta variable cambiará de valor una vez dentro.
        while (1 > type or type > 5){
        type = nt.ChordType();
            if (type == 1){
               acordes[n] = new Mayor();    // Se crea nuevo objeto "Mayor"
            }
            else if (type == 2){
                acordes[n] = new Menor();   // Se crea nuevo objeto "Menor"
            }
            else if (type == 3){
                acordes[n] = new Dism();    // Se crea nuevo objeto "Dism"
            }
        
            else if (type == 4){
               acordes[n] = new D7();     // Se crea nuevo objeto "D7"
            }
        
            else if (type == 5){
                acordes[n] = new Maj7();    // Se crea nuevo objeto "Maj7"
            }
            else{
                cout << "Por favor introduzca un número del 1 al 5" << endl;
            }
        }
        string acorde = acordes[n] -> creaAcorde(num);  // Se crea un acorde de acuerdo al objeto creado
        string c = acordes[n] -> compas();  // El usuario agrega la duración del acorde
        cancion = cancion + "\n" + acorde + c;  //  Aqui se va guardando la canción en la variable "cancion", sumando los strings obtenidos en cada vuelta del ciclo.
        n++;
        cout <<"\n" <<  "Acorde " << n+1 << endl;   //Pedimos el siguiente acorde.
        num = nt.setNota();
        
    }
    
    cout << cancion << endl; // Una vez que el usuario teclea "FIn", se imprimen los acordes almacenados

    
    return 0;
}
