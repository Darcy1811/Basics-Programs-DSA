#include <stdio.h>
#include <stdlib.h>

struct Room {
    double length;
    double width;
    double height;
};

double area(double length, double width) {
    return length * width;
}

double volume(struct Room r) {
    return r.length * r.width * r.height;
}

void bigger(struct Room* r1, struct Room* r2) {
    double volume1 = volume(*r1);
    double volume2 = volume(*r2);

    if (volume1 > volume2) {
        printf("Room 1 is bigger.\n");
    } else if (volume1 < volume2) {
        printf("Room 2 is bigger.\n");
    } else {
        printf("Both rooms are of the same size.\n");
    }
}

int main() {
    struct Room room1 = {10.0, 8.0, 3.0};
    struct Room room2 = {12.0, 6.0, 4.0};

    struct Room* room3 = (struct Room*)malloc(sizeof(struct Room));
    if (room3 == NULL) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }
    room3->length = 15.0;
    room3->width = 10.0;
    room3->height = 3.5;

    printf("Area of room 1: %.2f square units\n", area(room1.length, room1.width));
    printf("Volume of room 2: %.2f cubic units\n", volume(room2));
    bigger(&room1, &room2);

    free(room3);

    return 0;
}
