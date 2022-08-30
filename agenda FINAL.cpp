#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <cstdlib>
#include <windows.h>

using namespace std;
//_____________________________________________________________________________________________________________

struct persona{
	long identi;
	char nom[15];
	int t_f;
	int t_m;
	char dir[30], email[40];
};
int p=0;
persona pas[100];
//_____________________________________________________________________________________________________________

//prototipos
void menuprincipal();
void buscar();
void RegPersona();
void gotoxy(int x,int y);
void mostrarPersona();
void borrarPersona();
void modificarPersona();
//_____________________________________________________________________________________________________________

main(){
	system("color 1F");
	menuprincipal();
	
}
//_____________________________________________________________________________________________________________

void RegPersona(){
	bool resp= true;
	char r;
	

	do{
	    system("cls");
	    long id;
    	
	    gotoxy(3,3);cout<<"..:: REGISTRAR PERSONA ::..";
	    cout<<endl;

   gotoxy(5,6);cout<<"DOC IDENTIDAD: ";
   cin>>id;
   cout<<endl;

 	   int ban = 0;
 	   for (int i=1; i<=p; i++){
	        if (pas[i].identi == id){
		            ban++;
 	           break;
	        }
  	    }
 	   if (ban == 0){
 	       p++;
 	       fflush(stdin);
    	   pas[p].identi = id;
           fflush(stdin);
     	   cout<<"NOMBRE   : ";
			gets(pas[p].nom);
     	   fflush(stdin);
    	   cout<<"TELEFONO FIJO : ";
		   cin>>pas[p].t_f;
    	   fflush(stdin);
     	   cout<<"TELEFONO MOVIL: ";
			cin>>pas[p].t_m;
     	   fflush(stdin);
    	   cout<<"DIRECCION: ";
		   gets(pas[p].dir);
    	   fflush(stdin);
    	   cout<<"EMAIL: ";
		   gets(pas[p].email);

           printf("REGISTRADO CORRECTAMENTE...");
   		}
		   else{
           printf("ESTE CODIGO YA EXISTE");
           system("PAUSE");
           system("cls");
           RegPersona();
    	}
    	cout<<endl;
    	cout<<endl;

	  cout<<"Desea registrar otra persona?: "<<endl;
	  cout<<"SI=s y NO=n";cin>>r;
	  if(r =='n'){
	  	resp= false;
	  }else{
	  	resp= true;
	  }
	}while(resp== true );
	menuprincipal();

}

//_____________________________________________________________________________________________________________

void buscar(){
	
	bool ban=true;
	do{
	
	char resp;
	int i;
	long busca;

	system("cls");

	fflush(stdin);
	cout<<"\nBuscar contacto\nIngrese el documento de identidad contacto:";
	cin>>busca;

	for(i=0;i<=p;i++){
		if(pas[i].identi==busca){
			cout<<"\nNombre: "<< pas[i].nom;
			cout<<endl;
			cout<<"Telfono fijo: "<< pas[i].t_f;
			cout<<endl;
			cout<<"Telefono movil: "<< pas[i].t_m;
			cout<<endl;
			cout<<"Direccion: "<< pas[i].dir;
			cout<<endl;
			cout<<"E-mail: "<< pas[i].email;
			cout<<endl;
		}
	}
	cout<<"¿Dese buscar otra persona?\t SI=s | NO=n ";
	cout<<"Ingrese una opcion: ";
	cin>>resp;
	if(resp=='s'){
    	ban=true;
	}
	else{
		ban=false;
	}
}while(ban==true);

menuprincipal();

}
//_____________________________________________________________________________________________________________

void menuprincipal(){
	int opc;
    bool ban=true;
	do{
		system("cls");

    	gotoxy(4,4);cout<<"\tMENU\n";
		cout<<"\t[1].Agregar\n";
		cout<<"\t[2].Buscar\n";
		cout<<"\t[3].Ver todos los contactos\n";
		cout<<"\t[4].Borrar\n";
		cout<<"\t[5].Actualizar\n";
		cout<<"\t[6].Salir\n";
	
        cout<<"\tIngrese una opcion: ";
        cin>>opc;
        cout<<endl;
		switch(opc){
		case 1:{
				RegPersona();
			break;
		}

		case 2:{
			buscar();
			system("PAUSE");
			break;
		}

		case 3:{
			mostrarPersona();
			break;
		}
			
		case 4:{
				borrarPersona();
				break;
			}
			case 5:{
				modificarPersona();
			
				break;
			}
			case 6:{
					ban=false;
				break;
			}
		}
	}while(ban==true);


}
//_____________________________________________________________________________________________________________

