namespace Solution {
  open Microsoft.Quantum.Primitive;
  open Microsoft.Quantum.Canon;

  operation Solve(q: Qubit): Int {
    body {
      let rnd = RandomInt(2);
      if (rnd == 0) {
        if(M(q) == One) {
          return 1;
        }
      } else {
        H(q);
        if(M(q) == One) {
          return 0;
        }
      }
      return -1;
    }
  }
}
