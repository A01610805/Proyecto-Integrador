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

//  Este main es un ejemplo de como obtener cada uno de los tipos de acordes incluidos en el programa. Posteriormente se creará otra clase "cancion", donde almacenaremos uno a uno los acordes que el usuario requiera para ir construyendo su canción

int main() {
    nota n;
    int numnot = n.setNota();
    n.creaAcorde(numnot);   // Aqui nos imprime la quinta; como no se define ninguna clase hereditaria, se lleva a cabo la función creaAcorde dentro de nota
    
    nota *M = new Mayor();
    M -> creaAcorde(numnot);    // Aqui obtenemos un acorde mayor, ya que definimos el apuntador M como un nuevo objeto de la clase Mayor
    
    nota *m = new Menor();
    m -> creaAcorde(numnot);    // Aqui obtenemos un acorde menor, ya que definimos el apuntador m como un nuevo objeto de la clase Menor
    
    nota *D = new Dism();
    D -> creaAcorde(numnot);    // Aqui obtenemos un acorde disminuido, ya que definimos el apuntador D como un nuevo objeto de la clase Disminuido
    
    nota *S = new A7();
    S -> creaAcorde(numnot);    // Aqui obtenemos un acorde dominante 7, ya que definimos el apuntador S como un nuevo objeto de la clase A7
    
    delete M;
    delete m;
    delete D;
    delete S;
    
    
    return 0;
}
