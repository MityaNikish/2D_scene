#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "new.h"
#include "point.h"
#include "hline.h"
#include "vline.h"
#include "rect.h"

#include "parser.h"
#include "elemlist.h"

#include "console.h"
#include "parameters.h"
#include "init_field.h"

#include "creator_shape.h"

int main() {
    int quit = 0;

    const struct Creator* creators[] = { CreatorPoint,CreatorRect, CreatorHLine, CreatorVLine, NULL };
    struct WrapContainer* vec_shape;

    printf("Input file name with your date (empl: file.txt): ");
    char file_name[10] = "";

    while (1) {
        fgets(file_name, 10, stdin);
        file_name[strlen(file_name) - 1] = '\0';

        vec_shape = (struct WrapContainer*)_reading_shapes_from_input_file(file_name, creators);
        if (vec_shape != NULL) break;
        printf("\nThe specified file could not be opened!!!\n");
        printf("Repeat input file name with your date: ");
    }


    con_init();
    con_hideCursor();
    init_colors();
    initial_draw(); 

    struct Shape** sprites = (struct Shape**)calloc(vec_shape->size, sizeof(void*));
    assert(sprites != NULL);


    for (int i = 0; i < vec_shape->size; i++) {
        for (int j = 0; creators[j] != NULL; j++) {
            if (strstr(vec_shape->elem_vector[i].name, creators[j]->name) != NULL) {
                Tokens temp = vec_shape->elem_vector[i];
                *(sprites + i) = figure_creation(creators[j], temp.arg[0], temp.arg[1], temp.arg[2], temp.arg[3]);
                break;
            }
        }
    }

    for (int i = 0; i < vec_shape->size; i++) {
        draw(*(sprites + i));
    }

    while (!quit) {
        if (con_keyPressed()) {
            quit = 1;
        }
    }

    for (int i = 0; i < vec_shape->size; i++) {
        delete(*(sprites + i));
    }

    free(sprites);
    delete(vec_shape);

    con_clearScr();
    con_deinit();

    _CrtDumpMemoryLeaks();
}