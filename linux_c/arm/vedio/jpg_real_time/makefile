CC = arm-linux-gcc

real_time_video:real_time_video.c lcd.c
	$(CC) $^ -o $@ -I ./libjpeg -L ./libjpeg -lapi_v4l2_arm -lpthread -ljpeg

clean:
	rm real_time_video








