
regi_param:     file format elf64-x86-64


Disassembly of section .init:

0000000000001000 <_init>:
    1000:	f3 0f 1e fa          	endbr64 
    1004:	48 83 ec 08          	sub    $0x8,%rsp
    1008:	48 8b 05 d9 2f 00 00 	mov    0x2fd9(%rip),%rax        # 3fe8 <__gmon_start__@Base>
    100f:	48 85 c0             	test   %rax,%rax
    1012:	74 02                	je     1016 <_init+0x16>
    1014:	ff d0                	call   *%rax
    1016:	48 83 c4 08          	add    $0x8,%rsp
    101a:	c3                   	ret    

Disassembly of section .plt:

0000000000001020 <.plt>:
    1020:	ff 35 9a 2f 00 00    	push   0x2f9a(%rip)        # 3fc0 <_GLOBAL_OFFSET_TABLE_+0x8>
    1026:	f2 ff 25 9b 2f 00 00 	bnd jmp *0x2f9b(%rip)        # 3fc8 <_GLOBAL_OFFSET_TABLE_+0x10>
    102d:	0f 1f 00             	nopl   (%rax)
    1030:	f3 0f 1e fa          	endbr64 
    1034:	68 00 00 00 00       	push   $0x0
    1039:	f2 e9 e1 ff ff ff    	bnd jmp 1020 <_init+0x20>
    103f:	90                   	nop

Disassembly of section .plt.got:

0000000000001040 <__cxa_finalize@plt>:
    1040:	f3 0f 1e fa          	endbr64 
    1044:	f2 ff 25 ad 2f 00 00 	bnd jmp *0x2fad(%rip)        # 3ff8 <__cxa_finalize@GLIBC_2.2.5>
    104b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

Disassembly of section .plt.sec:

0000000000001050 <printf@plt>:
    1050:	f3 0f 1e fa          	endbr64 
    1054:	f2 ff 25 75 2f 00 00 	bnd jmp *0x2f75(%rip)        # 3fd0 <printf@GLIBC_2.2.5>
    105b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

Disassembly of section .text:

0000000000001060 <_start>:
    1060:	f3 0f 1e fa          	endbr64 
    1064:	31 ed                	xor    %ebp,%ebp
    1066:	49 89 d1             	mov    %rdx,%r9
    1069:	5e                   	pop    %rsi
    106a:	48 89 e2             	mov    %rsp,%rdx
    106d:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
    1071:	50                   	push   %rax
    1072:	54                   	push   %rsp
    1073:	45 31 c0             	xor    %r8d,%r8d
    1076:	31 c9                	xor    %ecx,%ecx
    1078:	48 8d 3d 0e 01 00 00 	lea    0x10e(%rip),%rdi        # 118d <main>
    107f:	ff 15 53 2f 00 00    	call   *0x2f53(%rip)        # 3fd8 <__libc_start_main@GLIBC_2.34>
    1085:	f4                   	hlt    
    1086:	66 2e 0f 1f 84 00 00 	cs nopw 0x0(%rax,%rax,1)
    108d:	00 00 00 

0000000000001090 <deregister_tm_clones>:
    1090:	48 8d 3d 79 2f 00 00 	lea    0x2f79(%rip),%rdi        # 4010 <__TMC_END__>
    1097:	48 8d 05 72 2f 00 00 	lea    0x2f72(%rip),%rax        # 4010 <__TMC_END__>
    109e:	48 39 f8             	cmp    %rdi,%rax
    10a1:	74 15                	je     10b8 <deregister_tm_clones+0x28>
    10a3:	48 8b 05 36 2f 00 00 	mov    0x2f36(%rip),%rax        # 3fe0 <_ITM_deregisterTMCloneTable@Base>
    10aa:	48 85 c0             	test   %rax,%rax
    10ad:	74 09                	je     10b8 <deregister_tm_clones+0x28>
    10af:	ff e0                	jmp    *%rax
    10b1:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    10b8:	c3                   	ret    
    10b9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000000010c0 <register_tm_clones>:
    10c0:	48 8d 3d 49 2f 00 00 	lea    0x2f49(%rip),%rdi        # 4010 <__TMC_END__>
    10c7:	48 8d 35 42 2f 00 00 	lea    0x2f42(%rip),%rsi        # 4010 <__TMC_END__>
    10ce:	48 29 fe             	sub    %rdi,%rsi
    10d1:	48 89 f0             	mov    %rsi,%rax
    10d4:	48 c1 ee 3f          	shr    $0x3f,%rsi
    10d8:	48 c1 f8 03          	sar    $0x3,%rax
    10dc:	48 01 c6             	add    %rax,%rsi
    10df:	48 d1 fe             	sar    %rsi
    10e2:	74 14                	je     10f8 <register_tm_clones+0x38>
    10e4:	48 8b 05 05 2f 00 00 	mov    0x2f05(%rip),%rax        # 3ff0 <_ITM_registerTMCloneTable@Base>
    10eb:	48 85 c0             	test   %rax,%rax
    10ee:	74 08                	je     10f8 <register_tm_clones+0x38>
    10f0:	ff e0                	jmp    *%rax
    10f2:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
    10f8:	c3                   	ret    
    10f9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001100 <__do_global_dtors_aux>:
    1100:	f3 0f 1e fa          	endbr64 
    1104:	80 3d 05 2f 00 00 00 	cmpb   $0x0,0x2f05(%rip)        # 4010 <__TMC_END__>
    110b:	75 2b                	jne    1138 <__do_global_dtors_aux+0x38>
    110d:	55                   	push   %rbp
    110e:	48 83 3d e2 2e 00 00 	cmpq   $0x0,0x2ee2(%rip)        # 3ff8 <__cxa_finalize@GLIBC_2.2.5>
    1115:	00 
    1116:	48 89 e5             	mov    %rsp,%rbp
    1119:	74 0c                	je     1127 <__do_global_dtors_aux+0x27>
    111b:	48 8b 3d e6 2e 00 00 	mov    0x2ee6(%rip),%rdi        # 4008 <__dso_handle>
    1122:	e8 19 ff ff ff       	call   1040 <__cxa_finalize@plt>
    1127:	e8 64 ff ff ff       	call   1090 <deregister_tm_clones>
    112c:	c6 05 dd 2e 00 00 01 	movb   $0x1,0x2edd(%rip)        # 4010 <__TMC_END__>
    1133:	5d                   	pop    %rbp
    1134:	c3                   	ret    
    1135:	0f 1f 00             	nopl   (%rax)
    1138:	c3                   	ret    
    1139:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001140 <frame_dummy>:
    1140:	f3 0f 1e fa          	endbr64 
    1144:	e9 77 ff ff ff       	jmp    10c0 <register_tm_clones>

