#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include "crud_csv.h"
using namespace std;

int main(){
  string ruta = "datos.csv";
  char delimitador = ';';
  const int cant_cols = 5;
  cout << "HolaMundo!!";
  string encabezado[cant_cols];
  encabezado[0] = "id";
  encabezado[1] = "nombre";
  encabezado[2] = "apellido";
  encabezado[3] = "edad";
  encabezado[4] = "mail";
  
crear_archivo(ruta,delimitador,encabezado,cant_cols);
find_all(ruta,delimitador,cant_cols);

  encabezado[0] = "1";
  encabezado[1] = "Sergio";
  encabezado[2] = "anto";
  encabezado[3] = "39";
  encabezado[4] = "santozzi@flasf.com";
add_line(ruta, delimitador, encabezado,5);
  encabezado[0] = "2";
  encabezado[1] = "carlo";
  encabezado[2] = "antos";
  encabezado[3] = "31";
  encabezado[4] = "sdfsd@flasf.com";
add_line(ruta, delimitador, encabezado,5);
  encabezado[0] = "3";
  encabezado[1] = "mariela";
  encabezado[2] = "lamba";
  encabezado[3] = "42";
  encabezado[4] = "lambad@flasf.com";
add_line(ruta, delimitador, encabezado,5);
  encabezado[0] = "2";
  encabezado[1] = "Carlos";
  encabezado[2] = "antos";
  encabezado[3] = "31";
  encabezado[4] = "carlos@flasf.com";

//update_line(ruta,delimitador,"1",encabezado,cant_cols);
}