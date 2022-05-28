#include <string.h>
#include <math.h>
#include <iostream>
using namespace std;

unsigned long rabinKarpSort() {
	int iteration_compare = 0;
	const long len = 100000; //Задаем ограничение и длину строки и образа
	char x[len], y[len]; //Обновляем символьные массивы для работы с образом и строкой
	setlocale(LC_CTYPE, "RUS");
	cout << "Введите строку для поиска: ";
	cin.getline(y, len);
	cout << "Введите слово для поиска: "; cin >> x;
	cout << y << endl;
	long n = strlen(y); // определяем длину строки
	long m = strlen(x); // определяем длину образа
	long hx = 0, pos;
	for(int i = 0; i < m; i++) hx = hx + x[i]; // находим значение хеш-функции для образа, складывая аски коды всех символов
	cout << hx << endl;
	bool found = false; // флаг наличия вхождения
	for(int i = 0; i < n; i++) {
		iteration_compare++;
		long hy = 0;
		for(int j = i; j < m + i; j++) hy = hy + y[j]; // находим значение хеш-функций для строки
		//cout << hy << endl;
		if(hx == hy) {
			iteration_compare++;
			found = true; pos = i; // если значения хеш-функций образа и строки в i-ой позиции совпадают
			for(int j = 0; j < m; j++) //проверяем  посимвольно совпадение на случай холостого срабатывания из-за коллизии
				if(x[j] != y[i + j]) {
					iteration_compare++;
					found = false; break;
				}
		}
	}
	if(found) cout << "Слово найдено в " << pos << "позиции" << endl;
	else cout << "Нет совпадения!!!" << endl;
	printf("%d\n", iteration_compare);
	system("pause");
	return 0;
}

int main() {
	rabinKarpSort();
}
