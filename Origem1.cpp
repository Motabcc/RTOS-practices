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

int randoms(){
	//semente
	std::random_device rd;
	std::mt19937 gen(rd());

	//distribui eentre 500-3000 ms
	std::uniform_int_distribution<int> distrib(500, 3000);
	return distrib(gen);
}
int escalonamento(int id,int quantum){
	Processo p;
	switch (!terminou) {
	case quantum < tempo_execucao: 
		
		executar_processo(id,quantum)
		break;
	case quantum > tempo_execucao:
		executar_processo(id, tempo_execucao)
			break;
	break;
	default: 
		#include <iostream>
#include <random>
//por padrão struct é público
struct Processo {
	int id;
	int tempo_execucao;
	int terminou;
};
Processo executar_processo(int id, int tempo_execucao) {
	Processo p;
	p.id = id;
	p.tempo_execucao = tempo_execucao;
	p.terminou = 0;
	return p;
}

int randoms(){
	//semente
	std::random_device rd;
	std::mt19937 gen(rd());

	//distribui eentre 500-3000 ms
	std::uniform_int_distribution<int> distrib(500, 3000);
	return distrib(gen);
}
int escalonamento(int id,int quantum){
	switch (!terminou) {
	case quantum < tempo_execucao: 	
		executar_processo(id, quantum);
		tempo_execucao = quantum - tempo_execucao;
		
		break;
	case quantum > tempo_execucao:
		executar_processo(id, tempo_execucao);
			break;
	default:
		executar_processo(id, quantum);
		break;
	}
}
int main() {
	Processo vetor[8];
	for (int i = 0;i < 8;++i) {
		vetor[i]= status_processo(i + 1, randoms());

	}
}
	}
}
int main() {
	Processo vetor[8];
	for (int i = 0;i < 8;++i) {
		vetor[i]= status_processo(i + 1, randoms());

	}
}