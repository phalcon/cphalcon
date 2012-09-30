
ulimit -c unlimited
PHP_VERSION=`php -r "echo PHP_VERSION;"`
PHP_BIN="/home/travis/.phpenv/versions/$PHP_VERSION/bin/php"
echo $PHP_BIN
$PHP_BIN ./unit-tests/ci/phpunit.php --debug -c unit-tests/phpunit.xml
STATUS=$?
if [ $STATUS != 0 ]; then
	if [ -f core ]; then
		gdb -q -batch -x ./unit-tests/ci/gdb-commands -e $PHP_BIN -c core
	else
		echo "No core dump was generated"
	fi
fi
exit $STATUS
