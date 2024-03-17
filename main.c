#include "stream.h"
#include "json_handle.h"
#include "ui_handle.h"
#include <stdio.h>

#ifdef __APPLE__
#include <TargetConditionals.h>
#endif

#define PROGRAM_NAME "/simple-player"

int simple_player(char* argv[]) {
    SONG* songs;

    char* dir = strndup(argv[0], strlen(argv[0]) - strlen(PROGRAM_NAME));
    int songs_num = load_songs(&songs, dir);
    if(songs_num < 0) {
        return -1;
    }
    int choise = handle_ui(songs, songs_num);

    if(choise >= 0) {
        printf("\nPlaying > %s...\n", songs[choise].name);
        return stream_api(songs[choise].uri);
    } else {
        printf("\nNumber did not match any station.\nExiting...\n");
        return -1;
    }
}

int main(int argc, char* argv[]) {
#if defined(__APPLE__) && TARGET_OS_MAC && !TARGET_OS_IPHONE
    return gst_macos_main((GstMainFunc) simple_plater, argv);
#else
    return simple_player(argv);
#endif
}
