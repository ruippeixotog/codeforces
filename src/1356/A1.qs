namespace A1 {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Measurement;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        using (qubit = Qubit()) {
            unitary(qubit);
            if(MResetZ(qubit) == One) {
                return 1;
            }
        }
        return 0;
    }

    @Test("QuantumSimulator")
    operation Test () : Unit {
        for (_ in 0..100) {
            Fact(Solve(I) == 0, "Solve(I) was not 0");
            Fact(Solve(X) == 1, "Solve(X) was not 1");
        }
    }
}
