#include <iostream>
#include <conio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <fstream>
#include <cstdlib>

using namespace std;

typedef struct nodo *Tlista;

struct nodo{
   string _nombre,_codigo,_RFC,_domicilio,_IFE,_director,_genero;
   int _telefono,_cantidad;
   float _precior, _preciov;
   struct nodo *sgte;
};

int check(Tlista lista,string codigo)
{
    Tlista q = lista;
    char palabra1[50],palabra2[50];
    int i = 1, band = 0 ,check=1;
    strcpy(palabra2,codigo.c_str());
    while(q!=NULL)
    {
    	strcpy(palabra1,q->_codigo.c_str());
        if(strcmp(palabra1,palabra2) == 0)
        {
        if(q->_cantidad>3){
        	cout<<endl<<"El usuario tiene rentada mas de 3 peliculas";
        	return check;
		}
		else{
        check=0;
    	band = 1;
    	}
        }
        q = q->sgte;
        i++;
    }

    if(band==0)
        cout<<"\n\n Codigo no encontrado..!"<< endl;
    return check;
}

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
  q->_cantidad = 0;
  q->sgte = lista;
  lista = q;
}

void reportarLista(Tlista lista)
{
    int i = 0;
    
    while(lista != NULL)
    {
        cout <<' '<< i+1 <<")Nombre: " << lista->_nombre<<endl;
        cout<<"    Codigo: "<<lista->_codigo<<endl;
        cout<<"    Telefono: "<<lista->_telefono<<endl;
        cout<<"    RFC: "<<lista->_RFC<<endl;
        cout<<"    Domicilio: "<<lista->_domicilio<<endl;
        cout<<"    IFE: "<<lista->_IFE<<endl;
        cout<<"    Pelis rentadas: "<<lista->_cantidad<<endl<<endl;
        lista = lista->sgte;
        i++;
    }
}

void buscarElementocodigo(Tlista lista,string codigo)
{
    Tlista q = lista;
    char palabra1[50],palabra2[50];
    int i = 1, band = 0;
    strcpy(palabra2,codigo.c_str());
    while(q!=NULL)
    {
    	strcpy(palabra1,q->_codigo.c_str());
        if(strcmp(palabra1,palabra2) == 0)
        {
        cout<<"    Nombre: " << q->_nombre<<endl;
        cout<<"    Codigo: "<<q->_codigo<<endl;
        cout<<"    Telefono: "<<q->_telefono<<endl;
        cout<<"    RFC: "<<q->_RFC<<endl;
        cout<<"    Domicilio: "<<q->_domicilio<<endl;
        cout<<"    IFE: "<<q->_IFE<<endl;
        cout<<"    Pelis rentadas: "<<q->_cantidad<<endl<<endl;
    	band = 1;
        }
        q = q->sgte;
        i++;
    }

    if(band==0)
        cout<<"\n\n Codigo no encontrado..!"<< endl;
}



void buscarElementonombre(Tlista lista,string nombre)
{
    Tlista q = lista;
	int i = 1, band = 0;
	char palabra1[50],palabra2[50];
	strcpy(palabra2,nombre.c_str());
    while(q!=NULL)
    {
        strcpy(palabra1,q->_nombre.c_str());
		if(strcmp(palabra1,palabra2)==0)
        {
        cout<<"    Nombre: " << q->_nombre<<endl;
        cout<<"    Codigo: "<<q->_codigo<<endl;
        cout<<"    Telefono: "<<q->_telefono<<endl;
        cout<<"    RFC: "<<q->_RFC<<endl;
        cout<<"    Domicilio: "<<q->_domicilio<<endl;
        cout<<"    IFE: "<<q->_IFE<<endl;
        cout<<"    Pelis rentadas: "<<q->_cantidad<<endl<<endl;
    	band = 1;
        }
        q = q->sgte;
        i++;
    }

    if(band==0)
        cout<<"\n\n Nombre no encontrado..!"<< endl;
}

