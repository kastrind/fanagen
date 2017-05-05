/* Kastrinakis Dimitrios, July 2008
 * Department of Computer Science
 * University of Crete */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define BUF 		50
#define NUMS		100
#define LIMIT 		10001
#define VOWELS_SOLO 	6
#define VOWELS_DUAL 	31
#define THREE_FOURTHS 	7500
#define HALF		5000
#define ONE_FOURTH	2500
#define CAR_NUMBER	20
#define CONSONANTS	20
#define POSTFIX_CONSONS 16
#define FOUR		4

void get_fname (char str[]);
int is_valid (char str[]);
int is_consonant (char letter);
void make_rand_seq (int sequence[]);
int is_allowed (char *CAR[], char fname_letter, char consonants[], int conson_number);

int main() {

	char fname[BUF] =	 "initinitinitinitinitinitinitinitinitinitinitinitin";
	char fantasy_name[BUF] = "initinitinitinitinitinitinitinitinitinitinitinitin";
	char postfix[FOUR];
	int i = 0;
	int y = 0;
	int r = 0;
	int z = 1;
	int look_ahead = 0;
	char selected_consonant;
	char  vowels_solo[VOWELS_SOLO] = {'a', 'e', 'i', 'o', 'u', 'y'};
	
	char *vowels_dual[VOWELS_DUAL] = {"aa", "ae", "ai", "ao", "au", "ay", 
					  "ee", "ea", "ei", "eo", "eu", "ey", 
  					  "ia", "ie", "io", "iu", "oo", "oa",
 					  "y", "oe", "oi", "ou", "oy", "ua", 
  					  "ue", "ui", "uo", "uy", "ya", "ye", "yo" };

    	char consonants[CONSONANTS] = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l',
					'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w',
  					'x', 'z'};
   
    	char *postfix_consons[POSTFIX_CONSONS] = {"f", "g", "th", "k", "l", "m", "n", "p", "ph", "r", "s", 					  "t","th", "x", "z", "ph"}; /*doubled the chance of 'nice' 'th' or 'ph' postfix!*/

  	 /* Consonant Adjacency Rules */
	char *CAR[CAR_NUMBER] = {"fjpqsx", "gjqsxz", "cqstx", "vx", "cjkqx", "cgkqswxz", "cdgstwxz", "cgjqwx", "*", "x", "x", "bfmx", "bcdfghjklmnpqrstvwxz", "x", "jxz", "cdjx", "cfjwx", "bcdfgjklmnpqrstuvwxz", "hjstz", "cjsx"};
   
    	int random_nums[NUMS];
    
    	make_rand_seq(random_nums);/*produce sequence of random nums*/

    	printf("What is your first name?\n");
    	get_fname(fname);
    	if (!is_valid(fname)) {printf("Invalid first name!\n"); return 0;}
	
    //////////////////////ALGORITHM////////////////////////////////////////
    
    	while (i < strlen(fname)) { /* until the end of fname */
	    look_ahead = i + 1;
	    
	    if (!is_consonant(fname[i])) { /*if we have a vowel then*/
		    if (random_nums[r++] < HALF ) { /*with a chance of 1/2*/
			/*put 2 vowels*/
			fantasy_name[y++] = vowels_dual[random_nums[r]%VOWELS_DUAL][0];
			fantasy_name[y] = vowels_dual[random_nums[r]%VOWELS_DUAL][1];
		    }else { 
			/*put 1 vowel*/
			fantasy_name[y] = vowels_solo[random_nums[r++]%VOWELS_SOLO];
		    }
		    
		    /*if there are not 2 consecutive consonants next*/
		    if (!is_consonant(fname[look_ahead])&&(!is_consonant(fname[look_ahead+1]))) {
			    
			    if ((random_nums[r++] > ONE_FOURTH)&&(random_nums[r++] < LIMIT)) {/*with a chance of 3/4*/
			    	/*put a consonant if allowed*/
			    	selected_consonant = random_nums[r++]%CONSONANTS;
			    	if (is_allowed(CAR, fname[i], consonants, selected_consonant)) {
					fantasy_name[y++] = consonants[selected_consonant];
			    	}
			    }
		    }
		   
	    } 
	    else { /*else if we have a consonant*/
		    
		    /*if we are not at the beginning of fname,
		    and if previous and  next letter are both vowels, then*/
		    if ((!is_consonant(fname[look_ahead]))&&(i>0)&&
			((!is_consonant(fname[i-1])))) {
			    
			    if (random_nums[r++] < THREE_FOURTHS) {/*with a chance of 3/4*/
			    	/*put a consonant if allowed*/
			    	selected_consonant = random_nums[r++]%CONSONANTS;
			    	if (is_allowed(CAR, fname[i], consonants, selected_consonant)) {
			    		fantasy_name[y++] = consonants[selected_consonant];
			    	}
			    }
		    }
		fantasy_name[y] = fname[i];
	    }
	    
	    i++;
	    y++;
	    fantasy_name[y] = '\0'; /*NULL termination*/
    }
    //////////////////////ALGORITHM////////////////////////////////////////
    
/////////////////////////////////POSTFIX PRODUCTION///////////////////////////
   	 if (random_nums[r++] > HALF ) { /*with a chance of 1/2*/
	    /*put 2 vowels*/
	    postfix[0] = vowels_dual[random_nums[r]%VOWELS_DUAL][0];
	    postfix[1] = vowels_dual[random_nums[r]%VOWELS_DUAL][1];
	    postfix[2] = '\0';
	    /*put a consonant (or two)*/
	    selected_consonant = random_nums[++r]%POSTFIX_CONSONS;
	    strcat(postfix, postfix_consons[selected_consonant]); 
	}else { 
	    /*put 1 vowel*/
	    postfix[0] = vowels_solo[random_nums[r++]%VOWELS_SOLO];
	    postfix[1] = '\0';
	    /*put a consonant (or two)*/
	    selected_consonant = random_nums[++r]%POSTFIX_CONSONS;
	    strcat(postfix, postfix_consons[selected_consonant]);
    	}
	
    	i=strlen(postfix)-1;
    	/*replace last chars of fname with the postfix*/
    	while (i>=0) { fantasy_name[y-z++] = postfix[i--]; }
////////////////////////////POSTFIX PRODUCTION/////////////////////////////////

    	printf("Fantasy name: %s\n", fantasy_name);
    	return 0;
}


void get_fname (char str[]) {
	int i = 0;
	while(i<BUF) {
		str[i] = getc(stdin);
		if (str[i] == '\n') {str[i] = '\0'; break;}
		i++;
	}
}

int is_valid (char str[]) {
	int i = 0;
	if(str[0] == '\0') {return 0;}
	
	while (i < strlen(str)) {
		if (!isalpha(str[i])) {return 0;}
		i++;
	}
	return 1;
}

int is_consonant (char letter) {
	switch (letter) {
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
		case 'y':
			return 0;
			
			default: return 1;
	}
}

void make_rand_seq (int sequence[]) {
	long ltime = time(NULL);
	int utime  = (unsigned int) ltime/2;
	int z = 0;
	srand(utime);
	while(z<NUMS) { sequence[z++] = rand()%LIMIT; }
}

int is_allowed(char *CAR[], char fname_letter, char consonants[], int conson_number) {
	if(CAR[conson_number] == "*") return 1;
	else return (!strchr(CAR[conson_number], (int)fname_letter));
}
