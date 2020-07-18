namespace A4 {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Measurement;

    operation Solve (unitary : ((Double, Qubit) => Unit is Adj+Ctl)) : Int {
        using (qubits = Qubit[2]) {
            H(qubits[0]);
            Controlled unitary([qubits[0]], (2.0 * PI(), qubits[1]));
            H(qubits[0]);
            return MResetZ(qubits[0]) == Zero ? 1 | 0;
        }
    }

    @Test("QuantumSimulator")
    operation Test () : Unit {
        for (_ in 0..100) {
            Fact(Solve(Rz) == 0, "Solve(Rz) was not 0");
            Fact(Solve(R1) == 1, "Solve(R1) was not 1");
        }
    }
}
