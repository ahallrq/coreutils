## Coreutils

Intended to be a re-implementation of various coreutils and extra programs for the purpose of learning C.

Beware: Don't expect 100% compatibility with the GNU or busybox equivalents. Likewise goes for any extra program provided here

Comparison to GNU Coreutils:

*A question mark indicates an unusuable/wip utility. A checkmark indicates a usable utility and a cross indicates a missing utility.*

**Usable**|**Name**|**Description**
:-----:|:-----:|:-----:
✗|chcon|Changes file security context (SELinux)
✗|chgrp|Changes file group ownership
✗|chown|Changes file ownership
✗|chmod|Changes the permissions of a file or directory
✗|cp|Copies a file or directory
✗|dd|Copies and converts a file
✗|df|Shows disk free space on file systems
✗|dir|Is exactly like "ls -C -b". (Files are by default listed in columns and sorted vertically.)
✗|dircolors|Set up color for ls
✗|install|Copies files and set attributes
✗|ln|Creates a link to a file
✓|ls|Lists the files in a directory
✗|mkdir|Creates a directory
✗|mkfifo|Makes named pipes (FIFOs)
✗|mknod|Makes block or character special files
✗|mktemp|Creates a temporary file or directory
✗|mv|Moves files or rename files
✗|realpath|Returns the resolved absolute or relative path for a file
✗|rm|Removes (deletes) files
✗|rmdir|Removes empty directories
✗|shred|Overwrites a file to hide its contents
✗|sync|Flushes file system buffers
✗|touch|Changes file timestamps
✗|truncate|Shrink or extend the size of a file to the specified size
✗|vdir|Is exactly like "ls -l -b". (Files are by default listed in long format.)
✗|b2sum|Computes and checks Blake2 message digest
✗|base32|base32 encodes or decodes data and prints to standard output
✗|base64|base64 encodes or decodes data and prints to standard output
✗|cat|Concatenates and prints files on the standard output
✗|cksum|Checksums and count the bytes in a file
✗|comm|Compares two sorted files line by line
✗|csplit|Splits a file into sections determined by context lines
✗|cut|Removes sections from each line of files
✗|expand|Converts tabs to spaces
✗|fmt|Simple optimal text formatter
✗|fold|Wraps each input line to fit in specified width
✗|head|Outputs the first part of files
✗|join|Joins lines of two files on a common field
✗|md5sum|Computes and checks MD5 message digest
✗|nl|Numbers lines of files
✗|numfmt|Reformat numbers
✗|od|Dumps files in octal and other formats
✗|paste|Merges lines of files
✗|ptx|Produces a permuted index of file contents
✗|pr|Converts text files for printing
✗|sha1sum|Calculates and checks SHA1 checksums.
✗|sha224sum|Calculates and checks SHA224 checksums.
✗|sha256sum|Calculates and checks SHA256 checksums.
✗|sha384sum|Calculates and checks SHA384 checksums.
✗|sha512sum|Calculates and checks SHA512 checksums.
✗|shuf|generate random permutations
✗|sort|sort lines of text files
✗|split|Splits a file into pieces
✗|sum|Checksums and counts the blocks in a file
✗|tac|Concatenates and prints files in reverse order line by line
✗|tail|Outputs the last part of files
✗|tr|Translates or deletes characters
✗|tsort|Performs a topological sort
✗|unexpand|Converts spaces to tabs
✗|uniq|Removes duplicate lines from a sorted file
✗|wc|Prints the number of bytes
✗|arch|Prints machine hardware name (same as uname -m)
✗|basename|Removes the path prefix from a given pathname
✗|chroot|Changes the root directory
✗|date|Prints or sets the system date and time
✗|dirname|Strips non-directory suffix from file name
✗|du|Shows disk usage on file systems
✗|echo|Displays a specified line of text
✗|env|Displays and modifies environment variables
✗|expr|Evaluates expressions
✗|factor|Factors numbers
✓|false|Does nothing
✗|groups|Prints the groups of which the user is a member
✗|hostid|Prints the numeric identifier for the current host
✗|id|Prints real or effective UID and GID
✗|link|Creates a link to a file
✗|logname|Print the user's login name
✗|nice|Modifies scheduling priority
✗|nohup|Allows a command to continue running after logging out
✗|nproc|Queries the number of (active) processors
✗|pathchk|Checks whether file names are valid or portable
✗|pinky|A lightweight version of finger
✗|printenv|Prints environment variables
✗|printf|Formats and prints data
✗|pwd|Prints the current working directory
✗|readlink|Displays value of a symbolic link
✗|runcon|Run command with specified security context
✗|seq|Prints a sequence of numbers
✗|sleep|Delays for a specified amount of time
✗|stat|Returns data about an inode
✗|stdbuf|Controls buffering for commands that use stdio
✗|stty|Changes and prints terminal line settings
✗|tee|Sends output to multiple files
✗|test|Evaluates an expression
✗|timeout|Run a command with a time limit
✓|true|Does nothing
✗|tty|Prints terminal name
✗|uname|Prints system information
✗|unlink|Removes the specified file using the unlink function
✗|uptime|Tells how long the system has been running
✗|users|Prints the user names of users currently logged into the current host
✗|who|Prints a list of all users currently logged in
✗|whoami|Prints the effective userid
✗|yes|Prints a string repeatedly
✗|[|A synonym for test; this program permits expressions like [ expression ].

Extras:

**Usable**|**Name**|**Description**
:-----:|:-----:|:-----:
✓|hexdump|Prints the hexidecimal representation of a file's contents.
