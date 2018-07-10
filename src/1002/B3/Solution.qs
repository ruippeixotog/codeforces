namespace Solution {
  open Microsoft.Quantum.Primitive;
  open Microsoft.Quantum.Canon;

  operation Solve(qs: Qubit[]): Int {
    body {
      H(qs[0]);
      H(qs[1]);
      if(M(qs[0]) == Zero && M(qs[1]) == Zero) {
        return 0;
      }
      if(M(qs[0]) == Zero && M(qs[1]) == One) {
        return 1;
      }
      if(M(qs[0]) == One && M(qs[1]) == Zero) {
        return 2;
      }
      return 3;
    }
  }
}
