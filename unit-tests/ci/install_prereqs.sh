#! /bin/sh

DIR=$(readlink -enq $(dirname $0))

if [ "$(php -r 'echo substr(PHP_VERSION, 0, 3);')" = "5.5" ]; then
	( pecl install apcu < /dev/null || ( pecl config-set preferred_state beta; pecl install apcu < /dev/null ) && phpenv config-add "$DIR/apcu.ini" ) &
else
	phpenv config-add "$DIR/apc.ini"
fi

pecl install igbinary < /dev/null && phpenv config-add $(DIR)/igbinary.ini &

phpenv config-add $(DIR)/memcache.ini
phpenv config-add $(DIR)/mongo.ini
wait

sudo apt-get -qq install beanstalkd
echo 'DAEMON_OPTS="-l 127.0.0.1 -p 11300"' | sudo tee -a /etc/default/beanstalkd > /dev/null
echo 'START=yes' | sudo tee -a /etc/default/beanstalkd > /dev/null
sudo service beanstalkd restart
