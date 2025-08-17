
// idk why i wrote this; please ignore

long __strn2long(char *s) {
    long a=0, t=1;
    for (char* ss=s;(*(ss++));) t*=10; t/=10;
    for (;t;t/=10) a+=(*(s++)-48)*t;
    return a;
}