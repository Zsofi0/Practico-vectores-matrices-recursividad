

#include <iostream>
#include <climits>
using namespace std;

class Matriz {
private:
    int m[100][100];
    int filas, columnas;

public:
    Matriz(){
        filas = 0;
        columnas = 0;
    }
    void cargar(int f, int c, int k = 0){
        filas = f;
        columnas = c;
        if (k == f * c) return;
        cout << "Posicion [" << k / c << "][" << k % c << "]: ";
        cin >> m[k / c][k % c];
        cargar(f, c, k + 1);
    }

    void mostrar(int k = 0){
        if (k == 0) cout << "Matriz:" << endl;
        if (k == filas * columnas) return;
        if (k % columnas == 0) cout << "|";
        cout << m[k / columnas][k % columnas] << "\t";
        if ((k + 1) % columnas == 0) cout << "|" << endl;
        mostrar(k + 1);
    }

    int getElemento(int pos){
        return m[pos / columnas][pos % columnas];
    }

    int getC(){
        return columnas;
    }

    int getF(){
        return filas;
    }

    //ejercicio26. Cargar una matriz
    void ejercicio26(int f, int c, int k = 0) {
        cargar(f, c, k);
    }

    //ejerccio27. Mostrar una matriz
    void ejercicio27(int k = 0){
        mostrar(k);
    }

    //ejercicio28. Sumar todos los elementos
    int ejercicio28(int k = 0){
        if (k == filas * columnas) return 0;

        return getElemento(k) + ejercicio28(k + 1);
    }

    // ejerccio 29 Contar pares e impares
    void ejercicio29(int k, int &pares, int &impares){
        if (k == filas * columnas) return;

        if (getElemento(k) % 2 == 0)
            pares++;
        else
            impares++;

        ejercicio29(k + 1, pares, impares);
    }

    //ejerccio 30 Encontrar el mayor
    int ejercicio30(int k = 0){
        if (k == filas * columnas - 1)
            return getElemento(k);
        int mayor = ejercicio30(k + 1);
        if (getElemento(k) > mayor)
            return getElemento(k);
        return mayor;
    }

    //ewjercio 31. Encontrar el menor y su posicion
    int ejercicio31(int k = 0){
        if (k == filas * columnas - 1)
            return getElemento(k);
        int menor = ejercicio31(k + 1);
        if (getElemento(k) < menor)
            return getElemento(k);
        return menor;
    }

    int posicion31(int menor, int k = 0){
        if (k == filas * columnas) return -1;
        if (getElemento(k) == menor) return k;
        return posicion31(menor, k + 1);
    }

    //ejercicio32. Contar positivos, negativos y ceros
    void ejercicio32(int k, int &positivos, int &negativos, int &ceros){
        if (k == filas * columnas) return;
        if (getElemento(k) > 0)
            positivos++;
        else if (getElemento(k) < 0)
            negativos++;
        else
            ceros++;
        ejercicio32(k + 1, positivos, negativos, ceros);
    }

    //ej 33. Buscar un elemento
    bool ejercicio33(int x, int k, int &f, int &c){
        if (k == filas * columnas) return false;

        if (getElemento(k) == x) {
            f = k / columnas;
            c = k % columnas;
            return true;
        }
        return ejercicio33(x, k + 1, f, c);
    }

    //ejer 34. Sumar cada fila
    int sumarFila34(int f, int c = 0){
        if (c == columnas) return 0;

        return m[f][c] + sumarFila34(f, c + 1);
    }
    void ejercicio34(int f = 0){
        if (f == filas) return;

        cout << "Fila " << f << ": " << sumarFila34(f) << endl;

        ejercicio34(f + 1);
    }

    //ej 35. Sumar cada columna
    int sumarColumna35(int f, int c){
        if (f == filas) return 0;

        return m[f][c] + sumarColumna35(f + 1, c);
    }
    void ejercicio35(int c = 0){
        if (c == columnas) return;

        cout << "Columna " << c << ": "
             << sumarColumna35(0, c) << endl;
        ejercicio35(c + 1);
    }

