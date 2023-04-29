#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

using namespace std;

 
typedef struct nodo *Tlista;
 
typedef struct nodo{
	string empresa;
	string nombre;
	string fechaN;
	string direccion;
	int telefono;
	char dato;
	Tlista sig;
	Tlista ant;
};

void menu (int &op)
{
	cout << " \n MENU PRINCIPAL\n\n" << endl;
	cout << " 1- Iniciar agenda" << endl;
	cout << " 2- Agregar usuarios" << endl;
	cout << " 3- Consultar usuarios" << endl;
	cout << " 4- Borrar usuarios" << endl;
	cout << " 5- Lista de usuarios" << endl;
	cout << " 6- Ver cantidad de usuarios\n" << endl;
	cout << " \n    SUBMENU\n\n" << endl;
	cout << "    7- Modificar numero telefonico" << endl;
	cout << "    8- Modificar nombre" << endl;
	cout << "    9- Modificar empresa" << endl;
	cout << "    10- Modificar fecha de nacimiento" << endl;
	cout << "    11- Modificar direccion corta" << endl;
	cout << "    12- Mostrar edad" << endl;
	cout << "    13- Ver cumpleannos" << endl;
	cout << "    14- SALIR" << endl;
 
	cout << "\n\n Seleccione alguna opcion: ";
	cin >> op;
}


/*void submenu (int &op)
{
	cout << " \n SUBMENU\n\n" << endl;
	cout << " 1- Modificar numero" << endl;
	cout << " 2- Agregar Persona" << endl;
	cout << " 3- Consultar Persona" << endl;
	cout << " 4- Modificar Persona" << endl;
	cout << " 5- Borrar Persona" << endl;
	cout << " 6- Lista de Personas" << endl;
	cout << " 7- Consultar Tamanno" << endl;
	cout << " 8- Salir" << endl;
	
	cout << "\n\n Seleccione alguna opcion: ";
	cin >> op;
}*/
				
		


void iniciar_lista (Tlista &inicio)
{
	Tlista i;
	char letras;
	inicio = NULL;
	for(i=inicio;i!=NULL;i=i->sig)
	{
 
		cout<<"Letras: "<<i->dato<<endl;
 
	}
	system("pause");
}
void crear (Tlista &nuevo)
{
	int op;
	bool volver=false;
	string rta="";
	nuevo = new nodo;
	if (nuevo != NULL)
	{
		do {
 
			cout << "\n Ingrese su nombre: ";
			cin >> nuevo->nombre;
			cout << "\n Ingrese su numero de telefono: ";
			cin >> nuevo->telefono;
			cout << "\n Ingrese su fecha de nacimiento: ";
			cin >> nuevo->fechaN;
			cout << "\n Ingrese una direccion corta: ";
			cin >> nuevo->direccion;
			cout << "\n Ingrese el nombre de su empresa: ";
			cin >> nuevo->empresa;
			nuevo->sig = NULL;
			system("cls");
		} while((nuevo->nombre!=nuevo->nombre) && (nuevo->telefono!=nuevo->telefono) && (nuevo->fechaN!=nuevo->fechaN) && (nuevo->direccion!=nuevo->direccion) && (nuevo->empresa!=nuevo->empresa));
	}
	else
		cout << "\n Memoria Insuficiente" << endl;
}
 
void agregar_inicio (Tlista &inicio, Tlista nuevo)
{
	nuevo -> sig = inicio;
	inicio = nuevo;
}

//Definicion de la Funcion
void calcularEdad( int anioAct , int mesAct, int fechAct, int anioNac, int mesNac, int fechNac)
{
    int respFech , respMes;
 
    if ( fechAct < fechNac  )
    {   //En caso de ser menor la fecha actual que el nacimiento
        fechAct = fechAct + 30; // Se le suma los 30 días (1 mes) a la fecha actual
        mesAct = mesAct - 1; // Se le resta un mes (30 días) al mes actual
        respFech =  fechAct - fechNac; //Se le resta fecha nacimiento al actual
    }
    else //En caso de ser mayor la fecha actual que el nacimiento
        respFech =  fechAct - fechNac;  //Se le resta fecha nacimiento al actual
 
    if( mesAct < mesNac )
    {   //En caso de ser menor el mes actual que el nacimiento
        mesAct = mesAct + 12; // Se le suma los 12 meses (1 año) al mes actual
        anioAct = anioAct - 1 ; // Se le resta 1 año ( 12 meses) al año actual
        respMes = mesAct - mesNac; //Se le resta año nacimiento al actual
    }
    else //En caso de ser mayor el mes actual que el nacimiento
        respMes = mesAct - mesNac; //Se le resta año nacimiento al actual
 
}


