#! /bin/sh

DIR=$(readlink -enq $(dirname $0))

sudo apt-get -qq update &

if [ "$(php -r 'echo PHP_VERSION_ID;')" -ge 50500 ]; then
	( pecl install apcu < /dev/null || ( pecl config-set preferred_state beta; pecl install apcu < /dev/null ) && phpenv config-add "$DIR/apcu.ini" ) &
else
	( CFLAGS="-O2 -g3 -fno-strict-aliasing" pecl upgrade apc < /dev/null; phpenv config-add "$DIR/apc.ini" ) &
fi

CFLAGS="-O1 -g3 -fno-strict-aliasing" pecl install igbinary < /dev/null &
CFLAGS="-O1 -g3 -fno-strict-aliasing" pecl install imagick < /dev/null &
#CFLAGS="-O1 -g3 -fno-strict-aliasing" pecl install mongo < /dev/null &
CFLAGS="-O1 -g3 -fno-strict-aliasing" pecl install yaml < /dev/null &
( pecl install weakref < /dev/null || ( pecl config-set preferred_state beta; pecl install weakref < /dev/null ) ) &

wait
phpenv config-add "$DIR/memcache.ini"
phpenv config-add "$DIR/memcached.ini"
phpenv config-add "$DIR/mongo.ini"
#phpenv config-add "$DIR/yaml.ini"
phpenv config-rm xdebug.ini

sudo apt-get -qq install beanstalkd
echo 'DAEMON_OPTS="-l 127.0.0.1 -p 11300"' | sudo tee -a /etc/default/beanstalkd > /dev/null
echo 'START=yes' | sudo tee -a /etc/default/beanstalkd > /dev/null
sudo service beanstalkd restart
