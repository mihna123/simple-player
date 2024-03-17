#include <stdio.h>
#include "json_handle.h"

int handle_ui(SONG* songs, int songs_num) {
    int choise = 0;
    printf("Your stations: \n");
    for(int i = 0; i < songs_num; i++) {
        printf("\t%d - %s\n", i + 1, songs[i].name);
    }

    printf("Play song number: ");
    scanf("%d", &choise);

    if(choise < 1 || choise > songs_num) {
        return -1;
    }

    return --choise;
}
