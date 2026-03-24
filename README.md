# KirCulator
Крутой и кросплатформенный калькулятор на C

## Юзаные Технологии
* **Language:** C11
* **Build System:** CMake
* **Compiler:** GCC / MinGW / Clang

## Как собрать и запустить 

### Способ 1: Через CMake (Рекомендуется)
Если у вас установлен CMake и компилятор:
mkdir build && cd build
cmake ..
cmake --build .

### Способ 2: Напрямую через GCC
Bash

gcc main.c -o KirCulator -static
./KirCulator

### Способ 3: Как нефиг делать скачать из релизов последнею версию
Сюда тыкаешь проста https://github.com/mrmerka/KirCulator/releases но лучше самому скомпилировать
