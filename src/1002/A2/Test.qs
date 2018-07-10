namespace Solution {
  open Microsoft.Quantum.Primitive;
  open Microsoft.Quantum.Canon;
  open Microsoft.Quantum.Extensions.Diagnostics;

  operation Test() : () {
    body {
      using (qubits = Qubit[4]) {
        Solve(qubits, [true;false;false;true]);
        DumpRegister("A2.dump", qubits);
        ResetAll(qubits);
      }
    }
  }
}
