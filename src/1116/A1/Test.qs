namespace Solution {
  open Microsoft.Quantum.Primitive;
  open Microsoft.Quantum.Canon;
  open Microsoft.Quantum.Extensions.Diagnostics;
   
  operation Test() : Unit {
    using (qubits = Qubit[2]) {
      Solve(qubits);
      DumpRegister("A1.dump", qubits);
      ResetAll(qubits);
    }
  }
}
