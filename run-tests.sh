#!/bin/sh

ZEND_DONT_UNLOAD_MODULES=1 $(phpenv which php) ./unit-tests/ci/phpunit.php --debug -c unit-tests/phpunit.xml --testsuite=stable
result_phpunit=$?

if [ "$(php -r 'echo substr(PHP_VERSION, 0, 3);')" = "5.3" ];
then
    # Not going to run any Codeception tests for 5.3
    echo ".."
    result_codecept=0
else
   $(phpenv which php) codecept.phar build
   ZEND_DONT_UNLOAD_MODULES=1 $(phpenv which php) codecept.phar run
   result_codecept=$?
fi

if [ $result_phpunit -ne 0 -o $result_codecept -ne 0 ];
then
   exit 1;
fi
