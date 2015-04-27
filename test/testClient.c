#include "./../lib/connection/socketUtils.h"
#include "./../lib/connection/server.h"

int main(int argc, char *argv[]) {

    int portNumber = 4444;
    int flag = FALSE;

    ServerConnection server = startConfigurationServer(portNumber);

    server.newSocketFileDescriptor[0] = Accept(server.socketFileDescriptor,
                                                  (struct sockaddr *) &server.cli_addr,
                                                  &server.clientLenght);
    printf("New connection , socket fd is %d , ip is : %s , port : %d \n",
           server.newSocketFileDescriptor[0], inet_ntoa(server.cli_addr.sin_addr),
           ntohs(server.cli_addr.sin_port));

    long long timeToStart = timeToStartInSeconds(10);

    printf("Sending timeToStart %lld \n",timeToStart);

    sendTimeToStart(server.newSocketFileDescriptor[0],timeToStart);

    sleep(1);

    printf("Sending flag %d\n",flag);

    sendFlag(server.newSocketFileDescriptor[0],flag);

    sleep(20);

    flag = TRUE;

    printf("Changing flag %d\n",flag);

    sendFlag(server.newSocketFileDescriptor[0],flag);

    sleep(20);

    flag = FALSE;

    printf("Changing flag %d\n",flag);

    sendFlag(server.newSocketFileDescriptor[0],flag);

    sleep(20);

    flag = TRUE;

    printf("Changing flag %d\n",flag);

    sendFlag(server.newSocketFileDescriptor[0],flag);

    return 0;

}