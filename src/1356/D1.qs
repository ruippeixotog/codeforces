namespace D1 {
    open Microsoft.Quantum.MachineLearning;

    function ClassifierStructure() : ControlledRotation[] {
        return [
            ControlledRotation((0, new Int[0]), PauliX, 0),
            ControlledRotation((0, new Int[0]), PauliY, 1),
            ControlledRotation((0, new Int[0]), PauliZ, 2)
        ];
    }

    operation Solve() : (ControlledRotation[], (Double[], Double)) {
        return (
            ClassifierStructure(),
            ([2.0114147733377417, 0.0, 3.520153553245436], 0.00145)
        );
    }
}