Tlista quitar_inicio (Tlista &inicio)
{
	Tlista borrado;
	if (inicio == NULL)
		borrado = NULL;
	else
	{
		borrado = inicio;
		inicio = inicio -> sig;
		borrado -> sig = NULL;
	}
	return borrado;
}

Tlista quitar_final (Tlista &inicio)
{
	Tlista borrado, i;
	if (inicio == NULL)
		borrado = NULL;
	else

		if (inicio -> sig == NULL)
		{
			borrado = inicio;
			inicio = NULL;
		}
		else
		{
			
			for (i = inicio; (i -> sig) -> sig != NULL; i = i -> sig);
			borrado = i -> sig;
			i -> sig = NULL;
		}
	return borrado;
}
 
Tlista quitar_buscado (Tlista &inicio, int valor)
{
	Tlista borrado, i;
	if (inicio == NULL)
		borrado = NULL;
	else
		if (inicio->telefono == valor)
		{
			borrado = inicio;
			inicio = borrado -> sig;
			borrado -> sig = NULL;
		}
		else
		{
			for (i = inicio; i -> sig != NULL && valor != (i -> sig)->telefono; i = i -> sig);
			if (i -> sig != NULL)
			{
				borrado = i -> sig;
				i -> sig = borrado -> sig;
				borrado -> sig = NULL;
			}
			else
				borrado = NULL;
		}
	return borrado;
}

void modificarNum(Tlista &inicio,int valor)
{
	int i=1;
	int encontrado=0;
	Tlista Tlista;
	Tlista=inicio;
	if(inicio!=NULL)
	{
		do
		{		
			if(Tlista->telefono==valor)
			{
				cout << "\n Numero " << valor << " encontrado";
				
				cout << "\n\n Ingrese el nuevo numero telefonico: ";
				cin >> Tlista->telefono;
				cout << "\n Numero modificado correctamente!\n\n";
				
				encontrado = 1;				
			}
			
			Tlista = Tlista->sig;
		}
		while(Tlista!=inicio && encontrado==0);
		
		if (encontrado==0) {
			cout << "\n Numero no encontrado en la agenda\n\n";
		}	
	}
}

void modificarNom(Tlista &inicio,string valorS)
{
	int encontrado=0;
	Tlista Tlista;
	Tlista=inicio;
	if(inicio!=NULL)
	{
		do
		{		
			if(Tlista->nombre==valorS)
			{
				cout << "\n Nombre " << valorS << " encontrado";
				
				cout << "\n\n Ingrese el nuevo nombre: ";
				cin >> Tlista->nombre;
				cout << "\n Nombre modificado correctamente!\n\n";
				
				encontrado = 1;				
			}
			
			Tlista = Tlista->sig;
		}
		while(Tlista!=inicio && encontrado==0);
		
		if (encontrado==0) {
			cout << "\n Nombre no encontrado en la agenda\n\n";
		}	
	}
}

void modificarEm(Tlista &inicio,string valorS)
{
	int encontrado=0;
	Tlista Tlista;
	Tlista=inicio;
	if(inicio!=NULL)
	{
		do
		{		
			if(Tlista->empresa==valorS)
			{
				cout << "\n Empresa " << valorS << " encontrada";
				
				cout << "\n\n Ingrese la nueva empresa: ";
				cin >> Tlista->empresa;
				cout << "\n Empresa modificada correctamente!\n\n";
				
				encontrado = 1;				
			}
			
			Tlista = Tlista->sig;
		}
		while(Tlista!=inicio && encontrado==0);
		
		if (encontrado==0) {
			cout << "\n Empresa no encontrada en la agenda\n\n";
		}	
	}
}

void modificarFechaN(Tlista &inicio,string valorS)
{
	int encontrado=0;
	Tlista Tlista;
	Tlista=inicio;
	if(inicio!=NULL)
	{
		do
		{		
			if(Tlista->fechaN==valorS)
			{
				cout << "\n Fecha de nacimiento " << valorS << " encontrada";
				
				cout << "\n\n Ingrese la nueva fecha de nacimiento: ";
				cin >> Tlista->fechaN;
				cout << "\n Fecha de nacimiento modificada correctamente!\n\n";
				
				encontrado = 1;				
			}
			
			Tlista = Tlista->sig;
		}
		while(Tlista!=inicio && encontrado==0);
		
		if (encontrado==0) {
			cout << "\n Fecha de nacimiento no encontrada en la agenda\n\n";
		}	
	}
}

void modificarCumple(Tlista &inicio,string valorS)
{
	int encontrado=0;
	Tlista Tlista;
	Tlista=inicio;
	if(inicio!=NULL)
	{
		do
		{		
			if(Tlista->fechaN==valorS)
			{
				cout << "\n El usuario esta cumpliendo años" << valorS << " feliz cumpleaños!";
				
				encontrado = 1;				
			}
			
			Tlista = Tlista->sig;
		}
		while(Tlista!=inicio && encontrado==0);
		
		if (encontrado==0) {
			cout << "\n El usuario de la fecha ingresada no esta cumpliendo años\n\n";
		}	
	}
}

