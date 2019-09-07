---
layout: default
language: 'en'
version: '4.0'
title: 'Phalcon\Annotations'
---

* [Phalcon\Annotations\Adapter\AbstractAdapter](#annotations-adapter-abstractadapter)
* [Phalcon\Annotations\Adapter\AdapterInterface](#annotations-adapter-adapterinterface)
* [Phalcon\Annotations\Adapter\Apcu](#annotations-adapter-apcu)
* [Phalcon\Annotations\Adapter\Memory](#annotations-adapter-memory)
* [Phalcon\Annotations\Adapter\Stream](#annotations-adapter-stream)
* [Phalcon\Annotations\Annotation](#annotations-annotation)
* [Phalcon\Annotations\AnnotationsFactory](#annotations-annotationsfactory)
* [Phalcon\Annotations\Collection](#annotations-collection)
* [Phalcon\Annotations\Exception](#annotations-exception)
* [Phalcon\Annotations\Reader](#annotations-reader)
* [Phalcon\Annotations\ReaderInterface](#annotations-readerinterface)
* [Phalcon\Annotations\Reflection](#annotations-reflection)
        
<h1 id="annotations-adapter-abstractadapter">Abstract Class Phalcon\Annotations\Adapter\AbstractAdapter</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/annotations/adapter/abstractadapter.zep)

| Namespace  | Phalcon\Annotations\Adapter |
| Uses       | Phalcon\Annotations\Adapter\AdapterInterface, Phalcon\Annotations\Reader, Phalcon\Annotations\Exception, Phalcon\Annotations\Collection, Phalcon\Annotations\Reflection, Phalcon\Annotations\ReaderInterface |
| Implements | AdapterInterface |

This is the base class for Phalcon\Annotations adapters


## Properties
```php
/**
 * @var array
 */
protected annotations;

/**
 * @var Reader
 */
protected reader;

```

## Methods
```php
public function get( mixed $className ): Reflection;
```
Parses or retrieves all the annotations found in a class


```php
public function getMethod( string $className, string $methodName ): Collection;
```
Returns the annotations found in a specific method


```php
public function getMethods( string $className ): array;
```
Returns the annotations found in all the class' methods


```php
public function getProperties( string $className ): array;
```
Returns the annotations found in all the class' methods


```php
public function getProperty( string $className, string $propertyName ): Collection;
```
Returns the annotations found in a specific property


```php
public function getReader(): ReaderInterface;
```
Returns the annotation reader


```php
public function setReader( ReaderInterface $reader );
```
Sets the annotations parser



        
<h1 id="annotations-adapter-adapterinterface">Interface Phalcon\Annotations\Adapter\AdapterInterface</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/annotations/adapter/adapterinterface.zep)

| Namespace  | Phalcon\Annotations\Adapter |
| Uses       | Phalcon\Annotations\Reflection, Phalcon\Annotations\Collection, Phalcon\Annotations\ReaderInterface |

This interface must be implemented by adapters in Phalcon\Annotations


## Methods
```php
public function get( string $className ): Reflection;
```
Parses or retrieves all the annotations found in a class


```php
public function getMethod( string $className, string $methodName ): Collection;
```
Returns the annotations found in a specific method


```php
public function getMethods( string $className ): array;
```
Returns the annotations found in all the class' methods


```php
public function getProperties( string $className ): array;
```
Returns the annotations found in all the class' methods


```php
public function getProperty( string $className, string $propertyName ): Collection;
```
Returns the annotations found in a specific property


```php
public function getReader(): ReaderInterface;
```
Returns the annotation reader


```php
public function setReader( ReaderInterface $reader );
```
Sets the annotations parser



        
<h1 id="annotations-adapter-apcu">Class Phalcon\Annotations\Adapter\Apcu</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/annotations/adapter/apcu.zep)

| Namespace  | Phalcon\Annotations\Adapter |
| Uses       | Phalcon\Annotations\Adapter\AbstractAdapter, Phalcon\Annotations\Reflection |
| Extends    | AbstractAdapter |

Stores the parsed annotations in APCu. This adapter is suitable for production

```php
use Phalcon\Annotations\Adapter\Apcu;

$annotations = new Apcu();
```


## Properties
```php
/**
 * @var string
 */
protected prefix = ;

/**
 * @var int
 */
protected ttl = 172800;

```

## Methods
```php
public function __construct( array $options = [] ): void;
```
Phalcon\Annotations\Adapter\Apcu constructor


```php
public function read( string $key ): Reflection | bool;
```
Reads parsed annotations from APCu


```php
public function write( string $key, Reflection $data ): bool;
```
Writes parsed annotations to APCu



        
<h1 id="annotations-adapter-memory">Class Phalcon\Annotations\Adapter\Memory</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/annotations/adapter/memory.zep)

| Namespace  | Phalcon\Annotations\Adapter |
| Uses       | Phalcon\Annotations\Adapter\AbstractAdapter, Phalcon\Annotations\Reflection |
| Extends    | AbstractAdapter |

Stores the parsed annotations in memory. This adapter is the suitable
development/testing


## Properties
```php
/**
 * @var mixed
 */
protected data;

```

## Methods
```php
public function read( string $key ): Reflection | bool;
```
Reads parsed annotations from memory


```php
public function write( string $key, Reflection $data ): void;
```
Writes parsed annotations to memory



        
<h1 id="annotations-adapter-stream">Class Phalcon\Annotations\Adapter\Stream</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/annotations/adapter/stream.zep)

| Namespace  | Phalcon\Annotations\Adapter |
| Uses       | Phalcon\Annotations\Adapter\AbstractAdapter, Phalcon\Annotations\Reflection, Phalcon\Annotations\Exception |
| Extends    | AbstractAdapter |

Stores the parsed annotations in files. This adapter is suitable for production

```php
use Phalcon\Annotations\Adapter\Stream;

$annotations = new Stream(
    [
        "annotationsDir" => "app/cache/annotations/",
    ]
);
```


## Properties
```php
/**
 * @var string
 */
protected annotationsDir = ./;

```

## Methods
```php
public function __construct( array $options = [] ): void;
```
Phalcon\Annotations\Adapter\Stream constructor


```php
public function read( string $key ): Reflection | bool | int;
```
Reads parsed annotations from files


```php
public function write( string $key, Reflection $data ): void;
```
Writes parsed annotations to files



        
<h1 id="annotations-annotation">Class Phalcon\Annotations\Annotation</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/annotations/annotation.zep)

| Namespace  | Phalcon\Annotations |
| Uses       | Phalcon\Annotations\Annotation, Phalcon\Annotations\Exception |

Represents a single annotation in an annotations collection


## Properties
```php
/**
 * Annotation Arguments
 *
 * @var array
 */
protected arguments;

/**
 * Annotation ExprArguments
 *
 * @var string
 */
protected exprArguments;

/**
 * Annotation Name
 *
 * @var string
 */
protected name;

```

## Methods
```php
public function __construct( array $reflectionData ): void;
```
Phalcon\Annotations\Annotation constructor


```php
public function getArgument( mixed $position );
```
Returns an argument in a specific position


```php
public function getArguments(): array;
```
Returns the expression arguments


```php
public function getExprArguments(): array;
```
Returns the expression arguments without resolving


```php
public function getExpression( array $expr ): mixed;
```
Resolves an annotation expression


```php
public function getName(): string;
```
Returns the annotation's name


```php
public function getNamedArgument( string $name );
```
Returns a named argument


```php
public function getNamedParameter( string $name ): mixed;
```
Returns a named parameter


```php
public function hasArgument( mixed $position ): bool;
```
Returns an argument in a specific position


```php
public function numberArguments(): int;
```
Returns the number of arguments that the annotation has



        
<h1 id="annotations-annotationsfactory">Class Phalcon\Annotations\AnnotationsFactory</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/annotations/annotationsfactory.zep)

| Namespace  | Phalcon\Annotations |
| Uses       | Phalcon\Annotations\Adapter\AbstractAdapter, Phalcon\Factory\AbstractFactory, Phalcon\Helper\Arr |
| Extends    | AbstractFactory |

Factory to create annotations components


## Methods
```php
public function __construct( array $services = [] );
```
AdapterFactory constructor.


```php
public function load( mixed $config ): mixed;
```
Factory to create an instace from a Config object


```php
public function newInstance( string $name, array $options = [] ): AbstractAdapter;
```
Create a new instance of the adapter


```php
protected function getAdapters(): array;
```
The available adapters



        
<h1 id="annotations-collection">Class Phalcon\Annotations\Collection</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/annotations/collection.zep)

| Namespace  | Phalcon\Annotations |
| Uses       | Countable, Iterator, Phalcon\Annotations\Annotation, Phalcon\Annotations\Exception |
| Implements | Iterator, Countable |

Represents a collection of annotations. This class allows to traverse a group
of annotations easily

```php
// Traverse annotations
foreach ($classAnnotations as $annotation) {
    echo "Name=", $annotation->getName(), PHP_EOL;
}

// Check if the annotations has a specific
var_dump($classAnnotations->has("Cacheable"));

// Get an specific annotation in the collection
$annotation = $classAnnotations->get("Cacheable");
```


## Properties
```php
/**
 * @var array
 */
protected annotations;

/**
 * @var int
 */
protected position = 0;

```

## Methods
```php
public function __construct( array $reflectionData = [] ): void;
```
Phalcon\Annotations\Collection constructor


```php
public function count(): int;
```
Returns the number of annotations in the collection


```php
public function current(): Annotation | bool;
```
Returns the current annotation in the iterator


```php
public function get( string $name ): Annotation;
```
Returns the first annotation that match a name


```php
public function getAll( string $name ): Annotation[];
```
Returns all the annotations that match a name


```php
public function getAnnotations(): Annotation[];
```
Returns the internal annotations as an array


```php
public function has( string $name ): bool;
```
Check if an annotation exists in a collection


```php
public function key(): int;
```
Returns the current position/key in the iterator


```php
public function next(): void;
```
Moves the internal iteration pointer to the next position


```php
public function rewind(): void;
```
Rewinds the internal iterator


```php
public function valid(): bool;
```
Check if the current annotation in the iterator is valid



        
<h1 id="annotations-exception">Class Phalcon\Annotations\Exception</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/annotations/exception.zep)

| Namespace  | Phalcon\Annotations |
| Extends    | \Phalcon\Exception |

Class for exceptions thrown by Phalcon\Annotations


        
<h1 id="annotations-reader">Class Phalcon\Annotations\Reader</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/annotations/reader.zep)

| Namespace  | Phalcon\Annotations |
| Uses       | Phalcon\Annotations\ReaderInterface, ReflectionClass |
| Implements | ReaderInterface |

Parses docblocks returning an array with the found annotations


## Methods
```php
public function parse( string $className ): array;
```
Reads annotations from the class docblocks, its methods and/or properties



        
<h1 id="annotations-readerinterface">Interface Phalcon\Annotations\ReaderInterface</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/annotations/readerinterface.zep)

| Namespace  | Phalcon\Annotations |

Parses docblocks returning an array with the found annotations


## Methods
```php
public function parse( string $className ): array;
```
Reads annotations from the class docblocks, its methods and/or properties



        
<h1 id="annotations-reflection">Class Phalcon\Annotations\Reflection</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/annotations/reflection.zep)

| Namespace  | Phalcon\Annotations |
| Uses       | Phalcon\Annotations\Collection |

Allows to manipulate the annotations reflection in an OO manner

```php
use Phalcon\Annotations\Reader;
use Phalcon\Annotations\Reflection;

// Parse the annotations in a class
$reader = new Reader();
$parsing = $reader->parse("MyComponent");

// Create the reflection
$reflection = new Reflection($parsing);

// Get the annotations in the class docblock
$classAnnotations = $reflection->getClassAnnotations();
```


## Properties
```php
//
protected classAnnotations;

//
protected methodAnnotations;

//
protected propertyAnnotations;

/**
 * @var array
 */
protected reflectionData;

```

## Methods
```php
public function __construct( array $reflectionData = [] ): void;
```
Phalcon\Annotations\Reflection constructor


```php
public function getClassAnnotations(): Collection | bool;
```
Returns the annotations found in the class docblock


```php
public function getMethodsAnnotations(): Collection[] | bool;
```
Returns the annotations found in the methods' docblocks


```php
public function getPropertiesAnnotations(): Collection[] | bool;
```
Returns the annotations found in the properties' docblocks


```php
public function getReflectionData(): array;
```
Returns the raw parsing intermediate definitions used to construct the
reflection


