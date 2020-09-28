#include <stdio.h>
#include <unistd.h>
#include <string.h> /* for strncpy */

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <net/if.h>
#include <arpa/inet.h>

int main( int argc, char *argv[] )  {
    
    if (argc == 1) { // no arguments
        // show help
        printf("Welcome to MacMe!\n\nUse me -h to get an overview of all possible operation modes of me.");
        return 0;
    } else {
        if (strcmp(argv[1], "ip") == 0) { 
            char* interface = "en0"; // default wifi interface on macOS
            if (argc == 4 && strcmp(argv[2], "-i") == 0) {
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
    }
}