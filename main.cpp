/*Librerías utilizadas*/
#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

/*Prototipo de Funciones* /
* 
/*Estructura de Nodos*/
struct Nodo {
    int dato;
    Nodo* derecho;
    Nodo* izquierdo;
    Nodo* padre;
};

/* Funciones Prototipo de Nodo */
Nodo* crearNodo(int, Nodo*);
void insertarNodo(Nodo*&, int, Nodo*);
void mostrarArbol(Nodo*, int);
bool busquedaNodo(Nodo*, int);
void busquedaPreOrden(Nodo*);
void busquedaInOrden(Nodo*);
void busquedaPostOrden(Nodo*);
void eliminar(Nodo*, int);
void eliminarNodo(Nodo*);
Nodo* minimo(Nodo*);
void reemplazar(Nodo*, Nodo*);
void destruirNodo(Nodo*);

Nodo* arbol = NULL;
void menu();

//Función Principal
int main() {
    menu();
}

/* Declaración de Funciones */

void menu() {
    int opc, dato, contador = 0;

    do {
        cout << "\t.:MENU:.\n" << endl;
        cout << "1. Insertar elementos en un Arbol: " << endl;
        cout << "2. Mostrar Arbol completo: " << endl;
        cout << "3. Busqueda de Nodos: " << endl;
        cout << "4. Recorrer el Arbol en busqueda de profundidad Pre-Orden: " << endl;
        cout << "5. Recorrer el Arbol en busqueda de profundidad In-Orden: " << endl;
        cout << "6. Recorrer el Arbol en busqueda de profundidad Post-Orden: " << endl;
        cout << "7. Eliminar Nodos del Arbol: " << endl;
        cout << "8. Salir. " << endl;
        cout << "\nDigite una opcion: ";
        cin >> opc;

        switch (opc){
        case 1:
            cout << "\nDigite un numero: ";
            cin >> dato;
            insertarNodo(arbol, dato, NULL);
            cout << "\n";
            system("pause");
            break;
        case 2:
            cout << "\nMostrando Arbol completo..." << endl;
            mostrarArbol(arbol, contador);
            cout << "\n" << endl;
            system("pause");
            break;
        case 3:
            cout << "\nInserte un elemento a buscar en el Arbol: " << endl;
            cin >> dato;
            if (busquedaNodo(arbol, dato) == true) {
                cout << "\nEl Nodo " << dato << " ha sido encontrado en el Arbol. " << endl;
            }
            else {
                cout << "\nEl Nodo " << dato << " no ha sido encontrado en el Arbol. " << endl;
            }
            cout << "\n";
            system("pause");
            break;
        case 4:           
            busquedaPreOrden(arbol);
            cout << "\n";
            system("pause");
            break;        
        case 5:
            busquedaInOrden(arbol);
            cout << "\n";
            system("pause");
            break;
        case 6:
            busquedaPostOrden(arbol);
            cout << "\n";
            system("pause");
            break;
        case 7:
            cout << "\nDigite el Nodo a eliminar: " << endl;
            cin >> dato;
            eliminar(arbol, dato);
            cout << "\n";
            system("pause");
            break;
        default:
            break;
        }
        system("cls");
    } while (opc != 8);
}

/*Creación de Nodos*/
Nodo* crearNodo(int n, Nodo* padre) {
    Nodo* nuevoNodo = new Nodo();
    nuevoNodo->dato = n;
    nuevoNodo->derecho = NULL;
    nuevoNodo->izquierdo = NULL;
    nuevoNodo->padre = padre;
    return nuevoNodo;
}

/*Inserción de Nodos*/
void insertarNodo(Nodo*& arbol, int n, Nodo* padre) {
    if (arbol == NULL) {
        Nodo* nuevoNodo = crearNodo(n, padre);
        arbol = nuevoNodo;
    }
    else {
        int valorRaiz = arbol->dato;
        if (n < valorRaiz){
            insertarNodo(arbol->izquierdo, n, arbol);
        }
        else {
            insertarNodo(arbol->derecho, n, arbol);
        }
    }
}

