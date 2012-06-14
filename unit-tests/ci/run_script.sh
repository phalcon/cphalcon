ulimit -c unlimited
rm -f /tmp/core
sudo echo "/tmp/core" > /proc/sys/kernel/core_pattern
php ./unit-tests/ci/phpunit.php --debug -c unit-tests/phpunit.xml
STATUS=$?
if [ $STATUS != 0 ]; then
        if [ -f /tmp/core ]; then
		gdb -q -batch -x ./unit-tests/ci/gdb-commands -e php -c /tmp/core 
	else 
		echo "No core dump was generated"
	fi
fi
exit $STATUS
