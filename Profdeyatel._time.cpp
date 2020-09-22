#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <math.h>

int mouth_to_days(int mouth, int day, bool vis){
	int days_return = 0 ;
	for (int i = 1; i< mouth; i++) 
		{	if( (i < 8) && (i % 2 == 1) ||((i>=8) && (i % 2 == 0)) ) days_return += 31 ;
			else if (i == 2) days_return += 28;
			else days_return += 30 ;
		}day ;
	if (vis) days_return++ ;
	return days_return ;
}
int zodiac (int days)
{ 	int i ;
for (i = 0; days>= 0; i++) 
	{ if ((i == 1) || (i== 2) || (i == 9) || (i == 10)) days -= 30 ;
	  else if ((i > 2) && (i< 9) && (i !=6))  days -= 31 ;
	  else if (i == 6) days -= 32 ;
	  else if (i== 0) days -= 20 ;
	  else if (i == 11) days -= 29 ;
	  else return 12 ;
	}
return i-1 ;		
}	
int main() {
	setlocale(LC_ALL, "Rus");
	int day,mouth,year, visocos_now, days_then, visocos_then, days_of_life, days_brd;
	time_t year_now, day_now ;
	bool vis = false ;
	char *zod[13] = {"Êîçåðîã", "Âîäîëåé", "Ðûáû", "Îâåí", "Òåëåö", "Áëèçíåöû",
				   "Ðàê", "Ëåâ", "Äåâà", "Âåñû", "Ñêîðïèîí", "Ñòðåëåö", "Êîçåðîã" } ;
	year_now = time (NULL)/31536000 + 1970;
	visocos_now = (year_now- 1972) /4 ;
	day_now = (int(ceil((time (NULL) / 86400.0))) % 365) - visocos_now  ;
	printf ("Âû çàïóñòèëè ïðîãðàììó \"Îðàêóë \" \n") ;
	printf ("Ïðåäóïðåæäåíèå:\n Äàííàÿ ïðîãðàììà íå óìååò ðàáîòàòü ñ ëþäüìè ñòàðøå %i ëåò \n", (year_now-1));
	do {
	printf ("Äëÿ êîððåêòíîé ðàáîòû ïðîãðàììû ââîäèòå öåëûå ÷èñëà áåç íåçíà÷àùåãî \"0\"\n") ;
	printf ("Ââåäèòå äåíü ðîæäåíèÿ: \n") ;
	scanf ("%i", &day) ;
	printf ("Ââåäèòå ìåñÿö ðîæäåíèÿ: \n") ;
	scanf ("%i", &mouth) ;  
	printf ("Ââåäèòå ãîä ðîæäåíèÿ: \n") ;
	scanf ("%i", &year) ;
	} 
	while ((day <= 0 || day >31) || (year <=0 || year>year_now) || (mouth <=0 || mouth>12) ) ;
	visocos_then = 0;
	for (int i = year; i<year_now; i++) {
		if (((i % 4 == 0) && (i % 100 != 0)) || (i % 400 == 0)) visocos_then++ ;
	}
	if (((year % 4 ==0) && (year % 100 != 0)) || (year % 400 == 0))
		vis = true;
	if ( (vis) && (mouth > 2) ) visocos_then-- ;	
	days_brd = mouth_to_days(mouth,day, vis) ;
	days_of_life = (year_now-1 - year)*365 +visocos_then + 
	(365-days_brd)+day_now ;
	if (vis) days_of_life++ ;
	printf ("Âàø çîäèàê: %s\n",zod [zodiac(days_brd)] ) ;
	printf("Âû ïðîæèëè %i äíåé\n", days_of_life) ;
	if (vis) printf ("%i - âèñîêîñíûé ãîä\n", year); 
	else ("%i - íåâèñîêîñíûé ãîä\n", year);
	return 0;
}
