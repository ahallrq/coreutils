CC=gcc
CFLAGS=-Wall

src_dir=src
bin_out_dir=bin

all: prep hexdump ls true false

prep:
	@mkdir -p $(bin_out_dir)

hexdump: $(src_dir)/hexdump.c
	$(CC) $(CFLAGS) -o $(bin_out_dir)/hexdump $(src_dir)/hexdump.c

ls: $(src_dir)/ls.c
	$(CC) $(CFLAGS) -o $(bin_out_dir)/ls $(src_dir)/ls.c

true: $(src_dir)/true
	$(CC) $(CFLAGS) -o $(bin_out_dir)/true $(src_dir)/true.c

false: $(src_dir)/false.c
	$(CC) $(CFLAGS) -o $(bin_out_dir)/false $(src_dir)/false.c

.PHONY: clean
clean:
	$(RM) $(bin_out_dir)/hexdump
	#$(RMDIR) $(bin_out_dir)
