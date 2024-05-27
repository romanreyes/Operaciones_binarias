#include "library.h"

void show_bin8(uint8_t val) {
	uint8_t mask = 1 << 7; // Se inicializa una variable en el valor más significativo (1000 0000)
	uint8_t aux;
	for (int i = 0; i < 8; i++) {
		aux= val & mask;
		if(aux==0){
			printf("0");
		}else{
			printf("1");
		}
		if ((i + 1) % 4 == 0) {
			printf("  ");
		}
		mask >>= 1; // Desplaza la máscara un bit a la derecha en cada iteracion
	}
	printf("\n"); // Nueva línea después de imprimir todos los bits
}
void show_bin32 (uint32_t val) {
	uint32_t mask = 1 << 31; // Se inicializa una variable en el valor más significativo (1000 0000)
	uint32_t aux;
	for (int i = 0; i < 32; i++) {
		aux= val & mask;
		if(aux==0){
			printf("0");
		}else{
			printf("1");
		}
		if ((i + 1) % 4 == 0) {
			printf("  ");
		}
		// Desplazar la máscara un bit a la derecha
		mask >>= 1;
	}
	printf("\n"); // Nueva línea después de imprimir todos los bits
}

uint32_t set_bit32(uint32_t data, uint8_t bit_pos, bool bit_value) {
        if(bit_pos > 32) //Si se ingresa una posicion mayor a los 32 bit disponibles muestra un mensaje y sale del procedimiento.
    {
        printf("\n Cantidad de mayor de bits");
        return 0;
    } else{
        if (bit_value) {
        data |= (1 << bit_pos);  // Operador OR (|) para establecer el bit en 1
    } else {
        data &= ~(1 << bit_pos); // Se invierte el 1 con el operador NOT (~), y luego con el operador AND (&) para establecer ese bit en 0
    }
    return data;
}   
}
uint32_t toogle_bit32(uint32_t data, uint8_t bit_pos){
    if(bit_pos > 32) //Si se ingresa una posicion mayor a los 32 bit disponibles muestra un mensaje y sale del procedimiento.
    {
        printf("\n Cantidad de mayor de bits");
        return 0;
    } else{
        data ^= (1 << bit_pos); // Con el operador XOR se invierte el bit que hay en esa posicion.
        return data;
    }
}

uint32_t carry_rotate32(uint32_t data, int8_t N) {
    if (N > 0) {  // Rotar a la izquierda
        for (int i = 0; i < N; i++) {
            uint32_t carry_bit = (data & 0x80000000) >> 31; // Captura el bit de acarreo (MSb)
            data = (data << 1) | carry_bit; // Rota a la izquierda y coloca el carry bit en el LSb
        }
    } 
    else if (N < 0) {  // Rotar a la derecha
        for (int i = 0; i < -N; i++) {  //-N para que se nos vuelva positivo el valor enviado por consola.
            uint32_t carry_bit = (data & 0x1) << 31; // Captura el bit de acarreo (LSb)
            data = (data >> 1) | carry_bit; // Rota a la derecha y coloca el carry bit en el MSb
        }
    }
    return data;
}

uint8_t extract_segment(uint32_t data, uint8_t start, uint8_t end) {
    uint32_t mask = ((1 << (end - start + 1)) - 1) << start; // Máscara con unos (1s) en la posición del segmento deseado
    uint32_t segment = (data & mask) >> start;     // Aplicar la máscara y desplazar el segmento al LSB
    return (uint8_t)segment; //Conversión explícita de tipo 
}