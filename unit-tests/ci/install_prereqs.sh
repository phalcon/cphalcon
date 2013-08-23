#! /bin/sh

DIR=$(readlink -enq $(dirname $0))

pecl install igbinary < /dev/null && phpenv config-add $(DIR)/igbinary.ini &
php -v

PREVDIR=$(pwd)
cd ~; svn co svn://svn.lighttpd.net/xcache/trunk xcache-trunk; cd xcache-trunk
phpize && ./configure --enable-xcache && make && make install
phpenv config-add xcache.ini
cd $PREVDIR

php -v

phpenv config-add $(DIR)/memcache.ini
phpenv config-add $(DIR)/mongo.ini
wait
