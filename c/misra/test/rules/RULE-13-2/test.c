void foo(int, int);

void unsequenced_sideeffects() {
  volatile int l1, l2;

  int l3 = l1 + l1; // NON_COMPLIANT
  int l4 = l1 + l2; // NON_COMPLIANT

  // Store value of volatile object in temporary non-volatile object.
  int l5 = l1;
  // Store value of volatile object in temporary non-volatile object.
  int l6 = l2;
  int l7 = l5 + l6; // COMPLIANT

  int l8, l9;
  l1 = l1 & 0x80;      // COMPLIANT
  l8 = l1 = l1 & 0x80; // NON_COMPLIANT

  foo(l1, l2); // NON_COMPLIANT
  // Store value of volatile object in temporary non-volatile object.
  l8 = l1;
  // Store value of volatile object in temporary non-volatile object.
  l9 = l2;
  foo(l8, l9);     // COMPLIANT
  foo(l8++, l9++); // NON_COMPLIANT

  int l10 = l8++, l11 = l8++; // COMPLIANT
}