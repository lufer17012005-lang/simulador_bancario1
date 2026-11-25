SIMULADOR BANCARIO - ENTREGA COMPLETA
Requisitos: compilador C++11 o superior.
Compilar:
  g++ -std=c++11 -Wall -Wextra -pedantic main.cpp -o simulador
Ejecutar:
  ./simulador (Linux/macOS) o simulador.exe (Windows)

Estructuras incluidas:
- Lista doble de cuentas
- Cola FIFO de turnos
- Pila de historial enlazada
- ABB de cuentas
- Cola de prioridad por multilistas (prioridad numérica menor = mayor urgencia)
- Árbol B de grado mínimo 2 (inserción, búsqueda y recorrido)
- Grafo dirigido y no dirigido (listas de adyacencia)

Nota: los datos permanecen en memoria durante la ejecución; no hay persistencia en archivos.

MENU RAPIDO
18 registra solicitud prioritaria. La prioridad 1 es la mas urgente.
19 atiende la solicitud con menor numero de prioridad; dentro del mismo nivel respeta FIFO.
24 crea un vertice en ambos grafos.
25 crea una conexion con sentido (origen -> destino).
26 crea una conexion en ambos sentidos.
El arbol B usa grado minimo 2 y permite insercion, busqueda y recorrido ordenado.
