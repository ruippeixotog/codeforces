namespace Solution {
  open Microsoft.Quantum.Primitive;
  open Microsoft.Quantum.Canon;
  open Microsoft.Quantum.Extensions.Diagnostics;
   
  operation Test() : () {
    body {
      using (qubits = Qubit[1]) {
        Solve(qubits[0], 1);
        DumpRegister("A(1).dump", [qubits[0]]);
        Reset(qubits[0]);
        Solve(qubits[0], -1);
        DumpRegister("A(-1).dump", [qubits[0]]);
        Reset(qubits[0]);
      }
    }
  }
}
