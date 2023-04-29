#include <iostream>
#include <stdlib.h>

using namespace std;
// Programa de Arboles balanceados
struct nodo{
   int num;
       struct nodo *izq;
       struct nodo *der;
};

typedef struct nodo *Tlista;


void insertaorden(Tlista &raiz,int valor)
{
  Tlista ptr,cont;
  ptr=new(struct nodo);
  ptr->num=valor;
  ptr->izq=NULL;
  ptr->der=NULL;
  if (raiz==NULL)
    raiz=ptr;
  else
     {
      if(ptr->num > raiz->num)
        if (raiz->der==NULL)
                raiz->der=ptr;
            else
            {
            cont=raiz->der;
            while(cont->der!=NULL && cont->num < valor)
             cont=cont->der;
            if(valor >cont->num)
               cont->der=ptr;
            else
               cont->izq=ptr;
            
            }    
      
      else
          {
          if(raiz->izq==NULL)
          raiz->izq=ptr;    
          else
              {
               cont=raiz->izq;
               while(cont->izq!=NULL && cont->num>valor)
               cont=cont->izq;
               if(valor < cont->num)
               cont->izq=ptr;
            else
               cont->der=ptr;
             }
         }
      
    }  
}

void Preorden(Tlista ptr)
{
  if(ptr != NULL){
     cout<<" "<<ptr->num;
     Preorden(ptr->izq);
     Preorden(ptr->der);
    }
}
void Postorden(Tlista ptr)
{
if(ptr != NULL){
     Postorden(ptr->izq);
     Postorden(ptr->der);
     cout<<" "<<ptr->num;
    }
}
void Inorden(Tlista ptr)
{
if(ptr != NULL){
     
     Inorden(ptr->izq);
     cout<<" "<<ptr->num;
     Inorden(ptr->der);
    }
}
void mostrarArbol(Tlista ptr, int n){
    if(ptr != NULL){
        mostrarArbol(ptr->der, n+1);
        for(int i = 0; i < n; i++)
            cout << " ";
        cout << ptr->num << endl;
        mostrarArbol(ptr->izq, n+1);
    }
}

void menu1()
{
cout<<"\n\t\tARBOLES BALANCEADOS\n\n";
cout<<" 1. Limpiar Arbol     "<<endl;
cout<<" 2. Insertar elemento "<<endl;
cout<<" 3. Preorden     "<<endl;
cout<<" 4. Postorden    "<<endl;
cout<<" 5. Inorden      "<<endl;
cout<<" 6. Mostrar arbol        "<<endl;
cout<<" 7. SALIR        "<<endl;
cout<<"\n INGRESE OPCION: ";
}



int main()
{
Tlista raiz = NULL;
int op; // opcion del menu
int nume; // elemenento a ingresar
int pos,canti; // posicion a insertar



system("color 0b");
do
{
    menu1(); cin>> op;
    switch(op)
    {
        case 1:
            cout<< "\n Limpiar el Arbol";
            raiz=NULL;
        break;
        case 2:
            cout<< "\n NUMERO A INSERTAR: "; cin>> nume;
            insertaorden(raiz, nume);
        break;
        case 3:
            cout<<"\n MODULO IMPRIMIR PREORDEN";
            Preorden(raiz);
        break;
        case 4:
            cout<<"\n MODULO IMPRIMIR POSTORDEN";
            Postorden(raiz);
        break;
        case 5:
            cout<<"\n MODULO IMPRIMIR INORDEN";
            Inorden(raiz);
        break;
        case 6:
        	cout<<"\n ARBOL\n\n";
            mostrarArbol(raiz, 0);
        break;

   }
    cout<<endl<<endl;
    system("pause");
    system("cls");
    }while (op!=7);
system("pause");
return 0;
}