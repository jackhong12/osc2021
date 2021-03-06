#ifndef UART_H
#define UART_H
#include "data_type.h"
int push_read_buffer ();
int read_line (char *buffer, u32 size);
void tmp_read ();

void uart_init ();
void uart_sendc (char c);
void uart_sendi (long num);
void uart_sendf (float num);
void uart_sendh (unsigned long num);
void uart_sendhf (unsigned long num);
void uart_send (char *str);
char uart_getc ();
void uart_getline (char *buffer, unsigned int size);

#endif
