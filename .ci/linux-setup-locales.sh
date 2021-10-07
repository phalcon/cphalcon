#!/usr/bin/env bash

## Setup locales for Codeception tests with Extension 'gettext'
sudo sudo apt-get install tzdata locales -y
sudo sed -i -e 's/# de_DE.UTF-8 UTF-8/de_DE.UTF-8 UTF-8/' /etc/locale.gen
sudo sed -i -e 's/# el_GR.UTF-8 UTF-8/el_GR.UTF-8 UTF-8/' /etc/locale.gen
sudo sed -i -e 's/# en_US.UTF-8 UTF-8/en_US.UTF-8 UTF-8/' /etc/locale.gen
sudo sed -i -e 's/# es_ES.UTF-8 UTF-8/es_ES.UTF-8 UTF-8/' /etc/locale.gen
sudo sed -i -e 's/# ru_RU.UTF-8 UTF-8/ru_RU.UTF-8 UTF-8/' /etc/locale.gen
sudo dpkg-reconfigure --frontend=noninteractive locales
sudo update-locale LANG=en_US.UTF-8
