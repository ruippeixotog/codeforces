namespace Solution {
  open Microsoft.Quantum.Primitive;
  open Microsoft.Quantum.Canon;
  open Microsoft.Quantum.Extensions.Diagnostics;

  operation ParityUf(x: Qubit[], y: Qubit, b: Int[]): () {
    body {
      for(i in 0..Length(x)-1) {
        if(b[i] == 1) {
          CNOT(x[i], y);
        }
      }
    }
  }

  operation Test(): () {
    body {
      let res = Solve(5, ParityUf(_, _, [1;1;0;1;0]));
      Message($"Result: {res}");
      return ();
    }
  }
}
