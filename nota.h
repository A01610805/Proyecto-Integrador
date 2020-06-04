//
//  nota.h
//  Proyecto Integrador
//
//  Created by Jose Antonio Lopez on 5/21/20.
//  Copyright © 2020 Jose Antonio Lopez. All rights reserved.
//

#ifndef nota_h
#define nota_h
#include <iostream>
#include <string>

using namespace std;

class nota { // Esta clase es para obtener una nota y convertirla en un numero entero del 0 al 11

private:
    string note;

    
public:
    int nt = 13;
    int numnot;
    string notes[24] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#","A", "A#", "B"}; // Este arreglo nos va a servir para automatizar la creación de acordes
    string ac[3];   // Arreglo con 3 espacios para las 3 notas de una triada

    
    int setNota();  // Función utilizada en el main
    int notaEjemplo();
    int ChordType();    // Función utilizada en el main

    
};

int nota::setNota(){    // Obtenemos una nota del usuario y la cambiamos a un valor numérico del 0 al 11 para poder trabajar dentro del arreglo "notes".
    cout << "Ingrese una nota musical en el sistema inglés (C, C#, D,... 'Fin' para finalizar)" << endl;
    cin >> note;
    
    while (nt == 13){ // Aqui cambiamos la nota obtenida por un número del 1 al 12, que utilizaremos para crear su escala y acordes posteriormente
        if (note == "C" or note == "c"){
            nt = 0;
            numnot = 0;
        }
        else if (note == "C#" or note == "c#" or note == "Db" or note == "db"){
            nt = 0;
        numnot = 1;
        }
        else if (note == "D" or note == "d"){
            nt = 0;
            numnot = 2;
        }
        else if (note == "D#" or note == "d#" or note == "Eb" or note == "eb"){
            nt = 0;
            numnot = 3;
        }
        else if (note == "E" or note == "e"){
            nt = 0;
            numnot = 4;
        }
        else if (note == "F" or note == "f"){
            nt = 0;
            numnot = 5;
        }
        else if (note == "F#" or note == "f#" or note == "Gb" or note == "gb"){
            nt = 0;
            numnot = 6;
        }
        else if (note == "G" or note == "g"){
            nt = 0;
            numnot = 7;
        }
        else if (note == "G#" or note == "g#" or note == "Ab" or note == "ab"){
            nt = 0;
            numnot = 8;
        }
        else if (note == "A" or note == "a"){
            nt = 0;
            numnot = 9;
        }
        else if (note == "A#" or note == "a#" or note == "Bb" or note == "bb"){
            numnot = 10;
            nt = 0;
        }
        else if (note == "B" or note == "b"){
            numnot = 11;
            nt = 0;
        }
        else if (note == "Fin" or note == "fin"){
            numnot = 12;
            nt = 0;
        }
        else {
            nt = 13; //Como se está recibiendo un string, un error del usuario es bastante probable. En ese caso, entraría                       este "else".
            cout << "Favor de ingresar una nota válida o 'Fin' para finalizar" << endl;
            cin >> note;
        }

    }
    nt = 13;
    return numnot;  //Regresa la nota convertida en número

}

int nota::notaEjemplo(){  // En caso de requerir un ejemplo
    cout << "Utilizaremos como ejemplo la nota 'Do' (C)" << endl;
    
    return 0;   // Aunque parece nulo, este 0 representa la nota "Do" dentro de nuestro arreglo
}

int nota::ChordType(){  // Se define el tipo de acorde
    cout << "Tipo de acorde: 1 para Mayor, 2 para Menor, 3 para Disminuido, 4 para Dominante 7, 5 para mayor 7 " << endl;
    int type;
    cin >> type;
    return type;
}
// clases Acorde Mayor, Acorde menor, Acorde disminuido, 7 Dominante y 7 Mayor. Estas clases tomarán la posición de la nota inicial, y mediante sumas formarán el acorde requerido.
class Acorde : public nota{ // Clase abstracta con función virutal creaAcorde.
private:
    
public:
    string compas();
    virtual string creaAcorde(int numnot) = 0;


    
    
};

string Acorde::compas(){    // Funcion para obtener duración del acorde en la canción.
    string c;
    cout << "Ingrese el número de compases para este acorde"<< endl;
    cin >> c;
    c = ", " + c + " compases";
    return c;
}


class Mayor : public Acorde {
public:
    string creaAcorde(int posN);
    
};

 string Mayor:: creaAcorde(int posN){   // Aqui se crea el acorde Mayor
    numnot = 13;
    ac[0] = notes[posN];
    posN = posN + 4;
    ac[1] = notes[posN];
    posN = posN + 3;
    ac[2] = notes[posN];
    string acorde = ac[0] + ": " + ac[0] + "," + ac[1] + "," + ac[2];
    return acorde;
 }


class Menor : public Acorde {
public:
    string creaAcorde(int posN);
    
};

string Menor:: creaAcorde(int posN){    // Aqui se crea el acorde Menor
    ac[0] = notes[posN];
    posN = posN + 3;
    ac[1] = notes[posN];
    posN = posN + 4;
    ac[2] = notes[posN];
    string acorde = ac[0] + "m: " + ac[0] + "," + ac[1] + "," + ac[2];
    return acorde;
}



class Dism : public Acorde {
public:
    string creaAcorde(int posN);
    
};

string Dism:: creaAcorde(int posN){ // Aqui se crea el acorde Disminuido
    ac[0] = notes[posN];
    posN = posN + 3;
    ac[1] = notes[posN];
    posN = posN + 3;
    ac[2] = notes[posN];
    string acorde = ac[0] + "º: " + ac[0] + "," + ac[1] + "," + ac[2];
    return acorde;
}

class D7 : public Acorde {
public:
    string creaAcorde(int posN);
    string ac[4];
    };

    string D7 :: creaAcorde(int posN){  // Aqui se crea el acorde Dominante 7
        ac[0] = notes[posN];
        posN = posN + 4;
        ac[1] = notes[posN];
        posN = posN + 3;
        ac[2] = notes[posN];
        posN = posN + 3;
        ac[3] = notes[posN];
        string acorde = ac[0] + "7: " + ac[0] + "," + ac[1] + "," + ac[2] + "," + ac[3];
        return acorde;
    }

class Maj7 : public Acorde {
public:
    string creaAcorde(int posN);
    string ac[4];
};

string Maj7 :: creaAcorde(int posN){  // Aqui se crea el acorde 7 Mayor
    ac[0] = notes[posN];
    posN = posN + 4;
    ac[1] = notes[posN];
    posN = posN + 3;
    ac[2] = notes[posN];
    posN = posN + 4;
    ac[3] = notes[posN];
    string acorde = ac[0] + "maj7: " + ac[0] + "," + ac[1] + "," + ac[2] + "," + ac[3];
    return acorde;
}




#endif /* nota_h */



