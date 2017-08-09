CC=gcc
CFLAGS=-Wall

src_dir=src
bin_out_dir=bin

all: prep hexdump

prep:
	@mkdir -p $(bin_out_dir)

hexdump: $(src_dir)/hexdump.c
	$(CC) $(CFLAGS) -o $(bin_out_dir)/hexdump $(src_dir)/hexdump.c

.PHONY: clean
clean:
	$(RM) $(bin_out_dir)/hexdump
	#$(RMDIR) $(bin_out_dir)
