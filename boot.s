# Declare multiboot header constants
.set ALIGN,     1<<0            # align loaded modules on page boundies
.set MEMINFO,   1<<1            # provide memory map
.set FLAGS,     ALIGN | MEMINFO # Multiboot flags
.set MAGIC,     0x1BADB002      # magic header detection constant
.set CHECKSUM,  -(MAGIC + FLAGS)

# Declare the header
.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM

# Allocate temporary stack
.section .bootstrap_stack
stack_bottom:
.skip 16384
stack_top:

# Bootstrap entry point
.section .text
.global _start
.type _start, @function
_start:
        #setup the stack
        movl $stack_top, %esp

        #call the kernel entry point
        call kernel_main

        #if the kernel returns
        #disable interupts
        cli
        #halt
        hlt
.Lhang:
        jmp .Lhang

#set size of _start to length of the bootstrap code for debugging
.size _start, . - _start
