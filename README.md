# so_long
I'm just a sleepy girl that needs coffee to start working

<h3>Want to play the game?</h3>

```
1. Copy the repository
2. Build the game using: make re
3. Launch the game by executing the game. The second argument shall be the map you want to play
	For example ./so_long map/01.ber
4. Enjoy moving "elili" around the map and collecting coffees until reaching the bathroom
```

# Project Tree

```c
.
├── Makefile
├── include
│   └── solong.h
├── libft/
├── map/
├── mlx/
├── sprites
│   ├── coffee.xpm
│   ├── eli.xpm
│   ├── exit.xpm
│   ├── floor.xpm
│   └── wall.xpm
└── src
    ├── content_checker.c
    ├── get_map.c
    ├── loop_handler.c
    ├── main.c
    ├── movement.c
    ├── path_checker.c
    ├── shape_checker.c
    └── window_handler.c
```

# Project Structure

Lo primero que necesitaremos será entender [cómo trabajan las funciones de miniLibX](https://github.com/erivero-p/42-Tutorials/tree/master/About%20MiniLibX), la librería para programación de aplicaciones gráficas simples que nos dejan utilizar en este proyecto.

Una vez sabido esto, en función de los requisitos especificados en el subject, el proyecto requerirá:

### Game info

Una estructura en la que vayamos almacenando toda la información relevante para el correcto funcionamiento del programa, por ejemplo:

- Los punteros a la ventana y a cada imagen que queramos cargar en el videojuego
- El mapa
- Las coordenadas con la posición del jugador
- El conteo de movimientos y de monedas

### Map handling

- Crear varios mapas, que serán matrices bidimensionales de caracteres en formato .ber.
- Chequear que la forma del mapa sea correcta: rectangular y rodeado de murallas
- Chequear el contenido: una posición inicial, una salida y al menos un objeto coleccionable
- Chequear que haya al menos un camino válido
- Leer el mapa y cargarlo en memoria

### Window management

- Gestionar la creación de la ventana
- Gestionar los hooks para que ESC y la cruz roja de la ventana la cierren
- Gestionar que el cierre de la ventana detenga el programa limpiamente

### Image management

- Elegir la temática y los sprites a utilizar
- Pasar las imágenes a .xpm
- Cargar las imágenes en memoria
- Cargar las imágenes en la ventana

### In-game events

- Un loop-handler que abra y gestione el loop en el que sucede el juego.
- Gestionar los hooks para que el personaje pueda moverse con las teclas W, A, S, D.
- Rehacer el mapa con cada movimiento del jugador, actualizando la posición del jugador, y haciendo desaparecer los coleccionables si los re coge.
- Gestionar el conteo de movimientos (que deberán mostrarse por pantalla) y el conteo de coleccionables recogidos.

# Map Handling

### Creación del mapa

El mapa será un array de caracteres donde `'0'` representa espacios vacíos, `'1'` representa paredes, `'C'` son coleccionables, `'P'` es la posición del jugador y `'E'` es la salida. A la hora de crear los mapas será conveniente crear también mapas con fallos, para poder comprobar que nuestra gestión de errores sea correcta. Un ejemplo de mapa podría ser:

```c
111111111	🟫🟫🟫🟫🟫🟫🟫🟫🟫
1P0100C01	🟫🟣⬜🟫⬜⬜🟡⬜🟫
100000001	🟫⬜⬜⬜⬜⬜⬜⬜🟫
10C000E01	🟫⬜🟡⬜⬜⬜🚩⬜🟫
100010001	🟫⬜⬜⬜🟫⬜⬜⬜🟫
111111111	🟫🟫🟫🟫🟫🟫🟫🟫🟫
```


### Lectura del mapa




Debemos cargar el mapa.ber en memoria, para ello, leeremos el archivo línea por línea con `get_next_line`, lo uniremos en una string con `ft_strjoin` y lo separaremos en un array bidimensional con `ft_split`.
Por como funciona ft_split, en caso de que el mapa tenga saltos de línea en medio, dividiéndolo, se cargará sin esos saltos de línea en memoria, y al hacer el chequeo de la forma del mapa, aunque esté partido por la mitad, nuestro programa lo dará por bueno. Si queremos revisar esto, deberá ser antes de pasar por ft_split.

### Chequeo del mapa

Lo primero que necesitaremos será conocer el dato de las dimensiones del mapa. Con esa información, será más fácil chequear que el mapa sea rectangular (si todas las  strings del array miden lo mismo) y que el mapa tenga paredes en la primera y la última array (paredes superior e inferior) y también en el primer y el último caracter de cada string (paredes izquierda y derecha). Además de comprobar esto, deberemos hacer una función dedicada a revisar que el contenido del mapa sea el requerido, asegurándonos también de comprobar que no haya ningún caracter distinto de los cinco admitidos en el subject. En cada caso deberá mostrarse por pantalla el tipo de error en caso de haberlo.

Por último, deberemos comprobar que haya al menos un camino válido para llegar desde la posición inicial a la salida pasando a recoger todos los coleccionables. Para esto, usaremos un `flood_fill`, que, con recursividad, llenará de caracteres `'F'` todas aquellas casillas a las que se pueda acceder desde la posición inicial. Antes, para no afectar a nuestro mapa, deberemos haber creado una copia del mismo, la cual deberá liberarse adecuadamente. Si, al comparar nuestro nuevo mapa y el original, encontramos que en todas las posiciones donde habían coleccionables así como en la salida, querrá decir que hay una forma posible de acceder a todos estos lugares.

# Window Management

Para crear la ventana haremos una función que llame a `mlx_init()`, para inicializar la conexión con el servidor gráfico, y con el puntero que nos devuelva, podremos llamar a `mlx_new_window()`. También podremos llamar desde esta función, a las funciones dedicadas a crear y cargar las imágenes.

También deberemos tener una función destinada a cerrar el juego, liberando memoria y cerrando (`mlx_destroy_window()`) y limpiando la ventana (`mlx_clear_window()`).

# Image Management

Para crear las imágenes tendremos que haber preparado previamente los sprites, con un tamaño adecuado (en mi caso uso 64px) y en formato xpm. Después, llamaremos a `mlx_xpm_file_to_image()` tantas veces como imágenes tengamos. Esto nos dará un puntero a cada una de las imágenes. 

Con cada puntero, podremos llamar a `mlx_put_image_to_window()`, teniendo siempre en cuenta que la primera imagen que carguemos será la que quede más al fondo, y considerando que, en función del caracter que haya en el mapa, deberemos cargar una imagen u otra.

# In-Game Events

Para gestionar lo que sucede durante el bucle usaremos `mlx_key_hook()` para responder ante las teclas que se pulsen y asignarles una función de control de eventos, y `mlx_hook()` para el evento de clickar la x, a la que le asignaremos una función que cierre todo y libere. Por último, deberemos llamar a `mlx_loop()`, que se encarga de iniciar el bucle principal de eventos, y que se llama después de haber creado la ventana y el resto de eventos.

Para la función de control de eventos, tendremos que prepararla para que reciba cada uno de los hooks y llame a la función correspondiente, bien para cerrar el programa o bien para mover al personaje.

A la hora de mover al personaje, habrá que comprobar que efectivamente nos podamos mover hacia la dirección solicitada, y en ese caso, actualizar las coordenadas del jugador, y rehacer el mapa dejando un `‘0’` donde estaba el jugador y una `‘P’` donde está ahora. Además, habrá que aumentar el conteo de movimientos, y, en caso de que hubiese una moneda, actualizar también este conteo.
