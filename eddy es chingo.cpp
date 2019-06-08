#include <iostream>
#include <conio.h>
#include <string>
#include <locale.h>

using namespace std;

class persona{ 
	private: 
		string nombre; 
		string codigo;
		string RFC;
		string domicilio;
	public: 
		persona(string,string,string,string);
		void mostrarpersona();
		string setnombre();
		string setcodigo();
		string setRFC();
		string setdomicilio();
};
   
 
class empleado:public persona{ 
	private: 
		float pago; 
		int ventas; 
	public:
		empleado(string,string,string,string,float,int);
		void mostrarempleado();
		
}; 
 
class cliente : public persona{ 
	private: 
		string IFE; 
		int telefono; 
	public: 
		cliente(string,string,string,string,string,int);
		void mostrarcliente();
}; 

class pelicula{
	private:
		string titulo;
		string pcodigo;
		int cantidad;
		float precio;
	public:
		pelicula(string,string,int,float);
		void mostrarpelicula();
};

string setnombre();
string setcodigo();
string setRFC();
string setdomicilo();
string setIFE();
int settelefono();
string settitulo();
string setpcodigo();
int setcantidad();
float setprecio();

persona::persona(string _nombre, string _codigo, string _RFC, string _domicilio){
	nombre=_nombre;
	codigo=_codigo;
	RFC=_RFC;
	domicilio=_domicilio;
}

empleado::empleado(string _nombre,string _codigo, string _RFC, string _domicilio, float _pago,int _ventas) : persona(_nombre,_codigo,_RFC,_domicilio){
	pago=_pago;
	ventas=_ventas;
}

cliente::cliente(string _nombre,string _codigo,string _RFC, string _domicilio, string _IFE,int _telefono) : persona(_nombre,_codigo,_RFC,_domicilio){
	IFE=_IFE;
	telefono=_telefono;
}

pelicula::pelicula(string _titulo,string _pcodigo,int _cantidad,float _precio){
	titulo=_titulo;
	pcodigo=_pcodigo;
	cantidad=_cantidad;
	precio=_precio;
}

void persona::mostrarpersona(){
	cout<<"Nombre: "<<nombre<<endl;
	cout<<"Codigo: "<<codigo<<endl;
	cout<<"RFC: "<<RFC<<endl;
	cout<<"Domicilio: "<<domicilio<<endl;
}

void empleado::mostrarempleado(){
	mostrarpersona();
	cout<<"Paga: "<<pago<<endl;
	cout<<"Ventas: "<<ventas<<endl;
}

void cliente::mostrarcliente(){
	mostrarpersona();
	cout<<"IFE: "<<IFE<<endl;
	cout<<"Telefono: "<<telefono<<endl;
}

void pelicula::mostrarpelicula(){
	cout<<"Titulo: "<<titulo<<endl;
	cout<<"Codigo: "<<pcodigo<<endl;
	cout<<"Cantidad en tienda: "<<cantidad<<endl;
	cout<<"Precio de venta: "<<precio<<"$"<<endl;
}

string setnombre(){
	string _nombre;
	cout<<"Introduce nombre: ";
	cin>>_nombre;
	return _nombre;
}

string setcodigo(){
	string _codigo;
	cout<<"Introduce codigo: ";
	cin>>_codigo;
	return _codigo;
}

string setIFE(){
	string _IFE;
	cout<<"Introduce IFE: ";
	cin>>_IFE;
	return _IFE;
}

string setpcodigo(){
	string _pcodigo;
	cout<<"Introduce codigo: ";
	cin>>_pcodigo;
	return _pcodigo;
}

string settitulo(){
	string _titulo;
	cout<<"Introduce Titulo: ";
	cin>>_titulo;
	return _titulo;
}

int setcantidad(){
	int _cantidad;
	cout<<"Introduce cantidad de copias: ";
	cin>>_cantidad;
	return _cantidad;
}

int settelefono(){
	int _telefono;
	cout<<"Introduce telefono: ";
	cin>>_telefono;
	return _telefono;
}

float setprecio(){
	int _precio;
	cout<<"Introduce precio: ";
	cin>>_precio;
	return _precio;
}

string setgenero(){
	string _genero;
	cout<<"Introduce el genero de la pelicula: ";
	cin>>_genero;
	return _genero;	
}

string setdirector(){
	string _director;
	cout<<"Introduce el director de la pelicula: ";
	cin>>_director;
	return _director;
}

//Falta especificar las funciones y como ordenarlas en el main

int main(){
	setlocale(LC_ALL, "");
	int opc, opc1, opc2, opc3;
	string contra="";
	cout<<"Introduce la contraseña: ";
	cin>>contra;
	if(contra == "Videoclub"){
		do{
			cout<<endl<<"1.CLIENTES"<<endl;
			cout<<"2.PELICULAS"<<endl;
			cout<<"3.EMPLEADO"<<endl;
			cout<<"4.REALIZAR RENTA O VENTA"<<endl;
			cout<<"5.SALIR"<<endl;
			cout<<endl<<"Opcion: "<<endl<<endl;
			opc=getche();
			cout<<endl;
			switch(opc)
			{
				case'1':
					do{
						cout<<endl<<"1.Registrar"<<endl;
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
								cout<<endl<<"	Registrar cliente"<<endl;
								break;
							case'2':
								cout<<endl<<"	Consultar por nombre	"<<endl;
								break;
							case'3':
								cout<<endl<<"	Consultar por código de cliente		"<<endl;
								break;
							case'4':
								cout<<endl<<"	Modificar"<<endl;
								break;
							case'5':
								cout<<endl<<"	Lista de clientes"<<endl;
								break;
							case'6':
								cout<<endl<<"	Saliste de clientes"<<endl;
								break;
						}
					} while (opc1!='6');
	
					break;
				case'2':
					do{
						cout<<endl<<"1.Registrar"<<endl;
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
								cout<<endl<<"	Registrar"<<endl;
								break;
							case'2':
								cout<<endl<<"	Consultar por nombre"<<endl;
								break;
							case'3':
								cout<<endl<<"	Modificar"<<endl;
								break;
							case'4':
								cout<<endl<<"	Reporte de peliculas rentadas"<<endl;
								break;
							case'5':
								cout<<endl<<"	Reporte de peliculas vendidas"<<endl;
								break;
							case'6':
								cout<<endl<<"	Reporte de peliculas disponibles"<<endl;
								break;
							case'7':
								cout<<endl<<"	Saliste de peliculas"<<endl;
								break;		
						}
					} while (opc2!='7');
	
					break;
				case'3':
					do{
						cout<<endl<<"1.Registrar"<<endl;
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
								cout<<endl<<"	Registrar"<<endl;
								break;
							case'2':
								cout<<endl<<"	Consultar por nombre"<<endl;
								break;
							case'3':
								cout<<endl<<"	Consultar por codigo de empleado"<<endl;
								break;
							case'4':
								cout<<endl<<"	Lista de empleados"<<endl;
								break;
							case'5':
								cout<<endl<<"	Saliste de empleados"<<endl;
								break;
						}
					} while (opc3!='5');
				
					break;
				case'4':
					break;
				case'5':
					cout<<endl<<"	Adios"<<endl;
					break;
				default:
					cout<<endl<<"	Error"<<endl;
					break;
			}
			getch();
		} while(opc!='5');
	}
	else
	cout<<endl<<"	La contraseña es incorrecta"<<endl;
	return 0;
}