/*Muestreo de Datos de Arbol*/
void mostrarArbol(Nodo* arbol, int contador) {
    if (arbol == NULL) {
        return;
    }
    else {
        mostrarArbol(arbol->derecho, contador + 1);
        for (int i = 0; i < contador; i++) {
            cout << "  ";
        }
        cout << arbol->dato << endl;
        mostrarArbol(arbol->izquierdo, contador + 1);
    }
}

/*Búsqueda de Nodos en Arbol*/
bool busquedaNodo(Nodo* arbol, int n) {
    if (arbol == NULL) {
        return false;
    }
    else if (arbol->dato == n) {
        return true;
    }
    else if (n < arbol->dato) {
        return busquedaNodo(arbol->izquierdo, n);
    }
    else {
        return busquedaNodo(arbol->derecho, n);
    }
}

/*Búsqueda Pre Orden*/
void busquedaPreOrden(Nodo* arbol) {
    if (arbol == NULL) {
        return;
    }
    else {
        cout << arbol->dato << " - ";
        busquedaPreOrden(arbol->izquierdo);
        busquedaPreOrden(arbol->derecho);
    }
}

/*Búsqueda In Orden*/
void busquedaInOrden(Nodo* arbol) {
    if (arbol == NULL) {
        return;
    }
    else {
        busquedaInOrden(arbol->izquierdo);
        cout << arbol->dato << " - ";
        busquedaInOrden(arbol->derecho);
    }
}

/*Búsqueda Post Orden*/
void busquedaPostOrden(Nodo* arbol) {
    if (arbol == NULL) {
        return;
    }
    else {
        busquedaPostOrden(arbol->izquierdo);
        busquedaPostOrden(arbol->derecho);
        cout << arbol->dato << " - ";
    }
}

/*Función recursiva Eliminar que verifica el Árbol*/
void eliminar(Nodo* arbol, int n){
    if (arbol == NULL) {
        return;
    }
    else if (n < arbol->dato) {
        eliminar(arbol->izquierdo, n);
    }
    else if (n > arbol->dato) {
        eliminar(arbol->derecho, n);
    }
    else {
        eliminarNodo(arbol);
    }
}

/*Función recursiva que busca el Nodo más izquierdo posible*/
Nodo* minimo(Nodo* arbol){
    if (arbol == NULL) {
        return NULL;
    }
    if (arbol->izquierdo) {
        return minimo(arbol->izquierdo);
    }
    else {
        return arbol;
    }
}

/*Función para reemplazar Nodo Padre por Nodo Hijo*/
void reemplazar(Nodo* arbol, Nodo* nuevoNodo) {
    if (arbol->padre) {
        if (arbol->dato == arbol->padre->izquierdo->dato) {
            arbol->padre->izquierdo = nuevoNodo;
        }
        else if (arbol->dato == arbol->padre->derecho->dato) {
            arbol->padre->derecho = nuevoNodo;
        }
    }
    if (nuevoNodo) {
        nuevoNodo->padre = arbol->padre;
    }
}

/*Función para destruir Nodos ya localizados*/
void destruirNodo(Nodo* nodo) {
    nodo->izquierdo = NULL;
    nodo->derecho = NULL;
    delete nodo;
}

/*Función para eliminar el Nodo encontrado*/
void eliminarNodo(Nodo* nodoEliminar) {
    if (nodoEliminar->izquierdo && nodoEliminar->derecho) {
        Nodo* menor = minimo(nodoEliminar->derecho);
        nodoEliminar->dato = menor->dato;
        eliminarNodo(menor);
    }
    else if (nodoEliminar->izquierdo) {
        reemplazar(nodoEliminar, nodoEliminar->izquierdo);
        destruirNodo(nodoEliminar);
    }
    else if (nodoEliminar->derecho) {
        reemplazar(nodoEliminar, nodoEliminar->derecho);
        destruirNodo(nodoEliminar);
    }
    else {
        reemplazar(nodoEliminar, NULL);
        destruirNodo(nodoEliminar);
    }
}