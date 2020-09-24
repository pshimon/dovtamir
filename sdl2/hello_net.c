
#define MAX_PACKET 0xFF
#define MAX_SOCKETS 0x10
#define WOOD_WAIT_TIME 5000
#define FLAG_QUIT 0x0000
#define FLAG_WOOD_UPDATE 0x0010
typedef struct {
    int in_use;
    int questing;
    uint8_t amt_wood;
    uint32_t timer_wood;
} Client;
int next_ind = 0;
TCPsocket server_socket;
Client clients[MAX_SOCKETS];
SDLNet_SocketSet socket_set;
TCPsocket sockets[MAX_SOCKETS];

void CloseSocket(int index) {
    if(sockets[index] == NULL) {
        fprintf(stderr, "ER: Attempted to delete a NULL socket.n");
        return;
    }
 
    if(SDLNet_TCP_DelSocket(socket_set, sockets[index]) == -1) {
        fprintf(stderr, "ER: SDLNet_TCP_DelSocket: %sn", SDLNet_GetError());
        exit(-1);
    }
 
    memset(&clients[index], 0x00, sizeof(Client));
    SDLNet_TCP_Close(sockets[index]);
    sockets[index] = NULL;
}


int main(int argc, char** argv) 
{
    if(SDL_Init(SDL_INIT_TIMER|SDL_INIT_EVENTS) != 0) {
        fprintf(stderr, "ER: SDL_Init: %sn", SDL_GetError());
        exit(-1);
    }

    if(SDLNet_Init() == -1) {
        fprintf(stderr, "ER: SDLNet_Init: %sn", SDLNet_GetError());
        exit(-1);
    }
    IPaddress ip;
    if(SDLNet_ResolveHost(&ip, NULL, 8099) == -1) {
        fprintf(stderr, "ER: SDLNet_ResolveHost: %sn", SDLNet_GetError());
        exit(-1);
    }

    server_socket = SDLNet_TCP_Open(&ip);
    if(server_socket == NULL) {
        fprintf(stderr, "ER: SDLNet_TCP_Open: %sn", SDLNet_GetError());
        exit(-1);
    }
    socket_set = SDLNet_AllocSocketSet(MAX_SOCKETS+1);
    if(socket_set == NULL) {
        fprintf(stderr, "ER: SDLNet_AllocSocketSet: %sn", SDLNet_GetError());
        exit(-1);
    }

    if(SDLNet_TCP_AddSocket(socket_set, server_socket) == -1) {
        fprintf(stderr, "ER: SDLNet_TCP_AddSocket: %sn", SDLNet_GetError());
        exit(-1);
    }
    int running = 1;
    while(running) {
        int num_rdy = SDLNet_CheckSockets(socket_set, 1000);

        if(num_rdy <= 0) {
            // NOTE: none of the sockets are ready
        } else {
            // NOTE: some number of the sockets are ready
        }
    }
    if(SDLNet_TCP_DelSocket(socket_set, server_socket) == -1) {
        fprintf(stderr, "ER: SDLNet_TCP_DelSocket: %sn", SDLNet_GetError());
        exit(-1);
    } SDLNet_TCP_Close(server_socket);

    int i;
    for(i=0; i<MAX_SOCKETS; ++i) {
        if(sockets[i] == NULL) continue;
        CloseSocket(i);
    }

    SDLNet_FreeSocketSet(socket_set);
    SDLNet_Quit();
    SDL_Quit();
}

