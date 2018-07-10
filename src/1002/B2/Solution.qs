namespace Solution {
  open Microsoft.Quantum.Primitive;
  open Microsoft.Quantum.Canon;

  operation Solve(qs: Qubit[]): Int {
    body {
      mutable onesCount = 0;
      for(i in 0..Length(qs)-1) {
        if(M(qs[i]) == One) {
          set onesCount = onesCount + 1;
        }
      }
      if(onesCount == 1) {
        return 1;
      } else {
        return 0;
      }
    }
  }
}