    //ej36. Diagonal principal
    int ejercicio36(int i = 0) {
        if (i == filas) return 0;
        return m[i][i] + ejercicio36(i + 1);
    }

    // ej37. Diagonal secundaria
    int ejercicio37(int i = 0){
        if (i == filas) return 0;

        return m[i][columnas - 1 - i] + ejercicio37(i + 1);
    }

    //ej38. Sumar sobre y debajo de la diagonal
    void ejercicio38(int i, int j, int &encima, int &debajo){
        if (i == filas) return;
        if (j == columnas) {
            ejercicio38(i + 1, 0, encima, debajo);
            return;
        }
        if (i < j)
            encima += m[i][j];
        if (i > j)
            debajo += m[i][j];
        ejercicio38(i, j + 1, encima, debajo);
    }

    //ej39. Mostrar el borde
    void ejercicio39(int k = 0){
        if (k == filas * columnas) return;
        int i = k / columnas;
        int j = k % columnas;
        if (i == 0 || i == filas - 1 || j == 0 || j == columnas - 1)
            cout << m[i][j] << " ";
        ejercicio39(k + 1);
    }

    // ej40. Sumar el borde
    int ejercicio40(int k = 0) {
        if (k == filas * columnas) return 0;

        int i = k / columnas;
        int j = k % columnas;

        if (i == 0 || i == filas - 1 || j == 0 || j == columnas - 1)
            return m[i][j] + ejercicio40(k + 1);

        return ejercicio40(k + 1);
    }

    //ej 41. Mostrar la transpuesta
    void ejercicio41(int i, int j) {
        if (i == columnas) return;
        if (j == 0) cout << "|";
        cout << m[j][i] << "\t";
        if (j == filas - 1) {
            cout << "|" << endl;
            ejercicio41(i + 1, 0);
        } else {
            ejercicio41(i, j + 1);
        }
    }

    //ej42. Mayor de cada fila
    int mayorFila42(int f, int c) {
        if (c == columnas - 1)
            return m[f][c];
        int mayor = mayorFila42(f, c + 1);
        if (m[f][c] > mayor)
            return m[f][c];
        return mayor;
    }

    void ejercicio42(int f = 0) {
        if (f == filas) return;

        cout << "Fila " << f << ": "
             << mayorFila42(f, 0) << endl;

        ejercicio42(f + 1);
    }

    //ej43. Verificar matriz simetrica
    bool ejercicio43(int k = 0) {
        if (k == filas * columnas) return true;
        int i = k / columnas;
        int j = k % columnas;
        if (m[i][j] != m[j][i]) return false;
        return ejercicio43(k + 1);
    }

    //ej44. Rotar 90 grados
    void ejercicio44(int i, int j) {
        if (i == filas) return;

        if (j == 0) cout << "|";

        cout << m[filas - 1 - j][i] << "\t";

        if (j == filas - 1) {
            cout << "|" << endl;
            ejercicio44(i + 1, 0);
        } else {
            ejercicio44(i, j + 1);
        }
    }

    //ej 45. Recorrido en espiral
    void filaDerecha45(int i, int j, int fin){
        if (j > fin) return;

        cout << m[i][j] << " ";
        filaDerecha45(i, j + 1, fin);
    }

    void columnaAbajo45(int i, int j, int fin){
        if (i > fin) return;

        cout << m[i][j] << " ";
        columnaAbajo45(i + 1, j, fin);
    }

    void filaIzquierda45(int i, int j, int fin){
        if (j < fin) return;
        cout << m[i][j] << " ";
        filaIzquierda45(i, j - 1, fin);
    }

    void columnaArriba45(int i, int j, int fin){
        if (i < fin) return;
        cout << m[i][j] << " ";
        columnaArriba45(i - 1, j, fin);
    }

    void ejercicio45(int arriba, int abajo, int izquierda, int derecha){
        if (arriba > abajo || izquierda > derecha) return;
        filaDerecha45(arriba, izquierda, derecha);
        columnaAbajo45(arriba + 1, derecha, abajo);
        if (arriba < abajo)
            filaIzquierda45(abajo, derecha - 1, izquierda);
        if (izquierda < derecha)
            columnaArriba45(abajo - 1, izquierda, arriba + 1);
        ejercicio45(arriba + 1, abajo - 1, izquierda + 1, derecha - 1);
    }

