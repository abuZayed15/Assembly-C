#include <stdio.h>

// This is a very simple example of inline assembler.
// On AArch64, this code will calculate c=a+b then 
// print the value of c.
//
int main() {
	int a = 3;
	int b = 19;
	int c;

	// __asm__ ("assembley code template" : outputs : inputs : clobbers)
	//__asm__ ("add %0, %1, %2" : "=r"(c) : "r"(a),"r"(b) ); //modulus this
	// the above line is the assembly code that adds r1, r2 and stores the added value to r0.
	
	__asm__("udiv %0, %1, %2 ; msub %3, %1, %2, %0;" : "=r"(c) : "r"(a),"r"(b) :); //modulus

	printf("%d\n", c);
}
