# Phalcon Framework

[![Build Status](https://travis-ci.org/phalcon/cphalcon.svg?branch=master)](https://travis-ci.org/phalcon/cphalcon)
[![Windows Build](https://ci.appveyor.com/api/projects/status/wkws3mgxaoy0u9a6/branch/master?svg=true)](https://ci.appveyor.com/project/sergeyklay/cphalcon/branch/master)
[![Phalcon Backers](https://img.shields.io/badge/phalcon-backers-99ddc0.svg)](https://github.com/phalcon/cphalcon/blob/master/BACKERS.md)
[![OpenCollective](https://opencollective.com/phalcon/backers/badge.svg)](#backers)
[![OpenCollective](https://opencollective.com/phalcon/sponsors/badge.svg)](#sponsors)

Phalcon is an open source web framework delivered as a C extension for the PHP language providing high
performance and lower resource consumption.

Phalcon is written in [Zephir/C](https://zephir-lang.com/) with platform independence in mind.
As a result, Phalcon is available on Microsoft Windows, GNU/Linux, FreeBSD and MacOS.
You can either download a binary package for the system of your choice or build it from source.

A big thank you to [our Backers](https://github.com/phalcon/cphalcon/blob/master/BACKERS.md); you rock!

## Contents

- [Get Started](#get-started)
  - [Windows](#windows)
  - [Linux/Unix/Mac](#linuxunixmac)
    - [Requirements](#requirements)
      - [Ubuntu](#ubuntu)
      - [Suse](#suse)
      - [CentOS/Fedora/RHEL](#centosfedorarhel)
    - [macOS](#macos)
    - [Gentoo](#gentoo)
    - [Compilation](#compilation)
- [Contributing](#contributing)
- [External Links](#external-links)
- [Meet the Incubator](#meet-the-incubator)
- [Sponsors](#sponsors)
- [Backers](#backers)
- [License](#license)

## Get Started

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

* PHP 5.5.x/5.6.x/7.0.x/7.1.x/7.2.x development resources (PHP 5.3 and 5.4 are no longer supported)
* `g++` >= 4.4 | `clang++` >= 3.x | `vc++` >= 11
* GNU `make` >= 3.81
* [`re2c`](http://re2c.org) >= 0.13

NOTE: Support for PHP 5.x is provided on a best-effort basis and will be removed in near future.

##### Ubuntu

```bash
# Use actual PHP development headers and tools here
sudo apt-get install php5-dev libpcre3-dev gcc make re2c
```

##### Suse

```bash
# Use actual PHP development headers and tools here
sudo zypper install php5-devel gcc make re2c
```

##### CentOS/Fedora/RHEL

```bash
# Use actual PHP development headers and tools here
sudo yum install php-devel pcre-devel gcc make re2c
```

#### macOS

We recommend to use command line to build Phalcon extension suitable for your system.
Another way is to use OSX MAMP ready extension: https://github.com/majksner/php-phalcon-mamp

#### Gentoo

There is Gentoo ebuilds maintained for the Phalcon Framework: https://github.com/smoke/phalcon-gentoo-overlay

#### Compilation

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

See [CONTRIBUTING.md](CONTRIBUTING.md) for details.

## External Links

* [Documentation](https://docs.phalconphp.com/)
* [Support](https://forum.phalconphp.com)
* [Zephir](https://zephir-lang.com/)
* [Twitter](https://twitter.com/phalconphp)

## Meet the Incubator

Our community is developing amazing extra features for Phalcon every day via [Incubator](https://github.com/phalcon/incubator).
There are resources to enhance your experience with the framework and that enlarge the main features.

Just give it a try and help us improve Phalcon even more!

## Sponsors

Become a sponsor and get your logo on our README on Github with a link to your site. [[Become a sponsor](https://opencollective.com/phalcon#sponsor)]

<a href="https://opencollective.com/phalcon/#contributors">
<img src="https://opencollective.com/phalcon/tiers/sponsors.svg?avatarHeight=48&width=800">
</a>

## Backers

Support us with a monthly donation and help us continue our activities. [[Become a backer](https://opencollective.com/phalcon#backer)]

<a href="https://opencollective.com/phalcon/#contributors">
<img src="https://opencollective.com/phalcon/tiers/backers.svg?avatarHeight=48&width=800&height=200">
</a>

## License

Phalcon is open source software licensed under the BSD 3-Clause License.
Copyright © 2011-present, Phalcon Team.<br>
See the [LICENSE.txt](https://github.com/phalcon/cphalcon/blob/master/LICENSE.txt) file for more.
