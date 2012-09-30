
ulimit -c unlimited
find /home/travis/.phpenv
php ./unit-tests/ci/phpunit.php --debug -c unit-tests/phpunit.xml
STATUS=$?
if [ $STATUS != 0 ]; then
	if [ -f core ]; then
		gdb -q -batch -x ./unit-tests/ci/gdb-commands -e php -c core
	else
		echo "No core dump was generated"
	fi
fi
exit $STATUS
