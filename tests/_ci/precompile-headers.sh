#!/usr/bin/env bash
#
# This file is part of the Phalcon.
#
# (c) Phalcon Team <team@phalconphp.com>
#
# For the full copyright and license information, please view the LICENSE
# file that was distributed with this source code.

# Ensure that this is being run inside a CI container
if [ "${CI}" != "true" ]; then
	echo "This script is designed to run inside a CI container only. Stop."
	exit 1
fi

PROJECT_ROOT=$(readlink -enq "$(dirname $0)/../../")

cd ${PROJECT_ROOT}

# Creating precompiled headers.
#
# If a `*.gch' file is not found then the normal header files will be used.
# For more see: http://en.wikipedia.org/wiki/Precompiled_header
for file in `find kernel -name "*.h"`; do
	echo -e "Creating a precompiled header: ext/${file} => ext/${file}.ghc ..."
	${CC} "$file" -I. $(php-config --includes) -o "$file.ghc"
done
