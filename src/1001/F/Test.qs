namespace Solution {
  open Microsoft.Quantum.Primitive;
  open Microsoft.Quantum.Canon;
  open Microsoft.Quantum.Extensions.Diagnostics;

  operation Test() : () {
    body {
      using (qubits = Qubit[2]) {
        let res1 = Solve(qubits, [false;false], [false;true]);
        if(res1 != 0) {
          fail $"Expected Solve(|00>, [false;false], [false;true]) = 0, found {res1}.";
        }
        ResetAll(qubits);

        let res2 = Solve(qubits, [true;false], [false;false]);
        if(res2 != 1) {
          fail $"Expected Solve(|00>, [true;false], [false;false]) = 1, found {res2}.";
        }
        ResetAll(qubits);
      }
    }
  }
}
