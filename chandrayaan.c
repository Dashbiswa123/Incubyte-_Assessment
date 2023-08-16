#include <stdio.h>

typedef struct {
    int x, y, z;
    char direction;
} GalacticCoordinates;

void moveForward(GalacticCoordinates *coords) {
    switch (coords->direction) {
        case 'N': coords->y++; break;
        case 'S': coords->y--; break;
        case 'E': coords->x++; break;
        case 'W': coords->x--; break;
        case 'U': coords->z++; break;
        case 'D': coords->z--; break;
    }
}

void moveBackward(GalacticCoordinates *coords) {
    switch (coords->direction) {
        case 'N': coords->y--; break;
        case 'S': coords->y++; break;
        case 'E': coords->x--; break;
        case 'W': coords->x++; break;
        case 'U': coords->z--; break;
        case 'D': coords->z++; break;
    }
}

void turnLeft(GalacticCoordinates *coords) {
    switch (coords->direction) {
        case 'N': coords->direction = 'W'; break;
        case 'S': coords->direction = 'E'; break;
        case 'E': coords->direction = 'N'; break;
        case 'W': coords->direction = 'S'; break;
    }
}

void turnRight(GalacticCoordinates *coords) {
    switch (coords->direction) {
        case 'N': coords->direction = 'E'; break;
        case 'S': coords->direction = 'W'; break;
        case 'E': coords->direction = 'S'; break;
        case 'W': coords->direction = 'N'; break;
    }
}

void turnUp(GalacticCoordinates *coords) {
    if (coords->direction != 'U') coords->direction = 'U';
}

void turnDown(GalacticCoordinates *coords) {
    if (coords->direction != 'D') coords->direction = 'D';
}

void resetPosition(GalacticCoordinates *coords) {
    coords->x = 0;
    coords->y = 0;
    coords->z = 0;
    coords->direction = 'N';
}

int main() {
    GalacticCoordinates coordinates = {0, 0, 0, 'N'};
    char command;

    while (1) {
        printf("Enter a command (f/b/l/r/u/d/reset(x)/exit(e)): ");
        scanf(" %c", &command);

        switch (command) {
            case 'f': moveForward(&coordinates); break;
            case 'b': moveBackward(&coordinates); break;
            case 'l': turnLeft(&coordinates); break;
            case 'r': turnRight(&coordinates); break;
            case 'u': turnUp(&coordinates); break;
            case 'd': turnDown(&coordinates); break;
            case 'x': resetPosition(&coordinates); break;
            case 'e':
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid command. Please try again.\n");
        }

        printf("Current Position: (%d, %d, %d)\n", coordinates.x, coordinates.y, coordinates.z);
        printf("Current Direction: %c\n", coordinates.direction);
    }

    return 0;
}
