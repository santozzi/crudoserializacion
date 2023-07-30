#include <sstream>
#include <fstream>
#include <string>
#include <iostream>
#include <stdio.h>
using namespace std;

string encrypt_code(string pin);
string alfabeto(char car);
  struct usuario
    {
        string CBU;
        string nombre;
        string apellido;
        string pin;
        float balance;
    };

bool crear_archivo(string ruta, char delimitador, string encabezado[],int cant_campos){
   ofstream archivo(ruta);
   for(int i=0;i<cant_campos;i++){
    archivo << encabezado[i]<<delimitador;
   }
   
   archivo << endl;
   archivo.close();

   return false;
}
void add_line(string ruta, char delimitador,string linea[], int cant_col){
  fstream archivo_salida(ruta, ios::app);
  for(int i=0; i< cant_col-1;i++){
    archivo_salida << linea[i]<<delimitador;
    
  }
  archivo_salida << linea[cant_col-1];
  archivo_salida.close();
}
void add_user(string ruta, char delimitador,usuario nuevo){
  fstream archivo_salida(ruta, ios::app);
  
    archivo_salida << nuevo.CBU<<delimitador;
    archivo_salida << nuevo.nombre<<delimitador;
    archivo_salida << nuevo.apellido<<delimitador;
    archivo_salida << encrypt_code(nuevo.pin)<<delimitador;
    archivo_salida << nuevo.balance<< endl;
   
  archivo_salida.close();
}

usuario find(string ruta, char delimitador, string CBU){
  fstream archivo;
  archivo.open(ruta, ios::in);
  string linea;
 // getline(archivo,linea);
  usuario user_selected;
  bool esta = false;
  while(!esta && archivo.good()){
    getline(archivo,linea);
    string id,balance_str;

    getline(archivo,id,delimitador);
    if(id==CBU){
       user_selected.CBU = CBU;
       getline(archivo,user_selected.nombre,delimitador) ;
       getline(archivo,user_selected.apellido,delimitador) ;
       getline(archivo,user_selected.pin,delimitador) ;
       getline(archivo,balance_str,delimitador) ;
       user_selected.balance = stof(balance_str);
       esta = true;
       

    }

    
  }
  archivo.close();
  return user_selected;
}

void find_all(string ruta, char delimitador){
  fstream archivo;
  archivo.open(ruta, ios::in);
  string linea;
 // getline(archivo,linea);
  usuario user_selected;
cout << endl;
 string id,balance_str;
  while(archivo.good()){
    getline(archivo,linea);

    

    getline(archivo,user_selected.CBU,delimitador);
    getline(archivo,user_selected.nombre,delimitador) ;
    getline(archivo,user_selected.apellido,delimitador) ;
    getline(archivo,user_selected.pin,delimitador) ;
    getline(archivo,balance_str,delimitador) ;
    
    cout << "-----------------------------"<<endl;
    cout << "CBU: "<< user_selected.CBU<<endl;
    cout << "Nombre: "<< user_selected.nombre<<endl;
    cout << "Apellido: "<< user_selected.apellido<<endl;
    //pin no se deberia mostrar
    cout << "Pin: "<< user_selected.pin<<endl;
    cout << "Balance: "<< balance_str<<endl;
    cout << "-----------------------------"<<endl;
    cout<<endl;
    
  }


    getline(archivo,user_selected.CBU,delimitador);
    getline(archivo,user_selected.nombre,delimitador) ;
    getline(archivo,user_selected.apellido,delimitador) ;
    getline(archivo,user_selected.pin,delimitador) ;
    getline(archivo,balance_str,delimitador) ;
    
    cout << "-----------------------------"<<endl;
    cout << "CBU: "<< user_selected.CBU<<endl;
    cout << "Nombre: "<< user_selected.nombre<<endl;
    cout << "Apellido: "<< user_selected.apellido<<endl;
    //pin no se deberia mostrar
    cout << "Pin: "<< user_selected.pin<<endl;
    cout << "Balance: "<< balance_str<<endl;
    cout << "-----------------------------"<<endl;
    cout<<endl;
  archivo.close();

}
/*
usuario *find_all_users(string ruta, char delimitador){
  fstream archivo;
  archivo.open(ruta, ios::in);
  string linea;
 // getline(archivo,linea);
  usuario user_selected;
cout << endl;
 string id,balance_str;
  while(archivo.good()){
    getline(archivo,linea);

    

    getline(archivo,user_selected.CBU,delimitador);
    getline(archivo,user_selected.nombre,delimitador) ;
    getline(archivo,user_selected.apellido,delimitador) ;
    getline(archivo,user_selected.pin,delimitador) ;
    getline(archivo,balance_str,delimitador) ;
    
    cout << "-----------------------------"<<endl;
    cout << "CBU: "<< user_selected.CBU<<endl;
    cout << "Nombre: "<< user_selected.nombre<<endl;
    cout << "Apellido: "<< user_selected.apellido<<endl;
    //pin no se deberia mostrar
    cout << "Pin: "<< user_selected.pin<<endl;
    cout << "Balance: "<< balance_str<<endl;
    cout << "-----------------------------"<<endl;
    cout<<endl;
    
  }


    getline(archivo,user_selected.CBU,delimitador);
    getline(archivo,user_selected.nombre,delimitador) ;
    getline(archivo,user_selected.apellido,delimitador) ;
    getline(archivo,user_selected.pin,delimitador) ;
    getline(archivo,balance_str,delimitador) ;
    
    cout << "-----------------------------"<<endl;
    cout << "CBU: "<< user_selected.CBU<<endl;
    cout << "Nombre: "<< user_selected.nombre<<endl;
    cout << "Apellido: "<< user_selected.apellido<<endl;
    //pin no se deberia mostrar
    cout << "Pin: "<< user_selected.pin<<endl;
    cout << "Balance: "<< balance_str<<endl;
    cout << "-----------------------------"<<endl;
    cout<<endl;
  archivo.close();

}
*/

