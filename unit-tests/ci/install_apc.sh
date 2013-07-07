#! /bin/sh

if [ "$(php -r 'echo substr(PHP_VERSION, 0, 3);')" = "5.3" ]; then
	wget -q http://pecl.php.net/get/apc-3.1.9.tgz
	tar -xzf apc-3.1.9.tgz
	( cd APC-3.1.9 && phpize && ./configure --enable-apc && make && sudo make install )
	echo "extension=apc.so" >> `php --ini | grep "Loaded Configuration" | sed -e "s|.*:\s*||"`
elif [ "$(php -r 'echo substr(PHP_VERSION, 0, 3);')" = "5.5" ]; then
	wget -q http://pecl.php.net/get/apcu-4.0.1.tgz
	tar xzf apcu-4.0.1.tgz
	( cd apcu-4.0.1 && phpize && ./configure && make && sudo make install )
	echo "extension=apcu.so" >> `php --ini | grep "Loaded Configuration" | sed -e "s|.*:\s*||"`
else
	wget -q http://pecl.php.net/get/apc-3.1.13.tgz
	tar -xzf apc-3.1.13.tgz
	( cd APC-3.1.13 && phpize && ./configure --enable-apc && make && sudo make install )
	echo "extension=apc.so" >> `php --ini | grep "Loaded Configuration" | sed -e "s|.*:\s*||"`
fi

echo "apc.enable_cli = On" >> `php --ini | grep "Loaded Configuration" | sed -e "s|.*:\s*||"`
