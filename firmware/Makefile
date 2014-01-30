
CC_WINDOWS_PATH="C:\\HMS800C"
CC=hms800-cc
OBJCOPY=hms800-elf-objcopy

OBJSIZE=hms800-elf-size

OBJS=UV3R/lcd.o UV3R/rda.o UV3R/spi.o UV3R/time.o UV3R/radio.o main.o Int.o UV3R/uart.o UV3R/ui.o UV3R/serialCtrl.o

all: uv3r_firmware

uv3r_firmware: $(OBJS)
	$(CC) -ramclr -mshort -Werror -Wl,"-Map=uv3r_firmware.map" --option-file="$(CC_WINDOWS_PATH)\\options\\MC81F8816.opt" -o uv3r_firmware.out $(OBJS) 
	$(OBJCOPY) -O srec uv3r_firmware.out uv3r_firmware.hex
	$(OBJSIZE) uv3r_firmware.out 

%.o: %.c
	$(CC) -ramclr -mshort -Os -g -Werror -Wa,"-mhms800"  --option-file="$(CC_WINDOWS_PATH)\\options\\MC81F8816.opt" -Wa,"-ahls=$*.lst" -c -o $*.o $<

%.o: %.s
	$(CC) -ramclr -mshort -Os -g -Werror -Wa,"-mhms800"  --option-file="$(CC_WINDOWS_PATH)\\options\\MC81F8816.opt" -Wa,"-ahls=$*.lst" -c -o $*.o $<

flash: uv3r_firmware
	../programmer/uv3rFlash.py -d -a uv3r_firmware.hex

clean:
	rm uv3r_firmware.hex *.o *.lst UV3R/*.o UV3R/*.lst

