namespace Solution {
  open Microsoft.Quantum.Primitive;
  open Microsoft.Quantum.Canon;
  open Microsoft.Quantum.Extensions.Diagnostics;

  operation Test() : () {
    body {
      using (qubits = Qubit[4]) {
        Solve(qubits, [true;false;false;true], [true;true;true;false]);
        DumpRegister("A3.dump", qubits);
        ResetAll(qubits);
      }
    }
  }
}
