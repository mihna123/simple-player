simple-player:
	gcc main.c -o simple-player `pkg-config --cflags --libs gstreamer-1.0 json-c`  

clean:
	rm simple-player