void eliminarCliente(Tlista &lista,string codigo)
{
    Tlista q, ant;
    q = lista;
    char palabra1[50],palabra2[50];
	strcpy(palabra2,codigo.c_str());
    
    if(lista!=NULL)
    {
        while(q!=NULL)
        {
            strcpy(palabra1,q->_codigo.c_str());
			if(strcmp(palabra1,palabra2)==0)
            {
                if(q==lista)
                    lista = lista->sgte;
                else
                    ant->sgte = q->sgte;
            
                delete(q);
                return;
            }
            ant = q;
            q = q->sgte;
        }
    }
    else
        cout<<" Lista vacia..!";
}

void modificarCliente(Tlista &lista,string codigo)
{
    Tlista q;
    q = lista;
    char palabra1[50],palabra2[50];
	strcpy(palabra2,codigo.c_str());
    string nombre,pcodigo,RFC,domicilio,IFE;
    int telefono;
    if(lista!=NULL)
    {
        while(q!=NULL)
        {
            strcpy(palabra1,q->_codigo.c_str());
			if(strcmp(palabra1,palabra2)==0)
            {
				cin.ignore();
				cout<<"Introduce Nombre: ";
				getline(cin,nombre);
				q->_nombre = nombre;
				cin.ignore();
				cout<<"Introduce Codigo: ";
				getline(cin,pcodigo);
				q->_codigo = codigo;
				cin.ignore();
				cout<<"Introduce RFC: ";
				getline(cin,RFC);
				q->_RFC = RFC;
				cin.ignore();
				cout<<"Introduce Domicilio: ";
				getline(cin,domicilio);
				q->_domicilio = domicilio;
				cin.ignore();
				cout<<"Introduce IFE: ";
				getline(cin,IFE);
				q->_IFE = IFE;
				cin.ignore();
				cout<<"Introduce Telefono: ";
				cin>>telefono;
				q->_telefono = telefono; 
				return;
            }
            q = q->sgte;
        }
    }
    else
        cout<<" Lista vacia..!";
}


//----------------------------------------------------------------
typedef struct nodo1 *Tlista1;

struct nodo1{ 
   string _nombre,_codigo,_RFC,_domicilio; 
   float _pago, _comision; 
   struct nodo1 *sgte; 
}; 
 

int check1(Tlista1 lista1,string codigo)
{
    Tlista1 q = lista1;
    char palabra1[50],palabra2[50];
    int i = 1, band = 0 ,check=1;
    strcpy(palabra2,codigo.c_str());
    while(q!=NULL)
    {
    	strcpy(palabra1,q->_codigo.c_str());
        if(strcmp(palabra1,palabra2) == 0)
        {
        check=0;
    	band = 1;
        }
        q = q->sgte;
        i++;
    }

    if(band==0)
        cout<<"\n\n Codigo no encontrado..!"<< endl;
    return check;
}

void insertarInicio1(Tlista1 &lista1,string nombre,string codigo,string RFC,string domicilio)
{
    Tlista1 q; 
  q = new(struct nodo1);
  q->_nombre = nombre;
  q->_codigo = codigo;
  q->_RFC = RFC;
  q->_domicilio = domicilio;
  q->_pago = 25000.00;
  q->_comision=0;
  q->sgte = lista1;
  lista1 = q;
}

void reportarLista1(Tlista1 lista1)
{
    int i = 0;
    
    while(lista1 != NULL)
    {
        cout <<' '<< i+1 <<")Nombre: " << lista1->_nombre<<endl;
        cout<<"    Codigo: "<<lista1->_codigo<<endl;
        cout<<"    RFC: "<<lista1->_RFC<<endl;
        cout<<"    Domicilio: "<<lista1->_domicilio<<endl;
        cout<<"    Pago: $"<<lista1->_pago<<endl;
        cout<<"    Pago generado por comisiones: $"<<lista1->_comision<<endl<<endl;
        lista1 = lista1->sgte;
        i++;
    }
}

void buscarElementocodigo1(Tlista1 lista1,string codigo)
{
    Tlista1 q = lista1;
    int i = 1, band = 0;
	char palabra1[50],palabra2[50];
	strcpy(palabra2,codigo.c_str());
    while(q!=NULL)
    {
        strcpy(palabra1,q->_codigo.c_str());
		if(strcmp(palabra1,palabra2)==0)
        {
        cout<<"    Nombre: " << q->_nombre<<endl;
        cout<<"    Codigo: "<<q->_codigo<<endl;
        cout<<"    RFC: "<<q->_RFC<<endl;
        cout<<"    Domicilio: "<<q->_domicilio<<endl;
        cout<<"    Pago: $"<<q->_pago<<endl;
        cout<<"    Pago generado por comisiones: $"<<q->_comision<<endl<<endl;
    	band = 1;
        }
        q = q->sgte;
        i++;
    }

    if(band==0)
        cout<<"\n\n Codigo no encontrado..!"<< endl;
}


