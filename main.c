#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <net/if.h>
#include <arpa/inet.h>

#define WELCOME "Welcome to MacMe!\n\nUse me -h to get an overview of all possible operation modes of me.\n"

int main(int argc, char *argv[])
{
    if (argc == 1)
    { // no arguments
        printf(WELCOME);
        return 0;
    } 
    else 
    {
        const char* program = argv[1];
        if (strcmp(program, "-h") == 0) 
        { // Show help prompt
            const char* helpPrompt = "Usage: me [program | -h] [options...]\n\nPrograms include:\n \
            \tip\t\t\t\tReturns the ip address of the network interface en0 (default).\n \
            \tip [-i] <interface name>\tReturns the ip address of the specified interface.\n \
            \tname\t\t\t\tReturns the user name of the currently logged in user.\n \
            \tfinder\t\t\t\tOpens a finder window in the current directory.\n \
            \tsettings\t\t\tOpens the settings window.\n \
            \tos\t\t\t\tReturns the MacOS version.\n \
            \n";
            printf("%s", helpPrompt);
        }
        else if (strcmp(program, "ip") == 0)
        { // ip program
            char* interface = "en0"; // default wifi interface on macOS
            if (argc == 4 && strcmp(argv[2], "-i") == 0)
            {
                interface = argv[3];
            }
            int fd;
            struct ifreq ifr;

            fd = socket(AF_INET, SOCK_DGRAM, 0);
            ifr.ifr_addr.sa_family = AF_INET;
            strncpy(ifr.ifr_name, interface, IFNAMSIZ-1);

            ioctl(fd, SIOCGIFADDR, &ifr);
            close(fd);
            printf("%s\n", inet_ntoa(((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr));
            return 0;
        }
        else if (strcmp(program, "name") == 0)
        { // print current user name
            system("echo $USER");
        }
        else if (strcmp(program, "finder") == 0)
        { // open finder in current directory
            system("open .");
        }
        else if (strcmp(program, "settings") == 0) 
        { // open settings
            system("open \"x-apple.systempreferences:com.apple.preference\"");
        }
        else if (strcmp(program, "os") == 0) 
        {
            system("sw_vers -productVersion");
        }
    }
}