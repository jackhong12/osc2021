#include "uart.h"
#include "string.h"
#include "reboot.h"
#include "time.h"
#define BUFFER_SIZE 64

void parse_command (char *b) {
    if (!strcmp(b, "hello")) {
        uart_send("Hello World!\n");
    }
    else if (!strcmp(b, "help")) {
        uart_send("hello: print Hello World!\r\n");
        uart_send("help: print all available commands\r\n");
        uart_send("reboot: reboot raspi\r\n");
        uart_send("time: show current time from boost\r\n");
    }
    else if (!strcmp(b, "reboot")) {
        uart_send("reboot~~\n");
        reset(10000);
    }
    else if (!strcmp(b, "time")) {
        uart_sendf(get_time());
        uart_send(" (s)\r\n");
    }
    else {
        uart_send("No such command.\n");
    }
}

int main () {
    uart_init();
    char buffer[BUFFER_SIZE];

    uart_send("\r\n");
    uart_send("+========================+\r\n");
    uart_send("|       osdi shell       |\r\n");
    uart_send("+========================+\r\n");

    while (1) {
        uart_send("$ ");
        uart_getline(buffer, BUFFER_SIZE);
        parse_command(buffer);
        uart_send("\r\n");
    }
}
