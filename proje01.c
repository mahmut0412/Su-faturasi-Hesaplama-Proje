#include <stdio.h>

int main() {
	char Baska_Abone;
	int  Abone_Tipi_Kodu, Onceki_Sayac_Degeri, Simdiki_Sayac_Degeri,Gun_Sayisi;
	int Abone_Say_Konut = 0, Abone_Say_Isyeri = 0, Abone_Say_Kamu_Kurumu = 0, Abone_Say_Turistik_Tesis = 0;
	int Toplam_abone;
	int Su_Tuketim_Miktari;
	float Su_Tuketim_Ucreti;
	float Fatura_Tutari;
	float KDV_Tutari;
	float Atik_Su_Ucreti;
	int Toplam_Miktari_Konut =0, Toplam_Gun_Sayisi_Konut =0;
	int Toplam_Miktari_Isyeri = 0, Toplam_Gun_Sayisi_Isyeri = 0;
	int Toplam_Miktari_Kamu_Kurumu = 0, Toplam_Gun_Sayisi_Kamu_Kurumu = 0;
	int Toplam_Miktari_Turistik_Tesis = 0, Toplam_Gun_Sayisi_Turistik_Tesis = 0;
	/*2*/
	float Gunluk_Ort_Tuk_Konut, Gunluk_Ort_Tuk_Isyeri, Gunluk_Ort_Tuk_Kamu_Kurumu, Gunluk_Ort_Tuk_Turistik_Tesis;
	int kademeyi_asmayan_konut, Toplam_kademeyi_asmayan_konut=0;
	/*3*/
	int kademeyi_asan_Isyeri, Toplam_kademeyi_asan_Isyeri = 0;
	/*4*/
	float yuksek_Gunluk_Ort_Tuk_Konut = 0;
	/*5*/
	int yuksek_Su_Tuketim_Miktari=0, yuksek_Abone_Tipi_Kodu=0 ;
	float yuksek_Su_Tuketim_Ucreti=0;
	/*6*/
	int yuksek_Atik_Su_Ucreti_Miktari = 0, yuksek_Atik_Su_Ucreti_Tipi = 0;
	float yuksek_Atik_Su_Ucreti = 0;
	/*8*/
	float Toplam_Atik_Su_Ucreti_Konut=0, Toplam_Atik_Su_Ucreti_Isyeri=0, Toplam_Atik_Su_Ucreti_Kamu_Kurumu=0, Toplam_Atik_Su_Ucreti_Turistik_Tesis=0;
	/*9*/
	float Toplam_Atik_Su_Ucreti=0;
	/*10*/
	float Toplam_KDV_Tutari=0;
	do {

			do {
				printf("\n-Abone tipi kodu:\n1: konut\n2: isyeri\n3: kamu kurumu\n4: turistik tesis\n");
				scanf("%d", &Abone_Tipi_Kodu);
				if (Abone_Tipi_Kodu > 0 && Abone_Tipi_Kodu < 5) {
					do {
						printf("\nOnceki Sayac Degeri:\n");
						scanf("%d", &Onceki_Sayac_Degeri);
					} while (Onceki_Sayac_Degeri < 0);
					do {
						printf("\nSimdiki Sayac Degeri:\n");
						scanf("%d", &Simdiki_Sayac_Degeri);
					} while (Simdiki_Sayac_Degeri < Onceki_Sayac_Degeri);
					do {
						printf("\nGun sayisini girin:\n");
						scanf("%d", &Gun_Sayisi);
					} while (Gun_Sayisi <= 0);
					Su_Tuketim_Miktari = Simdiki_Sayac_Degeri - Onceki_Sayac_Degeri;
				}
				switch (Abone_Tipi_Kodu)
				{
				case(1):
					Abone_Say_Konut++;
					if (Su_Tuketim_Miktari <= ((13 * Gun_Sayisi) / 30.0)) {
						Su_Tuketim_Ucreti = Su_Tuketim_Miktari * 2.24;
					}
					else if (Su_Tuketim_Miktari <= (20 * (Gun_Sayisi / 30.0))) {
						Su_Tuketim_Ucreti = (13 * (Gun_Sayisi / 30.0)) * 2.24 + ((Su_Tuketim_Miktari - (13 * (Gun_Sayisi / 30.0) )) * 5.78);
					}
					else {
						Su_Tuketim_Ucreti = (13 * Gun_Sayisi / 30.0 * 2.24) + ((7 * Gun_Sayisi / 30.0) * 5.78) + ((Su_Tuketim_Miktari - 20 * (Gun_Sayisi / 30.0)) * 9.33);
					}
					Toplam_Miktari_Konut += Su_Tuketim_Miktari;
					Toplam_Gun_Sayisi_Konut += Gun_Sayisi;
					Atik_Su_Ucreti = 1.91 * Su_Tuketim_Miktari;
					KDV_Tutari = ((Su_Tuketim_Ucreti + Atik_Su_Ucreti) * 8) / 100;
					Fatura_Tutari = Su_Tuketim_Ucreti + Atik_Su_Ucreti + KDV_Tutari;
					/*2*/
					if (Gun_Sayisi / 30 > 0) {
						kademeyi_asmayan_konut = Su_Tuketim_Miktari / (Gun_Sayisi / 30);
					}
					else {
						kademeyi_asmayan_konut = Su_Tuketim_Miktari;
					}
					if (kademeyi_asmayan_konut < 14) {
						Toplam_kademeyi_asmayan_konut++;
					}
					/*4*/
					if (yuksek_Gunluk_Ort_Tuk_Konut < ((float)Su_Tuketim_Miktari / Gun_Sayisi)) {
						yuksek_Gunluk_Ort_Tuk_Konut = ((float)Su_Tuketim_Miktari / Gun_Sayisi);
					}
					/*8*/
					Toplam_Atik_Su_Ucreti_Konut += Su_Tuketim_Ucreti;
					printf("\nAbone tipi: Konut");
					break;
				case (2):
					Abone_Say_Isyeri++;
					if (Su_Tuketim_Miktari <= (10 * (Gun_Sayisi / 30.0))) {
						Su_Tuketim_Ucreti = Su_Tuketim_Miktari * 7.71;
					}
					else {
						Su_Tuketim_Ucreti = ((10 * (Gun_Sayisi / 30.0) * 7.71) + (Su_Tuketim_Miktari - (10 * (Gun_Sayisi / 30.0))) * 8.88);
					}
					Toplam_Miktari_Isyeri += Su_Tuketim_Miktari;
					Toplam_Gun_Sayisi_Isyeri += Gun_Sayisi;
					Atik_Su_Ucreti = 3.79 * Su_Tuketim_Miktari;
					KDV_Tutari = ((Su_Tuketim_Ucreti + Atik_Su_Ucreti) * 8) / 100;
					Fatura_Tutari = Su_Tuketim_Ucreti + Atik_Su_Ucreti + KDV_Tutari;
					/*3*/
					if ((Gun_Sayisi / 30) > 0) {
						kademeyi_asan_Isyeri = Su_Tuketim_Miktari / (Gun_Sayisi / 30);
					}
					else {
						kademeyi_asan_Isyeri = Su_Tuketim_Miktari;
					}
					if (kademeyi_asan_Isyeri > 10) {
						Toplam_kademeyi_asan_Isyeri++;
					}
					/*8*/
					Toplam_Atik_Su_Ucreti_Isyeri += Su_Tuketim_Ucreti;
					printf("\nAbone tipi: Isyeri");
					break;
				case (3):
					Abone_Say_Kamu_Kurumu++;
					Su_Tuketim_Ucreti = Su_Tuketim_Miktari * 6.64;
					Toplam_Miktari_Kamu_Kurumu += Su_Tuketim_Miktari;
					Toplam_Gun_Sayisi_Kamu_Kurumu += Gun_Sayisi;
					Atik_Su_Ucreti = 2.56 * Su_Tuketim_Miktari;
					KDV_Tutari = ((Su_Tuketim_Ucreti + Atik_Su_Ucreti) * 8) / 100;
					Fatura_Tutari = Su_Tuketim_Ucreti + Atik_Su_Ucreti + KDV_Tutari;
					/*8*/
					Toplam_Atik_Su_Ucreti_Kamu_Kurumu += Su_Tuketim_Ucreti;
					printf("\nAbone tipi: Kamu Kurumu");
					break;
				case (4):
					Abone_Say_Turistik_Tesis++;
					Su_Tuketim_Ucreti = Su_Tuketim_Miktari * 5.78;
					Toplam_Miktari_Turistik_Tesis += Su_Tuketim_Miktari;
					Toplam_Gun_Sayisi_Turistik_Tesis += Gun_Sayisi;
					Atik_Su_Ucreti = 1.91 * Su_Tuketim_Miktari;
					KDV_Tutari = ((Su_Tuketim_Ucreti + Atik_Su_Ucreti) * 8) / 100;
					Fatura_Tutari = Su_Tuketim_Ucreti + Atik_Su_Ucreti + KDV_Tutari;
					/*8*/
					Toplam_Atik_Su_Ucreti_Turistik_Tesis += Su_Tuketim_Ucreti;
					printf("\nAbone tipi: Kamu Kurumu");
					break;
				default:
					break;
				}
				if (Abone_Tipi_Kodu > 0 && Abone_Tipi_Kodu < 5) {
					printf("\nsu tuketim miktari: %d ton", Su_Tuketim_Miktari);
					printf("\nsu tuketim ucreti: %.2f TL", Su_Tuketim_Ucreti);
					printf("\natik su ucreti: %.2f TL", Atik_Su_Ucreti);
					printf("\nKDV tutari (%%8): %.2f TL", KDV_Tutari);
					printf("\nToplam fatura tutari: %.2f TL", Fatura_Tutari);
					/*5*/
					if (yuksek_Su_Tuketim_Ucreti <= Su_Tuketim_Ucreti) {
						yuksek_Su_Tuketim_Ucreti = Su_Tuketim_Ucreti;
						yuksek_Su_Tuketim_Miktari = Su_Tuketim_Miktari;
						yuksek_Abone_Tipi_Kodu = Abone_Tipi_Kodu;
					}
					/*6*/
					if (yuksek_Atik_Su_Ucreti <= Atik_Su_Ucreti) {
						yuksek_Atik_Su_Ucreti = Atik_Su_Ucreti;
						yuksek_Atik_Su_Ucreti_Miktari = Su_Tuketim_Miktari;
						yuksek_Atik_Su_Ucreti_Tipi = Abone_Tipi_Kodu;
					}
					/*9*/
					Toplam_Atik_Su_Ucreti += Atik_Su_Ucreti;
					/*10*/
					Toplam_KDV_Tutari += KDV_Tutari;
				}
			} while (Abone_Tipi_Kodu < 1 || Abone_Tipi_Kodu >4);

			do {
				printf("\nBaska Abone Var mi ? \n");
				scanf("%s", &Baska_Abone);

			} while ( (Baska_Abone != 'e' && Baska_Abone != 'E') && (Baska_Abone != 'h' && Baska_Abone != 'H'));
	} while (Baska_Abone != 'h' && Baska_Abone != 'H');

	/*1*/
	Toplam_abone = Abone_Say_Konut + Abone_Say_Isyeri + Abone_Say_Kamu_Kurumu + Abone_Say_Turistik_Tesis;
	(Toplam_Gun_Sayisi_Konut == 0) ? Gunluk_Ort_Tuk_Konut = 0 : (Gunluk_Ort_Tuk_Konut = (float)Toplam_Miktari_Konut / Toplam_Gun_Sayisi_Konut);
	(Toplam_Gun_Sayisi_Isyeri == 0) ? Gunluk_Ort_Tuk_Isyeri = 0 : (Gunluk_Ort_Tuk_Isyeri = (float)Toplam_Miktari_Isyeri / Toplam_Gun_Sayisi_Isyeri);
	(Toplam_Gun_Sayisi_Kamu_Kurumu == 0) ? Gunluk_Ort_Tuk_Kamu_Kurumu = 0 : (Gunluk_Ort_Tuk_Kamu_Kurumu = (float)Toplam_Miktari_Kamu_Kurumu / Toplam_Gun_Sayisi_Kamu_Kurumu);
	(Toplam_Gun_Sayisi_Turistik_Tesis == 0) ? Gunluk_Ort_Tuk_Turistik_Tesis = 0 : (Gunluk_Ort_Tuk_Turistik_Tesis = (float)Toplam_Miktari_Turistik_Tesis / Toplam_Gun_Sayisi_Turistik_Tesis);
	printf("\n\n1) Abone Tipi\t  Abone Say\tYuzde\t  Gunluk Ort Tuk");
	printf("\n   Konut\t  %d        \t%% %.2f\t  %.2f ton", Abone_Say_Konut, (Abone_Say_Konut* 100.0)/ Toplam_abone, Gunluk_Ort_Tuk_Konut);
	printf("\n   Isyeri\t %d        \t%% %.2f\t  %.2f ton", Abone_Say_Isyeri, (Abone_Say_Isyeri * 100.0) / Toplam_abone, Gunluk_Ort_Tuk_Isyeri);
	printf("\n   Kamu Kurumu\t  %d        \t%% %.2f\t  %.2f ton", Abone_Say_Kamu_Kurumu, (Abone_Say_Kamu_Kurumu * 100.0) / Toplam_abone, Gunluk_Ort_Tuk_Kamu_Kurumu);
	printf("\n   Turistik Tesis %d        \t%% %.2f\t  %.2f ton", Abone_Say_Turistik_Tesis, (Abone_Say_Turistik_Tesis * 100.0) / Toplam_abone, Gunluk_Ort_Tuk_Turistik_Tesis);
	/*2*/
	printf("\n\n2) Aylik su tuketim miktari, 1. kademeyi asmayan konut abonelerinin:");
	printf("\nsayisi: %d\nyuzdesi: %%%.2f ", Toplam_kademeyi_asmayan_konut, (Toplam_kademeyi_asmayan_konut * 100.0) / Abone_Say_Konut);
	/*3*/
	printf("\n\n3) Aylik su tuketim miktari, 1. kademeyi asan isyeri abonelerinin:");
	printf("\nsayisi: %d\nyuzdesi: %%%.2f ", Toplam_kademeyi_asan_Isyeri, (Toplam_kademeyi_asan_Isyeri * 100.0) / Abone_Say_Isyeri);
	/*4*/
	printf("\n\n4) Gunluk ortalama su tuketim miktari en yuksek olan konut tipi abonenin gunluk ortalama su tuketim miktari: %.2f ton", yuksek_Gunluk_Ort_Tuk_Konut);
	/*5*/
	printf("\n\n5) Aylik su tuketim ucreti en yuksek olan abonenin:");
	printf("\nabone tipi:  ");
	switch (yuksek_Abone_Tipi_Kodu)
	{
	case(1):
		printf("Konut");
		break;
	case(2):
		printf("Isyeri");
		break;
	case(3):
		printf("Kamu Kurumu");
		break;
	case(4):
		printf("Turistik Tesis");
		break;
	default:
		printf("Yok");
		break;
	}
	printf("\naylik su tuketim miktari: %d ton", yuksek_Su_Tuketim_Miktari);
	printf("\nodedigi aylik su tuketim ucreti: %.2f TL", yuksek_Su_Tuketim_Ucreti);
	/*6*/
	printf("\n\n6) Aylik atik su ucreti en yuksek olan abonenin:");
	printf("\nabone tipi:  ");
	switch (yuksek_Atik_Su_Ucreti_Tipi)
	{
	case(1):
		printf("Konut");
		break;
	case(2):
		printf("Isyeri");
		break;
	case(3):
		printf("Kamu Kurumu");
		break;
	case(4):
		printf("Turistik Tesis");
		break;
	default:
		printf("Yok");
		break;
	}
	printf("\naylik su tuketim miktari: %d ton", yuksek_Atik_Su_Ucreti_Miktari);
	printf("\nodedigi aylik atik su ucreti:  %.2f TL", yuksek_Atik_Su_Ucreti);
	/*7*/
	printf("\n\n7) Abone Tipi\t  Toplam Su Tuk Miktari");
	printf("\n   Konut\t  %d ton", Toplam_Miktari_Konut);
	printf("\n   Isyeri\t  %d ton", Toplam_Miktari_Isyeri);
	printf("\n   Kamu Kurumu\t  %d ton", Toplam_Miktari_Kamu_Kurumu);
	printf("\n   Turistik Tesis %d ton", Toplam_Miktari_Turistik_Tesis);
	printf("\n\n   Toplam\t  %d ton", Toplam_Miktari_Konut+ Toplam_Miktari_Isyeri+ Toplam_Miktari_Kamu_Kurumu+ Toplam_Miktari_Turistik_Tesis);
	/*8*/
	printf("\n\n8) Abone Tipi\t  Toplam Su Tuk Ucreti");
	printf("\n   Konut\t  %.2f TL", Toplam_Atik_Su_Ucreti_Konut);
	printf("\n   Isyeri\t  %.2f TL", Toplam_Atik_Su_Ucreti_Isyeri);
	printf("\n   Kamu Kurumu\t  %.2f TL", Toplam_Atik_Su_Ucreti_Kamu_Kurumu);
	printf("\n   Turistik Tesis %.2f TL", Toplam_Atik_Su_Ucreti_Turistik_Tesis);
	printf("\n\n   Toplam\t  %.2f TL", Toplam_Atik_Su_Ucreti_Konut + Toplam_Atik_Su_Ucreti_Isyeri + Toplam_Atik_Su_Ucreti_Kamu_Kurumu + Toplam_Atik_Su_Ucreti_Turistik_Tesis);
	/*9*/
	printf("\n\n9) Tum abonelerden elde edilen aylik toplam atik su ucreti: %.2f TL", Toplam_Atik_Su_Ucreti);
	/*10*/
	printf("\n\n10) Devlete odenen aylik toplam KDV tutari: %.2f TL", Toplam_KDV_Tutari);
	return 0;
}
