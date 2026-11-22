
#include <iostream>
using namespace std;

class Vector {
private:
    static const int MAX = 100;
    int v[MAX];
    int tamano;

public:
    Vector() {
        tamano = 0;
    }

    //ejercicio1. cargar un vector
    void ejercicio1(int n, int i) {
        tamano = n;

        if (i == tamano) return;

        cout << "Ingresa el elemento " << i + 1 << ": ";
        cin >> v[i];

        ejercicio1(n, i + 1);
    }

    //ejercicio 2. Mostrar un vector
    void ejercicio2(int i) {
        if (i == tamano) return;

        cout << v[i] << " ";
        ejercicio2(i + 1);
    }

    // ejercicio3. Mostrar en orden inverso
    void ejercicio3(int i) {
        if (i < 0) return;

        cout << v[i] << " ";
        ejercicio3(i - 1);
    }

    //ejercicioo4. Sumar elementos
    int ejercicio4(int i) {
        if (i == tamano) return 0;

        return v[i] + ejercicio4(i + 1);
    }

    //ejercicio5. Contar numerospares
    int ejercicio5(int i) {
        if (i == tamano) return 0;

        if (v[i] % 2 == 0)
            return 1 + ejercicio5(i + 1);

        return ejercicio5(i + 1);
    }

    //ejercico 6 contar positivos, negativos y ceros
    void ejercicio6(int i, int &positivos, int &negativos, int &ceros) {
        if (i == tamano) return;

        if (v[i] > 0)
            positivos++;
        else if (v[i] < 0)
            negativos++;
        else
            ceros++;

        ejercicio6(i + 1, positivos, negativos, ceros);
    }

    // ejercicio 7 calcular promedio
    float ejercicio7() {
        if (tamano == 0) return 0;

        return (float)ejercicio4(0) / tamano;
    }

    // ejercico8. Contar multiplos de un numero
    int ejercicio8(int k, int i) {
        if (i == tamano) return 0;

        if (v[i] % k == 0)
            return 1 + ejercicio8(k, i + 1);

        return ejercicio8(k, i + 1);
    }

    //ejercicio 9. Encontrar el mayor
    int ejercicio9(int i) {
        if (i == tamano - 1) return v[i];

        int mayor = ejercicio9(i + 1);

        if (v[i] > mayor)
            return v[i];

        return mayor;
    }

    // ejercio10. Encontrar el menor y su posicion
    int ejercicio10(int i) {
        if (i == tamano - 1) return v[i];

        int menor = ejercicio10(i + 1);

        if (v[i] < menor)
            return v[i];

        return menor;
    }

    int posicion10(int menor, int i) {
        if (i == tamano) return -1;

        if (v[i] == menor) return i;

        return posicion10(menor, i + 1);
    }

    //ejercico 11. Buscar un elemento
    int ejercicio11(int x, int i) {
        if (i == tamano) return -1;

        if (v[i] == x) return i;

        return ejercicio11(x, i + 1);
    }

    // ejercicio 12. Contar repeticiones
    int ejercicio12(int x, int i) {
        if (i == tamano) return 0;

        if (v[i] == x)
            return 1 + ejercicio12(x, i + 1);

        return ejercicio12(x, i + 1);
    }

    //ejercicio 13. Reemplazar elementos
    void ejercicio13(int x, int y, int i) {
        if (i == tamano) return;

        if (v[i] == x)
            v[i] = y;

        ejercicio13(x, y, i + 1);
    }

    //ejercicio 14. Invertir el vector
    void ejercicio14(int inicio, int fin) {
        if (inicio >= fin) return;

        int aux = v[inicio];
        v[inicio] = v[fin];
        v[fin] = aux;

        ejercicio14(inicio + 1, fin - 1);
    }

    // ejercicio15. Verificar orden ascendente
    bool ejercicio15(int i) {
        if (i == tamano - 1) return true;

        if (v[i] > v[i + 1]) return false;

        return ejercicio15(i + 1);
    }

    // ejercicio 16 Sumar posiciones pares e impares
    void ejercicio16(int i, int &pares, int &impares) {
        if (i == tamano) return;

        if (i % 2 == 0)
            pares += v[i];
        else
            impares += v[i];

        ejercicio16(i + 1, pares, impares);
    }

