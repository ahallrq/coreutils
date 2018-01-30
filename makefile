CC=gcc
CFLAGS=-g -O0 

src_dir=src
bin_out_dir=bin

all: prep hexdump ls true false

prep:
	@mkdir -p $(bin_out_dir)


hexdump: $(src_dir)/hexdump.c
	$(CC) $(CFLAGS) -o $(bin_out_dir)/hexdump $(src_dir)/hexdump.c

ls: $(src_dir)/ls.c
	$(CC) $(CFLAGS) -o $(bin_out_dir)/ls $(src_dir)/ls.c

true: $(src_dir)/true.c
	$(CC) $(CFLAGS) -o $(bin_out_dir)/true $(src_dir)/true.c

false: $(src_dir)/false.c
	$(CC) $(CFLAGS) -o $(bin_out_dir)/false $(src_dir)/false.c

.PHONY: clean
clean:
	rm $(bin_out_dir)/hexdump
	rm $(bin_out_dir)/ls
	rm $(bin_out_dir)/true
	rm $(bin_out_dir)/false
	#$(RMDIR) $(bin_out_dir)
