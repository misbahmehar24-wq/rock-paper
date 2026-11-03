# Rock Paper Scissors

A simple Rock, Paper, Scissors game available as a browser game and a C
command-line program.

## Run the browser game

Open [`frontend/index.html`](frontend/index.html) in a browser. No install or
build step is needed.

## Build and run the C game

From the project root, compile with a C compiler such as GCC:

```sh
gcc -std=c11 -Wall -Wextra -pedantic backend/main.c -o rock-paper-scissors
```

Run the resulting program:

```sh
./rock-paper-scissors
```

On Windows, run `rock-paper-scissors.exe` after compiling.

## Project layout

- `frontend/index.html` — browser version of the game
- `backend/main.c` — command-line version written in C

## Publish on GitHub

Create an empty repository on GitHub, then replace the URL below with its
HTTPS URL and run these commands from the project folder:

```sh
git remote add origin https://github.com/YOUR-USERNAME/YOUR-REPOSITORY.git
git add .
git commit -m "Prepare Rock Paper Scissors game"
git push -u origin main
```
