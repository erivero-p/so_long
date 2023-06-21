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

<h3>Project Tree</h3>

```

.
├── Makefile
├── include
│   └── solong.h
├── libft
├── map
│   ├── 01.ber
│   ├── 02.ber
│   ├── 03.ber
│   └── errors
│       ├── character.ber
│       ├── coins.ber
│       ├── multiple.ber
│       ├── no_path.ber
│       ├── shape.ber
│       └── walls.ber
├── mlx
├── objs
├── so_long
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
