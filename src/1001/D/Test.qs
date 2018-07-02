namespace Solution {
  open Microsoft.Quantum.Primitive;
  open Microsoft.Quantum.Canon;
  open Microsoft.Quantum.Extensions.Diagnostics;
   
  operation Test() : () {
    body {
      using (qubits = Qubit[1]) {
        H(qubits[0]);
        let res1 = Solve(qubits[0]);
        if(res1 != 1) {
          fail $"Expected Solve(|+>) = 1, found {res1}.";
        }
        Reset(qubits[0]);

        X(qubits[0]);
        H(qubits[0]);
        let res2 = Solve(qubits[0]);
        if(res2 != -1) {
          fail $"Expected Solve(|->) = -1, found {res2}.";
        }
        Reset(qubits[0]);
      }
    }
  }
}
