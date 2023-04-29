#include<iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
  int mat[7][4][3];
  float c, prome;
  int i, op, j, k, mayor, menor, suma;
  do {
    system("cls");
    cout << "\n\n Menu de Opciones" << endl;
    cout << " 1. Llenar matriz de ceros " << endl;
    cout << " 2. Llenar matriz Manualmente" << endl;
    cout << " 3. Llenar matriz Random " << endl;
    cout << " 4. Imprimir " << endl;
    cout << " 5. Promedio por alumno " << endl;
    cout << " 6. Promedio por materia " << endl;
    cout << " 7. Sumar Caras 1 " << endl;
    cout << " 8. Sumar Caras 2 " << endl;
    cout << " 9. Promedios " << endl;
    cout << " 10. Salir " << endl;
    cout << " \n Ingrese una opción: ";
    cin >> op;
    switch (op) {
    case 1:
      //Limpiar Matriz
      cout << "Llenar de cero las posiciones del arreglo" << endl;
      for (k = 0; k <= 2; k++) {
        for (i = 0; i <= 6; i++) {
          for (j = 0; j <= 3; j++) {
            mat[i][j][k] = 0;
          }
        }
      }
      break;
    case 2:
      //Llenar Matriz manual
      cout << "Llenar de números al azar" << endl;
      cout << "Llenar de números al azar" << endl;
      for (k = 0; k <= 2; k++) {
        for (i = 0; i <= 5; i++) {
          for (j = 0; j <= 2; j++) {
            cout << "Escriba el numero de la fila: " << i << "Columna: " << j << "Cara: " << k << endl;
            cin >> mat[i][j][k];
          }
        }
      }
      break;
    case 3:
      //Llenar Matriz Randon
      cout << "Llenar de números al azar" << endl;
      srand(time(NULL));
      for (k = 0; k <= 2; k++) {
        for (i = 0; i <= 5; i++) {
          for (j = 0; j <= 2; j++) {
            mat[i][j][k] = rand() % 39 + 1;
          }
        }
      }
      break;
    case 4:
      //Imprimir la Matriz
      cout << "Imprime las caras del Arreglo Multidimensional" << endl;
      for (k = 0; k <= 2; k++) {
        for (i = 0; i <= 6; i++) {
          for (j = 0; j <= 3; j++) {
            cout << mat[i][j][k] << " ";
          }
          cout << " " << endl;
        }
        cout << " " << endl;
      }
      system("pause>nul");
      break;
    case 5:
      //Obtener el promedio por Alumno
      cout << "Obtener el promedio del Alumno por Cuatrimestre" << endl;
      suma = 0;
      prome = 0;
      for (k = 0; k <= 2; k++) {
        for (i = 0; i <= 6; i++) {
          for (j = 0; j <= 3; j++) {
            suma += mat[i][j][k];
          }
          prome = suma / 3;
          mat[i][3][k] = prome;
          prome = 0;
          suma = 0;
        }
      }
      system("pause>nul");
      break;

    case 6:
      //Obtener el promedio por Alumno por maateria
      cout << "Obtener el promedio del Alumno por materia" << endl;
      suma = 0;
      prome = 0;
      for (k = 0; k <= 2; k++) {
        for (j = 0; j <= 3; j++) {
          for (i = 0; i <= 6; i++) {
            suma += mat[i][j][k];
          }
          prome = suma / 6;
          mat[6][j][k] = prome;
          prome = 0;
          suma = 0;
        }
      }
      system("pause>nul");
      break;

    }
  }
  while (op != 10);
  system("pause");
  system("cls");
  return 0;
}