#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <string.h>

/* Main function, opens the file and writes writestring in it */
long unsigned write_in_file(char writefile[], char *writestring)
{
    FILE *fp;

    syslog(LOG_INFO, "Starting writing in file: %s", writefile);  // Log action
    // Try opening the file for writing
    if ((fp = fopen(writefile, "w")) == NULL)
    {
        syslog(LOG_ERR, "Unable to open the file: %s", writefile);
        return 1;
    }

    // Write the string to the file
    if (strlen(writestring) > 0)
    {
        syslog(LOG_INFO, "Writing string to file: %s", writefile);
        fputs(writestring, fp);
        fputs("\n", fp);
    }

    // Close the file after writing
    fclose(fp);
    syslog(LOG_INFO, "Finished writing to file: %s", writefile);
    return 0;
}

int main(int argc, char *argv[])
{
    openlog("Logs", LOG_PID | LOG_CONS, LOG_USER);  // Open syslog with console logging
    syslog(LOG_INFO, "Program started.");  // Log action
    
    // Check if enough arguments are passed
    if (argc < 3)
    {
        syslog(LOG_ERR, "Insufficient arguments. Usage: <program> <filename> <string>");
        closelog();
        return 1;
    }
    
    // Call the write function with provided file name and string
    write_in_file(argv[1], argv[2]);

    syslog(LOG_INFO, "Program finished.");  // Log action
    closelog();  // Close syslog
    return 0;
}
