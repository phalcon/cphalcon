---
layout: default
language: 'en'
version: '4.0'
title: 'Phalcon\Dispatcher'
---

* [Phalcon\Dispatcher\AbstractDispatcher](#dispatcher-abstractdispatcher)
* [Phalcon\Dispatcher\DispatcherInterface](#dispatcher-dispatcherinterface)
* [Phalcon\Dispatcher\Exception](#dispatcher-exception)
        
<h1 id="dispatcher-abstractdispatcher">Abstract Class Phalcon\Dispatcher\AbstractDispatcher</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/dispatcher/abstractdispatcher.zep)

| Namespace  | Phalcon\Dispatcher |
| Uses       | Exception, Phalcon\Di\DiInterface, Phalcon\Di\AbstractInjectionAware, Phalcon\Dispatcher\DispatcherInterface, Phalcon\Dispatcher\Exception, Phalcon\Events\EventsAwareInterface, Phalcon\Events\ManagerInterface, Phalcon\Filter\FilterInterface, Phalcon\Mvc\Model\Binder, Phalcon\Mvc\Model\BinderInterface |
| Extends    | AbstractInjectionAware |
| Implements | DispatcherInterface, EventsAwareInterface |

This is the base class for Phalcon\Mvc\Dispatcher and Phalcon\Cli\Dispatcher.
This class can't be instantiated directly, you can use it to create your own
dispatchers.


## Properties
```php
//
protected activeHandler;

/**
 * @var array
 */
protected activeMethodMap;

//
protected actionName;

/**
 * @var string
 */
protected actionSuffix = Action;

/**
 * @var array
 */
protected camelCaseMap;

/**
 * @var string
 */
protected defaultAction = ;

//
protected defaultNamespace;

//
protected defaultHandler;

/**
 * @var array
 */
protected handlerHashes;

//
protected handlerName;

/**
 * @var string
 */
protected handlerSuffix = ;

//
protected eventsManager;

/**
 * @var bool
 */
protected finished = false;

/**
 * @var bool
 */
protected forwarded = false;

/**
 * @var bool
 */
protected isControllerInitialize = false;

//
protected lastHandler;

//
protected modelBinder;

/**
 * @var bool
 */
protected modelBinding = false;

//
protected moduleName;

//
protected namespaceName;

/**
 * @var array
 */
protected params;

//
protected previousActionName;

//
protected previousHandlerName;

//
protected previousNamespaceName;

//
protected returnedValue;

```

## Methods
```php
public function callActionMethod( mixed $handler, string $actionMethod, array $params = [] );
```
//

```php
public function dispatch(): object | bool;
```
Process the results of the router by calling into the appropriate
controller action(s) including any routing data or injected parameters.

@return object|false Returns the dispatched handler class (the Controller for Mvc dispatching or a Task
                     for CLI dispatching) or <tt>false</tt> if an exception occurred and the operation was
                     stopped by returning <tt>false</tt> in the exception handler.

@throws \Exception if any uncaught or unhandled exception occurs during the dispatcher process.


```php
public function forward( array $forward ): void;
```
Forwards the execution flow to another controller/action.

```php
$this->dispatcher->forward(
    [
        "controller" => "posts",
        "action"     => "index",
    ]
);
```

@throws \Phalcon\Exception


```php
public function getActionName(): string;
```
Gets the latest dispatched action name


```php
public function getActionSuffix(): string;
```
Gets the default action suffix


```php
public function getActiveMethod(): string;
```
Returns the current method to be/executed in the dispatcher


```php
public function getBoundModels(): array;
```
Returns bound models from binder instance

```php
class UserController extends Controller
{
    public function showAction(User $user)
    {
        // return array with $user
        $boundModels = $this->dispatcher->getBoundModels();
    }
}
```


```php
public function getDefaultNamespace(): string;
```
Returns the default namespace


```php
public function getEventsManager(): ManagerInterface;
```
Returns the internal event manager


```php
public function getHandlerClass(): string;
```
Possible class name that will be located to dispatch the request


```php
public function getHandlerSuffix(): string;
```
Gets the default handler suffix


```php
public function getModelBinder(): BinderInterface | null;
```
Gets model binder


```php
public function getModuleName(): string;
```
Gets the module where the controller class is


```php
public function getNamespaceName(): string;
```
Gets a namespace to be prepended to the current handler name


```php
public function getParam( mixed $param, mixed $filters = null, mixed $defaultValue = null ): mixed;
```
Gets a param by its name or numeric index

@param  mixed param
@param  string|array filters
@param  mixed defaultValue
@return mixed


```php
public function getParams(): array;
```
Gets action params


```php
public function getReturnedValue(): mixed;
```
Returns value returned by the latest dispatched action


```php
public function hasParam( mixed $param ): bool;
```
Check if a param exists


```php
public function isFinished(): bool;
```
Checks if the dispatch loop is finished or has more pendent
controllers/tasks to dispatch


```php
public function setActionName( string $actionName ): void;
```
Sets the action name to be dispatched


```php
public function setActionSuffix( string $actionSuffix ): void;
```
Sets the default action suffix


```php
public function setDefaultAction( string $actionName ): void;
```
Sets the default action name


```php
public function setDefaultNamespace( string $namespaceName ): void;
```
Sets the default namespace


```php
public function setEventsManager( ManagerInterface $eventsManager ): void;
```
Sets the events manager


```php
public function setHandlerSuffix( string $handlerSuffix ): void;
```
Sets the default suffix for the handler


```php
public function setModelBinder( BinderInterface $modelBinder, mixed $cache = null ): Dispatcher;
```
Enable model binding during dispatch

```php
$di->set(
    'dispatcher',
    function() {
        $dispatcher = new Dispatcher();

        $dispatcher->setModelBinder(
            new Binder(),
            'cache'
        );

        return $dispatcher;
    }
);
```


```php
public function setModuleName( string $moduleName ): void;
```
Sets the module where the controller is (only informative)


```php
public function setNamespaceName( string $namespaceName ): void;
```
Sets the namespace where the controller class is


```php
public function setParam( mixed $param, mixed $value ): void;
```
Set a param by its name or numeric index


```php
public function setParams( array $params ): void;
```
Sets action params to be dispatched


```php
public function setReturnedValue( mixed $value ): void;
```
Sets the latest returned value by an action manually


```php
public function wasForwarded(): bool;
```
Check if the current executed action was forwarded by another one


```php
protected function resolveEmptyProperties(): void;
```
Set empty properties to their defaults (where defaults are available)


```php
protected function toCamelCase( string $input ): string;
```
//


        
<h1 id="dispatcher-dispatcherinterface">Interface Phalcon\Dispatcher\DispatcherInterface</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/dispatcher/dispatcherinterface.zep)

| Namespace  | Phalcon\Dispatcher |

Interface for Phalcon\Dispatcher\AbstractDispatcher


## Methods
```php
public function dispatch(): object | bool;
```
Dispatches a handle action taking into account the routing parameters


```php
public function forward( array $forward ): void;
```
Forwards the execution flow to another controller/action


```php
public function getActionName(): string;
```
Gets last dispatched action name


```php
public function getActionSuffix(): string;
```
Gets the default action suffix


```php
public function getHandlerSuffix(): string;
```
Gets the default handler suffix


```php
public function getParam( mixed $param, mixed $filters = null ): mixed;
```
Gets a param by its name or numeric index

@param  string|array filters


```php
public function getParams(): array;
```
Gets action params


```php
public function getReturnedValue(): mixed;
```
Returns value returned by the latest dispatched action


```php
public function hasParam( mixed $param ): bool;
```
Check if a param exists


```php
public function isFinished(): bool;
```
Checks if the dispatch loop is finished or has more pendent
controllers/tasks to dispatch


```php
public function setActionName( string $actionName ): void;
```
Sets the action name to be dispatched


```php
public function setActionSuffix( string $actionSuffix ): void;
```
Sets the default action suffix


```php
public function setDefaultAction( string $actionName ): void;
```
Sets the default action name


```php
public function setDefaultNamespace( string $defaultNamespace ): void;
```
Sets the default namespace


```php
public function setHandlerSuffix( string $handlerSuffix ): void;
```
Sets the default suffix for the handler


```php
public function setModuleName( string $moduleName ): void;
```
Sets the module name which the application belongs to


```php
public function setNamespaceName( string $namespaceName ): void;
```
Sets the namespace which the controller belongs to


```php
public function setParam( mixed $param, mixed $value ): void;
```
Set a param by its name or numeric index

@param  mixed value


```php
public function setParams( array $params ): void;
```
Sets action params to be dispatched



        
<h1 id="dispatcher-exception">Class Phalcon\Dispatcher\Exception</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/dispatcher/exception.zep)

| Namespace  | Phalcon\Dispatcher |
| Extends    | \Phalcon\Exception |

Exceptions thrown in Phalcon\Dispatcher/* will use this class


## Constants
```php
const EXCEPTION_ACTION_NOT_FOUND = 5;
const EXCEPTION_CYCLIC_ROUTING = 1;
const EXCEPTION_HANDLER_NOT_FOUND = 2;
const EXCEPTION_INVALID_HANDLER = 3;
const EXCEPTION_INVALID_PARAMS = 4;
const EXCEPTION_NO_DI = 0;
```
