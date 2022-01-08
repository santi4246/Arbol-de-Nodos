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
};

/*Funciones de Nodo*/
Nodo* crearNodo(int);
void insertarNodo(Nodo*&, int);
void mostrarArbol(Nodo*, int);
bool busquedaNodo(Nodo*, int);
void busquedaPreOrden(Nodo*);
void busquedaInOrden(Nodo*);
void busquedaPostOrden(Nodo*);

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
        cout << "4. Recorrer el Arbol en busqueda de profundidad Pre Orden: " << endl;
        cout << "5. Recorrer el Arbol en busqueda de profundidad In Orden: " << endl;
        cout << "6. Recorrer el Arbol en busqueda de profundidad Post Orden: " << endl;
        cout << "7. Salir. " << endl;
        cout << "\nDigite una opcion: ";
        cin >> opc;

        switch (opc){
        case 1:
            cout << "\nDigite un numero: ";
            cin >> dato;
            insertarNodo(arbol, dato);
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
            cout << "\nMostrando los Nodos del Arbol en busqueda pre orden: " << endl;
            busquedaPreOrden(arbol);
            cout << "\n";
            system("pause");
            break;
        case 5:
            cout << "\nMostrando los Nodos del Arbol en busqueda in orden: " << endl;
            busquedaInOrden(arbol);
            cout << "\n";
            system("pause");
            break;
        case 6:
            cout << "\nMostrando los Nodos del Arbol en busqueda post orden: " << endl;
            busquedaPostOrden(arbol);
            cout << "\n";
            system("pause");
            break;
        default:
            break;
        }
        system("cls");
    } while (opc != 7);
}

/*Creación de Nodos*/
Nodo* crearNodo(int n) {
    Nodo* nuevoNodo = new Nodo();
    nuevoNodo->dato = n;
    nuevoNodo->derecho = NULL;
    nuevoNodo->izquierdo = NULL;
    return nuevoNodo;
}

/*Inserción de Nodos*/
void insertarNodo(Nodo*& arbol, int n) {
    if (arbol == NULL) {//Si el árbol está vacío.
        Nodo* nuevoNodo = crearNodo(n);
        arbol = nuevoNodo;
    }
    else {//Si el árbol tiene un nodo o más de un nodo.
        int valor_raiz = arbol->dato;
        if (n < valor_raiz) {
            insertarNodo(arbol->izquierdo, n);//Si el elemento es menor a la raíz.
        }
        else {
            insertarNodo(arbol->derecho, n);//Si el elemento es mayor a la raíz.
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