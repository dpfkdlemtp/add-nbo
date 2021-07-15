#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <netinet/in.h>


int main(int argc, char *argv[]){
    
    uint32_t n1, n2;

    FILE* in1 = fopen(argv[1], "rb");
    FILE* in2 = fopen(argv[2], "rb");


    fread(&n1, 1, 4, in1);
    fread(&n2, 1, 4, in2);
    
    n1 = htonl(n1);
    n2 = htonl(n2); 
             
    printf("%u(0x%x) + %u(0x%x) = %u(0x%x)\n", n1, n1, n2, n2, n1+n2, n1+n2);
    
    fclose(in1);
    fclose(in2);
    
    return 0;
}

