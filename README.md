Phalcon Framework
=================

Phalcon is an open source web framework delivered as a C extension for the PHP language providing high performance and lower resource consumption.

Get Started
-----------

Phalcon is written in Zephir/C with platform independence in mind. As a result, Phalcon is available on Microsoft Windows, GNU/Linux, and Mac OS X. You can either download a binary package for the system of your choice or build it from source.

### Windows

To install Phalcon on Windows:

1. Download [Phalcon for Windows](http://phalconphp.com/en/download/windows)
2. Extract the DLL file and copy it to your PHP extensions directory
3. Edit your php.ini file and add this line: `extension=php_phalcon.dll`
4. Finally, restart your webserver

**Hint:** To ensure that your Phalcon installation was successful, debug with `<?php phpinfo(); ?>` and search for a section mentioning the Phalcon extension.

### Linux/Unix/Mac

On a Unix-based platform you can easily compile and install the extension from sources.

#### Requirements
Prerequisite packages are:

* PHP 5.4.x/5.5.x/5.6.x development resources
* GCC compiler (Linux/Solaris) or Xcode (Mac)

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

Compilation
-----------

Follow these instructions to generate a binary extension for your platform:

```bash
git clone git://github.com/phalcon/cphalcon.git
cd cphalcon/build
sudo ./install
```

Add the extension to your php.ini:

```bash
extension=phalcon.so
```

Finally, restart the webserver.

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

[![Build Status](https://secure.travis-ci.org/phalcon/cphalcon.png?branch=master)](http://travis-ci.org/phalcon/cphalcon)

Meet the Incubator
-----------
Our community is developing amazing extra features for Phalcon every day via [Incubator](https://github.com/phalcon/incubator). There are resources to enhance your experience with the framework and that enlarge the main features.

Just give it a try and help us improve Phalcon even more!

License
-------
Phalcon is open source software licensed under the New BSD License. See the docs/LICENSE.txt file for more