    // ej46. Matriz triangular superior
    bool ejercicio46(int k = 0){
        if (k == filas * columnas) return true;
        int i = k / columnas;
        int j = k % columnas;
        if (i > j && m[i][j] != 0)
            return false;

        return ejercicio46(k + 1);
    }

    // ej 47. Sumar regiones triangulares
    void ejercicio47(int k, int &superior, int &inferior){
        if (k == filas * columnas) return;
        int i = k / columnas;
        int j = k % columnas;
        if (i <= j)
            superior += m[i][j];

        if (i >= j)
            inferior += m[i][j];
        ejercicio47(k + 1, superior, inferior);
    }

    // ejO 48. Encontrar punto de silla
    int mayorColumna48(int f, int c){
        if (f == filas) return INT_MIN;

        int mayor = mayorColumna48(f + 1, c);

        if (m[f][c] > mayor)
            return m[f][c];

        return mayor;
    }

    int menorFila48(int f, int c){
        if (c == columnas) return INT_MAX;
        int menor = menorFila48(f, c + 1);
        if (m[f][c] < menor)
            return m[f][c];
        return menor;
    }

    bool buscarPunto48(int i, int j, int &f, int &c){
        if (i == filas) return false;
        if (j == columnas)
            return buscarPunto48(i + 1, 0, f, c);
        if (m[i][j] == menorFila48(i, 0) &&
            m[i][j] == mayorColumna48(0, j)) {
            f = i;
            c = j;
            return true;
        }

        return buscarPunto48(i, j + 1, f, c);
    }

    //ejercio 49. Buscar secuencias consecutivas
    bool secuencia49(int i, int j, int di, int dj, int k, int valor) {
        if (k == 0) return true;

        if (i < 0 || i >= filas || j < 0 || j >= columnas)
            return false;

        if (m[i][j] != valor) return false;

        return secuencia49(i + di, j + dj, di, dj, k - 1, valor);
    }

    bool buscarSecuencia49(int k, int cantidad){
        if (k == filas * columnas) return false;

        int i = k /columnas;
        int j = k % columnas;
        int valor = m[i][j];

        if (secuencia49(i, j, 0, 1, cantidad, valor) ||
            secuencia49(i, j, 1, 0, cantidad, valor) ||
            secuencia49(i, j, 1, 1, cantidad, valor) ||
            secuencia49(i, j, 1, -1, cantidad, valor))
            return true;

        return buscarSecuencia49(k + 1, cantidad);
    }

    bool ejercicio49(int k){
        return buscarSecuencia49(0, k);
    }

    //ejerccio50. Camino de suma maxima
    int mejorDesde50(int i, int j){
        if (i == filas - 1 && j == columnas - 1)
            return m[i][j];

        if (i == filas - 1)
            return m[i][j] + mejorDesde50(i, j + 1);

        if (j == columnas - 1)
            return m[i][j] + mejorDesde50(i + 1, j);

        int derecha = mejorDesde50(i, j + 1);
        int abajo = mejorDesde50(i + 1, j);

        if (derecha > abajo)
            return m[i][j] + derecha;

        return m[i][j] + abajo;
    }

    void mostrarCamino50(int i, int j){
        cout << m[i][j];

        if (i == filas - 1 && j == columnas - 1)
            return;

        if (i == filas - 1) {
            cout << " -> ";
            mostrarCamino50(i, j + 1);
            return;
        }

        if (j == columnas - 1){
            cout << " -> ";
            mostrarCamino50(i + 1, j);
            return;
        }

        int derecha = mejorDesde50(i, j + 1);
        int abajo = mejorDesde50(i + 1, j);

        cout << " -> ";

        if (derecha > abajo)
            mostrarCamino50(i, j + 1);
        else
            mostrarCamino50(i + 1, j);
    }

