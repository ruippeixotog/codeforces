namespace Solution {
  open Microsoft.Quantum.Primitive;
  open Microsoft.Quantum.Canon;

  operation Rotate(x: Qubit[]) : Unit {
    body (...) {
      let N = Length(x);
      using(anc = Qubit()) {
        SWAP(x[0], anc);
        for(i in 1..N-1) {
          SWAP(x[i-1], x[i]);
        }
        SWAP(anc, x[N-1]);
      }
    }
    adjoint auto;
    controlled auto;
    controlled adjoint auto;
  }

  operation Solve (x : Qubit[], y : Qubit) : Unit {
    body (...) {
      let N = Length(x);
      using (ancs = Qubit[3]) {
        X(ancs[0]);
        for(i in 0..N-1) {
          (Controlled Rotate)([x[i]], ancs);
        }
        CNOT(ancs[0], y);
        for(i in 0..N-1) {
          (Controlled Adjoint Rotate)([x[i]], ancs);
        }
        X(ancs[0]);
      }
    }
    adjoint auto;
  }
}
