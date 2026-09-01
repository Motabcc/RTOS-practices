#include <iostream>
#include <random>
//por padrão struct é público
struct Processo {
	int id;
	int tempo_execucao;
	bool terminou;
};
Processo criar_processo(int id, int tempo_execucao) {
	Processo p;
	p.id = id;
	p.tempo_execucao = tempo_execucao;
	p.terminou = false;
	return p;
}

int randoms() {
	//semente
	std::random_device rd;
	std::mt19937 gen(rd());

	//distribui eentre 500-3000 ms
	std::uniform_int_distribution<int> distrib(500, 3000);
	return distrib(gen);
}
void escalonamento(Processo& p id, int quantum) {
	if (p.terminou) {
		//finaliza o processo se ele terminar
		return;
	}
	//print
	std::cout << "\n[Processo " << p.id << "] Tempo restante: " << p.tempo_execucao << "ms | ";

	if (quantum < p.tempo_execucao) {
		std::cout << "Executando por " << quantum << "ms (Quantum expirou).";
		p.tempo_execucao -= quantum;
	}
	else {
		std::cout << "Executando por " << p.tempo_execucao << "ms e FINALIZADO.";
		p.tempo_execucao = 0;
		p.terminou = true;
	}
}

int main() {
	const int TOTAL_PROCESSOS = 8;
	const int QUANTUM = 1000;
	Processo vetor[TOTAL_PROCESSOS];

	// Criação dos processos
	for (int i = 0; i < TOTAL_PROCESSOS; ++i) {
		vetor[i] = criar_processo(i + 1, gerar_tempo_aleatorio());
		std::cout << "Processo " << vetor[i].id << " criado com " << vetor[i].tempo_execucao << "ms.\n";
	}

	std::cout << "\n--- Iniciando Escalonamento Round Robin (Quantum: " << QUANTUM << "ms) ---\n";

	bool todos_terminaram = false;
	while (!todos_terminaram) {
		todos_terminaram = true;

		for (int i = 0; i < TOTAL_PROCESSOS; ++i) {
			if (!vetor[i].terminou) {
				escalonamento(vetor[i], QUANTUM);
				todos_terminaram = false;
			}
		}
	}

