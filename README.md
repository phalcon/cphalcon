# Phalcon Framework

[![Latest Version][packagist-version-badge]][packagist-version-link]
[![PHP Version][php-version-badge]][packagist-version-link]
[![Total Downloads][packagist-downloads-badge]][packagist-downloads-link]
[![License][license-badge]][license-link]

[![Phalcon 5.x CI][phalcon-5x-badge]][action-5x-link]
[![Quality Gate (phalcon)][sonar-quality-badge]][sonar-link]
[![Coverage (phalcon)][sonar-coverage-badge]][sonar-link]

[![Discord][discord-badge]][discord-link]
[![Contributors][contributors-badge]][contributors-link]
[![OpenCollective Backers][oc-backers-badge]][backers-link]
[![OpenCollective Sponsors][oc-sponsors-badge]][sponsors-link]

[![5.0 Pull Requests][phalcon-5x-pr-badge]][phalcon-5x-pr-link]
[![5.0 Issues][phalcon-5x-issue-badge]][phalcon-5x-issue-link]


Phalcon is an open-source web framework delivered as a C extension for PHP, providing high performance and lower resource consumption.

A big thank you to our Backers; you rock!

## Getting Started

Phalcon is written in [Zephir/C](https://zephir-lang.com/) with platform independence in mind.
As a result, Phalcon is available on Microsoft Windows, GNU/Linux, FreeBSD and macOS.
You can either download a binary package for the system of your choice or build it from source.

## Installation

### Using PIE (recommended)

[PIE](https://github.com/php/pie) is the modern PHP extension installer:

```bash
pie install phalcon/cphalcon
```

### Using PECL

> [!IMPORTANT]
> PECL has been deprecated, so users should switch to installing Phalcon with PIE. We will keep releasing on PECL until PECL is retired or v5.x reaches its end of life.

```bash
pecl install phalcon
```

### From source

For detailed installation instructions you can check our [installation](https://docs.phalcon.io/latest/installation/) page in the docs.

## Generating API Documentation

Generating new documentation files for docs repository can be done using the script in bin/generate-api-docs.php.
Steps:
- Clone the phalcon repo
- Checkout the tag you would like to generate docs for.
- Run `php bin/generate-api-docs.php`
- The generated `*.md` files will contain the documentation
- For publishing to the Phalcon website this [repo](https://github.com/phalcon/docs/tree/5.0/api) is used.

## Sponsors and backers

These sponsors and backers support Phalcon and Zephir. To join them, become a sponsor or a backer on [Open Collective](https://opencollective.com/phalcon) or [GitHub Sponsors](https://phalcon.io/fund).

<!-- The roster below is generated every day by the "Update backers" workflow from the phalcon/assets roster. Do not edit it by hand. -->
<!-- backers:start -->

### Sponsors

<a href="https://opencollective.com/commercesuite"><img src="https://images.opencollective.com/commercesuite/5c683c0/logo.png" alt="Commercesuite" title="Commercesuite" height="40"></a>
<a href="https://github.com/markofo"><img src="https://avatars.githubusercontent.com/u/59839390?v=4" alt="markofo" title="markofo" height="40"></a>

### Partners

<a href="https://abits.com"><img src="https://assets.phalcon.io/phalcon/images/backers/abits-100x34.svg" alt="Abits" title="Abits" height="40"></a>
<a href="https://www.cloudflare.com/"><img src="https://assets.phalcon.io/phalcon/images/backers/cloudflare.svg" alt="Cloudflare" title="Cloudflare" height="40"></a>
<a href="https://crowdin.com/"><img src="https://assets.phalcon.io/phalcon/images/backers/crowdin.png" alt="Crowdin" title="Crowdin" height="40"></a>
<a href="https://www.digitalocean.com/"><img src="https://assets.phalcon.io/phalcon/images/backers/digitalocean.svg" alt="DigitalOcean" title="DigitalOcean" height="40"></a>
<a href="https://mctekk.com"><img src="https://assets.phalcon.io/phalcon/images/backers/mctekk-149x34.svg" alt="mctekk" title="mctekk" height="40"></a>
<a href="https://odva.pro/"><img src="https://assets.phalcon.io/phalcon/images/backers/odva.svg" alt="odva" title="odva" height="40"></a>

### Supporters

<a href="https://github.com/elstin"><img src="https://avatars.githubusercontent.com/u/38716832?u=d219979f0233713ca897b1ea3dfaae57144d3a77&amp;v=4" alt="Akira Kato" title="Akira Kato" width="60" height="60"></a>
<a href="https://github.com/alrieckert"><img src="https://avatars.githubusercontent.com/u/452786?v=4" alt="Anton Rieckert" title="Anton Rieckert" width="60" height="60"></a>
<a href="https://opencollective.com/barry"><img src="https://images.opencollective.com/barry/avatar.png" alt="Barry Helfrich" title="Barry Helfrich" width="60" height="60"></a>
<a href="https://bd.fyi"><img src="https://images.opencollective.com/borisdelev/7630f7b/avatar.png" alt="Boris Delev" title="Boris Delev" width="60" height="60"></a>
<a href="https://github.com/fvromera"><img src="https://avatars.githubusercontent.com/u/32909196?u=a4a6d765c836be52ab247354399d0ed1a49224fa&amp;v=4" alt="Chess" title="Chess" width="60" height="60"></a>
<a href="https://opencollective.com/guest-163314bf"><img src="https://images.opencollective.com/guest-163314bf/avatar.png" alt="D3" title="D3" width="60" height="60"></a>
<a href="https://github.com/f-do"><img src="https://avatars.githubusercontent.com/u/4299065?u=66d3687ffd970119b19d39694a5ddf87294d0bd5&amp;v=4" alt="Florian" title="Florian" width="60" height="60"></a>
<a href="https://github.com/francoisgrogor"><img src="https://avatars.githubusercontent.com/u/5804565?v=4" alt="francoisgrogor" title="francoisgrogor" width="60" height="60"></a>
<a href="https://github.com/housesigma"><img src="https://avatars.githubusercontent.com/u/50630040?v=4" alt="HouseSigma" title="HouseSigma" width="60" height="60"></a>
<a href="https://www.ultimater.net"><img src="https://images.opencollective.com/ultimater/19fc150/avatar.png" alt="Kevin Yarmak" title="Kevin Yarmak" width="60" height="60"></a>
<a href="https://opencollective.com/info23"><img src="https://images.opencollective.com/info23/eebb146/avatar.png" alt="maGus Informática" title="maGus Informática" width="60" height="60"></a>
<a href="https://github.com/niden"><img src="https://avatars.githubusercontent.com/u/1073784?v=4" alt="Nikolaos Dimopoulos" title="Nikolaos Dimopoulos" width="60" height="60"></a>
<a href="https://github.com/rayanlevert"><img src="https://avatars.githubusercontent.com/u/78140431?u=e9757b8d038f97b4e81c104378657275cc24d150&amp;v=4" alt="Rayan Levert" title="Rayan Levert" width="60" height="60"></a>

### Backers

<a href="https://github.com/elcreator"><img src="https://avatars.githubusercontent.com/u/974975?u=f1bbb9b9c676bc2141bb68fed8f0533a26322632&amp;v=4" alt="Artur Kyryliuk" title="Artur Kyryliuk" width="60" height="60"></a>
<a href="https://github.com/raicabogdan"><img src="https://avatars.githubusercontent.com/u/4399340?v=4" alt="Bogdan Raica" title="Bogdan Raica" width="60" height="60"></a>
<a href="https://opencollective.com/christian-jay-bayno"><img src="https://images.opencollective.com/christian-jay-bayno/c6aab1d/avatar.png" alt="Ceage10" title="Ceage10" width="60" height="60"></a>
<a href="https://github.com/6trading"><img src="https://avatars.githubusercontent.com/u/12135941?u=befb955111226257bb44aec408af3229904d2831&amp;v=4" alt="Chris" title="Chris" width="60" height="60"></a>
<a href="https://github.com/iogates"><img src="https://avatars.githubusercontent.com/u/86652317?v=4" alt="ioGates" title="ioGates" width="60" height="60"></a>
<a href="https://aircode.pl/"><img src="https://images.opencollective.com/aircode/3e9590d/avatar.png" alt="Mateusz Pająk / Aircode" title="Mateusz Pająk / Aircode" width="60" height="60"></a>
<a href="https://github.com/dredasss"><img src="https://avatars.githubusercontent.com/u/38747389?u=ee99a8bb28ee6bedbbea6325d49d4eb99080d421&amp;v=4" alt="Nerijus Alex" title="Nerijus Alex" width="60" height="60"></a>
<a href="https://github.com/tztztztz"><img src="https://avatars.githubusercontent.com/u/7032308?v=4" alt="Tomasz Zadora" title="Tomasz Zadora" width="60" height="60"></a>

<!-- backers:end -->

## Core Team

[Anton](https://github.com/Jeckerson), [Nikolaos](https://github.com/niden)

![Alt](https://repobeats.axiom.co/api/embed/8ab44186e80c2f075c6b51603fd7cf2a80a2cb33.svg "Repobeats analytics image")

## Links

### General
* [Contributing to Phalcon](CONTRIBUTING.md)
* [Official Documentation](https://docs.phalcon.io/)
* [Zephir](https://zephir-lang.com/) - the language Phalcon is written in
* [Incubator](https://phalcon.io/incubator) - community-driven plugins and classes that extend the framework (written in PHP)

### Support
* [Discussions](https://phalcon.io/discussions)
* [Discord](https://phalcon.io/discord)
* [Stack Overflow](https://phalcon.io/so)

### Social Media
* [Telegram](https://phalcon.io/telegram)
* [Gab](https://phalcon.io/gab)
* [LinkedIn](https://phalcon.io/linkedin)
* [MeWe](https://phalcon.io/mewe)
* [Facebook](https://phalcon.io/fb)
* [Twitter](https://phalcon.io/t)

## License

Phalcon is open-source software licensed under the BSD 3-Clause License.

Copyright © 2011-present, Phalcon Team.

See the [LICENSE](https://github.com/phalcon/cphalcon/blob/master/LICENSE.txt) file or [license.phalcon.io](https://license.phalcon.io) for details. The licenses of the packages that Phalcon uses, is inspired by, or has adapted are also in the [3rdparty/licenses](https://github.com/phalcon/cphalcon/blob/master/3rdparty/licenses) directory.


<!-- Badges: package -->
[packagist-version-badge]:   https://img.shields.io/packagist/v/phalcon/cphalcon?style=flat-square&logo=packagist&logoColor=white
[packagist-version-link]:    https://packagist.org/packages/phalcon/cphalcon
[packagist-downloads-badge]: https://img.shields.io/packagist/dt/phalcon/cphalcon?style=flat-square&logo=packagist&logoColor=white
[packagist-downloads-link]:  https://packagist.org/packages/phalcon/cphalcon/stats
[php-version-badge]:          https://img.shields.io/packagist/php-v/phalcon/cphalcon?style=flat-square&logo=php&logoColor=white
[license-badge]:             https://img.shields.io/github/license/phalcon/cphalcon?style=flat-square&logo=opensourceinitiative&logoColor=white
[license-link]:              https://github.com/phalcon/cphalcon/blob/master/LICENSE.txt

<!-- Badges: quality & build -->
[phalcon-5x-badge]:         https://github.com/phalcon/cphalcon/actions/workflows/main.yml/badge.svg?branch=5.0.x
[action-5x-link]:           https://github.com/phalcon/cphalcon/actions/workflows/main.yml
[sonar-quality-badge]:      https://sonarcloud.io/api/project_badges/measure?project=phalcon_phalcon&metric=alert_status
[sonar-coverage-badge]:     https://sonarcloud.io/api/project_badges/measure?project=phalcon_phalcon&metric=coverage
[sonar-link]:               https://sonarcloud.io/summary/new_code?id=phalcon_phalcon

<!-- Links: community & activity -->
[discord-link]:             https://phalcon.io/discord
[contributors-link]:        https://github.com/phalcon/cphalcon/graphs/contributors
[backers-link]:             #backers
[sponsors-link]:            #sponsors
[phalcon-5x-pr-link]:       https://github.com/phalcon/cphalcon/pulls?q=is%3Apr+is%3Aopen+label%3A5.0
[phalcon-5x-issue-link]:    https://github.com/phalcon/cphalcon/issues?q=is%3Aissue+is%3Aopen+label%3A5.0

[discord-badge]:            https://img.shields.io/discord/310910488152375297?label=Discord&logo=discord&style=flat-square
[contributors-badge]:       https://img.shields.io/github/contributors/phalcon/cphalcon?style=flat-square&logo=github&logoColor=white
[oc-backers-badge]:         https://img.shields.io/opencollective/backers/phalcon?style=flat-square&logo=opencollective&logoColor=white
[oc-sponsors-badge]:        https://img.shields.io/opencollective/sponsors/phalcon?style=flat-square&logo=opencollective&logoColor=white
[phalcon-5x-pr-badge]:      https://img.shields.io/github/issues-pr/phalcon/cphalcon/5.0?color=brightgreen&style=flat-square&logo=github&logoColor=white
[phalcon-5x-issue-badge]:   https://img.shields.io/github/issues-raw/phalcon/cphalcon/5.0?color=yellow&style=flat-square&logo=github&logoColor=white