    // ejercicio 17. Eliminar un elemento por posicion
    void desplazar17(int i) {
        if (i == tamano - 1) return;

        v[i] = v[i + 1];

        desplazar17(i + 1);
    }

    void ejercicio17(int p) {
        if (p < 0 || p >= tamano) return;

        desplazar17(p);
        tamano--;
    }

    //ejercicio18. Ordenamiento por seleccion recursivo
    int buscarMenor18(int i, int pos) {
        if (i == tamano) return pos;

        if (v[i] < v[pos])
            pos = i;

        return buscarMenor18(i + 1, pos);
    }

    void ejercicio18(int i) {
        if (i == tamano - 1) return;

        int pos = buscarMenor18(i, i);

        int aux = v[i];
        v[i] = v[pos];
        v[pos] = aux;

        ejercicio18(i + 1);
    }

    //ejercicio19. Busqueda binaria recursiva
    int ejercicio19(int x, int inicio, int fin) {
        if (inicio > fin) return -1;

        int medio = (inicio + fin) / 2;

        if (v[medio] == x) return medio;

        if (x < v[medio])
            return ejercicio19(x, inicio, medio - 1);

        return ejercicio19(x, medio + 1, fin);
    }

    // ejercicio 20. Eliminar elementos duplicados
    void desplazar20(int i) {
        if (i == tamano - 1) return;

        v[i] = v[i + 1];

        desplazar20(i + 1);
    }

    void eliminarDesde20(int i, int j) {
        if (j == tamano) return;

        if (v[i] == v[j]) {
            desplazar20(j);
            tamano--;
            eliminarDesde20(i, j);
        } else {
            eliminarDesde20(i, j + 1);
        }
    }

    void ejercicio20(int i) {
        if (i == tamano - 1) return;

        eliminarDesde20(i, i + 1);

        ejercicio20(i + 1);
    }

    // ejercicio 21. Separar pares e impares
    int buscarImpar21(int i) {
        if (i == tamano) return -1;

        if (v[i] % 2 != 0) return i;

        return buscarImpar21(i + 1);
    }

    int buscarPar21(int i) {
        if (i < 0) return -1;

        if (v[i] % 2 == 0) return i;

        return buscarPar21(i - 1);
    }

    void ejercicio21(int inicio, int fin) {
        int impar = buscarImpar21(inicio);
        int par = buscarPar21(fin);

        if (impar == -1 || par == -1 || impar >= par)
            return;

        int aux = v[impar];
        v[impar] = v[par];
        v[par] = aux;

        ejercicio21(impar + 1, par - 1);
    }

    // ejercicio 22. Rotacion circular a la derecha
    void invertir22(int inicio, int fin) {
        if (inicio >= fin) return;

        int aux = v[inicio];
        v[inicio] = v[fin];
        v[fin] = aux;

        invertir22(inicio + 1, fin - 1);
    }

    void ejercicio22(int k) {
        if (tamano == 0) return;

        k = k % tamano;

        if (k < 0) k += tamano;

        invertir22(0, tamano - 1);
        invertir22(0, k - 1);
        invertir22(k, tamano - 1);
    }

    //ejercicio 23. Subsecuencia creciente consecutiva
    int ejercicio23(int i, int actual, int mayor) {
        if (i == tamano) return mayor;

        if (v[i] > v[i - 1])
            actual++;
        else
            actual = 1;

        if (actual > mayor)
            mayor = actual;

        return ejercicio23(i + 1, actual, mayor);
    }

    // ejericio 24. Segundo mayor distinto
    void ejercicio24(int i, int &mayor, int &segundo, bool &haySegundo) {
        if (i == tamano) return;

        if (v[i] > mayor) {
            segundo = mayor;
            mayor = v[i];
            haySegundo = true;
        }
        else if (v[i] < mayor) {
            if (!haySegundo || v[i] > segundo) {
                segundo = v[i];
                haySegundo = true;
            }
        }

        ejercicio24(i + 1, mayor, segundo, haySegundo);
    }

    // ejercicio25. Maxima suma de segmento consecutivo
    int ejercicio25(int i, int sumaActual, int sumaMayor) {
        if (i == tamano) return sumaMayor;

        if (sumaActual + v[i] < v[i])
            sumaActual = v[i];
        else
            sumaActual = sumaActual + v[i];

        if (sumaActual > sumaMayor)
            sumaMayor = sumaActual;

        return ejercicio25(i + 1, sumaActual, sumaMayor);
    }

