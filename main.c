#include <gst/gst.h>

#ifdef __APPLE__
#include <TargetConditionals.h>
#endif

int simple_player() {
    gst_init(NULL, NULL);
}

int main(int argc, char* argv[]) {
#if defined(__APPLE__) && TARGET_OS_MAC && !TARGET_OS_IPHONE
    return gst_macos_main((GstMainFunc) simple_plater, NULL);
#else
    return simple_player();
#endif
}
