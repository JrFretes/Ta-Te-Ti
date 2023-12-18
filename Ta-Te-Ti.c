#include <stdio.h>

#define FILAS 3
#define COLUMNAS 3

// Funciones prototipo
void inicializarTablero(char tablero[FILAS][COLUMNAS]);
void mostrarTablero(char tablero[FILAS][COLUMNAS]);
int realizarJugada(char tablero[FILAS][COLUMNAS], int fila, int columna, char jugador);
int verificarGanador(char tablero[FILAS][COLUMNAS]);

int main() {
    char tablero[FILAS][COLUMNAS];
    int fila, columna, turno = 1, ganador = 0;

    inicializarTablero(tablero);

    do {
        mostrarTablero(tablero);

        // Determinar el jugador actual
        char jugador = (turno % 2 == 1) ? 'X' : 'O';

        printf("\nJugador %c, ingrese fila y columna (ejemplo: 1 2): ", jugador);
        scanf("%d %d", &fila, &columna);

        // Verificar si la jugada es válida y realizarla
        if (fila >= 1 && fila <= FILAS && columna >= 1 && columna <= COLUMNAS &&
            tablero[fila - 1][columna - 1] == ' ') {
            realizarJugada(tablero, fila - 1, columna - 1, jugador);
            ganador = verificarGanador(tablero);
            turno++;
        } else {
            printf("Jugada no válida. Inténtelo de nuevo.\n");
        }

    } while (ganador == 0 && turno <= FILAS * COLUMNAS);

    mostrarTablero(tablero);

    if (ganador == 1) {
        printf("\n¡Jugador X es el ganador!\n");
    } else if (ganador == 2) {
        printf("\n¡Jugador O es el ganador!\n");
    } else {
        printf("\n¡Empate! No hay ganador.\n");
    }

    return 0;
}

void inicializarTablero(char tablero[FILAS][COLUMNAS]) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            tablero[i][j] = ' ';
        }
    }
}

void mostrarTablero(char tablero[FILAS][COLUMNAS]) {
    printf("\n  1 2 3\n");
    for (int i = 0; i < FILAS; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < COLUMNAS; j++) {
            printf("%c", tablero[i][j]);
            if (j < COLUMNAS - 1) {
                printf("|");
            }
        }
        printf("\n");
        if (i < FILAS - 1) {
            printf("  -----\n");
        }
    }
}

int realizarJugada(char tablero[FILAS][COLUMNAS], int fila, int columna, char jugador) {
    tablero[fila][columna] = jugador;
    return 0;
}

int verificarGanador(char tablero[FILAS][COLUMNAS]) {
    // Verificar filas y columnas
    for (int i = 0; i < FILAS; i++) {
        if (tablero[i][0] == tablero[i][1] && tablero[i][1] == tablero[i][2] && tablero[i][0] != ' ') {
            return (tablero[i][0] == 'X') ? 1 : 2; // X gana con 1, O gana con 2
        }
        if (tablero[0][i] == tablero[1][i] && tablero[1][i] == tablero[2][i] && tablero[0][i] != ' ') {
            return (tablero[0][i] == 'X') ? 1 : 2; // X gana con 1, O gana con 2
        }
    }

    // Verificar diagonales
    if (tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2] && tablero[0][0] != ' ') {
        return (tablero[0][0] == 'X') ? 1 : 2; // X gana con 1, O gana con 2
    }
    if (tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0] && tablero[0][2] != ' ') {
        return (tablero[0][2] == 'X') ? 1 : 2; // X gana con 1
    }

    return 0; // Ningún ganador
}