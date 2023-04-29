#include <iostream>
#include <stdlib.h>
using namespace std;
 
struct nodo{
       int num;            
	   struct nodo *sgte;  
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
	if (inicio==NULL)
	{
		inicio=ptr;
		inicio->ant=ptr;
		inicio->sgte=ptr;	
	}
	if (valor<inicio->num)
	{
		ptr->sgte=inicio;
		ptr->ant=ptr->sgte->ant;
		ptr->ant->sgte=ptr;
		ptr->sgte->ant=ptr;
		inicio=ptr;
		
	}
	else
	{
		aux=inicio;
		while(aux->sgte!=inicio && aux->num < valor )
		aux=aux->sgte;
		if(aux->num > valor)
		{
		 ptr->sgte=aux;	
		 ptr->ant=aux->ant;
		 ptr->ant->sgte=ptr;
		 ptr->sgte->ant=ptr;
		}
		else
		{
			ptr->ant=aux;
			ptr->sgte=ptr->ant->sgte;
			ptr->ant->sgte=ptr;
			ptr->sgte->ant=ptr;	
		}
	}
}

void menu1()
{
    cout<<"\n\t\tLista Enlazada Circular \n\n";
    cout<<" 1. Insertar Ordenado                "<<endl;
    cout<<" 2. Imprimir Ascendente              "<<endl;
    cout<<" 3. Imprimir Descendente             "<<endl;
    cout<<" 4. Buscar Elemento                  "<<endl;
    cout<<" 5. Modificar Elemento               "<<endl;
    cout<<" 6. Eliminar Elemento                "<<endl;
    cout<<" 7. Contar elementos de la lista     "<<endl;
    cout<<" 8. Salir                            "<<endl;
    cout<<"\n INGRESE OPCION: ";
}

void imprimira (Tlista &inicio)
{
	int i=0;
	Tlista ptr;
	ptr=inicio;
	while(ptr->sgte!=inicio)
	{
		cout<<' '<<i+1 <<") "<< ptr->num<<endl;
		ptr=ptr->sgte;
		i++;
	}
	if(ptr->sgte==inicio)
	cout<<' '<<i+1<<") "<< ptr->num<<endl;
}
void imprimird(Tlista &inicio)
{
	int i=0;
	Tlista ptr;
	ptr=inicio->ant;
	while(ptr->ant!=inicio)
	{
		cout<<' '<<i+1 <<") "<< ptr->num<<endl;
		ptr=ptr->ant;
		i++;
	}
	if(ptr->ant==inicio)
	cout<<' '<<i+1<<") "<< ptr->num<<endl;
}

void buscarn(Tlista &inicio,int valor)
{
	int i=1;
	int encontrado=0;
	Tlista ptr;
	ptr=inicio;
	while (ptr->sgte!=inicio && encontrado==0)
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
		 ptr->sgte->ant=ptr->ant;
		 ptr->ant->sgte=ptr->sgte;
		 inicio=ptr->sgte;
		 delete(ptr);
		 cout<<" Numero eliminado y encontrado en :"<<i<<endl;	
		}
	else
	{
	 while(ptr->sgte!=inicio && encontrado==0)
	 {
	  if (ptr->num==valor)
	    {
	  	 encontrado=1;
	  	 ptr->sgte->ant= ptr->ant;
	  	 ptr->ant->sgte=ptr->sgte;
	  	 delete(ptr);
	    }
	  else
	  	  ptr=ptr->sgte;	  	  
	 }
	 if (ptr->sgte==inicio && ptr->num==valor)
	 {
	  encontrado=1;
	  ptr->ant->sgte=ptr->sgte;
	  ptr->sgte->ant=ptr->ant;
	  delete(ptr);	
	 }
	 else
	 { 
	  if (encontrado==0)
	    cout<<" El número a eliminar no esta en la lista enlazada"<<endl;
	 }
	
	}
}
	
void modificar(Tlista &inicio,int valor)
{
	int i=1;
	int encontrado=0;
	Tlista ptr;
	ptr=inicio;
	if(inicio!=NULL)
	{
		do
		{		
			if(ptr->num==valor)
			{
				cout << "\n Numero " << valor << " encontrado";
				
				cout << "\n\n Ingrese el nuevo numero: ";
				cin >> ptr->num;
				cout << "\n Numero modificado\n\n";
				
				encontrado = 1;				
			}
			
			ptr = ptr->sgte;
		}
		while(ptr!=inicio && encontrado==0);
		
		if (encontrado==0) {
			cout << "\n Numero no encontrado en la lista\n\n";
		}	
	}
}

int main()
{
    Tlista inicio = NULL;
    int op, _dato, pos;
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
					 cout<< "\n Digite el numero a modificar: "; cin>> _dato;
                     modificar(inicio, _dato);
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
 
    }while(op!=8);
  
   system("pause");
   return 0;
}