---
layout: default
language: 'en'
version: '4.0'
title: 'Phalcon\Mvc'
---

* [Phalcon\Mvc\Application](#mvc-application)
* [Phalcon\Mvc\Application\Exception](#mvc-application-exception)
* [Phalcon\Mvc\Controller](#mvc-controller)
* [Phalcon\Mvc\Controller\BindModelInterface](#mvc-controller-bindmodelinterface)
* [Phalcon\Mvc\ControllerInterface](#mvc-controllerinterface)
* [Phalcon\Mvc\Dispatcher](#mvc-dispatcher)
* [Phalcon\Mvc\Dispatcher\Exception](#mvc-dispatcher-exception)
* [Phalcon\Mvc\DispatcherInterface](#mvc-dispatcherinterface)
* [Phalcon\Mvc\EntityInterface](#mvc-entityinterface)
* [Phalcon\Mvc\Micro](#mvc-micro)
* [Phalcon\Mvc\Micro\Collection](#mvc-micro-collection)
* [Phalcon\Mvc\Micro\CollectionInterface](#mvc-micro-collectioninterface)
* [Phalcon\Mvc\Micro\Exception](#mvc-micro-exception)
* [Phalcon\Mvc\Micro\LazyLoader](#mvc-micro-lazyloader)
* [Phalcon\Mvc\Micro\MiddlewareInterface](#mvc-micro-middlewareinterface)
* [Phalcon\Mvc\Model](#mvc-model)
* [Phalcon\Mvc\Model\Behavior](#mvc-model-behavior)
* [Phalcon\Mvc\Model\Behavior\SoftDelete](#mvc-model-behavior-softdelete)
* [Phalcon\Mvc\Model\Behavior\Timestampable](#mvc-model-behavior-timestampable)
* [Phalcon\Mvc\Model\BehaviorInterface](#mvc-model-behaviorinterface)
* [Phalcon\Mvc\Model\Binder](#mvc-model-binder)
* [Phalcon\Mvc\Model\Binder\BindableInterface](#mvc-model-binder-bindableinterface)
* [Phalcon\Mvc\Model\BinderInterface](#mvc-model-binderinterface)
* [Phalcon\Mvc\Model\Criteria](#mvc-model-criteria)
* [Phalcon\Mvc\Model\CriteriaInterface](#mvc-model-criteriainterface)
* [Phalcon\Mvc\Model\Exception](#mvc-model-exception)
* [Phalcon\Mvc\Model\Manager](#mvc-model-manager)
* [Phalcon\Mvc\Model\ManagerInterface](#mvc-model-managerinterface)
* [Phalcon\Mvc\Model\MetaData](#mvc-model-metadata)
* [Phalcon\Mvc\Model\MetaData\Apcu](#mvc-model-metadata-apcu)
* [Phalcon\Mvc\Model\MetaData\Libmemcached](#mvc-model-metadata-libmemcached)
* [Phalcon\Mvc\Model\MetaData\Memory](#mvc-model-metadata-memory)
* [Phalcon\Mvc\Model\MetaData\Redis](#mvc-model-metadata-redis)
* [Phalcon\Mvc\Model\MetaData\Strategy\Annotations](#mvc-model-metadata-strategy-annotations)
* [Phalcon\Mvc\Model\MetaData\Strategy\Introspection](#mvc-model-metadata-strategy-introspection)
* [Phalcon\Mvc\Model\MetaData\StrategyInterface](#mvc-model-metadata-strategyinterface)
* [Phalcon\Mvc\Model\MetaData\Stream](#mvc-model-metadata-stream)
* [Phalcon\Mvc\Model\MetaDataInterface](#mvc-model-metadatainterface)
* [Phalcon\Mvc\Model\Query](#mvc-model-query)
* [Phalcon\Mvc\Model\Query\Builder](#mvc-model-query-builder)
* [Phalcon\Mvc\Model\Query\BuilderInterface](#mvc-model-query-builderinterface)
* [Phalcon\Mvc\Model\Query\Lang](#mvc-model-query-lang)
* [Phalcon\Mvc\Model\Query\Status](#mvc-model-query-status)
* [Phalcon\Mvc\Model\Query\StatusInterface](#mvc-model-query-statusinterface)
* [Phalcon\Mvc\Model\QueryInterface](#mvc-model-queryinterface)
* [Phalcon\Mvc\Model\Relation](#mvc-model-relation)
* [Phalcon\Mvc\Model\RelationInterface](#mvc-model-relationinterface)
* [Phalcon\Mvc\Model\ResultInterface](#mvc-model-resultinterface)
* [Phalcon\Mvc\Model\Resultset](#mvc-model-resultset)
* [Phalcon\Mvc\Model\Resultset\Complex](#mvc-model-resultset-complex)
* [Phalcon\Mvc\Model\Resultset\Simple](#mvc-model-resultset-simple)
* [Phalcon\Mvc\Model\ResultsetInterface](#mvc-model-resultsetinterface)
* [Phalcon\Mvc\Model\Row](#mvc-model-row)
* [Phalcon\Mvc\Model\Transaction](#mvc-model-transaction)
* [Phalcon\Mvc\Model\Transaction\Exception](#mvc-model-transaction-exception)
* [Phalcon\Mvc\Model\Transaction\Failed](#mvc-model-transaction-failed)
* [Phalcon\Mvc\Model\Transaction\Manager](#mvc-model-transaction-manager)
* [Phalcon\Mvc\Model\Transaction\ManagerInterface](#mvc-model-transaction-managerinterface)
* [Phalcon\Mvc\Model\TransactionInterface](#mvc-model-transactioninterface)
* [Phalcon\Mvc\Model\ValidationFailed](#mvc-model-validationfailed)
* [Phalcon\Mvc\ModelInterface](#mvc-modelinterface)
* [Phalcon\Mvc\ModuleDefinitionInterface](#mvc-moduledefinitioninterface)
* [Phalcon\Mvc\Router](#mvc-router)
* [Phalcon\Mvc\Router\Annotations](#mvc-router-annotations)
* [Phalcon\Mvc\Router\Exception](#mvc-router-exception)
* [Phalcon\Mvc\Router\Group](#mvc-router-group)
* [Phalcon\Mvc\Router\GroupInterface](#mvc-router-groupinterface)
* [Phalcon\Mvc\Router\Route](#mvc-router-route)
* [Phalcon\Mvc\Router\RouteInterface](#mvc-router-routeinterface)
* [Phalcon\Mvc\RouterInterface](#mvc-routerinterface)
* [Phalcon\Mvc\View](#mvc-view)
* [Phalcon\Mvc\View\Engine\AbstractEngine](#mvc-view-engine-abstractengine)
* [Phalcon\Mvc\View\Engine\EngineInterface](#mvc-view-engine-engineinterface)
* [Phalcon\Mvc\View\Engine\Php](#mvc-view-engine-php)
* [Phalcon\Mvc\View\Engine\Volt](#mvc-view-engine-volt)
* [Phalcon\Mvc\View\Engine\Volt\Compiler](#mvc-view-engine-volt-compiler)
* [Phalcon\Mvc\View\Engine\Volt\Exception](#mvc-view-engine-volt-exception)
* [Phalcon\Mvc\View\Exception](#mvc-view-exception)
* [Phalcon\Mvc\View\Simple](#mvc-view-simple)
* [Phalcon\Mvc\ViewBaseInterface](#mvc-viewbaseinterface)
* [Phalcon\Mvc\ViewInterface](#mvc-viewinterface)
        
<h1 id="mvc-application">Class Phalcon\Mvc\Application</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/application.zep)

| Namespace  | Phalcon\Mvc |
| Uses       | Closure, Phalcon\Application\AbstractApplication, Phalcon\Di\DiInterface, Phalcon\Mvc\ViewInterface, Phalcon\Mvc\RouterInterface, Phalcon\Http\ResponseInterface, Phalcon\Events\ManagerInterface, Phalcon\Mvc\DispatcherInterface, Phalcon\Mvc\Application\Exception, Phalcon\Mvc\Router\RouteInterface, Phalcon\Mvc\ModuleDefinitionInterface |
| Extends    | AbstractApplication |

Phalcon\Mvc\Application

This component encapsulates all the complex operations behind instantiating
every component needed and integrating it with the rest to allow the MVC
pattern to operate as desired.

```php
use Phalcon\Mvc\Application;

class MyApp extends Application
{
Register the services here to make them general or register
in the ModuleDefinition to make them module-specific
\/
    protected function registerServices()
    {

    }

This method registers all the modules in the application
\/
    public function main()
    {
        $this->registerModules(
            [
                "frontend" => [
                    "className" => "Multiple\\Frontend\\Module",
                    "path"      => "../apps/frontend/Module.php",
                ],
                "backend" => [
                    "className" => "Multiple\\Backend\\Module",
                    "path"      => "../apps/backend/Module.php",
                ],
            ]
        );
    }
}

$application = new MyApp();

$application->main();
```


## Properties
```php
//
protected implicitView = true;

//
protected sendCookies = true;

//
protected sendHeaders = true;

```

## Methods
```php
public function handle( string $uri ): ResponseInterface | bool;
```
Handles a MVC request


```php
public function sendCookiesOnHandleRequest( bool $sendCookies ): Application;
```
Enables or disables sending cookies by each request handling


```php
public function sendHeadersOnHandleRequest( bool $sendHeaders ): Application;
```
Enables or disables sending headers by each request handling


```php
public function useImplicitView( bool $implicitView ): Application;
```
By default. The view is implicitly buffering all the output
You can full disable the view component using this method



        
<h1 id="mvc-application-exception">Class Phalcon\Mvc\Application\Exception</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/application/exception.zep)

| Namespace  | Phalcon\Mvc\Application |
| Extends    | \Phalcon\Application\Exception |

Phalcon\Mvc\Application\Exception

Exceptions thrown in Phalcon\Mvc\Application class will use this class


        
<h1 id="mvc-controller">Abstract Class Phalcon\Mvc\Controller</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/controller.zep)

| Namespace  | Phalcon\Mvc |
| Uses       | Phalcon\Di\Injectable |
| Extends    | Injectable |
| Implements | ControllerInterface |

Phalcon\Mvc\Controller

Every application controller should extend this class that encapsulates all
the controller functionality

The controllers provide the “flow” between models and views. Controllers are
responsible for processing the incoming requests from the web browser,
interrogating the models for data, and passing that data on to the views for
presentation.

```php
<?php

class PeopleController extends \Phalcon\Mvc\Controller
{
    // This action will be executed by default
    public function indexAction()
    {

    }

    public function findAction()
    {

    }

    public function saveAction()
    {
        // Forwards flow to the index action
        return $this->dispatcher->forward(
            [
                "controller" => "people",
                "action"     => "index",
            ]
        );
    }
}
```


## Methods
```php
final public function __construct();
```
Phalcon\Mvc\Controller constructor



        
<h1 id="mvc-controller-bindmodelinterface">Interface Phalcon\Mvc\Controller\BindModelInterface</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/controller/bindmodelinterface.zep)

| Namespace  | Phalcon\Mvc\Controller |

Phalcon\Mvc\Controller\BindModelInterface

Interface for Phalcon\Mvc\Controller


        
<h1 id="mvc-controllerinterface">Interface Phalcon\Mvc\ControllerInterface</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/controllerinterface.zep)

| Namespace  | Phalcon\Mvc |

Phalcon\Mvc\ControllerInterface

Interface for controller handlers


        
<h1 id="mvc-dispatcher">Class Phalcon\Mvc\Dispatcher</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/dispatcher.zep)

| Namespace  | Phalcon\Mvc |
| Uses       | Phalcon\Mvc\DispatcherInterface, Phalcon\Mvc\Dispatcher\Exception, Phalcon\Events\ManagerInterface, Phalcon\Http\ResponseInterface, Phalcon\Mvc\ControllerInterface, Phalcon\Dispatcher\AbstractDispatcher |
| Extends    | BaseDispatcher |
| Implements | DispatcherInterface |

Dispatching is the process of taking the request object, extracting the
module name, controller name, action name, and optional parameters contained
in it, and then instantiating a controller and calling an action of that
controller.

```php
$di = new \Phalcon\Di();

$dispatcher = new \Phalcon\Mvc\Dispatcher();

$dispatcher->setDI($di);

$dispatcher->setControllerName("posts");
$dispatcher->setActionName("index");
$dispatcher->setParams([]);

$controller = $dispatcher->dispatch();
```


## Properties
```php
//
protected defaultAction = index;

//
protected defaultHandler = index;

//
protected handlerSuffix = Controller;

```

## Methods
```php
public function forward( mixed $forward );
```
Forwards the execution flow to another controller/action.

```php
use Phalcon\Events\Event;
use Phalcon\Mvc\Dispatcher;
use App\Backend\Bootstrap as Backend;
use App\Frontend\Bootstrap as Frontend;

// Registering modules
$modules = [
    "frontend" => [
        "className" => Frontend::class,
        "path"      => __DIR__ . "/app/Modules/Frontend/Bootstrap.php",
        "metadata"  => [
            "controllersNamespace" => "App\Frontend\Controllers",
        ],
    ],
    "backend" => [
        "className" => Backend::class,
        "path"      => __DIR__ . "/app/Modules/Backend/Bootstrap.php",
        "metadata"  => [
            "controllersNamespace" => "App\Backend\Controllers",
        ],
    ],
];

$application->registerModules($modules);

// Setting beforeForward listener
$eventsManager  = $di->getShared("eventsManager");

$eventsManager->attach(
    "dispatch:beforeForward",
    function(Event $event, Dispatcher $dispatcher, array $forward) use ($modules) {
        $metadata = $modules[$forward["module"]]["metadata"];

        $dispatcher->setModuleName(
            $forward["module"]
        );

        $dispatcher->setNamespaceName(
            $metadata["controllersNamespace"]
        );
    }
);

// Forward
$this->dispatcher->forward(
    [
        "module"     => "backend",
        "controller" => "posts",
        "action"     => "index",
    ]
);
```

@param array forward


```php
public function getActiveController(): ControllerInterface;
```
Returns the active controller in the dispatcher


```php
public function getControllerClass(): string;
```
Possible controller class name that will be located to dispatch the
request


```php
public function getControllerName(): string;
```
Gets last dispatched controller name


```php
public function getLastController(): ControllerInterface;
```
Returns the latest dispatched controller


```php
public function getPreviousActionName(): string;
```
Gets previous dispatched action name


```php
public function getPreviousControllerName(): string;
```
Gets previous dispatched controller name


```php
public function getPreviousNamespaceName(): string;
```
Gets previous dispatched namespace name


```php
public function setControllerName( string $controllerName );
```
Sets the controller name to be dispatched


```php
public function setControllerSuffix( string $controllerSuffix );
```
Sets the default controller suffix


```php
public function setDefaultController( string $controllerName );
```
Sets the default controller name


```php
protected function handleException( \Exception $exception );
```
Handles a user exception


```php
protected function throwDispatchException( string $message, int $exceptionCode = int );
```
Throws an internal exception



        
<h1 id="mvc-dispatcher-exception">Class Phalcon\Mvc\Dispatcher\Exception</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/dispatcher/exception.zep)

| Namespace  | Phalcon\Mvc\Dispatcher |
| Extends    | \Phalcon\Dispatcher\Exception |

Phalcon\Mvc\Dispatcher\Exception

Exceptions thrown in Phalcon\Mvc\Dispatcher will use this class


        
<h1 id="mvc-dispatcherinterface">Interface Phalcon\Mvc\DispatcherInterface</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/dispatcherinterface.zep)

| Namespace  | Phalcon\Mvc |
| Uses       | Phalcon\Mvc\ControllerInterface, Phalcon\Dispatcher\DispatcherInterface |
| Extends    | DispatcherInterfaceBase |

Phalcon\Mvc\DispatcherInterface

Interface for Phalcon\Mvc\Dispatcher


## Methods
```php
public function getActiveController(): ControllerInterface;
```
Returns the active controller in the dispatcher


```php
public function getControllerName(): string;
```
Gets last dispatched controller name


```php
public function getLastController(): ControllerInterface;
```
Returns the latest dispatched controller


```php
public function setControllerName( string $controllerName );
```
Sets the controller name to be dispatched


```php
public function setControllerSuffix( string $controllerSuffix );
```
Sets the default controller suffix


```php
public function setDefaultController( string $controllerName );
```
Sets the default controller name



        
<h1 id="mvc-entityinterface">Interface Phalcon\Mvc\EntityInterface</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/entityinterface.zep)

| Namespace  | Phalcon\Mvc |

Phalcon\Mvc\EntityInterface

Interface for Phalcon\Mvc\Collection and Phalcon\Mvc\Model


## Methods
```php
public function readAttribute( string $attribute ): mixed | null;
```
Reads an attribute value by its name


```php
public function writeAttribute( string $attribute, mixed $value );
```
Writes an attribute value by its name



        
<h1 id="mvc-micro">Class Phalcon\Mvc\Micro</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/micro.zep)

| Namespace  | Phalcon\Mvc |
| Uses       | ArrayAccess, Closure, Phalcon\Di\DiInterface, Phalcon\Di\Injectable, Phalcon\Mvc\Controller, Phalcon\Di\FactoryDefault, Phalcon\Mvc\Micro\Exception, Phalcon\Di\ServiceInterface, Phalcon\Mvc\Micro\Collection, Phalcon\Mvc\Micro\LazyLoader, Phalcon\Http\ResponseInterface, Phalcon\Mvc\Model\BinderInterface, Phalcon\Mvc\Router\RouteInterface, Phalcon\Mvc\Micro\MiddlewareInterface, Phalcon\Mvc\Micro\CollectionInterface, Throwable |
| Extends    | Injectable |
| Implements | ArrayAccess |

Phalcon\Mvc\Micro

With Phalcon you can create "Micro-Framework like" applications. By doing
this, you only need to write a minimal amount of code to create a PHP
application. Micro applications are suitable to small applications, APIs and
prototypes in a practical way.

```php
$app = new \Phalcon\Mvc\Micro();

$app->get(
    "/say/welcome/{name}",
    function ($name) {
        echo "<h1>Welcome $name!</h1>";
    }
);

$app->handle("/say/welcome/Phalcon");
```


## Properties
```php
//
protected activeHandler;

//
protected afterBindingHandlers;

//
protected afterHandlers;

//
protected beforeHandlers;

//
protected container;

//
protected errorHandler;

//
protected finishHandlers;

//
protected handlers;

//
protected modelBinder;

//
protected notFoundHandler;

//
protected responseHandler;

//
protected returnedValue;

//
protected router;

//
protected stopped;

```

## Methods
```php
public function __construct( DiInterface $container = null );
```
Phalcon\Mvc\Micro constructor


```php
public function after( mixed $handler ): Micro;
```
Appends an 'after' middleware to be called after execute the route

@param callable handler


```php
public function afterBinding( mixed $handler ): Micro;
```
Appends a afterBinding middleware to be called after model binding

@param callable handler


```php
public function before( mixed $handler ): Micro;
```
Appends a before middleware to be called before execute the route

@param callable handler


```php
public function delete( string $routePattern, mixed $handler ): RouteInterface;
```
Maps a route to a handler that only matches if the HTTP method is DELETE

@param callable handler


```php
public function error( mixed $handler ): Micro;
```
Sets a handler that will be called when an exception is thrown handling
the route

@param callable handler


```php
public function finish( mixed $handler ): Micro;
```
Appends a 'finish' middleware to be called when the request is finished

@param callable handler


```php
public function get( string $routePattern, mixed $handler ): RouteInterface;
```
Maps a route to a handler that only matches if the HTTP method is GET

@param callable handler


```php
public function getActiveHandler();
```
Return the handler that will be called for the matched route

@return callable


```php
public function getBoundModels(): array;
```
Returns bound models from binder instance


```php
public function getHandlers(): array;
```
Returns the internal handlers attached to the application


```php
public function getModelBinder(): BinderInterface | null;
```
Gets model binder


```php
public function getReturnedValue();
```
Returns the value returned by the executed handler

@return mixed


```php
public function getRouter(): RouterInterface;
```
Returns the internal router used by the application


```php
public function getService( string $serviceName );
```
Obtains a service from the DI

@return object


```php
public function getSharedService( string $serviceName );
```
Obtains a shared service from the DI

@return mixed


```php
public function handle( string $uri );
```
Handle the whole request

@param string uri
@return mixed


```php
public function hasService( string $serviceName ): bool;
```
Checks if a service is registered in the DI


```php
public function head( string $routePattern, mixed $handler ): RouteInterface;
```
Maps a route to a handler that only matches if the HTTP method is HEAD

@param callable handler


```php
public function map( string $routePattern, mixed $handler ): RouteInterface;
```
Maps a route to a handler without any HTTP method constraint

@param callable handler


```php
public function mount( CollectionInterface $collection ): Micro;
```
Mounts a collection of handlers


```php
public function notFound( mixed $handler ): Micro;
```
Sets a handler that will be called when the router doesn't match any of
the defined routes

@param callable handler


```php
public function offsetExists( mixed $alias ): bool;
```
Check if a service is registered in the internal services container using
the array syntax


```php
public function offsetGet( mixed $alias ): mixed;
```
Allows to obtain a shared service in the internal services container
using the array syntax

```php
var_dump(
    $app["request"]
);
```


```php
public function offsetSet( mixed $alias, mixed $definition ): void;
```
Allows to register a shared service in the internal services container
using the array syntax

```php
   $app["request"] = new \Phalcon\Http\Request();
```


```php
public function offsetUnset( mixed $alias ): void;
```
Removes a service from the internal services container using the array
syntax


```php
public function options( string $routePattern, mixed $handler ): RouteInterface;
```
Maps a route to a handler that only matches if the HTTP method is OPTIONS

@param callable handler


```php
public function patch( string $routePattern, mixed $handler ): RouteInterface;
```
Maps a route to a handler that only matches if the HTTP method is PATCH

@param callable $handler


```php
public function post( string $routePattern, mixed $handler ): RouteInterface;
```
Maps a route to a handler that only matches if the HTTP method is POST

@param callable handler


```php
public function put( string $routePattern, mixed $handler ): RouteInterface;
```
Maps a route to a handler that only matches if the HTTP method is PUT

@param callable $handler


```php
public function setActiveHandler( mixed $activeHandler );
```
Sets externally the handler that must be called by the matched route

@param callable activeHandler


```php
public function setDI( DiInterface $container ): void;
```
Sets the DependencyInjector container


```php
public function setModelBinder( BinderInterface $modelBinder, mixed $cache = null ): Micro;
```
Sets model binder

```php
$micro = new Micro($di);

$micro->setModelBinder(
    new Binder(),
    'cache'
);
```


```php
public function setResponseHandler( mixed $handler ): Micro;
```
Appends a custom 'reponse' handler to be called insted of the default
response handler

@param callable handler


```php
public function setService( string $serviceName, mixed $definition, bool $shared = bool ): ServiceInterface;
```
Sets a service from the DI


```php
public function stop();
```
Stops the middleware execution avoiding than other middlewares be
executed



        
<h1 id="mvc-micro-collection">Class Phalcon\Mvc\Micro\Collection</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/micro/collection.zep)

| Namespace  | Phalcon\Mvc\Micro |
| Implements | CollectionInterface |

Phalcon\Mvc\Micro\Collection

Groups Micro-Mvc handlers as controllers

```php
$app = new \Phalcon\Mvc\Micro();

$collection = new Collection();

$collection->setHandler(
    new PostsController()
);

$collection->get("/posts/edit/{id}", "edit");

$app->mount($collection);
```


## Properties
```php
//
protected handler;

//
protected handlers;

//
protected lazy;

//
protected prefix;

```

## Methods
```php
public function delete( string $routePattern, mixed $handler, string $name = null ): CollectionInterface;
```
Maps a route to a handler that only matches if the HTTP method is DELETE.

@param callable|string handler


```php
public function get( string $routePattern, mixed $handler, string $name = null ): CollectionInterface;
```
Maps a route to a handler that only matches if the HTTP method is GET.

@param callable|string handler


```php
public function getHandler(): mixed;
```
Returns the main handler


```php
public function getHandlers(): array;
```
Returns the registered handlers


```php
public function getPrefix(): string;
```
Returns the collection prefix if any


```php
public function head( string $routePattern, mixed $handler, string $name = null ): CollectionInterface;
```
Maps a route to a handler that only matches if the HTTP method is HEAD.

@param callable|string handler


```php
public function isLazy(): bool;
```
Returns if the main handler must be lazy loaded


```php
public function map( string $routePattern, mixed $handler, string $name = null ): CollectionInterface;
```
Maps a route to a handler.

@param callable|string handler


```php
public function mapVia( string $routePattern, mixed $handler, mixed $method, string $name = null ): CollectionInterface;
```
Maps a route to a handler via methods.

```php
$collection->mapVia(
    "/test",
    "indexAction",
    ["POST", "GET"],
    "test"
);
```

@param callable handler
@param string|array method


```php
public function options( string $routePattern, mixed $handler, string $name = null ): CollectionInterface;
```
Maps a route to a handler that only matches if the HTTP method is
OPTIONS.

@param callable|string handler


```php
public function patch( string $routePattern, mixed $handler, string $name = null ): CollectionInterface;
```
Maps a route to a handler that only matches if the HTTP method is PATCH.

@param callable|string handler


```php
public function post( string $routePattern, mixed $handler, string $name = null ): CollectionInterface;
```
Maps a route to a handler that only matches if the HTTP method is POST.

@param callable|string handler


```php
public function put( string $routePattern, mixed $handler, string $name = null ): CollectionInterface;
```
Maps a route to a handler that only matches if the HTTP method is PUT.

@param callable|string handler


```php
public function setHandler( mixed $handler, bool $lazy = bool ): CollectionInterface;
```
Sets the main handler.

@param callable|string handler


```php
public function setLazy( bool $lazy ): CollectionInterface;
```
Sets if the main handler must be lazy loaded


```php
public function setPrefix( string $prefix ): CollectionInterface;
```
Sets a prefix for all routes added to the collection


```php
protected function addMap( mixed $method, string $routePattern, mixed $handler, string $name );
```
Internal function to add a handler to the group.

@param string|array    method
@param callable|string handler



        
<h1 id="mvc-micro-collectioninterface">Interface Phalcon\Mvc\Micro\CollectionInterface</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/micro/collectioninterface.zep)

| Namespace  | Phalcon\Mvc\Micro |

Phalcon\Mvc\Micro\CollectionInterface

Interface for Phalcon\Mvc\Micro\Collection


## Methods
```php
public function delete( string $routePattern, callable $handler, string $name = null ): CollectionInterface;
```
Maps a route to a handler that only matches if the HTTP method is DELETE


```php
public function get( string $routePattern, callable $handler, string $name = null ): CollectionInterface;
```
Maps a route to a handler that only matches if the HTTP method is GET


```php
public function getHandler(): mixed;
```
Returns the main handler


```php
public function getHandlers(): array;
```
Returns the registered handlers


```php
public function getPrefix(): string;
```
Returns the collection prefix if any


```php
public function head( string $routePattern, callable $handler, string $name = null ): CollectionInterface;
```
Maps a route to a handler that only matches if the HTTP method is HEAD


```php
public function isLazy(): bool;
```
Returns if the main handler must be lazy loaded


```php
public function map( string $routePattern, callable $handler, string $name = null ): CollectionInterface;
```
Maps a route to a handler


```php
public function options( string $routePattern, callable $handler, string $name = null ): CollectionInterface;
```
Maps a route to a handler that only matches if the HTTP method is OPTIONS


```php
public function patch( string $routePattern, callable $handler, string $name = null ): CollectionInterface;
```
Maps a route to a handler that only matches if the HTTP method is PATCH


```php
public function post( string $routePattern, callable $handler, string $name = null ): CollectionInterface;
```
Maps a route to a handler that only matches if the HTTP method is POST


```php
public function put( string $routePattern, callable $handler, string $name = null ): CollectionInterface;
```
Maps a route to a handler that only matches if the HTTP method is PUT


```php
public function setHandler( mixed $handler, bool $lazy = bool ): CollectionInterface;
```
Sets the main handler


```php
public function setLazy( bool $lazy ): CollectionInterface;
```
Sets if the main handler must be lazy loaded


```php
public function setPrefix( string $prefix ): CollectionInterface;
```
Sets a prefix for all routes added to the collection



        
<h1 id="mvc-micro-exception">Class Phalcon\Mvc\Micro\Exception</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/micro/exception.zep)

| Namespace  | Phalcon\Mvc\Micro |
| Extends    | \Phalcon\Exception |

Exceptions thrown in Phalcon\Mvc\Micro will use this class


        
<h1 id="mvc-micro-lazyloader">Class Phalcon\Mvc\Micro\LazyLoader</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/micro/lazyloader.zep)

| Namespace  | Phalcon\Mvc\Micro |
| Uses       | Phalcon\Mvc\Model\BinderInterface |

Phalcon\Mvc\Micro\LazyLoader

Lazy-Load of handlers for Mvc\Micro using auto-loading


## Properties
```php
//
protected handler;

//
protected definition;

```

## Methods
```php
public function __construct( string $definition );
```
Phalcon\Mvc\Micro\LazyLoader constructor


```php
public function callMethod( string $method, mixed $arguments, BinderInterface $modelBinder = null );
```
Calling __call method

@param  array arguments
@return mixed


```php
public function getDefinition()
```



        
<h1 id="mvc-micro-middlewareinterface">Interface Phalcon\Mvc\Micro\MiddlewareInterface</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/micro/middlewareinterface.zep)

| Namespace  | Phalcon\Mvc\Micro |
| Uses       | Phalcon\Mvc\Micro |

Allows to implement Phalcon\Mvc\Micro middleware in classes


## Methods
```php
public function call( Micro $application );
```
Calls the middleware



        
<h1 id="mvc-model">Abstract Class Phalcon\Mvc\Model</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/model.zep)

| Namespace  | Phalcon\Mvc |
| Uses       | JsonSerializable, Phalcon\Db\Adapter\AdapterInterface, Phalcon\Db\Column, Phalcon\Db\DialectInterface, Phalcon\Db\Enum, Phalcon\Db\RawValue, Phalcon\Di\AbstractInjectionAware, Phalcon\Di, Phalcon\Di\DiInterface, Phalcon\Events\ManagerInterface, Phalcon\Helper\Arr, Phalcon\Messages\Message, Phalcon\Messages\MessageInterface, Phalcon\Mvc\Model\BehaviorInterface, Phalcon\Mvc\Model\Criteria, Phalcon\Mvc\Model\CriteriaInterface, Phalcon\Mvc\Model\Exception, Phalcon\Mvc\Model\ManagerInterface, Phalcon\Mvc\Model\MetaDataInterface, Phalcon\Mvc\Model\Query, Phalcon\Mvc\Model\Query\Builder, Phalcon\Mvc\Model\Query\BuilderInterface, Phalcon\Mvc\Model\QueryInterface, Phalcon\Mvc\Model\ResultInterface, Phalcon\Mvc\Model\Resultset, Phalcon\Mvc\Model\ResultsetInterface, Phalcon\Mvc\Model\Relation, Phalcon\Mvc\Model\RelationInterface, Phalcon\Mvc\Model\TransactionInterface, Phalcon\Mvc\Model\ValidationFailed, Phalcon\Mvc\ModelInterface, Phalcon\Validation\ValidationInterface, Phalcon\Events\ManagerInterface, Serializable |
| Extends    | AbstractInjectionAware |
| Implements | EntityInterface, ModelInterface, ResultInterface, Serializable, JsonSerializable |

Phalcon\Mvc\Model

Phalcon\Mvc\Model connects business objects and database tables to create a
persistable domain model where logic and data are presented in one wrapping.
It‘s an implementation of the object-relational mapping (ORM).

A model represents the information (data) of the application and the rules to
manipulate that data. Models are primarily used for managing the rules of
interaction with a corresponding database table. In most cases, each table in
your database will correspond to one model in your application. The bulk of
your application's business logic will be concentrated in the models.

Phalcon\Mvc\Model is the first ORM written in Zephir/C languages for PHP,
giving to developers high performance when interacting with databases while
is also easy to use.

```php
$robot = new Robots();

$robot->type = "mechanical";
$robot->name = "Astro Boy";
$robot->year = 1952;

if ($robot->save() === false) {
    echo "Umh, We can store robots: ";

    $messages = $robot->getMessages();

    foreach ($messages as $message) {
        echo $message;
    }
} else {
    echo "Great, a new robot was saved successfully!";
}
```


## Constants
```php
const DIRTY_STATE_DETACHED = 2;
const DIRTY_STATE_PERSISTENT = 0;
const DIRTY_STATE_TRANSIENT = 1;
const OP_CREATE = 1;
const OP_DELETE = 3;
const OP_NONE = 0;
const OP_UPDATE = 2;
const TRANSACTION_INDEX = transaction;
```

## Properties
```php
//
protected dirtyState = 1;

//
protected dirtyRelated;

//
protected errorMessages;

//
protected modelsManager;

//
protected modelsMetaData;

//
protected related;

//
protected operationMade = 0;

//
protected oldSnapshot;

//
protected skipped;

//
protected snapshot;

//
protected transaction;

//
protected uniqueKey;

//
protected uniqueParams;

//
protected uniqueTypes;

```

## Methods
```php
public function __call( string $method, array $arguments );
```
Handles method calls when a method is not implemented

@return    mixed


```php
public static function __callStatic( string $method, array $arguments );
```
Handles method calls when a static method is not implemented

@return mixed


```php
final public function __construct( mixed $data = null, DiInterface $container = null, ManagerInterface $modelsManager = null ): void;
```
Phalcon\Mvc\Model constructor


```php
public function __get( string $property );
```
Magic method to get related records using the relation alias as a
property

@return mixed


```php
public function __isset( string $property ): bool;
```
Magic method to check if a property is a valid relation


```php
public function __set( string $property, mixed $value );
```
Magic method to assign values to the the model

@param mixed value


```php
public function addBehavior( BehaviorInterface $behavior ): void;
```
Setups a behavior in a model

```php
use Phalcon\Mvc\Model;
use Phalcon\Mvc\Model\Behavior\Timestampable;

class Robots extends Model
{
    public function initialize()
    {
        $this->addBehavior(
            new Timestampable(
                [
                    "onCreate" => [
                        "field"  => "created_at",
                        "format" => "Y-m-d",
                    ],
                ]
            )
        );
    }
}
```


```php
public function appendMessage( MessageInterface $message ): ModelInterface;
```
Appends a customized message on the validation process

```php
use Phalcon\Mvc\Model;
use Phalcon\Messages\Message as Message;

class Robots extends Model
{
    public function beforeSave()
    {
        if ($this->name === "Peter") {
            $message = new Message(
                "Sorry, but a robot cannot be named Peter"
            );

            $this->appendMessage($message);
        }
    }
}
```


```php
public function assign( array $data, mixed $dataColumnMap = null, mixed $whiteList = null ): ModelInterface;
```
Assigns values to a model from an array

```php
$robot->assign(
    [
        "type" => "mechanical",
        "name" => "Astro Boy",
        "year" => 1952,
    ]
);

// Assign by db row, column map needed
$robot->assign(
    $dbRow,
    [
        "db_type" => "type",
        "db_name" => "name",
        "db_year" => "year",
    ]
);

// Allow assign only name and year
$robot->assign(
    $_POST,
    null,
    [
        "name",
        "year",
    ]
);

// By default assign method will use setters if exist, you can disable it by using ini_set to directly use properties

ini_set("phalcon.orm.disable_assign_setters", true);

$robot->assign(
    $_POST,
    null,
    [
        "name",
        "year",
    ]
);
```

@param array dataColumnMap array to transform keys of data to another
@param array whiteList


```php
public function create(): bool;
```
Inserts a model instance. If the instance already exists in the
persistence it will throw an exception
Returning true on success or false otherwise.

```php
// Creating a new robot
$robot = new Robots();

$robot->type = "mechanical";
$robot->name = "Astro Boy";
$robot->year = 1952;

$robot->create();

// Passing an array to create
$robot = new Robots();

$robot->assign(
    [
        "type" => "mechanical",
        "name" => "Astro Boy",
        "year" => 1952,
    ]
);

$robot->create();
```


```php
public function delete(): bool;
```
Deletes a model instance. Returning true on success or false otherwise.

```php
$robot = Robots::findFirst("id=100");

$robot->delete();

$robots = Robots::find("type = 'mechanical'");

foreach ($robots as $robot) {
    $robot->delete();
}
```


```php
public function dump(): array;
```
Returns a simple representation of the object that can be used with
`var_dump()`

```php
var_dump(
    $robot->dump()
);
```


```php
public function fireEvent( string $eventName ): bool;
```
Fires an event, implicitly calls behaviors and listeners in the events
manager are notified


```php
public function fireEventCancel( string $eventName ): bool;
```
Fires an event, implicitly calls behaviors and listeners in the events
manager are notified
This method stops if one of the callbacks/listeners returns bool false


```php
public function getChangedFields(): array;
```
Returns a list of changed values.

```php
$robots = Robots::findFirst();
print_r($robots->getChangedFields()); // []

$robots->deleted = 'Y';

$robots->getChangedFields();
print_r($robots->getChangedFields()); // ["deleted"]
```


```php
public function getDirtyState(): int;
```
Returns one of the DIRTY_STATE_* constants telling if the record exists
in the database or not


```php
public function getEventsManager(): EventsManagerInterface;
```
Returns the custom events manager


```php
public function getMessages( mixed $filter = null ): MessageInterface[];
```
Returns array of validation messages

```php
$robot = new Robots();

$robot->type = "mechanical";
$robot->name = "Astro Boy";
$robot->year = 1952;

if ($robot->save() === false) {
    echo "Umh, We can't store robots right now ";

    $messages = $robot->getMessages();

    foreach ($messages as $message) {
        echo $message;
    }
} else {
    echo "Great, a new robot was saved successfully!";
}
```


```php
public function getModelsManager(): ManagerInterface;
```
Returns the models manager related to the entity instance


```php
public function getModelsMetaData(): MetaDataInterface;
```
{@inheritdoc}


```php
public function getOldSnapshotData(): array;
```
Returns the internal old snapshot data


```php
public function getOperationMade(): int;
```
Returns the type of the latest operation performed by the ORM
Returns one of the OP_* class constants


```php
final public function getReadConnection(): AdapterInterface;
```
Gets the connection used to read data for the model


```php
final public function getReadConnectionService(): string;
```
Returns the DependencyInjection connection service name used to read data
related the model


```php
public function getRelated( string $alias, mixed $arguments = null );
```
Returns related records based on defined relations

@param array arguments
@return \Phalcon\Mvc\Model\Resultset\Simple|Phalcon\Mvc\Model\Resultset\Simple|false


```php
final public function getSchema(): string;
```
Returns schema name where the mapped table is located


```php
public function getSnapshotData(): array;
```
Returns the internal snapshot data


```php
final public function getSource(): string;
```
Returns the table name mapped in the model


```php
public function getTransaction()
```


```php
public function getUpdatedFields(): array;
```
Returns a list of updated values.

```php
$robots = Robots::findFirst();
print_r($robots->getChangedFields()); // []

$robots->deleted = 'Y';

$robots->getChangedFields();
print_r($robots->getChangedFields()); // ["deleted"]
$robots->save();
print_r($robots->getChangedFields()); // []
print_r($robots->getUpdatedFields()); // ["deleted"]
```


```php
final public function getWriteConnection(): AdapterInterface;
```
Gets the connection used to write data to the model


```php
final public function getWriteConnectionService(): string;
```
Returns the DependencyInjection connection service name used to write
data related to the model


```php
public function hasChanged( mixed $fieldName = null, bool $allFields = bool ): bool;
```
Check if a specific attribute has changed
This only works if the model is keeping data snapshots

```php
$robot = new Robots();

$robot->type = "mechanical";
$robot->name = "Astro Boy";
$robot->year = 1952;

$robot->create();

$robot->type = "hydraulic";

$hasChanged = $robot->hasChanged("type"); // returns true
$hasChanged = $robot->hasChanged(["type", "name"]); // returns true
$hasChanged = $robot->hasChanged(["type", "name"], true); // returns false
```

@param string|array fieldName
@param boolean allFields


```php
public function hasSnapshotData(): bool;
```
Checks if the object has internal snapshot data


```php
public function hasUpdated( mixed $fieldName = null, bool $allFields = bool ): bool;
```
Check if a specific attribute was updated
This only works if the model is keeping data snapshots

@param string|array fieldName


```php
public function isRelationshipLoaded( string $relationshipAlias ): bool;
```
Checks if saved related records have already been loaded.

Only returns true if the records were previously fetched
through the model without any additional parameters.

```php
$robot = Robots::findFirst();
var_dump($robot->isRelationshipLoaded('robotsParts')); // false

$robotsParts = $robot->getRobotsParts(['id > 0']);
var_dump($robot->isRelationshipLoaded('robotsParts')); // false

$robotsParts = $robot->getRobotsParts(); // or $robot->robotsParts
var_dump($robot->isRelationshipLoaded('robotsParts')); // true

$robot->robotsParts = [new RobotsParts()];
var_dump($robot->isRelationshipLoaded('robotsParts')); // false
```


```php
public function jsonSerialize(): array;
```
   Serializes the object for json_encode
   
   ```php
   echo json_encode($robot);
   ```
   

```php
public function readAttribute( string $attribute ): mixed | null;
```
Reads an attribute value by its name

```php
echo $robot->readAttribute("name");
```


```php
public function refresh(): ModelInterface;
```
Refreshes the model attributes re-querying the record from the database


```php
public function save(): bool;
```
Inserts or updates a model instance. Returning true on success or false
otherwise.

```php
// Creating a new robot
$robot = new Robots();

$robot->type = "mechanical";
$robot->name = "Astro Boy";
$robot->year = 1952;

$robot->save();

// Updating a robot name
$robot = Robots::findFirst("id = 100");

$robot->name = "Biomass";

$robot->save();
```


```php
public function serialize(): string;
```
Serializes the object ignoring connections, services, related objects or
static properties


```php
final public function setConnectionService( string $connectionService ): ModelInterface;
```
Sets the DependencyInjection connection service name


```php
public function setDirtyState( int $dirtyState ): ModelInterface | bool;
```
Sets the dirty state of the object using one of the DIRTY_STATE_* constants


```php
public function setEventsManager( EventsManagerInterface $eventsManager );
```
Sets a custom events manager


```php
public function setOldSnapshotData( array $data, mixed $columnMap = null );
```
Sets the record's old snapshot data.
This method is used internally to set old snapshot data when the model
was set up to keep snapshot data

@param array data
@param array columnMap


```php
final public function setReadConnectionService( string $connectionService ): ModelInterface;
```
Sets the DependencyInjection connection service name used to read data


```php
public function setSnapshotData( array $data, mixed $columnMap = null ): void;
```
Sets the record's snapshot data.
This method is used internally to set snapshot data when the model was
set up to keep snapshot data

@param array columnMap


```php
public function setTransaction( TransactionInterface $transaction ): ModelInterface;
```
Sets a transaction related to the Model instance

```php
use Phalcon\Mvc\Model\Transaction\Manager as TxManager;
use Phalcon\Mvc\Model\Transaction\Failed as TxFailed;

try {
    $txManager = new TxManager();

    $transaction = $txManager->get();

    $robot = new Robots();

    $robot->setTransaction($transaction);

    $robot->name       = "WALL·E";
    $robot->created_at = date("Y-m-d");

    if ($robot->save() === false) {
        $transaction->rollback("Can't save robot");
    }

    $robotPart = new RobotParts();

    $robotPart->setTransaction($transaction);

    $robotPart->type = "head";

    if ($robotPart->save() === false) {
        $transaction->rollback("Robot part cannot be saved");
    }

    $transaction->commit();
} catch (TxFailed $e) {
    echo "Failed, reason: ", $e->getMessage();
}
```


```php
final public function setWriteConnectionService( string $connectionService ): ModelInterface;
```
Sets the DependencyInjection connection service name used to write data


```php
public function skipOperation( bool $skip ): void;
```
Skips the current operation forcing a success state


```php
public function toArray( mixed $columns = null ): array;
```
Returns the instance as an array representation

```php
print_r(
    $robot->toArray()
);
```

@param array $columns


```php
public function unserialize( mixed $data );
```
Unserializes the object from a serialized string


```php
public function update(): bool;
```
Updates a model instance. If the instance doesn't exist in the
persistence it will throw an exception. Returning true on success or
false otherwise.

```php
// Updating a robot name
$robot = Robots::findFirst("id = 100");

$robot->name = "Biomass";

$robot->update();
```


```php
public function validationHasFailed(): bool;
```
Check whether validation process has generated any messages

```php
use Phalcon\Mvc\Model;
use Phalcon\Validation;
use Phalcon\Validation\Validator\ExclusionIn;

class Subscriptors extends Model
{
    public function validation()
    {
        $validator = new Validation();

        $validator->validate(
            "status",
            new ExclusionIn(
                [
                    "domain" => [
                        "A",
                        "I",
                    ],
                ]
            )
        );

        return $this->validate($validator);
    }
}
```


```php
public function writeAttribute( string $attribute, mixed $value ): void;
```
Writes an attribute value by its name

```php
$robot->writeAttribute("name", "Rosey");
```


```php
protected function _cancelOperation();
```
Cancel the current operation


```php
final protected function _checkForeignKeysRestrict(): bool;
```
Reads "belongs to" relations and check the virtual foreign keys when
inserting or updating records to verify that inserted/updated values are
present in the related entity


```php
final protected function _checkForeignKeysReverseCascade(): bool;
```
Reads both "hasMany" and "hasOne" relations and checks the virtual
foreign keys (cascade) when deleting records


```php
final protected function _checkForeignKeysReverseRestrict(): bool;
```
Reads both "hasMany" and "hasOne" relations and checks the virtual
foreign keys (restrict) when deleting records


```php
protected function _doLowInsert( MetaDataInterface $metaData, AdapterInterface $connection, mixed $table, mixed $identityField ): bool;
```
Sends a pre-build INSERT SQL statement to the relational database system

@param string|array table
@param bool|string identityField


```php
protected function _doLowUpdate( MetaDataInterface $metaData, AdapterInterface $connection, mixed $table ): bool;
```
Sends a pre-build UPDATE SQL statement to the relational database system

@param string|array table


```php
protected function _exists( MetaDataInterface $metaData, AdapterInterface $connection ): bool;
```
Checks whether the current record already exists


```php
protected function _getRelatedRecords( string $modelName, string $method, mixed $arguments );
```
Returns related records defined relations depending on the method name

@param array arguments
@return mixed


```php
final protected function _possibleSetter( string $property, mixed $value ): bool;
```
Check for, and attempt to use, possible setter.


```php
protected function _postSave( bool $success, bool $exists ): bool;
```
Executes internal events after save a record


```php
protected function _postSaveRelatedRecords( AdapterInterface $connection, mixed $related ): bool;
```
Save the related records assigned in the has-one/has-many relations

@param  Phalcon\Mvc\ModelInterface[] related


```php
protected function _preSave( MetaDataInterface $metaData, bool $exists, mixed $identityField ): bool;
```
Executes internal hooks before save a record


```php
protected function _preSaveRelatedRecords( AdapterInterface $connection, mixed $related ): bool;
```
Saves related records that must be stored prior to save the master record

@param \Phalcon\Mvc\ModelInterface[] related


```php
protected function allowEmptyStringValues( array $attributes ): void;
```
Sets a list of attributes that must be skipped from the
generated UPDATE statement

```php
class Robots extends \Phalcon\Mvc\Model
{
    public function initialize()
    {
        $this->allowEmptyStringValues(
            [
                "name",
            ]
        );
    }
}
```


```php
protected function belongsTo( mixed $fields, string $referenceModel, mixed $referencedFields, mixed $options = null ): Relation;
```
Setup a reverse 1-1 or n-1 relation between two models

```php
class RobotsParts extends \Phalcon\Mvc\Model
{
    public function initialize()
    {
        $this->belongsTo(
            "robots_id",
            Robots::class,
            "id"
        );
    }
}
```


```php
protected function hasMany( mixed $fields, string $referenceModel, mixed $referencedFields, mixed $options = null ): Relation;
```
Setup a 1-n relation between two models

```php
class Robots extends \Phalcon\Mvc\Model
{
    public function initialize()
    {
        $this->hasMany(
            "id",
            RobotsParts::class,
            "robots_id"
        );
    }
}
```


```php
protected function hasManyToMany( mixed $fields, string $intermediateModel, mixed $intermediateFields, mixed $intermediateReferencedFields, string $referenceModel, mixed $referencedFields, mixed $options = null ): Relation;
```
Setup an n-n relation between two models, through an intermediate
relation

```php
class Robots extends \Phalcon\Mvc\Model
{
    public function initialize()
    {
        // Setup a many-to-many relation to Parts through RobotsParts
        $this->hasManyToMany(
            "id",
            RobotsParts::class,
            "robots_id",
            "parts_id",
            Parts::class,
            "id",
        );
    }
}
```

@param    string|array fields
@param    string|array intermediateFields
@param    string|array intermediateReferencedFields
@param    string|array referencedFields
@param    array options


```php
protected function hasOne( mixed $fields, string $referenceModel, mixed $referencedFields, mixed $options = null ): Relation;
```
Setup a 1-1 relation between two models

```php
class Robots extends \Phalcon\Mvc\Model
{
    public function initialize()
    {
        $this->hasOne(
            "id",
            RobotsDescription::class,
            "robots_id"
        );
    }
}
```


```php
protected function keepSnapshots( bool $keepSnapshot ): void;
```
Sets if the model must keep the original record snapshot in memory

```php
use Phalcon\Mvc\Model;

class Robots extends Model
{
    public function initialize()
    {
        $this->keepSnapshots(true);
    }
}
```


```php
final protected function setSchema( string $schema ): ModelInterface;
```
Sets schema name where the mapped table is located


```php
final protected function setSource( string $source ): ModelInterface;
```
Sets the table name to which model should be mapped


```php
protected function skipAttributes( array $attributes );
```
Sets a list of attributes that must be skipped from the
generated INSERT/UPDATE statement

```php
class Robots extends \Phalcon\Mvc\Model
{
    public function initialize()
    {
        $this->skipAttributes(
            [
                "price",
            ]
        );
    }
}
```


```php
protected function skipAttributesOnCreate( array $attributes ): void;
```
Sets a list of attributes that must be skipped from the
generated INSERT statement

```php
class Robots extends \Phalcon\Mvc\Model
{
    public function initialize()
    {
        $this->skipAttributesOnCreate(
            [
                "created_at",
            ]
        );
    }
}
```


```php
protected function skipAttributesOnUpdate( array $attributes ): void;
```
Sets a list of attributes that must be skipped from the
generated UPDATE statement

```php
class Robots extends \Phalcon\Mvc\Model
{
    public function initialize()
    {
        $this->skipAttributesOnUpdate(
            [
                "modified_in",
            ]
        );
    }
}
```


```php
protected function useDynamicUpdate( bool $dynamicUpdate ): void;
```
Sets if a model must use dynamic update instead of the all-field update

```php
use Phalcon\Mvc\Model;

class Robots extends Model
{
    public function initialize()
    {
        $this->useDynamicUpdate(true);
    }
}
```


```php
protected function validate( ValidationInterface $validator ): bool;
```
Executes validators on every validation call

```php
use Phalcon\Mvc\Model;
use Phalcon\Validation;
use Phalcon\Validation\Validator\ExclusionIn;

class Subscriptors extends Model
{
    public function validation()
    {
        $validator = new Validation();

        $validator->add(
            "status",
            new ExclusionIn(
                [
                    "domain" => [
                        "A",
                        "I",
                    ],
                ]
            )
        );

        return $this->validate($validator);
    }
}
```



        
<h1 id="mvc-model-behavior">Abstract Class Phalcon\Mvc\Model\Behavior</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/model/behavior.zep)

| Namespace  | Phalcon\Mvc\Model |
| Uses       | Phalcon\Mvc\ModelInterface, Phalcon\Mvc\Model\BehaviorInterface |
| Implements | BehaviorInterface |

Phalcon\Mvc\Model\Behavior

This is an optional base class for ORM behaviors


## Properties
```php
/**
 * @var array
 */
protected options;

```

## Methods
```php
public function __construct( array $options = [] ): void;
```
Phalcon\Mvc\Model\Behavior


```php
public function missingMethod( ModelInterface $model, string $method, array $arguments = [] );
```
Acts as fallbacks when a missing method is called on the model


```php
public function notify( string $type, ModelInterface $model );
```
This method receives the notifications from the EventsManager


```php
protected function getOptions( string $eventName = null );
```
Returns the behavior options related to an event

@return array


```php
protected function mustTakeAction( string $eventName ): bool;
```
Checks whether the behavior must take action on certain event



        
<h1 id="mvc-model-behavior-softdelete">Class Phalcon\Mvc\Model\Behavior\SoftDelete</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/model/behavior/softdelete.zep)

| Namespace  | Phalcon\Mvc\Model\Behavior |
| Uses       | Phalcon\Mvc\ModelInterface, Phalcon\Mvc\Model\Behavior, Phalcon\Mvc\Model\Exception |
| Extends    | Behavior |

Phalcon\Mvc\Model\Behavior\SoftDelete

Instead of permanently delete a record it marks the record as deleted
changing the value of a flag column


## Methods
```php
public function notify( string $type, ModelInterface $model );
```
Listens for notifications from the models manager



        
<h1 id="mvc-model-behavior-timestampable">Class Phalcon\Mvc\Model\Behavior\Timestampable</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/model/behavior/timestampable.zep)

| Namespace  | Phalcon\Mvc\Model\Behavior |
| Uses       | Closure, Phalcon\Mvc\ModelInterface, Phalcon\Mvc\Model\Behavior, Phalcon\Mvc\Model\Exception |
| Extends    | Behavior |

Phalcon\Mvc\Model\Behavior\Timestampable

Allows to automatically update a model’s attribute saving the datetime when a
record is created or updated


## Methods
```php
public function notify( string $type, ModelInterface $model );
```
Listens for notifications from the models manager



        
<h1 id="mvc-model-behaviorinterface">Interface Phalcon\Mvc\Model\BehaviorInterface</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/model/behaviorinterface.zep)

| Namespace  | Phalcon\Mvc\Model |
| Uses       | Phalcon\Mvc\ModelInterface |

Phalcon\Mvc\Model\BehaviorInterface

Interface for Phalcon\Mvc\Model\Behavior


## Methods
```php
public function missingMethod( ModelInterface $model, string $method, array $arguments = [] );
```
Calls a method when it's missing in the model


```php
public function notify( string $type, ModelInterface $model );
```
This method receives the notifications from the EventsManager



        
<h1 id="mvc-model-binder">Class Phalcon\Mvc\Model\Binder</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/model/binder.zep)

| Namespace  | Phalcon\Mvc\Model |
| Uses       | Closure, Phalcon\Mvc\Controller\BindModelInterface, Phalcon\Mvc\Model\Binder\BindableInterface, Phalcon\Cache\Adapter\AdapterInterface, ReflectionFunction, ReflectionMethod |
| Implements | BinderInterface |

Phalcon\Mvc\Model\Binding

This is an class for binding models into params for handler


## Properties
```php
/**
 * Array for storing active bound models
 *
 * @var array
 */
protected boundModels;

/**
 * Cache object used for caching parameters for model binding
 */
protected cache;

/**
 * Internal cache for caching parameters for model binding during request
 */
protected internalCache;

/**
 * Array for original values
 */
protected originalValues;

```

## Methods
```php
public function __construct( AdapterInterface $cache = null ): void;
```
Phalcon\Mvc\Model\Binder constructor


```php
public function bindToHandler( object $handler, array $params, string $cacheKey, string $methodName = null ): array;
```
Bind models into params in proper handler


```php
public function getBoundModels(): array
```


```php
public function getCache(): AdapterInterface;
```
Sets cache instance


```php
public function getOriginalValues()
```


```php
public function setCache( AdapterInterface $cache ): BinderInterface;
```
Gets cache instance


```php
protected function findBoundModel( mixed $paramValue, string $className ): object | bool;
```
Find the model by param value.


```php
protected function getParamsFromCache( string $cacheKey ): array | null;
```
Get params classes from cache by key


```php
protected function getParamsFromReflection( object $handler, array $params, string $cacheKey, string $methodName ): array;
```
Get modified params for handler using reflection



        
<h1 id="mvc-model-binder-bindableinterface">Interface Phalcon\Mvc\Model\Binder\BindableInterface</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/model/binder/bindableinterface.zep)

| Namespace  | Phalcon\Mvc\Model\Binder |

Phalcon\Mvc\Model\Binder\BindableInterface

Interface for bindable classes


## Methods
```php
public function getModelName(): string | array;
```
Return the model name or models names and parameters keys associated with
this class



        
<h1 id="mvc-model-binderinterface">Interface Phalcon\Mvc\Model\BinderInterface</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/model/binderinterface.zep)

| Namespace  | Phalcon\Mvc\Model |
| Uses       | Phalcon\Cache\Adapter\AdapterInterface |

Phalcon\Mvc\Model\BinderInterface

Interface for Phalcon\Mvc\Model\Binder


## Methods
```php
public function bindToHandler( object $handler, array $params, string $cacheKey, string $methodName = null ): array;
```
Bind models into params in proper handler


```php
public function getBoundModels(): array;
```
Gets active bound models


```php
public function getCache(): AdapterInterface;
```
Gets cache instance


```php
public function setCache( AdapterInterface $cache ): BinderInterface;
```
Sets cache instance



        
<h1 id="mvc-model-criteria">Class Phalcon\Mvc\Model\Criteria</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/model/criteria.zep)

| Namespace  | Phalcon\Mvc\Model |
| Uses       | Phalcon\Di, Phalcon\Db\Column, Phalcon\Di\DiInterface, Phalcon\Mvc\Model\Exception, Phalcon\Di\InjectionAwareInterface, Phalcon\Mvc\Model\CriteriaInterface, Phalcon\Mvc\Model\ResultsetInterface, Phalcon\Mvc\Model\Query\BuilderInterface |
| Implements | CriteriaInterface, InjectionAwareInterface |

Phalcon\Mvc\Model\Criteria

This class is used to build the array parameter required by
Phalcon\Mvc\Model::find() and Phalcon\Mvc\Model::findFirst() using an
object-oriented interface.

```php
$robots = Robots::query()
    ->where("type = :type:")
    ->andWhere("year < 2000")
    ->bind(["type" => "mechanical"])
    ->limit(5, 10)
    ->orderBy("name")
    ->execute();
```


## Properties
```php
//
protected bindParams;

//
protected bindTypes;

//
protected hiddenParamNumber = 0;

//
protected model;

//
protected params;

```

## Methods
```php
public function andWhere( string $conditions, mixed $bindParams = null, mixed $bindTypes = null ): CriteriaInterface;
```
Appends a condition to the current conditions using an AND operator


```php
public function betweenWhere( string $expr, mixed $minimum, mixed $maximum ): CriteriaInterface;
```
Appends a BETWEEN condition to the current conditions

```php
$criteria->betweenWhere("price", 100.25, 200.50);
```


```php
public function bind( array $bindParams, bool $merge = bool ): CriteriaInterface;
```
Sets the bound parameters in the criteria
This method replaces all previously set bound parameters


```php
public function bindTypes( array $bindTypes ): CriteriaInterface;
```
Sets the bind types in the criteria
This method replaces all previously set bound parameters


```php
public function cache( array $cache ): CriteriaInterface;
```
Sets the cache options in the criteria
This method replaces all previously set cache options


```php
public function columns( mixed $columns ): CriteriaInterface;
```
Sets the columns to be queried

```php
$criteria->columns(
    [
        "id",
        "name",
    ]
);
```

@param string|array columns


```php
public function conditions( string $conditions ): CriteriaInterface;
```
Adds the conditions parameter to the criteria


```php
public function createBuilder(): BuilderInterface;
```
Creates a query builder from criteria.

```php
$builder = Robots::query()
    ->where("type = :type:")
    ->bind(["type" => "mechanical"])
    ->createBuilder();
```


```php
public function distinct( mixed $distinct ): CriteriaInterface;
```
Sets SELECT DISTINCT / SELECT ALL flag


```php
public function execute(): ResultsetInterface;
```
Executes a find using the parameters built with the criteria


```php
public function forUpdate( bool $forUpdate = bool ): CriteriaInterface;
```
Adds the "for_update" parameter to the criteria


```php
public function getColumns(): string | null;
```
Returns the columns to be queried

@return string|array|null


```php
public function getConditions(): string | null;
```
Returns the conditions parameter in the criteria


```php
public function getDI(): DiInterface;
```
Returns the DependencyInjector container


```php
public function getGroupBy();
```
Returns the group clause in the criteria


```php
public function getHaving();
```
Returns the having clause in the criteria


```php
public function getLimit(): string | null;
```
Returns the limit parameter in the criteria, which will be an integer if
limit was set without an offset, an array with 'number' and 'offset' keys
if an offset was set with the limit, or null if limit has not been set.

@return int|array|null


```php
public function getModelName(): string;
```
Returns an internal model name on which the criteria will be applied


```php
public function getOrderBy(): string | null;
```
Returns the order clause in the criteria


```php
public function getParams(): array;
```
Returns all the parameters defined in the criteria


```php
public function getWhere(): string | null;
```
Returns the conditions parameter in the criteria


```php
public function groupBy( mixed $group ): CriteriaInterface;
```
Adds the group-by clause to the criteria


```php
public function having( mixed $having ): CriteriaInterface;
```
Adds the having clause to the criteria


```php
public function inWhere( string $expr, array $values ): CriteriaInterface;
```
Appends an IN condition to the current conditions

```php
$criteria->inWhere("id", [1, 2, 3]);
```


```php
public function innerJoin( string $model, mixed $conditions = null, mixed $alias = null ): CriteriaInterface;
```
Adds an INNER join to the query

```php
$criteria->innerJoin(
    Robots::class
);

$criteria->innerJoin(
    Robots::class,
    "r.id = RobotsParts.robots_id"
);

$criteria->innerJoin(
    Robots::class,
    "r.id = RobotsParts.robots_id",
    "r"
);
```


```php
public function join( string $model, mixed $conditions = null, mixed $alias = null, mixed $type = null ): CriteriaInterface;
```
Adds an INNER join to the query

```php
$criteria->join(
    Robots::class
);

$criteria->join(
    Robots::class,
    "r.id = RobotsParts.robots_id"
);

$criteria->join(
    Robots::class,
    "r.id = RobotsParts.robots_id",
    "r"
);

$criteria->join(
    Robots::class,
    "r.id = RobotsParts.robots_id",
    "r",
    "LEFT"
);
```


```php
public function leftJoin( string $model, mixed $conditions = null, mixed $alias = null ): CriteriaInterface;
```
Adds a LEFT join to the query

```php
$criteria->leftJoin(
    Robots::class,
    "r.id = RobotsParts.robots_id",
    "r"
);
```


```php
public function limit( int $limit, int $offset = int ): CriteriaInterface;
```
Adds the limit parameter to the criteria.

```php
$criteria->limit(100);
$criteria->limit(100, 200);
$criteria->limit("100", "200");
```


```php
public function notBetweenWhere( string $expr, mixed $minimum, mixed $maximum ): CriteriaInterface;
```
Appends a NOT BETWEEN condition to the current conditions

```php
$criteria->notBetweenWhere("price", 100.25, 200.50);
```


```php
public function notInWhere( string $expr, array $values ): CriteriaInterface;
```
Appends a NOT IN condition to the current conditions

```php
$criteria->notInWhere("id", [1, 2, 3]);
```


```php
public function orWhere( string $conditions, mixed $bindParams = null, mixed $bindTypes = null ): CriteriaInterface;
```
Appends a condition to the current conditions using an OR operator


```php
public function orderBy( string $orderColumns ): CriteriaInterface;
```
Adds the order-by clause to the criteria


```php
public function rightJoin( string $model, mixed $conditions = null, mixed $alias = null ): CriteriaInterface;
```
Adds a RIGHT join to the query

```php
$criteria->rightJoin(
    Robots::class,
    "r.id = RobotsParts.robots_id",
    "r"
);
```


```php
public function setDI( DiInterface $container ): void;
```
Sets the DependencyInjector container


```php
public function setModelName( string $modelName ): CriteriaInterface;
```
Set a model on which the query will be executed


```php
public function sharedLock( bool $sharedLock = bool ): CriteriaInterface;
```
Adds the "shared_lock" parameter to the criteria


```php
public function where( string $conditions, mixed $bindParams = null, mixed $bindTypes = null ): CriteriaInterface;
```
Sets the conditions parameter in the criteria



        
<h1 id="mvc-model-criteriainterface">Interface Phalcon\Mvc\Model\CriteriaInterface</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/model/criteriainterface.zep)

| Namespace  | Phalcon\Mvc\Model |
| Uses       | Phalcon\Di\DiInterface |

Phalcon\Mvc\Model\CriteriaInterface

Interface for Phalcon\Mvc\Model\Criteria


## Methods
```php
public function andWhere( string $conditions, mixed $bindParams = null, mixed $bindTypes = null ): CriteriaInterface;
```
Appends a condition to the current conditions using an AND operator

@param array bindParams
@param array bindTypes


```php
public function betweenWhere( string $expr, mixed $minimum, mixed $maximum ): CriteriaInterface;
```
Appends a BETWEEN condition to the current conditions

```php
$criteria->betweenWhere("price", 100.25, 200.50);
```

@param mixed minimum
@param mixed maximum


```php
public function bind( array $bindParams ): CriteriaInterface;
```
Sets the bound parameters in the criteria
This method replaces all previously set bound parameters


```php
public function bindTypes( array $bindTypes ): CriteriaInterface;
```
Sets the bind types in the criteria
This method replaces all previously set bound parameters


```php
public function cache( array $cache ): CriteriaInterface;
```
Sets the cache options in the criteria
This method replaces all previously set cache options


```php
public function conditions( string $conditions ): CriteriaInterface;
```
Adds the conditions parameter to the criteria


```php
public function distinct( mixed $distinct ): CriteriaInterface;
```
Sets SELECT DISTINCT / SELECT ALL flag


```php
public function execute(): ResultsetInterface;
```
Executes a find using the parameters built with the criteria


```php
public function forUpdate( bool $forUpdate = bool ): CriteriaInterface;
```
Sets the "for_update" parameter to the criteria


```php
public function getColumns(): string | null;
```
Returns the columns to be queried

@return string|array|null


```php
public function getConditions(): string | null;
```
Returns the conditions parameter in the criteria


```php
public function getGroupBy();
```
Returns the group clause in the criteria


```php
public function getHaving();
```
Returns the having clause in the criteria


```php
public function getLimit(): string | null;
```
Returns the limit parameter in the criteria, which will be an integer if
limit was set without an offset, an array with 'number' and 'offset' keys
if an offset was set with the limit, or null if limit has not been set.


```php
public function getModelName(): string;
```
Returns an internal model name on which the criteria will be applied


```php
public function getOrderBy(): string | null;
```
Returns the order parameter in the criteria


```php
public function getParams(): array;
```
Returns all the parameters defined in the criteria


```php
public function getWhere(): string | null;
```
Returns the conditions parameter in the criteria


```php
public function groupBy( mixed $group ): CriteriaInterface;
```
Adds the group-by clause to the criteria


```php
public function having( mixed $having ): CriteriaInterface;
```
Adds the having clause to the criteria


```php
public function inWhere( string $expr, array $values ): CriteriaInterface;
```
Appends an IN condition to the current conditions

```php
$criteria->inWhere("id", [1, 2, 3]);
```


```php
public function innerJoin( string $model, mixed $conditions = null, mixed $alias = null ): CriteriaInterface;
```
Adds an INNER join to the query

```php
$criteria->innerJoin(
    Robots::class
);

$criteria->innerJoin(
    Robots::class,
    "r.id = RobotsParts.robots_id"
);

$criteria->innerJoin(
    Robots::class,
    "r.id = RobotsParts.robots_id",
    "r"
);
```


```php
public function leftJoin( string $model, mixed $conditions = null, mixed $alias = null ): CriteriaInterface;
```
Adds a LEFT join to the query

```php
$criteria->leftJoin(
    Robots::class,
    "r.id = RobotsParts.robots_id",
    "r"
);
```


```php
public function limit( int $limit, int $offset = int ): CriteriaInterface;
```
Sets the limit parameter to the criteria


```php
public function notBetweenWhere( string $expr, mixed $minimum, mixed $maximum ): CriteriaInterface;
```
Appends a NOT BETWEEN condition to the current conditions

```php
$criteria->notBetweenWhere("price", 100.25, 200.50);
```

@param mixed minimum
@param mixed maximum


```php
public function notInWhere( string $expr, array $values ): CriteriaInterface;
```
Appends a NOT IN condition to the current conditions

```php
$criteria->notInWhere("id", [1, 2, 3]);
```


```php
public function orWhere( string $conditions, mixed $bindParams = null, mixed $bindTypes = null ): CriteriaInterface;
```
Appends a condition to the current conditions using an OR operator

@param array bindParams
@param array bindTypes


```php
public function orderBy( string $orderColumns ): CriteriaInterface;
```
Adds the order-by parameter to the criteria


```php
public function rightJoin( string $model, mixed $conditions = null, mixed $alias = null ): CriteriaInterface;
```
Adds a RIGHT join to the query

```php
$criteria->rightJoin(
    Robots::class,
    "r.id = RobotsParts.robots_id",
    "r"
);
```


```php
public function setModelName( string $modelName ): CriteriaInterface;
```
Set a model on which the query will be executed


```php
public function sharedLock( bool $sharedLock = bool ): CriteriaInterface;
```
Sets the "shared_lock" parameter to the criteria


```php
public function where( string $conditions ): CriteriaInterface;
```
Sets the conditions parameter in the criteria



        
<h1 id="mvc-model-exception">Class Phalcon\Mvc\Model\Exception</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/model/exception.zep)

| Namespace  | Phalcon\Mvc\Model |
| Extends    | \Phalcon\Exception |

Phalcon\Mvc\Model\Exception

Exceptions thrown in Phalcon\Mvc\Model\* classes will use this class


        
<h1 id="mvc-model-manager">Class Phalcon\Mvc\Model\Manager</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/model/manager.zep)

| Namespace  | Phalcon\Mvc\Model |
| Uses       | Phalcon\Di\DiInterface, Phalcon\Mvc\Model\Relation, Phalcon\Mvc\Model\RelationInterface, Phalcon\Mvc\Model\Exception, Phalcon\Mvc\ModelInterface, Phalcon\Db\Adapter\AdapterInterface, Phalcon\Mvc\Model\ResultsetInterface, Phalcon\Mvc\Model\ManagerInterface, Phalcon\Di\InjectionAwareInterface, Phalcon\Events\EventsAwareInterface, Phalcon\Mvc\Model\Query, Phalcon\Mvc\Model\QueryInterface, Phalcon\Mvc\Model\Query\Builder, Phalcon\Mvc\Model\Query\BuilderInterface, Phalcon\Mvc\Model\BehaviorInterface, Phalcon\Events\ManagerInterface |
| Implements | ManagerInterface, InjectionAwareInterface, EventsAwareInterface |

Phalcon\Mvc\Model\Manager

This components controls the initialization of models, keeping record of
relations between the different models of the application.

A ModelsManager is injected to a model via a Dependency Injector/Services
Container such as Phalcon\Di.

```php
use Phalcon\Di;
use Phalcon\Mvc\Model\Manager as ModelsManager;

$di = new Di();

$di->set(
    "modelsManager",
    function() {
        return new ModelsManager();
    }
);

$robot = new Robots($di);
```


## Properties
```php
//
protected aliases;

/**
 * Models' behaviors
 */
protected behaviors;

/**
 * Belongs to relations
 */
protected belongsTo;

/**
 * All the relationships by model
 */
protected belongsToSingle;

//
protected container;

//
protected customEventsManager;

/**
 * Does the model use dynamic update, instead of updating all rows?
 */
protected dynamicUpdate;

//
protected eventsManager;

/**
 * Has many relations
 */
protected hasMany;

/**
 * Has many relations by model
 */
protected hasManySingle;

/**
 * Has many-Through relations
 */
protected hasManyToMany;

/**
 * Has many-Through relations by model
 */
protected hasManyToManySingle;

/**
 * Has one relations
 */
protected hasOne;

/**
 * Has one relations by model
 */
protected hasOneSingle;

/**
 * Mark initialized models
 */
protected initialized;

//
protected keepSnapshots;

/**
 * Last model initialized
 */
protected lastInitialized;

/**
 * Last query created/executed
 */
protected lastQuery;

//
protected modelVisibility;

//
protected prefix = ;

//
protected readConnectionServices;

//
protected sources;

//
protected schemas;

//
protected writeConnectionServices;

/**
 * Stores a list of reusable instances
 */
protected reusable;

```

## Methods
```php
public function __destruct();
```
Destroys the current PHQL cache


```php
public function _getConnectionService( ModelInterface $model, mixed $connectionServices ): string;
```
Returns the connection service name used to read or write data related to
a model depending on the connection services


```php
public function addBehavior( ModelInterface $model, BehaviorInterface $behavior ): void;
```
Binds a behavior to a model


```php
public function addBelongsTo( ModelInterface $model, mixed $fields, string $referencedModel, mixed $referencedFields, mixed $options = null ): RelationInterface;
```
Setup a relation reverse many to one between two models

@param    array options


```php
public function addHasMany( ModelInterface $model, mixed $fields, string $referencedModel, mixed $referencedFields, mixed $options = null ): RelationInterface;
```
Setup a relation 1-n between two models

@param    mixed referencedFields
@param    array options


```php
public function addHasManyToMany( ModelInterface $model, mixed $fields, string $intermediateModel, mixed $intermediateFields, mixed $intermediateReferencedFields, string $referencedModel, mixed $referencedFields, mixed $options = null ): RelationInterface;
```
Setups a relation n-m between two models

@param    string fields
@param    string intermediateFields
@param    string intermediateReferencedFields
@param    string referencedFields
@param   array options


```php
public function addHasOne( ModelInterface $model, mixed $fields, string $referencedModel, mixed $referencedFields, mixed $options = null ): RelationInterface;
```
Setup a 1-1 relation between two models

@param array options


```php
public function clearReusableObjects(): void;
```
Clears the internal reusable list


```php
public function createBuilder( mixed $params = null ): BuilderInterface;
```
Creates a Phalcon\Mvc\Model\Query\Builder


```php
public function createQuery( string $phql ): QueryInterface;
```
Creates a Phalcon\Mvc\Model\Query without execute it


```php
public function executeQuery( string $phql, mixed $placeholders = null, mixed $types = null ): QueryInterface;
```
Creates a Phalcon\Mvc\Model\Query and execute it


```php
public function existsBelongsTo( string $modelName, string $modelRelation ): bool;
```
Checks whether a model has a belongsTo relation with another model


```php
public function existsHasMany( string $modelName, string $modelRelation ): bool;
```
Checks whether a model has a hasMany relation with another model


```php
public function existsHasManyToMany( string $modelName, string $modelRelation ): bool;
```
Checks whether a model has a hasManyToMany relation with another model


```php
public function existsHasOne( string $modelName, string $modelRelation ): bool;
```
Checks whether a model has a hasOne relation with another model


```php
public function getBelongsTo( ModelInterface $model ): RelationInterface[] | array;
```
Gets all the belongsTo relations defined in a model

```php
$relations = $modelsManager->getBelongsTo(
    new Robots()
);
```


```php
public function getBelongsToRecords( string $modelName, string $modelRelation, ModelInterface $record, mixed $parameters = null, string $method = null ): ResultsetInterface | bool;
```
Gets belongsTo related records from a model


```php
public function getCustomEventsManager( ModelInterface $model ): EventsManagerInterface | bool;
```
Returns a custom events manager related to a model


```php
public function getDI(): DiInterface;
```
Returns the DependencyInjector container


```php
public function getEventsManager(): EventsManagerInterface;
```
Returns the internal event manager


```php
public function getHasMany( ModelInterface $model ): RelationInterface[] | array;
```
Gets hasMany relations defined on a model


```php
public function getHasManyRecords( string $modelName, string $modelRelation, ModelInterface $record, mixed $parameters = null, string $method = null ): ResultsetInterface | bool;
```
Gets hasMany related records from a model


```php
public function getHasManyToMany( ModelInterface $model ): RelationInterface[] | array;
```
Gets hasManyToMany relations defined on a model


```php
public function getHasOne( ModelInterface $model ): array;
```
Gets hasOne relations defined on a model


```php
public function getHasOneAndHasMany( ModelInterface $model ): RelationInterface[];
```
Gets hasOne relations defined on a model


```php
public function getHasOneRecords( string $modelName, string $modelRelation, ModelInterface $record, mixed $parameters = null, string $method = null ): ModelInterface | bool;
```
Gets belongsTo related records from a model


```php
public function getLastInitialized(): ModelInterface;
```
Get last initialized model


```php
public function getLastQuery(): QueryInterface;
```
Returns the last query created or executed in the models manager


```php
public function getModelPrefix(): string;
```
Returns the prefix for all model sources.


```php
public function getModelSchema( ModelInterface $model ): string;
```
Returns the mapped schema for a model


```php
public function getModelSource( ModelInterface $model ): string;
```
Returns the mapped source for a model


```php
public function getReadConnection( ModelInterface $model ): AdapterInterface;
```
Returns the connection to read data related to a model


```php
public function getReadConnectionService( ModelInterface $model ): string;
```
Returns the connection service name used to read data related to a model


```php
public function getRelationByAlias( string $modelName, string $alias ): RelationInterface | bool;
```
Returns a relation by its alias


```php
public function getRelationRecords( RelationInterface $relation, ModelInterface $record, mixed $parameters = null, string $method = null );
```
Helper method to query records based on a relation definition

@return \Phalcon\Mvc\Model\Resultset\Simple|Phalcon\Mvc\Model\Resultset\Simple|int|false


```php
public function getRelations( string $modelName ): RelationInterface[];
```
Query all the relationships defined on a model


```php
public function getRelationsBetween( string $first, string $second ): RelationInterface[] | bool;
```
Query the first relationship defined between two models


```php
public function getReusableRecords( string $modelName, string $key );
```
Returns a reusable object from the internal list


```php
public function getWriteConnection( ModelInterface $model ): AdapterInterface;
```
Returns the connection to write data related to a model


```php
public function getWriteConnectionService( ModelInterface $model ): string;
```
Returns the connection service name used to write data related to a model


```php
public function initialize( ModelInterface $model ): bool;
```
Initializes a model in the model manager


```php
public function isInitialized( string $className ): bool;
```
Check whether a model is already initialized


```php
public function isKeepingSnapshots( ModelInterface $model ): bool;
```
Checks if a model is keeping snapshots for the queried records


```php
public function isUsingDynamicUpdate( ModelInterface $model ): bool;
```
Checks if a model is using dynamic update instead of all-field update


```php
final public function isVisibleModelProperty( ModelInterface $model, string $property ): bool;
```
Check whether a model property is declared as public.

```php
$isPublic = $manager->isVisibleModelProperty(
    new Robots(),
    "name"
);
```


```php
public function keepSnapshots( ModelInterface $model, bool $keepSnapshots ): void;
```
Sets if a model must keep snapshots


```php
public function load( string $modelName ): ModelInterface;
```
Loads a model throwing an exception if it doesn't exist


```php
public function missingMethod( ModelInterface $model, string $eventName, mixed $data );
```
Dispatch an event to the listeners and behaviors
This method expects that the endpoint listeners/behaviors returns true
meaning that a least one was implemented


```php
public function notifyEvent( string $eventName, ModelInterface $model );
```
Receives events generated in the models and dispatches them to an
events-manager if available. Notify the behaviors that are listening in
the model


```php
public function setConnectionService( ModelInterface $model, string $connectionService ): void;
```
Sets both write and read connection service for a model


```php
public function setCustomEventsManager( ModelInterface $model, EventsManagerInterface $eventsManager ): void;
```
Sets a custom events manager for a specific model


```php
public function setDI( DiInterface $container ): void;
```
Sets the DependencyInjector container


```php
public function setEventsManager( EventsManagerInterface $eventsManager ): ManagerInterface;
```
Sets a global events manager


```php
public function setModelPrefix( string $prefix ): void;
```
Sets the prefix for all model sources.

```php
use Phalcon\Mvc\Model\Manager;

$di->set(
    "modelsManager",
    function () {
        $modelsManager = new Manager();

        $modelsManager->setModelPrefix("wp_");

        return $modelsManager;
    }
);

$robots = new Robots();

echo $robots->getSource(); // wp_robots
```


```php
public function setModelSchema( ModelInterface $model, string $schema ): void;
```
Sets the mapped schema for a model


```php
public function setModelSource( ModelInterface $model, string $source ): void;
```
Sets the mapped source for a model


```php
public function setReadConnectionService( ModelInterface $model, string $connectionService ): void;
```
Sets read connection service for a model


```php
public function setReusableRecords( string $modelName, string $key, mixed $records ): void;
```
Stores a reusable record in the internal list


```php
public function setWriteConnectionService( ModelInterface $model, string $connectionService ): void;
```
Sets write connection service for a model


```php
public function useDynamicUpdate( ModelInterface $model, bool $dynamicUpdate ): void;
```
Sets if a model must use dynamic update instead of the all-field update


```php
protected function _getConnection( ModelInterface $model, mixed $connectionServices ): AdapterInterface;
```
Returns the connection to read or write data related to a model depending on the connection services.


```php
final protected function _mergeFindParameters( mixed $findParamsOne, mixed $findParamsTwo ): array;
```
Merge two arrays of find parameters



        
<h1 id="mvc-model-managerinterface">Interface Phalcon\Mvc\Model\ManagerInterface</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/model/managerinterface.zep)

| Namespace  | Phalcon\Mvc\Model |
| Uses       | Phalcon\Db\Adapter\AdapterInterface, Phalcon\Mvc\ModelInterface, Phalcon\Mvc\Model\BehaviorInterface, Phalcon\Mvc\Model\RelationInterface, Phalcon\Mvc\Model\Query\BuilderInterface, Phalcon\Mvc\Model\QueryInterface |

Phalcon\Mvc\Model\ManagerInterface

Interface for Phalcon\Mvc\Model\Manager


## Methods
```php
public function addBehavior( ModelInterface $model, BehaviorInterface $behavior ): void;
```
Binds a behavior to a model


```php
public function addBelongsTo( ModelInterface $model, mixed $fields, string $referencedModel, mixed $referencedFields, mixed $options = null ): RelationInterface;
```
Setup a relation reverse 1-1  between two models

@param    mixed  fields
@param    mixed  referencedFields
@param    array  options


```php
public function addHasMany( ModelInterface $model, mixed $fields, string $referencedModel, mixed $referencedFields, mixed $options = null ): RelationInterface;
```
Setup a relation 1-n between two models

@param    mixed  fields
@param    mixed  referencedFields
@param    array  options


```php
public function addHasManyToMany( ModelInterface $model, mixed $fields, string $intermediateModel, mixed $intermediateFields, mixed $intermediateReferencedFields, string $referencedModel, mixed $referencedFields, mixed $options = null ): RelationInterface;
```
Setups a relation n-m between two models

@param    string fields
@param    string intermediateFields
@param    string intermediateReferencedFields
@param    string referencedFields
@param   array options


```php
public function addHasOne( ModelInterface $model, mixed $fields, string $referencedModel, mixed $referencedFields, mixed $options = null ): RelationInterface;
```
Setup a 1-1 relation between two models

@param    mixed  fields
@param    mixed  referencedFields
@param    array  options


```php
public function createBuilder( mixed $params = null ): BuilderInterface;
```
Creates a Phalcon\Mvc\Model\Query\Builder

@param string $params


```php
public function createQuery( string $phql ): QueryInterface;
```
Creates a Phalcon\Mvc\Model\Query without execute it


```php
public function executeQuery( string $phql, mixed $placeholders = null ): QueryInterface;
```
Creates a Phalcon\Mvc\Model\Query and execute it

@param array $placeholders


```php
public function existsBelongsTo( string $modelName, string $modelRelation ): bool;
```
Checks whether a model has a belongsTo relation with another model


```php
public function existsHasMany( string $modelName, string $modelRelation ): bool;
```
Checks whether a model has a hasMany relation with another model


```php
public function existsHasManyToMany( string $modelName, string $modelRelation ): bool;
```
Checks whether a model has a hasManyToMany relation with another model


```php
public function existsHasOne( string $modelName, string $modelRelation ): bool;
```
Checks whether a model has a hasOne relation with another model


```php
public function getBelongsTo( ModelInterface $model ): RelationInterface[] | array;
```
Gets belongsTo relations defined on a model


```php
public function getBelongsToRecords( string $modelName, string $modelRelation, ModelInterface $record, mixed $parameters = null, string $method = null ): ResultsetInterface | bool;
```
Gets belongsTo related records from a model

@param string            $modelName
@param string            $modelRelation
@param array|string|null $parameters
@param ModelInterface    $record
@param string|null       $method


```php
public function getHasMany( ModelInterface $model ): RelationInterface[] | array;
```
Gets hasMany relations defined on a model


```php
public function getHasManyRecords( string $modelName, string $modelRelation, ModelInterface $record, mixed $parameters = null, string $method = null ): ResultsetInterface | bool;
```
Gets hasMany related records from a model

@param string            $modelName
@param string            $modelRelation
@param array|string|null $parameters
@param ModelInterface    $record
@param string|null       $method


```php
public function getHasManyToMany( ModelInterface $model ): RelationInterface[] | array;
```
Gets hasManyToMany relations defined on a model


```php
public function getHasOne( ModelInterface $model ): RelationInterface[] | array;
```
Gets hasOne relations defined on a model


```php
public function getHasOneAndHasMany( ModelInterface $model ): RelationInterface[];
```
Gets hasOne relations defined on a model


```php
public function getHasOneRecords( string $modelName, string $modelRelation, ModelInterface $record, mixed $parameters = null, string $method = null ): ModelInterface | bool;
```
Gets belongsTo related records from a model

@param string            $modelName
@param string            $modelRelation
@param array|string|null $parameters
@param ModelInterface    $record
@param string|null       $method


```php
public function getLastInitialized(): ModelInterface;
```
Get last initialized model


```php
public function getLastQuery(): QueryInterface;
```
Returns the last query created or executed in the models manager


```php
public function getModelSchema( ModelInterface $model ): string;
```
Returns the mapped schema for a model


```php
public function getModelSource( ModelInterface $model ): string;
```
Returns the mapped source for a model


```php
public function getReadConnection( ModelInterface $model ): AdapterInterface;
```
Returns the connection to read data related to a model


```php
public function getReadConnectionService( ModelInterface $model ): string;
```
Returns the connection service name used to read data related to a model


```php
public function getRelationByAlias( string $modelName, string $alias ): Relation | bool;
```
Returns a relation by its alias


```php
public function getRelationRecords( RelationInterface $relation, ModelInterface $record, mixed $parameters = null, string $method = null );
```
Helper method to query records based on a relation definition

@return \Phalcon\Mvc\Model\Resultset\Simple|Phalcon\Mvc\Model\Resultset\Simple|int|false


```php
public function getRelations( string $modelName ): RelationInterface[];
```
Query all the relationships defined on a model


```php
public function getRelationsBetween( string $first, string $second ): RelationInterface[] | bool;
```
Query the relations between two models


```php
public function getWriteConnection( ModelInterface $model ): AdapterInterface;
```
Returns the connection to write data related to a model


```php
public function getWriteConnectionService( ModelInterface $model ): string;
```
Returns the connection service name used to write data related to a model


```php
public function initialize( ModelInterface $model );
```
Initializes a model in the model manager


```php
public function isInitialized( string $className ): bool;
```
Check of a model is already initialized


```php
public function isKeepingSnapshots( ModelInterface $model ): bool;
```
Checks if a model is keeping snapshots for the queried records


```php
public function isUsingDynamicUpdate( ModelInterface $model ): bool;
```
Checks if a model is using dynamic update instead of all-field update


```php
final public function isVisibleModelProperty( ModelInterface $model, string $property ): bool;
```
Check whether a model property is declared as public.

```php
$isPublic = $manager->isVisibleModelProperty(
    new Robots(),
    "name"
);
```


```php
public function keepSnapshots( ModelInterface $model, bool $keepSnapshots ): void;
```
Sets if a model must keep snapshots


```php
public function load( string $modelName ): ModelInterface;
```
Loads a model throwing an exception if it doesn't exist


```php
public function missingMethod( ModelInterface $model, string $eventName, mixed $data );
```
Dispatch an event to the listeners and behaviors
This method expects that the endpoint listeners/behaviors returns true
meaning that a least one is implemented

@param array data
@return bool


```php
public function notifyEvent( string $eventName, ModelInterface $model );
```
Receives events generated in the models and dispatches them to an events-manager if available
Notify the behaviors that are listening in the model


```php
public function setConnectionService( ModelInterface $model, string $connectionService ): void;
```
Sets both write and read connection service for a model


```php
public function setModelSchema( ModelInterface $model, string $schema ): void;
```
Sets the mapped schema for a model


```php
public function setModelSource( ModelInterface $model, string $source ): void;
```
Sets the mapped source for a model


```php
public function setReadConnectionService( ModelInterface $model, string $connectionService ): void;
```
Sets read connection service for a model


```php
public function setWriteConnectionService( ModelInterface $model, string $connectionService );
```
Sets write connection service for a model


```php
public function useDynamicUpdate( ModelInterface $model, bool $dynamicUpdate ): void;
```
Sets if a model must use dynamic update instead of the all-field update



        
<h1 id="mvc-model-metadata">Abstract Class Phalcon\Mvc\Model\MetaData</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/model/metadata.zep)

| Namespace  | Phalcon\Mvc\Model |
| Uses       | Phalcon\Di\DiInterface, Phalcon\Mvc\ModelInterface, Phalcon\Mvc\Model\Exception, Phalcon\Di\InjectionAwareInterface, Phalcon\Mvc\Model\MetaData\Strategy\Introspection, Phalcon\Mvc\Model\MetaData\StrategyInterface, Phalcon\Cache\Adapter\AdapterInterface |
| Implements | InjectionAwareInterface, MetaDataInterface |

Phalcon\Mvc\Model\MetaData

Because Phalcon\Mvc\Model requires meta-data like field names, data types,
primary keys, etc. This component collect them and store for further
querying by Phalcon\Mvc\Model. Phalcon\Mvc\Model\MetaData can also use
adapters to store temporarily or permanently the meta-data.

A standard Phalcon\Mvc\Model\MetaData can be used to query model attributes:

```php
$metaData = new \Phalcon\Mvc\Model\MetaData\Memory();

$attributes = $metaData->getAttributes(
    new Robots()
);

print_r($attributes);
```


## Constants
```php
const MODELS_ATTRIBUTES = 0;
const MODELS_AUTOMATIC_DEFAULT_INSERT = 10;
const MODELS_AUTOMATIC_DEFAULT_UPDATE = 11;
const MODELS_COLUMN_MAP = 0;
const MODELS_DATA_TYPES = 4;
const MODELS_DATA_TYPES_BIND = 9;
const MODELS_DATA_TYPES_NUMERIC = 5;
const MODELS_DATE_AT = 6;
const MODELS_DATE_IN = 7;
const MODELS_DEFAULT_VALUES = 12;
const MODELS_EMPTY_STRING_VALUES = 13;
const MODELS_IDENTITY_COLUMN = 8;
const MODELS_NON_PRIMARY_KEY = 2;
const MODELS_NOT_NULL = 3;
const MODELS_PRIMARY_KEY = 1;
const MODELS_REVERSE_COLUMN_MAP = 1;
```

## Properties
```php
/**
 * @var CacheAdapterInterface
 */
protected adapter;

//
protected columnMap;

//
protected container;

//
protected metaData;

//
protected strategy;

```

## Methods
```php
public function getAttributes( ModelInterface $model ): array;
```
Returns table attributes names (fields)

```php
print_r(
    $metaData->getAttributes(
        new Robots()
    )
);
```


```php
public function getAutomaticCreateAttributes( ModelInterface $model ): array;
```
Returns attributes that must be ignored from the INSERT SQL generation

```php
print_r(
    $metaData->getAutomaticCreateAttributes(
        new Robots()
    )
);
```


```php
public function getAutomaticUpdateAttributes( ModelInterface $model ): array;
```
Returns attributes that must be ignored from the UPDATE SQL generation

```php
print_r(
    $metaData->getAutomaticUpdateAttributes(
        new Robots()
    )
);
```


```php
public function getBindTypes( ModelInterface $model ): array;
```
Returns attributes and their bind data types

```php
print_r(
    $metaData->getBindTypes(
        new Robots()
    )
);
```


```php
public function getColumnMap( ModelInterface $model ): array;
```
Returns the column map if any

```php
print_r(
    $metaData->getColumnMap(
        new Robots()
    )
);
```


```php
public function getDI(): DiInterface;
```
Returns the DependencyInjector container


```php
public function getDataTypes( ModelInterface $model ): array;
```
Returns attributes and their data types

```php
print_r(
    $metaData->getDataTypes(
        new Robots()
    )
);
```


```php
public function getDataTypesNumeric( ModelInterface $model ): array;
```
Returns attributes which types are numerical

```php
print_r(
    $metaData->getDataTypesNumeric(
        new Robots()
    )
);
```


```php
public function getDefaultValues( ModelInterface $model ): array;
```
Returns attributes (which have default values) and their default values

```php
print_r(
    $metaData->getDefaultValues(
        new Robots()
    )
);
```


```php
public function getEmptyStringAttributes( ModelInterface $model ): array;
```
Returns attributes allow empty strings

```php
print_r(
    $metaData->getEmptyStringAttributes(
        new Robots()
    )
);
```


```php
public function getIdentityField( ModelInterface $model ): string;
```
Returns the name of identity field (if one is present)

```php
print_r(
    $metaData->getIdentityField(
        new Robots()
    )
);
```

@param  Phalcon\Mvc\ModelInterface model
@return string


```php
public function getNonPrimaryKeyAttributes( ModelInterface $model ): array;
```
Returns an array of fields which are not part of the primary key

```php
print_r(
    $metaData->getNonPrimaryKeyAttributes(
        new Robots()
    )
);
```


```php
public function getNotNullAttributes( ModelInterface $model ): array;
```
Returns an array of not null attributes

```php
print_r(
    $metaData->getNotNullAttributes(
        new Robots()
    )
);
```


```php
public function getPrimaryKeyAttributes( ModelInterface $model ): array;
```
Returns an array of fields which are part of the primary key

```php
print_r(
    $metaData->getPrimaryKeyAttributes(
        new Robots()
    )
);
```


```php
public function getReverseColumnMap( ModelInterface $model ): array;
```
Returns the reverse column map if any

```php
print_r(
    $metaData->getReverseColumnMap(
        new Robots()
    )
);
```


```php
public function getStrategy(): StrategyInterface;
```
Return the strategy to obtain the meta-data


```php
public function hasAttribute( ModelInterface $model, string $attribute ): bool;
```
Check if a model has certain attribute

```php
var_dump(
    $metaData->hasAttribute(
        new Robots(),
        "name"
    )
);
```


```php
public function isEmpty(): bool;
```
Checks if the internal meta-data container is empty

```php
var_dump(
    $metaData->isEmpty()
);
```


```php
public function read( string $key ): array | null;
```
Reads metadata from the adapter


```php
final public function readColumnMap( ModelInterface $model ): array | null;
```
Reads the ordered/reversed column map for certain model

```php
print_r(
    $metaData->readColumnMap(
        new Robots()
    )
);
```


```php
final public function readColumnMapIndex( ModelInterface $model, int $index );
```
Reads column-map information for certain model using a MODEL_* constant

```php
print_r(
    $metaData->readColumnMapIndex(
        new Robots(),
        MetaData::MODELS_REVERSE_COLUMN_MAP
    )
);
```


```php
final public function readMetaData( ModelInterface $model ): array;
```
Reads the complete meta-data for certain model

```php
print_r(
    $metaData->readMetaData(
        new Robots()
    )
);
```


```php
final public function readMetaDataIndex( ModelInterface $model, int $index );
```
Reads meta-data for certain model

```php
print_r(
    $metaData->readMetaDataIndex(
        new Robots(),
        0
    )
);
```


```php
public function reset(): void;
```
Resets internal meta-data in order to regenerate it

```php
$metaData->reset();
```


```php
public function setAutomaticCreateAttributes( ModelInterface $model, array $attributes ): void;
```
Set the attributes that must be ignored from the INSERT SQL generation

```php
$metaData->setAutomaticCreateAttributes(
    new Robots(),
    [
        "created_at" => true,
    ]
);
```


```php
public function setAutomaticUpdateAttributes( ModelInterface $model, array $attributes ): void;
```
Set the attributes that must be ignored from the UPDATE SQL generation

```php
$metaData->setAutomaticUpdateAttributes(
    new Robots(),
    [
        "modified_at" => true,
    ]
);
```


```php
public function setDI( DiInterface $container ): void;
```
Sets the DependencyInjector container


```php
public function setEmptyStringAttributes( ModelInterface $model, array $attributes ): void;
```
Set the attributes that allow empty string values

```php
$metaData->setEmptyStringAttributes(
    new Robots(),
    [
        "name" => true,
    ]
);
```


```php
public function setStrategy( StrategyInterface $strategy ): void;
```
Set the meta-data extraction strategy


```php
public function write( string $key, array $data ): void;
```
Writes the metadata to adapter


```php
final public function writeMetaDataIndex( ModelInterface $model, int $index, mixed $data ): void;
```
Writes meta-data for certain model using a MODEL_* constant

```php
print_r(
    $metaData->writeColumnMapIndex(
        new Robots(),
        MetaData::MODELS_REVERSE_COLUMN_MAP,
        [
            "leName" => "name",
        ]
    )
);
```


```php
final protected function initialize( ModelInterface $model, mixed $key, mixed $table, mixed $schema );
```
Initialize the metadata for certain table



        
<h1 id="mvc-model-metadata-apcu">Class Phalcon\Mvc\Model\MetaData\Apcu</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/model/metadata/apcu.zep)

| Namespace  | Phalcon\Mvc\Model\MetaData |
| Uses       | Phalcon\Mvc\Model\MetaData, Phalcon\Mvc\Model\Exception, Phalcon\Cache\AdapterFactory |
| Extends    | MetaData |

Phalcon\Mvc\Model\MetaData\Apcu

Stores model meta-data in the APCu cache. Data will erased if the web server is restarted

By default meta-data is stored for 48 hours (172800 seconds)

You can query the meta-data by printing apcu_fetch('$PMM$') or apcu_fetch('$PMM$my-app-id')

```php
$metaData = new \Phalcon\Mvc\Model\MetaData\Apcu(
    [
        "prefix"   => "my-app-id",
        "lifetime" => 86400,
    ]
);
```


## Methods
```php
public function __construct( AdapterFactory $factory, array $options = null ): void;
```
Phalcon\Mvc\Model\MetaData\Apcu constructor

@param array options



        
<h1 id="mvc-model-metadata-libmemcached">Class Phalcon\Mvc\Model\MetaData\Libmemcached</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/model/metadata/libmemcached.zep)

| Namespace  | Phalcon\Mvc\Model\MetaData |
| Uses       | Phalcon\Helper\Arr, Phalcon\Mvc\Model\Exception, Phalcon\Mvc\Model\MetaData, Phalcon\Cache\AdapterFactory |
| Extends    | MetaData |

Phalcon\Mvc\Model\MetaData\Libmemcached

Stores model meta-data in the Memcache.

By default meta-data is stored for 48 hours (172800 seconds)


## Methods
```php
public function __construct( AdapterFactory $factory, array $options = [] ): void;
```
Phalcon\Mvc\Model\MetaData\Libmemcached constructor

@param array options


```php
public function reset(): void;
```
Flush Memcache data and resets internal meta-data in order to regenerate it



        
<h1 id="mvc-model-metadata-memory">Class Phalcon\Mvc\Model\MetaData\Memory</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/model/metadata/memory.zep)

| Namespace  | Phalcon\Mvc\Model\MetaData |
| Uses       | Phalcon\Mvc\Model\MetaData, Phalcon\Mvc\Model\Exception |
| Extends    | MetaData |

Phalcon\Mvc\Model\MetaData\Memory

Stores model meta-data in memory. Data will be erased when the request finishes



## Methods
```php
public function __construct( mixed $options = null ): void;
```
Phalcon\Mvc\Model\MetaData\Memory constructor

@param array options


```php
public function read( string $key ): array | null;
```
Reads the meta-data from temporal memory


```php
public function write( string $key, array $data ): void;
```
Writes the meta-data to temporal memory



        
<h1 id="mvc-model-metadata-redis">Class Phalcon\Mvc\Model\MetaData\Redis</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/model/metadata/redis.zep)

| Namespace  | Phalcon\Mvc\Model\MetaData |
| Uses       | Phalcon\Mvc\Model\MetaData, Phalcon\Cache\AdapterFactory |
| Extends    | MetaData |

Phalcon\Mvc\Model\MetaData\Redis

Stores model meta-data in the Redis.

By default meta-data is stored for 48 hours (172800 seconds)

```php
use Phalcon\Mvc\Model\MetaData\Redis;

$metaData = new Redis(
    [
        "host"       => "127.0.0.1",
        "port"       => 6379,
        "persistent" => 0,
        "lifetime"   => 172800,
        "index"      => 2,
    ]
);
```


## Methods
```php
public function __construct( AdapterFactory $factory, array $options = [] ): void;
```
Phalcon\Mvc\Model\MetaData\Redis constructor

@param array options


```php
public function reset(): void;
```
Flush Redis data and resets internal meta-data in order to regenerate it



        
<h1 id="mvc-model-metadata-strategy-annotations">Class Phalcon\Mvc\Model\MetaData\Strategy\Annotations</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/model/metadata/strategy/annotations.zep)

| Namespace  | Phalcon\Mvc\Model\MetaData\Strategy |
| Uses       | Phalcon\Di\DiInterface, Phalcon\Db\Column, Phalcon\Mvc\ModelInterface, Phalcon\Mvc\Model\MetaData, Phalcon\Mvc\Model\MetaData\StrategyInterface, Phalcon\Mvc\Model\Exception |
| Implements | StrategyInterface |

This file is part of the Phalcon Framework.

(c) Phalcon Team <team@phalcon.io>

For the full copyright and license information, please view the LICENSE.txt
file that was distributed with this source code.


## Methods
```php
final public function getColumnMaps( ModelInterface $model, DiInterface $container ): array;
```
Read the model's column map, this can't be inferred


```php
final public function getMetaData( ModelInterface $model, DiInterface $container ): array;
```
The meta-data is obtained by reading the column descriptions from the database information schema



        
<h1 id="mvc-model-metadata-strategy-introspection">Class Phalcon\Mvc\Model\MetaData\Strategy\Introspection</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/model/metadata/strategy/introspection.zep)

| Namespace  | Phalcon\Mvc\Model\MetaData\Strategy |
| Uses       | Phalcon\Di\DiInterface, Phalcon\Db\Adapter\AdapterInterface, Phalcon\Db\Column, Phalcon\Mvc\ModelInterface, Phalcon\Mvc\Model\Exception, Phalcon\Mvc\Model\MetaData, Phalcon\Mvc\Model\MetaData\StrategyInterface |
| Implements | StrategyInterface |

Phalcon\Mvc\Model\MetaData\Strategy\Introspection

Queries the table meta-data in order to introspect the model's metadata


## Methods
```php
final public function getColumnMaps( ModelInterface $model, DiInterface $container ): array;
```
Read the model's column map, this can't be inferred


```php
final public function getMetaData( ModelInterface $model, DiInterface $container ): array;
```
The meta-data is obtained by reading the column descriptions from the database information schema



        
<h1 id="mvc-model-metadata-strategyinterface">Interface Phalcon\Mvc\Model\MetaData\StrategyInterface</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/model/metadata/strategyinterface.zep)

| Namespace  | Phalcon\Mvc\Model\MetaData |
| Uses       | Phalcon\Mvc\ModelInterface, Phalcon\Di\DiInterface |

This file is part of the Phalcon Framework.

(c) Phalcon Team <team@phalcon.io>

For the full copyright and license information, please view the LICENSE.txt
file that was distributed with this source code.


## Methods
```php
public function getColumnMaps( ModelInterface $model, DiInterface $container ): array;
```
Read the model's column map, this can't be inferred

@todo Not implemented


```php
public function getMetaData( ModelInterface $model, DiInterface $container ): array;
```
The meta-data is obtained by reading the column descriptions from the database information schema



        
<h1 id="mvc-model-metadata-stream">Class Phalcon\Mvc\Model\MetaData\Stream</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/model/metadata/stream.zep)

| Namespace  | Phalcon\Mvc\Model\MetaData |
| Uses       | Phalcon\Mvc\Model\MetaData, Phalcon\Mvc\Model\Exception |
| Extends    | MetaData |

Phalcon\Mvc\Model\MetaData\Stream

Stores model meta-data in PHP files.

```php
$metaData = new \Phalcon\Mvc\Model\MetaData\Files(
    [
        "metaDataDir" => "app/cache/metadata/",
    ]
);
```


## Properties
```php
//
protected metaDataDir = ./;

```

## Methods
```php
public function __construct( mixed $options = null ): void;
```
Phalcon\Mvc\Model\MetaData\Files constructor

@param array options


```php
public function read( string $key ): array | null;
```
Reads meta-data from files


```php
public function write( string $key, array $data ): void;
```
Writes the meta-data to files



        
<h1 id="mvc-model-metadatainterface">Interface Phalcon\Mvc\Model\MetaDataInterface</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/model/metadatainterface.zep)

| Namespace  | Phalcon\Mvc\Model |
| Uses       | Phalcon\Mvc\ModelInterface, Phalcon\Mvc\Model\MetaData\StrategyInterface |

Phalcon\Mvc\Model\MetaDataInterface

Interface for Phalcon\Mvc\Model\MetaData


## Methods
```php
public function getAttributes( ModelInterface $model ): array;
```
Returns table attributes names (fields)


```php
public function getAutomaticCreateAttributes( ModelInterface $model ): array;
```
Returns attributes that must be ignored from the INSERT SQL generation


```php
public function getAutomaticUpdateAttributes( ModelInterface $model ): array;
```
Returns attributes that must be ignored from the UPDATE SQL generation


```php
public function getBindTypes( ModelInterface $model ): array;
```
Returns attributes and their bind data types


```php
public function getColumnMap( ModelInterface $model ): array;
```
Returns the column map if any


```php
public function getDataTypes( ModelInterface $model ): array;
```
Returns attributes and their data types


```php
public function getDataTypesNumeric( ModelInterface $model ): array;
```
Returns attributes which types are numerical


```php
public function getDefaultValues( ModelInterface $model ): array;
```
Returns attributes (which have default values) and their default values


```php
public function getEmptyStringAttributes( ModelInterface $model ): array;
```
Returns attributes allow empty strings


```php
public function getIdentityField( ModelInterface $model ): string;
```
Returns the name of identity field (if one is present)


```php
public function getNonPrimaryKeyAttributes( ModelInterface $model ): array;
```
Returns an array of fields which are not part of the primary key


```php
public function getNotNullAttributes( ModelInterface $model ): array;
```
Returns an array of not null attributes


```php
public function getPrimaryKeyAttributes( ModelInterface $model ): array;
```
Returns an array of fields which are part of the primary key


```php
public function getReverseColumnMap( ModelInterface $model ): array;
```
Returns the reverse column map if any


```php
public function getStrategy(): StrategyInterface;
```
Return the strategy to obtain the meta-data


```php
public function hasAttribute( ModelInterface $model, string $attribute ): bool;
```
Check if a model has certain attribute


```php
public function isEmpty(): bool;
```
Checks if the internal meta-data container is empty


```php
public function read( string $key ): array | null;
```
Reads meta-data from the adapter


```php
public function readColumnMap( ModelInterface $model ): array | null;
```
Reads the ordered/reversed column map for certain model


```php
public function readColumnMapIndex( ModelInterface $model, int $index );
```
Reads column-map information for certain model using a MODEL_* constant


```php
public function readMetaData( ModelInterface $model ): array;
```
Reads meta-data for certain model


```php
public function readMetaDataIndex( ModelInterface $model, int $index ): mixed;
```
Reads meta-data for certain model using a MODEL_* constant


```php
public function reset();
```
Resets internal meta-data in order to regenerate it


```php
public function setAutomaticCreateAttributes( ModelInterface $model, array $attributes );
```
Set the attributes that must be ignored from the INSERT SQL generation


```php
public function setAutomaticUpdateAttributes( ModelInterface $model, array $attributes );
```
Set the attributes that must be ignored from the UPDATE SQL generation


```php
public function setEmptyStringAttributes( ModelInterface $model, array $attributes ): void;
```
Set the attributes that allow empty string values


```php
public function setStrategy( StrategyInterface $strategy );
```
Set the meta-data extraction strategy


```php
public function write( string $key, array $data ): void;
```
Writes meta-data to the adapter


```php
public function writeMetaDataIndex( ModelInterface $model, int $index, mixed $data );
```
Writes meta-data for certain model using a MODEL_* constant



        
<h1 id="mvc-model-query">Class Phalcon\Mvc\Model\Query</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/model/query.zep)

| Namespace  | Phalcon\Mvc\Model |
| Uses       | Phalcon\Db\Column, Phalcon\Db\RawValue, Phalcon\Db\ResultInterface, Phalcon\Db\Adapter\AdapterInterface, Phalcon\Di\DiInterface, Phalcon\Helper\Arr, Phalcon\Mvc\Model\Row, Phalcon\Mvc\ModelInterface, Phalcon\Mvc\Model\Exception, Phalcon\Mvc\Model\ManagerInterface, Phalcon\Mvc\Model\QueryInterface, Phalcon\Mvc\Model\Query\Status, Phalcon\Mvc\Model\Resultset\Complex, Phalcon\Mvc\Model\Query\StatusInterface, Phalcon\Mvc\Model\ResultsetInterface, Phalcon\Mvc\Model\Resultset\Simple, Phalcon\Di\InjectionAwareInterface, Phalcon\Mvc\Model\RelationInterface, Phalcon\Mvc\Model\TransactionInterface, Phalcon\Db\DialectInterface, Phalcon\Cache\Adapter\AdapterInterface |
| Implements | QueryInterface, InjectionAwareInterface |

Phalcon\Mvc\Model\Query

This class takes a PHQL intermediate representation and executes it.

```php
$phql = "SELECT c.price*0.16 AS taxes, c.* FROM Cars AS c JOIN Brands AS b
         WHERE b.name = :name: ORDER BY c.name";

$result = $manager->executeQuery(
    $phql,
    [
        "name" => "Lamborghini",
    ]
);

foreach ($result as $row) {
    echo "Name: ",  $row->cars->name, "\n";
    echo "Price: ", $row->cars->price, "\n";
    echo "Taxes: ", $row->taxes, "\n";
}

// with transaction
use Phalcon\Mvc\Model\Query;
use Phalcon\Mvc\Model\Transaction;

// $di needs to have the service "db" registered for this to work
$di = Phalcon\Di\FactoryDefault::getDefault();

$phql = 'SELECTFROM robot';

$myTransaction = new Transaction($di);
$myTransaction->begin();

$newRobot = new Robot();
$newRobot->setTransaction($myTransaction);
$newRobot->type = "mechanical";
$newRobot->name = "Astro Boy";
$newRobot->year = 1952;
$newRobot->save();

$queryWithTransaction = new Query($phql, $di);
$queryWithTransaction->setTransaction($myTransaction);

$resultWithEntries = $queryWithTransaction->execute();

$queryWithOutTransaction = new Query($phql, $di);
$resultWithOutEntries = $queryWithTransaction->execute();
```


## Constants
```php
const TYPE_DELETE = 303;
const TYPE_INSERT = 306;
const TYPE_SELECT = 309;
const TYPE_UPDATE = 300;
```

## Properties
```php
//
protected ast;

//
protected bindParams;

//
protected bindTypes;

//
protected cache;

//
protected cacheOptions;

//
protected container;

//
protected enableImplicitJoins;

//
protected intermediate;

//
protected manager;

//
protected metaData;

//
protected models;

//
protected modelsInstances;

//
protected nestingLevel = -1;

//
protected phql;

//
protected sharedLock;

//
protected sqlAliases;

//
protected sqlAliasesModels;

//
protected sqlAliasesModelsInstances;

//
protected sqlColumnAliases;

//
protected sqlModelsAliases;

//
protected type;

//
protected uniqueRow;

//
static protected _irPhqlCache;

/**
 * TransactionInterface so that the query can wrap a transaction
 * around batch updates and intermediate selects within the transaction.
 * however if a model got a transaction set inside it will use the local
 * transaction instead of this one
 */
protected _transaction;

```

## Methods
```php
public function __construct( string $phql = null, DiInterface $container = null, array $options = [] ): void;
```
Phalcon\Mvc\Model\Query constructor


```php
public function cache( array $cacheOptions ): QueryInterface;
```
Sets the cache parameters of the query


```php
public function execute( array $bindParams = [], array $bindTypes = [] );
```
Executes a parsed PHQL statement

@return mixed


```php
public function getBindParams(): array;
```
Returns default bind params


```php
public function getBindTypes(): array;
```
Returns default bind types


```php
public function getCache(): AdapterInterface;
```
Returns the current cache backend instance


```php
public function getCacheOptions(): array;
```
Returns the current cache options


```php
public function getDI(): DiInterface;
```
Returns the dependency injection container


```php
public function getIntermediate(): array;
```
Returns the intermediate representation of the PHQL statement


```php
public function getSingleResult( array $bindParams = [], array $bindTypes = [] ): ModelInterface;
```
Executes the query returning the first result


```php
public function getSql(): array;
```
Returns the SQL to be generated by the internal PHQL (only works in
SELECT statements)


```php
public function getType(): int;
```
Gets the type of PHQL statement executed


```php
public function getUniqueRow(): bool;
```
Check if the query is programmed to get only the first row in the
resultset


```php
public function get_transaction()
```


```php
public function parse(): array;
```
Parses the intermediate code produced by Phalcon\Mvc\Model\Query\Lang
generating another intermediate representation that could be executed by
Phalcon\Mvc\Model\Query


```php
public function setBindParams( array $bindParams, bool $merge = bool ): QueryInterface;
```
Set default bind parameters


```php
public function setBindTypes( array $bindTypes, bool $merge = bool ): QueryInterface;
```
Set default bind parameters


```php
public function setDI( DiInterface $container ): void;
```
Sets the dependency injection container


```php
public function setIntermediate( array $intermediate ): QueryInterface;
```
Allows to set the IR to be executed


```php
public function setSharedLock( bool $sharedLock = bool ): QueryInterface;
```
Set SHARED LOCK clause


```php
public function setTransaction( TransactionInterface $transaction ): QueryInterface;
```
allows to wrap a transaction around all queries


```php
public function setType( int $type ): QueryInterface;
```
Sets the type of PHQL statement to be executed


```php
public function setUniqueRow( bool $uniqueRow ): QueryInterface;
```
Tells to the query if only the first row in the resultset must be
returned


```php
final protected function _executeDelete( array $intermediate, array $bindParams, array $bindTypes ): StatusInterface;
```
Executes the DELETE intermediate representation producing a
Phalcon\Mvc\Model\Query\Status


```php
final protected function _executeInsert( array $intermediate, array $bindParams, array $bindTypes ): StatusInterface;
```
Executes the INSERT intermediate representation producing a
Phalcon\Mvc\Model\Query\Status


```php
final protected function _executeSelect( array $intermediate, array $bindParams, array $bindTypes, bool $simulate = bool ): ResultsetInterface | array;
```
Executes the SELECT intermediate representation producing a
Phalcon\Mvc\Model\Resultset


```php
final protected function _executeUpdate( array $intermediate, array $bindParams, array $bindTypes ): StatusInterface;
```
Executes the UPDATE intermediate representation producing a
Phalcon\Mvc\Model\Query\Status


```php
final protected function _getCallArgument( array $argument ): array;
```
Resolves an expression in a single call argument


```php
final protected function _getCaseExpression( array $expr ): array;
```
Resolves an expression in a single call argument


```php
final protected function _getExpression( array $expr, bool $quoting = bool ): string;
```
Resolves an expression from its intermediate code into a string


```php
final protected function _getFunctionCall( array $expr ): array;
```
Resolves an expression in a single call argument


```php
final protected function _getGroupClause( array $group ): array;
```
Returns a processed group clause for a SELECT statement


```php
final protected function _getJoin( ManagerInterface $manager, array $join ): array;
```
Resolves a JOIN clause checking if the associated models exist


```php
final protected function _getJoinType( array $join ): string;
```
Resolves a JOIN type


```php
final protected function _getJoins( array $select ): array;
```
Processes the JOINs in the query returning an internal representation for
the database dialect


```php
final protected function _getLimitClause( array $limitClause ): array;
```
Returns a processed limit clause for a SELECT statement


```php
final protected function _getMultiJoin( string $joinType, mixed $joinSource, string $modelAlias, string $joinAlias, RelationInterface $relation ): array;
```
Resolves joins involving many-to-many relations

@param string joinSource


```php
final protected function _getOrderClause( mixed $order ): array;
```
Returns a processed order clause for a SELECT statement

@param array|string order


```php
final protected function _getQualified( array $expr ): array;
```
Replaces the model's name to its source name in a qualified-name
expression


```php
final protected function _getRelatedRecords( ModelInterface $model, array $intermediate, array $bindParams, array $bindTypes ): ResultsetInterface;
```
Query the records on which the UPDATE/DELETE operation will be done


```php
final protected function _getSelectColumn( array $column ): array;
```
Resolves a column from its intermediate representation into an array
used to determine if the resultset produced is simple or complex


```php
final protected function _getSingleJoin( string $joinType, mixed $joinSource, string $modelAlias, string $joinAlias, RelationInterface $relation ): array;
```
Resolves joins involving has-one/belongs-to/has-many relations

@param string joinSource


```php
final protected function _getTable( ManagerInterface $manager, array $qualifiedName );
```
Resolves a table in a SELECT statement checking if the model exists

@return string


```php
final protected function _prepareDelete(): array;
```
Analyzes a DELETE intermediate code and produces an array to be executed
later


```php
final protected function _prepareInsert(): array;
```
Analyzes an INSERT intermediate code and produces an array to be executed
later


```php
final protected function _prepareSelect( mixed $ast = null, bool $merge = bool ): array;
```
Analyzes a SELECT intermediate code and produces an array to be executed later


```php
final protected function _prepareUpdate(): array;
```
Analyzes an UPDATE intermediate code and produces an array to be executed
later


```php
protected function getReadConnection( ModelInterface $model, array $intermediate = null, array $bindParams = [], array $bindTypes = [] ): AdapterInterface;
```
Gets the read connection from the model if there is no transaction set
inside the query object


```php
protected function getWriteConnection( ModelInterface $model, array $intermediate = null, array $bindParams = [], array $bindTypes = [] ): AdapterInterface;
```
Gets the write connection from the model if there is no transaction
inside the query object



        
<h1 id="mvc-model-query-builder">Class Phalcon\Mvc\Model\Query\Builder</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/model/query/builder.zep)

| Namespace  | Phalcon\Mvc\Model\Query |
| Uses       | Phalcon\Di, Phalcon\Db\Column, Phalcon\Di\DiInterface, Phalcon\Helper\Arr, Phalcon\Mvc\Model\Exception, Phalcon\Di\InjectionAwareInterface, Phalcon\Mvc\Model\QueryInterface, Phalcon\Mvc\Model\Query\BuilderInterface |
| Implements | BuilderInterface, InjectionAwareInterface |

Phalcon\Mvc\Model\Query\Builder

Helps to create PHQL queries using an OO interface

```php
$params = [
    "models"     => [
        Users::class,
    ],
    "columns"    => ["id", "name", "status"],
    "conditions" => [
        [
            "created > :min: AND created < :max:",
            [
                "min" => "2013-01-01",
                "max" => "2014-01-01",
            ],
            [
                "min" => PDO::PARAM_STR,
                "max" => PDO::PARAM_STR,
            ],
        ],
    ],
    // or "conditions" => "created > '2013-01-01' AND created < '2014-01-01'",
    "group"      => ["id", "name"],
    "having"     => "name = 'Kamil'",
    "order"      => ["name", "id"],
    "limit"      => 20,
    "offset"     => 20,
    // or "limit" => [20, 20],
];

$queryBuilder = new \Phalcon\Mvc\Model\Query\Builder($params);
```


## Properties
```php
//
protected bindParams;

//
protected bindTypes;

//
protected columns;

//
protected conditions;

//
protected container;

//
protected distinct;

//
protected forUpdate;

/**
 * @var array
 */
protected group;

//
protected having;

//
protected hiddenParamNumber = 0;

//
protected joins;

//
protected limit;

//
protected models;

//
protected offset;

//
protected order;

//
protected sharedLock;

```

## Methods
```php
public function __construct( mixed $params = null, DiInterface $container = null ): void;
```
Phalcon\Mvc\Model\Query\Builder constructor


```php
public function addFrom( string $model, string $alias = null ): BuilderInterface;
```
Add a model to take part of the query

```php
// Load data from models Robots
$builder->addFrom(
    Robots::class
);

// Load data from model 'Robots' using 'r' as alias in PHQL
$builder->addFrom(
    Robots::class,
    "r"
);
```


```php
public function andHaving( string $conditions, array $bindParams = [], array $bindTypes = [] ): BuilderInterface;
```
Appends a condition to the current HAVING conditions clause using a AND operator

```php
$builder->andHaving("SUM(Robots.price) > 0");

$builder->andHaving(
    "SUM(Robots.price) > :sum:",
    [
        "sum" => 100,
    ]
);
```


```php
public function andWhere( string $conditions, array $bindParams = [], array $bindTypes = [] ): BuilderInterface;
```
Appends a condition to the current WHERE conditions using a AND operator

```php
$builder->andWhere("name = 'Peter'");

$builder->andWhere(
    "name = :name: AND id > :id:",
    [
        "name" => "Peter",
        "id"   => 100,
    ]
);
```


```php
final public function autoescape( string $identifier ): string;
```
Automatically escapes identifiers but only if they need to be escaped.


```php
public function betweenHaving( string $expr, mixed $minimum, mixed $maximum, string $operator = static-constant-access ): BuilderInterface;
```
Appends a BETWEEN condition to the current HAVING conditions clause

```php
$builder->betweenHaving("SUM(Robots.price)", 100.25, 200.50);
```


```php
public function betweenWhere( string $expr, mixed $minimum, mixed $maximum, string $operator = static-constant-access ): BuilderInterface;
```
Appends a BETWEEN condition to the current WHERE conditions

```php
$builder->betweenWhere("price", 100.25, 200.50);
```


```php
public function columns( mixed $columns ): BuilderInterface;
```
Sets the columns to be queried

```php
$builder->columns("id, name");

$builder->columns(
    [
        "id",
        "name",
    ]
);

$builder->columns(
    [
        "name",
        "number" => "COUNT(*)",
    ]
);
```


```php
public function distinct( mixed $distinct ): BuilderInterface;
```
Sets SELECT DISTINCT / SELECT ALL flag

```php
$builder->distinct("status");
$builder->distinct(null);
```


```php
public function forUpdate( bool $forUpdate ): BuilderInterface;
```
Sets a FOR UPDATE clause

```php
$builder->forUpdate(true);
```


```php
public function from( mixed $models ): BuilderInterface;
```
Sets the models who makes part of the query

```php
$builder->from(
    Robots::class
);

$builder->from(
    [
        Robots::class,
        RobotsParts::class,
    ]
);

$builder->from(
    [
        "r"  => Robots::class,
        "rp" => RobotsParts::class,
    ]
);
```


```php
public function getBindParams(): array;
```
Returns default bind params


```php
public function getBindTypes(): array;
```
Returns default bind types


```php
public function getColumns();
```
Return the columns to be queried

@return string|array


```php
public function getDI(): DiInterface;
```
Returns the DependencyInjector container


```php
public function getDistinct(): bool;
```
Returns SELECT DISTINCT / SELECT ALL flag


```php
public function getFrom();
```
Return the models who makes part of the query

@return string|array


```php
public function getGroupBy(): array;
```
Returns the GROUP BY clause


```php
public function getHaving(): string;
```
Return the current having clause


```php
public function getJoins(): array;
```
Return join parts of the query


```php
public function getLimit();
```
Returns the current LIMIT clause

@return string|array


```php
public function getModels(): string | array | null;
```
Returns the models involved in the query


```php
public function getOffset(): int;
```
Returns the current OFFSET clause


```php
public function getOrderBy();
```
Returns the set ORDER BY clause

@return string|array


```php
final public function getPhql(): string;
```
Returns a PHQL statement built based on the builder parameters


```php
public function getQuery(): QueryInterface;
```
Returns the query built


```php
public function getWhere();
```
Return the conditions for the query

@return string|array


```php
public function groupBy( mixed $group ): BuilderInterface;
```
Sets a GROUP BY clause

```php
$builder->groupBy(
    [
        "Robots.name",
    ]
);
```

@param string|array group


```php
public function having( mixed $conditions, array $bindParams = [], array $bindTypes = [] ): BuilderInterface;
```
Sets the HAVING condition clause

```php
$builder->having("SUM(Robots.price) > 0");

$builder->having(
    "SUM(Robots.price) > :sum:",
    [
        "sum" => 100,
    ]
);
```


```php
public function inHaving( string $expr, array $values, string $operator = static-constant-access ): BuilderInterface;
```
Appends an IN condition to the current HAVING conditions clause

```php
$builder->inHaving("SUM(Robots.price)", [100, 200]);
```


```php
public function inWhere( string $expr, array $values, string $operator = static-constant-access ): BuilderInterface;
```
Appends an IN condition to the current WHERE conditions

```php
$builder->inWhere(
    "id",
    [1, 2, 3]
);
```


```php
public function innerJoin( string $model, string $conditions = null, string $alias = null ): BuilderInterface;
```
Adds an INNER join to the query

```php
// Inner Join model 'Robots' with automatic conditions and alias
$builder->innerJoin(
    Robots::class
);

// Inner Join model 'Robots' specifying conditions
$builder->innerJoin(
    Robots::class,
    "Robots.id = RobotsParts.robots_id"
);

// Inner Join model 'Robots' specifying conditions and alias
$builder->innerJoin(
    Robots::class,
    "r.id = RobotsParts.robots_id",
    "r"
);
```


```php
public function join( string $model, string $conditions = null, string $alias = null, string $type = null ): BuilderInterface;
```
Adds an :type: join (by default type - INNER) to the query

```php
// Inner Join model 'Robots' with automatic conditions and alias
$builder->join(
    Robots::class
);

// Inner Join model 'Robots' specifying conditions
$builder->join(
    Robots::class,
    "Robots.id = RobotsParts.robots_id"
);

// Inner Join model 'Robots' specifying conditions and alias
$builder->join(
    Robots::class,
    "r.id = RobotsParts.robots_id",
    "r"
);

// Left Join model 'Robots' specifying conditions, alias and type of join
$builder->join(
    Robots::class,
    "r.id = RobotsParts.robots_id",
    "r",
    "LEFT"
);
```


```php
public function leftJoin( string $model, string $conditions = null, string $alias = null ): BuilderInterface;
```
Adds a LEFT join to the query

```php
$builder->leftJoin(
    Robots::class,
    "r.id = RobotsParts.robots_id",
    "r"
);
```


```php
public function limit( int $limit, mixed $offset = null ): BuilderInterface;
```
Sets a LIMIT clause, optionally an offset clause

```php
$builder->limit(100);
$builder->limit(100, 20);
$builder->limit("100", "20");
```


```php
public function notBetweenHaving( string $expr, mixed $minimum, mixed $maximum, string $operator = static-constant-access ): BuilderInterface;
```
Appends a NOT BETWEEN condition to the current HAVING conditions clause

```php
$builder->notBetweenHaving("SUM(Robots.price)", 100.25, 200.50);
```


```php
public function notBetweenWhere( string $expr, mixed $minimum, mixed $maximum, string $operator = static-constant-access ): BuilderInterface;
```
Appends a NOT BETWEEN condition to the current WHERE conditions

```php
$builder->notBetweenWhere("price", 100.25, 200.50);
```


```php
public function notInHaving( string $expr, array $values, string $operator = static-constant-access ): BuilderInterface;
```
Appends a NOT IN condition to the current HAVING conditions clause

```php
$builder->notInHaving("SUM(Robots.price)", [100, 200]);
```


```php
public function notInWhere( string $expr, array $values, string $operator = static-constant-access ): BuilderInterface;
```
Appends a NOT IN condition to the current WHERE conditions

```php
$builder->notInWhere("id", [1, 2, 3]);
```


```php
public function offset( int $offset ): BuilderInterface;
```
Sets an OFFSET clause

```php
$builder->offset(30);
```


```php
public function orHaving( string $conditions, array $bindParams = [], array $bindTypes = [] ): BuilderInterface;
```
Appends a condition to the current HAVING conditions clause using an OR operator

```php
$builder->orHaving("SUM(Robots.price) > 0");

$builder->orHaving(
    "SUM(Robots.price) > :sum:",
    [
        "sum" => 100,
    ]
);
```


```php
public function orWhere( string $conditions, array $bindParams = [], array $bindTypes = [] ): BuilderInterface;
```
Appends a condition to the current conditions using an OR operator

```php
$builder->orWhere("name = 'Peter'");

$builder->orWhere(
    "name = :name: AND id > :id:",
    [
        "name" => "Peter",
        "id"   => 100,
    ]
);
```


```php
public function orderBy( mixed $orderBy ): BuilderInterface;
```
Sets an ORDER BY condition clause

```php
$builder->orderBy("Robots.name");
$builder->orderBy(["1", "Robots.name"]);
$builder->orderBy(["Robots.name DESC"]);
```

@param string|array orderBy


```php
public function rightJoin( string $model, string $conditions = null, string $alias = null ): BuilderInterface;
```
Adds a RIGHT join to the query

```php
$builder->rightJoin(
    Robots::class,
    "r.id = RobotsParts.robots_id",
    "r"
);
```


```php
public function setBindParams( array $bindParams, bool $merge = bool ): BuilderInterface;
```
Set default bind parameters


```php
public function setBindTypes( array $bindTypes, bool $merge = bool ): BuilderInterface;
```
Set default bind types


```php
public function setDI( DiInterface $container ): BuilderInterface;
```
Sets the DependencyInjector container


```php
public function where( string $conditions, array $bindParams = [], array $bindTypes = [] ): BuilderInterface;
```
Sets the query WHERE conditions

```php
$builder->where(100);

$builder->where("name = 'Peter'");

$builder->where(
    "name = :name: AND id > :id:",
    [
        "name" => "Peter",
        "id"   => 100,
    ]
);
```


```php
protected function conditionBetween( string $clause, string $operator, string $expr, mixed $minimum, mixed $maximum ): BuilderInterface;
```
Appends a BETWEEN condition


```php
protected function conditionIn( string $clause, string $operator, string $expr, array $values ): BuilderInterface;
```
Appends an IN condition


```php
protected function conditionNotBetween( string $clause, string $operator, string $expr, mixed $minimum, mixed $maximum ): BuilderInterface;
```
Appends a NOT BETWEEN condition


```php
protected function conditionNotIn( string $clause, string $operator, string $expr, array $values ): BuilderInterface;
```
Appends a NOT IN condition



        
<h1 id="mvc-model-query-builderinterface">Interface Phalcon\Mvc\Model\Query\BuilderInterface</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/model/query/builderinterface.zep)

| Namespace  | Phalcon\Mvc\Model\Query |
| Uses       | Phalcon\Mvc\Model\QueryInterface |

Phalcon\Mvc\Model\Query\BuilderInterface

Interface for Phalcon\Mvc\Model\Query\Builder


## Constants
```php
const OPERATOR_AND = and;
const OPERATOR_OR = or;
```

## Methods
```php
public function addFrom( string $model, string $alias = null ): BuilderInterface;
```
Add a model to take part of the query


```php
public function andWhere( string $conditions, array $bindParams = [], array $bindTypes = [] ): BuilderInterface;
```
Appends a condition to the current conditions using a AND operator


```php
public function betweenWhere( string $expr, mixed $minimum, mixed $maximum, string $operator = static-constant-access ): BuilderInterface;
```
Appends a BETWEEN condition to the current conditions

@param mixed minimum
@param mixed maximum


```php
public function columns( mixed $columns ): BuilderInterface;
```
Sets the columns to be queried

@param string|array columns


```php
public function distinct( mixed $distinct ): BuilderInterface;
```
Sets SELECT DISTINCT / SELECT ALL flag

```php
$builder->distinct("status");
$builder->distinct(null);
```


```php
public function forUpdate( bool $forUpdate ): BuilderInterface;
```
Sets a FOR UPDATE clause

```php
$builder->forUpdate(true);
```


```php
public function from( mixed $models ): BuilderInterface;
```
Sets the models who makes part of the query

@param string|array models


```php
public function getBindParams(): array;
```
Returns default bind params


```php
public function getBindTypes(): array;
```
Returns default bind types


```php
public function getColumns();
```
Return the columns to be queried

@return string|array


```php
public function getDistinct(): bool;
```
Returns SELECT DISTINCT / SELECT ALL flag


```php
public function getFrom();
```
Return the models who makes part of the query

@return string|array


```php
public function getGroupBy(): array;
```
Returns the GROUP BY clause


```php
public function getHaving(): string;
```
Returns the HAVING condition clause


```php
public function getJoins(): array;
```
Return join parts of the query


```php
public function getLimit();
```
Returns the current LIMIT clause

@return string|array


```php
public function getModels(): string | array | null;
```
Returns the models involved in the query


```php
public function getOffset(): int;
```
Returns the current OFFSET clause


```php
public function getOrderBy();
```
Return the set ORDER BY clause

@return string|array


```php
public function getPhql(): string;
```
Returns a PHQL statement built based on the builder parameters


```php
public function getQuery(): QueryInterface;
```
Returns the query built


```php
public function getWhere();
```
Return the conditions for the query

@return string|array


```php
public function groupBy( mixed $group ): BuilderInterface;
```
Sets a GROUP BY clause

@param string|array group


```php
public function having( string $having ): BuilderInterface;
```
Sets a HAVING condition clause


```php
public function inWhere( string $expr, array $values, string $operator = static-constant-access ): BuilderInterface;
```
Appends an IN condition to the current conditions


```php
public function innerJoin( string $model, string $conditions = null, string $alias = null ): BuilderInterface;
```
Adds an INNER join to the query


```php
public function join( string $model, string $conditions = null, string $alias = null ): BuilderInterface;
```
Adds an :type: join (by default type - INNER) to the query

@param string model
@param string conditions
@param string alias
@param string type
@return BuilderInterface


```php
public function leftJoin( string $model, string $conditions = null, string $alias = null ): BuilderInterface;
```
Adds a LEFT join to the query


```php
public function limit( int $limit, mixed $offset = null ): BuilderInterface;
```
Sets a LIMIT clause

@param int offset


```php
public function notBetweenWhere( string $expr, mixed $minimum, mixed $maximum, string $operator = static-constant-access ): BuilderInterface;
```
Appends a NOT BETWEEN condition to the current conditions

@param mixed minimum
@param mixed maximum


```php
public function notInWhere( string $expr, array $values, string $operator = static-constant-access ): BuilderInterface;
```
Appends a NOT IN condition to the current conditions


```php
public function offset( int $offset ): BuilderInterface;
```
Sets an OFFSET clause


```php
public function orWhere( string $conditions, array $bindParams = [], array $bindTypes = [] ): BuilderInterface;
```
Appends a condition to the current conditions using an OR operator


```php
public function orderBy( string $orderBy ): BuilderInterface;
```
Sets an ORDER BY condition clause


```php
public function rightJoin( string $model, string $conditions = null, string $alias = null ): BuilderInterface;
```
Adds a RIGHT join to the query


```php
public function setBindParams( array $bindParams, bool $merge = bool ): BuilderInterface;
```
Set default bind parameters


```php
public function setBindTypes( array $bindTypes, bool $merge = bool ): BuilderInterface;
```
Set default bind types


```php
public function where( string $conditions, array $bindParams = [], array $bindTypes = [] ): BuilderInterface;
```
Sets conditions for the query



        
<h1 id="mvc-model-query-lang">Abstract Class Phalcon\Mvc\Model\Query\Lang</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/model/query/lang.zep)

| Namespace  | Phalcon\Mvc\Model\Query |

Phalcon\Mvc\Model\Query\Lang

PHQL is implemented as a parser (written in C) that translates syntax in
that of the target RDBMS. It allows Phalcon to offer a unified SQL language to
the developer, while internally doing all the work of translating PHQL
instructions to the most optimal SQL instructions depending on the
RDBMS type associated with a model.

To achieve the highest performance possible, we wrote a parser that uses
the same technology as SQLite. This technology provides a small in-memory
parser with a very low memory footprint that is also thread-safe.

```php
$intermediate = Phalcon\Mvc\Model\Query\Lang::parsePHQL(
    "SELECT r.* FROM Robots r LIMIT 10"
);
```


        
<h1 id="mvc-model-query-status">Class Phalcon\Mvc\Model\Query\Status</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/model/query/status.zep)

| Namespace  | Phalcon\Mvc\Model\Query |
| Uses       | Phalcon\Messages\MessageInterface, Phalcon\Mvc\ModelInterface, Phalcon\Mvc\Model\Query\StatusInterface |
| Implements | StatusInterface |

Phalcon\Mvc\Model\Query\Status

This class represents the status returned by a PHQL
statement like INSERT, UPDATE or DELETE. It offers context
information and the related messages produced by the
model which finally executes the operations when it fails

```php
$phql = "UPDATE Robots SET name = :name:, type = :type:, year = :year: WHERE id = :id:";

$status = $app->modelsManager->executeQuery(
    $phql,
    [
        "id"   => 100,
        "name" => "Astroy Boy",
        "type" => "mechanical",
        "year" => 1959,
    ]
);

// Check if the update was successful
if ($status->success()) {
    echo "OK";
}
```


## Properties
```php
//
protected model;

//
protected success;

```

## Methods
```php
public function __construct( bool $success, ModelInterface $model = null ): void;
```
Phalcon\Mvc\Model\Query\Status


```php
public function getMessages(): MessageInterface[];
```
Returns the messages produced because of a failed operation


```php
public function getModel(): ModelInterface;
```
Returns the model that executed the action


```php
public function success(): bool;
```
Allows to check if the executed operation was successful



        
<h1 id="mvc-model-query-statusinterface">Interface Phalcon\Mvc\Model\Query\StatusInterface</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/model/query/statusinterface.zep)

| Namespace  | Phalcon\Mvc\Model\Query |
| Uses       | Phalcon\Messages\MessageInterface, Phalcon\Mvc\ModelInterface |

Phalcon\Mvc\Model\Query\StatusInterface

Interface for Phalcon\Mvc\Model\Query\Status


## Methods
```php
public function getMessages(): MessageInterface[];
```
Returns the messages produced by an operation failed


```php
public function getModel(): ModelInterface;
```
Returns the model which executed the action


```php
public function success(): bool;
```
Allows to check if the executed operation was successful



        
<h1 id="mvc-model-queryinterface">Interface Phalcon\Mvc\Model\QueryInterface</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/model/queryinterface.zep)

| Namespace  | Phalcon\Mvc\Model |
| Uses       | Phalcon\Mvc\ModelInterface |

Phalcon\Mvc\Model\QueryInterface

Interface for Phalcon\Mvc\Model\Query


## Methods
```php
public function cache( array $cacheOptions ): QueryInterface;
```
Sets the cache parameters of the query


```php
public function execute( array $bindParams = [], array $bindTypes = [] );
```
Executes a parsed PHQL statement

@return mixed


```php
public function getBindParams(): array;
```
Returns default bind params


```php
public function getBindTypes(): array;
```
Returns default bind types


```php
public function getCacheOptions(): array;
```
Returns the current cache options


```php
public function getSingleResult( array $bindParams = [], array $bindTypes = [] ): ModelInterface;
```
Executes the query returning the first result


```php
public function getSql(): array;
```
Returns the SQL to be generated by the internal PHQL (only works in SELECT statements)


```php
public function getUniqueRow(): bool;
```
Check if the query is programmed to get only the first row in the resultset


```php
public function parse(): array;
```
Parses the intermediate code produced by Phalcon\Mvc\Model\Query\Lang generating another
intermediate representation that could be executed by Phalcon\Mvc\Model\Query


```php
public function setBindParams( array $bindParams, bool $merge = bool ): QueryInterface;
```
Set default bind parameters


```php
public function setBindTypes( array $bindTypes, bool $merge = bool ): QueryInterface;
```
Set default bind parameters


```php
public function setSharedLock( bool $sharedLock = bool ): QueryInterface;
```
Set SHARED LOCK clause


```php
public function setUniqueRow( bool $uniqueRow ): QueryInterface;
```
Tells to the query if only the first row in the resultset must be returned



        
<h1 id="mvc-model-relation">Class Phalcon\Mvc\Model\Relation</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/model/relation.zep)

| Namespace  | Phalcon\Mvc\Model |
| Uses       | Phalcon\Mvc\Model\RelationInterface |
| Implements | RelationInterface |

Phalcon\Mvc\Model\Relation

This class represents a relationship between two models


## Constants
```php
const ACTION_CASCADE = 2;
const ACTION_RESTRICT = 1;
const BELONGS_TO = 0;
const HAS_MANY = 2;
const HAS_MANY_THROUGH = 4;
const HAS_ONE = 1;
const HAS_ONE_THROUGH = 3;
const NO_ACTION = 0;
```

## Properties
```php
//
protected fields;

//
protected intermediateFields;

//
protected intermediateModel;

//
protected intermediateReferencedFields;

//
protected options;

//
protected referencedFields;

//
protected referencedModel;

//
protected type;

```

## Methods
```php
public function __construct( int $type, string $referencedModel, mixed $fields, mixed $referencedFields, array $options = [] ): void;
```
Phalcon\Mvc\Model\Relation constructor

@param string|array fields
@param string|array referencedFields


```php
public function getFields();
```
Returns the fields

@return string|array


```php
public function getForeignKey();
```
Returns the foreign key configuration

@return string|array


```php
public function getIntermediateFields();
```
Gets the intermediate fields for has-*-through relations

@return string|array


```php
public function getIntermediateModel(): string;
```
Gets the intermediate model for has-*-through relations


```php
public function getIntermediateReferencedFields();
```
Gets the intermediate referenced fields for has-*-through relations

@return string|array


```php
public function getOption( string $name );
```
Returns an option by the specified name
If the option doesn't exist null is returned


```php
public function getOptions(): array;
```
Returns the options


```php
public function getParams();
```
Returns parameters that must be always used when the related records are obtained

@return array


```php
public function getReferencedFields();
```
Returns the referenced fields

@return string|array


```php
public function getReferencedModel(): string;
```
Returns the referenced model


```php
public function getType(): int;
```
Returns the relation type


```php
public function isForeignKey(): bool;
```
Check whether the relation act as a foreign key


```php
public function isReusable(): bool;
```
Check if records returned by getting belongs-to/has-many are implicitly cached during the current request


```php
public function isThrough(): bool;
```
Check whether the relation is a 'many-to-many' relation or not


```php
public function setIntermediateRelation( mixed $intermediateFields, string $intermediateModel, mixed $intermediateReferencedFields );
```
Sets the intermediate model data for has-*-through relations

@param string|array intermediateFields
@param string       intermediateReferencedFields



        
<h1 id="mvc-model-relationinterface">Interface Phalcon\Mvc\Model\RelationInterface</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/model/relationinterface.zep)

| Namespace  | Phalcon\Mvc\Model |

Phalcon\Mvc\Model\RelationInterface

Interface for Phalcon\Mvc\Model\Relation


## Methods
```php
public function getFields();
```
Returns the fields

@return string|array


```php
public function getForeignKey();
```
Returns the foreign key configuration

@return string|array


```php
public function getIntermediateFields();
```
Gets the intermediate fields for has-*-through relations

@return string|array


```php
public function getIntermediateModel(): string;
```
Gets the intermediate model for has-*-through relations


```php
public function getIntermediateReferencedFields();
```
Gets the intermediate referenced fields for has-*-through relations

@return string|array


```php
public function getOption( string $name );
```
Returns an option by the specified name
If the option doesn't exist null is returned


```php
public function getOptions(): array;
```
Returns the options


```php
public function getParams();
```
Returns parameters that must be always used when the related records are obtained

@return array


```php
public function getReferencedFields();
```
Returns the referenced fields

@return string|array


```php
public function getReferencedModel(): string;
```
Returns the referenced model


```php
public function getType(): int;
```
Returns the relations type


```php
public function isForeignKey(): bool;
```
Check whether the relation act as a foreign key


```php
public function isReusable(): bool;
```
Check if records returned by getting belongs-to/has-many are implicitly cached during the current request


```php
public function isThrough(): bool;
```
Check whether the relation is a 'many-to-many' relation or not


```php
public function setIntermediateRelation( mixed $intermediateFields, string $intermediateModel, mixed $intermediateReferencedFields );
```
Sets the intermediate model dat for has-*-through relations

@param string|array intermediateFields
@param string|array intermediateReferencedFields



        
<h1 id="mvc-model-resultinterface">Interface Phalcon\Mvc\Model\ResultInterface</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/model/resultinterface.zep)

| Namespace  | Phalcon\Mvc\Model |
| Uses       | Phalcon\Mvc\ModelInterface |

Phalcon\Mvc\Model\ResultInterface

All single objects passed as base objects to Resultsets must implement this interface


## Methods
```php
public function setDirtyState( int $dirtyState ): ModelInterface | bool;
```
Sets the object's state



        
<h1 id="mvc-model-resultset">Abstract Class Phalcon\Mvc\Model\Resultset</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/model/resultset.zep)

| Namespace  | Phalcon\Mvc\Model |
| Uses       | ArrayAccess, Closure, Countable, Iterator, JsonSerializable, Phalcon\Db\Enum, Phalcon\Messages\MessageInterface, Phalcon\Mvc\Model, Phalcon\Mvc\ModelInterface, Phalcon\Mvc\Model\Exception, Phalcon\Mvc\Model\ResultsetInterface, Phalcon\Cache\Adapter\AdapterInterface, Phalcon\Storage\Serializer\SerializerInterface, SeekableIterator, Serializable |
| Implements | ResultsetInterface, Iterator, SeekableIterator, Countable, ArrayAccess, Serializable, JsonSerializable |

Phalcon\Mvc\Model\Resultset

This component allows to Phalcon\Mvc\Model returns large resultsets with the minimum memory consumption
Resultsets can be traversed using a standard foreach or a while statement. If a resultset is serialized
it will dump all the rows into a big array. Then unserialize will retrieve the rows as they were before
serializing.

```php

// Using a standard foreach
$robots = Robots::find(
    [
        "type = 'virtual'",
        "order" => "name",
    ]
);

foreach ($robots as robot) {
    echo robot->name, "\n";
}

// Using a while
$robots = Robots::find(
    [
        "type = 'virtual'",
        "order" => "name",
    ]
);

$robots->rewind();

while ($robots->valid()) {
    $robot = $robots->current();

    echo $robot->name, "\n";

    $robots->next();
}
```


## Constants
```php
const HYDRATE_ARRAYS = 1;
const HYDRATE_OBJECTS = 2;
const HYDRATE_RECORDS = 0;
const TYPE_RESULT_FULL = 0;
const TYPE_RESULT_PARTIAL = 1;
```

## Properties
```php
//
protected activeRow;

//
protected cache;

//
protected count;

//
protected errorMessages;

//
protected hydrateMode = 0;

//
protected isFresh = true;

//
protected pointer = 0;

//
protected row;

//
protected rows;

/**
 * Phalcon\Db\ResultInterface or false for empty resultset
 */
protected result;

```

## Methods
```php
public function __construct( mixed $result, AdapterInterface $cache = null ): void;
```
Phalcon\Mvc\Model\Resultset constructor

@param \Phalcon\Db\ResultInterface|false result


```php
final public function count(): int;
```
Counts how many rows are in the resultset


```php
public function delete( Closure $conditionCallback = null ): bool;
```
Deletes every record in the resultset


```php
public function filter( callable $filter ): ModelInterface[];
```
Filters a resultset returning only those the developer requires

```php
$filtered = $robots->filter(
    function ($robot) {
        if ($robot->id < 3) {
            return $robot;
        }
    }
);
```


```php
public function getCache(): AdapterInterface;
```
Returns the associated cache for the resultset


```php
public function getFirst(): ModelInterface | null;
```
Get first row in the resultset


```php
public function getHydrateMode(): int;
```
Returns the current hydration mode


```php
public function getLast(): ModelInterface | null;
```
Get last row in the resultset


```php
public function getMessages(): MessageInterface[];
```
Returns the error messages produced by a batch operation


```php
public function getType(): int;
```
Returns the internal type of data retrieval that the resultset is using


```php
public function isFresh(): bool;
```
Tell if the resultset if fresh or an old one cached


```php
public function jsonSerialize(): array;
```
Returns serialised model objects as array for json_encode.
Calls jsonSerialize on each object if present

```php
$robots = Robots::find();

echo json_encode($robots);
```


```php
public function key(): int | null;
```
Gets pointer number of active row in the resultset


```php
public function next(): void;
```
Moves cursor to next row in the resultset


```php
public function offsetExists( mixed $index ): bool;
```
Checks whether offset exists in the resultset


```php
public function offsetGet( mixed $index ): ModelInterface | bool;
```
Gets row in a specific position of the resultset


```php
public function offsetSet( mixed $index, mixed $value ): void;
```
Resultsets cannot be changed. It has only been implemented to meet the definition of the ArrayAccess interface

@param int index
@param \Phalcon\Mvc\ModelInterface value


```php
public function offsetUnset( mixed $offset ): void;
```
Resultsets cannot be changed. It has only been implemented to meet the definition of the ArrayAccess interface


```php
final public function rewind(): void;
```
Rewinds resultset to its beginning


```php
final public function seek( mixed $position ): void;
```
Changes the internal pointer to a specific position in the resultset.
Set the new position if required, and then set this->row


```php
public function setHydrateMode( int $hydrateMode ): ResultsetInterface;
```
Sets the hydration mode in the resultset


```php
public function setIsFresh( bool $isFresh ): ResultsetInterface;
```
Set if the resultset is fresh or an old one cached


```php
public function update( mixed $data, Closure $conditionCallback = null ): bool;
```
Updates every record in the resultset

@param array data


```php
public function valid(): bool;
```
Check whether internal resource has rows to fetch



        
<h1 id="mvc-model-resultset-complex">Class Phalcon\Mvc\Model\Resultset\Complex</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/model/resultset/complex.zep)

| Namespace  | Phalcon\Mvc\Model\Resultset |
| Uses       | Phalcon\Mvc\Model, Phalcon\Mvc\Model\Row, Phalcon\Db\ResultInterface, Phalcon\Mvc\Model\Resultset, Phalcon\Mvc\Model\Exception, Phalcon\Mvc\Model\ResultsetInterface, Phalcon\Di\DiInterface, Phalcon\Di, Phalcon\Cache\Adapter\AdapterInterface, Phalcon\Storage\Serializer\SerializerInterface, stdClass |
| Extends    | Resultset |
| Implements | ResultsetInterface |

Phalcon\Mvc\Model\Resultset\Complex

Complex resultsets may include complete objects and scalar values.
This class builds every complex row as it is required


## Properties
```php
//
protected columnTypes;

/**
 * Unserialised result-set hydrated all rows already. unserialise() sets
 * disableHydration to true
 */
protected disableHydration = false;

```

## Methods
```php
public function __construct( mixed $columnTypes, ResultInterface $result = null, AdapterInterface $cache = null ): void;
```
Phalcon\Mvc\Model\Resultset\Complex constructor

@param array columnTypes


```php
final public function current(): ModelInterface | bool;
```
Returns current row in the resultset


```php
public function serialize(): string;
```
Serializing a resultset will dump all related rows into a big array


```php
public function toArray(): array;
```
Returns a complete resultset as an array, if the resultset has a big
number of rows it could consume more memory than currently it does.


```php
public function unserialize( mixed $data ): void;
```
Unserializing a resultset will allow to only works on the rows present in the saved state



        
<h1 id="mvc-model-resultset-simple">Class Phalcon\Mvc\Model\Resultset\Simple</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/model/resultset/simple.zep)

| Namespace  | Phalcon\Mvc\Model\Resultset |
| Uses       | Phalcon\Di, Phalcon\Di\DiInterface, Phalcon\Mvc\Model, Phalcon\Mvc\Model\Exception, Phalcon\Mvc\Model\Resultset, Phalcon\Cache\Adapter\AdapterInterface, Phalcon\Storage\Serializer\SerializerInterface |
| Extends    | Resultset |

Phalcon\Mvc\Model\Resultset\Simple

Simple resultsets only contains a complete objects
This class builds every complete object as it is required


## Properties
```php
//
protected columnMap;

//
protected model;

/**
 * @var bool
 */
protected keepSnapshots = false;

```

## Methods
```php
public function __construct( mixed $columnMap, mixed $model, mixed $result, AdapterInterface $cache = null, bool $keepSnapshots = null ): void;
```
Phalcon\Mvc\Model\Resultset\Simple constructor

@param array                                             columnMap
@param \Phalcon\Mvc\ModelInterface|Phalcon\Mvc\Model\Row model


```php
final public function current(): ModelInterface | null;
```
Returns current row in the resultset


```php
public function serialize(): string;
```
Serializing a resultset will dump all related rows into a big array


```php
public function toArray( bool $renameColumns = bool ): array;
```
Returns a complete resultset as an array, if the resultset has a big
number of rows it could consume more memory than currently it does.
Export the resultset to an array couldn't be faster with a large number
of records


```php
public function unserialize( mixed $data ): void;
```
Unserializing a resultset will allow to only works on the rows present in
the saved state



        
<h1 id="mvc-model-resultsetinterface">Interface Phalcon\Mvc\Model\ResultsetInterface</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/model/resultsetinterface.zep)

| Namespace  | Phalcon\Mvc\Model |
| Uses       | Closure, Phalcon\Messages\MessageInterface, Phalcon\Mvc\ModelInterface, Phalcon\Cache\Adapter\AdapterInterface |

Phalcon\Mvc\Model\ResultsetInterface

Interface for Phalcon\Mvc\Model\Resultset


## Methods
```php
public function delete( Closure $conditionCallback = null ): bool;
```
Deletes every record in the resultset


```php
public function filter( callable $filter ): ModelInterface[];
```
Filters a resultset returning only those the developer requires

```php
$filtered = $robots->filter(
    function ($robot) {
        if ($robot->id < 3) {
            return $robot;
        }
    }
);
```


```php
public function getCache(): AdapterInterface;
```
Returns the associated cache for the resultset


```php
public function getFirst(): ModelInterface | null;
```
Get first row in the resultset


```php
public function getHydrateMode(): int;
```
Returns the current hydration mode


```php
public function getLast(): ModelInterface | null;
```
Get last row in the resultset


```php
public function getMessages(): MessageInterface[];
```
Returns the error messages produced by a batch operation


```php
public function getType(): int;
```
Returns the internal type of data retrieval that the resultset is using


```php
public function isFresh(): bool;
```
Tell if the resultset if fresh or an old one cached


```php
public function setHydrateMode( int $hydrateMode ): ResultsetInterface;
```
Sets the hydration mode in the resultset


```php
public function setIsFresh( bool $isFresh ): ResultsetInterface;
```
Set if the resultset is fresh or an old one cached


```php
public function toArray(): array;
```
Returns a complete resultset as an array, if the resultset has a big number of rows
it could consume more memory than currently it does.


```php
public function update( mixed $data, Closure $conditionCallback = null ): bool;
```
Updates every record in the resultset

@param array data



        
<h1 id="mvc-model-row">Class Phalcon\Mvc\Model\Row</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/model/row.zep)

| Namespace  | Phalcon\Mvc\Model |
| Uses       | ArrayAccess, JsonSerializable, Phalcon\Mvc\ModelInterface, Phalcon\Mvc\EntityInterface, Phalcon\Mvc\Model\Exception, Phalcon\Mvc\Model\ResultInterface |
| Implements | EntityInterface, ResultInterface, ArrayAccess, JsonSerializable |

Phalcon\Mvc\Model\Row

This component allows Phalcon\Mvc\Model to return rows without an associated entity.
This objects implements the ArrayAccess interface to allow access the object as object->x or array[x].


## Methods
```php
public function jsonSerialize(): array;
```
   Serializes the object for json_encode
   

```php
public function offsetExists( mixed $index ): bool;
```
Checks whether offset exists in the row

@param string|int $index


```php
public function offsetGet( mixed $index ): mixed;
```
Gets a record in a specific position of the row

@param string|int index

@return string|Phalcon\Mvc\ModelInterface


```php
public function offsetSet( mixed $index, mixed $value ): void;
```
Rows cannot be changed. It has only been implemented to meet the definition of the ArrayAccess interface

@param string|int index
@param \Phalcon\Mvc\ModelInterface value


```php
public function offsetUnset( mixed $offset ): void;
```
Rows cannot be changed. It has only been implemented to meet the definition of the ArrayAccess interface

@param string|int offset


```php
public function readAttribute( string $attribute );
```
Reads an attribute value by its name

```php
echo $robot->readAttribute("name");
```

@return mixed


```php
public function setDirtyState( int $dirtyState ): ModelInterface | bool;
```
Set the current object's state


```php
public function toArray(): array;
```
Returns the instance as an array representation


```php
public function writeAttribute( string $attribute, mixed $value ): void;
```
Writes an attribute value by its name

```php
$robot->writeAttribute("name", "Rosey");
```

@param mixed value



        
<h1 id="mvc-model-transaction">Class Phalcon\Mvc\Model\Transaction</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/model/transaction.zep)

| Namespace  | Phalcon\Mvc\Model |
| Uses       | Phalcon\Di\DiInterface, Phalcon\Mvc\ModelInterface, Phalcon\Mvc\Model\Transaction\Failed, Phalcon\Mvc\Model\Transaction\ManagerInterface, Phalcon\Mvc\Model\TransactionInterface |
| Implements | TransactionInterface |

Phalcon\Mvc\Model\Transaction

Transactions are protective blocks where SQL statements are only permanent if
they can all succeed as one atomic action. Phalcon\Transaction is intended to
be used with Phalcon_Model_Base. Phalcon Transactions should be created using
Phalcon\Transaction\Manager.

```php
use Phalcon\Mvc\Model\Transaction\Failed;
use Phalcon\Mvc\Model\Transaction\Manager;

try {
    $manager = new Manager();

    $transaction = $manager->get();

    $robot = new Robots();

    $robot->setTransaction($transaction);

    $robot->name       = "WALL·E";
    $robot->created_at = date("Y-m-d");

    if ($robot->save() === false) {
        $transaction->rollback("Can't save robot");
    }

    $robotPart = new RobotParts();

    $robotPart->setTransaction($transaction);

    $robotPart->type = "head";

    if ($robotPart->save() === false) {
        $transaction->rollback("Can't save robot part");
    }

    $transaction->commit();
} catch(Failed $e) {
    echo "Failed, reason: ", $e->getMessage();
}
```


## Properties
```php
//
protected activeTransaction = false;

//
protected connection;

//
protected isNewTransaction = true;

//
protected manager;

//
protected messages;

//
protected rollbackRecord;

//
protected rollbackOnAbort = false;

//
protected rollbackThrowException = false;

```

## Methods
```php
public function __construct( DiInterface $container, bool $autoBegin = bool, string $service = string ): void;
```
Phalcon\Mvc\Model\Transaction constructor


```php
public function begin(): bool;
```
Starts the transaction


```php
public function commit(): bool;
```
Commits the transaction


```php
public function getConnection(): \Phalcon\Db\Adapter\AdapterInterface;
```
Returns the connection related to transaction


```php
public function getMessages(): array;
```
Returns validations messages from last save try


```php
public function isManaged(): bool;
```
Checks whether transaction is managed by a transaction manager


```php
public function isValid(): bool;
```
Checks whether internal connection is under an active transaction


```php
public function rollback( string $rollbackMessage = null, ModelInterface $rollbackRecord = null ): bool;
```
Rollbacks the transaction


```php
public function setIsNewTransaction( bool $isNew ): void;
```
Sets if is a reused transaction or new once


```php
public function setRollbackOnAbort( bool $rollbackOnAbort ): void;
```
Sets flag to rollback on abort the HTTP connection


```php
public function setRollbackedRecord( ModelInterface $record ): void;
```
Sets object which generates rollback action


```php
public function setTransactionManager( ManagerInterface $manager ): void;
```
Sets transaction manager related to the transaction


```php
public function throwRollbackException( bool $status ): TransactionInterface;
```
Enables throwing exception



        
<h1 id="mvc-model-transaction-exception">Class Phalcon\Mvc\Model\Transaction\Exception</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/model/transaction/exception.zep)

| Namespace  | Phalcon\Mvc\Model\Transaction |
| Extends    | \Phalcon\Mvc\Model\Exception |

Phalcon\Mvc\Model\Transaction\Exception

Exceptions thrown in Phalcon\Mvc\Model\Transaction will use this class


        
<h1 id="mvc-model-transaction-failed">Class Phalcon\Mvc\Model\Transaction\Failed</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/model/transaction/failed.zep)

| Namespace  | Phalcon\Mvc\Model\Transaction |
| Uses       | Phalcon\Messages\MessageInterface, Phalcon\Mvc\ModelInterface, Phalcon\Mvc\Model\Transaction\Exception |
| Extends    | Exception |

Phalcon\Mvc\Model\Transaction\Failed

This class will be thrown to exit a try/catch block for isolated transactions


## Properties
```php
//
protected record;

```

## Methods
```php
public function __construct( string $message, ModelInterface $record = null ): void;
```
Phalcon\Mvc\Model\Transaction\Failed constructor


```php
public function getRecord(): ModelInterface;
```
Returns validation record messages which stop the transaction


```php
public function getRecordMessages(): MessageInterface[];
```
Returns validation record messages which stop the transaction



        
<h1 id="mvc-model-transaction-manager">Class Phalcon\Mvc\Model\Transaction\Manager</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/model/transaction/manager.zep)

| Namespace  | Phalcon\Mvc\Model\Transaction |
| Uses       | Phalcon\Di, Phalcon\Di\DiInterface, Phalcon\Di\InjectionAwareInterface, Phalcon\Mvc\Model\Transaction\ManagerInterface, Phalcon\Mvc\Model\Transaction\Exception, Phalcon\Mvc\Model\Transaction, Phalcon\Mvc\Model\TransactionInterface |
| Implements | ManagerInterface, InjectionAwareInterface |

Phalcon\Mvc\Model\Transaction\Manager

A transaction acts on a single database connection. If you have multiple
class-specific databases, the transaction will not protect interaction among
them.

This class manages the objects that compose a transaction.
A transaction produces a unique connection that is passed to every object
part of the transaction.

```php
use Phalcon\Mvc\Model\Transaction\Failed;
use Phalcon\Mvc\Model\Transaction\Manager;

try {
   $transactionManager = new Manager();

   $transaction = $transactionManager->get();

   $robot = new Robots();

   $robot->setTransaction($transaction);

   $robot->name       = "WALL·E";
   $robot->created_at = date("Y-m-d");

   if ($robot->save() === false) {
       $transaction->rollback("Can't save robot");
   }

   $robotPart = new RobotParts();

   $robotPart->setTransaction($transaction);

   $robotPart->type = "head";

   if ($robotPart->save() === false) {
       $transaction->rollback("Can't save robot part");
   }

   $transaction->commit();
} catch (Failed $e) {
   echo "Failed, reason: ", $e->getMessage();
}
```


## Properties
```php
//
protected container;

//
protected initialized = false;

//
protected number = 0;

//
protected rollbackPendent = true;

//
protected service = db;

/**
 * @var array
 */
protected transactions;

```

## Methods
```php
public function __construct( DiInterface $container = null ): void;
```
Phalcon\Mvc\Model\Transaction\Manager constructor


```php
public function collectTransactions(): void;
```
Remove all the transactions from the manager


```php
public function commit();
```
Commits active transactions within the manager


```php
public function get( bool $autoBegin = bool ): TransactionInterface;
```
Returns a new \Phalcon\Mvc\Model\Transaction or an already created once
This method registers a shutdown function to rollback active connections


```php
public function getDI(): DiInterface;
```
Returns the dependency injection container


```php
public function getDbService(): string;
```
Returns the database service used to isolate the transaction


```php
public function getOrCreateTransaction( bool $autoBegin = bool ): TransactionInterface;
```
Create/Returns a new transaction or an existing one


```php
public function getRollbackPendent(): bool;
```
Check if the transaction manager is registering a shutdown function to
clean up pendent transactions


```php
public function has(): bool;
```
Checks whether the manager has an active transaction


```php
public function notifyCommit( TransactionInterface $transaction ): void;
```
Notifies the manager about a committed transaction


```php
public function notifyRollback( TransactionInterface $transaction ): void;
```
Notifies the manager about a rollbacked transaction


```php
public function rollback( bool $collect = bool ): void;
```
Rollbacks active transactions within the manager
Collect will remove the transaction from the manager


```php
public function rollbackPendent(): void;
```
Rollbacks active transactions within the manager


```php
public function setDI( DiInterface $container ): void;
```
Sets the dependency injection container


```php
public function setDbService( string $service ): ManagerInterface;
```
Sets the database service used to run the isolated transactions


```php
public function setRollbackPendent( bool $rollbackPendent ): ManagerInterface;
```
Set if the transaction manager must register a shutdown function to clean
up pendent transactions


```php
protected function collectTransaction( TransactionInterface $transaction ): void;
```
Removes transactions from the TransactionManager



        
<h1 id="mvc-model-transaction-managerinterface">Interface Phalcon\Mvc\Model\Transaction\ManagerInterface</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/model/transaction/managerinterface.zep)

| Namespace  | Phalcon\Mvc\Model\Transaction |
| Uses       | Phalcon\Mvc\Model\TransactionInterface |

Phalcon\Mvc\Model\Transaction\ManagerInterface

Interface for Phalcon\Mvc\Model\Transaction\Manager


## Methods
```php
public function collectTransactions(): void;
```
Remove all the transactions from the manager


```php
public function commit();
```
Commits active transactions within the manager


```php
public function get( bool $autoBegin = bool ): TransactionInterface;
```
Returns a new \Phalcon\Mvc\Model\Transaction or an already created once


```php
public function getDbService(): string;
```
Returns the database service used to isolate the transaction


```php
public function getRollbackPendent(): bool;
```
Check if the transaction manager is registering a shutdown function to clean up pendent transactions


```php
public function has(): bool;
```
Checks whether manager has an active transaction


```php
public function notifyCommit( TransactionInterface $transaction ): void;
```
Notifies the manager about a committed transaction


```php
public function notifyRollback( TransactionInterface $transaction ): void;
```
Notifies the manager about a rollbacked transaction


```php
public function rollback( bool $collect = bool ): void;
```
Rollbacks active transactions within the manager
Collect will remove transaction from the manager


```php
public function rollbackPendent(): void;
```
Rollbacks active transactions within the manager


```php
public function setDbService( string $service ): ManagerInterface;
```
Sets the database service used to run the isolated transactions


```php
public function setRollbackPendent( bool $rollbackPendent ): ManagerInterface;
```
Set if the transaction manager must register a shutdown function to clean up pendent transactions



        
<h1 id="mvc-model-transactioninterface">Interface Phalcon\Mvc\Model\TransactionInterface</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/model/transactioninterface.zep)

| Namespace  | Phalcon\Mvc\Model |
| Uses       | Phalcon\Mvc\ModelInterface, Phalcon\Mvc\Model\Transaction\ManagerInterface |

Phalcon\Mvc\Model\TransactionInterface

Interface for Phalcon\Mvc\Model\Transaction


## Methods
```php
public function begin(): bool;
```
Starts the transaction


```php
public function commit(): bool;
```
Commits the transaction


```php
public function getConnection(): \Phalcon\Db\Adapter\AdapterInterface;
```
Returns connection related to transaction


```php
public function getMessages(): array;
```
Returns validations messages from last save try


```php
public function isManaged(): bool;
```
Checks whether transaction is managed by a transaction manager


```php
public function isValid(): bool;
```
Checks whether internal connection is under an active transaction


```php
public function rollback( string $rollbackMessage = null, ModelInterface $rollbackRecord = null ): bool;
```
Rollbacks the transaction


```php
public function setIsNewTransaction( bool $isNew ): void;
```
Sets if is a reused transaction or new once


```php
public function setRollbackOnAbort( bool $rollbackOnAbort ): void;
```
Sets flag to rollback on abort the HTTP connection


```php
public function setRollbackedRecord( ModelInterface $record ): void;
```
Sets object which generates rollback action


```php
public function setTransactionManager( ManagerInterface $manager ): void;
```
Sets transaction manager related to the transaction


```php
public function throwRollbackException( bool $status ): TransactionInterface;
```
Enables throwing exception



        
<h1 id="mvc-model-validationfailed">Class Phalcon\Mvc\Model\ValidationFailed</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/model/validationfailed.zep)

| Namespace  | Phalcon\Mvc\Model |
| Uses       | Phalcon\Mvc\ModelInterface |
| Extends    | Exception |

Phalcon\Mvc\Model\ValidationFailed

This exception is generated when a model fails to save a record
Phalcon\Mvc\Model must be set up to have this behavior


## Properties
```php
//
protected messages;

//
protected model;

```

## Methods
```php
public function __construct( ModelInterface $model, array $validationMessages ): void;
```
Phalcon\Mvc\Model\ValidationFailed constructor

@param Message[] validationMessages


```php
public function getMessages(): Message[];
```
Returns the complete group of messages produced in the validation


```php
public function getModel(): ModelInterface;
```
Returns the model that generated the messages



        
<h1 id="mvc-modelinterface">Interface Phalcon\Mvc\ModelInterface</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/modelinterface.zep)

| Namespace  | Phalcon\Mvc |
| Uses       | Phalcon\Db\Adapter\AdapterInterface, Phalcon\Di\DiInterface, Phalcon\Messages\MessageInterface, Phalcon\Mvc\Model\CriteriaInterface, Phalcon\Mvc\Model\ModelInterface, Phalcon\Mvc\Model\MetaDataInterface, Phalcon\Mvc\Model\ResultsetInterface, Phalcon\Mvc\Model\TransactionInterface, Phalcon\Mvc\ModelInterface |

Phalcon\Mvc\ModelInterface

Interface for Phalcon\Mvc\Model


## Methods
```php
public function appendMessage( MessageInterface $message ): ModelInterface;
```
Appends a customized message on the validation process


```php
public function assign( array $data, mixed $dataColumnMap = null, mixed $whiteList = null ): ModelInterface;
```
Assigns values to a model from an array

@param array columnMap


```php
public function create(): bool;
```
Inserts a model instance. If the instance already exists in the
persistence it will throw an exception. Returning true on success or
false otherwise.


```php
public function delete(): bool;
```
Deletes a model instance. Returning true on success or false otherwise.


```php
public function fireEvent( string $eventName ): bool;
```
Fires an event, implicitly calls behaviors and listeners in the events
manager are notified


```php
public function fireEventCancel( string $eventName ): bool;
```
Fires an event, implicitly calls behaviors and listeners in the events
manager are notified. This method stops if one of the callbacks/listeners
returns bool false


```php
public function getDirtyState(): int;
```
Returns one of the DIRTY_STATE_* constants telling if the record exists
in the database or not


```php
public function getMessages(): MessageInterface[];
```
Returns array of validation messages


```php
public function getModelsMetaData(): MetaDataInterface;
```
Returns the models meta-data service related to the entity instance.


```php
public function getOperationMade(): int;
```
Returns the type of the latest operation performed by the ORM
Returns one of the OP_* class constants


```php
public function getReadConnection(): AdapterInterface;
```
Gets internal database connection


```php
public function getReadConnectionService(): string;
```
Returns DependencyInjection connection service used to read data


```php
public function getRelated( string $alias, mixed $arguments = null );
```
Returns related records based on defined relations

@param array arguments
@return \Phalcon\Mvc\Model\Resultset\Simple|Phalcon\Mvc\Model\Resultset\Simple|false


```php
public function getSchema(): string;
```
Returns schema name where table mapped is located


```php
public function getSource(): string;
```
Returns table name mapped in the model


```php
public function getWriteConnection(): AdapterInterface;
```
Gets internal database connection


```php
public function getWriteConnectionService(): string;
```
Returns DependencyInjection connection service used to write data


```php
public function refresh(): ModelInterface;
```
Refreshes the model attributes re-querying the record from the database


```php
public function save(): bool;
```
Inserts or updates a model instance. Returning true on success or false
otherwise.


```php
public function setConnectionService( string $connectionService ): void;
```
Sets both read/write connection services


```php
public function setDirtyState( int $dirtyState ): ModelInterface | bool;
```
Sets the dirty state of the object using one of the DIRTY_STATE_*
constants


```php
public function setReadConnectionService( string $connectionService ): void;
```
Sets the DependencyInjection connection service used to read data


```php
public function setSnapshotData( array $data, mixed $columnMap = null ): void;
```
Sets the record's snapshot data. This method is used internally to set
snapshot data when the model was set up to keep snapshot data

@param array columnMap


```php
public function setTransaction( TransactionInterface $transaction ): ModelInterface;
```
Sets a transaction related to the Model instance


```php
public function setWriteConnectionService( string $connectionService ): void;
```
Sets the DependencyInjection connection service used to write data


```php
public function skipOperation( bool $skip ): void;
```
Skips the current operation forcing a success state


```php
public function update(): bool;
```
Updates a model instance. If the instance doesn't exist in the
persistence it will throw an exception. Returning true on success or
false otherwise.


```php
public function validationHasFailed(): bool;
```
Check whether validation process has generated any messages



        
<h1 id="mvc-moduledefinitioninterface">Interface Phalcon\Mvc\ModuleDefinitionInterface</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/moduledefinitioninterface.zep)

| Namespace  | Phalcon\Mvc |
| Uses       | Phalcon\Di\DiInterface |

Phalcon\Mvc\ModuleDefinitionInterface

This interface must be implemented by class module definitions


## Methods
```php
public function registerAutoloaders( DiInterface $container = null );
```
Registers an autoloader related to the module


```php
public function registerServices( DiInterface $container );
```
Registers services related to the module



        
<h1 id="mvc-router">Class Phalcon\Mvc\Router</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/router.zep)

| Namespace  | Phalcon\Mvc |
| Uses       | Phalcon\Di\DiInterface, Phalcon\Di\AbstractInjectionAware, Phalcon\Events\EventsAwareInterface, Phalcon\Events\ManagerInterface, Phalcon\Http\RequestInterface, Phalcon\Mvc\Router\Exception, Phalcon\Mvc\Router\GroupInterface, Phalcon\Mvc\Router\Route, Phalcon\Mvc\Router\RouteInterface |
| Extends    | AbstractInjectionAware |
| Implements | RouterInterface, EventsAwareInterface |

Phalcon\Mvc\Router

Phalcon\Mvc\Router is the standard framework router. Routing is the
process of taking a URI endpoint (that part of the URI which comes after the
base URL) and decomposing it into parameters to determine which module,
controller, and action of that controller should receive the request

```php
use Phalcon\Mvc\Router;

$router = new Router();

$router->add(
    "/documentation/{chapter}/{name}\.{type:[a-z]+}",
    [
        "controller" => "documentation",
        "action"     => "show",
    ]
);

$router->handle(
    "/documentation/1/examples.html"
);

echo $router->getControllerName();
```


## Constants
```php
const POSITION_FIRST = 0;
const POSITION_LAST = 1;
```

## Properties
```php
//
protected action;

//
protected controller;

//
protected defaultAction;

//
protected defaultController;

//
protected defaultModule;

//
protected defaultNamespace;

//
protected defaultParams;

//
protected eventsManager;

//
protected keyRouteNames;

//
protected keyRouteIds;

//
protected matchedRoute;

//
protected matches;

//
protected module;

//
protected namespaceName;

//
protected notFoundPaths;

//
protected params;

//
protected removeExtraSlashes;

//
protected routes;

//
protected uriSource;

//
protected wasMatched = false;

```

## Methods
```php
public function __construct( bool $defaultRoutes = bool );
```
Phalcon\Mvc\Router constructor


```php
public function add( string $pattern, mixed $paths = null, mixed $httpMethods = null, mixed $position = static-constant-access ): RouteInterface;
```
Adds a route to the router without any HTTP constraint

```php
use Phalcon\Mvc\Router;

$router->add("/about", "About::index");

$router->add(
    "/about",
    "About::index",
    ["GET", "POST"]
);

$router->add(
    "/about",
    "About::index",
    ["GET", "POST"],
    Router::POSITION_FIRST
);
```


```php
public function addConnect( string $pattern, mixed $paths = null, mixed $position = static-constant-access ): RouteInterface;
```
Adds a route to the router that only match if the HTTP method is CONNECT


```php
public function addDelete( string $pattern, mixed $paths = null, mixed $position = static-constant-access ): RouteInterface;
```
Adds a route to the router that only match if the HTTP method is DELETE


```php
public function addGet( string $pattern, mixed $paths = null, mixed $position = static-constant-access ): RouteInterface;
```
Adds a route to the router that only match if the HTTP method is GET


```php
public function addHead( string $pattern, mixed $paths = null, mixed $position = static-constant-access ): RouteInterface;
```
Adds a route to the router that only match if the HTTP method is HEAD


```php
public function addOptions( string $pattern, mixed $paths = null, mixed $position = static-constant-access ): RouteInterface;
```
Add a route to the router that only match if the HTTP method is OPTIONS


```php
public function addPatch( string $pattern, mixed $paths = null, mixed $position = static-constant-access ): RouteInterface;
```
Adds a route to the router that only match if the HTTP method is PATCH


```php
public function addPost( string $pattern, mixed $paths = null, mixed $position = static-constant-access ): RouteInterface;
```
Adds a route to the router that only match if the HTTP method is POST


```php
public function addPurge( string $pattern, mixed $paths = null, mixed $position = static-constant-access ): RouteInterface;
```
Adds a route to the router that only match if the HTTP method is PURGE
(Squid and Varnish support)


```php
public function addPut( string $pattern, mixed $paths = null, mixed $position = static-constant-access ): RouteInterface;
```
Adds a route to the router that only match if the HTTP method is PUT


```php
public function addTrace( string $pattern, mixed $paths = null, mixed $position = static-constant-access ): RouteInterface;
```
Adds a route to the router that only match if the HTTP method is TRACE


```php
public function attach( RouteInterface $route, mixed $position = static-constant-access ): RouterInterface;
```
Attach Route object to the routes stack.

```php
use Phalcon\Mvc\Router;
use Phalcon\Mvc\Router\Route;

class CustomRoute extends Route {
     // ...
}

$router = new Router();

$router->attach(
    new CustomRoute("/about", "About::index", ["GET", "HEAD"]),
    Router::POSITION_FIRST
);
```


```php
public function clear(): void;
```
Removes all the pre-defined routes


```php
public function getActionName(): string;
```
Returns the processed action name


```php
public function getControllerName(): string;
```
Returns the processed controller name


```php
public function getDefaults(): array;
```
Returns an array of default parameters


```php
public function getEventsManager(): ManagerInterface;
```
Returns the internal event manager


```php
public function getKeyRouteIds()
```


```php
public function getKeyRouteNames()
```


```php
public function getMatchedRoute(): RouteInterface;
```
Returns the route that matches the handled URI


```php
public function getMatches(): array;
```
Returns the sub expressions in the regular expression matched


```php
public function getModuleName(): string;
```
Returns the processed module name


```php
public function getNamespaceName(): string;
```
Returns the processed namespace name


```php
public function getParams(): array;
```
Returns the processed parameters


```php
public function getRouteById( mixed $id ): RouteInterface | bool;
```
Returns a route object by its id


```php
public function getRouteByName( string $name ): RouteInterface | bool;
```
Returns a route object by its name


```php
public function getRoutes(): RouteInterface[];
```
Returns all the routes defined in the router


```php
public function handle( string $uri );
```
Handles routing information received from the rewrite engine

```php
// Passing a URL
$router->handle("/posts/edit/1");
```


```php
public function isExactControllerName(): bool;
```
Returns whether controller name should not be mangled


```php
public function mount( GroupInterface $group ): RouterInterface;
```
Mounts a group of routes in the router


```php
public function notFound( mixed $paths ): RouterInterface;
```
Set a group of paths to be returned when none of the defined routes are
matched


```php
public function removeExtraSlashes( bool $remove ): RouterInterface;
```
Set whether router must remove the extra slashes in the handled routes


```php
public function setDefaultAction( string $actionName ): RouterInterface;
```
Sets the default action name


```php
public function setDefaultController( string $controllerName ): RouterInterface;
```
Sets the default controller name


```php
public function setDefaultModule( string $moduleName ): RouterInterface;
```
Sets the name of the default module


```php
public function setDefaultNamespace( string $namespaceName ): RouterInterface;
```
Sets the name of the default namespace


```php
public function setDefaults( array $defaults ): RouterInterface;
```
Sets an array of default paths. If a route is missing a path the router
will use the defined here. This method must not be used to set a 404
route

```php
$router->setDefaults(
    [
        "module" => "common",
        "action" => "index",
    ]
);
```


```php
public function setEventsManager( ManagerInterface $eventsManager ): void;
```
Sets the events manager


```php
public function setKeyRouteIds( $keyRouteIds )
```


```php
public function setKeyRouteNames( $keyRouteNames )
```


```php
public function wasMatched(): bool;
```
Checks if the router matches any of the defined routes



        
<h1 id="mvc-router-annotations">Class Phalcon\Mvc\Router\Annotations</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/router/annotations.zep)

| Namespace  | Phalcon\Mvc\Router |
| Uses       | Phalcon\Di\DiInterface, Phalcon\Mvc\Router, Phalcon\Annotations\Annotation, Phalcon\Mvc\Router\Exception |
| Extends    | Router |

Phalcon\Mvc\Router\Annotations

A router that reads routes annotations from classes/resources

```php
use Phalcon\Mvc\Router\Annotations;

$di->setShared(
    "router",
    function() {
        // Use the annotations router
        $router = new Annotations(false);

        // This will do the same as above but only if the handled uri starts with /robots
        $router->addResource("Robots", "/robots");

        return $router;
    }
);
```


## Properties
```php
//
protected actionSuffix = Action;

//
protected controllerSuffix = Controller;

//
protected handlers;

//
protected routePrefix;

```

## Methods
```php
public function addModuleResource( string $module, string $handler, string $prefix = null ): Annotations;
```
Adds a resource to the annotations handler
A resource is a class that contains routing annotations
The class is located in a module


```php
public function addResource( string $handler, string $prefix = null ): Annotations;
```
Adds a resource to the annotations handler
A resource is a class that contains routing annotations


```php
public function getResources(): array;
```
Return the registered resources


```php
public function handle( string $uri );
```
Produce the routing parameters from the rewrite information


```php
public function processActionAnnotation( string $module, string $namespaceName, string $controller, string $action, Annotation $annotation );
```
Checks for annotations in the public methods of the controller


```php
public function processControllerAnnotation( string $handler, Annotation $annotation );
```
Checks for annotations in the controller docblock


```php
public function setActionSuffix( string $actionSuffix );
```
Changes the action method suffix


```php
public function setControllerSuffix( string $controllerSuffix );
```
Changes the controller class suffix



        
<h1 id="mvc-router-exception">Class Phalcon\Mvc\Router\Exception</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/router/exception.zep)

| Namespace  | Phalcon\Mvc\Router |
| Extends    | \Phalcon\Exception |

Phalcon\Mvc\Router\Exception

Exceptions thrown in Phalcon\Mvc\Router will use this class


        
<h1 id="mvc-router-group">Class Phalcon\Mvc\Router\Group</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/router/group.zep)

| Namespace  | Phalcon\Mvc\Router |
| Implements | GroupInterface |

Phalcon\Mvc\Router\Group

Helper class to create a group of routes with common attributes

```php
$router = new \Phalcon\Mvc\Router();

//Create a group with a common module and controller
$blog = new Group(
    [
        "module"     => "blog",
        "controller" => "index",
    ]
);

//All the routes start with /blog
$blog->setPrefix("/blog");

//Add a route to the group
$blog->add(
    "/save",
    [
        "action" => "save",
    ]
);

//Add another route to the group
$blog->add(
    "/edit/{id}",
    [
        "action" => "edit",
    ]
);

//This route maps to a controller different than the default
$blog->add(
    "/blog",
    [
        "controller" => "about",
        "action"     => "index",
    ]
);

//Add the group to the router
$router->mount($blog);
```


## Properties
```php
//
protected beforeMatch;

//
protected hostname;

//
protected paths;

//
protected prefix;

//
protected routes;

```

## Methods
```php
public function __construct( mixed $paths = null );
```
Phalcon\Mvc\Router\Group constructor


```php
public function add( string $pattern, mixed $paths = null, mixed $httpMethods = null ): RouteInterface;
```
Adds a route to the router on any HTTP method

```php
$router->add("/about", "About::index");
```


```php
public function addConnect( string $pattern, mixed $paths = null ): RouteInterface;
```
Adds a route to the router that only match if the HTTP method is CONNECT

@param string|array paths


```php
public function addDelete( string $pattern, mixed $paths = null ): RouteInterface;
```
Adds a route to the router that only match if the HTTP method is DELETE

@param string|array paths


```php
public function addGet( string $pattern, mixed $paths = null ): RouteInterface;
```
Adds a route to the router that only match if the HTTP method is GET

@param string|array paths


```php
public function addHead( string $pattern, mixed $paths = null ): RouteInterface;
```
Adds a route to the router that only match if the HTTP method is HEAD

@param string|array paths


```php
public function addOptions( string $pattern, mixed $paths = null ): RouteInterface;
```
Add a route to the router that only match if the HTTP method is OPTIONS

@param string|array paths


```php
public function addPatch( string $pattern, mixed $paths = null ): RouteInterface;
```
Adds a route to the router that only match if the HTTP method is PATCH

@param string|array paths


```php
public function addPost( string $pattern, mixed $paths = null ): RouteInterface;
```
Adds a route to the router that only match if the HTTP method is POST

@param string|array paths


```php
public function addPurge( string $pattern, mixed $paths = null ): RouteInterface;
```
Adds a route to the router that only match if the HTTP method is PURGE

@param string|array paths


```php
public function addPut( string $pattern, mixed $paths = null ): RouteInterface;
```
Adds a route to the router that only match if the HTTP method is PUT

@param string|array paths


```php
public function addTrace( string $pattern, mixed $paths = null ): RouteInterface;
```
Adds a route to the router that only match if the HTTP method is TRACE

@param string|array paths


```php
public function beforeMatch( callable $beforeMatch ): GroupInterface;
```
Sets a callback that is called if the route is matched.
The developer can implement any arbitrary conditions here
If the callback returns false the route is treated as not matched


```php
public function clear(): void;
```
Removes all the pre-defined routes


```php
public function getBeforeMatch(): callable;
```
Returns the 'before match' callback if any


```php
public function getHostname(): string;
```
Returns the hostname restriction


```php
public function getPaths(): array | string;
```
Returns the common paths defined for this group


```php
public function getPrefix(): string;
```
Returns the common prefix for all the routes


```php
public function getRoutes(): RouteInterface[];
```
Returns the routes added to the group


```php
public function setHostname( string $hostname ): GroupInterface;
```
Set a hostname restriction for all the routes in the group


```php
public function setPaths( mixed $paths ): GroupInterface;
```
Set common paths for all the routes in the group


```php
public function setPrefix( string $prefix ): GroupInterface;
```
Set a common uri prefix for all the routes in this group


```php
protected function addRoute( string $pattern, mixed $paths = null, mixed $httpMethods = null ): RouteInterface;
```
Adds a route applying the common attributes



        
<h1 id="mvc-router-groupinterface">Interface Phalcon\Mvc\Router\GroupInterface</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/router/groupinterface.zep)

| Namespace  | Phalcon\Mvc\Router |
| Uses       | Phalcon\Mvc\Router\RouteInterface |

Phalcon\Mvc\Router\GroupInterface

```php
$router = new \Phalcon\Mvc\Router();

// Create a group with a common module and controller
$blog = new Group(
    [
        "module"     => "blog",
        "controller" => "index",
    ]
);

// All the routes start with /blog
$blog->setPrefix("/blog");

// Add a route to the group
$blog->add(
    "/save",
    [
        "action" => "save",
    ]
);

// Add another route to the group
$blog->add(
    "/edit/{id}",
    [
        "action" => "edit",
    ]
);

// This route maps to a controller different than the default
$blog->add(
    "/blog",
    [
        "controller" => "about",
        "action"     => "index",
    ]
);

// Add the group to the router
$router->mount($blog);
```


## Methods
```php
public function add( string $pattern, mixed $paths = null, mixed $httpMethods = null ): RouteInterface;
```
Adds a route to the router on any HTTP method

```php
router->add("/about", "About::index");
```


```php
public function addConnect( string $pattern, mixed $paths = null ): RouteInterface;
```
Adds a route to the router that only match if the HTTP method is CONNECT


```php
public function addDelete( string $pattern, mixed $paths = null ): RouteInterface;
```
Adds a route to the router that only match if the HTTP method is DELETE


```php
public function addGet( string $pattern, mixed $paths = null ): RouteInterface;
```
Adds a route to the router that only match if the HTTP method is GET


```php
public function addHead( string $pattern, mixed $paths = null ): RouteInterface;
```
Adds a route to the router that only match if the HTTP method is HEAD


```php
public function addOptions( string $pattern, mixed $paths = null ): RouteInterface;
```
Add a route to the router that only match if the HTTP method is OPTIONS


```php
public function addPatch( string $pattern, mixed $paths = null ): RouteInterface;
```
Adds a route to the router that only match if the HTTP method is PATCH


```php
public function addPost( string $pattern, mixed $paths = null ): RouteInterface;
```
Adds a route to the router that only match if the HTTP method is POST


```php
public function addPurge( string $pattern, mixed $paths = null ): RouteInterface;
```
Adds a route to the router that only match if the HTTP method is PURGE


```php
public function addPut( string $pattern, mixed $paths = null ): RouteInterface;
```
Adds a route to the router that only match if the HTTP method is PUT


```php
public function addTrace( string $pattern, mixed $paths = null ): RouteInterface;
```
Adds a route to the router that only match if the HTTP method is TRACE


```php
public function beforeMatch( callable $beforeMatch ): GroupInterface;
```
Sets a callback that is called if the route is matched.
The developer can implement any arbitrary conditions here
If the callback returns false the route is treated as not matched


```php
public function clear(): void;
```
Removes all the pre-defined routes


```php
public function getBeforeMatch(): callable;
```
Returns the 'before match' callback if any


```php
public function getHostname(): string;
```
Returns the hostname restriction


```php
public function getPaths(): array | string;
```
Returns the common paths defined for this group


```php
public function getPrefix(): string;
```
Returns the common prefix for all the routes


```php
public function getRoutes(): RouteInterface[];
```
Returns the routes added to the group


```php
public function setHostname( string $hostname ): GroupInterface;
```
Set a hostname restriction for all the routes in the group


```php
public function setPaths( mixed $paths ): GroupInterface;
```
Set common paths for all the routes in the group

@param array paths


```php
public function setPrefix( string $prefix ): GroupInterface;
```
Set a common uri prefix for all the routes in this group



        
<h1 id="mvc-router-route">Class Phalcon\Mvc\Router\Route</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/router/route.zep)

| Namespace  | Phalcon\Mvc\Router |
| Uses       | Phalcon\Mvc\Router\Exception |
| Implements | RouteInterface |

Phalcon\Mvc\Router\Route

This class represents every route added to the router


## Properties
```php
//
protected beforeMatch;

//
protected compiledPattern;

//
protected converters;

//
protected group;

//
protected hostname;

//
protected id;

//
protected methods;

//
protected match;

//
protected name;

//
protected paths;

//
protected pattern;

//
protected static uniqueId = 0;

```

## Methods
```php
public function __construct( string $pattern, mixed $paths = null, mixed $httpMethods = null );
```
Phalcon\Mvc\Router\Route constructor


```php
public function beforeMatch( mixed $callback ): RouteInterface;
```
Sets a callback that is called if the route is matched.
The developer can implement any arbitrary conditions here
If the callback returns false the route is treated as not matched

```php
$router->add(
    "/login",
    [
        "module"     => "admin",
        "controller" => "session",
    ]
)->beforeMatch(
    function ($uri, $route) {
        // Check if the request was made with Ajax
        if ($_SERVER["HTTP_X_REQUESTED_WITH"] === "xmlhttprequest") {
            return false;
        }

        return true;
    }
);
```


```php
public function compilePattern( string $pattern ): string;
```
Replaces placeholders from pattern returning a valid PCRE regular expression


```php
public function convert( string $name, mixed $converter ): RouteInterface;
```
{@inheritdoc}


```php
public function extractNamedParams( string $pattern ): array | bool;
```
Extracts parameters from a string


```php
public function getBeforeMatch(): callable;
```
Returns the 'before match' callback if any


```php
public function getCompiledPattern(): string;
```
Returns the route's compiled pattern


```php
public function getConverters(): array;
```
Returns the router converter


```php
public function getGroup(): GroupInterface | null;
```
Returns the group associated with the route


```php
public function getHostname(): string;
```
Returns the hostname restriction if any


```php
public function getHttpMethods(): array | string;
```
Returns the HTTP methods that constraint matching the route


```php
public function getId()
```


```php
public function getMatch(): callable;
```
Returns the 'match' callback if any


```php
public function getName(): string;
```
Returns the route's name


```php
public function getPaths(): array;
```
Returns the paths


```php
public function getPattern(): string;
```
Returns the route's pattern


```php
public function getReversedPaths(): array;
```
Returns the paths using positions as keys and names as values


```php
public function getRouteId(): string;
```
Returns the route's id


```php
public function match( mixed $callback ): RouteInterface;
```
Allows to set a callback to handle the request directly in the route

```php
$router->add(
    "/help",
    []
)->match(
    function () {
        return $this->getResponse()->redirect("https://support.google.com/", true);
    }
);
```


```php
public function reConfigure( string $pattern, mixed $paths = null ): void;
```
Reconfigure the route adding a new pattern and a set of paths


```php
public function setGroup( GroupInterface $group ): RouteInterface;
```
Sets the group associated with the route


```php
public function setHostname( string $hostname ): RouteInterface;
```
Sets a hostname restriction to the route

```php
$route->setHostname("localhost");
```


```php
public function setHttpMethods( mixed $httpMethods ): RouteInterface;
```
Sets a set of HTTP methods that constraint the matching of the route (alias of via)

```php
$route->setHttpMethods("GET");

$route->setHttpMethods(
    [
        "GET",
        "POST",
    ]
);
```


```php
public function setName( string $name ): RouteInterface;
```
Sets the route's name

```php
$router->add(
    "/about",
    [
        "controller" => "about",
    ]
)->setName("about");
```


```php
public function via( mixed $httpMethods ): RouteInterface;
```
Set one or more HTTP methods that constraint the matching of the route

```php
$route->via("GET");

$route->via(
    [
        "GET",
        "POST",
    ]
);
```



        
<h1 id="mvc-router-routeinterface">Interface Phalcon\Mvc\Router\RouteInterface</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/router/routeinterface.zep)

| Namespace  | Phalcon\Mvc\Router |

Phalcon\Mvc\Router\RouteInterface

Interface for Phalcon\Mvc\Router\Route


## Methods
```php
public function compilePattern( string $pattern ): string;
```
Replaces placeholders from pattern returning a valid PCRE regular expression


```php
public function convert( string $name, mixed $converter ): RouteInterface;
```
Adds a converter to perform an additional transformation for certain parameter.


```php
public function getCompiledPattern(): string;
```
Returns the route's pattern


```php
public function getHostname(): string;
```
Returns the hostname restriction if any


```php
public function getHttpMethods(): string | array;
```
Returns the HTTP methods that constraint matching the route


```php
public function getName(): string;
```
Returns the route's name


```php
public function getPaths(): array;
```
Returns the paths


```php
public function getPattern(): string;
```
Returns the route's pattern


```php
public function getReversedPaths(): array;
```
Returns the paths using positions as keys and names as values


```php
public function getRouteId(): string;
```
Returns the route's id


```php
public function reConfigure( string $pattern, mixed $paths = null ): void;
```
Reconfigure the route adding a new pattern and a set of paths


```php
public function setHostname( string $hostname ): RouteInterface;
```
Sets a hostname restriction to the route


```php
public function setHttpMethods( mixed $httpMethods ): RouteInterface;
```
Sets a set of HTTP methods that constraint the matching of the route


```php
public function setName( string $name ): void;
```
Sets the route's name


```php
public function via( mixed $httpMethods ): void;
```
Set one or more HTTP methods that constraint the matching of the route



        
<h1 id="mvc-routerinterface">Interface Phalcon\Mvc\RouterInterface</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/routerinterface.zep)

| Namespace  | Phalcon\Mvc |
| Uses       | Phalcon\Mvc\Router, Phalcon\Mvc\Router\RouteInterface, Phalcon\Mvc\Router\GroupInterface |

Interface for Phalcon\Mvc\Router


## Methods
```php
public function add( string $pattern, mixed $paths = null, mixed $httpMethods = null ): RouteInterface;
```
Adds a route to the router on any HTTP method


```php
public function addConnect( string $pattern, mixed $paths = null ): RouteInterface;
```
Adds a route to the router that only match if the HTTP method is CONNECT


```php
public function addDelete( string $pattern, mixed $paths = null ): RouteInterface;
```
Adds a route to the router that only match if the HTTP method is DELETE


```php
public function addGet( string $pattern, mixed $paths = null ): RouteInterface;
```
Adds a route to the router that only match if the HTTP method is GET


```php
public function addHead( string $pattern, mixed $paths = null ): RouteInterface;
```
Adds a route to the router that only match if the HTTP method is HEAD


```php
public function addOptions( string $pattern, mixed $paths = null ): RouteInterface;
```
Add a route to the router that only match if the HTTP method is OPTIONS


```php
public function addPatch( string $pattern, mixed $paths = null ): RouteInterface;
```
Adds a route to the router that only match if the HTTP method is PATCH


```php
public function addPost( string $pattern, mixed $paths = null ): RouteInterface;
```
Adds a route to the router that only match if the HTTP method is POST


```php
public function addPurge( string $pattern, mixed $paths = null ): RouteInterface;
```
Adds a route to the router that only match if the HTTP method is PURGE
(Squid and Varnish support)


```php
public function addPut( string $pattern, mixed $paths = null ): RouteInterface;
```
Adds a route to the router that only match if the HTTP method is PUT


```php
public function addTrace( string $pattern, mixed $paths = null ): RouteInterface;
```
Adds a route to the router that only match if the HTTP method is TRACE


```php
public function attach( RouteInterface $route, mixed $position = static-constant-access ): RouterInterface;
```
Attach Route object to the routes stack.


```php
public function clear(): void;
```
Removes all the defined routes


```php
public function getActionName(): string;
```
Returns processed action name


```php
public function getControllerName(): string;
```
Returns processed controller name


```php
public function getMatchedRoute(): RouteInterface;
```
Returns the route that matches the handled URI


```php
public function getMatches(): array;
```
Return the sub expressions in the regular expression matched


```php
public function getModuleName(): string;
```
Returns processed module name


```php
public function getNamespaceName(): string;
```
Returns processed namespace name


```php
public function getParams(): array;
```
Returns processed extra params


```php
public function getRouteById( mixed $id ): RouteInterface | bool;
```
Returns a route object by its id


```php
public function getRouteByName( string $name ): RouteInterface | bool;
```
Returns a route object by its name


```php
public function getRoutes(): RouteInterface[];
```
Return all the routes defined in the router


```php
public function handle( string $uri ): void;
```
Handles routing information received from the rewrite engine


```php
public function mount( GroupInterface $group ): RouterInterface;
```
Mounts a group of routes in the router


```php
public function setDefaultAction( string $actionName ): void;
```
Sets the default action name


```php
public function setDefaultController( string $controllerName ): void;
```
Sets the default controller name


```php
public function setDefaultModule( string $moduleName ): void;
```
Sets the name of the default module


```php
public function setDefaults( array $defaults ): void;
```
Sets an array of default paths


```php
public function wasMatched(): bool;
```
Check if the router matches any of the defined routes



        
<h1 id="mvc-view">Class Phalcon\Mvc\View</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/view.zep)

| Namespace  | Phalcon\Mvc |
| Uses       | Closure, Phalcon\Di\DiInterface, Phalcon\Di\Injectable, Phalcon\Events\ManagerInterface, Phalcon\Helper\Arr, Phalcon\Helper\Str, Phalcon\Mvc\View\Exception, Phalcon\Mvc\ViewInterface, Phalcon\Mvc\View\Engine\Php |
| Extends    | Injectable |
| Implements | ViewInterface |

Phalcon\Mvc\View

Phalcon\Mvc\View is a class for working with the "view" portion of the
model-view-controller pattern. That is, it exists to help keep the view
script separate from the model and controller scripts. It provides a system
of helpers, output filters, and variable escaping.

```php
use Phalcon\Mvc\View;

$view = new View();

// Setting views directory
$view->setViewsDir("app/views/");

$view->start();

// Shows recent posts view (app/views/posts/recent.phtml)
$view->render("posts", "recent");
$view->finish();

// Printing views output
echo $view->getContent();
```


## Constants
```php
const LEVEL_ACTION_VIEW = 1;
const LEVEL_AFTER_TEMPLATE = 4;
const LEVEL_BEFORE_TEMPLATE = 2;
const LEVEL_LAYOUT = 3;
const LEVEL_MAIN_LAYOUT = 5;
const LEVEL_NO_RENDER = 0;
```

## Properties
```php
//
protected actionName;

//
protected activeRenderPaths;

//
protected basePath = ;

//
protected content = ;

//
protected controllerName;

//
protected currentRenderLevel = 0;

//
protected disabled = false;

//
protected disabledLevels;

//
protected engines = false;

//
protected layout;

//
protected layoutsDir = ;

//
protected mainView = index;

//
protected options;

//
protected params;

//
protected pickView;

//
protected partialsDir = ;

//
protected registeredEngines;

//
protected renderLevel = 5;

//
protected templatesAfter;

//
protected templatesBefore;

//
protected viewsDirs;

//
protected viewParams;

```

## Methods
```php
public function __construct( array $options = [] );
```
Phalcon\Mvc\View constructor


```php
public function __get( string $key ): mixed | null;
```
Magic method to retrieve a variable passed to the view

```php
echo $this->view->products;
```


```php
public function __isset( string $key ): bool;
```
Magic method to retrieve if a variable is set in the view

```php
echo isset($this->view->products);
```


```php
public function __set( string $key, mixed $value );
```
Magic method to pass variables to the views

```php
$this->view->products = $products;
```


```php
public function cleanTemplateAfter(): View;
```
Resets any template before layouts


```php
public function cleanTemplateBefore(): View;
```
Resets any "template before" layouts


```php
public function disable(): View;
```
Disables the auto-rendering process


```php
public function disableLevel( mixed $level ): ViewInterface;
```
Disables a specific level of rendering

```php
// Render all levels except ACTION level
$this->view->disableLevel(
    View::LEVEL_ACTION_VIEW
);
```


```php
public function enable(): View;
```
Enables the auto-rendering process


```php
public function exists( string $view ): bool;
```
Checks whether view exists


```php
public function finish(): View;
```
Finishes the render process by stopping the output buffering


```php
public function getActionName(): string;
```
Gets the name of the action rendered


```php
public function getActiveRenderPath(): string | array;
```
Returns the path (or paths) of the views that are currently rendered


```php
public function getBasePath(): string;
```
Gets base path


```php
public function getContent(): string;
```
Returns output from another view stage


```php
public function getControllerName(): string;
```
Gets the name of the controller rendered


```php
public function getCurrentRenderLevel()
```


```php
public function getLayout(): string;
```
Returns the name of the main view


```php
public function getLayoutsDir(): string;
```
Gets the current layouts sub-directory


```php
public function getMainView(): string;
```
Returns the name of the main view


```php
public function getParamsToView(): array;
```
Returns parameters to views


```php
public function getPartial( string $partialPath, mixed $params = null ): string;
```
Renders a partial view

```php
// Retrieve the contents of a partial
echo $this->getPartial("shared/footer");
```

```php
// Retrieve the contents of a partial with arguments
echo $this->getPartial(
    "shared/footer",
    [
        "content" => $html,
    ]
);
```


```php
public function getPartialsDir(): string;
```
Gets the current partials sub-directory


```php
public function getRegisteredEngines()
```


```php
public function getRender( string $controllerName, string $actionName, array $params = [], mixed $configCallback = null ): string;
```
Perform the automatic rendering returning the output as a string

```php
$template = $this->view->getRender(
    "products",
    "show",
    [
        "products" => $products,
    ]
);
```

@param mixed configCallback


```php
public function getRenderLevel()
```


```php
public function getVar( string $key );
```
Returns a parameter previously set in the view


```php
public function getViewsDir(): string | array;
```
Gets views directory


```php
public function isDisabled(): bool;
```
Whether automatic rendering is enabled


```php
public function partial( string $partialPath, mixed $params = null );
```
Renders a partial view

```php
// Show a partial inside another view
$this->partial("shared/footer");
```

```php
// Show a partial inside another view with parameters
$this->partial(
    "shared/footer",
    [
        "content" => $html,
    ]
);
```


```php
public function pick( mixed $renderView ): View;
```
Choose a different view to render instead of last-controller/last-action

```php
use Phalcon\Mvc\Controller;

class ProductsController extends Controller
{
    public function saveAction()
    {
        // Do some save stuff...

        // Then show the list view
        $this->view->pick("products/list");
    }
}
```


```php
public function processRender( string $controllerName, string $actionName, array $params = [], bool $fireEvents = bool ): bool;
```
Processes the view and templates; Fires events if needed


```php
public function registerEngines( array $engines ): View;
```
Register templating engines

```php
$this->view->registerEngines(
    [
        ".phtml" => \Phalcon\Mvc\View\Engine\Php::class,
        ".volt"  => \Phalcon\Mvc\View\Engine\Volt::class,
        ".mhtml" => \MyCustomEngine::class,
    ]
);
```


```php
public function render( string $controllerName, string $actionName, array $params = [] ): View | bool;
```
Executes render process from dispatching data

```php
// Shows recent posts view (app/views/posts/recent.phtml)
$view->start()->render("posts", "recent")->finish();
```


```php
public function reset(): View;
```
Resets the view component to its factory default values


```php
public function setBasePath( string $basePath ): View;
```
Sets base path. Depending of your platform, always add a trailing slash
or backslash

```php
$view->setBasePath(__DIR__ . "/");
```


```php
public function setContent( string $content ): View;
```
Externally sets the view content

```php
$this->view->setContent("<h1>hello</h1>");
```


```php
public function setLayout( string $layout ): View;
```
Change the layout to be used instead of using the name of the latest
controller name

```php
$this->view->setLayout("main");
```


```php
public function setLayoutsDir( string $layoutsDir ): View;
```
Sets the layouts sub-directory. Must be a directory under the views
directory. Depending of your platform, always add a trailing slash or
backslash

```php
$view->setLayoutsDir("../common/layouts/");
```


```php
public function setMainView( string $viewPath ): View;
```
Sets default view name. Must be a file without extension in the views
directory

```php
// Renders as main view views-dir/base.phtml
$this->view->setMainView("base");
```


```php
public function setParamToView( string $key, mixed $value ): View;
```
Adds parameters to views (alias of setVar)

```php
$this->view->setParamToView("products", $products);
```


```php
public function setPartialsDir( string $partialsDir ): View;
```
Sets a partials sub-directory. Must be a directory under the views
directory. Depending of your platform, always add a trailing slash or
backslash

```php
$view->setPartialsDir("../common/partials/");
```


```php
public function setRenderLevel( int $level ): ViewInterface;
```
Sets the render level for the view

```php
// Render the view related to the controller only
$this->view->setRenderLevel(
    View::LEVEL_LAYOUT
);
```


```php
public function setTemplateAfter( mixed $templateAfter ): View;
```
Sets a "template after" controller layout


```php
public function setTemplateBefore( mixed $templateBefore ): View;
```
Sets a template before the controller layout


```php
public function setVar( string $key, mixed $value ): View;
```
Set a single view parameter

```php
$this->view->setVar("products", $products);
```


```php
public function setVars( array $params, bool $merge = bool ): View;
```
Set all the render params

```php
$this->view->setVars(
    [
        "products" => $products,
    ]
);
```


```php
public function setViewsDir( mixed $viewsDir ): View;
```
Sets the views directory. Depending of your platform,
always add a trailing slash or backslash


```php
public function start(): View;
```
Starts rendering process enabling the output buffering


```php
public function toString( string $controllerName, string $actionName, array $params = [] ): string;
```
Renders the view and returns it as a string


```php
protected function engineRender( array $engines, string $viewPath, bool $silence, bool $mustClean = bool );
```
Checks whether view exists on registered extensions and render it


```php
protected function getViewsDirs(): array;
```
Gets views directories


```php
final protected function isAbsolutePath( string $path );
```
Checks if a path is absolute or not


```php
protected function loadTemplateEngines(): array;
```
Loads registered template engines, if none is registered it will use
Phalcon\Mvc\View\Engine\Php



        
<h1 id="mvc-view-engine-abstractengine">Abstract Class Phalcon\Mvc\View\Engine\AbstractEngine</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/view/engine/abstractengine.zep)

| Namespace  | Phalcon\Mvc\View\Engine |
| Uses       | Phalcon\Di\DiInterface, Phalcon\Di\Injectable, Phalcon\Mvc\ViewBaseInterface |
| Extends    | Injectable |
| Implements | EngineInterface |

All the template engine adapters must inherit this class. This provides
basic interfacing between the engine and the Phalcon\Mvc\View component.


## Properties
```php
//
protected view;

```

## Methods
```php
public function __construct( ViewBaseInterface $view, DiInterface $container = null );
```
Phalcon\Mvc\View\Engine constructor


```php
public function getContent(): string;
```
Returns cached output on another view stage


```php
public function getView(): ViewBaseInterface;
```
Returns the view component related to the adapter


```php
public function partial( string $partialPath, mixed $params = null ): string;
```
Renders a partial inside another view

@param array params



        
<h1 id="mvc-view-engine-engineinterface">Interface Phalcon\Mvc\View\Engine\EngineInterface</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/view/engine/engineinterface.zep)

| Namespace  | Phalcon\Mvc\View\Engine |

Interface for Phalcon\Mvc\View engine adapters


## Methods
```php
public function getContent(): string;
```
Returns cached output on another view stage


```php
public function partial( string $partialPath, mixed $params = null ): string;
```
Renders a partial inside another view


```php
public function render( string $path, mixed $params, bool $mustClean = bool );
```
Renders a view using the template engine



        
<h1 id="mvc-view-engine-php">Class Phalcon\Mvc\View\Engine\Php</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/view/engine/php.zep)

| Namespace  | Phalcon\Mvc\View\Engine |
| Uses       | Phalcon\Mvc\View\Engine\AbstractEngine |
| Extends    | AbstractEngine |

Adapter to use PHP itself as templating engine


## Methods
```php
public function render( string $path, mixed $params, bool $mustClean = bool );
```
Renders a view using the template engine



        
<h1 id="mvc-view-engine-volt">Class Phalcon\Mvc\View\Engine\Volt</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/view/engine/volt.zep)

| Namespace  | Phalcon\Mvc\View\Engine |
| Uses       | Phalcon\Di\DiInterface, Phalcon\Mvc\View\Engine\AbstractEngine, Phalcon\Mvc\View\Engine\Volt\Compiler, Phalcon\Mvc\View\Exception |
| Extends    | AbstractEngine |

Designer friendly and fast template engine for PHP written in Zephir/C


## Properties
```php
//
protected compiler;

//
protected macros;

//
protected options;

```

## Methods
```php
public function callMacro( string $name, array $arguments = [] ): mixed;
```
Checks if a macro is defined and calls it


```php
public function convertEncoding( string $text, string $from, string $to ): string;
```
Performs a string conversion


```php
public function getCompiler(): Compiler;
```
Returns the Volt's compiler


```php
public function getOptions(): array;
```
Return Volt's options


```php
public function isIncluded( mixed $needle, mixed $haystack ): bool;
```
Checks if the needle is included in the haystack


```php
public function length( mixed $item ): int;
```
Length filter. If an array/object is passed a count is performed otherwise a strlen/mb_strlen


```php
public function render( string $templatePath, mixed $params, bool $mustClean = bool );
```
Renders a view using the template engine


```php
public function setOptions( array $options );
```
Set Volt's options


```php
public function slice( mixed $value, int $start = int, mixed $end = null );
```
Extracts a slice from a string/array/traversable object value


```php
public function sort( array $value ): array;
```
Sorts an array



        
<h1 id="mvc-view-engine-volt-compiler">Class Phalcon\Mvc\View\Engine\Volt\Compiler</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/view/engine/volt/compiler.zep)

| Namespace  | Phalcon\Mvc\View\Engine\Volt |
| Uses       | Closure, Phalcon\Di\DiInterface, Phalcon\Mvc\ViewBaseInterface, Phalcon\Di\InjectionAwareInterface, Phalcon\Mvc\View\Engine\Volt\Exception |
| Implements | InjectionAwareInterface |

This class reads and compiles Volt templates into PHP plain code

```php
$compiler = new \Phalcon\Mvc\View\Engine\Volt\Compiler();

$compiler->compile("views/partials/header.volt");

require $compiler->getCompiledTemplatePath();
```


## Properties
```php
//
protected autoescape = false;

//
protected blockLevel = 0;

//
protected blocks;

//
protected container;

//
protected compiledTemplatePath;

//
protected currentBlock;

//
protected currentPath;

//
protected exprLevel = 0;

//
protected extended = false;

//
protected extensions;

//
protected extendedBlocks;

//
protected filters;

//
protected foreachLevel = 0;

//
protected forElsePointers;

//
protected functions;

//
protected level = 0;

//
protected loopPointers;

//
protected macros;

//
protected options;

//
protected prefix;

//
protected view;

```

## Methods
```php
public function __construct( ViewBaseInterface $view = null );
```
Phalcon\Mvc\View\Engine\Volt\Compiler


```php
public function addExtension( mixed $extension ): Compiler;
```
Registers a Volt's extension


```php
public function addFilter( string $name, mixed $definition ): Compiler;
```
Register a new filter in the compiler


```php
public function addFunction( string $name, mixed $definition ): Compiler;
```
Register a new function in the compiler


```php
public function attributeReader( array $expr ): string;
```
Resolves attribute reading


```php
public function compile( string $templatePath, bool $extendsMode = bool );
```
Compiles a template into a file applying the compiler options
This method does not return the compiled path if the template was not compiled

```php
$compiler->compile("views/layouts/main.volt");

require $compiler->getCompiledTemplatePath();
```


```php
public function compileAutoEscape( array $statement, bool $extendsMode ): string;
```
Compiles a "autoescape" statement returning PHP code


```php
public function compileCache( array $statement, bool $extendsMode = bool ): string;
```
Compiles a "cache" statement returning PHP code


```php
public function compileCall( array $statement, bool $extendsMode );
```
Compiles calls to macros


```php
public function compileCase( array $statement, bool $caseClause = bool ): string;
```
Compiles a "case"/"default" clause returning PHP code


```php
public function compileDo( array $statement ): string;
```
Compiles a "do" statement returning PHP code


```php
public function compileEcho( array $statement ): string;
```
Compiles a {% raw %}`{{` `}}`{% endraw %} statement returning PHP code


```php
public function compileElseIf( array $statement ): string;
```
Compiles a "elseif" statement returning PHP code


```php
public function compileFile( string $path, string $compiledPath, bool $extendsMode = bool );
```
Compiles a template into a file forcing the destination path

```php
$compiler->compileFile(
    "views/layouts/main.volt",
    "views/layouts/main.volt.php"
);
```

@return string|array


```php
public function compileForElse(): string;
```
Generates a 'forelse' PHP code


```php
public function compileForeach( array $statement, bool $extendsMode = bool ): string;
```
Compiles a "foreach" intermediate code representation into plain PHP code


```php
public function compileIf( array $statement, bool $extendsMode = bool ): string;
```
Compiles a 'if' statement returning PHP code


```php
public function compileInclude( array $statement ): string;
```
Compiles a 'include' statement returning PHP code


```php
public function compileMacro( array $statement, bool $extendsMode ): string;
```
Compiles macros


```php
public function compileReturn( array $statement ): string;
```
Compiles a "return" statement returning PHP code


```php
public function compileSet( array $statement ): string;
```
Compiles a "set" statement returning PHP code


```php
public function compileString( string $viewCode, bool $extendsMode = bool ): string;
```
Compiles a template into a string

```php
echo $compiler->compileString({% raw %}'{{ "hello world" }}'{% endraw %});
```


```php
public function compileSwitch( array $statement, bool $extendsMode = bool ): string;
```
Compiles a 'switch' statement returning PHP code


```php
final public function expression( array $expr ): string;
```
Resolves an expression node in an AST volt tree


```php
final public function fireExtensionEvent( string $name, mixed $arguments = null );
```
Fires an event to registered extensions

@param array arguments
@return mixed


```php
public function functionCall( array $expr ): string;
```
Resolves function intermediate code into PHP function calls


```php
public function getCompiledTemplatePath(): string;
```
Returns the path to the last compiled template


```php
public function getDI(): DiInterface;
```
Returns the internal dependency injector


```php
public function getExtensions(): array;
```
Returns the list of extensions registered in Volt


```php
public function getFilters(): array;
```
Register the user registered filters


```php
public function getFunctions(): array;
```
Register the user registered functions


```php
public function getOption( string $option );
```
Returns a compiler's option

@return string


```php
public function getOptions(): array;
```
Returns the compiler options


```php
public function getTemplatePath(): string;
```
Returns the path that is currently being compiled


```php
public function getUniquePrefix(): string;
```
Return a unique prefix to be used as prefix for compiled variables and
contexts


```php
public function parse( string $viewCode );
```
Parses a Volt template returning its intermediate representation

```php
print_r(
    $compiler->parse("{% raw %}{{ 3 + 2 }}{% endraw %}")
);
```

@return array


```php
public function resolveTest( array $test, string $left ): string;
```
Resolves filter intermediate code into a valid PHP expression


```php
public function setDI( DiInterface $container ): void;
```
Sets the dependency injector


```php
public function setOption( string $option, mixed $value );
```
Sets a single compiler option

@param mixed value


```php
public function setOptions( array $options );
```
Sets the compiler options


```php
public function setUniquePrefix( string $prefix ): Compiler;
```
Set a unique prefix to be used as prefix for compiled variables


```php
protected function compileSource( string $viewCode, bool $extendsMode = bool ): string;
```
Compiles a Volt source code returning a PHP plain version


```php
protected function getFinalPath( string $path );
```
Gets the final path with VIEW


```php
final protected function resolveFilter( array $filter, string $left ): string;
```
Resolves filter intermediate code into PHP function calls


```php
final protected function statementList( array $statements, bool $extendsMode = bool ): string;
```
Traverses a statement list compiling each of its nodes


```php
final protected function statementListOrExtends( mixed $statements );
```
Compiles a block of statements

@param array statements
@return string|array



        
<h1 id="mvc-view-engine-volt-exception">Class Phalcon\Mvc\View\Engine\Volt\Exception</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/view/engine/volt/exception.zep)

| Namespace  | Phalcon\Mvc\View\Engine\Volt |
| Uses       | Phalcon\Mvc\View\Exception |
| Extends    | BaseException |

Class for exceptions thrown by Phalcon\Mvc\View


## Properties
```php
//
protected statement;

```

## Methods
```php
public function __construct( string $message = string, array $statement = [], int $code = int, \Exception $previous = null );
```
//

```php
public function getStatement(): array;
```
Gets currently parsed statement (if any).



        
<h1 id="mvc-view-exception">Class Phalcon\Mvc\View\Exception</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/view/exception.zep)

| Namespace  | Phalcon\Mvc\View |
| Extends    | \Phalcon\Exception |

Phalcon\Mvc\View\Exception

Class for exceptions thrown by Phalcon\Mvc\View


        
<h1 id="mvc-view-simple">Class Phalcon\Mvc\View\Simple</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/view/simple.zep)

| Namespace  | Phalcon\Mvc\View |
| Uses       | Closure, Phalcon\Di\DiInterface, Phalcon\Di\Injectable, Phalcon\Helper\Arr, Phalcon\Helper\Str, Phalcon\Mvc\View\Exception, Phalcon\Mvc\ViewBaseInterface, Phalcon\Mvc\View\Engine\EngineInterface, Phalcon\Mvc\View\Engine\Php |
| Extends    | Injectable |
| Implements | ViewBaseInterface |

Phalcon\Mvc\View\Simple

This component allows to render views without hierarchical levels

```php
use Phalcon\Mvc\View\Simple as View;

$view = new View();

// Render a view
echo $view->render(
    "templates/my-view",
    [
        "some" => $param,
    ]
);

// Or with filename with extension
echo $view->render(
    "templates/my-view.volt",
    [
        "parameter" => $here,
    ]
);
```


## Properties
```php
//
protected activeRenderPath;

//
protected content;

/**
 * @var \Phalcon\Mvc\View\EngineInterface[]|false
 */
protected engines = false;

//
protected options;

//
protected partialsDir;

/**
 * @var array|null
 */
protected registeredEngines;

//
protected viewsDir;

//
protected viewParams;

```

## Methods
```php
public function __construct( array $options = [] );
```
Phalcon\Mvc\View\Simple constructor


```php
public function __get( string $key ): mixed | null;
```
Magic method to retrieve a variable passed to the view

```php
echo $this->view->products;
```


```php
public function __set( string $key, mixed $value );
```
Magic method to pass variables to the views

```php
$this->view->products = $products;
```


```php
public function getActiveRenderPath(): string;
```
Returns the path of the view that is currently rendered


```php
public function getContent(): string;
```
Returns output from another view stage


```php
public function getParamsToView(): array;
```
Returns parameters to views


```php
public function getRegisteredEngines(): array|null
```


```php
public function getVar( string $key ): mixed | null;
```
Returns a parameter previously set in the view


```php
public function getViewsDir(): string;
```
Gets views directory


```php
public function partial( string $partialPath, mixed $params = null );
```
Renders a partial view

```php
// Show a partial inside another view
$this->partial("shared/footer");
```

```php
// Show a partial inside another view with parameters
$this->partial(
    "shared/footer",
    [
        "content" => $html,
    ]
);
```


```php
public function registerEngines( array $engines );
```
Register templating engines

```php
$this->view->registerEngines(
    [
        ".phtml" => \Phalcon\Mvc\View\Engine\Php::class,
        ".volt"  => \Phalcon\Mvc\View\Engine\Volt::class,
        ".mhtml" => \MyCustomEngine::class,
    ]
);
```


```php
public function render( string $path, array $params = [] ): string;
```
Renders a view


```php
public function setContent( string $content ): Simple;
```
Externally sets the view content

```php
$this->view->setContent("<h1>hello</h1>");
```


```php
public function setParamToView( string $key, mixed $value ): Simple;
```
Adds parameters to views (alias of setVar)

```php
$this->view->setParamToView("products", $products);
```


```php
public function setVar( string $key, mixed $value ): Simple;
```
Set a single view parameter

```php
$this->view->setVar("products", $products);
```


```php
public function setVars( array $params, bool $merge = bool ): Simple;
```
Set all the render params

```php
$this->view->setVars(
    [
        "products" => $products,
    ]
);
```


```php
public function setViewsDir( string $viewsDir );
```
Sets views directory


```php
final protected function internalRender( string $path, mixed $params );
```
Tries to render the view with every engine registered in the component

@param array  params


```php
protected function loadTemplateEngines(): array;
```
Loads registered template engines, if none are registered it will use
Phalcon\Mvc\View\Engine\Php



        
<h1 id="mvc-viewbaseinterface">Interface Phalcon\Mvc\ViewBaseInterface</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/viewbaseinterface.zep)

| Namespace  | Phalcon\Mvc |
| Uses       | Phalcon\Cache\Adapter\AdapterInterface |

Phalcon\Mvc\ViewInterface

Interface for Phalcon\Mvc\View and Phalcon\Mvc\View\Simple


## Methods
```php
public function getContent(): string;
```
Returns cached output from another view stage


```php
public function getParamsToView(): array;
```
Returns parameters to views


```php
public function getViewsDir(): string | array;
```
Gets views directory


```php
public function partial( string $partialPath, mixed $params = null );
```
Renders a partial view


```php
public function setContent( string $content );
```
Externally sets the view content


```php
public function setParamToView( string $key, mixed $value );
```
Adds parameters to views (alias of setVar)


```php
public function setVar( string $key, mixed $value );
```
Adds parameters to views


```php
public function setViewsDir( string $viewsDir );
```
Sets views directory. Depending of your platform, always add a trailing
slash or backslash



        
<h1 id="mvc-viewinterface">Interface Phalcon\Mvc\ViewInterface</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/mvc/viewinterface.zep)

