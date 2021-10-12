// Universidad de La Laguna
// Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Símbolos, alfabetos y cadenas
// Autor: Aday Chocho Aisa
// Correo: alu0101437538@ull.edu.es
// Fecha: 09/10/2021
// Archivo string_a.cc: clase cadena.
// Contiene la definición de los métodos de la clase string (getters, setters,
// constructores, destructor y las funciones que nos pide el ejercicio)
// Enlaces de interés:
// Historial de revisiones:
// 09/10/2021 - Creación (primera versión) del código - Creación de las clases
// y la función de la primera operación
// 10/10/2021 - Creación del resto de funciones de operación

#include "string_a.h"
#include <fstream>

// Constructores
String_a::String_a() : string_pos_(), alphabet_() {}

String_a::String_a(std::string string, Alphabet alphabet) {
  alphabet_ = alphabet;
  for (int i = 0; i < string.size(); ++i) {
    for (int j = 0; j < alphabet.Get_Size(); ++j) {
      std::string symbol = string.substr(i, alphabet.Get_Symbol(j).size());
      if (alphabet.Get_Symbol(j) == symbol) {
          string_pos_.push_back(j);
          i += alphabet.Get_Symbol(j).size() - 1;
          break;
      }
    }
  }
}

// Destructor
String_a::~String_a() {}

// Getter que devuelve el alfabeto
Alphabet String_a::Get_Alphabet() const {
    return alphabet_;
}

// Método que devuelve el tamaño de la cadena
int String_a::Get_Size() const {
    return string_pos_.size();
}

// Método que invierte la cadena
void String_a::Invert() {
  std::vector<int> v_copy = string_pos_;
  for (int i = 0; i < v_copy.size(); ++i) {
    string_pos_[v_copy.size() - i - 1] = v_copy[i];
  }
}

// Método que devuelve el prefijo de tamaño "number"
std::string String_a::Prefix(int number) {
  assert (number <= string_pos_.size());
  std::string prefix;
  if (number == 0) {
    prefix = EMPTY;
  }
  else {
    for (int i = 0; i < number; ++i) {
      prefix += alphabet_.Get_Symbol(string_pos_[i]);
    }
  }
  return prefix;
}

// Método que devuelve el sufijo de tamaño "number"
std::string String_a::Suffix(int number) {
  assert (number <= string_pos_.size());
  std::string suffix;
  if (number == 0) {
    suffix = EMPTY;
  }
  else {
    for (int i = string_pos_.size() - number; i < string_pos_.size(); ++i) {
      suffix += alphabet_.Get_Symbol(string_pos_[i]);
    }
  }
  return suffix;
}

// Método que devuelve todas las subcadenas de la cadena en un vector
std::vector<std::string> String_a::Substrings() {
  std::vector<std::string> substrings {EMPTY};
  for (int i = 1; i <= string_pos_.size(); ++i) {
    for (int j = 0; j < string_pos_.size() + 1 - i; ++j) {
      std::string string;
      for (int k = 0; k < i; ++k) {
        string += alphabet_.Get_Symbol(string_pos_[k + j]);
      }
      bool flag = true;

      for (int k = 0; k < substrings.size(); ++k) {

        if (substrings[k] == string) {
          flag = false;
        }
      }
      if (flag == true) {
        substrings.push_back(string);
      }
    }
  }
  return substrings;
}

// Sobrecarga del operador <<
std::ostream& operator<<(std::ostream& out, const String_a& string) {
  for (int i = 0; i < string.string_pos_.size(); i++) {
    out << string.alphabet_.Get_Symbol(string.string_pos_[i]);
  }
  return out;
}