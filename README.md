# Phalcon Framework

[![Build Status](https://travis-ci.org/phalcon/cphalcon.svg?branch=master)](https://travis-ci.org/phalcon/cphalcon)
[![Windows Build](https://ci.appveyor.com/api/projects/status/github/sergeyklay/cphalcon?branch=master&svg=true)](https://ci.appveyor.com/project/sergeyklay/cphalcon/branch/master)
[![Phalcon Backers](https://img.shields.io/badge/phalcon-backers-99ddc0.svg)](https://github.com/phalcon/cphalcon/blob/master/BACKERS.md)
[![OpenCollective](https://opencollective.com/phalcon/backers/badge.svg)](#backers)
[![OpenCollective](https://opencollective.com/phalcon/sponsors/badge.svg)](#sponsors)


Phalcon is an open source web framework delivered as a C extension for the PHP language providing high performance and lower resource consumption.

A big thank you to [our Backers](https://github.com/phalcon/cphalcon/blob/master/BACKERS.md); you rock!

## Get Started

Phalcon is written in [Zephir/C](https://zephir-lang.com/) with platform independence in mind.
As a result, Phalcon is available on Microsoft Windows, GNU/Linux, FreeBSD and MacOS.
You can either download a binary package for the system of your choice or build it from source.

### Windows

To install Phalcon on Windows:

1. Download [Phalcon for Windows](https://phalconphp.com/en/download/windows)
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

* PHP 5.5.x/5.6.x/7.0.x/7.1.x development resources (PHP 5.3 and 5.4 are no longer supported)
* `g++` >= 4.4 | `clang++` >= 3.x | `vc++` >= 11
* GNU `make` >= 3.81
* [`re2c`](http://re2c.org) >= 0.13

Ubuntu:

```bash
# Use actual PHP development headers and tools here
sudo apt-get install php5-dev libpcre3-dev gcc make re2c
```

Suse:

```bash
# Use actual PHP development headers and tools here
sudo zypper install php5-devel gcc make re2c
```

CentOS/Fedora/RHEL

```bash
# Use actual PHP development headers and tools here
sudo yum install php-devel pcre-devel gcc make re2c
```

macOS(Sierra / El Capitan / Yosemite):

Using [Homebrew](https://brew.sh/)

```bash
# brew install php<version>-phalcon
# available versions 56, 70, 71

brew install php71-phalcon
```

## Compilation

Follow these instructions to generate a binary extension for your platform:

```bash
git clone git://github.com/phalcon/cphalcon.git
cd cphalcon/build
sudo ./install
```

If you have specific php versions running

```bash
git clone https://github.com/phalcon/cphalcon
cd cphalcon/build
sudo ./install --phpize /usr/bin/phpize5.6 --php-config /usr/bin/php-config5.6
```

Add the extension to your **php.ini**:

```ini
extension=phalcon.so
```

Finally, **restart the web server**.

## Contributing

Tests are located in `tests/` and use Codeception.
Test classes should follow the [PSR-2 coding style guide](https://github.com/php-fig/fig-standards/blob/master/accepted/PSR-2-coding-style-guide.md).

## OSX MAMP ready extensions

https://github.com/majksner/php-phalcon-mamp

## Gentoo

https://github.com/smoke/phalcon-gentoo-overlay

## External Links

* [Documentation](https://docs.phalconphp.com/)
* [Support](https://forum.phalconphp.com)
* [Blog](https://blog.phalconphp.com)
* [Zephir](https://zephir-lang.com/)
* [Twitter](https://twitter.com/phalconphp)

## Meet the Incubator

Our community is developing amazing extra features for Phalcon every day via [Incubator](https://github.com/phalcon/incubator).
There are resources to enhance your experience with the framework and that enlarge the main features.

Just give it a try and help us improve Phalcon even more!

## Sponsors

Become a sponsor and get your logo on our README on Github with a link to your site. [[Become a sponsor](https://opencollective.com/phalcon#sponsor)]

<a href="https://opencollective.com/phalcon/sponsor/0/website" target="_blank"><img src="https://opencollective.com/phalcon/sponsor/0/avatar.svg"></a>
<a href="https://opencollective.com/phalcon/sponsor/1/website" target="_blank"><img src="https://opencollective.com/phalcon/sponsor/1/avatar.svg"></a>
<a href="https://opencollective.com/phalcon/sponsor/2/website" target="_blank"><img src="https://opencollective.com/phalcon/sponsor/2/avatar.svg"></a>
<a href="https://opencollective.com/phalcon/sponsor/3/website" target="_blank"><img src="https://opencollective.com/phalcon/sponsor/3/avatar.svg"></a>
<a href="https://opencollective.com/phalcon/sponsor/4/website" target="_blank"><img src="https://opencollective.com/phalcon/sponsor/4/avatar.svg"></a>
<a href="https://opencollective.com/phalcon/sponsor/5/website" target="_blank"><img src="https://opencollective.com/phalcon/sponsor/5/avatar.svg"></a>
<a href="https://opencollective.com/phalcon/sponsor/6/website" target="_blank"><img src="https://opencollective.com/phalcon/sponsor/6/avatar.svg"></a>
<a href="https://opencollective.com/phalcon/sponsor/7/website" target="_blank"><img src="https://opencollective.com/phalcon/sponsor/7/avatar.svg"></a>
<a href="https://opencollective.com/phalcon/sponsor/8/website" target="_blank"><img src="https://opencollective.com/phalcon/sponsor/8/avatar.svg"></a>
<a href="https://opencollective.com/phalcon/sponsor/9/website" target="_blank"><img src="https://opencollective.com/phalcon/sponsor/9/avatar.svg"></a>
<a href="https://opencollective.com/phalcon/sponsor/10/website" target="_blank"><img src="https://opencollective.com/phalcon/sponsor/10/avatar.svg"></a>
<a href="https://opencollective.com/phalcon/sponsor/11/website" target="_blank"><img src="https://opencollective.com/phalcon/sponsor/11/avatar.svg"></a>
<a href="https://opencollective.com/phalcon/sponsor/12/website" target="_blank"><img src="https://opencollective.com/phalcon/sponsor/12/avatar.svg"></a>
<a href="https://opencollective.com/phalcon/sponsor/13/website" target="_blank"><img src="https://opencollective.com/phalcon/sponsor/13/avatar.svg"></a>
<a href="https://opencollective.com/phalcon/sponsor/14/website" target="_blank"><img src="https://opencollective.com/phalcon/sponsor/14/avatar.svg"></a>
<a href="https://opencollective.com/phalcon/sponsor/15/website" target="_blank"><img src="https://opencollective.com/phalcon/sponsor/15/avatar.svg"></a>
<a href="https://opencollective.com/phalcon/sponsor/16/website" target="_blank"><img src="https://opencollective.com/phalcon/sponsor/16/avatar.svg"></a>
<a href="https://opencollective.com/phalcon/sponsor/17/website" target="_blank"><img src="https://opencollective.com/phalcon/sponsor/17/avatar.svg"></a>
<a href="https://opencollective.com/phalcon/sponsor/18/website" target="_blank"><img src="https://opencollective.com/phalcon/sponsor/18/avatar.svg"></a>
<a href="https://opencollective.com/phalcon/sponsor/19/website" target="_blank"><img src="https://opencollective.com/phalcon/sponsor/19/avatar.svg"></a>
<a href="https://opencollective.com/phalcon/sponsor/20/website" target="_blank"><img src="https://opencollective.com/phalcon/sponsor/20/avatar.svg"></a>
<a href="https://opencollective.com/phalcon/sponsor/21/website" target="_blank"><img src="https://opencollective.com/phalcon/sponsor/21/avatar.svg"></a>
<a href="https://opencollective.com/phalcon/sponsor/22/website" target="_blank"><img src="https://opencollective.com/phalcon/sponsor/22/avatar.svg"></a>
<a href="https://opencollective.com/phalcon/sponsor/23/website" target="_blank"><img src="https://opencollective.com/phalcon/sponsor/23/avatar.svg"></a>
<a href="https://opencollective.com/phalcon/sponsor/24/website" target="_blank"><img src="https://opencollective.com/phalcon/sponsor/24/avatar.svg"></a>
<a href="https://opencollective.com/phalcon/sponsor/25/website" target="_blank"><img src="https://opencollective.com/phalcon/sponsor/25/avatar.svg"></a>
<a href="https://opencollective.com/phalcon/sponsor/26/website" target="_blank"><img src="https://opencollective.com/phalcon/sponsor/26/avatar.svg"></a>
<a href="https://opencollective.com/phalcon/sponsor/27/website" target="_blank"><img src="https://opencollective.com/phalcon/sponsor/27/avatar.svg"></a>
<a href="https://opencollective.com/phalcon/sponsor/28/website" target="_blank"><img src="https://opencollective.com/phalcon/sponsor/28/avatar.svg"></a>
<a href="https://opencollective.com/phalcon/sponsor/29/website" target="_blank"><img src="https://opencollective.com/phalcon/sponsor/29/avatar.svg"></a>

## Backers

Support us with a monthly donation and help us continue our activities. [[Become a backer](https://opencollective.com/phalcon#backer)]

<a href="https://opencollective.com/phalcon/backer/0/website" target="_blank"><img src="https://opencollective.com/phalcon/backer/0/avatar.svg"></a>
<a href="https://opencollective.com/phalcon/backer/1/website" target="_blank"><img src="https://opencollective.com/phalcon/backer/1/avatar.svg"></a>
<a href="https://opencollective.com/phalcon/backer/2/website" target="_blank"><img src="https://opencollective.com/phalcon/backer/2/avatar.svg"></a>
<a href="https://opencollective.com/phalcon/backer/3/website" target="_blank"><img src="https://opencollective.com/phalcon/backer/3/avatar.svg"></a>
<a href="https://opencollective.com/phalcon/backer/4/website" target="_blank"><img src="https://opencollective.com/phalcon/backer/4/avatar.svg"></a>
<a href="https://opencollective.com/phalcon/backer/5/website" target="_blank"><img src="https://opencollective.com/phalcon/backer/5/avatar.svg"></a>
<a href="https://opencollective.com/phalcon/backer/6/website" target="_blank"><img src="https://opencollective.com/phalcon/backer/6/avatar.svg"></a>
<a href="https://opencollective.com/phalcon/backer/7/website" target="_blank"><img src="https://opencollective.com/phalcon/backer/7/avatar.svg"></a>
<a href="https://opencollective.com/phalcon/backer/8/website" target="_blank"><img src="https://opencollective.com/phalcon/backer/8/avatar.svg"></a>
<a href="https://opencollective.com/phalcon/backer/9/website" target="_blank"><img src="https://opencollective.com/phalcon/backer/9/avatar.svg"></a>
<a href="https://opencollective.com/phalcon/backer/10/website" target="_blank"><img src="https://opencollective.com/phalcon/backer/10/avatar.svg"></a>
<a href="https://opencollective.com/phalcon/backer/11/website" target="_blank"><img src="https://opencollective.com/phalcon/backer/11/avatar.svg"></a>
<a href="https://opencollective.com/phalcon/backer/12/website" target="_blank"><img src="https://opencollective.com/phalcon/backer/12/avatar.svg"></a>
<a href="https://opencollective.com/phalcon/backer/13/website" target="_blank"><img src="https://opencollective.com/phalcon/backer/13/avatar.svg"></a>
<a href="https://opencollective.com/phalcon/backer/14/website" target="_blank"><img src="https://opencollective.com/phalcon/backer/14/avatar.svg"></a>
<a href="https://opencollective.com/phalcon/backer/15/website" target="_blank"><img src="https://opencollective.com/phalcon/backer/15/avatar.svg"></a>
<a href="https://opencollective.com/phalcon/backer/16/website" target="_blank"><img src="https://opencollective.com/phalcon/backer/16/avatar.svg"></a>
<a href="https://opencollective.com/phalcon/backer/17/website" target="_blank"><img src="https://opencollective.com/phalcon/backer/17/avatar.svg"></a>
<a href="https://opencollective.com/phalcon/backer/18/website" target="_blank"><img src="https://opencollective.com/phalcon/backer/18/avatar.svg"></a>
<a href="https://opencollective.com/phalcon/backer/19/website" target="_blank"><img src="https://opencollective.com/phalcon/backer/19/avatar.svg"></a>
<a href="https://opencollective.com/phalcon/backer/20/website" target="_blank"><img src="https://opencollective.com/phalcon/backer/20/avatar.svg"></a>
<a href="https://opencollective.com/phalcon/backer/21/website" target="_blank"><img src="https://opencollective.com/phalcon/backer/21/avatar.svg"></a>
<a href="https://opencollective.com/phalcon/backer/22/website" target="_blank"><img src="https://opencollective.com/phalcon/backer/22/avatar.svg"></a>
<a href="https://opencollective.com/phalcon/backer/23/website" target="_blank"><img src="https://opencollective.com/phalcon/backer/23/avatar.svg"></a>
<a href="https://opencollective.com/phalcon/backer/24/website" target="_blank"><img src="https://opencollective.com/phalcon/backer/24/avatar.svg"></a>
<a href="https://opencollective.com/phalcon/backer/25/website" target="_blank"><img src="https://opencollective.com/phalcon/backer/25/avatar.svg"></a>
<a href="https://opencollective.com/phalcon/backer/26/website" target="_blank"><img src="https://opencollective.com/phalcon/backer/26/avatar.svg"></a>
<a href="https://opencollective.com/phalcon/backer/27/website" target="_blank"><img src="https://opencollective.com/phalcon/backer/27/avatar.svg"></a>
<a href="https://opencollective.com/phalcon/backer/28/website" target="_blank"><img src="https://opencollective.com/phalcon/backer/28/avatar.svg"></a>
<a href="https://opencollective.com/phalcon/backer/29/website" target="_blank"><img src="https://opencollective.com/phalcon/backer/29/avatar.svg"></a>

## License
Phalcon is open source software licensed under the New BSD License. See the docs/LICENSE.txt file for more or visit our [license](https://license.phalconphp.com) page.
