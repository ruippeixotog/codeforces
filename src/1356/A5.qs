namespace A5 {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Measurement;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        using (qubits = Qubit[2]) {
            H(qubits[0]);
            Controlled unitary([qubits[0]], qubits[1]);
            H(qubits[0]);
            if(MResetZ(qubits[0]) == One) {
                return 1;
            }
        }
        return 0;
    }

    @Test("QuantumSimulator")
    operation Test () : Unit {
        for (i in 0..100) {
            Fact(Solve(Z) == 0, "Solve(Z) was not 0");
            Fact(Solve(Rz(-2.0 * PI(), _)) == 1, "Solve(-Z) was not 1");
        }
    }
}
