namespace Solution {
  open Microsoft.Quantum.Primitive;
  open Microsoft.Quantum.Canon;
  open Microsoft.Quantum.Extensions.Diagnostics;

  operation Test() : () {
    body {
      using (qubits = Qubit[6]) {
        let res1 = Solve(qubits);
        if(res1 != 0) {
          fail $"Expected Solve(|000000>) = 0, found {res1}.";
        }

        X(qubits[0]);
        let res2 = Solve(qubits);
        if(res2 != 1) {
          fail $"Expected Solve(|100000>) = 0, found {res2}.";
        }

        for(i in 1..5) {
          X(qubits[i]);
        }
        let res3 = Solve(qubits);
        if(res3 != 0) {
          fail $"Expected Solve(|111111>) = 0, found {res3}.";
        }
        ResetAll(qubits);
      }
    }
  }
}
