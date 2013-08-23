#!/bin/bash
php -m | grep -i apc > /dev/null 
if [ $? != 0 ]; then
	echo "APC not found, preparing latest XCache build"
	export PREVDIR=$(pwd)
	cd ~; svn co svn://svn.lighttpd.net/xcache/trunk xcache-trunk; cd xcache-trunk
	phpize && ./configure --enable-xcache && make && make install
	phpenv config-add xcache.ini
	cd $PREVDIR
	echo "flush_all" | nc localhost 11211
	$(phpenv which php) ./unit-tests/ci/phpunit.php --debug -c unit-tests/phpunit.xml ./unit-tests/CacheTest.php
fi
