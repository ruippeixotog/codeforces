namespace Solution {
  open Microsoft.Quantum.Primitive;
  open Microsoft.Quantum.Canon;
  open Microsoft.Quantum.Extensions.Convert;
  open Microsoft.Quantum.Extensions.Math;

  operation Solve(qs: Qubit[]): () {
    body {
      if(Length(qs) == 1) {
        X(qs[0]);
      } else {
        Solve(qs[0..Length(qs)/2-1]);
        using(anc = Qubit[1]) {
          H(anc[0]);
          for(i in 0..Length(qs)/2-1) {
            (Controlled SWAP)(anc, (qs[i], qs[i + Length(qs)/2]));
          }
          for(i in 0..Length(qs)/2-1) {
            CNOT(qs[i + Length(qs)/2], anc[0]);
          }
          ResetAll(anc);
        }
      }
    }
  }
}