| Namespace  | Phalcon\Mvc |
| Extends    | ViewBaseInterface |

Phalcon\Mvc\ViewInterface

Interface for Phalcon\Mvc\View


## Methods
```php
public function cleanTemplateAfter();
```
Resets any template before layouts


```php
public function cleanTemplateBefore();
```
Resets any template before layouts


```php
public function disable();
```
Disables the auto-rendering process


```php
public function enable();
```
Enables the auto-rendering process


```php
public function finish();
```
Finishes the render process by stopping the output buffering


```php
public function getActionName(): string;
```
Gets the name of the action rendered


```php
public function getActiveRenderPath(): string | array;
```
Returns the path of the view that is currently rendered


```php
public function getBasePath(): string;
```
Gets base path


```php
public function getControllerName(): string;
```
Gets the name of the controller rendered


```php
public function getLayout(): string;
```
Returns the name of the main view


```php
public function getLayoutsDir(): string;
```
Gets the current layouts sub-directory


```php
public function getMainView(): string;
```
Returns the name of the main view


```php
public function getPartialsDir(): string;
```
Gets the current partials sub-directory


```php
public function isDisabled(): bool;
```
Whether the automatic rendering is disabled


```php
public function pick( string $renderView );
```
Choose a view different to render than last-controller/last-action


