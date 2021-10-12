// Universidad de La Laguna
// Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Símbolos, alfabetos y cadenas
// Autor: Aday Chocho Aisa
// Correo: alu0101437538@ull.edu.es
// Fecha: 09/10/2021
// Archivo alphabet.cc: clase alfabeto.
// Contiene la definición de los métodos de la clase alphabet: getters, setters,
// y tamaño. Existen dos getter/setter: UNo que devuelve un símbolo y otro que
// devuelve el alfabeto entero.
// Referencias:
// Enlaces de interés:
// Historial de revisiones:
// 09/10/2021 - Creación (primera versión) del código - Creación de las clases
// y la función de la primera operación
// 10/10/2021 - Creación del resto de funciones de operación

#include "alphabet.h"

//Getter de un único símbolo
std::string Alphabet::Get_Symbol(int position) const {
  assert(position < symbols_.size());
  return symbols_[position];
}

//Getter del alfabeto completo
std::vector<std::string> Alphabet::Get_Symbols() const {
  return symbols_;
}

//Setter de un único símbolo
void Alphabet::Set_Symbol(const int position, const std::string new_symbol) {
  assert(position < symbols_.size());
  symbols_[position] = new_symbol;
}

//Setter del alfabeto completo
void Alphabet::Set_Symbols(const std::vector<std::string> new_symbols) {
  symbols_ = new_symbols;
}

//Método que devuelve el nº de símbolos del alfabeto
int Alphabet::Get_Size() {
  return symbols_.size();
}