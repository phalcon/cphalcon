#!/usr/bin/env bash
#
# This file is part of the Phalcon Framework.
#
# (c) Phalcon Team <team@phalcon.io>
#
# For the full copyright and license information, please view the
# LICENSE.txt file that was distributed with this source code.

php -d extension=ext/modules/phalcon.so vendor/bin/codecept run --ext DotReporter unit
php -d extension=ext/modules/phalcon.so vendor/bin/codecept run --ext DotReporter cli
php -d extension=ext/modules/phalcon.so vendor/bin/codecept run --ext DotReporter integration
php -d extension=ext/modules/phalcon.so vendor/bin/codecept run --ext DotReporter database -g common
php -d extension=ext/modules/phalcon.so vendor/bin/codecept run --ext DotReporter database --env mysql -g mysql
php -d extension=ext/modules/phalcon.so vendor/bin/codecept run --ext DotReporter database --env sqlite -g sqlite
php -d extension=ext/modules/phalcon.so vendor/bin/codecept run --ext DotReporter database --env pgsql -g pgsql
