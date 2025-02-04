#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

//Pinos dos leds 
#define PINO_LED_VERMELHO 13
#define PINO_LED_AMARELO 12
#define PINO_LED_VERDE 11

int estado_atual = 0;
// Função que alterna os estados do semáforo.
bool callback_temporizador(struct repeating_timer *t) {
    gpio_put(PINO_LED_VERMELHO, 0);
    gpio_put(PINO_LED_AMARELO, 0); //todos inciam desligado
    gpio_put(PINO_LED_VERDE, 0);

    if (estado_atual == 0) {
        gpio_put(PINO_LED_VERMELHO, 1); //altera o estado a cada 3 segundos
        estado_atual = 1;
    } else if (estado_atual == 1) {
        gpio_put(PINO_LED_AMARELO, 1);
        estado_atual = 2;
    } else if (estado_atual == 2) {
        gpio_put(PINO_LED_VERDE, 1);
        estado_atual = 0;
    }
    return true;
}

int main() {
    stdio_init_all();
    //Pinos como saida
    gpio_init(PINO_LED_VERMELHO);
    gpio_set_dir(PINO_LED_VERMELHO, GPIO_OUT);
    gpio_init(PINO_LED_AMARELO);
    gpio_set_dir(PINO_LED_AMARELO, GPIO_OUT);
    gpio_init(PINO_LED_VERDE);
    gpio_set_dir(PINO_LED_VERDE, GPIO_OUT);
// Configura um temporizador que chama a função de callback 
    struct repeating_timer temporizador;
    add_repeating_timer_ms(3000, callback_temporizador, NULL, &temporizador);

    while (true) { //loop
        printf("Semáforo em execução...\n");
        sleep_ms(1000);
    }
    return 0;
}