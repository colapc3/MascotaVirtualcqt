Simulación de Mascota Virtual

Este proyecto es una simulación de una mascota virtual que se puede interactuar a través de una interfaz gráfica. La mascota tiene varias estadísticas como salud, energía, felicidad y edad, que se ven afectadas por el tiempo y las interacciones del usuario con diferentes objetos.

Características

Interacción con Objetos: Puedes usar diferentes tipos de objetos (comida, medicina y juguetes) para afectar las estadísticas de la mascota.
Actualización en Tiempo Real: La edad de la mascota y sus estadísticas se actualizan cada 0.5 segundos.
Condiciones Especiales: La felicidad y la energía de la mascota se ven afectadas dependiendo de su edad y salud.
Interfaz Gráfica: Una interfaz intuitiva que muestra la imagen de la mascota y sus estadísticas en tiempo real.

Requisitos del Sistema

Qt 6.7: Necesitarás la versión 6.7 de Qt para compilar y ejecutar este proyecto.
C++: Asegúrate de tener un compilador compatible con C++.

Instalación y Configuración

1. Instalar Qt 6.7: Descarga e instala Qt 6.7 desde Qt Downloads.
2. Configurar Qt Creator:
   - Abre Qt Creator.
   - Crea un nuevo proyecto Qt Widgets Application.
   - Copia los archivos del proyecto en el directorio del proyecto nuevo.
   - Asegúrate de incluir todos los archivos .cpp, .h, y .ui en el proyecto.
3. Ubicación del Archivo CSV:
   - El archivo config.csv debe estar en el mismo directorio que el ejecutable del proyecto para cargar correctamente el inventario.

Estructura del Código

Archivos Principales

- Mascota.h y Mascota.cpp:
  - Define la clase Mascota, que maneja las estadísticas y el estado de la mascota.
  - Métodos clave incluyen usarComida(), usarMedicina(), usarJuguete(), y avanzarTiempo().
- MainWindow.h y MainWindow.cpp:
  - Define la clase MainWindow, que maneja la interfaz gráfica.
  - Configura los temporizadores para actualizar la simulación cada 0.5 segundos.
  - Incluye métodos para actualizar la interfaz y manejar interacciones del usuario.
- main.cpp:
  - Punto de entrada del programa que inicializa y ejecuta la aplicación Qt.
- mainwindow.ui:
  - Define la estructura de la interfaz gráfica utilizando el diseñador de Qt.

Funcionalidades Clave

- Actualizar Tiempo:
  - La edad de la mascota aumenta en 0.5 cada 0.5 segundos.
  - Las estadísticas de la mascota (salud, energía, felicidad) se ajustan según el paso del tiempo y las condiciones específicas.
- Interacción con Objetos:
  - Los botones de la interfaz permiten usar objetos que afectan las estadísticas de la mascota.
- Simulación y Finalización:
  - La simulación se detiene y la aplicación se cierra cuando la mascota muere o el tiempo de simulación excede los 15 segundos.

Ejecución

1. Compilar el Proyecto:
   - Haz clic en el botón de "Build"  en Qt Creator para compilar el proyecto.
2. Ejecutar el Proyecto:
   - Haz clic en el botón de "Run"  para ejecutar la aplicación.

