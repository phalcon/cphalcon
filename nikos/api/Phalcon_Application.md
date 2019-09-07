---
layout: default
language: 'en'
version: '4.0'
title: 'Phalcon\Application'
---

* [Phalcon\Application\AbstractApplication](#application-abstractapplication)
* [Phalcon\Application\Exception](#application-exception)
        
<h1 id="application-abstractapplication">Abstract Class Phalcon\Application\AbstractApplication</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/application/abstractapplication.zep)

| Namespace  | Phalcon\Application |
| Uses       | Phalcon\Application\Exception, Phalcon\Di\DiInterface, Phalcon\Di\Injectable, Phalcon\Events\EventsAwareInterface, Phalcon\Events\ManagerInterface |
| Extends    | Injectable |
| Implements | EventsAwareInterface |

Base class for Phalcon\Cli\Console and Phalcon\Mvc\Application.


## Properties
```php
/**
 * @var DiInterface
 */
protected container;

/**
 * @var string
 */
protected defaultModule;

/**
 * @var null | ManagerInterface
 */
protected eventsManager;

/**
 * @var array
 */
protected modules;

```

## Methods
```php
public function __construct( DiInterface $container = null ): void;
```
Phalcon\AbstractApplication constructor


```php
public function getDefaultModule(): string;
```
Returns the default module name


```php
public function getEventsManager(): ManagerInterface;
```
Returns the internal event manager


```php
public function getModule( string $name ): array | object;
```
Gets the module definition registered in the application via module name


```php
public function getModules(): array;
```
Return the modules registered in the application


```php
abstract public function handle();
```
Handles a request


```php
public function registerModules( array $modules, bool $merge = bool ): AbstractApplication;
```
Register an array of modules present in the application

```php
$this->registerModules(
    [
        "frontend" => [
            "className" => \Multiple\Frontend\Module::class,
            "path"      => "../apps/frontend/Module.php",
        ],
        "backend" => [
            "className" => \Multiple\Backend\Module::class,
            "path"      => "../apps/backend/Module.php",
        ],
    ]
);
```


```php
public function setDefaultModule( string $defaultModule ): AbstractApplication;
```
Sets the module name to be used if the router doesn't return a valid module


```php
public function setEventsManager( ManagerInterface $eventsManager ): AbstractApplication;
```
Sets the events manager



        
<h1 id="application-exception">Class Phalcon\Application\Exception</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/application/exception.zep)

| Namespace  | Phalcon\Application |
| Extends    | \Phalcon\Exception |

Exceptions thrown in Phalcon\Application class will use this class

