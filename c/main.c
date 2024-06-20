#include <stdio.h>
#include <string.h>
void literal(char sentence[],char word[]){
	int i=0,j=0;
    while(sentence[i]!='\0'){
		if (sentence[i]==word[j]){
    		j++;
    		i++;
		}
		else{
			i++;
			j=0;
		}
		if (word[j]=='\0'){
			printf("Found!\n");
			printf("Index: %d\n", i-j+1);
			break;
		}
		if(sentence[i]=='\0') 
		printf("Not Found!\n");
	}
}
void special(char sentence[],char word[]){
	int i=0,j=0;
	while(sentence[i]!='\0'){
		if(word[j]=='<' && sentence[i]>='0' && sentence[i]<='9'){
			j++;
    		i++;
		}
		else if(word[j]=='>' && (sentence[i]>='a' && sentence[i]<='z' || sentence[i]>='A' && sentence[i]<='Z')){
			j++;
    		i++;
		}
		else if(word[j]=='_' && sentence[i]!=' '){
			j++;
    		i++;
		}
		else{
			i++;
			j=0;
		}
		if (word[j]=='\0'){
			printf("Found!\n");
			printf("Index: %d\n", i-j+1);
			break;
		}
		if(sentence[i]=='\0') 
		printf("Not Found!\n");
	}
}
int main(){
	char sentence[1028],word[1028];
	int a,i=0,b;
	
	printf("Please enter a sentence: ");
	gets(sentence);
	
	printf("Please enter how many searches you want to make: ");
	scanf("%d", &b);
	
	while(i<b){
		printf("Please enter the search-text: ");
	    scanf("%s", word);
	    
	    printf("Please enter if the search is literal (1) or special (0): ");
	    scanf("%d", &a);
	    
		if(a==0){
			special(sentence,word);
		}
		else if(a==1){
			literal(sentence,word);
		}
		i++;
	}
	
	return 0;
}