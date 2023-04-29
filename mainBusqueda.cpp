#include<iostream>
#include<conio.h>
#include<string.h>
#define MAX 100
using namespace std;
struct fecha
{ char dia[3];
  char mes[3];
  char anho[5];
};
struct personal
{ char codigo[9];
  char nombre[MAX];
  char apellidos[MAX];
  struct fecha fecnac;
};
void leepersonal(int, struct personal[]);
void listado(int, struct personal[]);
void ordenaxfecha(int n,struct personal[]);
int busqueda (int, struct personal[], struct fecha);

int main()
{
	int n,pos;
	struct fecha f;
 	struct personal per[MAX];
 	cout<<"Cantidad de registros"; cin>>n;
 	leepersonal(n,per);
 	ordenaxfecha(n,per);
 	listado(n,per);
 	cout<<"que fecha de nacimiento desea buscar?:"<<endl;
 	cout<<"DIA:"; cin>>f.dia;
 	cout<<"MES:"; cin>>f.mes; 
 	cout<<"ANHO:"; cin>>f.anho;
 	pos=busqueda(n,per,f);
	if(pos==-1)
 		cout<<"Elemento no se encuentra"<<endl;
 	else
 		cout<<"Elemento encontrado en la posicion"<<pos;
 	getch();
}

void leepersonal(int n, struct personal x[])
{int i;
 for(i=0;i<n;i++)
 {cout<<"Codigo:"; cin>>x[i].codigo;
  cout<<"Nombre:"; cin>>x[i].nombre;
  cout<<"Apellidos:"; cin>>x[i].apellidos;
  cout<<"Dia:"; cin>>x[i].fecnac.dia;
  cout<<"Mes:"; cin>>x[i].fecnac.mes;
  cout<<"Anho:"; cin>>x[i].fecnac.anho;
  cout<<endl;
 }
}
void listado(int n, struct personal x[])
{cout<<endl<<"LISTADO DE EMPLEADOS"<<endl;
for(int i=0;i<n;i++)
{cout<<x[i].codigo<<"t" <<x[i].nombre<<"t" <<x[i].apellidos<<"t" <<x[i].fecnac.dia<<"t"<<x[i].fecnac.mes<<"t"<<x[i].fecnac.anho<<endl;
cout<<endl;
}
}
void ordenaxfecha(int n,struct personal x[])
{ struct personal temp;
  char f1[9],f2[9];
  for(int i=1;i<n;i++)
    for(int j=n-1;j>=i;j--)
     {strcpy(f1,"");strcpy(f2,"");
      strcat(f1,x[j-1].fecnac.anho);
      strcat(f1,x[j-1].fecnac.mes);
      strcat(f1,x[j-1].fecnac.dia);
      strcat(f2,x[j].fecnac.anho);
      strcat(f2,x[j].fecnac.mes);
      strcat(f2,x[j].fecnac.dia);
      if(strcmp(f1,f2)>0)
 {
  temp=x[j-1];
  x[j-1]=x[j];
  x[j]=temp;
 }}
}

int busqueda(int n,struct personal x[], struct fecha f)
{
char f1[9],f2[9];
  int mitad, izq=0, der=n-1;
  while(izq<=der)
  { mitad=(izq+der)/2 ;
    strcpy(f1,"");strcpy(f2,"");
    strcat(f1,f.anho);
    strcat(f1,f.mes);
    strcat(f1,f.dia);
    strcat(f2,x[mitad].fecnac.anho);
    strcat(f2,x[mitad].fecnac.mes);
    strcat(f2,x[mitad].fecnac.dia);
    if(strcmp(f1,f2)>0)izq=mitad+1;
    else if (strcmp(f1,f2)<0)der=mitad-1;
  else return mitad;
  }
 return -1;
}