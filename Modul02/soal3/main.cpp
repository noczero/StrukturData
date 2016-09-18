#include <iostream>
#include "siswa.cpp"

using namespace std;

int main() {
	siswa s;
	bool ok;

	for (int i = 0; i < 10; i++)
	{
		s.nilai[i] = -1;
	}

	s.nama_siswa = "Budi";

	ok = input_nilai(s, 1 , 90);
	cout << ok << endl;

	ok = input_nilai(s, 5 , 815);
	cout << ok << endl;

	ok = input_nilai(s, 15 ,  75);
	cout << ok << endl;

	cout << rata2_nilai(s) << endl;

	tampil_siswa(s);

	return 0;
}