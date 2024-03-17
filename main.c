#include "stream.h"
#include "json_handle.h"
#include "ui_handle.h"
#include <stdio.h>

#ifdef __APPLE__
#include <TargetConditionals.h>
#endif


int simple_player() {
    SONG* songs;
    int songs_num = load_songs(&songs);
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
    return gst_macos_main((GstMainFunc) simple_plater, NULL);
#else
    return simple_player();
#endif
}
