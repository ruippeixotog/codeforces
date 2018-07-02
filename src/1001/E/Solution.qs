namespace Solution {
  open Microsoft.Quantum.Primitive;
  open Microsoft.Quantum.Canon;

  operation Solve(qs: Qubit[]): Int {
    body {
      CNOT(qs[0], qs[1]);
      H(qs[0]);
      let m0 = M(qs[0]);
      let m1 = M(qs[1]);
      if(m1 == Zero && m0 == Zero) {
        return 0;
      }
      if(m1 == Zero && m0 == One) {
        return 1;
      }
      if(m1 == One && m0 == Zero) {
        return 2;
      }
      return 3;
    }
  }
}
