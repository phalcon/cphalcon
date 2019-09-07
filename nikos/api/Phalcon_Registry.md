---
layout: default
language: 'en'
version: '4.0'
title: 'Phalcon\Registry'
---

* [Phalcon\Registry](#registry)
        
<h1 id="registry">Final Class Phalcon\Registry</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/registry.zep)

| Namespace  | Phalcon |
| Uses       | Phalcon\Collection, Traversable |
| Extends    | Collection |

Phalcon\Registry

A registry is a container for storing objects and values in the application
space. By storing the value in a registry, the same object is always
available throughout your application.

```php
$registry = new \Phalcon\Registry();

// Set value
$registry->something = "something";
// or
$registry["something"] = "something";

// Get value
$value = $registry->something;
// or
$value = $registry["something"];

// Check if the key exists
$exists = isset($registry->something);
// or
$exists = isset($registry["something"]);

// Unset
unset($registry->something);
// or
unset($registry["something"]);
```

In addition to ArrayAccess, Phalcon\Registry also implements Countable
(count($registry) will return the number of elements in the registry),
Serializable and Iterator (you can iterate over the registry using a foreach
loop) interfaces. For PHP 5.4 and higher, JsonSerializable interface is
implemented.

Phalcon\Registry is very fast (it is typically faster than any userspace
implementation of the registry); however, this comes at a price:
Phalcon\Registry is a final class and cannot be inherited from.

Though Phalcon\Registry exposes methods like __get(), offsetGet(), count() etc,
it is not recommended to invoke them manually (these methods exist mainly to
match the interfaces the registry implements): $registry->__get("property")
is several times slower than $registry->property.

Internally all the magic methods (and interfaces except JsonSerializable)
are implemented using object handlers or similar techniques: this allows to
bypass relatively slow method calls.


## Methods
```php
final public function __construct( array $data = null ): void;
```
Constructor


```php
final public function __get( string $element ): mixed;
```
Magic getter to get an element from the collection


```php
final public function __isset( string $element ): bool;
```
Magic isset to check whether an element exists or not


```php
final public function __set( string $element, mixed $value ): void;
```
Magic setter to assign values to an element


```php
final public function __unset( string $element ): void;
```
Magic unset to remove an element from the collection


```php
final public function clear(): void;
```
Clears the internal collection


```php
final public function count(): int;
```
Count elements of an object

@link https://php.net/manual/en/countable.count.php


```php
final public function get( string $element, mixed $defaultValue = null ): mixed;
```
Get the element from the collection


```php
final public function getIterator(): Traversable;
```
Returns the iterator of the class


```php
final public function has( string $element ): bool;
```
Get the element from the collection


```php
final public function init( array $data = [] ): void;
```
Initialize internal array


```php
final public function jsonSerialize(): array;
```
Specify data which should be serialized to JSON

@link https://php.net/manual/en/jsonserializable.jsonserialize.php


```php
final public function offsetExists( mixed $element ): bool;
```
Whether a offset exists

@link https://php.net/manual/en/arrayaccess.offsetexists.php


```php
final public function offsetGet( mixed $element ): mixed;
```
Offset to retrieve

@link https://php.net/manual/en/arrayaccess.offsetget.php


```php
final public function offsetSet( mixed $element, mixed $value ): void;
```
Offset to set

@link https://php.net/manual/en/arrayaccess.offsetset.php


```php
final public function offsetUnset( mixed $element ): void;
```
Offset to unset

@link https://php.net/manual/en/arrayaccess.offsetunset.php


```php
final public function remove( string $element ): void;
```
Delete the element from the collection


```php
final public function serialize(): string;
```
String representation of object

@link https://php.net/manual/en/serializable.serialize.php


```php
final public function set( string $element, mixed $value ): void;
```
Set an element in the collection


```php
final public function toArray(): array;
```
Returns the object in an array format


```php
final public function toJson( int $options = int ): string;
```
Returns the object in a JSON format

The default string uses the following options for json_encode

JSON_HEX_TAG, JSON_HEX_APOS, JSON_HEX_AMP, JSON_HEX_QUOT, JSON_UNESCAPED_SLASHES

@see https://www.ietf.org/rfc/rfc4627.txt


```php
final public function unserialize( mixed $serialized ): void;
```
Constructs the object

@link https://php.net/manual/en/serializable.unserialize.php


