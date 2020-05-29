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
    int numnot = 12;
    string notes[24] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#","A", "A#", "B"}; // Este arreglo nos va a servir para automatizar la creación de acordes
    string ac[3];

    virtual string creaAcorde(int PosN){ // Se limita a leer la nota y obtener su quinta justa, la nota con la que crea mayor armonía
        ac[0] = notes[PosN];
        PosN = PosN + 7;
        ac[1] = notes[PosN];
        string acorde = "Quinta: " + ac[0] + "," + ac[1];
        cout << acorde << endl;
        return acorde;
    }
    
    int setNota();
    int notaEjemplo();
    
};

int nota::setNota(){    // Obtenemos una nota del usuario y la cambiamos a un valor numérico del 0 al 11 para poder trabajar dentro del arreglo "notes".
    cout << "Ingrese una nota musical en el sistema inglés (C, C#, D,...)" << endl;
    cin >> note;
    
    while (numnot == 12){ // Aqui cambiamos la nota obtenida por un número del 1 al 12, que utilizaremos para crear su escala y acordes posteriormente
        if (note == "C" or note == "c"){
            numnot = 0;
        }
        else if (note == "C#" or note == "c#" or note == "Db" or note == "db"){
        numnot = 1;
        }
        else if (note == "D" or note == "d"){
            numnot = 2;
        }
        else if (note == "D#" or note == "d#" or note == "Eb" or note == "eb"){
            numnot = 3;
        }
        else if (note == "E" or note == "e"){
            numnot = 4;
        }
        else if (note == "F" or note == "f"){
            numnot = 5;
        }
        else if (note == "F#" or note == "f#" or note == "Gb" or note == "gb"){
            numnot = 6;
        }
        else if (note == "G" or note == "g"){
            numnot = 7;
        }
        else if (note == "G#" or note == "g#" or note == "Ab" or note == "ab"){
            numnot = 8;
        }
        else if (note == "A" or note == "a"){
            numnot = 9;
        }
        else if (note == "A#" or note == "a#" or note == "Bb" or note == "bb"){
            numnot = 10;
        }
        else if (note == "B" or note == "b"){
            numnot = 11;
        }
        else {
            numnot = 12;        //Como se está recibiendo un string, un error del usuario es bastante probable. En ese caso, entraría                       este "else".
            cout << "Favor de ingresar una nota válida" << endl;
            cin >> note;
        }
    }

    return numnot;  //Regresa la nota convertida en número
}

int notaEjemplo(){  // En caso de requerir un ejemplo
    cout << "Utilizaremos como ejemplo la nota 'Do' (C)" << endl;
    
    return 0;   // Aunque parece nulo, este 0 representa la nota "Do" dentro de nuestro arreglo
}



// clases Acorde Mayor, Acorde menor, Acorde disminuido y acorde 7. Estas clases tomarán la posición de la nota inicial, y mediante sumas formarán el acorde requerido.

class Mayor : public nota {
public:
    string creaAcorde(int posN);
    
};

 string Mayor:: creaAcorde(int posN){   // Aqui se crea el acorde Mayor
    ac[0] = notes[posN];
    posN = posN + 4;
    ac[1] = notes[posN];
    posN = posN + 3;
    ac[2] = notes[posN];
     string acorde = "Acorde Mayor: " + ac[0] + "," + ac[1] + "," + ac[2];
    cout << acorde << endl;
    return acorde;
 }


class Menor : public nota {
public:
    string creaAcorde(int posN);
    
};

string Menor:: creaAcorde(int posN){    // Aqui se crea el acorde Menor
    ac[0] = notes[posN];
    posN = posN + 3;
    ac[1] = notes[posN];
    posN = posN + 4;
    ac[2] = notes[posN];
    string acorde = "Acorde Menor: " + ac[0] + "," + ac[1] + "," + ac[2];
    cout << acorde << endl;
    return acorde;
}



class Dism : public nota {
public:
    string creaAcorde(int posN);
    
};

string Dism:: creaAcorde(int posN){ // Aqui se crea el acorde DIsminuido
    ac[0] = notes[posN];
    posN = posN + 3;
    ac[1] = notes[posN];
    posN = posN + 3;
    ac[2] = notes[posN];
    string acorde = "Acorde Disminuido: " + ac[0] + "," + ac[1] + "," + ac[2];
    cout << acorde << endl;
    return acorde;
}

class A7 : public nota {
public:
    string creaAcorde(int posN);
    string ac[4];
    };

    string A7 :: creaAcorde(int posN){  // Aqui se crea el acorde 7
        ac[0] = notes[posN];
        posN = posN + 4;
        ac[1] = notes[posN];
        posN = posN + 3;
        ac[2] = notes[posN];
        posN = posN + 3;
        ac[3] = notes[posN];
        string acorde = "Acorde 7: " + ac[0] + "," + ac[1] + "," + ac[2] + "," + ac[3];
        cout << acorde << endl;
        return acorde;
    }






#endif /* nota_h */



