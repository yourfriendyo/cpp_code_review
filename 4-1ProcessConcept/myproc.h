0000000000001189 <main>:
  118d:	 push   %rbp
  118e:	 mov    %rsp,%rbp
  1191:	 callq  1090 <fork@plt>
  1196:	 test   %eax,%eax
  1198:	 jne    11e6 <main+0x5d>
  119a:	 mov    0x2e74(%rip),%eax  
  11a0:	 lea    0x2e6d(%rip),%rdx  
  11a7:	 mov    %eax,%esi
  11a9:	 lea    0xe58(%rip),%rdi   
  11b0:	 mov    $0x0,%eax
  11b5:	 callq  1070 <printf@plt>
  11ba:	 movl   $0xc8,0x2e50(%rip) 
  11c1:	 
  11c4:	 mov    0x2e4a(%rip),%eax  
  11ca:	 lea    0x2e43(%rip),%rdx  
  11d1:	 mov    %eax,%esi
  11d3:	 lea    0xe5e(%rip),%rdi   
  11da:	 mov    $0x0,%eax
  11df:	 callq  1070 <printf@plt>
  11e4:	 jmp    1210 <main+0x87>
  11e6:	 mov    $0x1,%edi
  11eb:	 callq  1080 <sleep@plt>
  11f0:	 mov    0x2e1e(%rip),%eax  
  11f6:	 lea    0x2e17(%rip),%rdx  
  11fd:	 mov    %eax,%esi
  11ff:	 lea    0xe62(%rip),%rdi    
  1206:	 mov    $0x0,%eax
  120b:	 callq  1070 <printf@plt>
  1210:	 mov    $0x0,%eax
  1215:	 pop    %rbp
  1216:	 retq   
  1217:	 nopw   0x0(%rax,%rax,1)
