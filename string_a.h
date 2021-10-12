// Universidad de La Laguna
// Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Símbolos, alfabetos y cadenas
// Autor: Aday Chocho Aisa
// Correo: alu0101437538@ull.edu.es
// Fecha: 09/10/2021
// Archivo string_a.h: clase cadena.
// Contiene la declaración de la clase string (atributos y métodos)
// Referencias:
// Enlaces de interés:
// Historial de revisiones:
// 09/10/2021 - Creación (primera versión) del código - Creación de las clases
// y la función de la primera operación
// 10/10/2021 - Creación del resto de funciones de operación

#ifndef STRING_H
#define STRING_H

#define EMPTY "&"

#include "alphabet.h"

// Clase que almacena una secuencia de símbolos que pretenecen a un alfabeto
// y al propio alfabeto, almacenando la posición del simbolo en este último
class String_a{
  private:
    std::vector<int> string_pos_;
    Alphabet alphabet_;

  public:
    // Constructores y destructor
    String_a(void);
    String_a(std::string, Alphabet);
    ~String_a(void);

    // Getters
    Alphabet Get_Alphabet(void) const;

    // Funciones
    int Get_Size(void) const;
    void Invert();
    std::string Prefix(int);
    std::string Suffix(int);
    std::vector<std::string> Substrings(void);

    // Sobrecarga
    friend std::ostream& operator<<(std::ostream& out, const String_a& string);
};

#endif