#! /bin/sh

wget -q http://pecl.php.net/get/mongo-1.4.1.tgz
tar -xzf mongo-1.4.1.tgz
( cd mongo-1.4.1 && phpize && ./configure --enable-mongo && make && sudo make install )

echo "extension=mongo.so" >> `php --ini | grep "Loaded Configuration" | sed -e "s|.*:\s*||"`
