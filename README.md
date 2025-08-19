# 4Bit Tiny CPU
+ ISA
+ Register
+ Memory
+ Fetch-Decode-Execute
---
## ISA
| instruction | bianry | action                          |
|-------------|--------|---------------------------------|
| MOV         | 0x0    | save to register                |
| LOAD        | 0x1    | load to register from RAM       |
| STR         | 0x2    | store to RAM from register      |
| ADD         | 0x3    | add two register value          |
| SUB         | 0x4    | substract two register value    |
| JMP         | 0x5    | jump to address                 |
| JEQ         | 0x6    | jump to address if compare same |
| HLT         | 0x7    | program exit                    |

---
## Register
+ R0
+ R1
+ R2
+ R3

---
## RAM

---
## Fetch-Decode-Execute Cycle
