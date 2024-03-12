simple-player:
	gcc main.c -o simple-player `pkg-config --cflags --libs gstreamer-1.0`  
