#ifndef JSON_HANDLE
#define JSON_HANDLE

#include "arraylist.h"
#include "json_object.h"
#include "json_types.h"
#include "json_util.h"
#include <json.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct song {
    char* name;
    char* uri;
} SONG;

int load_songs(SONG** songs) {
    json_object* json_config;
    FILE* input = fopen("./simple-player-config.json", "r");  

    if(input == NULL) {
        printf("Error with opening the config file");
        return -1;
    }

    if((json_config = json_object_from_fd(fileno(input))) == NULL){
        printf("Error with parsing the config file");
        fclose(input);
        return -1;
    }

    array_list* songs_array;
    json_object* song;

    songs_array = json_object_get_array(json_config);
    *songs = malloc(songs_array->length * sizeof(SONG)); 
    
    for(int i = 0; i < songs_array->length; i++) {
        song = (json_object*)(songs_array->array[i]);
        json_object* name_obj;
        json_object* uri_obj;
        if(json_object_object_get_ex(song, "name", &name_obj) == 0){
            printf("Error: 'name' not found in JSON object");
            fclose(input);
            return -1;
        }

        if(json_object_object_get_ex(song, "uri", &uri_obj) == 0) {
            printf("Error: 'uri' not found in JSON object");
            fclose(input);
            return -1;
        }

        (*songs)[i].name = strdup(json_object_get_string(name_obj));
        (*songs)[i].uri = strdup(json_object_get_string(uri_obj));
    }

    fclose(input);
    return songs_array->length;
} 

#endif