void modificarDirec(Tlista &inicio,string valorS)
{
	int encontrado=0;
	Tlista Tlista;
	Tlista=inicio;
	if(inicio!=NULL)
	{
		do
		{		
			if(Tlista->direccion==valorS)
			{
				cout << "\n Direccion corta " << valorS << " encontrada";
				
				cout << "\n\n Ingrese la nueva direccion corta: ";
				cin >> Tlista->direccion;
				cout << "\n Direccion corta modificada correctamente!\n\n";
				
				encontrado = 1;				
			}
			
			Tlista = Tlista->sig;
		}
		while(Tlista!=inicio && encontrado==0);
		
		if (encontrado==0) {
			cout << "\n Direccion corta no encontrada en la agenda\n\n";
		}	
	}
}

bool buscar_nodo (Tlista inicio, int valor)
{
	Tlista i;
	bool encontrado = false;
	if (inicio != NULL)
		for (i = inicio; i != NULL && encontrado == false; i = i -> sig)
		{
			if (i->telefono == valor)
				encontrado = true;
		}
	return encontrado;
}

void mostrar (Tlista inicio)
{
	Tlista i;
	if (inicio != NULL)
	{
 
		for (i = inicio; i != NULL; i = i -> sig)
		{
			cout << "\n" << endl;
			cout << "\n";
			cout << " Nombre: " << i->nombre << "\n ";
			cout << "Numero de telefono: " << i->telefono << "\n ";
			cout << "Fecha de nacimiento: " << i->fechaN << "\n ";
			cout << "Direccion: " << i->direccion << "\n ";
			cout << "Nombre de la empresa: " << i->empresa << "\n ";
			cout << "\n" << endl;
		}
	}
	else
		cout << "\n Agenda Vacia" << endl;
}

int contar_personas(Tlista inicio)
{
	Tlista i;
	int suma=0;
	if(inicio!=NULL)
	{
		for(i=inicio;i!=NULL;i=i->sig)
		{
			suma=suma+1;
		}
	}
	return suma;
}

/*void submenu (int &po)
{
	int valor;
	Tlista inicio;
	
	do
	{
		cout << " \n SUBMENU\n\n" << endl;
		cout << " 1- Modificar numero" << endl;
		cout << " 2- Agregar Persona" << endl;
		cout << " 3- Consultar Persona" << endl;
		cout << " 4- Modificar Persona" << endl;
		cout << " 5- Borrar Persona" << endl;
		cout << " 6- Lista de Personas" << endl;
		cout << " 7- Consultar Tamanno" << endl;
		cout << " 8- Salir" << endl;
 
		cout << "\n\n Seleccione alguna opcion: ";
		cin >> po;
		
		
		system ("cls");
		switch (po)
		{
			case 1:
				{
					cout<< "\n Numero a modificar: "; cin>> valor;
                    modificar(inicio, valor);
				}
				cout << "\n";
				system ("pause");
				break;
				{
				}
				cout << "\n";
				system ("pause");
				break;
				
			case 3:
				{
				}
				cout << "\n";
				system ("pause");
				break;
				
			case 4:
				{
				}
				break;
				
			case 5:
				{
				}
				cout << "\n";
				system ("pause");
				break;
				
			case 6:
				{
				}
				cout << "\n";
				system ("pause");
				break;
		}
	}while (po != 7);
	cout << "\n";
}*/

