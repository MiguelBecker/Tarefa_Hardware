#include <stdio.h>

void base_2(int x) {
  int binario[32];
  int i = 0;
  if (x == 0) {
    printf("\nNúmero em binário: \n0\n");
    return;
  }
  if (x < 0) {
    x = (1 << 8) + x;
  }
  while (x > 0) {
    binario[i] = x % 2;
    x = x / 2;
    i++;
  }
  printf("\nNúmero em binário: ");
  for (int j = i - 1; j >= 0; j--) {
    printf("%d", binario[j]);
  }
  printf("\n");
}

void base_8(int x) {
  int Octal[32];
  int i = 0;
  if (x == 0) {
    printf("\nNúmero em Octal: \n0\n");
    return;
  }
  if (x < 0) {
    while (x != 0) {
      Octal[i] = -(x % 8);
      x = x / 8;
      i++;
    }
    printf("\nNúmero em Octal: ");
    printf("-");
    for (int j = i - 1; j >= 0; j--) {
      printf("%d", Octal[j]);
    }
    printf("\n");
    return;
  }
  while (x > 0) {
    Octal[i] = x % 8;
    x = x / 8;
    i++;
  }
  printf("\nNúmero em Octal: ");
  for (int j = i - 1; j >= 0; j--) {
    printf("%d", Octal[j]);
  }
  printf("\n");
}

void base_16(int x) {
  char hexadecimal[32];
  int i = 0;
  if (x == 0) {
    printf("\nNúmero em Hexadecimal: 0\n");
    return;
  }
  unsigned int valorConvertido = (x < 0) ? (unsigned int)x : x;
  while (valorConvertido > 0) {
    int resto = valorConvertido % 16;
    if (resto < 10) {
      hexadecimal[i] = resto + '0';
    } else {
      hexadecimal[i] = resto - 10 + 'A';
    }
    valorConvertido /= 16;
    i++;
  }
  if (x < 0) {
    printf("\nNúmero em Hexadecimal: -");
  } else {
    printf("\nNúmero em Hexadecimal: ");
  }

  for (int j = i - 1; j >= 0; j--) {
    printf("%c", hexadecimal[j]);
  }
  printf("\n");
}

void codigo_BCD(int x) {
  int BCD[128];
  int algarismos[32];
  int i = 0;
  int o = 0;
  int f = 0;
  if (x == 0) {
    printf("\nNúmero em BCD: 0000\n");
    return;
  }
  if (x < 0) {
    x = x * -1;
    f++;
  }
  while (x != 0) {
    algarismos[o] = x % 10;
    x = x / 10;
    o++;
  }
  for (int h = o - 1; h >= 0; h--) {
    int n = algarismos[h];
    for (int k = 3; k >= 0; k--) {
      BCD[i] = (n >> k) & 1;
      i++;
    }
  }
  int r = 0;
  printf("\nNúmero em BCD: ");
  if (f > 0) {
    printf("1101 ");
  }
  for (int j = 0; j < i; j++) {
    printf("%d", BCD[j]);
    r++;
    while (r == 4) {
      printf(" ");
      r = 0;
    }
  }
  printf("\n");
}

int main(void) {
  int a;
  scanf("%d", &a);
  base_2(a);
  base_8(a);
  base_16(a);
  codigo_BCD(a);
  return 0;
}
