namespace Solution {
  open Microsoft.Quantum.Primitive;
  open Microsoft.Quantum.Canon;
  open Microsoft.Quantum.Extensions.Diagnostics;

  operation UfTest(qs: Qubit[], q: Qubit): () {
    body {
      // H(q);
      // X(q);
    }
  }

  operation Kth(x: Qubit[], y: Qubit, k: Int): () {
    body {
      CNOT(x[k], y);
    }
  }

  operation Test(): () {
    body {
      // let res = Solve(5, UfTest);
      let res = Solve(5, Kth(_, _, 2));
      Message($"Result: {res}");
      return ();
    }
  }
}
