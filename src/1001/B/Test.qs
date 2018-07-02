namespace Solution {
  open Microsoft.Quantum.Primitive;
  open Microsoft.Quantum.Canon;
  open Microsoft.Quantum.Extensions.Diagnostics;

  operation Test() : () {
    body {
      using (qubits = Qubit[2]) {
        for(index in 0..3) {
          Solve(qubits, index);
          DumpRegister($"B({index}).dump", qubits);
          Reset(qubits[0]);
          Reset(qubits[1]);
        }
      }
    }
  }
}
