CXX      = g++
CXXFLAGS = -Wall -std=c++11 -Isrc
BIN_DIR  = bin

# Puxa dinamicamente apenas as implementações reais do motor e os fluxos
SRC      = $(filter-out src/main.cpp, $(wildcard src/*Impl.cpp src/*Flow.cpp))

all: funcional unit

funcional:
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(SRC) test/funcional/*.cpp -o $(BIN_DIR)/funcional_tests

unit:
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(SRC) test/unit/*.cpp -o $(BIN_DIR)/unit_tests

run-funcional: funcional
	./$(BIN_DIR)/funcional_tests

run-unit: unit
	./$(BIN_DIR)/unit_tests

clean:
	rm -rf $(BIN_DIR)/*

.PHONY: all funcional unit run-funcional run-unit clean