// Universidad de La Laguna
// Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Símbolos, alfabetos y cadenas
// Autor: Aday Chocho Aisa
// Correo: alu0101437538@ull.edu.es
// Fecha: 09/10/2021
// Archivo alphabet.h: clase alfabeto.
// Contiene la declaración de la clase alphabet (atributos y métodos)
// Referencias:
// Enlaces de interés:
// Historial de revisiones:
// 09/10/2021 - Creación (primera versión) del código - Creación de las clases
// y la función de la primera operación
// 10/10/2021 - Creación del resto de funciones de operación

#ifndef ALPHABET_H
#define ALPHABET_H

#include <iostream>
#include <string>
#include <vector>
#include <cassert>

// Clase que permite almacenar los símbolos usados en una cadena mediante un
// vector de strings
class Alphabet{
  private:
    std::vector<std::string> symbols_;

  public:
    // Constructores y destructor
    Alphabet(void): symbols_() {};
    Alphabet(std::vector<std::string> symbols) : symbols_(symbols) {};
    ~Alphabet() {};

    // Getters-Setters
    std::string Get_Symbol(int position) const;
    std::vector<std::string> Get_Symbols(void) const;
    void Set_Symbol(const int position, const std::string new_symbol);
    void Set_Symbols(const std::vector<std::string> new_symbols);

    // Funciones
    int Get_Size(void);
};

#endif