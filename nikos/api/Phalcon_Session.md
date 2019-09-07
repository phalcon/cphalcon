---
layout: default
language: 'en'
version: '4.0'
title: 'Phalcon\Session'
---

* [Phalcon\Session\Adapter\AbstractAdapter](#session-adapter-abstractadapter)
* [Phalcon\Session\Adapter\Libmemcached](#session-adapter-libmemcached)
* [Phalcon\Session\Adapter\Noop](#session-adapter-noop)
* [Phalcon\Session\Adapter\Redis](#session-adapter-redis)
* [Phalcon\Session\Adapter\Stream](#session-adapter-stream)
* [Phalcon\Session\Bag](#session-bag)
* [Phalcon\Session\Exception](#session-exception)
* [Phalcon\Session\Manager](#session-manager)
* [Phalcon\Session\ManagerInterface](#session-managerinterface)
        
<h1 id="session-adapter-abstractadapter">Abstract Class Phalcon\Session\Adapter\AbstractAdapter</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/session/adapter/abstractadapter.zep)

| Namespace  | Phalcon\Session\Adapter |
| Uses       | Phalcon\Storage\Adapter\AdapterInterface, SessionHandlerInterface |
| Implements | SessionHandlerInterface |

This file is part of the Phalcon.

(c) Phalcon Team <team@phalcon.com>

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.


## Properties
```php
/**
 * @var <AdapterInterface>
 */
protected adapter;

```

## Methods
```php
public function close(): bool;
```
Close


```php
public function destroy( mixed $id ): bool;
```
Destroy


```php
public function gc( mixed $maxlifetime ): bool;
```
Garbage Collector


```php
public function open( mixed $savePath, mixed $sessionName ): bool;
```
Open


```php
public function read( mixed $id ): string;
```
Read


```php
public function write( mixed $id, mixed $data ): bool;
```
Write



        
<h1 id="session-adapter-libmemcached">Class Phalcon\Session\Adapter\Libmemcached</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/session/adapter/libmemcached.zep)

| Namespace  | Phalcon\Session\Adapter |
| Uses       | Phalcon\Storage\AdapterFactory, Phalcon\Session\Adapter\AbstractAdapter |
| Extends    | AbstractAdapter |

Phalcon\Session\Adapter\Libmemcached


## Methods
```php
public function __construct( AdapterFactory $factory, array $options = [] ): void;
```
Constructor



        
<h1 id="session-adapter-noop">Class Phalcon\Session\Adapter\Noop</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/session/adapter/noop.zep)

| Namespace  | Phalcon\Session\Adapter |
| Uses       | SessionHandlerInterface |
| Implements | SessionHandlerInterface |

Phalcon\Session\Adapter\Noop

This is an "empty" or null adapter. It can be used for testing or any
other purpose that no session needs to be invoked

```php
<?php

use Phalcon\Session\Manager;
use Phalcon\Session\Adapter\Noop;

$session = new Manager();
$session->setHandler(new Noop());
```


## Properties
```php
/**
 * The connection of some adapters
 */
protected connection;

/**
 * Session options
 *
 * @var array
 */
protected options;

/**
 * Session prefix
 *
 * @var string
 */
protected prefix = ;

/**
 * Time To Live
 *
 * @var int
 */
protected ttl = 8600;

```

## Methods
```php
public function __construct( array $options = [] ): void;
```
Constructor


```php
public function close(): bool;
```
Close


```php
public function destroy( mixed $id ): bool;
```
Destroy


```php
public function gc( mixed $maxlifetime ): bool;
```
Garbage Collector


```php
public function open( mixed $savePath, mixed $sessionName ): bool;
```
Open


```php
public function read( mixed $id ): string;
```
Read


```php
public function write( mixed $id, mixed $data ): bool;
```
Write


```php
protected function getPrefixedName( mixed $name ): string;
```
Helper method to get the name prefixed



        
<h1 id="session-adapter-redis">Class Phalcon\Session\Adapter\Redis</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/session/adapter/redis.zep)

| Namespace  | Phalcon\Session\Adapter |
| Uses       | Phalcon\Storage\AdapterFactory, Phalcon\Session\Adapter\AbstractAdapter |
| Extends    | AbstractAdapter |

Phalcon\Session\Adapter\Redis


## Methods
```php
public function __construct( AdapterFactory $factory, array $options = [] ): void;
```
Constructor



        
<h1 id="session-adapter-stream">Class Phalcon\Session\Adapter\Stream</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/session/adapter/stream.zep)

| Namespace  | Phalcon\Session\Adapter |
| Uses       | Phalcon\Helper\Str, Phalcon\Session\Exception |
| Extends    | Noop |

Phalcon\Session\Adapter\Stream

This is the file based adapter. It stores sessions in a file based system

```php
<?php

use Phalcon\Session\Manager;
use Phalcon\Session\Adapter\Stream;

$session = new Manager();
$files = new Stream(
    [
        'savePath' => '/tmp',
    ]
);
$session->setHandler($files);
```


## Properties
```php
/**
 * @var string
 */
private path = ;

```

## Methods
```php
public function __construct( array $options = [] ): void;
```
//

```php
public function destroy( mixed $id ): bool;
```
//

```php
public function gc( mixed $maxlifetime ): bool;
```
//

```php
public function open( mixed $savePath, mixed $sessionName ): bool;
```
   Ignore the savePath and use local defined path
   
   @return bool
   

```php
public function read( mixed $id ): string;
```
//

```php
public function write( mixed $id, mixed $data ): bool;
```
//


        
<h1 id="session-bag">Class Phalcon\Session\Bag</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/session/bag.zep)

| Namespace  | Phalcon\Session |
| Uses       | Phalcon\Collection, Phalcon\Di, Phalcon\Di\DiInterface, Phalcon\Di\InjectionAwareInterface |
| Extends    | Collection |
| Implements | InjectionAwareInterface |

Phalcon\Session\Bag

This component helps to separate session data into "namespaces". Working by
this way you can easily create groups of session variables into the
application

```php
$user = new \Phalcon\Session\Bag("user");

$user->name = "Kimbra Johnson";
$user->age  = 22;
```


## Properties
```php
//
private container;

//
private name;

//
private session;

```

## Methods
```php
public function __construct( string $name ): void;
```
Phalcon\Session\Bag constructor


```php
public function clear(): void;
```
Destroys the session bag


```php
public function getDI(): DiInterface;
```
Returns the DependencyInjector container


```php
public function init( array $data = [] ): void;
```
Removes a property from the internal bag


```php
public function remove( string $element ): void;
```
Removes a property from the internal bag


```php
public function set( string $element, mixed $value );
```
Sets a value in the session bag


```php
public function setDI( DiInterface $container ): void;
```
Sets the DependencyInjector container



        
<h1 id="session-exception">Class Phalcon\Session\Exception</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/session/exception.zep)

| Namespace  | Phalcon\Session |
| Extends    | \Phalcon\Exception |

Phalcon\Session\Exception

Exceptions thrown in Phalcon\Session will use this class


        
<h1 id="session-manager">Class Phalcon\Session\Manager</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/session/manager.zep)

| Namespace  | Phalcon\Session |
| Uses       | InvalidArgumentException, RuntimeException, SessionHandlerInterface, Phalcon\DI\AbstractInjectionAware, Phalcon\Di\DiInterface, Phalcon\Helper\Arr, Phalcon\Session\ManagerInterface |
| Extends    | AbstractInjectionAware |
| Implements | ManagerInterface |

Phalcon\Session\Manager

Session manager class


## Properties
```php
/**
 * @var <SessionHandlerInterface>|null
 */
private handler;

/**
 * @var string
 */
private name = ;

/**
 * @var array
 */
private options;

/**
 * @var string
 */
private uniqueId = ;

```

## Methods
```php
public function __construct( array $options = [] ): void;
```
Manager constructor.


```php
public function __get( string $key ): mixed;
```
Alias: Gets a session variable from an application context


```php
public function __isset( string $key ): bool;
```
Alias: Check whether a session variable is set in an application context


```php
public function __set( string $key, mixed $value ): void;
```
Alias: Sets a session variable in an application context


```php
public function __unset( string $key ): void;
```
Alias: Removes a session variable from an application context


```php
public function destroy(): void;
```
Destroy/end a session


```php
public function exists(): bool;
```
Check whether the session has been started


```php
public function get( string $key, mixed $defaultValue = null, bool $remove = bool ): mixed;
```
Gets a session variable from an application context


```php
public function getHandler(): SessionHandlerInterface;
```
Returns the stored session handler


```php
public function getId(): string;
```
Returns the session id


```php
public function getName(): string;
```
Returns the name of the session


```php
public function getOptions(): array;
```
Get internal options


```php
public function has( string $key ): bool;
```
Check whether a session variable is set in an application context


```php
public function regenerateId( mixed $deleteOldSession = bool ): ManagerInterface;
```
Regenerates the session id using the handler.


```php
public function registerHandler( SessionHandlerInterface $handler ): bool;
```
Registers a handler with the session


```php
public function remove( string $key );
```
Removes a session variable from an application context


```php
public function set( string $key, mixed $value ): void;
```
Sets a session variable in an application context


```php
public function setHandler( SessionHandlerInterface $handler ): ManagerInterface;
```
Set the handler for the session


```php
public function setId( string $id ): ManagerInterface;
```
Set session Id


```php
public function setName( string $name ): ManagerInterface;
```
Set the session name. Throw exception if the session has started
and do not allow poop names

@param  string name

@throws InvalidArgumentException

@return Manager


```php
public function setOptions( array $options ): void;
```
Sets session's options


```php
public function start(): bool;
```
Starts the session (if headers are already sent the session will not be
started)


```php
public function status(): int;
```
Returns the status of the current session.



        
<h1 id="session-managerinterface">Interface Phalcon\Session\ManagerInterface</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/session/managerinterface.zep)

