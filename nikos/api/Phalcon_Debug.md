---
layout: default
language: 'en'
version: '4.0'
title: 'Phalcon\Debug'
---

* [Phalcon\Debug](#debug)
* [Phalcon\Debug\Dump](#debug-dump)
* [Phalcon\Debug\Exception](#debug-exception)
        
<h1 id="debug">Class Phalcon\Debug</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/debug.zep)

| Namespace  | Phalcon |
| Uses       | ErrorException, Phalcon\Helper\Arr, Phalcon\Version, Phalcon\Tag, ReflectionClass, ReflectionFunction |

Provides debug capabilities to Phalcon applications


## Properties
```php
/**
 * @var array
    */
protected blacklist;

//
protected data;

/**
 * @var bool
 */
protected hideDocumentRoot = false;

/**
 * @var bool
 */
protected static isActive;

/**
 * @var bool
 */
protected showBackTrace = true;

/**
 * @var bool
 */
protected showFileFragment = false;

/**
 * @var bool
 */
protected showFiles = true;

/**
 * @var string
    */
protected uri = https://assets.phalcon.io/debug/4.0.x/;

```

## Methods
```php
public function clearVars(): Debug;
```
Clears are variables added previously


```php
public function debugVar( mixed $varz, string $key = null ): Debug;
```
Adds a variable to the debug output


```php
public function getCssSources(): string;
```
Returns the css sources


```php
public function getJsSources(): string;
```
Returns the javascript sources


```php
public function getVersion(): string;
```
Generates a link to the current version documentation


```php
public function halt(): void;
```
Halts the request showing a backtrace


```php
public function listen( bool $exceptions = bool, bool $lowSeverity = bool ): Debug;
```
Listen for uncaught exceptions and unsilent notices or warnings


```php
public function listenExceptions(): Debug;
```
Listen for uncaught exceptions


```php
public function listenLowSeverity(): Debug;
```
Listen for unsilent notices or warnings


```php
public function onUncaughtException( \Exception $exception ): bool;
```
Handles uncaught exceptions


```php
public function onUncaughtLowSeverity( mixed $severity, mixed $message, mixed $file, mixed $line, mixed $context ): void;
```
Throws an exception when a notice or warning is raised


```php
public function setBlacklist( array $blacklist ): Debug;
```
Sets if files the exception's backtrace must be showed


```php
public function setShowBackTrace( bool $showBackTrace ): Debug;
```
Sets if files the exception's backtrace must be showed


```php
public function setShowFileFragment( bool $showFileFragment ): Debug;
```
Sets if files must be completely opened and showed in the output
or just the fragment related to the exception


```php
public function setShowFiles( bool $showFiles ): Debug;
```
Set if files part of the backtrace must be shown in the output


```php
public function setUri( string $uri ): Debug;
```
Change the base URI for static resources


```php
protected function escapeString( mixed $value ): string;
```
Escapes a string with htmlentities


```php
protected function getArrayDump( array $argument, mixed $n = int ): string | null;
```
Produces a recursive representation of an array


```php
protected function getVarDump( mixed $variable ): string;
```
Produces an string representation of a variable


```php
final protected function showTraceItem( int $n, array $trace ): string;
```
Shows a backtrace item



        
<h1 id="debug-dump">Class Phalcon\Debug\Dump</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/debug/dump.zep)

| Namespace  | Phalcon\Debug |
| Uses       | Phalcon\Di, Reflection, ReflectionClass, ReflectionProperty, stdClass |

Dumps information about a variable(s)

```php
$foo = 123;

echo (new \Phalcon\Debug\Dump())->variable($foo, "foo");
```

```php
$foo = "string";
$bar = ["key" => "value"];
$baz = new stdClass();

echo (new \Phalcon\Debug\Dump())->variables($foo, $bar, $baz);
```


## Properties
```php
/**
 * @var bool
 */
protected detailed = false;

/**
 * @var array
 */
protected methods;

/**
 * @var array
 */
protected styles;

```

## Methods
```php
public function __construct( array $styles = [], bool $detailed = bool ): void;
```
Phalcon\Debug\Dump constructor


```php
public function all(): string;
```
Alias of variables() method


```php
public function getDetailed(): bool
```


```php
public function one( mixed $variable, string $name = null ): string;
```
Alias of variable() method


```php
public function setDetailed( bool $detailed )
```


```php
public function setStyles( array $styles = [] ): array;
```
Set styles for vars type


```php
public function toJson( mixed $variable ): string;
```
Returns an JSON string of information about a single variable.

```php
$foo = [
    "key" => "value",
];

echo (new \Phalcon\Debug\Dump())->toJson($foo);

$foo = new stdClass();
$foo->bar = "buz";

echo (new \Phalcon\Debug\Dump())->toJson($foo);
```


```php
public function variable( mixed $variable, string $name = null ): string;
```
Returns an HTML string of information about a single variable.

```php
echo (new \Phalcon\Debug\Dump())->variable($foo, "foo");
```


```php
public function variables(): string;
```
Returns an HTML string of debugging information about any number of
variables, each wrapped in a "pre" tag.

```php
$foo = "string";
$bar = ["key" => "value"];
$baz = new stdClass();

echo (new \Phalcon\Debug\Dump())->variables($foo, $bar, $baz);
```


```php
protected function getStyle( string $type ): string;
```
Get style for type


```php
protected function output( mixed $variable, string $name = null, int $tab = int ): string;
```
Prepare an HTML string of information about a single variable.



        
<h1 id="debug-exception">Class Phalcon\Debug\Exception</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/debug/exception.zep)

| Namespace  | Phalcon\Debug |
| Extends    | \Phalcon\Exception |

Exceptions thrown in Phalcon\Debug will use this class

