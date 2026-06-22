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
[![Phalcon Backers][backers-badge]][phalcon-backers-link]
[![OpenCollective Backers][oc-backers-badge]][backers-link]
[![OpenCollective Sponsors][oc-sponsors-badge]][sponsors-link]

[![5.0 Pull Requests][phalcon-5x-pr-badge]][phalcon-5x-pr-link]
[![5.0 Issues][phalcon-5x-issue-badge]][phalcon-5x-issue-link]


Phalcon is an open-source web framework delivered as a C extension for PHP, providing high performance and lower resource consumption.

A big thank you to [our Backers](https://github.com/phalcon/cphalcon/blob/master/BACKERS.md); you rock!

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

## Links

### General
* [Contributing to Phalcon](CONTRIBUTING.md)
* [Official Documentation](https://docs.phalcon.io/)
* [Zephir](https://zephir-lang.com/) — the language Phalcon is written in
* [Incubator](https://phalcon.io/incubator) — community-driven plugins and classes that extend the framework (written in PHP)

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


## Sponsors

Become a sponsor and get your logo on our README on GitHub with a link to your site. [[Become a sponsor](https://opencollective.com/phalcon#sponsor)]

<a href="https://opencollective.com/phalcon/#contributors">
<img src="https://opencollective.com/phalcon/tiers/sponsors.svg?avatarHeight=48&width=800" alt="OpenCollective Sponsors">
</a>

## Backers

Support us with a monthly donation and help us continue our activities. [[Become a backer](https://opencollective.com/phalcon#backer)]

<a href="https://opencollective.com/phalcon/#contributors">
<img src="https://opencollective.com/phalcon/tiers/backers.svg?avatarHeight=48&width=800&height=200" alt="OpenCollective Backers">
</a>

## License

Phalcon is open-source software licensed under the BSD 3-Clause License.

Copyright © 2011–present, Phalcon Team.

See the [LICENSE.txt](https://github.com/phalcon/cphalcon/blob/master/LICENSE.txt) file for details. Additional licenses of packages that Phalcon uses, is inspired by, or has adapted are located in the [3rdparty/licenses](https://github.com/phalcon/cphalcon/blob/master/3rdparty/licenses) directory.


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
[phalcon-backers-link]:     https://github.com/phalcon/cphalcon/blob/master/BACKERS.md
[backers-link]:             #backers
[sponsors-link]:            #sponsors
[phalcon-5x-pr-link]:       https://github.com/phalcon/cphalcon/pulls?q=is%3Apr+is%3Aopen+label%3A5.0
[phalcon-5x-issue-link]:    https://github.com/phalcon/cphalcon/issues?q=is%3Aissue+is%3Aopen+label%3A5.0

[discord-badge]:            https://img.shields.io/discord/310910488152375297?label=Discord&logo=discord&style=flat-square
[contributors-badge]:       https://img.shields.io/github/contributors/phalcon/cphalcon?style=flat-square&logo=github&logoColor=white
[backers-badge]:            https://img.shields.io/badge/phalcon-backers-99ddc0.svg?&style=flat-square&logo=data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAA4AAAAOCAYAAAAfSC3RAAAAGXRFWHRTb2Z0d2FyZQBBZG9iZSBJbWFnZVJlYWR5ccllPAAAAyZpVFh0WE1MOmNvbS5hZG9iZS54bXAAAAAAADw/eHBhY2tldCBiZWdpbj0i77u/IiBpZD0iVzVNME1wQ2VoaUh6cmVTek5UY3prYzlkIj8+IDx4OnhtcG1ldGEgeG1sbnM6eD0iYWRvYmU6bnM6bWV0YS8iIHg6eG1wdGs9IkFkb2JlIFhNUCBDb3JlIDUuNi1jMTQyIDc5LjE2MDkyNCwgMjAxNy8wNy8xMy0wMTowNjozOSAgICAgICAgIj4gPHJkZjpSREYgeG1sbnM6cmRmPSJodHRwOi8vd3d3LnczLm9yZy8xOTk5LzAyLzIyLXJkZi1zeW50YXgtbnMjIj4gPHJkZjpEZXNjcmlwdGlvbiByZGY6YWJvdXQ9IiIgeG1sbnM6eG1wPSJodHRwOi8vbnMuYWRvYmUuY29tL3hhcC8xLjAvIiB4bWxuczp4bXBNTT0iaHR0cDovL25zLmFkb2JlLmNvbS94YXAvMS4wL21tLyIgeG1sbnM6c3RSZWY9Imh0dHA6Ly9ucy5hZG9iZS5jb20veGFwLzEuMC9zVHlwZS9SZXNvdXJjZVJlZiMiIHhtcDpDcmVhdG9yVG9vbD0iQWRvYmUgUGhvdG9zaG9wIENDIDIwMTggKFdpbmRvd3MpIiB4bXBNTTpJbnN0YW5jZUlEPSJ4bXAuaWlkOjc3RTA0NTM1MEE1ODExRUFBNENEOUNDREQ1RDJGQ0FBIiB4bXBNTTpEb2N1bWVudElEPSJ4bXAuZGlkOjc3RTA0NTM2MEE1ODExRUFBNENEOUNDREQ1RDJGQ0FBIj4gPHhtcE1NOkRlcml2ZWRGcm9tIHN0UmVmOmluc3RhbmNlSUQ9InhtcC5paWQ6NzdFMDQ1MzMwQTU4MTFFQUE0Q0Q5Q0NERDVEMkZDQUEiIHN0UmVmOmRvY3VtZW50SUQ9InhtcC5kaWQ6NzdFMDQ1MzQwQTU4MTFFQUE0Q0Q5Q0NERDVEMkZDQUEiLz4gPC9yZGY6RGVzY3JpcHRpb24+IDwvcmRmOlJERj4gPC94OnhtcG1ldGE+IDw/eHBhY2tldCBlbmQ9InIiPz4mTnOmAAACyklEQVR42nxSyU8TcRj9fvObaQsMhS5UW8ACUkG2sEqiLCGRi0S2gxoPGmP8B4xHa6IHPRg0kZh4ksQgIhE5CCYmKC4NrTExlgqhbLULDJ1pZWmhnbYz4wBe9SUv3+W9vOR9DzXU1gEmSbh67zpYqspoVZLoJABeAiBBAgn2IIkCiJIIlKyb8y7DpcZOIBIpsSce3Wl9OzgG/s2gfkdM3JQkNCbrNfAfEPqe1oAqXTngcfx88bn/1VEmFFyLkamzctaknFj+T6OhrZHJv3w6TBu1F75OfHwzZO1X2O3TsSjwtZRCOSVruhAgINABkcw9YM+X79tpKVGT21beTpv0FDv3y+x656CWF5cgS6/JMOblnttN8vaYJKwIsoHb+A21+aWAuzraoMJc5Eqy0QrBkFaibSyWe0EQ+OYGx/gUaHValDBpDCNzM8POECuuMwHorDwJiBEZ4BM8RDaTeU7nzHBY2j0VouLgda9AaNYL8dUNaO8949/JwSVcNBLjI3EYuHILcF1pHTRVN4GB1m67JXZKBOl4UbbRaCksRqYaCyIrD0GGLotuMJfVL6z7TDwA01PVvIkZhgGO5cA974bx9xObId3u8w2eP+LfYqu0RDpWCwrkm18Jp0tkQndY3xJkgue7alofEySB4fXoKDzqe4jXFj1qTbH5NkK4u7m4WlmYaUAL4/Znk31DNT8mp08UENpjgRHb3b1WSZGmQJFGglKvxpaOlhvupzZrc1ktcLqN7Q+2T4LXv5CuUinzF2fdq+sPngjsWnBw31hvvQjyngDotOSS3eniHR7B0NuNbb45QsSSFacghSlyjWNY4JigHKLa/yPJBzmIyAQVJUUDvnljgfG+Vq8vo7ZUFlpBX4t5QlZMYR+SiIPJSAf7JXfCEQj7w0BSCsgQVV6WW72jlqiCvJwCPO1azI7x8SVamQnEX4Moivv3jwADAA9sObdCbqMjAAAAAElFTkSuQmCC
[oc-backers-badge]:         https://img.shields.io/opencollective/backers/phalcon?style=flat-square&logo=opencollective&logoColor=white
[oc-sponsors-badge]:        https://img.shields.io/opencollective/sponsors/phalcon?style=flat-square&logo=opencollective&logoColor=white
[phalcon-5x-pr-badge]:      https://img.shields.io/github/issues-pr/phalcon/cphalcon/5.0?color=brightgreen&style=flat-square&logo=github&logoColor=white
[phalcon-5x-issue-badge]:   https://img.shields.io/github/issues-raw/phalcon/cphalcon/5.0?color=yellow&style=flat-square&logo=github&logoColor=white
