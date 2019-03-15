namespace Solution {
  open Microsoft.Quantum.Primitive;
  open Microsoft.Quantum.Canon;

  operation CountMod3 (x : Qubit[], sum: Qubit, carry: Qubit) : Unit {
    body (...) {
      for(xi in x) {
        (ControlledOnBitString([true, false], X))([xi, carry], sum);
        (ControlledOnBitString([true, false], X))([xi, sum], carry);      
      }
    }
    adjoint auto;
  }

  operation Solve (x : Qubit[], y : Qubit) : Unit {
    body (...) {
      using (ancs = Qubit[2]) {
        let sum = ancs[0];
        let carry = ancs[1];
        CountMod3(x, sum, carry);
        (ControlledOnInt(0, X))([sum, carry], y);
        (Adjoint CountMod3)(x, sum, carry);
      }
    }
    adjoint auto;
  }
}
