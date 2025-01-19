#include <stdio.h>
#include <string.h>  // Incluído para usar a função strcmp
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "pico/bootrom.h" 


// Definição dos pinos dos LEDs
#define LED_VERDE_PIN 11
#define LED_AZUL_PIN 12
#define LED_VERMELHO_PIN 13

// Definição do pino do buzzer
#define BUZZER_PIN 21

void inicializarLEDs() {
    for(int i = 0; i < 3; i++) {
        gpio_init(LED_VERDE_PIN + i);
        gpio_set_dir(LED_VERDE_PIN + i, GPIO_OUT);
    }
}

void inicializarBuzzer(){
    gpio_init(BUZZER_PIN);
    gpio_set_dir(BUZZER_PIN, GPIO_OUT);
}

void colorir(uint8_t r, uint8_t g, uint8_t b) {
    gpio_put(LED_VERMELHO_PIN, r);
    gpio_put(LED_VERDE_PIN, g);
    gpio_put(LED_AZUL_PIN, b);
}

void ligar_led_verde() {
    colorir(0, 1, 0);
}

void ligar_led_azul() {
    colorir(0, 0, 1);
}

void ligar_led_vermelho() {
    colorir(1, 0, 0);
}

void ligar_leds_branco() {
    colorir(1, 1, 1);
}

void desligar_leds() {
    colorir(0, 0, 0);
}

void acionar_buzzer() {
    for(int i = 0; i < 1000; i++) {
        gpio_put(BUZZER_PIN, 1);
        sleep_ms(1);
        gpio_put(BUZZER_PIN, 0);
        sleep_ms(1);
    }
}


void reiniciar_boot() {
    reset_usb_boot(0,0);
}

int main() {
    char comando[1024];
    stdio_init_all();
    inicializarLEDs(); // Inicializar os LEDs
    inicializarBuzzer(); // Inicializar o Buzzer
    
    while (1) {
        scanf("%1024s", comando);
        printf("Comando recebido: %s\n", comando);
        
        // Interpretando os comandos
        if (strcmp(comando, "verde") == 0) {
            ligar_led_verde();
        } else if (strcmp(comando, "azul") == 0) {
            ligar_led_azul();
        } else if (strcmp(comando, "vermelho") == 0) {
            ligar_led_vermelho();
        } else if (strcmp(comando, "branco") == 0) {
            ligar_leds_branco();
        } else if (strcmp(comando, "desligar") == 0) {
            desligar_leds();
        } else if (strcmp(comando, "buzz") == 0) {
            desligar_leds();
            acionar_buzzer();
        } else if (strcmp(comando, "reboot") == 0) {
            desligar_leds();
            reiniciar_boot();
        }
    }

    return 0;
}