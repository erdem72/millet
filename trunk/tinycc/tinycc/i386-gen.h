#ifndef _I386_GEN_H
#define _I386_GEN_H

/* number of available registers */
#define NB_REGS             4

/* a register can belong to several classes. The classes must be
 sorted from more general to more precise (see gv2() code which does
 assumptions on it). */
#define RC_INT     0x0001 /* generic integer register */
#define RC_FLOAT   0x0002 /* generic float register */
#define RC_EAX     0x0004
#define RC_ST0     0x0008 
#define RC_ECX     0x0010
#define RC_EDX     0x0020
#define RC_IRET    RC_EAX /* function return: integer register */
#define RC_LRET    RC_EDX /* function return: second integer register */
#define RC_FRET    RC_ST0 /* function return: float register */

/* pretty names for the registers */
enum
{
	TREG_EAX = 0, TREG_ECX, TREG_EDX, TREG_ST0,
};

/* return registers for function */
#define REG_IRET TREG_EAX /* single word int return register */
#define REG_LRET TREG_EDX /* second word return register (for long long) */
#define REG_FRET TREG_ST0 /* float return register */

/* defined if function parameters must be evaluated in reverse order */
#define INVERT_FUNC_PARAMS

/* defined if structures are passed as pointers. Otherwise structures
 are directly pushed on stack. */
//#define FUNC_STRUCT_PARAM_AS_PTR

/* pointer size, in bytes */
#define PTR_SIZE 4

/* long double size and alignment, in bytes */
#define LDOUBLE_SIZE  12
#define LDOUBLE_ALIGN 4
/* maximum alignment (for aligned attribute support) */
#define MAX_ALIGN     8

/******************************************************/
/* ELF defines */

#define EM_TCC_TARGET EM_386

/* relocation type for 32 bit data relocation */
#define R_DATA_32   R_386_32
#define R_JMP_SLOT  R_386_JMP_SLOT
#define R_COPY      R_386_COPY

#define ELF_START_ADDR 0x08048000
#define ELF_PAGE_SIZE  0x1000

void gen_le32(int c);
void g(int c);

/******************************************************/

#endif //_I386-GEN_H
