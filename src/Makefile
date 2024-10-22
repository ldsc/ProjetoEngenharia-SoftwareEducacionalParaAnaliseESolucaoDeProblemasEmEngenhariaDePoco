# Nome do compilador
CXX = g++

CXXFLAGS = -Wall -std=c++17 -O2

# Diretório de saída
OUT_DIR = output

# Nome do executável
TARGET = $(OUT_DIR)/SoftwarePoco


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


OBJ = $(SRC:.cpp=.o)


$(TARGET): $(OBJ)
	mkdir -p $(OUT_DIR)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)


%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean:
	rm -f $(OBJ) $(TARGET)
