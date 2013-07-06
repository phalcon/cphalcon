
sudo sh -c 'echo core > /proc/sys/kernel/core_pattern' || true
ulimit -c unlimited
php ./php-tests/ci/phpunit.php --debug -c php-tests/tests/phpunit.xml
STATUS=$?
if [ $STATUS != 0 ]; then
	if [ -f core ]; then
		sudo apt-get -qq install gdb
		gdb -q -batch -x ./php-tests/ci/gdb-commands -e $PHP_BIN -c core
	else
		echo "No core dump was generated"
	fi
fi
exit $STATUS
