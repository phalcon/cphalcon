#!/usr/bin/env bash

ZEND_DONT_UNLOAD_MODULES=1 vendor/bin/phpunit --bootstrap unit-tests/ci/phpunit.php unit-tests/
result_phpunit=$?

vendor/bin/codecept build
ZEND_DONT_UNLOAD_MODULES=1 vendor/bin/codecept run
result_codecept=$?

if [ ${result_phpunit} -ne 0 -o ${result_codecept} -ne 0 ];
then
   exit 1;
fi
