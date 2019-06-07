#include <iostream>
#include <conio.h>
#include <string>
#include <locale.h>

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


