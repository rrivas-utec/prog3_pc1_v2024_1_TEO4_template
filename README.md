# Task #PC1: Practica Calificada 1  
**course:** Programación III  
**unit:** 1 y 2  
**cmake project:** prog3_pc1_v2024_1
## Indicaciones Específicas
- El tiempo límite para la evaluación es 100 minutos.
- Cada pregunta deberá ser respondida en un archivo cabecera (`.h`) con el número de la pregunta:
    - `board.h`
    - `counter.h`
- Deberás subir estos archivos directamente a [www.gradescope.com](https://www.gradescope.com) o se puede crear un `.zip` que contenga todos ellos y subirlo.

## Question #1 - Template de clase - Tablero de juego (14 points)

### Objetivo:

Elaborar una clase genérica `utec::board` diseñada para manejar tableros de juego que serán utilizados en diferentes contextos, donde cada celda del tablero puede contener una pieza. Las piezas pueden ser representadas por un tipo genérico, que puede incluir pero no está limitado a números enteros, caracteres, enumeraciones, o instancias de una clase.

### Descripción de Requisitos:

1. Generalidades de la Clase:
   - Nombre de la Clase: utec::board.
   - Parámetros de Template:
     - Tipo de Pieza (T): El tipo de elementos que las celdas del tablero pueden almacenar.
       - Cantidad de Filas (ROWS): Un parámetro no tipo que especifica el número de filas en el tablero.
       - Cantidad de Columnas (COLS): Un parámetro no tipo que define el número de columnas en el tablero.
2. Manejo de Celdas Vacías:
   - El tablero debe manejar celdas vacías sin el uso de std::optional. Para representar una celda vacía, se utilizará un valor especial de tipo T, que deberá ser definido en la creación del tablero como el valor vacío.
3. Inicialización del Tablero:
   - Al construir una instancia de utec::board, el tablero deberá inicializarse completamente vacío, llenando todas las celdas con el valor especial que representa "vacío".
4. Funcionalidad de Impresión:
   - Implementar la sobrecarga del operador << para permitir la impresión del tablero. Las celdas vacías se mostrarán como un punto ("`.`") y las celdas ocupadas mostrarán el valor del elemento contenido.
5. Acceso y Modificación de Celdas:
   - Sobrecargar el operador `()` para permitir el acceso y modificación de las celdas del tablero, aceptando dos parámetros enteros que representan la `fila` y la `columna` respectivamente.
6. Constructores y Operadores:
   - Implementar constructores parametrizados, de copia y de movimiento para garantizar una correcta gestión de la memoria y la funcionalidad del tablero.
   - Proveer implementaciones para el operador de asignación de copia y el operador de asignación de movimiento.
7. Memoria dinámica:
   - La clase debe gestionar la memoria dinámica de manera adecuada, evitando fugas de memoria y garantizando la liberación de recursos al finalizar la vida útil de la instancia.

**Use Case #1:**
```cpp
  utec::board<int, 5, 5> b1(-1); // -1 es el valor vacío
  std::cout << b1.rows() << " " << b1.cols() << std::endl;
  std::cout << b1;
```

**Use Case #2:**
```cpp
    class checkers_piece {
      std::string color{};
    public:
      checkers_piece() = default;
      explicit checkers_piece(std::string color): color(std::move(color)) {}
      friend ostream& operator <<(ostream& os, const checkers_piece& cp) {
        os << cp.color;
        return os;
      }
      bool operator==(const checkers_piece& other) { return color == other.color; }
    };
    
    void test() {
      utec::board<checkers_piece, 5, 5> b1(checkers_piece{}); // checkers_piece{} es el valor vacío
      std::cout << b1.rows() << " " << b1.cols() << std::endl;
      b1(1,1) = checkers_piece{"b"};
      b1(3,3) = checkers_piece{"w"};
      std::cout << b1;
    }
```

**Use Case #3:**
```cpp
  utec::board<char, 5, 5> b1(char{}); // char{} es el valor vacío
  std::cout << b1.rows() << " " << b1.cols() << std::endl;
  b1(1,1) = 'b';
  b1(3,3) = 'w';
  std::cout << b1;
  
  utec::board<char, 5, 5> b2(char{}); // char{} es el valor vacío
  b2(0,0) = 'w';
  b2(3,0) = 'w';
  b2(3,3) = 'w';
  b2(0,3) = 'w';
  std::cout << b2;

  std::swap(b1, b2);
  std::cout << b1;
  std::cout << b2;
```
**Use Case #4:**
```cpp
  utec::board<char, 5, 5> b1(char{}); // char{} es el valor vacío
  std::cout << b1.rows() << " " << b1.cols() << std::endl;
  b1(1,1) = 'b';
  b1(3,3) = 'w';
  std::cout << b1;
  utec::board<char, 5, 5> b2(char{});
  b2(0,0) = 'w';
  b2(3,0) = 'w';
  b2(3,3) = 'w';
  b2(0,3) = 'w';
  std::cout << b2;
  b1 = std::move(b2); // uso asignación move: b1 ahora tiene los valores de b2 
  std::cout << b1;
  std::cout << b2.rows() << " " << b2.cols() << std::endl;
  std::cout << b2;
  utec::board<char, 5, 5> b3 = b1; // uso constructor copia: b3 es un clone de b1
  b2 = b3; // uso asignación copia: b2 es un clone de b3
  b2(0,0) = 'w';
  b2(1,1) = 'w';
  std::cout << b2;
  std::cout << b3;
```

## Question #2 - Template de funciones - Contador (6 points)

### Objetivo:

Desarrollar un template de función `counter` que pueda determinar la cantidad de veces que un elemento específico aparece, esta función debe ser capaz de ser utilizada en tres diferentes tipos de estructuras de datos: la clase template `board` incluida en el namespace `utec`, contenedores secuenciales estándar como (`vector`, `deque`, `list`) y arreglos estáticos.

### Descripción de la Tarea:

El template de función `counter` debe ser capaz de recibir distintos tipos de estructuras de datos y contar cuántas veces un elemento específico se encuentra en ellas. Se utilizarán las siguientes estructuras para demostrar la universalidad y flexibilidad del template:

**Contenedor Tipo `utec::board`**:
Define e inicializa una instancia de board con dimensiones y tipo de datos seleccionados, asegurándote de incluir varios ejemplos del elemento a contar.
**Contenedor Estándar de C++**:
Utiliza cualquier contenedor estándar, como `std::vector`, `std::deque` o `std::list`, rellenándolo con una variedad de elementos, incluyendo múltiples instancias del valor a contar.
**Arreglo Estático**:
Crea un arreglo estático con un conjunto predefinido de valores, asegurando la presencia del valor a contar en varias ocasiones.

**Use Case #1:**
```cpp
    std::vector<int> v = {1, 2, 2, 3, 4, 2, 5};
    std::cout << utec::counter(v, 2) << std::endl; // 3
```
**Use Case #2:**
```cpp
    std::list<int> l = {3, 1, 2, 2, 3, 4, 2, 5};
    std::cout << utec::counter(l, 3) << std::endl; // 2
```
**Use Case #3:**
```cpp
    std::deque d = {1, 2, 2, 3, 4, 2, 5};
    std::cout << utec::counter(d, 4) << std::endl; // 1
```
**Use Case #4:**
```cpp
    int arr[] = {6, 2, 6, 4, 2, 7, 2, 6, 6};
    std::cout << utec::counter(arr, 6) << std::endl; // 4
```
**Use Case #5:**
```cpp
    utec::board<int, 3, 3> myBoard(-1);
    myBoard(0, 0) = 1;
    myBoard(0, 1) = 1;
    myBoard(0, 2) = 2;
    myBoard(1, 0) = 2;
    myBoard(1, 1) = 1;
    myBoard(1, 2) = 3;
    myBoard(2, 0) = 4;
    myBoard(2, 1) = 5;
    myBoard(2, 2) = 1;
    std::cout << utec::counter(myBoard, 1) << std::endl; // 4
```

