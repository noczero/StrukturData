#include <iostream>
#include <string>
#include "siswa.h"

using namespace std;

bool input_nilai(siswa &s , int posisi, double nilai){

	if (posisi >= 0 && posisi <= 9 && nilai >= 0 && nilai <= 100){
		s.nilai[posisi] = nilai;
		return true;
	}	else {
		return false;
	}
}

double rata2_nilai(siswa s){
	int jumlahNilai = 0;
	int i = 0;
	double rata_rata, totalNilai;

	for (int i = 0; i < 10; i++)
	{
		/* code */
		if (s.nilai[i] >= 0 && s.nilai[i] <= 100)
		{
			/* code */
			jumlahNilai++;
			totalNilai += s.nilai[i];
		}
	}

	rata_rata = totalNilai / jumlahNilai;

	return rata_rata;
}

void tampil_siswa(siswa s) {
	int i = 0;
	cout << s.nama_siswa << endl;

	for (int i = 0; i < 10; i++)
	{
		/* code */
		if (s.nilai[i] >= 0 && s.nilai[i] <= 100)
		{
			cout << s.nilai[i];
		}
	}

	return;
}