| Namespace  | Phalcon\Session |
| Uses       | InvalidArgumentException, RuntimeException, SessionHandlerInterface |

Phalcon\Session

Interface for the Phalcon\Session\Manager


## Constants
```php
const SESSION_ACTIVE = 2;
const SESSION_DISABLED = 0;
const SESSION_NONE = 1;
```

## Methods
```php
public function __get( string $key ): void;
```
Alias: Gets a session variable from an application context


```php
public function __isset( string $key ): bool;
```
Alias: Check whether a session variable is set in an application context


```php
public function __set( string $key, mixed $value ): void;
```
Alias: Sets a session variable in an application context


```php
public function __unset( string $key ): void;
```
Alias: Removes a session variable from an application context


```php
public function destroy(): void;
```
Destroy/end a session


```php
public function exists(): bool;
```
Check whether the session has been started


```php
public function get( string $key, mixed $defaultValue = null, bool $remove = bool ): mixed;
```
Gets a session variable from an application context


```php
public function getHandler(): SessionHandlerInterface;
```
Returns the stored session handler


```php
public function getId(): string;
```
Returns the session id


```php
public function getName(): string;
```
Returns the name of the session


```php
public function getOptions(): array;
```
Get internal options


```php
public function has( string $key ): bool;
```
Check whether a session variable is set in an application context


```php
public function regenerateId( mixed $deleteOldSession = bool ): ManagerInterface;
```
Regenerates the session id using the handler.


```php
public function registerHandler( SessionHandlerInterface $handler ): bool;
```
Registers a handler with the session


```php
public function remove( string $key ): void;
```
Removes a session variable from an application context


```php
public function set( string $key, mixed $value ): void;
```
Sets a session variable in an application context


```php
public function setHandler( SessionHandlerInterface $handler ): ManagerInterface;
```
Set the handler for the session


```php
public function setId( string $id ): ManagerInterface;
```
Set session Id


```php
public function setName( string $name ): ManagerInterface;
```
Set the session name. Throw exception if the session has started
and do not allow poop names

@throws InvalidArgumentException


```php
public function setOptions( array $options ): void;
```
Sets session's options


```php
public function start(): bool;
```
Starts the session (if headers are already sent the session will not be
started)


```php
public function status(): int;
```
Returns the status of the current session.


