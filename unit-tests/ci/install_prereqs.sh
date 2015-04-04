#! /bin/sh

DIR=$(readlink -enq $(dirname $0))

pecl channel-update pecl.php.net

if [ "$(php -r 'echo substr(PHP_VERSION, 0, 3);')" = "5.5" ]; then
	( pecl install apcu < /dev/null || ( pecl config-set preferred_state beta; pecl install apcu < /dev/null ) && phpenv config-add "$DIR/apcu.ini" ) &
else
	if [ "$(php -r 'echo substr(PHP_VERSION, 0, 3);')" = "5.6" ]; then
		( pecl install apcu < /dev/null || ( pecl config-set preferred_state beta; pecl install apcu < /dev/null ) && phpenv config-add "$DIR/apcu.ini" ) &
	else
		( CFLAGS="-O2 -g3 -fno-strict-aliasing" pecl upgrade apc < /dev/null; phpenv config-add "$DIR/apc.ini" ) &
	fi
fi

CFLAGS="-O2 -g3 -fno-strict-aliasing" pecl install igbinary < /dev/null &
CFLAGS="-O1 -g3 -fno-strict-aliasing" pecl install imagick < /dev/null &
CFLAGS="-O1 -g3 -fno-strict-aliasing" pecl install yaml < /dev/null &
# CFLAGS="-O2 -g3 -fno-strict-aliasing" pecl upgrade mongo < /dev/null &

phpenv config-add "$DIR/memcache.ini"
phpenv config-add "$DIR/mongo.ini"
phpenv config-rm xdebug.ini
wait
