#include<iostream>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;

int main() {
int mat[7][4][4];
string nombres [6] = {"Pablo","Mario","Luis","Alex","Mariana","Carlos"};
string materias [9] = {"Espannol","Matematicas","Biologia","Quimica","Fisica","Estudios Sociales","Ingles","Educ. Fisica","Artes Plasticas"};
int i, op, j, k, b;

do {
    system("cls");
    cout << "\n\n Menu Principal" << endl;
    cout << " 1. Limpiar " << endl;
    cout << " 2. Ingresar nombre" << endl;
    cout << " 3. Ingresar materias " << endl;
    cout << " 4. Generar notas " << endl;
    cout << " 5. Reportes " << endl;
    
    cout << " 8. Alumnos que se graduan " << endl;
    cout << " 9. Alumnos reprobados " << endl;
    
    cout << " 6. Salir " << endl;
    cout << " 7. Probar " << endl;
    cout << " \n Ingrese una opcion: ";
    cin >> op;
    switch (op) {

    case 1:
      cout << "Limpiar" << endl;
      for (k = 0; k <= 3; k++) {
        for (i = 0; i <= 6; i++) {
          for (j = 0; j <= 3; j++) {
            mat[i][j][k] = 0;
          }
        }
      }
      break;
    case 2:
      cout << "Ingresar nombre" << endl;
      for (int i = 0; i < 6; i++)
        cout << nombres[i] << "\n";
        system("pause>nul");
      break;
    case 3:
      cout << "Ingresar materias" << endl;
      for (int i = 0; i < 9; i++)
        cout << materias[i] << "\n";
        system("pause>nul");
      break;
    case 4:
      cout << "Generar notas" << endl;
      srand(time(NULL));
      for (k = 0; k <= 2; k++) {
        for (i = 0; i <= 5; i++) {
          for (j = 0; j <= 2; j++) {
            mat[i][j][k] = 1 + rand() % 100;
          }
        }
      }
      break;
    case 5:
      cout << "Reportes" << endl;
      break;

    case 6:
      cout << "Salir" << endl;
      cout << "\n 1. Si ";
      cin >> b;
      cout << "\n \n";
      if (b == 1); {
        return 0;
      }
      break;
      
    case 7:
      cout << "Imprimir" << endl;
      for (k = 0; k <= 3; k++) {
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
    case 8:
      cout << "Alumnos que se graduan" << endl;
      srand(time(NULL));
      for (k = 0; k <= 2; k++) {
        for (i = 0; i <= 5; i++) {
          for (j = 0; j <= 2; j++) {
            mat[i][j][k] = 70 + rand() % 30;
          }
        }
      }
      break;
      
     case 9:
       cout << "Alumnos reprobados" << endl;
      srand(time(NULL));
      for (k = 0; k <= 2; k++) {
        for (i = 0; i <= 5; i++) {
          for (j = 0; j <= 2; j++) {
            mat[i][j][k] = 1 + rand() % 64;
          }
        }
      }
    }

  }
  while (op != 10);
  system("pause");
  system("cls");
  return 0;
}
