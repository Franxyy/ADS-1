// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
  if (value < 2) {
    return false;
  }
  for (uint64_t z = 2; z < value; z++) {
    if (value % z == 0) {
  	  return false;
    }
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 2;
    }
    uint64_t counter = 1;
    uint64_t num = 2;

    for (uint64_t i = 3; counter < n; i+=2) {
        bool logic = true;
        for (uint64_t del = 3; del< i; del+=2) {
            if (i % del == 0) {
                logic = false;
                break;
            }
        }
        if (logic) {
            counter++;
            num = i;
        }
    }
    return num;
}

uint64_t nextPrime(uint64_t value) {
    if (value < 2) {
        return 2;
    } else {
        uint64_t num = value + 1;
        if (num % 2 == 0) {
            num++;
        }
        while (true) {
            bool logic = true;
            if (num < 2) {
                logic = false;
            } else if (num == 2) {
                logic = true;
            } else if (num % 2 == 0) {
                logic = false;
            } else {
                for (uint64_t del = 3; del < num; del += 2) {
                    if (num % del == 0) {
                        logic = false;
                        break;
                    }
                }
            }
            if (logic) {
                return num;
            }
            num += 2;
        }
    }
}

uint64_t sumPrime(uint64_t hbound) {
    uint64_t sum = 2;
    if (hbound < 2) {
        return 0;
    }
    if (hbound == 2) {
        return 2;
    }
    for (uint64_t i = 3; i < hbound; i += 2) {
        bool logic = true;
        for (uint64_t del = 3; del < i; del += 2) {
            if (i % del == 0) {
                logic = false;
                break;
            }
        }
        if (logic) {
            sum = sum + i;
        }
    }
    return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
    if (hbound < 3) {
        return 0;
    }
    uint64_t counter = 0;
    for (uint64_t i = lbound; i + 2 < hbound; i++) {
        bool logic1 = true;
        if (i < 2) {
            logic1 = false;
        }
        for (uint64_t del = 2; del < i; del++) {
            if (i % del == 0) {
                logic1 = false;
                break;
            }
        }
        bool logic2 = true;
        uint64_t num2 = i + 2;
        for (uint64_t del = 2; del < num2; del++) {
            if (num2 % del == 0) {
                logic2 = false;
                break;
            }
        }
        if (logic1 && logic2) {
            counter++;
        }
    }
    return counter;
}
