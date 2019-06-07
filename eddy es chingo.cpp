#include <iostream>
#include <conio.h>
#include <string>
#include <locale.h>

using namespace std;

#include <iostream>
#include <conio.h>
#include <string>
#include <locale.h>

using namespace std;

class persona{ 
private: 
string nombre; 
int codigo; 
public: 
persona(string,int);
void mostrarpersona();
};
   
 
class empleado:public persona{ 
	private: 
		float pago; 
		int ventas; 
	public:
		empleado(string,int,float,int);
		void mostrarempleado();
		
}; 
 
class cliente : public persona{ 
	private: 
		string IFE; 
		int telefono; 
	public: 
		cliente(string,int,,int);
		void mostrarcliente();
}; 

persona::persona(string _nombre,int _codigo){
	nombre=_nombre;
	codigo=_codigo;
}

empleado::empleado(string _nombre,int _codigo,float _pago,int _ventas) : persona(_nombre,_codigo){
	pago=_pago;
	ventas=_ventas;
}

cliente::cliente(string _nombre,int _codigo,string _IFE,int _telefono) : persona(_nombre,_codigo){
	IFE=_IFE;
	telefono=_telefono;
}

void persona::mostrarpersona(string _nombre,int _codigo,float _pago,int _ventas) : persona(_nombre,_codigo){
	cout<<"Nombre: "<<nombre<<endl;
	cout<<"Codigo: "<<codigo<<endl;
}

void empleado::mostrarempleado(){
	mostrarpersona();
	cout<<"Paga: "<<pago<<endl;
	cout<<"Ventas: "<<ventas<<endl;
}

void cliente::mostrarcliente(){
	mostarpersona();
	cout<<"IFE: "<<IFE<<endl;
	cout<<"Telefono: "<<telefono<<endl;
}
//Falta especificar las funciones y como ordenarlas en el main
 
class pelicula{ 
	private: 
		char titulo[30]; 
		int cantidad; 
		float precio; 
	public: 
		void gettitulo(); 
		void settitulo(); 
		void getcantidad(); 
		void setcantidad(); 
		void getprecio(); 
		void setprecio(); 
		 
}; 


int main(){
	setlocale(LC_ALL, "");
	int opc, opc1, opc2, opc3;
	string contra="";
	cout<<"Introduce la contraseña: ";
	cin>>contra;
	if(contra=="Videoclub"){
		do{
			cout<<endl<<"1.CLIENTES"<<endl;
			cout<<"2.PELICULAS"<<endl;
			cout<<"3.EMPLEADO"<<endl;
			cout<<"4.REALIZAR RENTA O VENTA"<<endl;
			cout<<"5.SALIR"<<endl;
			cout<<endl<<"Opcion: "<<endl<<endl;
			opc=getche();
			switch(opc)
			{
				case'1':
					do{
						cout<<"1.Registrar"<<endl;
						cout<<"2.Consultar por nombre"<<endl;
						cout<<"3.Consultar por codigo de cliente"<<endl;
						cout<<"4.Modificar"<<endl;
						cout<<"5.Lista de clientes"<<endl;
						cout<<"6.Salir"<<endl;
						cout<<endl<<"Opcion: "<<endl<<endl;
						opc1=getche();
						cout<<endl<<endl;
						switch(opc1)
						{
							case'1':
								break;
							case'2':
								break;
							case'3':
								break;
							case'4':
								break;
							case'5':
								break;
							case'6':
								cout<<"Saliste de clientes"<<endl;
								break;
						}
					} while (opc1!='6');

	
					break;
				case'2':
					do{
						cout<<"1.Registrar"<<endl;
						cout<<"2.Consultar por nombre"<<endl;
						cout<<"3.Modificar"<<endl;
						cout<<"4.Reporte de peliculas rentadas"<<endl;
						cout<<"5.Reporte de peliculas vendidas"<<endl;
						cout<<"6.Reporte de peliculas disponibles"<<endl;
						cout<<"7.Salir"<<endl;
						cout<<endl<<"Opcion: "<<endl<<endl;
						opc2=getche();
						cout<<endl<<endl;
						switch(opc2)
						{
							case'1':
								break;
							case'2':
								break;
							case'3':
								break;
							case'4':
								break;
							case'5':
								break;
							case'6':
								break;
							case'7':
								cout<<"Saliste de peliculas"<<endl;
								break;		
						}
					} while (opc2!='7');
	
					break;
				case'3':
					do{
						cout<<"1.Registrar"<<endl;
						cout<<"2.Consultar por nombre"<<endl;
						cout<<"3.Consultar por codigo de empleado"<<endl;
						cout<<"4.Lista de empleados"<<endl;
						cout<<"5.Salir"<<endl;
						cout<<endl<<"Opcion: "<<endl<<endl;
						opc3=getche();
						cout<<endl<<endl;
						switch(opc3)
						{
							case'1':
								break;
							case'2':
								break;
							case'3':
								break;
							case'4':
								break;
							case'5':
								cout<<"Saliste de empleados"<<endl;
								break;
						}
					} while (opc3!='5');
				
					break;
				case'4':
					break;
				case'5':
					cout<<endl<<"Adios"<<endl;
					break;
				default:
					cout<<endl<<"Error"<<endl;
					break;
			}
			getch();
		} while(opc!='5');
	}
	else
	cout<<"La contraseña es incorrecta"<<endl;
	return 0;	
}


