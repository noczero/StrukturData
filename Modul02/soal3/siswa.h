#ifndef SISWA_H
#define SISWA_H
#include <string>

using namespace std;


struct siswa{
	string nama_siswa;
	double nilai[10];
};

bool input_nilai(siswa &s , int posisi, double nilai);

double rata2_nilai(siswa s);

void tampil_siswa(siswa s);
#endif
