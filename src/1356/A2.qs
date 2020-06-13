namespace A2 {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Measurement;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        using (qubit = Qubit()) {
            H(qubit);
            unitary(qubit);
            if(MResetX(qubit) == One) {
                return 1;
            }
        }
        return 0;
    }

    @Test("QuantumSimulator")
    operation Test () : Unit {
        for (_ in 0..100) {
            Fact(Solve(I) == 0, "Solve(I) was not 0");
            Fact(Solve(Z) == 1, "Solve(Z) was not 1");
        }
    }
}
