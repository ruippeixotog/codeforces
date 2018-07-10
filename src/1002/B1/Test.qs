namespace Solution {
  open Microsoft.Quantum.Primitive;
  open Microsoft.Quantum.Canon;
  open Microsoft.Quantum.Extensions.Diagnostics;

  operation Test() : () {
    body {
      using (qubits = Qubit[6]) {
        let res = Solve(qubits);
        if(res != 0) {
          fail $"Expected Solve(|0>) = 0, found {res}.";
        }
        ResetAll(qubits);
      }
    }
  }
}