void buscarElementonombre1(Tlista1 lista1,string nombre)
{
    Tlista1 q = lista1;
    int i = 1, band = 0;
	char palabra1[50],palabra2[50];
	strcpy(palabra2,nombre.c_str());
    while(q!=NULL)
    {
        strcpy(palabra1,q->_nombre.c_str());
		if(strcmp(palabra1,palabra2)==0)
        {
        cout<<"    Nombre: " <<q->_nombre<<endl;
        cout<<"    Codigo: "<<q->_codigo<<endl; 
        cout<<"    RFC: "<<q->_RFC<<endl; 
        cout<<"    Domicilio: "<<q->_domicilio<<endl; 
        cout<<"    Pago: $"<<q->_pago<<endl; 
        cout<<"    Pago generado por comisiones: $"<<q->_comision<<endl<<endl; 
    	band = 1; 
        } 
        q = q->sgte; 
        i++;
    }

    if(band==0)
        cout<<"\n\n Numero no encontrado..!"<< endl;
}

//---------------------------------------------------------------------
typedef struct nodo2 *Tlista2;

struct nodo2{
   string _titulo,_pcodigo,_director,_genero, _codigo;
   int _cantidad;
   float _precior, _preciov;
   struct nodo2 *sgte;
};

int check2(Tlista2 lista2,string codigo)
{
    Tlista2 q = lista2;
    char palabra1[50],palabra2[50];
    int i = 1, band = 0 ,check=1;
    strcpy(palabra2,codigo.c_str());
    while(q!=NULL)
    {
    	strcpy(palabra1,q->_pcodigo.c_str());
        if(strcmp(palabra1,palabra2) == 0)
        {
        if(q->_cantidad<=0){
        	cout<<endl<<"Pelicula no disponible";
        	return check;
		}
		else{
        check=0;
    	band = 1;
    	}
        }
        q = q->sgte;
        i++;
    }

    if(band==0)
        cout<<"\n\n Codigo no encontrado..!"<< endl;
    return check;
}

void insertarInicio(Tlista2 &lista2,string titulo,string pcodigo,string director,string genero,int cantidad,float precior,float preciov)
{
    Tlista2 q; 
  q = new(struct nodo2);
  q->_titulo = titulo;
  q->_pcodigo = pcodigo;
  q->_director = director;
  q->_genero = genero;
  q->_cantidad = cantidad;
  q->_precior = precior;
  q->_preciov = preciov;
  q->sgte = lista2;
  lista2 = q;
}

void reportarLista2(Tlista2 lista2)
{
    int i = 0;
    
    while(lista2 != NULL)
    {
        cout <<' '<< i+1 <<")Titulo: " << lista2->_titulo<<endl;
        cout<<"    Codigo: "<<lista2->_pcodigo<<endl;
        cout<<"    Director: "<<lista2->_director<<endl;
        cout<<"    Genero: "<<lista2->_genero<<endl;
        cout<<"    Cantidad: "<<lista2->_cantidad<<endl;
        cout<<"    Precio de renta: $"<<lista2->_precior<<endl;
 		cout<<"    Precio de venta: $"<<lista2->_preciov<<endl<<endl;
        lista2 = lista2->sgte;
        i++;
    }
}

void buscarElementonombre2(Tlista2 lista2,string titulo)
{
    Tlista2 q = lista2;
    int i = 1, band = 0;
	char palabra1[50],palabra2[50];
	strcpy(palabra2,titulo.c_str());
    while(q!=NULL)
    {
        strcpy(palabra1,q->_titulo.c_str());
		if(strcmp(palabra1,palabra2)==0)
        {
        cout<<"    Titulo: " << q->_titulo<<endl;
        cout<<"    Codigo: "<<q->_pcodigo<<endl;
        cout<<"    Director: "<<q->_director<<endl;
        cout<<"    Genero: "<<q->_genero<<endl;
        cout<<"    Cantidad: "<<q->_cantidad<<endl;
        cout<<"    Precio de renta: $"<<q->_precior<<endl;
 		cout<<"    Precio de venta: $"<<q->_preciov<<endl<<endl;
    	band = 1;
        }
        q = q->sgte;
        i++;
    }

    if(band==0)
        cout<<"\n\n Titulo no encontrado..!"<< endl;
}

