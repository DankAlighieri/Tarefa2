#include <stdio.h>
#include <string.h>  // Incluído para usar a função strcmp
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "pico/bootrom.h" 

void reiniciar_boot() {
    reset_usb_boot(0,0);
}

int main() {
    char comando[10];
    stdio_init_all();

    /*
        ToDo
        Recerber o comando do usuário
    */
    
    while (1) {
        //Adicionado scanf        
        // Interpretando os comandos
        if (strcmp(comando, "verde") == 0) {
            ligar_led_verde();
            scanf("%c", &comando);
            printf("\nLED VERDE");
        } else if (strcmp(comando, "azul") == 0) {
            ligar_led_azul();
            scanf("%c", &comando);
            printf("\nLED AZUL");
        } else if (strcmp(comando, "vermelho") == 0) {
            ligar_led_vermelho();
            scanf("%c", &comando);
            printf("\nLED VERMELHO");
            scanf("%c", &comando);
        } else if (strcmp(comando, "branco") == 0) {
            ligar_leds_branco();
            scanf("%c", &comando);
            printf("\nLED BRANCO");
        } else if (strcmp(comando, "desligar") == 0) {
            desligar_leds();
            scanf("%c", &comando);
            printf("\nLEDS DESLIGADOS");
        } else if (strcmp(comando, "buzzer") == 0) {
            acionar_buzzer();
            scanf("%c", &comando);
            printf("\nBUZZER");
        } else if (strcmp(comando, "reboot") == 0) {
            reiniciar_boot();
            scanf("%c", &comando);
            printf("\nREBOOT");
        } else {
            printf("Comando não reconhecido!\n");
        }
    }

    return 0;
}