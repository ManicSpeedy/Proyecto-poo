#include <iostream>

using namespace std;

class persona{
	private:
		string nombre;
		int codigo;
	public:
		string nombre
        {
            get { return nombre; }
            set { nombre = value; }
        }
        int codigo
        {
            get { return codigo; }
            set { nombre = value; }
        }
		
};

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
	} while(opc!='5');
	return 0;
	
}