int main ()
{
	int op,sec,total;
	int valor;
	int anioAct;  //Año Actual
    int mesAct; //Mes actual
    int fechAct; //Fecha actual
    int respFech , respMes;
    int anioNac; //Año nacimiento
    int mesNac; //Mes nacimiento
    int fechNac; 
	string valorS;
	bool op1 = false;
	bool guardar=false;
	Tlista inicio, nuevo, eliminado;
	char rta;
	do
	{
		system ("cls");
		menu (op);
		switch (op)
		{
			case 1: iniciar_lista (inicio);
 
				op1 = true;
				cout << "\n Iniciando agenda..."<< endl;
				cout << "\n Programa Iniciado!" << endl;
				cout << "\n";
				system ("pause");
				break;
			case 2: if (op1 == true)
				{
					do{
						crear (nuevo);
						if (nuevo != NULL){
							agregar_inicio (inicio, nuevo);
							cout<<"Desea ingresar mas personas S/N"<<endl;
							cin>>rta;
						}else{
							cout << "\n\n Selecione primero la opcion 1" << endl;
						}
					}while((rta!='N')&&(rta!='n'));
				}
				cout << "\n";
				system ("pause");
				break;
				
			case 3: if (op1 == true)
				{
					cout << "\n Ingrese el numero de telefono para poder buscar: ";
					cin >> valor;
					if (buscar_nodo (inicio, valor) == true)
						cout << "\n Numero encontrado" << endl;
					else
						cout << "\n El numero de telefono no fue encontrado" << endl;
				}
				else
					cout << "\n\n Selecione primero la opcion 1" << endl;
				cout << "\n";
				system ("pause");
				break;
				
			case 4: if (op1 == true)
				{
					cout << "\n Ingrese el numero de telefono para poder eliminar a el usuario: ";
					cin >> valor;
					eliminado = quitar_buscado (inicio, valor);
					if (eliminado != NULL)
					{
						cout << "\n Usuario eliminado " << eliminado -> dato << "" << endl;
						delete (eliminado);
					}
					else
						cout << "\n No se puede eliminar, el numero ingresado no esta en la lista" << endl;
				}
				else
					cout << "\n\n Selecione primero la opcion 1" << endl;
				cout << "\n";
				system ("pause");
				break;
				
			case 5: if (op1 == true)
					mostrar (inicio);
				else
					cout << "\n\n Selecione primero la opcion 1" << endl;
				cout << "\n";
				system ("pause");
				break;
				
			case 6: if(op1 == true)
				{
					total=contar_personas(inicio);
					cout<<" La cantidad de usuarios en la agenda es de: "<<total<<endl;
					system("pause");
				}else{
					cout << "\n\n Selecione primero la opcion 1" << endl;
				 cout << "\n";
				 system ("pause");
				}
				break;
				
				case 7: if(op1 == true)
				{
					cout<< "\n Digite el numero a modificar: "; cin>> valor;
                    modificarNum(inicio, valor);
				}
				else
					cout << "\n\n Selecione primero la opcion 1" << endl;
				cout << "\n";
				system ("pause");
				break;
				
				case 8: if(op1 == true)
				{
					cout<< "\n Escriba el nombre a modificar: "; cin>> valorS;
                    modificarNom(inicio, valorS);
				}
				else
					cout << "\n\n Selecione primero la opcion 1" << endl;
				cout << "\n";
				system ("pause");
				break;
				
				case 9: if(op1 == true)
				{
					cout<< "\n Escriba la empresa a modificar: "; cin>> valorS;
                    modificarEm(inicio, valorS);
				}
				else
					cout << "\n\n Selecione primero la opcion 1" << endl;
				cout << "\n";
				system ("pause");
				break;
				
				case 10: if(op1 == true)
				{
					cout<< "\n Escriba la fecha de nacimiento a modificar: "; cin>> valorS;
                    modificarFechaN(inicio, valorS);
				}
				else
					cout << "\n\n Selecione primero la opcion 1" << endl;
				cout << "\n";
				system ("pause");
				break;
				
				case 11: if(op1 == true)
				{
					cout<< "\n Escriba la direccion corta a modificar: "; cin>> valorS;
                    modificarDirec(inicio, valorS);
				}
				else
					cout << "\n\n Selecione primero la opcion 1" << endl;
				cout << "\n";
				system ("pause");
				break;
				
				case 12: if(op1 == true)
				{
					cout << "\n Ingrese el año actual: ";   cin >> anioAct;
                    cout << "\n Ingrese el mes actual: ";   cin >> mesAct;
                    cout << "\n Ingrese la fecha actual: ";  cin >> fechAct;
 
                    cout << "\n\n Ingrese su año de nacimiento: ";  cin >> anioNac;
                    cout << "\n Ingrese su mes de nacimiento: ";  cin >> mesNac;
                    cout << "\n Ingrese su fecha de nacimiento: ";  cin >> fechNac;
                    
                    cout << "\n Usted tiene:\n";
                    cout << " Edad: " <<anioAct - anioNac << endl;//Muestra edad
                    /*cout << " Mes: " << respMes << endl;//Muestra mes
                    cout << " Dia: " << respFech << endl;//Muestra 
                    */
                system ("pause");
				break;
			
				}
				else
					cout << "\n\n Selecione primero la opcion 1" << endl;
				cout << "\n";
				system ("pause");
				break;
				
				case 13: if(op1 == true)
				{
					cout<< "\n Escriba la fecha de nacimiento para ver si algun usuario esta cumpliendo hoy: "; cin>> valorS;
                    modificarCumple(inicio, valorS);
				}
				else
					cout << "\n\n Selecione primero la opcion 1" << endl;
				cout << "\n";
				system ("pause");
				break;
			
		}
	}while (op != 14);
	cout << "\n";
}
