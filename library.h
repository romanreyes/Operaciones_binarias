#pragma once
#include <stdint.h>
#include <stdio.h>

void show_bin8(uint8_t val);
void show_bin32 (uint32_t val);
uint32_t set_bit32(uint32_t data, uint8_t bit_pos, bool bit_value);
uint32_t toogle_bit32(uint32_t data, uint8_t bit_pos);