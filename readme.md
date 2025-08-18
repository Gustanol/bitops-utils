# Bitutils

This is a simple project that aims to be my gateway to low level programming, starting with bitwise.

Although being simple, that's an important step to dive into this world!

---

### Bellow, I will explain the elements created:

- [`bitutils.h`](./include/bitutils.h): header created to group functions that would be use. We must it to import them in a test file.

- [`bitutils.c`](./src/bitutils.c): the file that will define what each function will do.

  1. `set_bit`: receive a value and set the bit in `bit` position to 1.

  ```c
  void set_bit(uint32_t *value, uint8_t bit) {
    *value |= (1U << bit);
  }
  ```

---
  > [!WARNING]
  > See that `value` variable is a pointer. It must be that way because we will modify the global variable directly, dereferencing it.

---

  - `(1U << bit)` will create a mask defining the bit 1 `bit` positions to left. For example:

  ```text
  bit = 4
  (1U << bit) = 10000
```

  - We must using `OR` bitwise operation to keep bit 1.

---

  2. `clear_bit`: receive a value and set the bit in `bit` position to 0.

  ```c
  void clear_bit(uint32_t *value, uint8_t bit) {
    *value &= ~(1U << bit);
  }
  ```

  - `~`: is `NOT` in bitwise and has the function to invert all bits of a sequence. So, `~(1U << bit)` creates an inverted mask.
  
  - We must use `AND` to compare bit to bit and keep the chosen one 0.

  ```text
  value = 00111010
  bit = 3
  mask = 0111

  AND:
  00111010
      0111
  --------
  00110010
  ```

---

 3. `toggle_bit`: receive a value and toggle the bit in `bit` position.

 ```c
 void toggle_bit(uint32_t *value, uint8_t bit) {
   *value ^= (1U << bit);
 }
 ```

  - In this case, we use `XOR` bitwise operation, because, as its name suggests, it's `Exclusive OR`. So, with two different bits, it's the same as `OR`. In same bits, it 'returns' a 0, what's perfect for this situation, because if the chosen bit were 1, the comparison between `1` and `1` results in `0`.

  ```text
  value = 0001
  bit = 0
  mask = 1

  XOR:
  0001
     1
  ----
  0000
  ```

---

  4. `check_bit`: receive a value and verify if the chosen bit `1` or `0`.

  ```c
  bool check_bit(uint32_t value, uint8_t bit) {
    return (value & (1U << value)) != 0;
  }
  ```

---

  > [!NOTE]
  > Note that, in here, we do not need to receive a pointer as an argument, because there's no modification.

---

  ```text
  value = 00010000
  bit = 4
  mask = 10000

  AND:
  00010000
     10000
  --------
  00010000 != 0 (true)
  ```

```text
  value = 00010000
  bit = 5
  mask = 100000

  AND:
  00010000
    100000
  --------
  00000000 == 0 (false)
```

---

  5. `print_binary`: prints a binary number with the specified number of bits.

  ```c
  void print_binary(uint32_t value, uint8_t bits) {
    for (int i = bits - 1; i >= 0; i--) {
        printf("%d", (value >> i) & 1);
    }
    printf("\n");
  } 
  ```

  - This function seems to be complicated, but it's simple.
    - It's created a for loop to iterate between `bits - 1` and `0`.
    - Shifts `value` variable `i` to left. It means that always the current number will be printed.

  ```text
  value = 0101
  bits = 8

  LOOP:
  
  - i = 7: 00000000 & 1 = 0
  - i = 6: 00000000 & 1 = 0
  - i = 5: 00000000 & 1 = 0
  - i = 4: 00000000 & 1 = 0
  - i = 3: 00000000 & 1 = 0
  - i = 2: 00000001 & 1 = 1
  - i = 1: 00000010 & 1 = 0
  - i = 0: 00000101 & 1 = 1

result = 00000101
  ```

---

The [`main.c`](./src/main.c) is just a file to define tests to the functions. You can change 'em.

---

### How to run it?

You can manually create objects of each C file or use the [`Makefile`](./Makefile):

1. Compile all files:

```bash
make all
```

2. Run the main file:

```bash
make run
```

> [!WARNING]
> Ensure you have `make` package installed!

---

That's it!
