namespace Solution {
  open Microsoft.Quantum.Primitive;
  open Microsoft.Quantum.Canon;

  operation Test() : () {
    body {
      using (qs = Qubit[1]) {
        let res1 = Solve(qs[0]);
        if(res1 == 1) {
          fail $"Expected Solve(|0>) = 0 or -1, found {res1}.";
        }
        ResetAll(qs);
        H(qs[0]);
        let res2 = Solve(qs[0]);
        if(res2 == 0) {
          fail $"Expected Solve(|+>) = 1 or -1, found {res2}.";
        }
        ResetAll(qs);
      }
    }
  }
}
