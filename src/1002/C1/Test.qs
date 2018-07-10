namespace Solution {
  open Microsoft.Quantum.Primitive;
  open Microsoft.Quantum.Canon;
  open Microsoft.Quantum.Extensions.Diagnostics;

  operation Test() : () {
    body {
      using (qs = Qubit[1]) {
        let res1 = Solve(qs[0]);
        if(res1 != 0) {
          fail $"Expected Solve(|0>) = 0, found {res1}.";
        }
        ResetAll(qs);
        // H(qs[0]);
        // let res2 = Solve(qs[0]);
        // if(res2 != 1) {
        //   fail $"Expected Solve(|+>) = 1, found {res2}.";
        // }
        // ResetAll(qs);
      }
    }
  }
}
