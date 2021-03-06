#ifndef DATA_TYPE_H
#define DATA_TYPE_H

typedef unsigned long u64;
typedef unsigned int u32;
typedef unsigned char u8;
#define NULL 0
#define PAGE_SIZE 0x1000
#define page_mask 0xfffffffffffff000
#define aligned16(size) (((size + 0xf) & 0xffffffffffffff0))

#endif
