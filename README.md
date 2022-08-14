# Esteira ![Language grade: C](https://img.shields.io/badge/language-C-blue)

Uso de conversor AD para mudar intensidade do led conforme a resistência de um potenciômetro.

## Índice 

* [Descrição](#descrição)
* [Desenvolvimento](#desenvolvimento)

## Descrição

1. Considere inicialmente a figura abaixo onde os objetos são carregados por uma esteira e a sua presença é detectada por um sensor, gerando um pulso para cada objeto detectado. Uma caixa armazena os objetos e a sua missão é construir uma aplicação capaz de contar quantos objetos estão sendo colocados na caixa e interromper a esteira quando esse limite for alcançado. 

2. Considere que um pino de saída poderá indicar quando a esteira for parada. Por exemplo, você pode utilizar o LED da placa para representar essa situação.

3. A esteira só reinicializará a contagem e voltará a funcionar quando um operador apertar um botão, indicando que a caixa foi esvaziada. Você pode usar um pino de entrada para representar essa ação do operador.

![esteira](https://github.com/LeslyMontufar/Esteira/blob/main/img/esteira.png)

A contagem dos objetos deve ser feita através de um timer configurado para contagem de pulsos. PA0 pode ser o botão do operador e PC13 a indicação de esteira parada.

## Desenvolvimento
1. Timer foi configurado para receber pulsos externos, e pino o PA12 do timer foi configurado como entrada pull up.

![config-timer](https://github.com/LeslyMontufar/Esteira/blob/main/img/config_timer.png)

2. O temporizador é iniciado em `app_init()`, e no `app_loop()` verifica-se se o contador de pulsos ultrapassou o limite permitido.
```
void app_init(void){
	app_started = true;
	hw_input_capture_init();
}

void app_loop(void){
	uint16_t cnt = hw_input_capture_get();

	if(cnt > 10){
		hw_input_capture_set(0);
		hw_toggle_led();
	}
}
```
```
void hw_input_capture_init(void){
	HAL_TIM_Base_Start(&htim1);
	hw_input_capture_set(0);
}

uint16_t hw_input_capture_get(void){
	return __HAL_TIM_GET_COUNTER(&htim1);
}
```
3. Quando a esteira parar por exceder o limite, o operador pode fazer a esteira continuar pressionando o botão PA0.

```
void app_button_interrupt(void){
	static uint32_t debouncing_time_ms = 0;

	if(!app_started)
		return;

	if((hw_tick_ms_get() - debouncing_time_ms) >= APP_DEBOUNCING_TIME_MS){
		hw_toggle_led();
		hw_input_capture_set(0); // pra ter certeza
		debouncing_time_ms = hw_tick_ms_get();
	}
}
```

4. Circuito funcionando, com um led para verificar quando o botão, que simula os objetos passando, está pressionado.

![funcionando](https://github.com/LeslyMontufar/Esteira/blob/main/img/funcionando.jpg)
