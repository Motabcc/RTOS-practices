#include "FreeRTOS.h"
#include "task.h"
#include "basic_io.h"
#include <stdio.h>

//1.Criação de uma tarefa
//declaraçao da funçao e criação do ponteiro e da tarefa, obrigado a avisar q ela exite la embaixo pro compilador 
void vTaskNome(void* pvParameters);
void vTaskSobrenome(void* pvParameters);
void vTaskTempo(void* pvParameters);


void vTaskNome(void* pvParameters) {
	const char* nome = "Gabriel\n";
	//loop infinito com print e 1000 ticks de delay = 1 seg
	for (;;) {
		vPrintString(nome);
		vTaskDelay(500);
	}
	//auto-deleção = NULL,devemos deltar toda tarefa explicitamente
	vTaskDelete(NULL);
}
void vTaskSobrenome(void* pvParameters) {

	const char* sobrenome = "Mota\n";

	for (;;) {
		vPrintString(sobrenome);
		vTaskDelay(750);
	};

	vTaskDelete(NULL);
}
void vTaskTempo(void* pvParameters) {
	for (;;) {
		float tempo = (xTaskGetTickCount() * portTICK_PERIOD_MS) / 1000.0f;
			printf("Tempo: %.2f s\n", tempo);
		vTaskDelay(1000);
	}
	vTaskDelete(NULL);
}
/*
1. Ponteiro para a função que representa a tarefa;
2. String para identificar a tarefa no modo de depuração;
3. Tamanho da pilha da tarefa;
4. Parâmetros da tarefa;
5. Prioridade da tarefa;
6. Define um identificador para a tarefa

*/
//xTaskCreate(1,2,3,4,5,6)
void main_(void) {
	xTaskCreate(vTaskNome, "Primeiro Nome: ", 100, NULL, 1, NULL);
	xTaskCreate(vTaskSobrenome, "Sobrenome: ", 100, NULL, 1, NULL);
	xTaskCreate(vTaskTempo, "Tempo Local: ", 100, NULL, 1, NULL);

	//inicia o escalonador de tarefas
	vTaskStartScheduler();
	for (;;);

}