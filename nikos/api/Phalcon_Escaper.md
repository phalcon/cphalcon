---
layout: default
language: 'en'
version: '4.0'
title: 'Phalcon\Escaper'
---

* [Phalcon\Escaper](#escaper)
* [Phalcon\Escaper\EscaperInterface](#escaper-escaperinterface)
* [Phalcon\Escaper\Exception](#escaper-exception)
        
<h1 id="escaper">Class Phalcon\Escaper</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/escaper.zep)

| Namespace  | Phalcon |
| Uses       | Phalcon\Di\DiInterface, Phalcon\Escaper\EscaperInterface, Phalcon\Escaper\Exception |
| Implements | EscaperInterface |

Phalcon\Escaper

Escapes different kinds of text securing them. By using this component you
may prevent XSS attacks.

This component only works with UTF-8. The PREG extension needs to be compiled
with UTF-8 support.

```php
$escaper = new \Phalcon\Escaper();

$escaped = $escaper->escapeCss("font-family: <Verdana>");

echo $escaped; // font\2D family\3A \20 \3C Verdana\3E
```


## Properties
```php
/**
 * @var bool
 */
protected doubleEncode = true;

/**
 * @var string
 */
protected encoding = utf-8;

//
protected htmlEscapeMap;

//
protected htmlQuoteType = 3;

```

## Methods
```php
final public function detectEncoding( string $str ): string | null;
```
Detect the character encoding of a string to be handled by an encoder.
Special-handling for chr(172) and chr(128) to chr(159) which fail to be
detected by mb_detect_encoding()


```php
public function escapeCss( string $css ): string;
```
Escape CSS strings by replacing non-alphanumeric chars by their
hexadecimal escaped representation


```php
public function escapeHtml( string $text ): string;
```
Escapes a HTML string. Internally uses htmlspecialchars


```php
public function escapeHtmlAttr( string $attribute ): string;
```
Escapes a HTML attribute string


```php
public function escapeJs( string $js ): string;
```
Escape javascript strings by replacing non-alphanumeric chars by their
hexadecimal escaped representation


```php
public function escapeUrl( string $url ): string;
```
Escapes a URL. Internally uses rawurlencode


```php
public function getEncoding(): string;
```
Returns the internal encoding used by the escaper


```php
final public function normalizeEncoding( string $str ): string;
```
Utility to normalize a string's encoding to UTF-32.


```php
public function setDoubleEncode( bool $doubleEncode ): void;
```
Sets the double_encode to be used by the escaper

```php
$escaper->setDoubleEncode(false);
```


```php
public function setEncoding( string $encoding ): void;
```
Sets the encoding to be used by the escaper

```php
$escaper->setEncoding("utf-8");
```


```php
public function setHtmlQuoteType( int $quoteType ): void;
```
Sets the HTML quoting type for htmlspecialchars

```php
$escaper->setHtmlQuoteType(ENT_XHTML);
```



        
<h1 id="escaper-escaperinterface">Interface Phalcon\Escaper\EscaperInterface</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/escaper/escaperinterface.zep)

| Namespace  | Phalcon\Escaper |

Interface for Phalcon\Escaper


## Methods
```php
public function escapeCss( string $css ): string;
```
Escape CSS strings by replacing non-alphanumeric chars by their
hexadecimal representation


```php
public function escapeHtml( string $text ): string;
```
Escapes a HTML string


```php
public function escapeHtmlAttr( string $text ): string;
```
Escapes a HTML attribute string


```php
public function escapeJs( string $js ): string;
```
Escape Javascript strings by replacing non-alphanumeric chars by their
hexadecimal representation


```php
public function escapeUrl( string $url ): string;
```
Escapes a URL. Internally uses rawurlencode


```php
public function getEncoding(): string;
```
Returns the internal encoding used by the escaper


```php
public function setEncoding( string $encoding ): void;
```
Sets the encoding to be used by the escaper


```php
public function setHtmlQuoteType( int $quoteType ): void;
```
Sets the HTML quoting type for htmlspecialchars



        
<h1 id="escaper-exception">Class Phalcon\Escaper\Exception</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/escaper/exception.zep)

| Namespace  | Phalcon\Escaper |
| Extends    | \Phalcon\Exception |

Exceptions thrown in Phalcon\Escaper will use this class

