#include <stdio.h>
#include <string.h>
int prev[2000+1];

static inline int min(int a, int b, int c) {
    int m = a;
    if (m > b) m = b;
    if (m > c) m = c;
    return m;
}

static inline int edit_distance(char *s, char *t, int n, int m) {
	int i,j;
	int cc,cp;
	int pp,pc;
	//initialise array
	for(i=0;i<=m;i++) {
		prev[i]=i;
	} 
	j=1;
	while(j<=n) {
		cp=j;
		i=1;
		while(i<=m) {
			//we only need one array
			//just overwrite previous values as we move along
			pp=prev[i-1];
			prev[i-1]=cp;
			pc=prev[i];
			if(s[j-1]==t[i-1]) {
				cc=min(pp,pc+1,cp+1);
			} else {
				cc=min(pp+1,pc+1,cp+1);
			}
			cp=cc;
			i++;
		}
		j++;
	}	
	return cc ;
}
int main() {
	char s[2000+1];
	char t[2000+1];
	char a;
	int i;
	int n,m;
	int ncases;
	scanf("%d",&ncases);
	while(ncases>0) {
		scanf("%s",s);
		scanf("%s",t);
		n=strlen(s);
		m=strlen(t);
		if(m==0 & n==0) { printf("0\n"); }
		else if (m==0) { printf("%d\n",n); }
		else if (n==0) { printf("%d\n",m); }
		else if (n>m) { printf("%d\n",edit_distance(t,s,m,n)); } 
		else { printf("%d\n",edit_distance(s,t,n,m));}
		ncases--;	
	}
	return 0;
}
