namespace Solution {
  open Microsoft.Quantum.Primitive;
  open Microsoft.Quantum.Canon;
  open Microsoft.Quantum.Extensions.Diagnostics;
   
  operation Test() : () {
    body {
      using (qubits = Qubit[8]) {
        Solve(qubits);
        DumpRegister("A1.dump", qubits);
        ResetAll(qubits);
      }
    }
  }
}
