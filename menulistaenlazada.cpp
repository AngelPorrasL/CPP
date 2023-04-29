/Programa Codigo C++ Listas Enlazadas
//Universidad Castro Carazo
//Curso de Estructura de Datos
#include <iostream>
#include <stdlib.h>
using namespace std;
 
struct nodo{
    int num;            //Variable entera
    struct nodo *sgte;  //Variable de tipo puntero
};
typedef struct nodo *Tlista;
 
//Insertar nodos al final de la lista.
 
void insertarF (Tlista &inicio, int valor)
{
    Tlista temp,aux;
    temp=new(struct nodo);
    temp->num=valor;
    temp->sgte=NULL;
    if (inicio==NULL)
       inicio=temp;
    else 
    {
        aux=inicio;    
        while (aux->sgte!=NULL)
            aux=aux->sgte;
        aux->sgte= temp;    
      }  

}
// Insertar nodos al inicio de la lista
void insertarI (Tlista &inicio, int valor)
{
    Tlista temp,aux;
    temp=new(struct nodo);
    temp->num=valor;
    temp->sgte=NULL;
    if (inicio==NULL)
        inicio=temp;
    else
        {
        temp->sgte=inicio;
        inicio=temp;
        }    
}
 
// Insertar nodos con el valor ordenado de menor a mayor.
void insertarO (Tlista &inicio, int valor){
    Tlista temp,ptr,ant;
    temp=new(struct nodo);
    temp->num=valor;
    temp->sgte=NULL;

    if (inicio == NULL){
        inicio = temp;
    }else if (valor<inicio->num) {
        temp->sgte=inicio;
        inicio=temp;
    }else{
        ant = NULL;
        ptr = inicio;
        while(ptr->sgte!=NULL && valor>ptr->num){
            ant = ptr;
            ptr = ptr->sgte;
        }

        if(ptr->sgte ==NULL && valor> ptr->num) //caso de que sea el final
        {
            ptr->sgte=temp;

        }
        else //en caso de que sea en medio
        {
            ant->sgte=temp;
            temp->sgte=ptr;


        }


    }
}
 
// Imprimir la lista enlazada
 
void imprimir(Tlista &inicio)
{
    int i=0;
    Tlista ptr;
    ptr=inicio;
    while (ptr!=NULL)
    {
        cout<< ' '<<i+1 <<") "<<ptr->num <<endl;
        ptr=ptr->sgte;
        i++;
    }

}
 
//Eliminar un nodo de la lista
 
void eliminarnodo (Tlista &inicio, int valor)
{
    Tlista ptr,ant;
    int i=1, bandera=0;

    if(inicio->num==valor)
    {
        ptr=inicio;
        inicio=inicio->sgte;
        delete(ptr);
        //bandera=1;
    }
    else
    {
        ant=NULL;
        ptr=inicio;
        while(ptr->sgte!=NULL && ptr->num!=valor)
        {
          ant=ptr;
          ptr=ptr->sgte;
        }
        if(ptr->num==valor && ptr->sgte ==NULL) //caso de que sea el final
        {
            delete(ptr);
            ant->sgte=NULL;
            bandera=1;
        }
        else //en caso de que sea en medio
        {
            if(ptr->num==valor)
            {    
            ant->sgte=ptr->sgte;
            delete (ptr);
            bandera=1;
            }
        }
        if(bandera==0)
        {
            cout<<" Numero no se encuentra en la lista...!"<<endl;
        }

    }
}
 
//Buscar  un nodo de la lista
 
void buscarnodo (Tlista &inicio, int valor)
{    
    Tlista ptr,ant;
    int i=1,bandera=0;
    ptr=inicio;
    while(ptr!=NULL)
    {
        if(ptr->num==valor)
        {
        cout<< "Encontrado en la posicion: "<<i<<endl;
        bandera=1;
        }
        ptr=ptr->sgte;
        i+=1;
    }
    if(bandera==0)
     cout<< "El numero no existe en la lista "<<endl;
 
}
void menu1()
{
    cout<<"\n\t\tLista Enlazadas \n\n            "<<endl;
    cout<<"1. Insertar nodo Final               "<<endl;
    cout<<"2. Insertar nodo inicio              "<<endl;
    cout<<"3. Insertar numeros de menor a mayor "<<endl;
    cout<<"4. Imprimir la lista                 "<<endl;
    cout<<"5. Eliminar nodo                     "<<endl;
    cout<<"6. Buscar nodo                        "<<endl;
    // Si el nodo esta y que posición se encuentra
    cout<<"7. Salir     "<<endl;
    cout<<"\n Ingrese la opción ";
}
 
// Modulo principal
 
int main()
{
    Tlista inicio = NULL;
    int op;
    int dato;
    int pos;
    do
    {
        menu1();  
        cin>> op;

        switch(op)
        {
            case 1:
                 cout<< "\n NUMERO A INSERTAR: "; cin>> dato;
                 insertarF(inicio,dato);

                 imprimir(inicio);
            break;
            case 2:
                 cout<< "\n NUMERO A INSERTAR: "; cin>> dato;
                 insertarI(inicio,dato);
                 imprimir(inicio);
            break;
            case 3:
                cout<< "\n NUMERO A INSERTAR: "; cin>> dato;
                insertarO(inicio,dato);
                imprimir(inicio);

            break;

            case 4:
                cout<< "\n Impresion de la Lista "<<endl; 
                if (inicio==NULL)
                    cout<< "\n La lista esta vacía "<<endl;
                else
                    imprimir(inicio);
            break;
            case 5:
                cout<< "\n Eliminar nodo de la lista "<<endl; 
                if (inicio==NULL)
                    cout<< "\n La lista esta vacía "<<endl;
                else
                    {
                    cout<< "\n Digite el número a Eliminar: "; 
                    cin>> dato;
                    eliminarnodo(inicio,dato);
                    }
            break;
            case 6:
                int i=0;
                cout<<"\n Buscar número: "; 

                if (inicio==NULL)
                    cout<< "\n La lista esta vacía "<<endl;
                else
                    {
                    cout<< "\n Digite el número a Buscar: "; 
                    cin>> dato;
                    buscarnodo(inicio,dato);
                    }








            break;
        }
        cout<<endl;
        system("pause");
        system("cls");
    }while (op!=7);
system("pause");
return 0;
}