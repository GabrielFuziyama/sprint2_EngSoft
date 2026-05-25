CXX = clang++
CXXFLAGS = -std=c++11 -Wall -Wextra

SRC = src/system.cpp src/flow.cpp src/model.cpp src/mySim.cpp

PRODUCT = bin/MyVensim.exe
UNIT_TEST = bin/unitTests.exe
FUNCTIONAL_TEST = bin/testesRegressivos.exe

all: product unit functional

product:
	$(CXX) $(CXXFLAGS) src/main.cpp $(SRC) -o $(PRODUCT)

unit:
	$(CXX) $(CXXFLAGS) test/unit/main.cpp test/unit/unit_tests.cpp $(SRC) -o $(UNIT_TEST)

functional:
	$(CXX) $(CXXFLAGS) test/funcional/main.cpp test/funcional/funcional_tests.cpp $(SRC) -o $(FUNCTIONAL_TEST)

run-product: product
	./$(PRODUCT)

run-unit: unit
	./$(UNIT_TEST)

run-functional: functional
	./$(FUNCTIONAL_TEST)

run-all: all
	./$(UNIT_TEST)
	./$(FUNCTIONAL_TEST)
	./$(PRODUCT)

clean:
	rm -f bin/*.exe bin/*.o bin/*.a bin/*.so bin/*.dll