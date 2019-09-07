---
layout: default
language: 'en'
version: '4.0'
title: 'Phalcon\Cli'
---

* [Phalcon\Cli\Console](#cli-console)
* [Phalcon\Cli\Console\Exception](#cli-console-exception)
* [Phalcon\Cli\Dispatcher](#cli-dispatcher)
* [Phalcon\Cli\Dispatcher\Exception](#cli-dispatcher-exception)
* [Phalcon\Cli\DispatcherInterface](#cli-dispatcherinterface)
* [Phalcon\Cli\Router](#cli-router)
* [Phalcon\Cli\Router\Exception](#cli-router-exception)
* [Phalcon\Cli\Router\Route](#cli-router-route)
* [Phalcon\Cli\Router\RouteInterface](#cli-router-routeinterface)
* [Phalcon\Cli\RouterInterface](#cli-routerinterface)
* [Phalcon\Cli\Task](#cli-task)
* [Phalcon\Cli\TaskInterface](#cli-taskinterface)
        
<h1 id="cli-console">Class Phalcon\Cli\Console</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/cli/console.zep)

| Namespace  | Phalcon\Cli |
| Uses       | Phalcon\Application\AbstractApplication, Phalcon\Cli\Router\Route, Phalcon\Cli\Console\Exception, Phalcon\Di\DiInterface, Phalcon\Events\ManagerInterface |
| Extends    | AbstractApplication |

This component allows to create CLI applications using Phalcon


## Properties
```php
/**
 * @var array
 */
protected arguments;

/**
 * @var array
 */
protected options;

```

## Methods
```php
public function handle( array $arguments = null );
```
Handle the whole command-line tasks


```php
public function setArgument( array $arguments = null, bool $str = bool, bool $shift = bool ): Console;
```
Set an specific argument



        
<h1 id="cli-console-exception">Class Phalcon\Cli\Console\Exception</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/cli/console/exception.zep)

| Namespace  | Phalcon\Cli\Console |
| Extends    | \Phalcon\Application\Exception |

Exceptions thrown in Phalcon\Cli\Console will use this class


        
<h1 id="cli-dispatcher">Class Phalcon\Cli\Dispatcher</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/cli/dispatcher.zep)

| Namespace  | Phalcon\Cli |
| Uses       | Phalcon\Cli\Dispatcher\Exception, Phalcon\Dispatcher\AbstractDispatcher, Phalcon\Events\ManagerInterface, Phalcon\Filter\FilterInterface |
| Extends    | CliDispatcher |
| Implements | DispatcherInterface |

Dispatching is the process of taking the command-line arguments, extracting
the module name, task name, action name, and optional parameters contained in
it, and then instantiating a task and calling an action on it.

```php
use Phalcon\Di;
use Phalcon\Cli\Dispatcher;

$di = new Di();

$dispatcher = new Dispatcher();

$dispatcher->setDi($di);

$dispatcher->setTaskName("posts");
$dispatcher->setActionName("index");
$dispatcher->setParams([]);

$handle = $dispatcher->dispatch();
```


## Properties
```php
/**
 * @var string
 */
protected defaultHandler = main;

/**
 * @var string
 */
protected defaultAction = main;

/**
 * @var string
 */
protected handlerSuffix = Task;

/**
 * @var array
 */
protected options;

```

## Methods
```php
public function callActionMethod( mixed $handler, string $actionMethod, array $params = [] ): mixed;
```
Calls the action method.


```php
public function getActiveTask(): TaskInterface;
```
Returns the active task in the dispatcher


```php
public function getLastTask(): TaskInterface;
```
Returns the latest dispatched controller


```php
public function getOption( mixed $option, mixed $filters = null, mixed $defaultValue = null ): mixed;
```
Gets an option by its name or numeric index

@param  mixed $option
@param  string|array $filters
@param  mixed $defaultValue


```php
public function getOptions(): array;
```
Get dispatched options


```php
public function getTaskName(): string;
```
Gets last dispatched task name


```php
public function getTaskSuffix(): string;
```
Gets the default task suffix


```php
public function hasOption( mixed $option ): bool;
```
Check if an option exists


```php
public function setDefaultTask( string $taskName ): void;
```
Sets the default task name


```php
public function setOptions( array $options ): void;
```
Set the options to be dispatched


```php
public function setTaskName( string $taskName ): void;
```
Sets the task name to be dispatched


```php
public function setTaskSuffix( string $taskSuffix ): void;
```
Sets the default task suffix


```php
protected function handleException( \Exception $exception );
```
Handles a user exception


```php
protected function throwDispatchException( string $message, int $exceptionCode = int );
```
Throws an internal exception



        
<h1 id="cli-dispatcher-exception">Class Phalcon\Cli\Dispatcher\Exception</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/cli/dispatcher/exception.zep)

| Namespace  | Phalcon\Cli\Dispatcher |
| Extends    | \Phalcon\Dispatcher\Exception |

Exceptions thrown in Phalcon\Cli\Dispatcher will use this class


        
<h1 id="cli-dispatcherinterface">Interface Phalcon\Cli\DispatcherInterface</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/cli/dispatcherinterface.zep)

| Namespace  | Phalcon\Cli |
| Uses       | Phalcon\Dispatcher\DispatcherInterface |
| Extends    | DispatcherInterfaceBase |

Interface for Phalcon\Cli\Dispatcher


## Methods
```php
public function getActiveTask(): TaskInterface;
```
Returns the active task in the dispatcher


```php
public function getLastTask(): TaskInterface;
```
Returns the latest dispatched controller


```php
public function getOptions(): array;
```
Get dispatched options


```php
public function getTaskName(): string;
```
Gets last dispatched task name


```php
public function getTaskSuffix(): string;
```
Gets default task suffix


```php
public function setDefaultTask( string $taskName ): void;
```
Sets the default task name


```php
public function setOptions( array $options ): void;
```
Set the options to be dispatched


```php
public function setTaskName( string $taskName ): void;
```
Sets the task name to be dispatched


```php
public function setTaskSuffix( string $taskSuffix ): void;
```
Sets the default task suffix



        
<h1 id="cli-router">Class Phalcon\Cli\Router</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/cli/router.zep)

| Namespace  | Phalcon\Cli |
| Uses       | Phalcon\Di\DiInterface, Phalcon\Di\AbstractInjectionAware, Phalcon\Cli\Router\Route, Phalcon\Cli\Router\Exception |
| Extends    | AbstractInjectionAware |

Phalcon\Cli\Router is the standard framework router. Routing is the process
of taking a command-line arguments and decomposing it into parameters to
determine which module, task, and action of that task should receive the
request.

```php
$router = new \Phalcon\Cli\Router();

$router->handle(
    [
        "module" => "main",
        "task"   => "videos",
        "action" => "process",
    ]
);

echo $router->getTaskName();
```


## Properties
```php
//
protected action;

//
protected defaultAction;

//
protected defaultModule;

/**
 * @var array
 */
protected defaultParams;

//
protected defaultTask;

//
protected matchedRoute;

//
protected matches;

//
protected module;

/**
 * @var array
 */
protected params;

//
protected routes;

//
protected task;

//
protected wasMatched = false;

```

## Methods
```php
public function __construct( bool $defaultRoutes = bool ): void;
```
Phalcon\Cli\Router constructor


```php
public function add( string $pattern, mixed $paths = null ): RouteInterface;
```
Adds a route to the router

```php
$router->add("/about", "About::main");
```

@param string|array paths


```php
public function getActionName(): string;
```
Returns processed action name


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
Returns processed module name


```php
public function getParams(): array;
```
Returns processed extra params


```php
public function getRouteById( mixed $id ): RouteInterface | bool;
```
Returns a route object by its id

@param int id


```php
public function getRouteByName( string $name ): RouteInterface | bool;
```
Returns a route object by its name


```php
public function getRoutes(): Route[];
```
Returns all the routes defined in the router


```php
public function getTaskName(): string;
```
Returns processed task name


```php
public function handle( mixed $arguments = null );
```
Handles routing information received from command-line arguments

@param array arguments


```php
public function setDefaultAction( string $actionName );
```
Sets the default action name


```php
public function setDefaultModule( string $moduleName );
```
Sets the name of the default module


```php
public function setDefaultTask( string $taskName ): void;
```
Sets the default controller name


```php
public function setDefaults( array $defaults ): Router;
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
public function wasMatched(): bool;
```
Checks if the router matches any of the defined routes



        
<h1 id="cli-router-exception">Class Phalcon\Cli\Router\Exception</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/cli/router/exception.zep)

| Namespace  | Phalcon\Cli\Router |
| Extends    | \Phalcon\Exception |

Exceptions thrown in Phalcon\Cli\Router will use this class


        
<h1 id="cli-router-route">Class Phalcon\Cli\Router\Route</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/cli/router/route.zep)

| Namespace  | Phalcon\Cli\Router |

This class represents every route added to the router


## Constants
```php
const DEFAULT_DELIMITER =  ;
```

## Properties
```php
//
protected beforeMatch;

//
protected compiledPattern;

//
protected converters;

//
protected delimiter;

//
protected static delimiterPath;

//
protected description;

//
protected id;

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
public function __construct( string $pattern, mixed $paths = null ): void;
```
@param array|string paths


```php
public function beforeMatch( mixed $callback ): RouteInterface;
```
Sets a callback that is called if the route is matched.
The developer can implement any arbitrary conditions here
If the callback returns false the route is treated as not matched

@param callback callback


```php
public function compilePattern( string $pattern ): string;
```
Replaces placeholders from pattern returning a valid PCRE regular
expression


```php
public function convert( string $name, mixed $converter ): RouteInterface;
```
Adds a converter to perform an additional transformation for certain
parameter

@param callable converter


```php
public function extractNamedParams( string $pattern ): array | bool;
```
Extracts parameters from a string


```php
public function getBeforeMatch(): mixed;
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
public function getDescription(): string;
```
Returns the route's description


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

@param array|string paths


```php
public function setDescription( string $description ): RouteInterface;
```
Sets the route's description


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



        
<h1 id="cli-router-routeinterface">Interface Phalcon\Cli\Router\RouteInterface</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/cli/router/routeinterface.zep)

| Namespace  | Phalcon\Cli\Router |

Interface for Phalcon\Cli\Router\Route


## Methods
```php
public function compilePattern( string $pattern ): string;
```
Replaces placeholders from pattern returning a valid PCRE regular
expression


```php
public function getCompiledPattern(): string;
```
Returns the route's pattern


```php
public function getDescription(): string;
```
Returns the route's description


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
public function setDescription( string $description ): RouteInterface;
```
Sets the route's description


```php
public function setName( string $name ): RouteInterface;
```
Sets the route's name



        
<h1 id="cli-routerinterface">Interface Phalcon\Cli\RouterInterface</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/cli/routerinterface.zep)

| Namespace  | Phalcon\Cli |
| Uses       | Phalcon\Cli\Router\RouteInterface |

Interface for Phalcon\Cli\Router


## Methods
```php
public function add( string $pattern, mixed $paths = null ): RouteInterface;
```
Adds a route to the router on any HTTP method


```php
public function getActionName(): string;
```
Returns processed action name


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
public function getParams(): array;
```
Returns processed extra params


```php
public function getRouteById( mixed $id ): RouteInterface;
```
Returns a route object by its id


```php
public function getRouteByName( string $name ): RouteInterface;
```
Returns a route object by its name


```php
public function getRoutes(): RouteInterface[];
```
Return all the routes defined in the router


```php
public function getTaskName(): string;
```
Returns processed task name


```php
public function handle( mixed $arguments = null );
```
Handles routing information received from the rewrite engine

@param array arguments


```php
public function setDefaultAction( string $actionName ): void;
```
Sets the default action name


```php
public function setDefaultModule( string $moduleName ): void;
```
Sets the name of the default module


```php
public function setDefaultTask( string $taskName ): void;
```
Sets the default task name


```php
public function setDefaults( array $defaults ): void;
```
Sets an array of default paths


```php
public function wasMatched(): bool;
```
Check if the router matches any of the defined routes



        
<h1 id="cli-task">Class Phalcon\Cli\Task</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/cli/task.zep)

| Namespace  | Phalcon\Cli |
| Uses       | Phalcon\Di\Injectable |
| Extends    | Injectable |
| Implements | TaskInterface |

Every command-line task should extend this class that encapsulates all the
task functionality

A task can be used to run "tasks" such as migrations, cronjobs, unit-tests,
or anything that you want. The Task class should at least have a "mainAction"
method.

```php
class HelloTask extends \Phalcon\Cli\Task
{
    // This action will be executed by default
    public function mainAction()
    {

    }

    public function findAction()
    {

    }
}
```


## Methods
```php
final public function __construct(): void;
```
Phalcon\Cli\Task constructor



        
<h1 id="cli-taskinterface">Interface Phalcon\Cli\TaskInterface</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/cli/taskinterface.zep)

| Namespace  | Phalcon\Cli |

Interface for task handlers

