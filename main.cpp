#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include "crud_csv.h"
using namespace std;



int main(){
  string ruta = "datos.csv";
  char delimitador = ';';
  string CBU = "1444806711100094671495";
  usuario jos = find(ruta,delimitador,CBU);
 /*
  cout <<endl;
  cout << "----------------------------------"<< endl;
  cout << "CBU: " << jos.CBU<< endl;
  cout << "Nombre: " << jos.nombre<< endl;
  cout << "Apellido: " << jos.apellido<< endl;
  cout << "Pin: " << jos.pin<< endl;
  cout << "Balance: " << jos.balance<< endl;
   
  cout << "----------------------------------"<< endl;
  cout <<endl;
  */
//crear_archivo(ruta,delimitador,encabezado,cant_cols);
//find_all(ruta,delimitador,cant_cols);
jos.nombre = "Sergio";
jos.balance = 123456;
string us[5];
us[0] = jos.CBU ;
us[1] = jos.nombre ;
us[2] = "Antozzi" ;
us[3] = jos.pin ;
us[4] = to_string(369.36)  ;
//update(ruta,delimitador,CBU,us,5);
jos.CBU = "123456";
jos.pin = "1234";
//add_user(ruta,delimitador,jos);
remove_line(ruta,delimitador,"123456");
find_all(ruta,delimitador);

//update_line(ruta,delimitador,"1",encabezado,cant_cols);



      
  
}