void modificarPelicula(Tlista2 &lista2, string pcodigo)
{
    Tlista2 q;
    q = lista2;
    char palabra1[50],palabra2[50];
	strcpy(palabra2,pcodigo.c_str());
    string titulo,codigo,director,genero;
    int cantidad;
    float precior, preciov;
    if(lista2!=NULL)
    {
        while(q!=NULL)
        {
            strcpy(palabra1,q->_pcodigo.c_str());
			if(strcmp(palabra1,palabra2)==0)
            {
				cin.ignore();
				cout<<"Introduce Titulo: ";
				getline(cin,titulo);
				q->_titulo = titulo;
				cin.ignore();
				cout<<"Introduce Codigo: ";
				getline(cin,codigo);
				q->_pcodigo = codigo;
				cin.ignore();
				cout<<"Introduce Director: ";
				getline(cin,director);
				q->_director = director;
				cin.ignore();
				cout<<"Introduce Genero: ";
				getline(cin,genero);
				q->_genero = genero;
				cin.ignore();
				cout<<"Introduce cantidad: ";
				cin>>cantidad;
				cout<<endl;
				q->_cantidad = cantidad;
				cin.ignore();
				cout<<"Introduce precio renta: ";
				cin>>precior;
				cout<<endl;
				q->_precior = precior; 
				cout<<"Introduce precio venta: ";
				cin>>preciov;
				cout<<endl;
				q->_preciov = preciov;
				return;
            }
            q = q->sgte;
        }
    }
    else
        cout<<" Lista vacia..!";
}

void costos(Tlista2 &lista2,string pcodigo,float&prenta,float&pventa)
{
    Tlista2 q;
    q = lista2;
    char palabra1[50],palabra2[50];
	strcpy(palabra2,pcodigo.c_str());
    if(lista2!=NULL)
    {
        while(q!=NULL)
        {
            strcpy(palabra1,q->_pcodigo.c_str());
			if(strcmp(palabra1,palabra2)==0)
            {
				prenta=q->_precior;
				pventa=q->_preciov;
				return;
            }
            q = q->sgte;
        }
    }
}


void gettitulo(Tlista2 &lista2,string pcodigo)
{
	Tlista2 q;
    q = lista2;
    char palabra1[50],palabra2[50];
	strcpy(palabra2,pcodigo.c_str());
    if(lista2!=NULL)
    {
        while(q!=NULL)
        {
            strcpy(palabra1,q->_pcodigo.c_str());
			if(strcmp(palabra1,palabra2)==0)
            {
				cout<<"Titulo: "<<q->_titulo;
				return;
            }
            q = q->sgte;
        }
    }
}

void eliminarPelicula(Tlista2 &lista2,string pcodigo)
{
    Tlista2 q, ant;
    q = lista2;
    char palabra1[50],palabra2[50];
	strcpy(palabra2,pcodigo.c_str());
    
    if(lista2!=NULL)
    {
        while(q!=NULL)
        {
            strcpy(palabra1,q->_pcodigo.c_str());
			if(strcmp(palabra1,palabra2)==0)
            {
                if(q==lista2)
                    lista2 = lista2->sgte;
                else
                    ant->sgte = q->sgte;
            
                delete(q);
                return;
            }
            ant = q;
            q = q->sgte;
        }
    }
    else
        cout<<" Lista vacia..!";
}

//---------------------------------------------------------------------------

typedef struct nodo3 *Tlista3;

struct nodo3{
   string _titulo,_pcodigo,_director,_genero, _codigo;
   int _cantidad;
   float _precior, _preciov;
   struct nodo3 *sgte;
};

