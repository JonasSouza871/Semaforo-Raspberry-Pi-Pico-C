#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

// Definição dos pinos GPIO para os LEDs
#define RED_LED_PIN 13
#define YELLOW_LED_PIN 12
#define GREEN_LED_PIN 11

// Variável global para rastrear o estado atual do semáforo
volatile int current_state = 0;

// Função de callback do temporizador periódico
bool repeating_timer_callback(struct repeating_timer *t) {
    // Desliga todos os LEDs antes de alterar o estado
    gpio_put(RED_LED_PIN, 0);
    gpio_put(YELLOW_LED_PIN, 0);
    gpio_put(GREEN_LED_PIN, 0);

    // Alterna entre os estados do semáforo
    if (current_state == 0) {
        gpio_put(RED_LED_PIN, 1); // Liga o LED vermelho
        current_state = 1;
    } else if (current_state == 1) {
        gpio_put(YELLOW_LED_PIN, 1); // Liga o LED amarelo
        current_state = 2;
    } else if (current_state == 2) {
        gpio_put(GREEN_LED_PIN, 1); // Liga o LED verde
        current_state = 0;
    }

    return true; // Retorna true para continuar o temporizador
}

int main() {
    // Inicializa a UART para comunicação serial
    stdio_init_all();

    // Configura os pinos dos LEDs como saída
    gpio_init(RED_LED_PIN);
    gpio_set_dir(RED_LED_PIN, GPIO_OUT);
    
    gpio_init(YELLOW_LED_PIN);
    gpio_set_dir(YELLOW_LED_PIN, GPIO_OUT);
    
    gpio_init(GREEN_LED_PIN);
    gpio_set_dir(GREEN_LED_PIN, GPIO_OUT);

    // Inicializa o temporizador periódico com intervalo de 3000 ms (3 segundos)
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    // Loop principal: imprime mensagens na porta serial a cada segundo
    while (true) {
        printf("Semáforo em execução...\n");
        sleep_ms(1000); // Atraso de 1 segundo
    }

    return 0;
}
