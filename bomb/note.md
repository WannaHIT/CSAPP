# bomblab

```bash
刚开始发现所有的参数都是$rsi，这是因为读入的输入是第一个输入，所以$rdi已经被占用了
```



##  phase1

```bash
# 太过于明显，不作说明，直接看汇编代码就行

#我们可以使用b phase_1或b *0x400e3a来打断点的，这两条命令有一点不同就在于，断在地址会停在地址 上也就是call指令的位置，断在函数名，会进入函数中，相当于再进行了一次si操作
b phase_1
b *0x400e3a

ni(next instruction)
si(step into)

# 进入汇编模式
layout asm 
# 退出汇编模式
layout none 
# 或者
tui disable # 好用

refresh # 刷新上面的汇编代码防止字体重叠

print /x $寄存器名  # 查看为十六进制
print /d $寄存器名  # 查看为十进制
print /t $寄存器名  # 查看为二进制

print $rax
```

```bash
# 打断点到地址 0x400e32
(gdb) break *0x400e32


# 查看 0x400ee0 函数 <phase_1> 的代码
(gdb) disassemble 0x400ee0
# 如果有源代码，查看源代码
(gdb) list *0x400ee0

# 显示当前 RIP 寄存器所指的指令
(gdb) x/i $rip
```



```bash
# 如果内存包含以 NULL (\0) 结尾的字符序列，GDB 会将其作为字符串显示。
x/s 0x402400 # 查看该地址存储的字符串

# 16 个字节并以十六进制（x）字节（b）形式显示
x/16xb 0x402400 # 查看内存的原始字节


# 以十六进制的 4 字节整型查看
x/4xw 0x402400

# 以十进制查看
x/4dw 0x402400
```

---

```
x/s 0x402400
```

```css
# 内存布局
Address:   0x402400    0x402401    0x402402    0x402403 ...
Content:     'B'         'o'         'r'         'd' ...
```

```
背后的含义：
在你运行的程序中，0x402400 是 .rodata 段的一部分，这是程序中的只读数据段（read-only data segment）。
编译器在编译过程中，将这个字符串硬编码到 .rodata 段中，并分配了地址 0x402400 给它。
```

## phase2

```bash
# 开头两个寄存器push到stack就是为了腾出来帮忙，做搬运工
# read_six_numbers将6个数字读入了栈
# 注意要运行过这个函数之后读入才算完成，
b *400f0a

#第二注意小端法读取四字节
# 栈是从低地址开始往上放置的参数
```



```bash
# 读取栈中的内容
x /32xb $rsp
```

```
# objdump命令将炸弹文件反汇编出来
objdump -d bomb > bomb.asm 
```

```bash
# 可以使用 layout regs，它会打开一个 TUI（文本用户界面）窗口，实时显示所有寄存器的值
layout regs

# 退出 TUI 界面：按下 Ctrl+x，然后按 o
```



------

### **2. 如何查看一个地址里的值？**

#### 方法 1：使用 `x` 命令查看内存内容

`x` 是 GDB 的内存检查命令，格式如下：

```gdb
x/<format> <address>
```

其中：

- ```
  <format>
  ```

   指定查看的格式，比如：

  - `x`：十六进制
  - `d`：十进制
  - `s`：字符串
  - `i`：汇编指令
  - `c`：字符
  - `b`：字节

- `<address>` 是你想查看的内存地址。

**示例：** 如果你想查看寄存器 `rbx` 中的地址指向的值：

```gdb
x/x $rbx
```

- `x/x` 表示以十六进制格式查看地址中的值。
- `$rbx` 是寄存器中的地址。

**更多示例：**

```bash
x/s $rbx   # 将地址中的值作为字符串显示

x/d $rbx   # 将地址中的值以十进制显示

x/x $rbx   # 将地址中的值以十六进制显示

x/4x $rbx  # 查看从地址开始的 4 个字节内容（以十六进制显示）

x/4i $rbx  # 将地址中的内容解释为汇编指令
```

------

#### 方法 2：结合寄存器值和指针间接访问

如果寄存器的值是一个地址，比如 `rbx = 0x7fffffffda44`，你可以用 `x` 命令查看该地址指向的内容。

**示例：**

```gdb
p $rbx                # 查看 rbx 中的值
x/x $rbx              # 查看 rbx 指向的内存地址中的值
x/4x $rbx             # 查看 rbx 指向的内存地址的后 4 个字节
x/s $rbx              # 如果地址中存储的是字符串，查看完整字符串
```

------

### **3. 示例操作总结**