void rentaPelicula(Tlista2 &lista2,Tlista3 &lista3, string pcodigo)
{
    Tlista2 q;
    q = lista2;
    Tlista3 p;
    p = lista3;
    char palabra1[50],palabra2[50];
	strcpy(palabra2,pcodigo.c_str());
    int cantidad;
    float precior, preciov;
    if(lista2!=NULL)
    {
        while(q!=NULL)
        {
            strcpy(palabra1,q->_pcodigo.c_str());
			if(strcmp(palabra1,palabra2)==0)
            {

				q->_cantidad = q->_cantidad-1;
				p = new(struct nodo3);
				p->_titulo = q->_titulo;
				p->_pcodigo = q->_pcodigo;
				p->_director = q->_director;
				p->_genero = q->_genero;
				p->_precior = q->_precior;
				p->_preciov = q->_preciov;
				p->sgte = lista3;
				lista3 = p;
				return;
            }
            q = q->sgte;
        }
    }
}

void reportarLista3(Tlista3 lista3)
{
    int i = 0;
    
    while(lista3 != NULL)
    {
        cout <<' '<< i+1 <<")Titulo: " << lista3->_titulo<<endl;
        cout<<"    Codigo: "<<lista3->_pcodigo<<endl;
        cout<<"    Director: "<<lista3->_director<<endl;
        cout<<"    Genero: "<<lista3->_genero<<endl;
        cout<<"    Precio de renta: $"<<lista3->_precior<<endl;
 		cout<<"    Precio de venta: $"<<lista3->_preciov<<endl<<endl;
        lista3 = lista3->sgte;
        i++;
    }
}

//---------------------------------------------------------------------------

typedef struct nodo4 *Tlista4;

struct nodo4{
   string _titulo,_pcodigo,_director,_genero, _codigo;
   int _cantidad;
   float _precior, _preciov;
   struct nodo4 *sgte;
};

void ventaPelicula(Tlista2 &lista2,Tlista4 &lista4, string pcodigo)
{
    Tlista2 q;
    q = lista2;
    Tlista4 p;
    p = lista4;
    char palabra1[50],palabra2[50];
	strcpy(palabra2,pcodigo.c_str());
    int cantidad;
    float precior, preciov;
    if(lista2!=NULL)
    {
        while(q!=NULL)
        {
            strcpy(palabra1,q->_pcodigo.c_str());
			if(strcmp(palabra1,palabra2)==0)
            {

				q->_cantidad = q->_cantidad-1;
				p = new(struct nodo4);
				p->_titulo = q->_titulo;
				p->_pcodigo = q->_pcodigo;
				p->_director = q->_director;
				p->_genero = q->_genero;
				p->_precior = q->_precior;
				p->_preciov = q->_preciov;
				p->sgte = lista4;
				lista4 = p;
				return;
            }
            q = q->sgte;
        }
    }
}

void reportarLista4(Tlista4 lista4)
{
    int i = 0;
    
    while(lista4 != NULL)
    {
        cout <<' '<< i+1 <<")Titulo: " << lista4->_titulo<<endl;
        cout<<"    Codigo: "<<lista4->_pcodigo<<endl;
        cout<<"    Director: "<<lista4->_director<<endl;
        cout<<"    Genero: "<<lista4->_genero<<endl;
        cout<<"    Precio de renta: $"<<lista4->_precior<<endl;
 		cout<<"    Precio de venta: $"<<lista4->_preciov<<endl<<endl;
        lista4 = lista4->sgte;
        i++;
    }
}

void comision(Tlista1 &lista1,string codigo,float comision)
{
    Tlista1 q;
    q = lista1;
    char palabra1[50],palabra2[50];
	strcpy(palabra2,codigo.c_str());
    int telefono;
    if(lista1!=NULL)
    {
        while(q!=NULL)
        {
            strcpy(palabra1,q->_codigo.c_str());
			if(strcmp(palabra1,palabra2)==0) 
            { 
				q->_pago=q->_pago+(comision*0.03); 
				q->_comision=q->_comision+(comision*0.03); 
				return; 
            } 
            q = q->sgte; 
        }
    }
    else
        cout<<" Lista vacia..!";
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
	cin.ignore();
	cout<<"Introduce RFC: ";
	getline(cin,_RFC);
	return _RFC;
}

string setdomicilio(){
	string _domicilio;
	cin.ignore();
	cout<<"Introduce domicilio: ";
	getline(cin,_domicilio);
	return _domicilio;
}

