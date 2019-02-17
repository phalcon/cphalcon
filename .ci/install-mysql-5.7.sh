#!/usr/bin/env bash
#
# This file is part of the Phalcon Framework.
#
# (c) Phalcon Team <team@phalconphp.com>
#
# For the full copyright and license information, please view the
# LICENSE.txt file that was distributed with this source code.

# Ensure that this is being run inside a CI container
if [ "${CI}" != "true" ];
then
	>&2 echo "This script is designed to run inside a CI container only."
	>&2 echo "Aborting."
	exit 1
fi

echo mysql-apt-config mysql-apt-config/select-server select mysql-5.7 | sudo debconf-set-selections
wget https://dev.mysql.com/get/mysql-apt-config_0.7.3-1_all.deb
sudo dpkg --install mysql-apt-config_0.7.3-1_all.deb
sudo apt-get update -q
sudo apt-get install -q -y --allow-unauthenticated -o Dpkg::Options::=--force-confnew mysql-server
sudo mysql_upgrade
