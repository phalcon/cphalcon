Phalcon Framework
=================

Phalcon is a web framework delivered as a C extension providing high performance and lower resource consumption.

Get Started
-----------

Phalcon is written in C with platform independence in mind. As a result, Phalcon is available on Microsoft Windows, GNU/Linux, Mac OS X, You can either download a binary package for the system of your choice or build it from sources.

### Windows

For use Phalcon on Windows, you only should to [download a DLL library](http://phalconphp.com/en/download/windows), place it in your `/php/ext` folder and then append at the last line (or whatever line you wish) of your `php.ini`:

```bash
extension=php_phalcon.dll
```

Finally, just restart your webserver and voilà!

**Hint:** To ensure that your Phalcon's installation was successful, debug with `<?php phpinfo(); ?>` and search for the a section mentioning the Phalcon extension.

### Linux/Unix/Mac

On a Unix based platform you can easily compile and install the extension from sources.

#### Requirements
We need some packages previously installed.

* PHP 5.x development resources
* GCC compiler

Ubuntu:

```bash
sudo apt-get install php5-dev php5-mysql gcc make
```

Suse:

```bash
yast2 -i php5-pear php5-devel libmysqlclient gcc make autoconf2.13
```

Compilation
-----------

Follow these instructions to generate a binary extension for your platform:

```bash
git clone git://github.com/phalcon/cphalcon.git
cd cphalcon/build
sudo ./install
```

Add the extension to your php.ini

```bash
extension=phalcon.so
```

Finally restart the webserver

External Links
--------------

* [Documentation](http://docs.phalconphp.com/)
* [Support](http://phalconphp.com/support)
* [Blog](http://blog.phalconphp.com)
* [Twitter](http://twitter.com/phalconphp)

Current Build Status
--------------------

Phalcon Framework is built under Travis CI service. Every commit pushed to this repository will queue a build into the continuous integration service and will run all PHPUnit tests to ensure that everything is going well and the project is stable. The current build status is:

[![Build Status](https://secure.travis-ci.org/phalcon/cphalcon.png?branch=master)](http://travis-ci.org/phalcon/cphalcon)

Meet the Incubator
-----------
Our community is developing amazing extra features for Phalcon everyday via [Incubator](https://github.com/phalcon/incubator). There are resources to enhance your experience with the framework and that enlarge the main features.

Just give a try and help us improve more & more our PHP's stronghold.


License
-------
Phalcon is open-sourced software licensed under the New BSD License. See the docs/LICENSE.txt file for more information.
