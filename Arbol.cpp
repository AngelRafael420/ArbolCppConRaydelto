/** Arbol.cpp
* Created on: Mar 9, 2019
* Author: raydelto
*/

#include "Arbol.h"
#include <iostream>

// Constructor predeterminado del Arbol
Arbol::Arbol() : _raiz(NULL), _primerNodo(NULL), _ultimoNodo(NULL) {}

// Método para iniciar el proceso de recorrido del árbol
void Arbol::IniciarProceso() {
    _ultimoNodo = NULL;
    _primerNodo = NULL;
}

// Método para procesar un nodo del árbol
void Arbol::Procesar(Nodo* nodo) {
    if (_primerNodo == NULL) {
        _primerNodo = nodo;
        _ultimoNodo = nodo;
    } else {
        _ultimoNodo->SetSiguiente(nodo);
        _ultimoNodo = nodo;
    }
}

// Método de recorrido del árbol
void Arbol::Recorrer() {
    Recorrer(_raiz);
}

// Método de recorrido recursivo del árbol
void Arbol::Recorrer(Nodo* nodo) {
    Procesar(nodo);
    std::cout << nodo->GetNombre() << std::endl;
    Nodo* nodoActual = nodo->GetPrimerHijo();
    while (nodoActual != NULL) {
        Recorrer(nodoActual);
        nodoActual = nodoActual->GetSiguienteHijo();
    }
}

// Método para obtener un nodo dado un índice
Nodo* Arbol::GetNodo(int indice) {
    Nodo* nodo = _primerNodo;
    int i = 0;
    while (nodo != NULL) {
        if (i == indice) {
            return nodo;
        }
        nodo = nodo->GetSiguiente();
        i++;
    }
    return NULL;
}

// Constructor del Arbol con raiz especificada
Arbol::Arbol(Nodo* raiz) : _raiz(raiz), _primerNodo(NULL), _ultimoNodo(NULL) {}

// Destructor del Arbol
Arbol::~Arbol() {}

// Método para agregar un hijo a un nodo del árbol
void Nodo::AgregarHijo(Nodo* hijo) {
    if (_primerHijo) {
        _ultimoHijo->SetSiguienteHijo(hijo);
        _ultimoHijo = hijo;
    } else {
        _primerHijo = hijo;
        _ultimoHijo = _primerHijo;
    }
}
