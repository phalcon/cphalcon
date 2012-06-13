phpunit --debug -c unit-tests/phpunit.xml
STATUS=$?
if [ $STATUS != 0 ]; then
	cat core
fi
exit $STATUS
