#!/usr/bin/env python

import os
from subprocess import check_call, Popen

REPO = "https://github.com/phalcon/cphalcon.git"
DEV_TOOLS_REPO = "https://github.com/phalcon/phalcon-devtools.git"

HOME_PATH = os.environ['HOME']
GIT_PATH = "/usr/bin/git"
CURL_PATH = "/usr/bin/curl"
APT_GET_PATH = "/usr/bin/apt-get"
PHP_PATH = "/usr/bin/php"

PHALCON_DIR = HOME_PATH + "/.phalcon"
PHALCON_SCRIPT = PHALCON_DIR + "/phalcon-devtools/phalcon.sh"
PHALCON_SCRIPT_BIN_PATH = "/usr/bin/phalcon"
CPHALCON_BUILD_DIR = PHALCON_DIR + "/cphalcon/build"

LIBS = ("git-core gcc autoconf php5 php5-dev php5-imagick php5-mcrypt php5-pgsql php5-cgi php5-cli php5-common php5-gd php5-curl php5-geoip make")

PHP_INI_FILE_PATH = "/etc/php5/apache2/php.ini"

def devtools():
    print("Installing DevTools ... \n")
    os.chdir(PHALCON_DIR)
    check_call([GIT_PATH, "clone", DEV_TOOLS_REPO])
    proc = Popen(PHALCON_SCRIPT, shell=True, stdin=None, executable="/bin/bash")
    proc.wait()
    print("Finish Installing DevTools \n")

def install_phalcon():
    print("Installing Phalcon ... \n")
    os.mkdir(PHALCON_DIR)
    os.chdir(PHALCON_DIR)
    check_call([GIT_PATH,"clone", REPO])
    os.chdir(CPHALCON_BUILD_DIR)
    proc = Popen("./install", shell=True, stdin=None, executable="/bin/bash")
    proc.wait()
    os.write(os.open(PHP_INI_FILE_PATH, os.O_WRONLY), "extension=phalcon.so")
    print("Finish Installing Phalcon \n")


def install_dependencies():
    print("Installing Dependencies ... \n")
    proc = Popen(APT_GET_PATH + " -y install " + LIBS, shell=True, stdin=None, executable="/bin/bash")
    proc.wait()
    print("Finish Installing Dependencies \n")

if __name__ == '__main__':
    install_dependencies()
    install_phalcon()
    devtools()
