namespace Solution {
  open Microsoft.Quantum.Primitive;
  open Microsoft.Quantum.Canon;
  open Microsoft.Quantum.Extensions.Diagnostics;
   
  operation Test() : Unit {
    using (qubits = Qubit[4]) {
      Solve(qubits, [
        [true, true, true, true],
        [true, true, true, false],
        [true, true, false, false],
        [true, false, false, false]
      ]);
      DumpRegister("A2.dump", qubits);
      ResetAll(qubits);
    }
  }
}
