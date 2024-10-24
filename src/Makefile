# Nome do compilador
CXX = g++

CXXFLAGS = -Wall -std=c++17 -O2

# Diretório de saída
OUT_DIR = output

# Nome do executável
TARGET = $(OUT_DIR)/SoftwarePoco

SRC = main.cpp \
      CAuxiliar.cpp \
      CModeloBingham.cpp \
      CModeloNewtoniano.cpp \
      CModeloPotencia.cpp \
      CModeloReologico.cpp \
      CSimuladorPoco.cpp \
      CTrechoPoco.cpp \
      CPoco.cpp 

OBJ = $(SRC:.cpp=.o)

# Regra principal para gerar o executável
$(TARGET): $(OBJ)
	mkdir -p $(OUT_DIR)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

# Regra para gerar arquivos .o a partir de .cpp
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regra de limpeza manual (mantém o diretório limpo após build)
clean:
	rm -f $(OBJ) $(TARGET)