void mostrarPersona(){
	bool ban=true;
	int op;
	do{
	
	system("cls");
	int y=6,x=4,ban=0;
	gotoxy(30,2);cout<<"..::  PERSONAS  ::..";
	gotoxy(0,2);cout<<"| Cedula   | Nombre | Tel. fijo | Tel. movil  | Direccion |    Email    |";
	for(int i=1;i<=p; i++){
	 ban++;
		x=0;
 	  gotoxy(x,y);cout<<pas[i].identi;
 	  	x+=12;
 	  gotoxy(x,y);cout<<pas[i].nom;
 	  	x+=12;
 	  gotoxy(x,y);cout<<pas[i].t_f;
 	  	x+=12;
 	  gotoxy(x,y);cout<<pas[i].t_m;
 	  	x+=12;
 	  gotoxy(x,y);cout<<pas[i].dir;
 	  	x+=12;
 	  gotoxy(x,y);cout<<pas[i].email;
 	   y+=2;
   }
   if(ban==0){
   			 gotoxy(10,10);cout<<"no hay personas registrados";
   }
   cout<<endl;
   cout<<endl;
   cout<<"Presione 0 para salir: ";
   cin>>op;
   if(op==0){
   	ban=false;
   }
   
}while(ban==false);
  // getch();
  menuprincipal();
}

//_____________________________________________________________________________________________________________
//_____________________________________________________________________________________________________________

void gotoxy(int x,int y){
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
 }

//_____________________________________________________________________________________________________________
void borrarPersona(){
	bool resp= true;
	char r;
	do{
		system("cls");
		int k,con=0;
    	cout<<"\n\t\tBORRAR PERSONA DE LA BASE DE DATOS\n\n";
	    cout<<"\tingrese id de la persona que desea eliminar: "; cin>>k;

		for (int i=1; i<=p; i++){
	        if(pas[i].identi==k){
	        	con++;
	        	if(i==p+1){
	        		p--;
	        	}
	        	else{
	        		pas[i]=pas[p];
	            	p--;

		        }
				cout<<"\n\n\n\t\t¡¡¡¡¡ELIMINADO CORRECTAMENTE!!!!\a";
	           	break;
    		}
		}
	    if (con==0){
	        cout<<"\n\n\tlo sentimos no se encontro ese numero de identificacion\a\n";
	    }

	  gotoxy(5,18);cout<<"Desea Eliminar otra persona?: ";cin>>r;
	  if(r =='n'){
	  	resp= false;
	  }else{
	  	resp= true;
	  }
	}while(resp== true );
menuprincipal();
}

void modificarPersona(){
	bool resp= true;
	char r;
	do{
		system("cls");
		int k,con=0;
    	cout<<"\n\tMODIFICAR PERSONA DE LA BASE DE DATOS\n\n";
	    cout<<"\tingrese id de la persona que desea modificar: "; cin>>k;

		for (int i=1; i<=p; i++){
	        if(pas[i].identi==k){
	        	con++;
	        	if(i==p+1){
	        		p--;
	        	}
	        	else{
	        		pas[i]=pas[p];
	            	p--;

		        }
	 	       p++;
	    	   pas[p].identi = k;
	           fflush(stdin);
	     	   
     	   cout<<"NOMBRE   : ";
			gets(pas[p].nom);
     	   fflush(stdin);
    	   cout<<"TELEFONO FIJO : ";
		   cin>>pas[p].t_f;
    	   fflush(stdin);
     	   cout<<"TELEFONO MOVIL: ";
			cin>>pas[p].t_m;
     	   fflush(stdin);
    	   cout<<"DIRECCION: ";
		   gets(pas[p].dir);
    	   fflush(stdin);
    	   cout<<"EMAIL: ";
		   gets(pas[p].email);
			   cout<<"\n\n\t\t¡¡¡¡¡MODIFICADO CORRECTAMENTE!!!!\a";
	           break;
    		}

		}
	    if (con==0){
	        cout<<"\n\n\tlo sentimos no se encontro ese numero de identificacion\a\n";
	    }

	  gotoxy(5,18);cout<<"Desea Modificar otra persona: ";cin>>r;
	  if(r =='n'){
	  	resp= false;
	  }else{
	  	resp= true;
	  }
	}while(resp== true );
menuprincipal();
}

//_____________________________________________________________________________________________________________

