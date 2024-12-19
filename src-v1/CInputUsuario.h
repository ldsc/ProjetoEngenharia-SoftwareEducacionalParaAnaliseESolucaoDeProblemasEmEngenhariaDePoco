#ifndef CINPUTUSUARIO_h
#define CINPUTUSUARIO_h

#include <string>

class CInputUsuario {
protected:


public:
    // Construtor
    CInputUsuario() {}
    ~CInputUsuario() {}

   // Método
   double getDouble(std::string prompt);
   bool getSimNao(std::string prompt);
   std::string getString(std::string prompt);

    
};

#endif