#ifndef TROPTER_OPTIMALCONTROLITERATE_H
#define TROPTER_OPTIMALCONTROLITERATE_H
// ----------------------------------------------------------------------------
// tropter: OptimalControlIterate.h
// ----------------------------------------------------------------------------
// Copyright (c) 2017 tropter authors
//
// Licensed under the Apache License, Version 2.0 (the "License"); you may
// not use this file except in compliance with the License. You may obtain a
// copy of the License at http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
// ----------------------------------------------------------------------------

#include <Eigen/Dense>

#include <string>
#include <vector>

namespace tropter {

/// This struct holds the values the variables in an optimal control problem.
/// Iterates can be written to and read from CSV files. The file format is as
/// follows:
/// @verbatim
/// num_states=<number-of-state-variables>
/// num_controls=<number-of-control-variables>
/// time,<state-var-0-name>,...,<control-var-0-name>,...
/// <#>,<#>,...,<#>,...
/// @endverbatim
/// @ingroup optimalcontrol
struct OptimalControlIterate {
    Eigen::RowVectorXd time;
    Eigen::MatrixXd states;
    Eigen::MatrixXd controls;
    std::vector<std::string> state_names;
    std::vector<std::string> control_names;
    /// This constructor leaves all members empty.
    OptimalControlIterate() = default;
    /// Read in states and controls from a CSV file generated by calling
    /// write().
    explicit OptimalControlIterate(const std::string& filepath);
    /// Linearly interpolate (upsample or downsample) this iterate to produce a
    /// new iterate with a desired number of columns with equally spaced time
    /// points. This is useful when forming an initial guess for an optimal
    /// control problem. If the size of time matches desired_num_columns, then
    /// we return a copy of this iterate (no interpolation).
    /// @returns the interpolated iterate.
    OptimalControlIterate interpolate(int desired_num_columns) const;
    // TODO void validate(const std::string& error_message) const;
    /// Write the states and controls trajectories to a plain-text CSV file.
    virtual void write(const std::string& filepath) const;
};

} // namespace tropter

#endif // TROPTER_OPTIMALCONTROLITERATE_H
