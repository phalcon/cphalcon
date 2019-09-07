---
layout: default
language: 'en'
version: '4.0'
title: 'Phalcon\Di'
---

* [Phalcon\Di](#di)
* [Phalcon\Di\AbstractInjectionAware](#di-abstractinjectionaware)
* [Phalcon\Di\DiInterface](#di-diinterface)
* [Phalcon\Di\Exception](#di-exception)
* [Phalcon\Di\Exception\ServiceResolutionException](#di-exception-serviceresolutionexception)
* [Phalcon\Di\FactoryDefault](#di-factorydefault)
* [Phalcon\Di\FactoryDefault\Cli](#di-factorydefault-cli)
* [Phalcon\Di\Injectable](#di-injectable)
* [Phalcon\Di\InjectionAwareInterface](#di-injectionawareinterface)
* [Phalcon\Di\Service](#di-service)
* [Phalcon\Di\Service\Builder](#di-service-builder)
* [Phalcon\Di\ServiceInterface](#di-serviceinterface)
* [Phalcon\Di\ServiceProviderInterface](#di-serviceproviderinterface)
        
<h1 id="di">Class Phalcon\Di</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/di.zep)

| Namespace  | Phalcon |
| Uses       | Phalcon\Config, Phalcon\Di\Service, Phalcon\Di\DiInterface, Phalcon\Di\Exception, Phalcon\Di\Exception\ServiceResolutionException, Phalcon\Config\Adapter\Php, Phalcon\Config\Adapter\Yaml, Phalcon\Di\ServiceInterface, Phalcon\Events\ManagerInterface, Phalcon\Di\InjectionAwareInterface, Phalcon\Di\ServiceProviderInterface |
| Implements | DiInterface |

Phalcon\Di is a component that implements Dependency Injection/Service
Location of services and it's itself a container for them.

Since Phalcon is highly decoupled, Phalcon\Di is essential to integrate the
different components of the framework. The developer can also use this
component to inject dependencies and manage global instances of the different
classes used in the application.

Basically, this component implements the `Inversion of Control` pattern.
Applying this, the objects do not receive their dependencies using setters or
constructors, but requesting a service dependency injector. This reduces the
overall complexity, since there is only one way to get the required
dependencies within a component.

Additionally, this pattern increases testability in the code, thus making it
less prone to errors.

```php
use Phalcon\Di;
use Phalcon\Http\Request;

$di = new Di();

// Using a string definition
$di->set("request", Request::class, true);

// Using an anonymous function
$di->setShared(
    "request",
    function () {
        return new Request();
    }
);

$request = $di->getRequest();
```


## Properties
```php
/**
 * List of registered services
 */
protected services;

/**
 * List of shared instances
 */
protected sharedInstances;

/**
 * Events Manager
 *
 * @var ManagerInterface
 */
protected eventsManager;

/**
 * Latest DI build
 */
protected static _default;

```

## Methods
```php
public function __call( string $method, array $arguments = [] ): mixed | null;
```
Magic method to get or set services using setters/getters


```php
public function __construct(): void;
```
Phalcon\Di constructor


```php
public function attempt( string $name, mixed $definition, bool $shared = bool ): ServiceInterface | bool;
```
Attempts to register a service in the services container
Only is successful if a service hasn't been registered previously
with the same name


```php
public function get( string $name, mixed $parameters = null ): mixed;
```
Resolves the service based on its configuration


```php
public function getInternalEventsManager(): ManagerInterface;
```
Returns the internal event manager


```php
public function getRaw( string $name ): mixed;
```
Returns a service definition without resolving


```php
public function getService( string $name ): ServiceInterface;
```
Returns a Phalcon\Di\Service instance


```php
public function getServices(): ServiceInterface[];
```
Return the services registered in the DI


```php
public function getShared( string $name, mixed $parameters = null ): mixed;
```
Resolves a service, the resolved service is stored in the DI, subsequent
requests for this service will return the same instance


```php
public function has( string $name ): bool;
```
Check whether the DI contains a service by a name


```php
public function loadFromPhp( string $filePath ): void;
```
Loads services from a php config file.

```php
$di->loadFromPhp("path/services.php");
```

And the services can be specified in the file as:

```php
return [
     'myComponent' => [
         'className' => '\Acme\Components\MyComponent',
         'shared' => true,
     ],
     'group' => [
         'className' => '\Acme\Group',
         'arguments' => [
             [
                 'type' => 'service',
                 'service' => 'myComponent',
             ],
         ],
     ],
     'user' => [
         'className' => '\Acme\User',
     ],
];
```

@link https://docs.phalcon.io/en/latest/reference/di.html


```php
public function loadFromYaml( string $filePath, array $callbacks = null ): void;
```
Loads services from a yaml file.

```php
$di->loadFromYaml(
    "path/services.yaml",
    [
        "!approot" => function ($value) {
            return dirname(__DIR__) . $value;
        }
    ]
);
```

And the services can be specified in the file as:

```php
myComponent:
    className: \Acme\Components\MyComponent
    shared: true

group:
    className: \Acme\Group
    arguments:
        - type: service
          name: myComponent

user:
   className: \Acme\User
```

@link https://docs.phalcon.io/en/latest/reference/di.html


```php
public function offsetExists( mixed $name ): bool;
```
Check if a service is registered using the array syntax


```php
public function offsetGet( mixed $name ): mixed;
```
Allows to obtain a shared service using the array syntax

```php
var_dump($di["request"]);
```


```php
public function offsetSet( mixed $name, mixed $definition ): void;
```
Allows to register a shared service using the array syntax

```php
$di["request"] = new \Phalcon\Http\Request();
```


```php
public function offsetUnset( mixed $name ): void;
```
Removes a service from the services container using the array syntax


```php
public function register( ServiceProviderInterface $provider ): void;
```
Registers a service provider.

```php
use Phalcon\Di\DiInterface;
use Phalcon\Di\ServiceProviderInterface;

class SomeServiceProvider implements ServiceProviderInterface
{
    public function register(DiInterface $di)
    {
        $di->setShared(
            'service',
            function () {
                // ...
            }
        );
    }
}
```


```php
public function remove( string $name ): void;
```
Removes a service in the services container
It also removes any shared instance created for the service


```php
public function set( string $name, mixed $definition, bool $shared = bool ): ServiceInterface;
```
Registers a service in the services container


```php
public function setInternalEventsManager( ManagerInterface $eventsManager );
```
Sets the internal event manager


```php
public function setRaw( string $name, ServiceInterface $rawDefinition ): ServiceInterface;
```
Sets a service using a raw Phalcon\Di\Service definition


```php
public function setShared( string $name, mixed $definition ): ServiceInterface;
```
Registers an "always shared" service in the services container


```php
protected function loadFromConfig( Config $config ): void;
```
Loads services from a Config object.



        
<h1 id="di-abstractinjectionaware">Abstract Class Phalcon\Di\AbstractInjectionAware</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/di/abstractinjectionaware.zep)

| Namespace  | Phalcon\Di |
| Uses       | Phalcon\Di, Phalcon\Di\DiInterface, Phalcon\Di\InjectionAwareInterface |
| Implements | InjectionAwareInterface |

This abstract class offers common access to the DI in a class


## Properties
```php
/**
 * Dependency Injector
 *
 * @var DiInterface
 */
protected container;

```

## Methods
```php
public function getDI(): DiInterface;
```
Returns the internal dependency injector


```php
public function setDI( DiInterface $container ): void;
```
Sets the dependency injector



        
<h1 id="di-diinterface">Interface Phalcon\Di\DiInterface</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/di/diinterface.zep)

| Namespace  | Phalcon\Di |
| Uses       | ArrayAccess, Phalcon\Di\ServiceInterface |
| Extends    | ArrayAccess |

Interface for Phalcon\Di


## Methods
```php
public function attempt( string $name, mixed $definition, bool $shared = bool ): ServiceInterface | bool;
```
Attempts to register a service in the services container
Only is successful if a service hasn't been registered previously
with the same name

@param mixed definition


```php
public function get( string $name, mixed $parameters = null ): mixed;
```
Resolves the service based on its configuration


```php
public function getRaw( string $name ): mixed;
```
Returns a service definition without resolving


```php
public function getService( string $name ): ServiceInterface;
```
Returns the corresponding Phalcon\Di\Service instance for a service


```php
public function getServices(): ServiceInterface[];
```
Return the services registered in the DI


```php
public function getShared( string $name, mixed $parameters = null ): mixed;
```
Returns a shared service based on their configuration


```php
public function has( string $name ): bool;
```
Check whether the DI contains a service by a name


```php
public function remove( string $name ): void;
```
Removes a service in the services container


```php
public function set( string $name, mixed $definition, bool $shared = bool ): ServiceInterface;
```
Registers a service in the services container


```php
public function setRaw( string $name, ServiceInterface $rawDefinition ): ServiceInterface;
```
Sets a service using a raw Phalcon\Di\Service definition


```php
public function setShared( string $name, mixed $definition ): ServiceInterface;
```
Registers an "always shared" service in the services container



        
<h1 id="di-exception">Class Phalcon\Di\Exception</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/di/exception.zep)

| Namespace  | Phalcon\Di |
| Extends    | \Phalcon\Exception |

Exceptions thrown in Phalcon\Di will use this class


        
<h1 id="di-exception-serviceresolutionexception">Class Phalcon\Di\Exception\ServiceResolutionException</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/di/exception/serviceresolutionexception.zep)

| Namespace  | Phalcon\Di\Exception |
| Uses       | Phalcon\Di\Exception\ServiceResolutionException |
| Extends    | \Phalcon\Di\Exception |

 Phalcon\Di\Exception\ServiceResolutionException
 

        
<h1 id="di-factorydefault">Class Phalcon\Di\FactoryDefault</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/di/factorydefault.zep)

| Namespace  | Phalcon\Di |
| Uses       | Phalcon\Filter\FilterFactory |
| Extends    | \Phalcon\Di |

This is a variant of the standard Phalcon\Di. By default it automatically
registers all the services provided by the framework. Thanks to this, the
developer does not need to register each service individually providing a
full stack framework


## Methods
```php
public function __construct(): void;
```
Phalcon\Di\FactoryDefault constructor



        
<h1 id="di-factorydefault-cli">Class Phalcon\Di\FactoryDefault\Cli</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/di/factorydefault/cli.zep)

| Namespace  | Phalcon\Di\FactoryDefault |
| Uses       | Phalcon\Di\FactoryDefault, Phalcon\Di\Service, Phalcon\Filter\FilterFactory |
| Extends    | FactoryDefault |

Phalcon\Di\FactoryDefault\Cli

This is a variant of the standard Phalcon\Di. By default it automatically
registers all the services provided by the framework.
Thanks to this, the developer does not need to register each service individually.
This class is specially suitable for CLI applications


## Methods
```php
public function __construct(): void;
```
Phalcon\Di\FactoryDefault\Cli constructor



        
<h1 id="di-injectable">Abstract Class Phalcon\Di\Injectable</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/di/injectable.zep)

| Namespace  | Phalcon\Di |
| Uses       | Phalcon\Di, Phalcon\Di\DiInterface, Phalcon\Events\ManagerInterface, Phalcon\Di\InjectionAwareInterface, Phalcon\Events\EventsAwareInterface, Phalcon\Di\Exception, Phalcon\Session\BagInterface |
| Implements | InjectionAwareInterface, EventsAwareInterface |

This class allows to access services in the services container by just only
accessing a public property with the same name of a registered service

@property \Phalcon\Mvc\Dispatcher|\Phalcon\Mvc\DispatcherInterface $dispatcher
@property \Phalcon\Mvc\Router|\Phalcon\Mvc\RouterInterface $router
@property \Phalcon\Url|\Phalcon\Url\UrlInterface $url
@property \Phalcon\Http\Request|\Phalcon\Http\RequestInterface $request
@property \Phalcon\Http\Response|\Phalcon\Http\ResponseInterface $response
@property \Phalcon\Http\Response\Cookies|\Phalcon\Http\Response\CookiesInterface $cookies
@property \Phalcon\Filter\FilterLocator $filter
@property \Phalcon\Flash\Direct $flash
@property \Phalcon\Flash\Session $flashSession
@property \Phalcon\Session\ManagerInterface $session
@property \Phalcon\Events\Manager|\Phalcon\Events\ManagerInterface $eventsManager
@property \Phalcon\Db\Adapter\AdapterInterface $db
@property \Phalcon\Security $security
@property \Phalcon\Crypt|\Phalcon\CryptInterface $crypt
@property \Phalcon\Tag $tag
@property \Phalcon\Escaper|\Phalcon\Escaper\EscaperInterface $escaper
@property \Phalcon\Annotations\Adapter\Memory|\Phalcon\Annotations\Adapter $annotations
@property \Phalcon\Mvc\Model\Manager|\Phalcon\Mvc\Model\ManagerInterface $modelsManager
@property \Phalcon\Mvc\Model\MetaData\Memory|\Phalcon\Mvc\Model\MetadataInterface $modelsMetadata
@property \Phalcon\Mvc\Model\Transaction\Manager|\Phalcon\Mvc\Model\Transaction\ManagerInterface $transactionManager
@property \Phalcon\Assets\Manager $assets
@property \Phalcon\Di|\Phalcon\Di\DiInterface $di
@property \Phalcon\Session\Bag|\Phalcon\Session\BagInterface $persistent
@property \Phalcon\Mvc\View|\Phalcon\Mvc\ViewInterface $view


## Properties
```php
/**
 * Dependency Injector
 *
 * @var DiInterface
 */
protected container;

/**
 * Events Manager
 *
 * @var \Phalcon\Events\ManagerInterface
 */
protected eventsManager;

```

## Methods
```php
public function __get( string $propertyName ): mixed | null;
```
Magic method __get


```php
public function getDI(): DiInterface;
```
Returns the internal dependency injector


```php
public function getEventsManager(): ManagerInterface;
```
Returns the internal event manager


```php
public function setDI( DiInterface $container ): void;
```
Sets the dependency injector


```php
public function setEventsManager( ManagerInterface $eventsManager ): void;
```
Sets the event manager



        
<h1 id="di-injectionawareinterface">Interface Phalcon\Di\InjectionAwareInterface</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/di/injectionawareinterface.zep)

| Namespace  | Phalcon\Di |
| Uses       | Phalcon\Di\DiInterface |

This interface must be implemented in those classes that uses internally the
Phalcon\Di that creates them


## Methods
```php
public function getDI(): DiInterface;
```
Returns the internal dependency injector


```php
public function setDI( DiInterface $container ): void;
```
Sets the dependency injector



        
<h1 id="di-service">Class Phalcon\Di\Service</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/di/service.zep)

| Namespace  | Phalcon\Di |
| Uses       | Closure, Phalcon\Di\DiInterface, Phalcon\Di\Exception, Phalcon\Di\Exception\ServiceResolutionException, Phalcon\Di\ServiceInterface, Phalcon\Di\Service\Builder |
| Implements | ServiceInterface |

Represents individually a service in the services container

```php
$service = new \Phalcon\Di\Service(
    "request",
    \Phalcon\Http\Request::class
);

$request = service->resolve();
```


## Properties
```php
//
protected definition;

/**
 * @var bool
 */
protected resolved = false;

/**
 * @var bool
 */
protected shared = false;

//
protected sharedInstance;

```

## Methods
```php
final public function __construct( mixed $definition, bool $shared = bool ): void;
```
Phalcon\Di\Service


```php
public function getDefinition(): mixed;
```
Returns the service definition


```php
public function getParameter( int $position );
```
Returns a parameter in a specific position

@return array


```php
public function isResolved(): bool;
```
Returns true if the service was resolved


```php
public function isShared(): bool;
```
Check whether the service is shared or not


```php
public function resolve( mixed $parameters = null, DiInterface $container = null ): mixed;
```
Resolves the service

@param array parameters


```php
public function setDefinition( mixed $definition ): void;
```
Set the service definition


```php
public function setParameter( int $position, array $parameter ): ServiceInterface;
```
Changes a parameter in the definition without resolve the service


```php
public function setShared( bool $shared ): void;
```
Sets if the service is shared or not


```php
public function setSharedInstance( mixed $sharedInstance ): void;
```
Sets/Resets the shared instance related to the service



        
<h1 id="di-service-builder">Class Phalcon\Di\Service\Builder</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/di/service/builder.zep)

| Namespace  | Phalcon\Di\Service |
| Uses       | Phalcon\Di\DiInterface, Phalcon\Di\Exception |

Phalcon\Di\Service\Builder

This class builds instances based on complex definitions


## Methods
```php
public function build( DiInterface $container, array $definition, mixed $parameters = null );
```
Builds a service using a complex service definition

@param array parameters
@return mixed



        
<h1 id="di-serviceinterface">Interface Phalcon\Di\ServiceInterface</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/di/serviceinterface.zep)

| Namespace  | Phalcon\Di |
| Uses       | Phalcon\Di\DiInterface |

Represents a service in the services container


## Methods
```php
public function getDefinition(): mixed;
```
Returns the service definition


```php
public function getParameter( int $position );
```
Returns a parameter in a specific position

@return array


```php
public function isResolved(): bool;
```
Returns true if the service was resolved


```php
public function isShared(): bool;
```
Check whether the service is shared or not


```php
public function resolve( mixed $parameters = null, DiInterface $container = null ): mixed;
```
Resolves the service

@param array parameters


```php
public function setDefinition( mixed $definition );
```
Set the service definition


```php
public function setParameter( int $position, array $parameter ): ServiceInterface;
```
Changes a parameter in the definition without resolve the service


```php
public function setShared( bool $shared );
```
Sets if the service is shared or not



        
<h1 id="di-serviceproviderinterface">Interface Phalcon\Di\ServiceProviderInterface</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/di/serviceproviderinterface.zep)

| Namespace  | Phalcon\Di |
| Uses       | Phalcon\Di\DiInterface |

Should be implemented by service providers, or such components, which
register a service in the service container.

```php
namespace Acme;

use Phalcon\Di\DiInterface;
use Phalcon\Di\ServiceProviderInterface;

class SomeServiceProvider implements ServiceProviderInterface
{
    public function register(DiInterface $di)
    {
        $di->setShared(
            'service',
            function () {
                // ...
            }
        );
    }
}
```


## Methods
```php
public function register( DiInterface $di ): void;
```
Registers a service provider.


