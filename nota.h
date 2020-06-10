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
    string note;    // Variable que se utiliza al pedirle al usuario una nota

    
public:
    int nt = 13;
    int numnot;
    string notes[24] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#","A", "A#", "B"}; // Este arreglo nos va a servir para automatizar la creación de acordes
    string ac[3];   // Arreglo con 3 espacios para las 3 notas de una triada

    
    int setNota();  // Función utilizada en el main
    int notaEjemplo();  // Función en caso de requerir un ejemplo 
    int ChordType();    // Función utilizada en el main

    
};

int nota::setNota(){    // Obtenemos una nota del usuario y la cambiamos a un valor numérico del 0 al 11 para poder trabajar dentro del arreglo "notes".
    cout << "Ingrese una nota musical en el sistema inglés (C, C#, D,... 'Fin' para finalizar)" << endl;
    cin >> note;
    
    while (nt == 13){ // Aqui cambiamos la nota obtenida por un número del 1 al 12, que utilizaremos para crear su escala y acordes posteriormente. Esá adaptado para funcionar ocn mayúsculas y minúsculas
        if (note == "C" or note == "c"){    // Si el usuario ingresa "C"
            nt = 0;
            numnot = 0;
        }
        else if (note == "C#" or note == "c#" or note == "Db" or note == "db"){ // Si el usuario ingresa "C# o Db" (equivalentes)
            nt = 0;
        numnot = 1;
        }
        else if (note == "D" or note == "d"){   // Si el usuario ingresa "D"
            nt = 0;
            numnot = 2;
        }
        else if (note == "D#" or note == "d#" or note == "Eb" or note == "eb"){ // Si el usuario ingresa "D# o Eb" (equivalentes)
            nt = 0;
            numnot = 3;
        }
        else if (note == "E" or note == "e"){   // Si el usuario ingresa "E"
            nt = 0;
            numnot = 4;
        }
        else if (note == "F" or note == "f"){   // Si el usuario ingresa "F"
            nt = 0;
            numnot = 5;
        }
        else if (note == "F#" or note == "f#" or note == "Gb" or note == "gb"){ // Si el usuario ingresa "F# o Gb" (equivalentes)
            nt = 0;
            numnot = 6;
        }
        else if (note == "G" or note == "g"){   // Si el usuario ingresa "G"
            nt = 0;
            numnot = 7;
        }
        else if (note == "G#" or note == "g#" or note == "Ab" or note == "ab"){ // Si el usuario ingresa "G# o Ab" (equivalentes)
            nt = 0;
            numnot = 8;
        }
        else if (note == "A" or note == "a"){   // Si el usuario ingresa "A"
            nt = 0;
            numnot = 9;
        }
        else if (note == "A#" or note == "a#" or note == "Bb" or note == "bb"){ // Si el usuario ingresa "A# o Bb" (equivalentes)
            numnot = 10;
            nt = 0;
        }
        else if (note == "B" or note == "b"){   // Si el usuario ingresa "B"
            numnot = 11;
            nt = 0;
        }
        else if (note == "Fin" or note == "fin"){   // Para finalizar el loop y mostrar resultados
            numnot = 12;
            nt = 0;
        }
        else {
            nt = 13; //Como se está recibiendo un string, un error del usuario es bastante probable. En ese caso, entraría                       este "else".
            cout << "Favor de ingresar una nota válida o 'Fin' para finalizar" << endl;
            cin >> note;
        }

    }
    nt = 13;    // Se regresa a nt su valor original, para poder volver a entrar al "while"
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
class Acorde : public nota{  // Clase abstracta con función virutal creaAcorde.
private:
    
public:
    string compas();    // Para obtener el número de compases de cada acorde
    virtual string creaAcorde(int numnot) = 0;  // Función que convierte esta clase en abstracta.


    
    
};

string Acorde::compas(){    // Funcion para obtener duración del acorde en la canción.
    string c;
    cout << "Ingrese el número de compases para este acorde"<< endl;
    cin >> c;
    c = ", " + c + " compases";
    return c;
}


class Mayor : public Acorde {   // Clase Mayor, que hereda de Acorde, creada para obtener el acorde mayor
public:
    string creaAcorde(int posN);    // Función sobreescrita
    
};

 string Mayor:: creaAcorde(int posN){   // Aqui se crea el acorde Mayor
    ac[0] = notes[posN];    // Nota principal
    posN = posN + 4;    // Distancia entre primer y segunda nota
    ac[1] = notes[posN];    // Se agrega la segunda nota
    posN = posN + 3;    // Distancia entre segunda y tercer nota
    ac[2] = notes[posN];    // Se agrega la tercer nota
    string acorde = ac[0] + ": " + ac[0] + "," + ac[1] + "," + ac[2];   // Se crea el acorde completo y se almacena en un string
    return acorde;  // Se regresa el string con el acorde completo
 }


class Menor : public Acorde {   // Clase Menor, que hereda de Acorde, creada para obtener el acorde menor
public:
    string creaAcorde(int posN);    // Función sobreescrita
    
};

string Menor:: creaAcorde(int posN){    // Aqui se crea el acorde Menor
    ac[0] = notes[posN];    // Nota principal
    posN = posN + 3;        // Distancia entre primer y segunda nota
    ac[1] = notes[posN];    // Se agrega la segunda nota
    posN = posN + 4;        // Distancia entre segunda y tercer nota
    ac[2] = notes[posN];    // Se agrega la tercer nota
    string acorde = ac[0] + "m: " + ac[0] + "," + ac[1] + "," + ac[2];  // Se crea el acorde completo y se almacena en un string
    return acorde;  // Se regresa el string con el acorde completo
}



class Dism : public Acorde {    // Clase Dism, que hereda de Acorde, creada para obtener el acorde disminuido
public:
    string creaAcorde(int posN);    // Función sobreescrita
    
};

string Dism:: creaAcorde(int posN){ // Aqui se crea el acorde Disminuido
    ac[0] = notes[posN];    // Nota principal
    posN = posN + 3;        // Distancia entre primer y segunda nota
    ac[1] = notes[posN];   // Se agrega la segunda nota
    posN = posN + 3;       // Distancia entre segunda y tercer nota
    ac[2] = notes[posN];    // Se agrega la tercer nota
    string acorde = ac[0] + "º: " + ac[0] + "," + ac[1] + "," + ac[2];  // Se crea el acorde completo y se almacena en un string
    return acorde;  // Se regresa el string con el acorde completo
}

class D7 : public Acorde {  // Clase D7, que hereda de Acorde, creada para obtener el acorde Dominante 7
public:
    string creaAcorde(int posN);    // Función sobreescrita
    string ac[4];
    };

    string D7 :: creaAcorde(int posN){  // Aqui se crea el acorde Dominante 7
        ac[0] = notes[posN];    // Nota principal
        posN = posN + 4;        // Distancia entre primer y segunda nota
        ac[1] = notes[posN];    // Se agrega la segunda nota
        posN = posN + 3;        // Distancia entre segunda y tercer nota
        ac[2] = notes[posN];    // Se agrega la tercer nota
        posN = posN + 3;        // Distancia entre tercer y cuarta nota
        ac[3] = notes[posN];    // Se agrega cuarta nota
        string acorde = ac[0] + "7: " + ac[0] + "," + ac[1] + "," + ac[2] + "," + ac[3];    // Se crea el acorde completo y se almacena en un string
        return acorde;  // Se regresa el string con el acorde completo
    }

class Maj7 : public Acorde {    // Clase Maj7, que hereda de Acorde, creada para obtener el acorde Mayor 7
public:
    string creaAcorde(int posN);    // Función sobreescrita
    string ac[4];
};

string Maj7 :: creaAcorde(int posN){  // Aqui se crea el acorde 7 Mayor
    ac[0] = notes[posN];    // Nota principal
    posN = posN + 4;        // Distancia entre primer y segunda nota
    ac[1] = notes[posN];    // Se agrega la segunda nota
    posN = posN + 3;        // Distancia entre segunda y tercer nota
    ac[2] = notes[posN];    // Se agrega la tercer nota
    posN = posN + 4;        // Distancia entre tercer y cuarta nota
    ac[3] = notes[posN];    // Se agrega cuarta nota
    string acorde = ac[0] + "maj7: " + ac[0] + "," + ac[1] + "," + ac[2] + "," + ac[3]; // Se crea el acorde completo y se almacena en un string
    return acorde;  // Se regresa el string con el acorde completo
}




#endif /* nota_h */



