namespace Solution {
  open Microsoft.Quantum.Primitive;
  open Microsoft.Quantum.Canon;

  operation Solve (qs : Qubit[], bits : Bool[][]) : Unit {
    using(ancs = Qubit[2]) {
      ApplyToEach(H, ancs);
      for(i in 0..3) {
        let op =
          ControlledOnBitString(
            [i / 2 == 0, i % 2 == 0],
            ApplyPauliFromBitString(PauliX, true, bits[i], _));
        op(ancs, qs);
      }
      for(i in 0..3) {
        let op =
          ControlledOnBitString(
            bits[i],
            ApplyPauliFromBitString(PauliX, true, [i / 2 == 0, i % 2 == 0], _));
        op(qs, ancs);
      }
    }
  }
}
