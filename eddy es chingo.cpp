#include <iostream>
#include <conio.h>
#include <string>
#include <locale.h>
//hols
using namespace std;

typedef struct nodo *Tlista;

struct nodo{
   string _nombre,_codigo,_RFC,_domicilio,_IFE;
   int _telefono;
   struct nodo *sgte;
};

void insertarInicio(Tlista &lista,string nombre,string codigo,string RFC,string domicilio,string IFE,int telefono)
{
    Tlista q; 
  q = new(struct nodo);
  q->_nombre = nombre;
  q->_codigo = codigo;
  q->_RFC = RFC;
  q->_domicilio = domicilio;
  q->_IFE = IFE;
  q->_telefono = telefono;
  q->sgte = lista;
  lista = q;
}

void reportarLista(Tlista lista)
{
    int i = 0;
    
    while(lista != NULL)
    {
        cout <<' '<< i+1 <<") Nombre: " << lista->_nombre<<endl;
        cout<<"    Codigo: "<<lista->_codigo<<endl;
        cout<<"    Telefono: "<<lista->_telefono<<endl;
        cout<<"    RFC: "<<lista->_RFC<<endl;
        cout<<"    Domicilio: "<<lista->_domicilio<<endl;
        cout<<"    IFE: "<<lista->_IFE<<endl;
        lista = lista->sgte;
        i++;
    }
}


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
		float precior;
		float preciov;
		string director;
		string genero;
	public:
		pelicula(string,string,int,float, float, string, string);
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
float setprecior();
float setpreciov();
string director();
string genero();


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

pelicula::pelicula(string _titulo,string _pcodigo,int _cantidad,float _precior,float _preciov,string _director,string _genero){
	titulo=_titulo;
	pcodigo=_pcodigo;
	cantidad=_cantidad;
	precior=_precior;
	preciov=_preciov;
	director=_director;
	genero=_genero;
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
	cout<<"Precio de renta: $"<<precior<<endl;
	cout<<"Precio de venta: $"<<preciov<<endl;
	cout<<"Director: "<<director<<endl;
	cout<<"Genero: "<<genero<<endl;
}

string setRFC(){
	string _RFC;
	cout<<"Introduce RFC: ";
	cin>> _RFC;
	return _RFC;
}

string setdomicilio(){
	string _domicilio;
	cout<<"Introduce domicilio: ";
	cin>>_domicilio;
	return _domicilio;
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

float setprecior(){
	int _precior;
	cout<<"Introduce precio de renta: ";
	cin>>_precior;
	return _precior;
}

float setpreciov(){
	int _preciov;
	cout<<"Introduce precio de venta: ";
	cin>>_preciov;
	return _preciov;
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




int main(){
	setlocale(LC_ALL, "");
	int opc, opc1, opc2, opc3, opc4,_telefono,_cantidad,i;
	float _precior,_preciov;
	Tlista lista = NULL;
	string contra="",_nombre,_codigo,_RFC,_domicilio,_IFE,_titulo,_pcodigo,_genero,_director;
	cout<<"Introduce la contraseña: ";
	cin>>contra;
	if(contra == "Videoclub"){
		do{
			cout<<endl<<"1.CLIENTES"<<endl;
			cout<<"2.PELICULAS"<<endl;
			cout<<"3.EMPLEADO"<<endl;
			cout<<"4.REALIZAR RENTA O VENTA"<<endl;
			cout<<"5.SALIR"<<endl;
			cout<<endl<<"Opcion: ";
			opc=getche();
			cout<<endl;
			switch(opc)
			{
				case'1':
					do{
						cout<<endl<<"1.Registrar cliente"<<endl;
						cout<<"2.Consultar por nombre"<<endl;
						cout<<"3.Consultar por codigo de cliente"<<endl;
						cout<<"4.Modificar"<<endl;
						cout<<"5.Lista de clientes"<<endl;
						cout<<"6.Salir"<<endl;
						cout<<endl<<"Opcion: ";
						opc1=getche();
						cout<<endl<<endl;
						switch(opc1)
						{
							case'1':
								cout<<endl<<"	Registrar cliente"<<endl<<endl;
								_nombre=setnombre();
								_codigo=setcodigo();
								_RFC=setRFC();
								_domicilio=setdomicilio();
								_IFE=setIFE();
								_telefono=settelefono();
								insertarInicio(lista,_nombre,_codigo,_RFC,_domicilio,_IFE,_telefono);
								cout<<endl<<"	Cliente registrado con exito"<<endl;
								
								break;
							case'2':
								cout<<endl<<"	Consultar por nombre"<<endl;
								break;
							case'3':
								cout<<endl<<"	Consultar por código de cliente"<<endl;
								break;
							case'4':
								cout<<endl<<"	Modificar"<<endl;
								break;
							case'5':
								cout<<endl<<"	Lista de clientes"<<endl;
								cout<<endl<<"Lista de clientes"<<endl;
								cout << "\n\n MOSTRANDO LISTA\n\n";
                				reportarLista(lista);
								break;
							case'6':
								cout<<endl<<"	Saliste de clientes"<<endl;
								break;
						}
					} while (opc1!='6');
	
					break;
				case'2':
					do{
						cout<<endl<<"1.Registrar pelicula"<<endl;
						cout<<"2.Consultar por nombre"<<endl;
						cout<<"3.Modificar"<<endl;
						cout<<"4.Reporte de peliculas rentadas"<<endl;
						cout<<"5.Reporte de peliculas vendidas"<<endl;
						cout<<"6.Reporte de peliculas disponibles"<<endl;
						cout<<"7.Salir"<<endl;
						cout<<endl<<"Opcion: ";
						opc2=getche();
						cout<<endl<<endl;
						switch(opc2)
						{
							case'1':
								cout<<endl<<"	Registrar pelicula"<<endl<<endl;
								_titulo = settitulo();
								_pcodigo = setpcodigo();
								_cantidad = setcantidad();
								_precior = setprecior();
								_preciov = setpreciov();
								_director = setdirector();
								_genero = setgenero();
								cout<<endl<<"	Pelicula registrada con exito"<<endl;
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
						cout<<endl<<"1.Registrar empleado"<<endl;
						cout<<"2.Consultar por nombre"<<endl;
						cout<<"3.Consultar por codigo de empleado"<<endl;
						cout<<"4.Lista de empleados"<<endl;
						cout<<"5.Salir"<<endl;
						cout<<endl<<"Opcion: ";
						opc3=getche();
						cout<<endl<<endl;
						switch(opc3)
						{
							case'1':
								cout<<endl<<"	Registrar empleado"<<endl;
								_nombre=setnombre();
								_codigo=setcodigo();
								_RFC=setRFC();
								_domicilio=setdomicilio();
								cout<<endl<<"	Empleado registrado con exito"<<endl;
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
					do{
						cout<<endl<<"1.Renta"<<endl;
						cout<<"2.Venta"<<endl;
						cout<<"3.Salir"<<endl;
						cout<<endl<<"Opcion: ";
						cin>>opc4;
						switch(opc4){
							case 1:
								cout<<endl<<"	Renta"<<endl;
								break;
							
							case 2:
								cout<<endl<<"	Venta"<<endl;
								break;
						}
					}while(opc4=!3);

					
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


