#include <iostream>
#include <locale>
using namespace std;

int fat(int x) {
	_asm {
		mov eax, x
		mov ecx, eax
		dec ecx
		repita :
		mul ecx
			loop repita
	}
}

int main() {
	setlocale(LC_ALL, "");
	int n;
	cout << "Informe um nº inteiro: ";
	cin >> n;

	cout << "Fatorial: " << fat(n) << endl;

	return 0;
}