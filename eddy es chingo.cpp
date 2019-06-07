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

<<<<<<< HEAD
int main(){
	do{
		cout<<endl<<"1.CLIENTES"<<endl;
		cout<<"2.PELICULAS"<<endl;
		cout<<"3.EMPLEADO"<<endl;
		cout<<"4.REALIZAR RENTA O VENTA"<<endl;
		cout<<"5.SALIR"<<endl;
		cout<<endl<<"Opcion: ";
		opc=getche();
		switch(opc)
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
				cout<<endl<<"Adios"<<endl;
				break;
			default:
				cout<<endl<<"Error"<<endl;
				break;
		}
		getch();
	} while(opc!='4');
	return 0;
	
}
=======
>>>>>>> master


