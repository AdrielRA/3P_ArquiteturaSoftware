#include <iostream>
#include <locale>
using namespace std;

int soma(int *v) {
	int s = 0;
	for (int i = 0; i < sizeof(v); i++) { s += v[i]; }
	return s;
}

int soma_asm(int* v) {
	int n = sizeof(v);
	_asm {
		mov ebx, v
		mov ecx, n
		mov eax, 0
		repita:
			add eax, [ebx]
			add ebx,4
		loop repita
	}
}

void mult(int *v, int m) {
	int n = sizeof(v);
	_asm {
		mov ebx, v
		mov ecx, n
		repita:
			mov edx, m
			mov eax, [ebx]
			mul edx
			mov [ebx], eax
			add ebx, 4
		loop repita
	}
}

int main() {
	setlocale(LC_ALL, "");
	int vet[] = { 1,4,3,5 };

	cout << "Soma do vetor: " << soma_asm(vet) << endl;
	mult(vet, 2);
	for (int i = 0; i < sizeof(vet) / sizeof(int); i++)
	{
		cout << vet[i] << " ";
	}

	return 0;
}