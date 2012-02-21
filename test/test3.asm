%define SYS_write 4
%define SYS_read 3
%define SYS_exit 1
%define MY_bufsize 4096 ; the only thing I changed
section .text
global _start
_start:
       sub     esp,MY_bufsize
       mov     ecx,esp
       call    readbuf
       jmp     skipread
loopy:
       cmp     esi,edx
       jne     skipread
       call    writebuf
       call    readbuf
skipread:
       cmp     BYTE [ecx+esi],'4'
       lea     esi,[esi+1]
       jne     loopy
       cmp     BYTE [ecx+esi],'2'
       lea     esi,[esi+1]
       jne     loopy
       lea     edx,[esi-2]
       call    writebuf
       mov     eax,SYS_exit
       xor     ebx,ebx
       int     80h
readbuf:
       mov     eax,SYS_read
       xor     ebx,ebx
       mov     edx,MY_bufsize
       int     80h
       mov     edx,eax
       xor     esi,esi
       ret
writebuf:
       mov     eax,SYS_write
       mov     ebx,1
       int     80h
       ret
