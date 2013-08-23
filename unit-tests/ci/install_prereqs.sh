#! /bin/sh

DIR=$(readlink -enq $(dirname $0))

if [ "$(php -r 'echo substr(PHP_VERSION, 0, 3);')" = "5.5" ]; then
	( pecl install apcu < /dev/null || ( pecl config-set preferred_state beta; pecl install apcu < /dev/null ) && phpenv config-add "$DIR/apcu.ini" ) &
else
	phpenv config-add "$DIR/apc.ini"
fi

pecl install igbinary < /dev/null && phpenv config-add $(DIR)/igbinary.ini &

PREVDIR=$(pwd)
cd ~; svn co svn://svn.lighttpd.net/xcache/trunk xcache-trunk; cd xcache-trunk
phpize && ./configure --enable-xcache && make && make install
phpenv config-add xcache.ini
cd $PREVDIR

phpenv config-add $(DIR)/memcache.ini
phpenv config-add $(DIR)/mongo.ini
wait
