#include <iostream>
#include <locale>
using namespace std;

void maiusculo(char* s) {
	// Transformar todos os caracteres em maiúsculos
	_asm {
		mov ebx,s
		inicio:
			cmp [ebx], 'a'
			jb proximo   // jumtp se menor - baixo
			cmp [ebx], 'z'
			ja proximo  // jump se maior - alto
			sub [ebx], 32
			
		proximo:
			add ebx, 1
			cmp [ebx], 0
			jnz inicio  // jump not zero
			// jmp inicio
	}
}

int contaChar(char *s, char c) {
	_asm {
		mov eax, 0
		mov ebx, s
		mov cl, c
		inicio:
			cmp [ebx], cl
			jnz proximo
			inc eax

		proximo:
			add ebx, 1
			cmp [ebx], 0
			jnz inicio
	}
}

void cripta(char *s, char l, char c) {
	_asm {
		mov ebx, s
		mov cl, l
		mov ch, c

		cmp cl, 97
		jb maiuscula
		cmp cl, 122
		ja proximo
		mov dl, cl
		sub dl, 32
		jmp verifica
		maiuscula:
			cmp cl, 65
			jb proximo
			cmp cl, 90
			ja proximo
			mov dl, cl
			add dl, 32
		verifica:
			cmp [ebx], cl
			je troca
			cmp [ebx], dl
			je troca
			jmp proximo

		troca:
			mov [ebx], ch

		proximo:
			add ebx,1
			cmp [ebx], 0
			jnz verifica
	}
}

int main() {
	setlocale(LC_ALL, "");
	char nome[50];
	cout << "Entre com o seu nome: ";
	cin.getline(nome, 50);

	maiusculo(nome);

	cout << "Nome: " << nome << endl;
	cout << "Número de espaços: " << contaChar(nome, ' ') << endl;

	cripta(nome, 'a', '*');

	cout << "Nome criptografado: " << nome << endl;

	return 0;
}