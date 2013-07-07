#! /bin/sh

wget http://pecl.php.net/get/mongo-1.3.4.tgz
tar -xzf mongo-1.3.4.tgz
sh -c "cd mongo-1.3.4 && phpize && ./configure --enable-memcache && make && sudo make install"

echo "extension=mongo.so" >> `php --ini | grep "Loaded Configuration" | sed -e "s|.*:\s*||"`
