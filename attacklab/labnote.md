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
# level 1 . Use vscode 
# file : ctarget.s
# 通过函数查找来解决这个问题
find test() -> getbuf() -> ret
```

