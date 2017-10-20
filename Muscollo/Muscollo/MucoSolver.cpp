/* -------------------------------------------------------------------------- *
 * OpenSim Muscollo: MucoSolver.cpp                                           *
 * -------------------------------------------------------------------------- *
 * Copyright (c) 2017 Stanford University and the Authors                     *
 *                                                                            *
 * Author(s): Christopher Dembia                                              *
 *                                                                            *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may    *
 * not use this file except in compliance with the License. You may obtain a  *
 * copy of the License at http://www.apache.org/licenses/LICENSE-2.0          *
 *                                                                            *
 * Unless required by applicable law or agreed to in writing, software        *
 * distributed under the License is distributed on an "AS IS" BASIS,          *
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.   *
 * See the License for the specific language governing permissions and        *
 * limitations under the License.                                             *
 * -------------------------------------------------------------------------- */
#include "MucoSolver.h"

#include "MucoProblem.h"

using namespace OpenSim;

MucoSolver::MucoSolver() {}

MucoSolver::MucoSolver(const MucoProblem& problem) : MucoSolver() {
    resetProblem(problem);
}

void MucoSolver::resetProblem() {
    m_problem.reset();
    resetProblemImpl();
}

void MucoSolver::resetProblem(const MucoProblem& problem) {
    m_problem.reset(&problem);
    resetProblemImpl(problem);
}

MucoSolution MucoSolver::solve() const {
    return solveImpl();
}
