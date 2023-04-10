#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "elemlist.h"
#include "new.h"

static char* _init_name_shape(char* istr, const struct Creator* creators[]) {
    if (istr == NULL) return NULL;

    int lenth = 0;
    int complet = 0;
    char* found_str = "";

    for (char* c = istr; *c; ++c) {
        *c = tolower(*c);
        ++lenth;
    }

    for (int i = 0; creators[i] != NULL; i++) {
        found_str = strstr(istr, creators[i]->name);
        if ((found_str != NULL) && (strlen(creators[i]->name) == strlen(found_str))) {
            complet = 1;
            break;
        }
    }

    if (complet) return found_str;
    else return NULL;
};


void* _reading_shapes_from_input_file(const char* file_name, const struct Creator* creators[]) {
    FILE* file;
    struct WrapContainer* vector_shape = new(_WrapContainer, 0);
    fopen_s(&file, file_name, "r");
    if (!file)
    {
        return NULL;
    }

    char buffer[256];
    char* istr;
    char* cotext = "";
    int arg_counter = 0;
    int num_of_args;
    Tokens elem = { "", {0,0,0,0} };

    if (file)
    {
        while ((fgets(buffer, 256, file)) != NULL)
        {
            istr = strtok_s(buffer, " ", &cotext);

            if (_init_name_shape(istr, creators) != NULL) strncpy_s(elem.name, strlen(istr) + 1, istr, strlen(istr));
            else continue;

            istr = strtok_s(NULL, " ", &cotext);

            num_of_args = 0;
            for (int i = 0; creators[i] != NULL; i++) {
                if (strstr(elem.name, creators[i]->name) != NULL) {
                    num_of_args = creators[i]->number_of_args;
                    break;
                }
            }

            arg_counter = 0;
            while ((istr != NULL) && (istr != (const char*)'\n') && (arg_counter < num_of_args))
            {
                elem.arg[arg_counter] = atoi(istr);
                istr = strtok_s(NULL, " ", &cotext);
                ++arg_counter;
            }

            if ((num_of_args == 0) || (arg_counter < num_of_args)) continue;

            if (push(vector_shape, &elem) == NULL) return vector_shape;
        }
    }
    fclose(file);
    return vector_shape;
}