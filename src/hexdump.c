#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int arg_showascii = 0;
long arg_blocksize = 8;
long arg_buffersize = 16;

void print_help(int exit_code);
int hexdump(char filename[]);

int main(int argc, char **argv)
{  
    char arg_filename[1024] = {'\0'};

    if (argc < 2)
    {
        printf("One or more arguments is required\n\n"); 
        print_help(1);
    }

    for (int arg = 1; arg < argc; arg++)
    {
        if (strncmp(argv[arg], "-", 1) == 0)
        {
            if ((strcmp(argv[arg], "--help") == 0) || (strcmp(argv[arg], "-h") == 0)) // Help argument
                print_help(0);
            else if ((strcmp(argv[arg], "--canonical") == 0) || (strcmp(argv[arg], "-C") == 0)) // ASCII display argument
                arg_showascii = 1;
            else if ((strcmp(argv[arg], "--blocksize") == 0) || (strcmp(argv[arg], "-b") == 0)) // Block size argument
            {
                if (arg == argc -1) // Argument is at the end of the list and has no value
                {
                    printf("Argument missing value: %s\n\n", argv[arg]);
                    print_help(1);
                }
                char *arg_val;
                long val = strtol(argv[arg + 1], &arg_val, 10); // Attempt to turn the argument into a long
                
                // Check if the conversion was successful
                // Exit with error if arg_val is our string or if its pointer isn't null
                if ((arg_val == argv[arg + 1]) || (*arg_val != '\0'))
                {
                    printf("Invalid value for argument %s: \"%s\"\n\n", argv[arg], argv[arg + 1]);
                    print_help(1);
                }
                else
                {
                    arg_blocksize = val;
                    arg++; // Note: The argument counter must be incremented otherwise the loop will parse our value
                }
            }
            else if ((strcmp(argv[arg], "--buffersize") == 0) || (strcmp(argv[arg], "-B") == 0)) // Block size argument
            {
                if (arg == argc -1) // Argument is at the end of the list and has no value
                {
                    printf("Argument missing value: %s\n\n", argv[arg]);
                    print_help(1);
                }
                char *arg_val;
                long val = strtol(argv[arg + 1], &arg_val, 10); // Attempt to turn the argument into a long
                
                // Check if the conversion was successful
                // Exit with error if arg_val is our string or if its pointer isn't null
                if ((arg_val == argv[arg + 1]) || (*arg_val != '\0'))
                {
                    printf("Invalid value for argument %s: \"%s\"\n\n", argv[arg], argv[arg + 1]);
                    print_help(1);
                }
                else
                {
                    arg_buffersize = val;
                    arg++; // Note: The argument counter must be incremented otherwise the loop will parse our value
                }
            }
            else
            {
                printf("Invalid argument: \"%s\"\n\n", argv[arg]);
                print_help(1);
            }
        }
        else
        {
            // Only the first argument is used for the file name.
            if (strlen(arg_filename) == 0)
            {
                strncpy(arg_filename, argv[arg], sizeof(arg_filename));
                arg_filename[sizeof(arg_filename)-1] = '\0';
                continue;
            }
        }
    }

    if (arg_filename[0] == '\0')
    {
        printf("Missing required argument: filename\n");
        exit(EXIT_FAILURE);
    }
    
    if (arg_blocksize < 1)
    {
        printf("The block size must be greater than 0.");
        exit(EXIT_FAILURE);
    }
    
    if (arg_buffersize < 1)
    {
        printf("The buffer size must be greater than 0.");
        exit(EXIT_FAILURE);
    }
    
    hexdump(arg_filename);
        
}

void print_help(int exit_code)
{
    printf("Usage:\n hexdump [options] <filename>\n");
    printf("Print a hexidecimal representation of an entire file.\n\n");
    printf("Required args:\n <filename>\t\t path to file to dump\n\n");
    printf("Optional args:\n");
    printf(" -h, --help\t\t print this help text\n");
    printf(" -C, --canonical\t show ascii alongside text\n");
    printf(" -b, --blocksize\t set the block size\n");
    printf(" -B, --buffersize\t set the buffer size\n");
    
    if (exit_code == 0)
        exit(EXIT_SUCCESS);
    else if (exit_code > 0)
        exit(EXIT_FAILURE);
    else
        return;
}

int hexdump(char filename[])
{
    FILE *f =  fopen(filename,"rb");
    if (f == NULL)
    {
        fprintf(stderr, "fopen() error - failed while opening file: %s\n", filename);
        exit(EXIT_FAILURE);
    }
    if (fseek(f, 0, SEEK_SET) != 0)
    {
        if (ferror(f))
        {
            fprintf(stderr, "fseek() error - failed while seeking file: %s\n", filename);
            exit(EXIT_FAILURE);
        }
    }
    
    fseek(f, 0, SEEK_END);
    long file_size = ftell(f);
    fseek(f, 0, SEEK_SET);
    long filepos = 0;

    int buffersize = arg_buffersize;
    unsigned char buffer[buffersize];
    int blocksize = arg_blocksize;
    int blocks = buffersize/blocksize;
    
    if (buffersize % blocksize != 0) // Check to make sure the blocks are evenly sized
    {
        fprintf(stderr, "Parameter error - unequal block size: %i\n \
            Ensure the buffer size (%i) is divisible by the block size.\n", blocksize, buffersize);
        exit(EXIT_FAILURE);
    }
    
    while (ftell(f) < file_size)
    {
        memset(buffer, 0, sizeof(buffer));
        int bufferpos = 0;
        int bytesread = fread(buffer, 1, buffersize, f);
        if (bytesread == 0)
        {
            if (ferror(f))
            {
                fprintf(stderr, "fread() error - failed while reading file: %s\n", filename);
                exit(EXIT_FAILURE);
            }
            break;
        }

        printf("%08lx  ", filepos);
        for (int currentblock = 0; currentblock < blocks; currentblock++)
        {
            for (int blockpos = 0; blockpos < blocksize; blockpos++)
            {
                if (bufferpos < sizeof(buffer)) // In case we somehow manage to go outside the buffer
                {
                    if (bufferpos < bytesread)
                        printf("%02x ", buffer[bufferpos]);
                    else
                        printf("   ");
                    
                    bufferpos++;
                }
            }
            printf(" ");
        }
        
        if (arg_showascii)
        {
            printf("|");
            for (int bufpos = 0; bufpos < bytesread; bufpos++)
            {
                if ((buffer[bufpos] > 31) && (buffer[bufpos] < 126))
                    printf("%c", buffer[bufpos]);
                else
                    printf(".");
            }
            printf("|");
        }
        printf("\n");
        filepos += bytesread;
    }
    printf("%08lx\n", filepos);

    return EXIT_SUCCESS;
}
