# Arquivo de configuração do cmake
cmake_minimum_required(VERSION 3.28)

# NomeDoProjeto
project(SimuladorEducativoPoco)

set(CMAKE_BUILD_TYPE Release)

add_executable(SimuladorEducativoPoco Auxiliar.cpp 
	  CFluido.cpp 
      CPoco.cpp 
      CTrechoPoco.cpp 
      CModeloReologico.cpp 
      CModeloBingham.cpp 
      CModeloNewtoniano.cpp 
      CModeloPotencia.cpp 
      CSimuladorPoco.cpp 
	  main.cpp
)

set_property(TARGET SimuladorEducativoPoco PROPERTY CXX_STANDARD 23)
set_property(TARGET SimuladorEducativoPoco PROPERTY RUNTIME_OUTPUT_DIRECTORY "../test")


