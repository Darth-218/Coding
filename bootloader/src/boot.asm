[BIT 16]
[ORG 0x7c00] ; where the code starts

start:
  cli
  mov ax, 0x00
  mov ds, ax
  mov es, ax
  mov ss, ax
  mov sp, 0x7c00
  sti
  mov si, msg

print:
  lodsb

msg: db 'Hello World', 0
