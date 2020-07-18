namespace A5 {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Measurement;

    operation Solve (theta : Double, unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        let unitaryPow = OperationPow(unitary, Floor(PI() / theta));
        let maxIters = 20;

        mutable counter = 0;
        using (q = Qubit()) {
            repeat {
                unitaryPow(q);
            }
            until (MResetZ(q) == One or counter == maxIters)
            fixup {
                Reset(q);
                set counter += 1;
            }
        }
        return counter == maxIters ? 0 | 1;
    }

    @Test("QuantumSimulator")
    operation Test () : Unit {
        for (i in 1..99) {
            let theta = IntAsDouble(i) * 0.01 * PI();
            Fact(Solve(theta, Rz(theta, _)) == 0, $"Solve({theta}, Rz({theta}, _)) was not 0");
            Fact(Solve(theta, Ry(theta, _)) == 1, $"Solve({theta}, Ry({theta}, _)) was not 1");
        }
    }
}
