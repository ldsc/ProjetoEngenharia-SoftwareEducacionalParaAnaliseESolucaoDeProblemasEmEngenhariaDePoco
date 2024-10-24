# Nome do compilador
CXX = g++

# Flags do compilador
CXXFLAGS = -Wall -std=c++17 -O2

# Diretório de saída
OUT_DIR = ..\test

# Nome do executável (adiciona extensão .exe no Windows)
TARGET = $(OUT_DIR)/SoftwarePoco$(EXE)


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

EXE = .exe
RM = del
RMFLAGS = /Q
RMCMD = FOR %i IN (*.o) DO $(RM) $(RMFLAGS) %i


$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RMCMD)
	$(RM) $(RMFLAGS) $(TARGET)
