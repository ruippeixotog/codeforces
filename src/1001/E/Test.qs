namespace Solution {
  open Microsoft.Quantum.Primitive;
  open Microsoft.Quantum.Canon;
  open Microsoft.Quantum.Extensions.Diagnostics;

  operation B(qs: Qubit[], index: Int) : () {
    body {
      if (index % 2 == 1) {
        X(qs[0]);
      }
      H(qs[0]);
      CNOT(qs[0], qs[1]);
      if (index / 2 == 1) {
        X(qs[1 - index % 2]);
      }
    }
  }

  operation Test() : () {
    body {
      using (qubits = Qubit[2]) {
        for(index in 0..3) {
          B(qubits, index);
          let res = Solve(qubits);
          if(res != index) {
            fail $"Expected Solve(|B{index}>) = {index}, found {res}.";
          }
          Reset(qubits[0]);
          Reset(qubits[1]);
        }
      }
    }
  }
}
