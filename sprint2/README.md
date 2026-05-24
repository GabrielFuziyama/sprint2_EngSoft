# MyVensim

Projeto da disciplina BCC322 — Engenharia de Software I.

Este repositório contém uma implementação inicial de um simulador C++ baseado em Dinâmica de Sistemas.

## Estrutura

```text
MyVensim/
├── bin/
├── src/
│   ├── main.cpp
│   ├── mySim.cpp
│   ├── mySim.h
│   ├── system.cpp
│   ├── system.h
│   ├── flow.cpp
│   ├── flow.h
│   ├── model.cpp
│   └── model.h
└── test/
    ├── unit/
    │   ├── main.cpp
    │   ├── unit_tests.cpp
    │   └── unit_tests.h
    └── funcional/
        ├── main.cpp
        ├── funcional_tests.cpp
        └── funcional_tests.h
```

## Como compilar no Windows/PowerShell

```powershell
g++ -std=c++11 -Wall -Wextra src/main.cpp src/system.cpp src/flow.cpp src/model.cpp src/mySim.cpp -o bin/MyVensim.exe

g++ -std=c++11 -Wall -Wextra test/funcional/main.cpp test/funcional/funcional_tests.cpp src/system.cpp src/flow.cpp src/model.cpp src/mySim.cpp -o bin/testesRegressivos.exe

g++ -std=c++11 -Wall -Wextra test/unit/main.cpp test/unit/unit_tests.cpp src/system.cpp src/flow.cpp src/model.cpp src/mySim.cpp -o bin/unitTests.exe
```

## Como executar

```powershell
.\bin\MyVensim.exe
.\bin\testesRegressivos.exe
.\bin\unitTests.exe
```

## Como compilar no Linux/Ubuntu

```Bash
g++ -std=c++11 -Wall -Wextra src/main.cpp src/system.cpp src/flow.cpp src/model.cpp src/mySim.cpp -o bin/MyVensim

g++ -std=c++11 -Wall -Wextra test/funcional/main.cpp test/funcional/funcional_tests.cpp src/system.cpp src/flow.cpp src/model.cpp src/mySim.cpp -o bin/testesRegressivos

g++ -std=c++11 -Wall -Wextra test/unit/main.cpp test/unit/unit_tests.cpp src/system.cpp src/flow.cpp src/model.cpp src/mySim.cpp -o bin/unitTests
```

## Como executar

```Bash
./bin/MyVensim
./bin/testesRegressivos
./bin/unitTests
```