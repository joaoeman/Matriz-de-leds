#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "matriz_leds.h"
#include "pico/bootrom.h"

int main()
{
    PIO pio = pio0;
    uint sm = configurar_matriz(pio);
    config_animacoes();
    keypad_init();
    while (true)
    {
        char leitura = read_keypad();
        switch(leitura)
        {
            case 'A' :
                tecla_A(pio, sm); // Desliga todos os leds
                break;
            case 'B' :
                tecla_B(pio, sm); // Acende os leds azuis com 100% de intensidade
                break;
            case 'C' :
                tecla_C(pio, sm); // Acende os leds vermelhos com 80% de intensidade
                break;
            case 'D' :
                tecla_D(pio, sm); // Acende os leds verdes com 50% de intensidade
                break;
            case '#' :
                branco(pio, sm); // Acende os leds brancos com 20% de intensidade
                break;
            case '1' :
                 // Animação de Douglas
                break;
            case '2' :
                animacao_g(pio, sm); // Animação de Ana Luiza
            break;
            case '3' :
                jogo_da_cobrinha(pio, sm); // Animação Leonardo
                break;
            case '4' :
                executar_animacao(0,pio,sm); // Animação de Alisson
                break;
            case '5' :
                anima_05(pio, sm); // Animação de Talles Gomes
                break;
            case '6' :
                animacao_onda(pio, sm); // Animação de Carolina
                break;
            case '7' :
                animacao_b(pio, sm); // Animação de Enzo Lisboa
                break;
            case '8' :
                animacao(pio, sm); // Animação de João, joaoeman
                break;
            case '9' :
                animacao_c(pio, sm); // Animação de Enzo Lisboa
                break;
            case '0' :
                animacao_d(pio, sm); // Animação de Enzo Lisboa
                break;
            case '*' :
                reset_usb_boot(0, 0); // Comando de bootSel
                break;
        }
    }
}
