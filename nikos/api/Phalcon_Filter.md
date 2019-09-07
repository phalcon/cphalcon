---
layout: default
language: 'en'
version: '4.0'
title: 'Phalcon\Filter'
---

* [Phalcon\Filter\Exception](#filter-exception)
* [Phalcon\Filter\Filter](#filter-filter)
* [Phalcon\Filter\FilterFactory](#filter-filterfactory)
* [Phalcon\Filter\FilterInterface](#filter-filterinterface)
* [Phalcon\Filter\Sanitize\AbsInt](#filter-sanitize-absint)
* [Phalcon\Filter\Sanitize\Alnum](#filter-sanitize-alnum)
* [Phalcon\Filter\Sanitize\Alpha](#filter-sanitize-alpha)
* [Phalcon\Filter\Sanitize\BoolVal](#filter-sanitize-boolval)
* [Phalcon\Filter\Sanitize\Email](#filter-sanitize-email)
* [Phalcon\Filter\Sanitize\FloatVal](#filter-sanitize-floatval)
* [Phalcon\Filter\Sanitize\IntVal](#filter-sanitize-intval)
* [Phalcon\Filter\Sanitize\Lower](#filter-sanitize-lower)
* [Phalcon\Filter\Sanitize\LowerFirst](#filter-sanitize-lowerfirst)
* [Phalcon\Filter\Sanitize\Regex](#filter-sanitize-regex)
* [Phalcon\Filter\Sanitize\Remove](#filter-sanitize-remove)
* [Phalcon\Filter\Sanitize\Replace](#filter-sanitize-replace)
* [Phalcon\Filter\Sanitize\Special](#filter-sanitize-special)
* [Phalcon\Filter\Sanitize\SpecialFull](#filter-sanitize-specialfull)
* [Phalcon\Filter\Sanitize\StringVal](#filter-sanitize-stringval)
* [Phalcon\Filter\Sanitize\Striptags](#filter-sanitize-striptags)
* [Phalcon\Filter\Sanitize\Trim](#filter-sanitize-trim)
* [Phalcon\Filter\Sanitize\Upper](#filter-sanitize-upper)
* [Phalcon\Filter\Sanitize\UpperFirst](#filter-sanitize-upperfirst)
* [Phalcon\Filter\Sanitize\UpperWords](#filter-sanitize-upperwords)
* [Phalcon\Filter\Sanitize\Url](#filter-sanitize-url)
        
<h1 id="filter-exception">Class Phalcon\Filter\Exception</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/filter/exception.zep)

| Namespace  | Phalcon\Filter |
| Extends    | \Phalcon\Exception |

Phalcon\Filter\Exception

Exceptions thrown in Phalcon\Filter will use this class


        
<h1 id="filter-filter">Class Phalcon\Filter\Filter</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/filter/filter.zep)

| Namespace  | Phalcon\Filter |
| Uses       | Closure, Phalcon\Filter\Exception, Phalcon\Filter\FilterInterface |
| Implements | FilterInterface |

Lazy loads, stores and exposes sanitizer objects


## Constants
```php
const FILTER_ABSINT = absint;
const FILTER_ALNUM = alnum;
const FILTER_ALPHA = alpha;
const FILTER_BOOL = bool;
const FILTER_EMAIL = email;
const FILTER_FLOAT = float;
const FILTER_INT = int;
const FILTER_LOWER = lower;
const FILTER_LOWERFIRST = lowerFirst;
const FILTER_REGEX = regex;
const FILTER_REMOVE = remove;
const FILTER_REPLACE = replace;
const FILTER_SPECIAL = special;
const FILTER_SPECIALFULL = specialFull;
const FILTER_STRING = string;
const FILTER_STRIPTAGS = striptags;
const FILTER_TRIM = trim;
const FILTER_UPPER = upper;
const FILTER_UPPERFIRST = upperFirst;
const FILTER_UPPERWORDS = upperWords;
const FILTER_URL = url;
```

## Properties
```php
/**
 * @var array
 */
protected mapper;

/**
 * @var array
 */
protected services;

```

## Methods
```php
public function __construct( array $mapper = [] ): void;
```
Key value pairs with name as the key and a callable as the value for
the service object


```php
public function get( string $name ): object;
```
Get a service. If it is not in the mapper array, create a new object,
set it and then return it.


```php
public function has( string $name ): bool;
```
Checks if a service exists in the map array


```php
public function sanitize( mixed $value, mixed $sanitizers, bool $noRecursive = bool ): mixed;
```
Sanitizes a value with a specified single or set of sanitizers


```php
public function set( string $name, callable $service ): void;
```
Set a new service to the mapper array


```php
protected function init( array $mapper ): void;
```
Loads the objects in the internal mapper array



        
<h1 id="filter-filterfactory">Class Phalcon\Filter\FilterFactory</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/filter/filterfactory.zep)

| Namespace  | Phalcon\Filter |
| Uses       | Phalcon\Filter\Filter |

This file is part of the Phalcon Framework.

(c) Phalcon Team <team@phalcon.io>

For the full copyright and license information, please view the LICENSE.txt
file that was distributed with this source code.


## Methods
```php
public function newInstance(): LocatorInterface;
```
Returns a Locator object with all the helpers defined in anonynous
functions


```php
protected function getAdapters(): array;
```
//


        
<h1 id="filter-filterinterface">Interface Phalcon\Filter\FilterInterface</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/filter/filterinterface.zep)

| Namespace  | Phalcon\Filter |

Lazy loads, stores and exposes sanitizer objects


## Methods
```php
public function sanitize( mixed $value, mixed $sanitizers, bool $noRecursive = bool ): mixed;
```
Sanitizes a value with a specified single or set of sanitizers



        
<h1 id="filter-sanitize-absint">Class Phalcon\Filter\Sanitize\AbsInt</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/filter/sanitize/absint.zep)

| Namespace  | Phalcon\Filter\Sanitize |

Phalcon\Filter\Sanitize\AbsInt

Sanitizes a value to absolute integer


## Methods
```php
public function __invoke( mixed $input );
```
@var mixed input The text to sanitize



        
<h1 id="filter-sanitize-alnum">Class Phalcon\Filter\Sanitize\Alnum</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/filter/sanitize/alnum.zep)

| Namespace  | Phalcon\Filter\Sanitize |

Phalcon\Filter\Sanitize\Alnum

Sanitizes a value to an alphanumeric value


## Methods
```php
public function __invoke( mixed $input );
```
@var mixed input The text to sanitize



        
<h1 id="filter-sanitize-alpha">Class Phalcon\Filter\Sanitize\Alpha</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/filter/sanitize/alpha.zep)

| Namespace  | Phalcon\Filter\Sanitize |

Phalcon\Filter\Sanitize\Alpha

Sanitizes a value to an alpha value


## Methods
```php
public function __invoke( mixed $input );
```
@var mixed input The text to sanitize



        
<h1 id="filter-sanitize-boolval">Class Phalcon\Filter\Sanitize\BoolVal</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/filter/sanitize/boolval.zep)

| Namespace  | Phalcon\Filter\Sanitize |

Phalcon\Filter\Sanitize\BoolVal

Sanitizes a value to boolean


## Methods
```php
public function __invoke( mixed $input );
```
@var mixed input The text to sanitize



        
<h1 id="filter-sanitize-email">Class Phalcon\Filter\Sanitize\Email</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/filter/sanitize/email.zep)

| Namespace  | Phalcon\Filter\Sanitize |

Phalcon\Filter\Sanitize\Email

Sanitizes an email string


## Methods
```php
public function __invoke( mixed $input );
```
@var mixed input The text to sanitize



        
<h1 id="filter-sanitize-floatval">Class Phalcon\Filter\Sanitize\FloatVal</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/filter/sanitize/floatval.zep)

| Namespace  | Phalcon\Filter\Sanitize |

Phalcon\Filter\Sanitize\FloatVal

Sanitizes a value to float


## Methods
```php
public function __invoke( mixed $input );
```
@var mixed input The text to sanitize



        
<h1 id="filter-sanitize-intval">Class Phalcon\Filter\Sanitize\IntVal</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/filter/sanitize/intval.zep)

| Namespace  | Phalcon\Filter\Sanitize |

Phalcon\Filter\Sanitize\IntVal

Sanitizes a value to integer


## Methods
```php
public function __invoke( mixed $input );
```
@var mixed input The text to sanitize



        
<h1 id="filter-sanitize-lower">Class Phalcon\Filter\Sanitize\Lower</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/filter/sanitize/lower.zep)

| Namespace  | Phalcon\Filter\Sanitize |

Phalcon\Filter\Sanitize\Lower

Sanitizes a value to lowercase


## Methods
```php
public function __invoke( string $input );
```
@var mixed input The text to sanitize



        
<h1 id="filter-sanitize-lowerfirst">Class Phalcon\Filter\Sanitize\LowerFirst</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/filter/sanitize/lowerfirst.zep)

| Namespace  | Phalcon\Filter\Sanitize |

Phalcon\Filter\Sanitize\LowerFirst

Sanitizes a value to lcfirst


## Methods
```php
public function __invoke( string $input );
```
@var mixed input The text to sanitize



        
<h1 id="filter-sanitize-regex">Class Phalcon\Filter\Sanitize\Regex</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/filter/sanitize/regex.zep)

| Namespace  | Phalcon\Filter\Sanitize |

Phalcon\Filter\Sanitize\Regex

Sanitizes a value performing preg_replace


## Methods
```php
public function __invoke( mixed $input, mixed $pattern, mixed $replace );
```
@var mixed input The text to sanitize



        
<h1 id="filter-sanitize-remove">Class Phalcon\Filter\Sanitize\Remove</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/filter/sanitize/remove.zep)

| Namespace  | Phalcon\Filter\Sanitize |

Phalcon\Filter\Sanitize\Remove

Sanitizes a value removing parts of a string


## Methods
```php
public function __invoke( mixed $input, mixed $replace );
```
@var mixed input The text to sanitize



        
<h1 id="filter-sanitize-replace">Class Phalcon\Filter\Sanitize\Replace</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/filter/sanitize/replace.zep)

| Namespace  | Phalcon\Filter\Sanitize |

Phalcon\Filter\Sanitize\Replace

Sanitizes a value replacing parts of a string


## Methods
```php
public function __invoke( mixed $input, mixed $from, mixed $to );
```
@var mixed input The text to sanitize



        
<h1 id="filter-sanitize-special">Class Phalcon\Filter\Sanitize\Special</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/filter/sanitize/special.zep)

| Namespace  | Phalcon\Filter\Sanitize |

Phalcon\Filter\Sanitize\Special

Sanitizes a value special characters


## Methods
```php
public function __invoke( mixed $input );
```
@var mixed input The text to sanitize



        
<h1 id="filter-sanitize-specialfull">Class Phalcon\Filter\Sanitize\SpecialFull</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/filter/sanitize/specialfull.zep)

| Namespace  | Phalcon\Filter\Sanitize |

Phalcon\Filter\Sanitize\SpecialFull

Sanitizes a value special characters (htmlspecialchars() and ENT_QUOTES)


## Methods
```php
public function __invoke( mixed $input );
```
@var mixed input The text to sanitize



        
<h1 id="filter-sanitize-stringval">Class Phalcon\Filter\Sanitize\StringVal</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/filter/sanitize/stringval.zep)

| Namespace  | Phalcon\Filter\Sanitize |

Phalcon\Filter\Sanitize\String

Sanitizes a value to string


## Methods
```php
public function __invoke( mixed $input );
```
@var mixed input The text to sanitize



        
<h1 id="filter-sanitize-striptags">Class Phalcon\Filter\Sanitize\Striptags</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/filter/sanitize/striptags.zep)

| Namespace  | Phalcon\Filter\Sanitize |

Phalcon\Filter\Sanitize\Striptags

Sanitizes a value striptags


## Methods
```php
public function __invoke( string $input );
```
@var mixed input The text to sanitize



        
<h1 id="filter-sanitize-trim">Class Phalcon\Filter\Sanitize\Trim</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/filter/sanitize/trim.zep)

| Namespace  | Phalcon\Filter\Sanitize |

Phalcon\Filter\Sanitize\Trim

Sanitizes a value removing leading and trailing spaces


## Methods
```php
public function __invoke( string $input );
```
@var mixed input The text to sanitize



        
<h1 id="filter-sanitize-upper">Class Phalcon\Filter\Sanitize\Upper</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/filter/sanitize/upper.zep)

| Namespace  | Phalcon\Filter\Sanitize |

Phalcon\Filter\Sanitize\Upper

Sanitizes a value to uppercase


## Methods
```php
public function __invoke( string $input );
```
@var mixed input The text to sanitize



        
<h1 id="filter-sanitize-upperfirst">Class Phalcon\Filter\Sanitize\UpperFirst</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/filter/sanitize/upperfirst.zep)

| Namespace  | Phalcon\Filter\Sanitize |

Phalcon\Filter\Sanitize\UpperFirst

Sanitizes a value to ucfirst


## Methods
```php
public function __invoke( string $input );
```
@var mixed input The text to sanitize



        
<h1 id="filter-sanitize-upperwords">Class Phalcon\Filter\Sanitize\UpperWords</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/filter/sanitize/upperwords.zep)

| Namespace  | Phalcon\Filter\Sanitize |

Phalcon\Filter\Sanitize\UpperWords

Sanitizes a value to uppercase teh first character of each word


## Methods
```php
public function __invoke( string $input );
```
@var mixed input The text to sanitize



        
<h1 id="filter-sanitize-url">Class Phalcon\Filter\Sanitize\Url</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/filter/sanitize/url.zep)

| Namespace  | Phalcon\Filter\Sanitize |

Phalcon\Filter\Sanitize\Url

Sanitizes a value url


## Methods
```php
public function __invoke( mixed $input );
```
@var mixed input The text to sanitize


