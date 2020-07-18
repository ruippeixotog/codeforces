namespace B1 {
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Math;

    operation Increment (register: LittleEndian) : Unit is Adj+Ctl {
        ApplyToEachCA(X, register!);
        X(register![0]);
        for (i in 1..Length(register!) - 1) {
            Controlled X(register![0..i - 1], register![i]);
        }
        ApplyToEachCA(X, register!);
    }

    operation SumBits (inputs: Qubit[], counter: LittleEndian) : Unit is Adj+Ctl {
        for (i in 0..Length(inputs)-1) {
            (Controlled Increment)([inputs[i]], counter);
        }
    }

    operation Solve (inputs : Qubit[], output : Qubit) : Unit is Adj+Ctl {
        let inputLenBits = Ceiling(Lg(IntAsDouble(Length(inputs))));
        using (cnt = Qubit[inputLenBits]) {
            SumBits(inputs, LittleEndian(cnt));
            (ControlledOnInt(Length(inputs) / 2, X))(cnt, output);
            (Adjoint SumBits)(inputs, LittleEndian(cnt));
        }
    }
}
