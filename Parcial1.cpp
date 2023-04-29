#include<iostream>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;

int main() {
int mat[4][8][4];
float c, prom;
string nombres [6] = {"Mariana","Steven","Luis"};
string materias [9] = {"Estudios Sociales","Matematicas","Ingles","Ciencias","Biologia","Frances","Espannol"};
int i, op, j, k, mayor, menor, suma, b;

do {
    system("cls");
    cout << "\n\n Menu Principal" << endl;
    cout << " \n\n 1. Limpiar " << endl;
    cout << " \n 2. Llenar" << endl;
    cout << " \n 3. Promedio final del alumno " << endl;
    cout << " \n 4. Promedio final del alumno por materia " << endl;
    cout << " \n 5. Condicion final anual " << endl;
    cout << " \n 6. Impresion de las notas por trimestre " << endl;
    cout << " \n 7. Impresion de promedio finales por alumno " << endl;
    cout << " \n 8. Salir " << endl;
    cout << " \n\n Ingrese una opcion: ";
    cin >> op;
    switch (op) {

    case 1:
      cout << "Limpiar" << endl;
      for (k = 0; k <= 3; k++) {
        for (i = 0; i <= 3; i++) {
          for (j = 0; j <= 7; j++) {
            mat[i][j][k] = 0;
          }
        }
      }
      break;
    case 2:
      cout << "Llenar" << endl;
      srand(time(NULL));
      for (k = 0; k <= 2; k++) {
        for (i = 0; i <= 2; i++) {
          for (j = 0; j <= 6; j++) {
            mat[i][j][k] = 10 + rand() % 90;
          }
        }
      }
      break;
    case 3:
      cout << "Promedio final del alumno" << endl;
      suma = 0;
      prom = 0;
      for (k = 0; k <= 2; k++) {
        for (i = 0; i <= 3; i++) {
          for (j = 0; j <= 7; j++) {
            suma += mat[i][j][k];
          }
          prom = suma / 7;
          mat[i][7][k] = prom;
          prom = 0;
          suma = 0;
        }
      }
      system("pause>nul");
      break;
    case 4:
      cout << "Promedio final del alumno por materia" << endl;
      suma = 0;
      prom = 0;
      for (k = 0; k <= 2; k++) {
        for (j = 0; j <= 7; j++) {
          for (i = 0; i <= 3; i++) {
            suma += mat[i][j][k];
          }
          prom = suma / 3;
          mat[3][j][k] = prom;
          prom = 0;
          suma = 0;
        }
      }
      system("pause>nul");
      break;
	case 5:
    	suma = 0;
      cout << "Condicion final anual" << endl;
      for (i = 0; i <= 2; i++) {
        for (j = 0; j <= 6; j++) {
          if (mat[i][j][0] >= 70 && mat[i][j][1] >= 70 && mat[i][j][2] >= 70) {
            mat[i][j][3] = 1;
            suma += 1;
          } else {
            mat[i][j][3] = 2;
          }
          cout << mat[i][j][3] << " ";
        }
        if (suma == 3)
          mat[i][7][3] = 1;
        cout << mat[i][j][3];
        cout << " " << endl;
        suma = 0;
      }
      system("pause>nul");
      break;
    case 6:
      cout << "Impresion de las notas por trimestre" << endl;
      for (k = 0; k <= 3; k++) {
        for (i = 0; i <= 3; i++) {
          for (j = 0; j <= 7; j++) {
            cout << mat[i][j][k] << " ";
          }
          cout << " " << endl;
        }
        cout << " " << endl;
      }
      system("pause>nul");
      break;
    case 7:
      cout << "Impresion de promedio finales por alumno" << endl;
      for (k = 0; k <= 2; k++) {
        for (i = 0; i <= 2; i++) {
          for (j = 0; j <= 7; j++) {
            cout << mat[i][j][k] << " ";
          }
          if (mat[i][7][k] >= 70)
            cout << "Aprobado" << endl;
          else if (mat[i][3][k] < 70)
            cout << "Reprobado" << endl;
          else
            cout << "Aplazado" << endl;
        }
        cout << " " << endl;
      }
      system("pause>nul");
      break;
	}
}
  while (op != 8);
  system("pause");
  system("cls");
  return 0;
}