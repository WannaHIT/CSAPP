```bash
# 通过管道来将ans里的Byte码变成字符串传入需要攻击的程序中，-q是不发信息给服务器
./hex2raw < ans.txt | ./ctarget -q # 这个命令不行，害我浪费了时间cao

# 一分为二比较好
# 先将答案写入ans里面，再通过hex2raw重定向到对应题目的txt文件里面
./hex2raw < ans.txt > c01.txt # 比如c的第一题
./ctarget -q -i c01.txt 
```

```bash
objdump -d ctarget >> ctarget.s # 得到汇编代码
# 还有即使注意x86 小端字节序
```

```bash
# 或者，利用gdb调试查看反汇编代码
# 但是遇到了问题，进入gdb之后没有反应
(gdb) l
83	main.c: No such file or directory. # 只有这个，没有代码
# solution！！！！！！！！！
# GDB 调试的时候，执行 run 的时候一定带上任意输入文件，否则会运行不到断点处
# 这样就可以查看寄存器的值了：
# method1：
gdb --args ./ctarget -q -i c01.txt 
(gdb) b getbuf
(gdb) run
# method2：
gdb ./ctarget
(gdb) set args -q -i c01.txt
(gdb) b getbuf
(gdb) run



# disassamble asm也是空的
# 这时候可以
(gdb) disassemble main
(gdb) b main
(gdb) b *0x401588 # 在该地址处插入断点
(gdb) run
(gdb) ni 


# 这时候可以 
(gdb) info functions # 查看有那些函数
# 然后选择一个函数名进行反汇编：
(gdb) disassemble <function_name>

```

```bash
# level 1 . Use vscode for file ctarget.s
# -------------------------------------
# 在getbuf的汇编代码中
0x00000000004017b9 <+17>:	add    $0x28,%rsp
0x00000000004017bd <+21>:	ret
# 这个ret其实就是pop $rip,
# rip寄存器存储的就是返回地址
# --------------------------------------

# file : ctarget.s
# 通过函数查找来解决这个问题
find test() -> getbuf() -> ret
# 缓冲区随便填满，（注意不能是0xa，因为这是换行），然后填入touch1的首地址
```

```bash
# level 2 . Use vscode 
# 想办法查看栈帧
# 难点：如何将cookie的值传入%rdi寄存器，所以不能只是像上一题简单调用
# idea: touch2函数只有一个参数unsigned val
# -------------------------------------
# 在getbuf的汇编代码中
0x00000000004017b9 <+17>:	add    $0x28,%rsp
0x00000000004017bd <+21>:	ret

# --------------------------------------
# gdb调试函数
```

```bash
# c02.s -> c02.o -> c02_raw.s-> c02_raw.txt -> c02.txt
gcc -c c02.s c02.o
objdump -d c02.o > c02_raw.s
```

![c02](c02_0.png)



![c02](c02.png)
