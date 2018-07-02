namespace Solution {
  open Microsoft.Quantum.Primitive;
  open Microsoft.Quantum.Canon;
  open Microsoft.Quantum.Extensions.Diagnostics;

  operation Set(desired: Result, q1: Qubit) : () {
    body {
      let current = M(q1);
      if(desired != current) {
        X(q1);
      }
    }
  }

  operation Test() : () {
    body {
      using (qResArr = Qubit[1]) {
        let qRes = qResArr[0];
        using (qs = Qubit[3]) {
          Set(One, qs[0]);
          Set(One, qs[2]);
          Solve(qs, qRes);
          if(M(qRes) != Zero) {
            fail $"Expected qRes = |0> after Solve(|101>, qRes), measured 1";
          }
          ResetAll(qs);
        }
        Reset(qRes);
      }
    }
  }
}