0000000000001149 <foo>:
    1149:	f3 0f 1e fa          	endbr64 
    114d:	55                   	push   %rbp
    114e:	48 89 e5             	mov    %rsp,%rbp
    1151:	89 7d fc             	mov    %edi,-0x4(%rbp)
    1154:	89 75 f8             	mov    %esi,-0x8(%rbp)
    1157:	89 55 f4             	mov    %edx,-0xc(%rbp)
    115a:	89 4d f0             	mov    %ecx,-0x10(%rbp)
    115d:	44 89 45 ec          	mov    %r8d,-0x14(%rbp)
    1161:	44 89 4d e8          	mov    %r9d,-0x18(%rbp)
    1165:	8b 55 fc             	mov    -0x4(%rbp),%edx
    1168:	8b 45 f8             	mov    -0x8(%rbp),%eax
    116b:	01 c2                	add    %eax,%edx
    116d:	8b 45 f4             	mov    -0xc(%rbp),%eax
    1170:	01 c2                	add    %eax,%edx
    1172:	8b 45 f0             	mov    -0x10(%rbp),%eax
    1175:	01 c2                	add    %eax,%edx
    1177:	8b 45 ec             	mov    -0x14(%rbp),%eax
    117a:	01 c2                	add    %eax,%edx
    117c:	8b 45 e8             	mov    -0x18(%rbp),%eax
    117f:	01 c2                	add    %eax,%edx
    1181:	8b 45 10             	mov    0x10(%rbp),%eax
    1184:	01 c2                	add    %eax,%edx
    1186:	8b 45 18             	mov    0x18(%rbp),%eax
    1189:	01 d0                	add    %edx,%eax
    118b:	5d                   	pop    %rbp
    118c:	c3                   	ret    

000000000000118d <main>:
    118d:	f3 0f 1e fa          	endbr64 
    1191:	55                   	push   %rbp
    1192:	48 89 e5             	mov    %rsp,%rbp
    1195:	48 83 ec 10          	sub    $0x10,%rsp
    1199:	6a 08                	push   $0x8
    119b:	6a 07                	push   $0x7
    119d:	41 b9 06 00 00 00    	mov    $0x6,%r9d
    11a3:	41 b8 05 00 00 00    	mov    $0x5,%r8d
    11a9:	b9 04 00 00 00       	mov    $0x4,%ecx
    11ae:	ba 03 00 00 00       	mov    $0x3,%edx
    11b3:	be 02 00 00 00       	mov    $0x2,%esi
    11b8:	bf 01 00 00 00       	mov    $0x1,%edi
    11bd:	e8 87 ff ff ff       	call   1149 <foo>
    11c2:	48 83 c4 10          	add    $0x10,%rsp
    11c6:	89 45 fc             	mov    %eax,-0x4(%rbp)
    11c9:	8b 45 fc             	mov    -0x4(%rbp),%eax
    11cc:	89 c6                	mov    %eax,%esi
    11ce:	48 8d 05 2f 0e 00 00 	lea    0xe2f(%rip),%rax        # 2004 <_IO_stdin_used+0x4>
    11d5:	48 89 c7             	mov    %rax,%rdi
    11d8:	b8 00 00 00 00       	mov    $0x0,%eax
    11dd:	e8 6e fe ff ff       	call   1050 <printf@plt>
    11e2:	b8 00 00 00 00       	mov    $0x0,%eax
    11e7:	c9                   	leave  
    11e8:	c3                   	ret    

Disassembly of section .fini:

00000000000011ec <_fini>:
    11ec:	f3 0f 1e fa          	endbr64 
    11f0:	48 83 ec 08          	sub    $0x8,%rsp
    11f4:	48 83 c4 08          	add    $0x8,%rsp
    11f8:	c3                   	ret    
