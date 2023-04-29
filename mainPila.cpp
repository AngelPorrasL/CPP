#include <iostream>

using namespace std;
struct nodo{
    int nro;  
    struct nodo *sgte;
};

typedef nodo *ptrpila;  // Crear un nodo tipo puntero

//Apilar elemento
void apilar(ptrpila&p,int valor)
{
    ptrpila aux;
    aux=new(struct nodo);
    aux->nro=valor;
    aux->sgte=p;
    p=aux;
}

// Desapilar elemento
int desapilar(ptrpila&p)
{
    int num;
    ptrpila aux;
    aux=p;
    num=aux->nro;
    p=aux->sgte;
    delete(aux);
    return num;
}

//Imprimir la pila
void mostrar_pila(ptrpila p)
{
    ptrpila aux;
    aux=p;
    while(aux!=NULL)
    {
        cout<<"\t"<<aux->nro <<endl;
        aux=aux->sgte;
    }
}

//Eliminar pila
void limpiar_pila(ptrpila&p)
{
    ptrpila aux;
    while(p!=NULL)
    {
        aux=p;
        p=aux->sgte;
        delete(aux);
    }
}

//Menu del programa
void menu()
{
    cout<<"\n\t Creando la estructura pila \n\n";
    cout<<"1. Apilar elemento     "<<endl;
    cout<<"2. Desapilar elemento  "<<endl;
    cout<<"3. Imprimir la pila    "<<endl;
    cout<<"4. Eliminar la pila    "<<endl;
    cout<<"5. Salir               "<<endl;
}

//Programa Principal
int main()
{
    ptrpila p=NULL;  //Limpiar la pila
    int dato;
    int op;
    int numero;
    system("color 0b");
    do
    {
        menu(); cin>>op;
        switch(op)
        {
            case 1:
                cout<<"\n Número a ingresar a la pila"; cin>>dato;
                apilar(p,dato);
                cout<<"Dato apilado";
            break;
            case 2:
                if (p!=NULL)
                    {
                    numero=desapilar(p);
                    cout<<"\n\n\t\tNumero desapilado: "<<numero <<"...\n\n";
                    }
                else
                    cout<<"\n\n\tPila Vacia....."<<endl;    
            break;
            case 3:
                cout<<"\n\n\tImprimiendo la pila....."<<endl;
                if (p!=NULL)
                    mostrar_pila(p);
                else
                    cout<<"\n\n\tPila Vacia....."<<endl;    
            break;
            case 4:
                    cout<<"\n\n\tEliminando la pila....."<<endl;
                if (p!=NULL)
                    limpiar_pila(p);
                else
                    cout<<"\n\n\tPila Vacia....."<<endl;       
            break;
        }
        cout<<endl;
        system ("pause");
        system ("cls");
    }while (op!=5);
    return 0;
}