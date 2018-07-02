namespace Solution {
  open Microsoft.Quantum.Primitive;
  open Microsoft.Quantum.Canon;
  open Microsoft.Quantum.Extensions.Diagnostics;

  operation Test() : () {
    body {
      for(nBits in 1..8) {
        using (qubits = Qubit[nBits]) {
          Solve(qubits);
          DumpRegister($"C({nBits}).dump", qubits);
          for(i in 0..nBits-1) {
            Reset(qubits[i]);
          }
        }
      }
    }
  }
}
