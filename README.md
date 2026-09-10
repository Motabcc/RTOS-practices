# ⚡ FreeRTOS — Práticas & Gerenciamento de Tarefas

![Linguagem C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![FreeRTOS](https://img.shields.io/badge/FreeRTOS-008080?style=for-the-badge&logo=freertos&logoColor=white)
![Visual Studio](https://img.shields.io/badge/Visual%20Studio-5C2D91?style=for-the-badge&logo=visual-studio&logoColor=white)
![Windows MSVC](https://img.shields.io/badge/Port-Win32_Simulator-blue?style=for-the-badge)

Este repositório é dedicado ao armazenamento de exercícios, exemplos e implementações práticas desenvolvidos na disciplina de **Sistemas Operacionais**. O objetivo central é compreender os conceitos de **Sistemas Operacionais de Tempo Real (RTOS)** na prática, explorando o ciclo de vida, prioridades e escalonamento de tarefas no **FreeRTOS** utilizando o simulador Win32 no Visual Studio.

---

## 📌 Conteúdo do Repositório

| Exercício / Módulo | Descrição das Atividades |
| :--- | :--- |
| **`Exemplo_01`** | Criando a primeira tarefa no FreeRTOS (`xTaskCreate`), loop infinito `for(;;)` e temporização com `vTaskDelay`. |
| **`Múltiplas Tarefas`** | Execução concorrente de tarefas com diferentes frequências de delay e calculando o tempo de execução do sistema através da contagem de *ticks* (`xTaskGetTickCount`). |
| **`Gerenciamento & Pilha`** | Monitoramento de uso de memória com `uxTaskGetStackHighWaterMark` e análise de prioridades do escalonador. |

---

## 🧠 Estrutura Padrão de uma Task

No FreeRTOS, cada tarefa se comporta como um programa independente rodando dentro de um loop infinito, liberando a CPU explicitamente com `vTaskDelay` para que o escalonador possa alternar o contexto:

```c
