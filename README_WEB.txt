SIMULADOR BANCARIO - VERSION WEB LOCAL CON SQLITE
================================================

INICIO RAPIDO EN WINDOWS
1. Descomprime TODO el archivo ZIP en una carpeta (por ejemplo, Escritorio\SimuladorBancario).
2. Verifica que tengas Python 3 instalado. No necesitas instalar Flask ni paquetes adicionales.
3. Abre la carpeta web.
4. Haz doble clic en iniciar_servidor.bat.
5. El navegador se abrirá en http://127.0.0.1:8000.
6. Para detener el servidor, vuelve a la ventana negra y presiona Ctrl + C.

BASE DE DATOS Y DATOS DE PRUEBA
- La aplicación usa SQLite, incluido en Python.
- El archivo web\simulador_bancario.db viene incluido con registros de demostración.
- Puedes crear, modificar (mediante depósitos/retiros/transferencias) y eliminar cuentas.
- Los cambios se guardan automáticamente en SQLite.
- Al cerrar y volver a iniciar el servidor, tus cambios permanecen.
- Los nombres que dicen “demo” y los clientes de prueba son ficticios; reemplázalos por los datos que quieras usar.
- NO borres web\simulador_bancario.db si quieres conservar tus registros.
- Si quieres comenzar de cero, detén el servidor y elimina ese archivo; al volver a iniciar se crea una base nueva con datos de demostración.

CONTENIDO
- web\app.py: servidor local y lógica de la aplicación.
- web\index.html: interfaz web.
- web\iniciar_servidor.bat: acceso rápido para Windows.
- web\simulador_bancario.db: base de datos SQLite inicial.
- Archivos .h y main.cpp: implementación académica en C++ de las estructuras de datos.
- INFORME_TECNICO_Y_SUSTENTACION.md: apoyo para explicar el proyecto.

ALCANCE ACADEMICO Y SEGURIDAD
- Es un simulador académico local, no un banco real ni un sistema para dinero real.
- El servidor escucha solo en 127.0.0.1 y no publica la aplicación en internet.
- La interfaz web implementa las operaciones del simulador en Python/SQLite; los archivos C++ se conservan como implementación académica separada, no se ejecutan desde la web.
- Las vistas del ABB, árbol B, pila y grafos son representaciones de las estructuras y sus datos. El índice web del árbol B se muestra ordenado; las operaciones completas de las estructuras C++ están en sus archivos fuente.