    // Mostrar cantidad actual de elementos
    int getTamano() {
        return tamano;
    }
};


int main() {
    Vector a;
    int n, x, y, k, p;
    int positivos = 0, negativos = 0, ceros = 0;
    int sumaPares = 0, sumaImpares = 0;
    int mayor, segundo;
    bool haySegundo = false;

    cout << "Ingrese cantidad de elementos: ";
    cin >> n;

    // EJERCICIO 1
    a.ejercicio1(n, 0);
/*
    // EJERCICIO 2
    cout << "Vector: ";
    a.ejercicio2(0);
    cout << endl;

    // EJERCICIO 3
    cout << "Orden inverso: ";
    a.ejercicio3(n - 1);
    cout << endl;

    // EJERCICIO 4
    cout << "Suma total: " << a.ejercicio4(0) << endl;

    // EJERCICIO 5
    cout << "Cantidad de pares: " << a.ejercicio5(0) << endl;

    // EJERCICIO 6
    a.ejercicio6(0, positivos, negativos, ceros);
    cout << "Positivos: " << positivos << endl;
    cout << "Negativos: " << negativos << endl;
    cout << "Ceros: " << ceros << endl;

    // EJERCICIO 7
    cout << "Promedio: " << a.ejercicio7() << endl;

    // EJERCICIO 8
    cout << "Ingrese K: ";
    cin >> k;
    cout << "Multiplos: " << a.ejercicio8(k, 0) << endl;

    // EJERCICIO 9
    cout << "Mayor: " << a.ejercicio9(0) << endl;

    // EJERCICIO 10
    int menor = a.ejercicio10(0);
    cout << "Menor: " << menor << endl;
    cout << "Posicion: " << a.posicion10(menor, 0) << endl;

    // EJERCICIO 11
    cout << "Ingrese X: ";
    cin >> x;
    cout << "Primera posicion: " << a.ejercicio11(x, 0) << endl;

    // EJERCICIO 12
    cout << "Apariciones: " << a.ejercicio12(x, 0) << endl;

    // EJERCICIO 13
    cout << "Ingrese Y: ";
    cin >> y;
    a.ejercicio13(x, y, 0);
    a.ejercicio2(0);

    // EJERCICIO 14
    a.ejercicio14(0, a.getTamano() - 1);
    a.ejercicio2(0);

    // EJERCICIO 15
    if (a.ejercicio15(0))
        cout << "Esta ordenado" << endl;
    else
        cout << "No esta ordenado" << endl;

    // EJERCICIO 16
    a.ejercicio16(0, sumaPares, sumaImpares);
    cout << "Suma indices pares: " << sumaPares << endl;
    cout << "Suma indices impares: " << sumaImpares << endl;

    // EJERCICIO 17
    cout << "Ingrese posicion a eliminar: ";
    cin >> p;
    a.ejercicio17(p);
    cout << "Nuevo tamano: " << a.getTamano() << endl;
    a.ejercicio2(0);

    // EJERCICIO 18
    a.ejercicio18(0);
    a.ejercicio2(0);

    // EJERCICIO 19
    cout << "Ingrese X para buscar: ";
    cin >> x;
    cout << "Indice encontrado: "
         << a.ejercicio19(x, 0, a.getTamano() - 1) << endl;

    // EJERCICIO 20
    a.ejercicio20(0);
    cout << "Nuevo tamano: " << a.getTamano() << endl;
    a.ejercicio2(0);

    // EJERCICIO 21
    a.ejercicio21(0, a.getTamano() - 1);
    a.ejercicio2(0);

    // EJERCICIO 22
    cout << "Ingrese K: ";
    cin >> k;
    a.ejercicio22(k);
    a.ejercicio2(0);

    // EJERCICIO 23
    cout << "Longitud maxima: "
         << a.ejercicio23(1, 1, 1) << endl;

    // EJERCICIO 24
    mayor = a.ejercicio9(0);
    a.ejercicio24(0, mayor, segundo, haySegundo);

    if (haySegundo)
        cout << "Mayor: " << mayor
             << "; segundo mayor: " << segundo << endl;
    else
        cout << "No existe segundo mayor distinto" << endl;

    // EJERCICIO 25
    cout << "Suma maxima: "
         << a.ejercicio25(1, v[0], v[0]) << endl;
*/
    return 0;
}

