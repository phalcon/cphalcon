#!/bin/sh

ZEND_DONT_UNLOAD_MODULES=1 $(phpenv which php) ./unit-tests/ci/phpunit.php --debug -c unit-tests/phpunit.xml --testsuite=stable
status_phpunit=$?

if [ "$(php -r 'echo substr(PHP_VERSION, 0, 3);')" = "5.3" ];
then
    # Not going to run any Codeception tests for 5.3
    echo ".."
else
   $(phpenv which php) codecept.phar build
   ZEND_DONT_UNLOAD_MODULES=1 $(phpenv which php) codecept.phar run
fi
status_codeception=$?

if [ ${status_phpunit} != 0 ] ; then
    exit ${status_phpunit}
fi

if [ ${status_codeception} != 0 ] ; then
    exit ${status_codeception}
fi
