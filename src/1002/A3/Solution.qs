namespace Solution {
  open Microsoft.Quantum.Primitive;
  open Microsoft.Quantum.Canon;

  operation Solve(qs: Qubit[], bits0: Bool[], bits1: Bool[]): () {
    body {
      mutable pivot = -1;
      for(i in 0..Length(qs)-1) {
        if(bits0[i] == bits1[i]) {
          if(bits0[i]) {
            X(qs[i]);
          }
        } else {
          if(pivot == -1) {
            H(qs[i]);
            set pivot = i;
          } else {
            if(bits0[pivot] == bits0[i]) {
              CNOT(qs[pivot], qs[i]);
            } else {
              CNOT(qs[pivot], qs[i]);
              X(qs[i]);
            }
          }
        }
      }
    }
  }
}
