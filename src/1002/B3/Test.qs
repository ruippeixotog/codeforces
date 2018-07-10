namespace Solution {
  open Microsoft.Quantum.Primitive;
  open Microsoft.Quantum.Canon;
  open Microsoft.Quantum.Extensions.Diagnostics;

  operation Test() : () {
    body {
      using (qs = Qubit[2]) {
        H(qs[0]);
        H(qs[1]);
        let res1 = Solve(qs);
        if(res1 != 0) {
          fail $"Expected Solve(|+>) = 0, found {res1}.";
        }
        ResetAll(qs);
      }
    }
  }
}
