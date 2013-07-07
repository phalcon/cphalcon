#! /bin/sh

if [ "`php -r 'echo substr(PHP_VERSION, 0, 3);'`" = "5.3" ]; then
	wget http://pecl.php.net/get/memcache-2.2.7.tgz
	tar -xzf memcache-2.2.7.tgz
	sh -c "cd memcache-2.2.7 && phpize && ./configure --enable-memcache && make && sudo make install"
else
	wget http://pecl.php.net/get/memcache-3.0.7.tgz
	tar -xzf memcache-3.0.7.tgz
	sh -c "cd memcache-3.0.7 && phpize && ./configure --enable-memcache && make && sudo make install"
fi

echo "extension=memcache.so" >> `php --ini | grep "Loaded Configuration" | sed -e "s|.*:\s*||"`
