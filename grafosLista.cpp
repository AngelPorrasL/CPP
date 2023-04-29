#include<iostream>
#include<stdlib.h>
#include<conio.h>



struct nodo{
            char nombre;//nombre del vertice o nodo
            struct nodo *sgte;
            struct arista *ady;//puntero hacia la primera arista del nodo
            };
struct arista{
              struct nodo *destino;//puntero al nodo de llegada
              struct arista *sgte;
              };
typedef struct nodo *Tnodo;//  Tipo Nodo
typedef struct arista *Tarista; //Tipo Arista






void menu()
{
    cout<<"\n\tREPRESENTACION DE GRAFOS DIRIGIDOS\n\n";
    cout<<" 1. INSERTAR UN NODO                 "<<endl;
    cout<<" 2. INSERTAR UNA ARISTA              "<<endl;
    cout<<" 3. ELIMINAR UN NODO                 "<<endl;
    cout<<" 4. ELIMINAR UNA ARISTA              "<<endl;
    cout<<" 5. MOSTRAR  GRAFO                   "<<endl;
    cout<<" 6. MOSTRAR ARISTAS DE UN NODO       "<<endl;
    cout<<" 7. SALIR                            "<<endl;



   cout<<"\n INGRESE OPCION: ";
}





//Programa Principal
int main()
{
    Tlista inicio = NULL;
    int op, _dato, pos;     // opcion del menu
    system("color 0b");
    do
    {
        menu1();  cin>> op;

        switch(op)
        {
            case 1:
                 cout<< "\n Digite el numero a insertar: "; cin>> _dato;
                 insertar(inicio, _dato);
            break;
            case 2:
                 if (inicio==NULL)
                      cout<< "\n La lista esta vacía ....."<<endl;
                 else
                    {
                     cout<< "\n Imprimir Lista: "<<endl;
                     imprimira(inicio);
                    }
            break;
            case 3:
                 if (inicio==NULL)
                      cout<< "\n La lista esta vacía ....."<<endl;
                 else
                    {
                     cout<< "\n Imprimir Lista: "<<endl;
                     imprimird(inicio);
                    }
            break;
            case 4:
                 if (inicio==NULL)
                      cout<< "\n La lista esta vacía ....."<<endl;
                 else
                    {
                     cout<< "\n Digite el numero a buscar: "; cin>> _dato;
                     buscarn(inicio, _dato);
                    }
            break;
            case 5:
                if (inicio==NULL)
                      cout<< "\n La lista esta vacía ....."<<endl;
                 else
                    {
                     cout<< "\n Digite el numero a eliminar: "; cin>> _dato;
                   //  modificarn(inicio, _dato);
                    }
            break;
            case 6:
                    if (inicio==NULL)
                      cout<< "\n La lista esta vacía ....."<<endl;
                 else
                    {
                     cout<< "\n Digite el numero a eliminar: "; cin>> _dato;
                     eliminarn(inicio, _dato);
                    }
            break;    
            case 7:
                    if (inicio==NULL)
                      cout<< "\n La lista esta vacía ....."<<endl;
                 else
                    {
                     cout<< "\n Digite el numero a eliminar: "; cin>> _dato;
                     eliminarn(inicio, _dato);
                    }
            break;    
       }
        cout<<endl<<endl;
        system("pause");  system("cls");

    }while(op!=7);
  
   system("pause");
   return 0;
}