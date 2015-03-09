Phalcon Framework
=================

Phalcon is an open source web framework delivered as a C extension for the PHP language providing high performance and lower resource consumption.

This readme provides an introduction to contributing to `Phalcon 2.0`.

Get Started
-----------

Clone `Phalcon 2.0` repo:

```bash
git clone -b 2.0.0 https://github.com/phalcon/cphalcon.git
```

Clone [Zephir](https://github.com/phalcon/zephir) repo:

```bash
git clone https://github.com/phalcon/zephir.git
```

Clone [json-c](https://github.com/json-c/json-c.git) repo:

```bash
git clone https://github.com/json-c/json-c.git
```

Install required packages:

```bash
sudo apt-get install php5-dev php5-mysql gcc make re2c libpcre3-dev
```

Compile `json-c` and `Zephir`:

```bash
cd zephir
sudo ./install-json
sudo ./install
cd ..
```

Compile `Phalcon`:

```bash
cd cphalcon
../zephir/bin/zephir generate
../zephir/bin/zephir compile
```

Add extension to your `php.ini`:

```ini
extension=phalcon.so
```

Finally restart the webserver!

External Links
--------------

* [Phalcon Documentation](http://docs.phalconphp.com/)
* [Zephir Documentation](http://zephir-lang.com/)

Current Build Status
--------------------

Phalcon Framework is built under Travis CI service. Every commit pushed to this repository will queue a build into the continuous integration service and will run all PHPUnit tests to ensure that everything is going well and the project is stable. The current build status is:

[![Build Status](https://secure.travis-ci.org/phalcon/cphalcon.png?branch=2.0.0)](http://travis-ci.org/phalcon/cphalcon)

License
-------

Phalcon is open-sourced software licensed under the New BSD License. See the docs/LICENSE.txt file for more information.