void update(string ruta, char delimitador, string CBU, usuario user_selected){
  fstream archivo_in;
  fstream archivo_out;
  archivo_in.open(ruta, ios::in);
  archivo_out.open("temp.csv", ios::out);
  string linea;

  getline(archivo_in,linea);
  archivo_out <<linea <<endl;
  
  
  while(archivo_in.good()){
    getline(archivo_in,linea);
    string id,nombre_str,apellido_str,pin_str,balance_str;
    stringstream stream(linea);

    getline(stream,id,delimitador);
    if(id==CBU){
       archivo_out << user_selected.CBU<<delimitador;
       archivo_out << user_selected.nombre<<delimitador;
       archivo_out << user_selected.apellido<<delimitador;
       archivo_out << user_selected.pin<<delimitador;
       archivo_out << user_selected.balance;
       archivo_out <<endl;
    }else{
   
       archivo_out <<linea<<endl; 
     }

        
  }

  archivo_in.close();
  archivo_out.close(); 
     // removing the existing file
    remove(ruta.c_str());
  
    // renaming the updated file with the existing file name
    rename("temp.csv", ruta.c_str());
}
void update(string ruta, char delimitador, string CBU, string user_selected[], int cant){
  fstream archivo_in;
  fstream archivo_out;
  archivo_in.open(ruta, ios::in);
  archivo_out.open("temp.csv", ios::out);
  string linea;

  getline(archivo_in,linea);
  archivo_out <<linea <<endl;
  
  
  while(archivo_in.good()){
    getline(archivo_in,linea);
    string id,nombre_str,apellido_str,pin_str,balance_str;
    stringstream stream(linea);

    getline(stream,id,delimitador);
    if(id==CBU){
       for(int i = 0 ;i<cant-1;i++){
        archivo_out << user_selected[i]<<delimitador;
       }
       
       archivo_out << user_selected[cant-1]<<endl;
 
    }else{
   
       archivo_out <<linea<<endl; 
     }

        
  }

  archivo_in.close();
  archivo_out.close(); 
     // removing the existing file
    remove(ruta.c_str());
  
    // renaming the updated file with the existing file name
    rename("temp.csv", ruta.c_str());
}
void remove_line(string ruta, char delimitador, string CBU){
  fstream archivo_in;
  fstream archivo_out;
  archivo_in.open(ruta, ios::in);
  archivo_out.open("temp.csv", ios::out);
  string linea;

  getline(archivo_in,linea);
  archivo_out <<linea;
  
  
  while(archivo_in.good()){
    getline(archivo_in,linea);
    string id,nombre_str,apellido_str,pin_str,balance_str;
    stringstream stream(linea);

    getline(stream,id,delimitador);
    if(id!=CBU){
       archivo_out <<linea<<endl; 
 
    }       
  }

  archivo_in.close();
  archivo_out.close(); 
     // removing the existing file
    remove(ruta.c_str());
  
    // renaming the updated file with the existing file name
    rename("temp.csv", ruta.c_str());
}

string encrypt_code(string pin){
  
  string encryted = "";
  for(int i = 0; i < 4;i++){
    encryted += alfabeto(pin[i]);
  }
  
  return encryted;
}
string alfabeto(char car){
  string letra;
  switch (car)
  {
  case '0': letra = "a";
    break;
  
  case '1': letra = "S";
    break;
  
  case '2': letra = "i";
    break;
  
  case '3': letra = "L";
    break;
  
  case '4': letra = "r";
    break;
  
  case '5': letra = "M";
    break;
  
  case '6': letra = "x";
    break;
  
  case '7': letra = "P";
    break;
  
  case '8': letra = "W";
    break;
  
  case '9': letra = "q";
    break;
  }
  return letra;
}