```php
public function registerEngines( array $engines );
```
Register templating engines


```php
public function render( string $controllerName, string $actionName, array $params = [] ): ViewInterface | bool;
```
Executes render process from dispatching data


```php
public function reset();
```
Resets the view component to its factory default values


```php
public function setBasePath( string $basePath );
```
Sets base path. Depending of your platform, always add a trailing slash
or backslash


```php
public function setLayout( string $layout );
```
Change the layout to be used instead of using the name of the latest
controller name


```php
public function setLayoutsDir( string $layoutsDir );
```
Sets the layouts sub-directory. Must be a directory under the views
directory. Depending of your platform, always add a trailing slash or
backslash


```php
public function setMainView( string $viewPath );
```
Sets default view name. Must be a file without extension in the views
directory


```php
public function setPartialsDir( string $partialsDir );
```
Sets a partials sub-directory. Must be a directory under the views
directory. Depending of your platform, always add a trailing slash or
backslash


```php
public function setRenderLevel( int $level ): ViewInterface;
```
Sets the render level for the view


```php
public function setTemplateAfter( mixed $templateAfter );
```
Appends template after controller layout

@param string|array templateAfter


```php
public function setTemplateBefore( mixed $templateBefore );
```
Appends template before controller layout

@param string|array templateBefore


```php
public function start();
```
Starts rendering process enabling the output buffering


