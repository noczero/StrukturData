#include <cstdio>
	
void pengurangan(int pmb1, int pny1, int pmb2, int pny2 , int &pemb, int &peny) {
	if (pny1 == pny2) {
		pemb = pmb1 - pmb2;	
		peny = pny1 - pny2;	
	}
	else if (pny1 != pny2) {
		peny = pny1 * pny2;
		pemb = (peny / pny1) * pmb1 -  (peny / pny2) * pmb2;
	}
}

void swap(int &x , int &y) {
	int temp; 
	temp = x;
	x = y;
	y = temp;

	return;
}

void pembagian(int pmb1, int pny1, int pmb2, int pny2 , int &pemb, int &peny) {
	swap(pmb2,pny2);
	pemb = pmb1 * pmb2;
	peny = pny1 * pny2;
}

int main() {
	int pemSatu, penySatu, pembDua, penyDua, hasilPemb , hasilPeny , hasilbagiPemb , hasilbagiPeny; 
	scanf("%d %d %d %d", &pemSatu , &penySatu , &pembDua , &penyDua);
	pengurangan(pemSatu, penySatu, pembDua, penyDua , hasilPemb , hasilPeny );
	pembagian(pemSatu, penySatu, pembDua, penyDua , hasilbagiPemb , hasilbagiPeny);
	printf("Hasil Pengurangan \t : %d  / %d\n", hasilPemb , hasilPeny);
	printf("Hasil Pembagian \t : %d  / %d\n", hasilbagiPemb , hasilbagiPeny);
	return 0;
}