假设：

- `rbx = 0x7fffffffda44`，且该地址指向一个字符串或整数。

**步骤：**

1. 查看 `rbx` 的值（即地址）：

   ```gdb
   p $rbx
   ```

2. 查看 `rbx` 指向地址的值：

   ```gdb
   x/x $rbx
   ```

3. 查看 `rbx` 指向地址的值作为字符串：

   ```gdb
   x/s $rbx
   ```

4. 如果 `rbx` 指向整数，可以用解引用查看：

   ```gdb
   p *(int*)$rbx
   ```

5. 如果想查看更多内存范围：

   ```gdb
   x/10x $rbx      # 查看从 rbx 开始的 10 个十六进制字节
   ```

------

### **4. 注意事项**

- **有效地址**：确保寄存器（如 `rbx`）存储的是有效内存地址，否则会导致段错误。
- **地址指向的内容类型**：通过上下文判断地址中存储的是数字、字符串、指针还是代码，从而选择合适的查看方法（如 `x/x` 或 `x/s`）。



----



```bash
# 以 十六进制格式 输出寄存器 rbx 的值
(gdb)  p /x $rbx
$18 = 0x7fffffffda44

# x 是 GDB 的内存检查命令
# 查看 rbx 寄存器指向的内存内容
(gdb)  x/x $rbx
0x7fffffffda44: 0x02

# 打印地址 本身 的值
(gdb)  p 0x7fffffffda44
$19 = 140737488345668

# error 
(gdb)  0x7fffffffda44
Undefined command: "0x7fffffffda44".  Try "help".

# 使用 x 查看指定地址的内容
(gdb)  x 0x7fffffffda44
0x7fffffffda44: 0x02
```

```bash
# 如果$rbp 的值是个地址的时候
(gdb) info registers       # 查看寄存器，包括 $rbp 的值
(gdb) x/wx $rbp - 0x14     # 查看该地址的值（以 4 字节十六进制形式显示）
(gdb) x/wd $rbp - 0x14     # 以十进制显示值

# 查看ecx的字符值
(gdb)  p /c $ecx 

```

## phase_5

```bash

# flyers，这是字符串对比函数的一个参数
# 其实就是一个6的循环，分别找出6个索引
# maduiersnfotvbylSo do you ... ，在这里找6个索引分别对应上字母就行
# 而不是输入"flyers"本身，对于输入的每个字符'X'--> 二进制的值低4位对应上就行
# 比如第一个字符f对应的索引是9,输入'X'-->0x_9就行，前面任意，只要是asii的范围
# flyers的索引分别为9 15 14 5 6 7。这个索引就是我们输入的字符的低4位，那我们只要找到低4位分别是以上数值的字符就可以
# 任意一个字符的对应值的二进制的低四位能对应上就行
```

## phase_6

```bash
x /24xw 0x6032d0 # 查看该地址出的内存
# 查看 12 个单位 的内存
x /12g 0x6032d0 # g：表示以 8 字节（64 位）为单位 打印内存（即“giant word”）
# 开头的node1代表这是一个链表的结点1,即开头
# 而且仔细看能看出来前面一个node里面前面8字节是data广义的，后面8个字节是next指针
0x6032d0 <node1>:0x0000014c 0x00000001 0x006032e0 0x00000000
0x6032e0 <node2>:0x000000a8 0x00000002 0x006032f0 0x00000000
0x6032f0 <node3>:0x0000039c 0x00000003 0x00603300 0x00000000
```

```bash
# 所以输入数组的是链表里面6个数字的顺序，按照这个顺序将node的地址从rsp+32的地方开始存储
# 所以存储的是链表的有序的地址，比如输入3 2 4....
# 那么每个拿出来和1比较，其实就是分别先放node3 node2 node4...的地址到栈上
# 这个阶段rsi就是数组下标，按照下标取arr[i], 也按照下标取node[i]
# 最后rsp+32开始的node顺序就是arr'[]的顺序
```

```bash
# b +188之后可以i对比
(gdb)  x/12xg 0x6032d0 # 原来链表
(gdb)  x/6xg $rsp+32 # 按照arr输入放在栈上的顺序
# 比如输入 arr = 123456
# arr' = 654321
# 栈上的顺序就是654321
```

```bash
# note:tip
# 从内存中读取数据，读取内存地址处的实际数据
mov 0x20(%rsp), %rbx	
# 计算地址并存入寄存器（不读内存）
lea 0x20(%rsp), %rbx	计算地址并存入寄存器（不读内存）	否
```

