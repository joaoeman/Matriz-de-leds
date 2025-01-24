// Definição de tipo da estrutura que irá controlar a cor dos LED's
typedef struct {
    double red;
    double green;
    double blue;
}Led_config;

typedef Led_config RGB_cod;

// Definição de tipo da matriz de leds
typedef Led_config Matriz_leds_config[5][5]; 

uint32_t gerar_binario_cor(double red, double green, double blue);

uint configurar_matriz(PIO pio);

void imprimir_desenho(Matriz_leds_config configuracao, PIO pio, uint sm);

RGB_cod obter_cor_por_parametro_RGB(int red, int green, int blue);