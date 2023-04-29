//Programa Codigo C++ Listas Doblemente Enlazadas 
//Universidad Castro Carazo
//Curso de Estructura de Datos
#include <iostream>
#include <stdlib.h>
using namespace std;
 
struct nodo{
       int num;            // Variable entera
	   struct nodo *sgte;  // Variable tipo Puntero
	   struct nodo *ant;
};
 
typedef struct nodo *Tlista;

void insertar(Tlista &inicio,int valor)
{
	Tlista ptr, aux;
	ptr=new(struct nodo);
	ptr->ant=NULL;
	ptr->sgte=NULL;
	ptr->num=valor;
	if (inicio == NULL)
	{
		inicio=ptr;	
	}
	else
	   {
	   	if (valor < inicio->num)
	   		{
	   		ptr->sgte=inicio;
	   		inicio->ant=ptr;
	   		inicio=ptr;   		
			}
		else
			{
			aux=inicio;	
			while(aux->sgte!=NULL && valor>aux->num)
			{
				aux=aux->sgte;
			}
			if (aux->sgte==NULL && valor>aux->num)
				{
				 aux->sgte=ptr;
				 ptr->ant=aux;	
				}
			else
				{
				ptr->sgte=aux;
				ptr->ant=aux->ant;
				ptr->ant->sgte=ptr;
				ptr->sgte->ant=ptr;	
				}	
			}	
	   }	
}

void menu1()
{
    cout<<"\n\t\tLISTA ENLAZADA DOBLE \n\n";
    cout<<" 1. Insertar Ordenado                "<<endl;
    cout<<" 2. Imprimir Ascendente              "<<endl;
    cout<<" 3. Imprimir Descendente             "<<endl;
    cout<<" 4. Buscar Elemento                  "<<endl;
    cout<<" 5. Modificar Elemento               "<<endl;
    cout<<" 6. Eliminar Elemento                "<<endl;
    cout<<" 7. Salir                            "<<endl;
    cout<<"\n INGRESE OPCION: ";
}

void imprimira (Tlista &inicio)
{
	int i=0;
	Tlista ptr;
	ptr=inicio;
	while(ptr!=NULL)
	{
		cout<<' '<<i+1 <<") "<< ptr->num<<endl;
		ptr=ptr->sgte;
		i++;
	}
}
// Metódo Buscar número
void buscarn(Tlista &inicio,int valor)
{
	int i=1;
	int encontrado=0;
	Tlista ptr;
	ptr=inicio;
	while (ptr!=NULL && encontrado==0)
	{
		if(ptr->num==valor)
		   {
		   cout<< "\n Numero encontrado en la posición : "<<i<<endl;
		   encontrado=1;
		   }
		else
		{
			i=i+1;
			ptr=ptr->sgte;
		} 
	}
	if (encontrado==0) 
	  cout<< "\n El numero no existe en la lista enlazada  "<<endl;
}

void eliminarn(Tlista &inicio,int valor)
{
	int i=1;
	int encontrado=0;
	Tlista ptr;
	ptr=inicio;
	if (inicio->num == valor)
		{
		 inicio=inicio->sgte;
		 inicio->ant=NULL;
		 delete(ptr);
		 cout<<" Numero eliminado y encontrado en :"<<i<<endl;	
		}
	else
		{
		 while(ptr!=NULL && encontrado==0)
		 	{
		 	 if (ptr->num==valor)
			  	{
			  		if(ptr->sgte==NULL && ptr->num==valor)
			  		{
			  			encontrado=1;
			  			ptr->ant->sgte=NULL;
			  			delete(ptr);
			  			cout<<" Numero eliminado y encontrado en :"<<i<<endl;
					}
					else
					{
						ptr->ant->sgte=ptr->sgte;
						ptr->sgte->ant=ptr->ant;
						delete(ptr);
						encontrado=1;
						cout<<" Numero eliminado y encontrado en :"<<i<<endl;
					}
				}
				else
				{
					i++;
					ptr=ptr->sgte;	
				}
				
			}	
		}
	if (encontrado==0)
	 cout<<" El número a eliminar no esta en la lista enlazada"<<endl;					
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
                   //  imprimird(inicio);
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
       }
        cout<<endl<<endl;
        system("pause");  system("cls");
 
    }while(op!=7);
  
   system("pause");
   return 0;
}