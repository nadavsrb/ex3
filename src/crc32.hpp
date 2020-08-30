#pragma once

#include <stddef.h>
#include <stdint.h>

uint32_t calculate_crc32c (uint32_t crc32c, const unsigned char *buffer, unsigned int length);
uint32_t crc32(const void *buf, size_t size);