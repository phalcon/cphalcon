# Phalcon Framework

[![Build Status](https://travis-ci.org/phalcon/cphalcon.svg?branch=master)](https://travis-ci.org/phalcon/cphalcon)
[![Windows Build](https://ci.appveyor.com/api/projects/status/wkws3mgxaoy0u9a6/branch/master?svg=true)](https://ci.appveyor.com/project/sergeyklay/cphalcon/branch/master)
[![Phalcon Backers](https://img.shields.io/badge/phalcon-backers-99ddc0.svg)](https://github.com/phalcon/cphalcon/blob/master/BACKERS.md)
[![OpenCollective](https://opencollective.com/phalcon/backers/badge.svg)](#backers)
[![OpenCollective](https://opencollective.com/phalcon/sponsors/badge.svg)](#sponsors)

Phalcon is an open source web framework delivered as a C extension for the PHP language providing high performance and lower resource consumption.

A big thank you to [our Backers](https://github.com/phalcon/cphalcon/blob/master/BACKERS.md); you rock!

## Getting Started

Phalcon is written in [Zephir/C](https://zephir-lang.com/) with platform independence in mind.
As a result, Phalcon is available on Microsoft Windows, GNU/Linux, FreeBSD and MacOS.
You can either download a binary package for the system of your choice or build it from source.

**NOTE:** Phalcon requires the [PSR PHP extension](https://github.com/jbboehr/php-psr) to be installed and enabled.

## Installation

For detailed installation instructions you can check our [installation](https://docs.phalcon.io/4.0/en/installation) page in the docs.

## Generating API Documentation

Generating new documentation files for docs repository can be done using the script in tests/_ci/generate-api-docs.php.
Steps:
- Clone the phalcon repo
- Checkout the tag you would like to generate docs for.
- Run `php tests/_ci/generate-api-docs.php`
- The files *.md files in nikos/api/ will contain the documentation
- For publishing to the Phalcon website this [repo](https://github.com/phalcon/docs/tree/4.0/en/api) is used.

## Links

### General
* [Contributing to Phalcon](CONTRIBUTING.md) 
* [Official Documentation](https://docs.phalcon.io/)
* [Zephir](https://zephir-lang.com/) - The language Phalcon is written on
* [Incubator](https://phalcon.link/incubator) - Community driven plugins and classes extending the framework (written in PHP)

### Support
* [Forum](https://phalcon.link/forum)
* [Discord](https://phalcon.link/discord)
* [Stack Overflow](https://phalcon.link/so)

### Social Media
* [Telegram](https://phalcon.link/telegram)
* [Gab](https://phalcon.link/gab)
* [Parler](https://phalcon.link/parler)
* [MeWe](https://phalcon.link/mewe)
* [Facebook](https://phalcon.link/fb)
* [Twitter](https://phalcon.link/t)


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

Copyright © 2011-present, Phalcon Team.

See the [LICENSE.txt](https://github.com/phalcon/cphalcon/blob/master/LICENSE.txt) file for more. Additional licenses of packages that Phalcon uses, is inspired by or has adapted is located in the [3rdparty/licenses][https://github.com/phalcon/cphalcon/blob/master/3rdparty/licenses] directory.
