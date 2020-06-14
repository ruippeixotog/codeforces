import json
import math
import numpy as np
import sys

import qsharp
qsharp.packages.add("Microsoft.Quantum.MachineLearning::0.11.2006.403")
qsharp.packages.add("Microsoft.Quantum.Xunit::0.11.2006.403")
qsharp.reload()

from DTrain import TrainModel, ValidateModel

if __name__ == "__main__":
    with open(sys.argv[1]) as f:
        data = json.load(f)

    features = data['Features']
    labels = data['Labels']
    train_validation_split = len(features) - 20

    parameter_starting_points = (np.random.rand(16, 3) * (2 * math.pi)).tolist()
    print(f"Starting points: {parameter_starting_points}")

    print("Ready to train.")
    (parameters, bias) = TrainModel.simulate(
        trainingVectors=features[:train_validation_split],
        trainingLabels=labels[:train_validation_split],
        initialParameters=parameter_starting_points
    )
    print("Training complete.")
    print(f"Found optimal parameters {parameters} with bias {bias}.")

    miss_rate = ValidateModel.simulate(
        validationVectors=features[train_validation_split:],
        validationLabels=labels[train_validation_split:],
        parameters=parameters,
        bias=bias
    )
    print(f"Miss rate: {miss_rate:0.2%}")
