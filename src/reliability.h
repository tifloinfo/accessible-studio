// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once
#include <cmath>
#include <limits>

namespace Reliability {
// OBS volmeter magnitude already includes the source fader. Silence cannot
// be inverted. Keeping the calculation independent permits signal tests.
inline double PreFaderDb(double outputDb, double gain)
{
    if (!std::isfinite(outputDb) || !std::isfinite(gain) || gain <= 0.0)
        return -std::numeric_limits<double>::infinity();
    return outputDb - 20.0 * std::log10(gain);
}
}
