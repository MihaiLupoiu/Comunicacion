#ifndef CONNECTION_CLIENT
#define CONNECTION_CLIENT

#include "../functions/functions.h"
#include "../socketUtils/socketUtils.h"
#include "../processSount/processSound.h"
#include "../superWAV/superwav.h"
#include "../parsher/parsher.h"

typedef struct ClientConnectionTag{
    /* *********************************************************************
    * socketFileDescriptor are file descriptors,
    * i.e. array subscripts into the file descriptor table .
    * These two variables store the values returned by the socket system call
    * and the accept system call.
    * ********************************************************************** */
    int socketFileDescriptor;

    /***********************************************************************
    * portNumber stores the port number on which the server accepts connections.
    * ********************************************************************** */
    int portNumber;

    /***********************************************************************
    * A sockaddr_in is a structure containing an internet address.
    * This structure is defined in netinet/in.h.
    *
    * The variable serv_addr will contain the address of the server, and
    * cli_addr will contain the address of the client which connects to the server.
    * ********************************************************************** */
    struct sockaddr_in server_addr;
    struct sockaddr_in cli_addr;

    /***********************************************************************
    * The variable server is a pointer to a structure of type hostent.
    * This structure is defined in the header file netdb.h.
    * ********************************************************************** */
    struct hostent *server;

    unsigned int length;

    int clientID;

 } ClientConnection;

int getConfig(Player* playerArguments, char* configFile);

ClientConnection startConfigurationClient(char *address, int portNumber);
int startClientConnection(char *address, int portNumber,  char* configFile);

void* playSuperWav(void *arguments);

#endif