#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void menu1()
{
	system("color 0A");
	system ("cls");
	cout<<"\n\t\t Menu Principal \n\n";
	cout<<" 1 Llenar el Vector    "<<endl;
	cout<<" 2 Llenar de números   "<<endl;
	cout<<" 3 Imprimir el Vector  "<<endl;
	cout<<" 4 El mayor, menor, promedio	  "<<endl;
	cout<<" 5 Ordenar el vector	  "<<endl;
	cout<<" 6 Limpiar matriz      "<<endl;
	cout<<" 7 Llenar matriz       "<<endl;
	cout<<" 8 Imprimir Matriz     "<<endl;
	cout<<" 9 Sumar las filas     "<<endl;
	cout<<" 10 Salir               "<<endl;   
}
//Programa Principal
int main()
{
 int op,sub,i,j,min,max,suma,temp;
 float promedio;
 int vect[5];
 int mat[4][4];
 do
  {
 	menu1();
 	cin>>op;
 	switch(op)
 	{
 		case 1:
 			//Llenar Vector de ceros 
			cout<< "Llenar el vector " <<endl;
			for(i=0;i<=4;i++)
			  vect[i]=0;
			break;	
		case 2:
		    // Llenar vector de números
			cout<< "Llenando de números el arreglo" <<endl;
			for (i=0;i<=4;i++)
			  	{
			  		cout<<"Digite el número" <<endl;
			  		cin>>vect[i];
				  }
			break;
		case 3:
		    // Imprimir el vector
			cout<<"Imprimir el vector ascendente"<<endl;
			for (i=0;i<=4;i++)
			  cout<<" "<<vect[i];
			cout<<endl;  
			system("pause");
			cout<<"Imprimir el vector descendente"<<endl;
			for (i=4;i>=0;i--)
			  cout<<" "<<vect[i];
			cout<<endl;
			system("pause");
		   break;
		case 4:
		   //Operaciones arreglos
		   min=99;
		   max=0;
		   suma=0;
		   for(i=0;i<=4;i++)
		   {
		   	suma+=vect[i];
		   	if(vect[i]<min)
		   	  min=vect[i];
		   	if(vect[i]>max)
			   max=vect[i];  
		   }
		   cout<<"El mayor es: "<<max<<endl;
		   cout<<"El menor es: "<<min<<endl;
		   promedio=suma/5;
		   cout<<"El promedio es: "<<promedio<<endl;
		   system("pause>nul");
		   break; 
		case 5:
			//Método de la burbuja  a=vect.lentgh
			for(j=5;j>=0;j--)
			{
				for(i=0;i<j-1;i++)
				{
					if(vect[i]>vect[i+1])
					{	
					temp=vect[i+1];
					vect[i+1]=vect[i];
					vect[i]=temp;
					}
				}
	    	}
		   break;
		case 6:
			// Limpiar la matriz
			cout<<"Limpiando la matriz"<<endl;
			for(i=0;i<=3;i++)
			  for(j=0;j<=3;j++)
			     mat[i][j]=0;
			system("pause>nul");     
			break;
		case 7:
			// Llenar la matriz random
			cout<<"Llenar la matriz de números"<<endl;
			srand(time(NULL));
			for(i=0;i<=2;i++)
			  for(j=0;j<=2;j++)
			     mat[i][j]=rand()%10+1;
			system("pause>nul");
			break;
		case 8:
			// Imprimir el arreglo bidimensional
			cout<<"Imprimiendo la matriz"<<endl;
			for(i=0;i<=3;i++)
			{
			  for(j=0;j<=3;j++)
			    {
			     cout<<mat[i][j]<<" ";	
				}
			cout<<" "<<endl;	
		   }
			system("pause>nul");
			break;
		case 9:
			//Sumar las filas de la columna 0 a la 2 en la 3
			cout<<"Sumando las filas de la Matriz"<<endl;
			suma=0;
			for(i=0;i<=2;i++)
			 {
			  for(j=0;j<=2;j++)
			   {
			    suma+=mat[i][j];
			   } 
			 mat[i][3]=suma;   
			 suma=0;
	    	}
			break;	 	  
   }
 }   while (op!=10);
 system("pause");
 system("cls");
 return 0;
}