string setnombre(){
	string _nombre;
	cin.ignore();
	cout<<"Introduce nombre: ";
	getline(cin,_nombre);
	return _nombre;
}

string setcodigo(){
	string _codigo;
	cin.ignore();
	cout<<"Introduce codigo: ";
	getline(cin,_codigo);
	return _codigo;
}

string setcodigom(){
	string _codigo;
	cin.ignore();
	cout<<endl<<endl<<"Introduce codigo de la pelicula a modificar: ";
	getline(cin,_codigo);
	return _codigo;
}

string setIFE(){
	string _IFE;
	cin.ignore();
	cout<<"Introduce IFE: ";
	getline(cin,_IFE);
	return _IFE;
}

string setpcodigo(){
	string _pcodigo;
	cin.ignore();
	cout<<"Introduce codigo: ";
	getline(cin,_pcodigo);
	return _pcodigo;
}

string settitulo(){
	string _titulo;
	cin.ignore();
	cout<<"Introduce Titulo: ";
	getline(cin,_titulo);
	return _titulo;
}

int setcantidad(){
	int _cantidad;
	cout<<"\n";
	cout<<"Introduce cantidad de copias: ";
	cin>>_cantidad;
	return _cantidad;
}

int settelefono(){
	int _telefono;
	cout<<"\n";
	cout<<"Introduce telefono: ";
	cin>>_telefono;
	return _telefono;
}

float setprecior(){
	int _precior;
	cout<<"\n";
	cout<<"Introduce precio de renta: ";
	cin>>_precior;
	return _precior;
}

float setpreciov(){
	int _preciov;
	cout<<"\n";
	cout<<"Introduce precio de venta: ";
	cin>>_preciov;
	cout<<endl;
	return _preciov;
}

string setgenero(){
	string _genero;
	cin.ignore();
	cout<<"Introduce el genero de la pelicula: ";
	getline(cin,_genero);
	return _genero;	
}

string setdirector(){
	string _director;
	cin.ignore();
	cout<<"Introduce el director de la pelicula: ";
	getline(cin,_director);
	return _director;
}


