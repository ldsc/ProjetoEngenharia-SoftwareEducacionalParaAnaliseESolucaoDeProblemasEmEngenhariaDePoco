# Nome do compilador
CXX = g++

# Flags de compilação
CXXFLAGS = -Wall -std=c++17 -O2

# Diretório de saída
OUT_DIR = output

# Nome do executável
TARGET = $(OUT_DIR)/meu_programa

# Arquivos-fonte (adicione todos os arquivos necessários aqui)
SRC = main.cpp \
      CDraw.cpp \
      CModeloBingham.cpp \
      CModeloNewtoniano.cpp \
      CModeloPotencia.cpp \
      CModeloReologico.cpp \
      CSimuladorPoco.cpp \
      CTrechoPoco.cpp \
      Cpoco.cpp \
      arquivos.cpp

# Arquivos-objeto
OBJ = $(SRC:.cpp=.o)

# Regra padrão para compilar o executável
$(TARGET): $(OBJ)
	mkdir -p $(OUT_DIR)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

# Regra para compilar arquivos .cpp em .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpeza dos arquivos gerados (.o e executável)
clean:
	rm -f $(OBJ) $(TARGET)
