#!/usr/bin/env bash
#
# This file is part of the Phalcon Framework.
#
# (c) Phalcon Team <team@phalcon.io>
#
# For the full copyright and license information, please view
# the LICENSE.txt file that was distributed with this source code.

# -e  Exit immediately if a command exits with a non-zero status.
# -u  Treat unset variables as an error when substituting.

set -eu
set -o pipefail

# Get Release notes for the latest release from CHANGELOG.md
# How to use:
#   release-notes.sh CHANGELOG.md

startline=$(awk '/^## /{print NR; exit}' "$1")
finishline=$(($(awk '/^# /{c++; if (c==2){print NR; exit}}' "$1") - 1))
changelog=$(sed -n "${startline},${finishline}p" "$1");

echo "${changelog}"
