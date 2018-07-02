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
          Solve(qs, qRes, 0);
          if(M(qRes) != One) {
            fail $"Expected qRes = |1> after Solve(|101>, qRes, 0), measured 0";
          }
          Solve(qs, qRes, 1);
          if(M(qRes) != Zero) {
            fail $"Expected qRes = |0> after Solve(|101>, qRes, 1), measured 1";
          }
          Solve(qs, qRes, 2);
          if(M(qRes) != One) {
            fail $"Expected qRes = |1> after Solve(|101>, qRes, 2), measured 0";
          }
          ResetAll(qs);
        }
        Reset(qRes);
      }
    }
  }
}
