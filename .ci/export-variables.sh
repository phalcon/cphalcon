#!/usr/bin/env bash
#
# This file is part of the Phalcon Framework.
#
# (c) Phalcon Team <team@phalcon.io>
#
# For the full copyright and license information, please view the
# LICENSE.txt file that was distributed with this source code.

# Export tests environment variables
# shellcheck disable=SC1091
source ./tests/_config/environment

# shellcheck disable=SC2046
export $(cut -d= -f1 tests/_config/environment)
