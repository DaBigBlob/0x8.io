
char* __strcp0(char *s, char *d, long l) {
    while (l--) *(d++)=*(s++);
    return d;
}

long __strlen0(char *s) {
    long n=0;
    while (*(s++)) n++;
    return n;
}

char* __strnmtch0(char *s, char *m) {
    char *mm=m;
    for (;*mm&&*s;s++) if (*mm==*s) mm++; else if (*m==*s) mm=m+1;
    return (*mm=='\0') ? s : m;
}

#include <stdlib.h> // i hate myself
#include <stdio.h> // i hate myself

int main(int argc, char **argv) {
    if (argc != 4) return 3;

    long bsz = __strlen0(*(argv+1));
    long msz = __strlen0(*(argv+2));
    long ssz = __strlen0(*(argv+3));
    char* buf = malloc(sizeof(char) * (bsz -msz +ssz));

    char *med = __strnmtch0(*(argv+1), *(argv+2));
    if (med==*(argv+2)) return 1;

    char *
    cur = __strcp0(*(argv+1), buf, (long)(med-*(argv+1)-msz));
    cur = __strcp0(*(argv+3), cur, ssz);
          __strcp0(med, cur, (long)(bsz-(med-*(argv+1))));
    fputs(buf, stdout);
    return 0;
}