    int ejercicio50(){
        return mejorDesde50(0, 0);
    }
};

int main(){
    Matriz a;
    int f, c, x, k;
    int pares = 0, impares = 0;
    int positivos = 0, negativos = 0, ceros = 0;
    int fila, columna;
    int encima = 0, debajo = 0;
    int superior = 0, inferior = 0;

    cout << "Ingrese filas: ";
    cin >> f;

    cout << "Ingrese columnas: ";
    cin >> c;

    // EJERCICIO 26
    a.ejercicio26(f, c);
/*
    // EJERCICIO 27
    a.ejercicio27();

    // EJERCICIO 28
    cout << "Suma total: " << a.ejercicio28() << endl;

    // EJERCICIO 29
    a.ejercicio29(0, pares, impares);
    cout << "Pares: " << pares << endl;
    cout << "Impares: " << impares << endl;

    // EJERCICIO 30
    cout << "Mayor: " << a.ejercicio30() << endl;

    // EJERCICIO 31
    int menor = a.ejercicio31();
    int pos = a.posicion31(menor);
    cout << "Menor: " << menor << endl;
    cout << "Fila: " << pos / c << endl;
    cout << "Columna: " << pos % c << endl;

    // EJERCICIO 32
    a.ejercicio32(0, positivos, negativos, ceros);
    cout << "Positivos: " << positivos << endl;
    cout << "Negativos: " << negativos << endl;
    cout << "Ceros: " << ceros << endl;

    // EJERCICIO 33
    cout << "Ingrese numero a buscar: ";
    cin >> x;

    if (a.ejercicio33(x, 0, fila, columna))
        cout << "Encontrado en fila " << fila
             << ", columna " << columna << endl;
    else
        cout << "No encontrado" << endl;

    // EJERCICIO 34
    a.ejercicio34();

    // EJERCICIO 35
    a.ejercicio35();

    // EJERCICIO 36
    cout << "Diagonal principal: " << a.ejercicio36() << endl;

    // EJERCICIO 37
    cout << "Diagonal secundaria: " << a.ejercicio37() << endl;

    // EJERCICIO 38
    a.ejercicio38(0, 0, encima, debajo);
    cout << "Encima: " << encima << endl;
    cout << "Debajo: " << debajo << endl;

    // EJERCICIO 39
    cout << "Borde: ";
    a.ejercicio39();
    cout << endl;

    // EJERCICIO 40
    cout << "Suma del borde: " << a.ejercicio40() << endl;

    // EJERCICIO 41
    cout << "Transpuesta:" << endl;
    a.ejercicio41(0, 0);

    // EJERCICIO 42
    a.ejercicio42();

    // EJERCICIO 43
    if (a.ejercicio43())
        cout << "Es simetrica" << endl;
    else
        cout << "No es simetrica" << endl;

    // EJERCICIO 44
    cout << "Matriz rotada:" << endl;
    a.ejercicio44(0, 0);

    // EJERCICIO 45
    cout << "Espiral: ";
    a.ejercicio45(0, f - 1, 0, c - 1);
    cout << endl;

    // EJERCICIO 46
    if (a.ejercicio46())
        cout << "Es triangular superior" << endl;
    else
        cout << "No es triangular superior" << endl;

    // EJERCICIO 47
    a.ejercicio47(0, superior, inferior);
    cout << "Triangulo superior: " << superior << endl;
    cout << "Triangulo inferior: " << inferior << endl;

    // EJERCICIO 48
    if (a.buscarPunto48(0, 0, fila, columna))
        cout << "Punto de silla: fila " << fila
             << ", columna " << columna << endl;
    else
        cout << "No existe punto de silla" << endl;

    // EJERCICIO 49
    cout << "Ingrese K: ";
    cin >> k;

    if (a.ejercicio49(k))
        cout << "Existe una secuencia" << endl;
    else
        cout << "No existe una secuencia" << endl;

    // EJERCICIO 50
    cout << "Suma maxima: " << a.ejercicio50() << endl;
    cout << "Camino: ";
    a.mostrarCamino50(0, 0);
    cout << endl;
*/
    return 0;
}

