#include <iostream>

using namespace std;

class persona{
private:
char nombre[20];
int codigo;
public:
void getnom();
void setnom();
void getcod();
void setcod();       
};

class empleado : public persona{
	private:
		float pago;
		int ventas;
	public:
		void getpago();
		void setpago();
		void getventas();
		void setventas();
};

class cliente : public persona{
	private:
		float pago;
		int ventas;
	public:
		void getpago();
		void setpago();
		void getventas();
		void setventas();
};

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



