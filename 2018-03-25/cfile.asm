
cfile.o:     file format elf32-i386


Disassembly of section .text:

00000000 <myUpper>:
__asm__(".code16gcc\n");
char myMessage[11]="AaBbCcDdEe";
void myUpper(){
   0:	66 55                	push   bp
   2:	66 89 e5             	mov    bp,sp
    for(int i=0;i<11;i++){
   5:	66 31 c0             	xor    ax,ax
        if(myMessage[i]>='a'&&myMessage[i]<='z')
   8:	67 8a 90 00 00       	mov    dl,BYTE PTR [bx+si+0x0]
   d:	00 00                	add    BYTE PTR [eax],al
   f:	67 66 8d 4a 9f       	lea    cx,[bp+si-0x61]
  14:	80 f9 19             	cmp    cl,0x19
  17:	77 0b                	ja     24 <myUpper+0x24>
            myMessage[i]=myMessage[i]+'A'-'a';
  19:	66 83 ea 20          	sub    dx,0x20
  1d:	67 88 90 00 00       	mov    BYTE PTR [bx+si+0x0],dl
  22:	00 00                	add    BYTE PTR [eax],al
    for(int i=0;i<11;i++){
  24:	66 40                	inc    ax
  26:	66 83 f8 0b          	cmp    ax,0xb
  2a:	75 dc                	jne    8 <myUpper+0x8>
    }
  2c:	66 5d                	pop    bp
  2e:	66 c3                	retw   
