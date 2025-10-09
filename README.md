# 4Bit CPU Simulator
C언어로 작성, 간단한 4비트 프로세스 및 메모리 아키텍처 시뮬레이션. 

어셈블리어 해석, 기계어로 번역, 메모리에 로드 후 실행 가능하다.

Fetch-Decode-Execute와 레지스터, 메모리, 처리 장치 간의 상호작용 시뮬레이션 한다.

## 주요 기능
+ 4비트 아키텍처
+ 16바이트 메모리
+ 레지스터
+ 실시간 어셈블러
+ 명령어 사이클
+ 파일 시스템 연동
+ 대화형 시각화

## 구조
``` plain
📁 4비트 CPU 에뮬레이터 프로젝트
 │
 ├─📁 CPU 핵심 동작 (Core CPU Cycle)
 │   ├─ fetcher.c      # 메모리에서 명령어를 가져오는 '인출(Fetch)' 단계 구현
 │   ├─ decoder.c      # 인출된 명령어를 해석하는 '해석(Decode)' 단계 구현
 │   └─ executor.c     # 해석된 명령어를 실제로 실행하는 '실행(Execute)' 단계 구현
 │
 ├─📁 CPU 구성 요소 (CPU Components)
 │   ├─ register.c     # R0-R3, PC, SR 등 CPU 레지스터를 정의하고 관리
 │   └─ memory.c       # 16-byte 메모리 공간을 모델링하고, 기계어를 저장
 │
 ├─📁 어셈블러 (Assembler)
 │   ├─ assembler.c    # 사용자가 입력한 어셈블리어를 명령어와 피연산자로 분리(파싱)
 │   └─ (memory.c)     # 분리된 어셈블리어를 기계어 코드로 변환하여 메모리에 적재
 │
 ├─📁 시스템 인터페이스 (System Interface)
 │   ├─ display.c      # ncurses 라이브러리를 사용해 메모리와 레지스터 상태를 시각화
 │   └─ filesystem.c   # 사용자가 작성한 어셈블리 코드를 .asm 파일로 저장하고 불러오는 기능
 │
 └─📁 기타 유틸리티 (Utilities)
     ├─ cpu.c          # CPU 관련 보조 함수
     └─ util.c         # 문자열 처리 등 범용 보조 함수
```

## 아키텍처
+ CPU: 한 번에 하나의 명령어를 실행하는 4비트 프로세서
+ 메모리: 16바이트 크기의 배열. 각 메모리 셀 1바이트 크기. 명령어 또는 데이터 저장 가능
+ 레지스터
  + `R0`, `R1`, `R2`, `R3`: 데이터 조작 위한 4비트 레지스터 4개
  + `SR` (상태 레지스터): JEQ 연산시에 사용
  + `PC` (프로그램 카운터): 다음에 실행할 명령어가 저장된 메모리 주소를 가리킴

## 명령어 형식
`M OOO PPPP`

+ `M` (1비트): 모드 비트, 피연산자를 어떻게 해석할지 결정
  + `0`: 레지스터 모드 (레지스터 끼리 연산)
  + `1`: 즉시값 모드 (즉시값 사용)
+ `OOO` (3비트): 명렁어 코드를 나타내는 opcode
+ `PPPP` (4비트): operand


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
