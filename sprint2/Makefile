CXX := $(shell if command -v g++ >/dev/null 2>&1; then echo g++; elif command -v clang++ >/dev/null 2>&1; then echo clang++; else echo g++; fi)
CXXFLAGS = -std=c++11 -Wall -Wextra

BIN_DIR = bin

APP_TARGET = $(BIN_DIR)/MyVensim.exe
FUNCIONAL_TARGET = $(BIN_DIR)/testesRegressivos.exe
UNIT_TARGET = $(BIN_DIR)/unitTests.exe

SRC_CORE = src/system.cpp src/flow.cpp src/model.cpp src/mySim.cpp
SRC_APP = src/main.cpp $(SRC_CORE)
SRC_FUNCIONAL = test/funcional/main.cpp test/funcional/funcional_tests.cpp $(SRC_CORE)
SRC_UNIT = test/unit/main.cpp test/unit/unit_tests.cpp $(SRC_CORE)

.PHONY: all product tests unit funcional run run-product run-unit run-funcional run-tests run-all clean

all: product funcional unit

product: $(APP_TARGET)

funcional: $(FUNCIONAL_TARGET)

unit: $(UNIT_TARGET)

tests: funcional unit

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(APP_TARGET): $(SRC_APP) | $(BIN_DIR)
	@echo "Compilador usado: $(CXX)"
	$(CXX) $(CXXFLAGS) $(SRC_APP) -o $(APP_TARGET)

$(FUNCIONAL_TARGET): $(SRC_FUNCIONAL) | $(BIN_DIR)
	@echo "Compilando testes funcionais..."
	$(CXX) $(CXXFLAGS) $(SRC_FUNCIONAL) -o $(FUNCIONAL_TARGET)

$(UNIT_TARGET): $(SRC_UNIT) | $(BIN_DIR)
	@echo "Compilando testes unitarios..."
	$(CXX) $(CXXFLAGS) $(SRC_UNIT) -o $(UNIT_TARGET)

run: run-product

run-product: product
	./$(APP_TARGET)

run-funcional: funcional
	./$(FUNCIONAL_TARGET)

run-unit: unit
	./$(UNIT_TARGET)

run-tests: run-funcional run-unit

run-all: product funcional unit
	./$(APP_TARGET)
	./$(FUNCIONAL_TARGET)
	./$(UNIT_TARGET)

clean:
	rm -f $(APP_TARGET) $(FUNCIONAL_TARGET) $(UNIT_TARGET)
