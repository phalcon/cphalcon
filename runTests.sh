#!/bin/sh

ZEND_DONT_UNLOAD_MODULES=1 $(phpenv which php) vendor/bin/phpunit --debug -c unit-tests/phpunit.xml unit-tests/

if [ "$(php -r 'echo substr(PHP_VERSION, 0, 3);')" = "5.3" ];
then
    # Not going to run any Codeception tests for 5.3
    echo ".."
else
   $(phpenv which php) codecept.phar build
   ZEND_DONT_UNLOAD_MODULES=1 $(phpenv which php) codecept.phar run
fi