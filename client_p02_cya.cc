// Universidad de La Laguna
// Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Símbolos, alfabetos y cadenas
// Autor: Aday Chocho Aisa
// Correo: alu0101437538@ull.edu.es
// Fecha: 09/10/2021
// Archivo client-p02_vya.cc: programa cliente.
// Contiene la función main del proyecto que usa las clases string y alphabet
// que realizan el trabajo de leer el fichero de entrada al fichero de salida.
// Referencias:
// Enlaces de interés:
// Historial de revisiones:
// 09/10/2021 - Creación (primera versión) del código - Creación de las clases
// y la función de la primera operación
// 10/10/2021 - Creación del resto de funciones de operación

#pragma once

#include <fstream>
#include "string_a.h"


int main(int argc, char* argv[]) {

  assert(argc >= 4);
  std::ifstream infile(argv[1]);
  std::ofstream outfile(argv[2]);
  std::string option {argv[3]};
  std::string line;
  const char SPACE = ' ';

  while (getline(infile, line)) {
    int found;
    std::vector<std::string> alphabet;

    if (line.find_last_of(SPACE) == -1) {
      std::string string_copy;
      string_copy = line;

      for (int i = 0; i < string_copy.size(); ++i) {
        std::string symbol(1, string_copy[i]);
        bool flag = true;

        for (int j = 0; j < alphabet.size(); ++j) {

          if (alphabet[j] == symbol) {
            flag = false;
          }
        }

        if (flag == true) {
          alphabet.push_back(symbol);
        }
      }
    }

    else {

      while (line.find_first_of(SPACE) != -1) {
        found = line.find_first_of(SPACE);
        std::string symbol = line.substr(0, found);
        line = line.substr(found +1);
        bool flag = true;

        for (int i = 0; i < alphabet.size(); ++i) {

          if (alphabet[i] == symbol) {
            flag = false;
          }
        }

        if (flag == true) {
          alphabet.push_back(symbol);
        }
      }
    }

    String_a chain (line, alphabet);

    switch (std::stoi (option)) {

      case 1: // Devuelve el tamaño de la cadena
        outfile << chain.Get_Size() << std::endl;
        break;

      case 2: // Devuelve la cadena invertida
        chain.Invert();
        outfile << chain << std::endl;
        break;

      case 3: // Devuelve los prefijos
        for (int i = 0; i <= chain.Get_Size(); ++i) {
          outfile << chain.Prefix(i) << SPACE;
        }
        outfile << std::endl;
        break;

      case 4: // Devuelve los sufijos
        for (int i = 0; i <= chain.Get_Size(); ++i) {
          outfile << chain.Suffix(i) << SPACE;
        }
        outfile << std::endl;
        break;

      case 5: // Devuelve las subcadenas
        std::vector<std::string> substrings = chain.Substrings();
        for (int i = 0; i < substrings.size(); ++i){
          outfile << substrings[i] << SPACE;
        }
        outfile << std::endl;
        break;

    }
  }
  
  outfile.close(); 
  infile.close();
  return 0;
}