
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

// Jumlah Laki2 Maupun Perempuan
#define N 5
//disini m1 adalah pasangan yang berpasangan duluan
bool wMilihM1dariM(int prefer[2*N][N], int w, int m, int m1)
{
	// mengecek apakah w lebih suka m atau m1 yang terlebih dahulu berpasangan
	for (int i = 0; i < N; i++)
	{

		// lebih suka m1
		if (prefer[w][i] == m1)
			return true;


		// lebih suka m
		if (prefer[w][i] == m)
		return false;
	}
}

//di program ini laki2 dinomori dari 0 sampai 4...perempuan dari 5 sampai 9
void stableMarriage(int prefer[2*N][N])
{

	int wPartner[N]; //yang sedang berpasangan dengan wanita


	bool mFree[N]; //apakah orang tsb free...bila false berarti free

	// inisiasi semua laki2 dan perempuan free
	memset(wPartner, -1, sizeof(wPartner));
	memset(mFree, false, sizeof(mFree));
	int freeCount = N;

	// apabila laki2 free
	while (freeCount > 0)
	{
		// looping laki2
		int m;
		for (m = 0; m < N; m++)
			if (mFree[m] == false)
				break;

		// laki2 memilih satu persatu sesuai keinginannya
		for (int i = 0; i < N && mFree[m] == false; i++)
		{
			int w = prefer[m][i];

// apabila perempuan free maka mereka berpasangan. Tetapi pasangan //bisa berubah nantinya
			if (wPartner[w-N] == -1)
			{
				wPartner[w-N] = m;
				mFree[m] = true;
				freeCount--;
			}

			else // apabila perempuan tidak free
			{
				// mencari laki2 yang telah berpasagan dengan perempuan tsb
				int m1 = wPartner[w-N];

				// memanggil fungsi yang diatas
				if (wMilihM1dariM(prefer, w, m, m1) == false)
				{
					wPartner[w-N] = m;
					mFree[m] = true;
					mFree[m1] = false;
				}
			}
		}
	}


	// mencetak hasil
	cout << "Perempuan     Laki2" << endl;
	for (int i = 0; i < N; i++)
	cout << " " << i+N << "\t\t" << wPartner[i] << endl;
}

int main()
{
	int prefer[2*N][N] = {
//yang terdapat di worksheet
		{6, 5, 8, 9, 7},
		{8, 6, 5, 7, 9},
		{6, 9, 7, 8, 5},
		{5, 8, 7, 6, 9},
		{6, 8, 5, 9, 7},
		{4, 0, 1, 3, 2},
		{2, 1, 3, 0, 4},
		{1, 2, 3, 4, 0},
		{0, 4, 3, 2, 1},
		{3, 1, 4, 3, 0}
	};
	stableMarriage(prefer);

	return 0;
}
