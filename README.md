Phalcon Framework
=================

Phalcon is an open source web framework delivered as a C extension for the PHP language providing high performance and lower resource consumption.

Get Started
-----------

Phalcon is written in [Zephir/C](http://zephir-lang.com/) with platform independence in mind. As a result, Phalcon is available on Microsoft Windows, GNU/Linux, FreeBSD and MacOS. You can either download a binary package for the system of your choice or build it from source.

### Windows

To install Phalcon on Windows:

1. Download [Phalcon for Windows](http://phalconphp.com/en/download/windows)
2. Extract the DLL file and copy it to your PHP extensions directory
3. Edit your **php.ini** file and add this line:

   ```ini
   extension=php_phalcon.dll
   ```
4. Finally, restart your web server

**Hint:** To ensure that your Phalcon installation was successful, debug with
```php
<?php phpinfo(); ?>
```
and search for a section mentioning the Phalcon extension.

### Linux/Unix/Mac

On a Unix-based platform you can easily compile and install the extension from sources.

#### Requirements

Prerequisite packages are:

* PHP 5.5.x/5.6.x/7.0.x development resources (PHP 5.3 and 5.4 are no longer supported)
* GCC compiler (Linux/Solaris/FreeBSD) or Xcode (MacOS)
* [`re2c`](http://re2c.org) >= 0.13

Ubuntu:

```bash
sudo apt-get install php5-dev libpcre3-dev gcc make
```

Suse:

```bash
sudo zypper install php5-devel gcc make
```

CentOS/Fedora/RHEL

```bash
sudo yum install php-devel pcre-devel gcc make
```

General Compilation
-------------------

Follow these instructions to generate a binary extension for your platform:

```bash
git clone git://github.com/phalcon/cphalcon.git
cd cphalcon/build
sudo ./install
```

Add the extension to your **php.ini**:

```ini
extension=phalcon.so
```

Finally, **restart the web server**.

Advanced compilation
--------------------
If you have specific php versions running

```bash
git clone https://github.com/phalcon/cphalcon
# or cd cphalcon/build/32bits
cd cphalcon/build/64bits

make clean

# Example: /opt/php-5.6.15
export CUSTOM_PHP_INSTALLATION_PATH=/your/php/installation/path

# Example: /opt/php-5.6.15/bin/phpize --clean
$CUSTOM_PHP_INSTALLATION_PATH/bin/phpize --clean

# Example: /opt/php-5.6.15/bin/phpize
$CUSTOM_PHP_INSTALLATION_PATH/bin/phpize

# Example: ./configure --with-php-config=/opt/php-5.6.15/bin/php-config
./configure --with-php-config=$CUSTOM_PHP_INSTALLATION_PATH/bin/php-config

make && sudo make install
```

Edit your **php.ini** (for the specific version) and add this line:

```ini
extension=phalcon.so
```

Save the file and **Restart the web server**.

Contributing
------------
Tests are located in `tests/` and use Codeception.
Test classes should follow the [PSR-2 coding style guide](https://github.com/php-fig/fig-standards/blob/master/accepted/PSR-2-coding-style-guide.md).

Vagrant
-------
https://github.com/phalcon/vagrant

OSX MAMP ready extensions
-------------------------

https://github.com/majksner/php-phalcon-mamp

External Links
--------------

* [Documentation](http://docs.phalconphp.com/)
* [Support](http://forum.phalconphp.com)
* [Blog](http://blog.phalconphp.com)
* [Zephir](http://zephir-lang.com/)
* [Twitter](http://twitter.com/phalconphp)

Current Build Status
--------------------

Phalcon Framework is built under the Travis CI service. Every commit pushed to this repository will queue a build into the continuous integration service and will run all PHPUnit tests to ensure that everything is going well and the project is stable. The current build status is:

[![Build Status](https://travis-ci.org/phalcon/cphalcon.svg?branch=master)](https://travis-ci.org/phalcon/cphalcon)

Meet the Incubator
------------------
Our community is developing amazing extra features for Phalcon every day via [Incubator](https://github.com/phalcon/incubator). There are resources to enhance your experience with the framework and that enlarge the main features.

Just give it a try and help us improve Phalcon even more!

License
-------
Phalcon is open source software licensed under the New BSD License. See the docs/LICENSE.txt file for more
