# Compilador
CXX = g++

# Diretório dos arquivos 
INCLUDE_DIR = include
SRC_DIR = src
OBJS_DIR = build
BIN_DIR = bin

# Arquivos .cpp dentro de e fora de /src
CPP_SOURCE = $(wildcard $(SRC_DIR)/*.cpp)

# Arquivos .h dentro de /include
H_SOURCE = $(wildcard $(INCLUDE_DIR)/*.h)

# Arquivos .o dentro de /build
# Essa linha irá pegar o padrão .cpp dentro da lista de arquivos CPP_SOURCE e irá
# substituí-los por $(OBJS_DIR)/%.o, ou seja, arquivos .o no diretório de objetos
OBJS = $(patsubst %.cpp, $(OBJS_DIR)/%.o, $(notdir $(CPP_SOURCE))) #notdir para não tentar criar algo em /src

# Nome do projeto
PROJETO = $(BIN_DIR)/imovel

# Flags
CXX_FLAGS = -g -Wall -pedantic

#
# Compilação e ligação
#

# Executa o target all ao digitar "make all"
all: $(PROJETO) # Tem como pré-requisito o projeto "imovel"

# Para construir o executavel "imovel"
$(PROJETO): $(OBJS) # Tem como pré-requisito os arquivos objeto
	$(CXX) $(OBJS) -o $(PROJETO)

# Constrói cada arquivo objeto, compilando cada arquivo .cpp em .o
$(OBJS_DIR)/%.o: $(SRC_DIR)/%.cpp $(INCLUDE_DIR)/%.h
#O compilador irá adicionar as Flags e compilar cada arquivo .cpp de acordo com o target objeto
	$(CXX) $(CXX_FLAGS) -c $< -o $@ 

# Constrói o arquivo objeto para a main
$(OBJS_DIR)/main.o: $(SRC_DIR)/main.cpp $(H_SOURCE)
	$(CXX) $(CXX_FLAGS) -c $< -o $@

clean:
	del /Q $(OBJS_DIR)\*.o
	@if exist $(BIN_DIR)\imovel.exe del $(BIN_DIR)\imovel.exe