int main(){
	setlocale(LC_ALL, "");
	int opc, opc1, opc2, opc3, opc4,_telefono,_cantidad,i,_check,con;
	float _precior=0,_preciov=0;
	Tlista lista = NULL;
	Tlista1 lista1 = NULL;
	Tlista2 lista2 = NULL;
	Tlista3 lista3 = NULL;
	Tlista4 lista4 = NULL;
	string contra="",_nombre,_codigo,_RFC,_domicilio,_IFE,_titulo,_pcodigo,_genero,_director,_empleado,_cliente,_pelicula;
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
								_nombre=setnombre();
				                buscarElementonombre(lista, _nombre);
								break;
							case'3':
								cout<<endl<<"	Consultar por código de cliente"<<endl;
								_codigo=setcodigo();
				                buscarElementocodigo(lista, _codigo);
								break;
							case'4':
								cout<<endl<<"	Modificar"<<endl;
								do{
									cout<<endl<<"1.Modificar"<<endl;
									cout<<"2.Eliminar"<<endl;
									cout<<"3.Salir"<<endl;
									cout<<"Opcion: ";
									opc2=getche();
									switch(opc2){
										case '1':
											cout<<endl<<"	Introduce el codigo del cliente"<<endl;
											_codigo=setcodigo();
							          		modificarCliente(lista, _codigo);
											break;
										case '2':
											cout<<endl<<"	Introduce el codigo del cliente"<<endl;
											_codigo=setcodigo();
						            		eliminarCliente(lista, _codigo);
											break;
										
										case '3':
											cout<<endl<<"	Saliste de modificar"<<endl;
											break;
									}
								}while(opc2!='3');
								
							case'5':
								cout<<endl<<"	Lista de clientes"<<endl;
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
								insertarInicio(lista2,_titulo,_pcodigo,_director,_genero,_cantidad,_precior,_preciov);
								cout<<endl<<"	Pelicula registrada con exito"<<endl;
								break;
							case'2':
								cout<<endl<<"	Consultar por titulo"<<endl;
								_titulo=settitulo();
				                buscarElementonombre2(lista2, _titulo);
								break;
						
							case'3':
								cout<<endl<<"	Modificar"<<endl;
								do{
									cout<<endl<<"1.Modificar"<<endl;
									cout<<"2.Eliminar"<<endl;
									cout<<"3.Salir"<<endl;
									cout<<"Opcion: ";
									opc3=getche();
									switch(opc3){
									
										case '1':
											_codigo=setcodigom();
							                modificarPelicula(lista2, _codigo);
											break;
									
										case '2':
											_codigo=setcodigom();
											eliminarPelicula(lista2, _codigo);
											break;
										
										case '3':
											cout<<endl<<endl<<"	Saliste de modificar"<<endl;
											break;
									}
								}while(opc3!='3');
								
								break;
							case'4':
								cout<<endl<<"	Reporte de peliculas rentadas"<<endl;
								cout<< "\n\n MOSTRANDO LISTA\n\n";
                				reportarLista3(lista3);
								break;
							case'5':
								cout<<endl<<"	Reporte de peliculas vendidas"<<endl;
								cout<< "\n\n MOSTRANDO LISTA\n\n";
                				reportarLista4(lista4);
								break;
							case'6':
								cout<<endl<<"	Reporte de peliculas disponibles"<<endl;
								cout<< "\n\n MOSTRANDO LISTA\n\n";
                				reportarLista2(lista2);
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
								cout<<endl<<"	Registrar empleado"<<endl<<endl;
								_nombre=setnombre();
								_codigo=setcodigo();
								_RFC=setRFC();
								_domicilio=setdomicilio();
								insertarInicio1(lista1,_nombre,_codigo,_RFC,_domicilio);
								cout<<endl<<"	Empleado registrado con exito"<<endl;
								break;
							case'2':
								cout<<endl<<"	Consultar por nombre"<<endl;
								_nombre=setnombre();
				                buscarElementonombre1(lista1, _nombre);
								break;
							case'3':
								cout<<endl<<"	Consultar por codigo de empleado"<<endl;
								_codigo=setcodigo();
				                buscarElementocodigo1(lista1, _codigo);
								break;
							case'4':
								cout<<endl<<"	Lista de empleados"<<endl;
								cout<< "\n\n MOSTRANDO LISTA\n\n";
                				reportarLista1(lista1);
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
								cout<<"Ingresa el codigo del empleado"<<endl;
								_empleado=setcodigo();
								_check=check1(lista1, _empleado);
								if(_check==1)
								break;
								cout<<"Ingresa el codigo del cliente";
								_cliente=setcodigo();
								_check=check(lista, _cliente);
								if(_check==1)
								break;
								cout<<"Ingresa el codigo de la pelicula";
								_pelicula=setcodigo();
								_check=check2(lista2, _pelicula);
								if(_check==1)
								break;
								costos(lista2,_pelicula,_preciov,_precior);
								gettitulo(lista2,_pelicula);
								cout<<"\nPagar: $"<<_preciov<<endl;
								cout<<"1.-Confirmar "<<endl;
								cout<<"2.-Cancelar  "<<endl;
								cout<<endl<<"Opcion: ";
								cin>>con;
								if(con==1){
								rentaPelicula(lista2,lista3,_pelicula);
								comision(lista1,_empleado,_precior);
								}
								if(con=2)
								break;
							
							case 2:
								cout<<endl<<"	Venta"<<endl;
								cout<<"Ingresa el codigo del empleado"<<endl;
								_empleado=setcodigo();
								_check=check1(lista1, _empleado);
								if(_check==1)
								break;
								cout<<"Ingresa el codigo del cliente";
								_cliente=setcodigo();
								_check=check(lista, _cliente);
								if(_check==1)
								break;
								cout<<"Ingresa el codigo de la pelicula";
								_pelicula=setcodigo();
								_check=check2(lista2, _pelicula);
								if(_check==1)
								break;
								costos(lista2,_pelicula,_preciov,_precior);
								gettitulo(lista2,_pelicula);
								cout<<"\nPagar: $"<<_preciov<<endl;
								cout<<"1.-Confirmar "<<endl;
								cout<<"2.-Cancelar  "<<endl;
								cout<<endl<<"Opcion: ";
								cin>>con;
								if(con==1){
								ventaPelicula(lista2,lista4,_pelicula);
								comision(lista1,_empleado,_preciov);
								}
								if(con=2)
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
