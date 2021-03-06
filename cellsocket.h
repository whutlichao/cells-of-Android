
/*
    use for two system communication
*/
#ifndef CELL_SOCKET_H
#define CELL_SOCKET_H

#define VM_SOCKET_PATH_C "/dev/socket/.c_bridge"
#define VM_SOCKET_PATH_H "/dev/socket/.h_bridge"

#define HOST_BASE_CMD 0
#define VM_BASE_CMD 0
#define SYSTEM_SWITCH 1

struct client_message {
	uint32_t _socket;

    uint32_t _rec_msg_len;
	void *_rec_msg;

    uint32_t _send_msg_len;
	void *_send_msg;
};

typedef void (*handle_message)(struct client_message * ,const int );

void register_cmd_handle(handle_message h,int flag);

void unregister_cmd_handle(int flag);

void create_server_daemon(int bhost);

int send_msg(int bhost,int send_len, const char *send_msg, size_t *reply_len, char *reply_msg);

#endif
