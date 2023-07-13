#include <sstream>
#include <fstream>
#include <string>
#include <iostream>
#include <stdio.h>
using namespace std;



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
  for(int i=0; i< cant_col;i++){
    archivo_salida << linea[i]<<delimitador;
  }
  archivo_salida <<endl;
     
  archivo_salida.close();
} 
/*
void update (string ruta, char delimitador,string buscado){
  ofstream archivo_salida("temp.csv");
  ifstream archivo_entrada(ruta);
  string cell;
 
  string linea;
  getline(archivo_entrada,linea);

  stringstream stream(linea);
  while(getline(stream,cell,delimitador)){
    if(cell==buscado){
      cell="sergio";
    }

    archivo_salida << cell;
    if(!stream.eof()){
      archivo_salida << delimitador;
    }
    archivo_salida << endl;
  }

  archivo_entrada.close();
  archivo_salida.close();
  remove(ruta.c_str());
  rename("temp.csv", ruta.c_str());

}

void update_line (string ruta,char delimitador,string id, string registro[],int cant_cols){
  ofstream archivo_salida("temp.csv");
  ifstream archivo_entrada(ruta);
  string cell;
 
  string linea;
  getline(archivo_entrada,linea);

  stringstream stream(linea);
  while(getline(stream,cell,delimitador)){
    if(cell==buscado){
      cell="sergio";
    }

    archivo_salida << cell;
    if(!stream.eof()){
      archivo_salida << delimitador;
    }
    archivo_salida << endl;
  }

  archivo_entrada.close();
  archivo_salida.close();
  remove(ruta.c_str());
  rename("temp.csv", ruta.c_str());
}
*/

bool find_all(string ruta,char delimitador, int cant_campos){
  ifstream archivo(ruta);
  string linea;
  string encabezado[cant_campos];
  getline(archivo,linea);
  stringstream stream(linea);

  for(int i=0; i<cant_campos;i++){
     getline(stream,encabezado[i],delimitador);
  }
  for(int i=0;i<cant_campos;i++){
    cout << encabezado[i] << " "<<i <<endl;
  }
/*
  int id;
  
  while(getline(archivo,linea)){
    stringstream stream(linea);
  }
*/
  archivo.close();
  return false;
}

