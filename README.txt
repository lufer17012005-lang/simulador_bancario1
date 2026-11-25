SIMULADOR BANCARIO - ENTREGA CON VERSION DE CONSOLA Y VERSION WEB LOCAL

VERSION WEB:
Consulta web/LEEME_WEB.txt. En Windows, entra a web y ejecuta iniciar_servidor.bat. Se abre http://127.0.0.1:8000 en el navegador. Requiere Python 3; no necesita instalar paquetes adicionales.

VERSION CONSOLA C++:
Compilar: g++ -std=c++11 -Wall -Wextra -pedantic main.cpp -o simulador
Ejecutar: ./simulador (Linux/macOS) o simulador.exe (Windows)

ESTRUCTURAS C++ INCLUIDAS:
- Lista doble de cuentas
- Cola FIFO de turnos
- Pila enlazada de historial
- Árbol binario de búsqueda
- Cola de prioridad por multilistas
- Árbol B de grado mínimo 2
- Grafo dirigido y no dirigido con listas de adyacencia

La versión web es una interfaz local independiente que implementa las operaciones principales en Python. Los archivos C++ originales se conservan para compilar y sustentar la versión de consola.
