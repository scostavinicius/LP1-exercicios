#SEU MAKEFILE

# Compilador
CXX = g++

# Diretório dos arquivos 
INCLUDE_DIR = include
SRC_DIR = src
OBJ_DIR = build
BIN_DIR = bin

# Arquivos .cpp dentro de /src
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp) main.cpp

# Arquivos .h dentro de /include
INCLUDE_FILES = $(wildcard $(INCLUDE_DIR)/*.h)

# Arquivos .o dentro de /objects
# Essa linha irá pegar o padrão .cpp dentro da lista de arquivos SRC_FILES e irá
# substituí-los por $(OBJ_DIR)/%.o, ou seja, arquivos .o no diretório de objetos
OBJ_FILES = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(notdir $(SRC_FILES))) #notdir para não tentar criar algo em /src

# Nome e endereço do projeto
PROJETO = $(BIN_DIR)/ordenacao

# Flags
CXX_FLAGS = -g -Wall -pedantic

#
# Compilação e ligação
#

# Executa o target all ao digitar "make all"
all: $(PROJETO) # Tem como pré-requisito o projeto "ordenacao"

# Para construir o "programa"
$(PROJETO): $(OBJ_FILES) # Tem como pré-requisito os arquivos objeto
	$(CXX) $(OBJ_FILES) -o $(PROJETO)

# Constrói cada arquivo objeto, compilando cada arquivo .cpp em .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(INCLUDE_DIR)/%.h
#O compilador irá adicionar as Flags e compilar cada arquivo .cpp de acordo com o target objeto
	$(CXX) $(CXX_FLAGS) -c $< -o $@ 

# Compilação do main.cpp em main.o
$(OBJ_DIR)/main.o: main.cpp $(INCLUDE_FILES)
	$(CXX) $(CXX_FLAGS) -c $< -o $@

clean:
	del /Q $(OBJ_DIR)\*.o
	@if exist $(BIN_DIR)\$(notdir $(PROJETO)).exe del $(BIN_DIR)\$(notdir $(PROJETO)).exe