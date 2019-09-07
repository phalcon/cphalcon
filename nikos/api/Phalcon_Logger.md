---
layout: default
language: 'en'
version: '4.0'
title: 'Phalcon\Logger'
---

* [Phalcon\Logger](#logger)
* [Phalcon\Logger\Adapter\AbstractAdapter](#logger-adapter-abstractadapter)
* [Phalcon\Logger\Adapter\AdapterInterface](#logger-adapter-adapterinterface)
* [Phalcon\Logger\Adapter\Noop](#logger-adapter-noop)
* [Phalcon\Logger\Adapter\Stream](#logger-adapter-stream)
* [Phalcon\Logger\Adapter\Syslog](#logger-adapter-syslog)
* [Phalcon\Logger\AdapterFactory](#logger-adapterfactory)
* [Phalcon\Logger\Exception](#logger-exception)
* [Phalcon\Logger\Formatter\AbstractFormatter](#logger-formatter-abstractformatter)
* [Phalcon\Logger\Formatter\FormatterInterface](#logger-formatter-formatterinterface)
* [Phalcon\Logger\Formatter\Json](#logger-formatter-json)
* [Phalcon\Logger\Formatter\Line](#logger-formatter-line)
* [Phalcon\Logger\Formatter\Syslog](#logger-formatter-syslog)
* [Phalcon\Logger\Item](#logger-item)
* [Phalcon\Logger\LoggerFactory](#logger-loggerfactory)
        
<h1 id="logger">Class Phalcon\Logger</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/logger.zep)

| Namespace  | Phalcon |
| Uses       | Psr\Log\LoggerInterface, Psr\Log\InvalidArgumentException, Phalcon\Logger\Adapter\AdapterInterface, Phalcon\Logger\Item, Phalcon\Logger\Exception |
| Implements | LoggerInterface |

Phalcon\Logger

This component offers logging capabilities for your application. The
component accepts multiple adapters, working also as a multiple logger.
Phalcon\Logger implements PSR-3.

```php
use Phalcon\Logger;
use Phalcon\Logger\Adapter\Stream;

$adapter1 = new Stream('/logs/first-log.log');
$adapter2 = new Stream('/remote/second-log.log');
$adapter3 = new Stream('/manager/third-log.log');

$logger = new Logger(
        'messages',
        [
            'local'   => $adapter1,
            'remote'  => $adapter2,
            'manager' => $adapter3,
        ]
    );

// Log to all adapters
$logger->error('Something went wrong');

// Log to specific adapters
$logger
        ->excludeAdapters(['manager'])
        ->info('This does not go to the "manager" logger);
```


## Constants
```php
const ALERT = 2;
const CRITICAL = 1;
const CUSTOM = 8;
const DEBUG = 7;
const EMERGENCY = 0;
const ERROR = 3;
const INFO = 6;
const NOTICE = 5;
const WARNING = 4;
```

## Properties
```php
/**
 * The adapter stack
 *
 * @var AdapterInterface[]
 */
protected adapters;

/**
 * @var string
 */
protected name = ;

/**
 * The excluded adapters for this log process
 *
 * @var AdapterInterface[]
 */
protected excluded;

```

## Methods
```php
public function __construct( string $name, array $adapters = [] ): void;
```
Constructor.

@param string name     The name of the logger
@param array  adapters The collection of adapters to be used for logging (default [])


```php
public function addAdapter( string $name, AdapterInterface $adapter ): Logger;
```
Add an adapter to the stack. For processing we use FIFO

@param string             name    The name of the adapter
@param <AdapterInterface> adapter The adapter to add to the stack


```php
public function alert( mixed $message, array $context = [] ): void;
```
Action must be taken immediately.

Example: Entire website down, database unavailable, etc. This should
trigger the SMS alerts and wake you up.

@param string message


```php
public function critical( mixed $message, array $context = [] ): void;
```
Critical conditions.

Example: Application component unavailable, unexpected exception.

@param string message


```php
public function debug( mixed $message, array $context = [] ): void;
```
Detailed debug information.

@param string message


```php
public function emergency( mixed $message, array $context = [] ): void;
```
System is unusable.

@param string message


```php
public function error( mixed $message, array $context = [] ): void;
```
Runtime errors that do not require immediate action but should typically
be logged and monitored.

@param string message


```php
public function excludeAdapters( array $adapters = [] ): Logger;
```
Exclude certain adapters.


```php
public function getAdapter( string $name ): AdapterInterface;
```
Returns an adapter from the stack

@param string name The name of the adapter

@throws <Exception>


```php
public function getAdapters(): array;
```
Returns the adapter stack array

@return AdapterInterface[]


```php
public function getName(): string;
```
Returns the name of the logger


```php
public function info( mixed $message, array $context = [] ): void;
```
Interesting events.

Example: User logs in, SQL logs.

@param string message


```php
public function log( mixed $level, mixed $message, array $context = [] ): void;
```
Logs with an arbitrary level.

@param mixed  level
@param string message


```php
public function notice( mixed $message, array $context = [] ): void;
```
Normal but significant events.

@param string message


```php
public function removeAdapter( string $name ): Logger;
```
Removes an adapter from the stack

@param string name The name of the adapter

@throws <Logger\Exception>


```php
public function setAdapters( array $adapters ): Logger;
```
Sets the adapters stack overriding what is already there

@param array adapters An array of adapters


```php
public function warning( mixed $message, array $context = [] ): void;
```
Exceptional occurrences that are not errors.

Example: Use of deprecated APIs, poor use of an API, undesirable things
that are not necessarily wrong.

@param string message


```php
protected function addMessage( int $level, string $message, array $context = [] ): bool;
```
Adds a message to each handler for processing

@param int    level
@param string message

@throws <Logger\Exception>


```php
protected function getLevels(): array;
```
Returns an array of log levels with integer to string conversion



        
<h1 id="logger-adapter-abstractadapter">Abstract Class Phalcon\Logger\Adapter\AbstractAdapter</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/logger/adapter/abstractadapter.zep)

| Namespace  | Phalcon\Logger\Adapter |
| Uses       | Phalcon\Logger, Phalcon\Logger\Adapter\AdapterInterface, Phalcon\Logger\Exception, Phalcon\Logger\Formatter\FormatterInterface, Phalcon\Logger\Item |
| Implements | AdapterInterface |

This file is part of the Phalcon Framework.

(c) Phalcon Team <team@phalcon.io>

For the full copyright and license information, please view the LICENSE.txt
file that was distributed with this source code.


## Properties
```php
/**
 * Name of the default formatter class
 *
 * @var string
 */
protected defaultFormatter = Line;

/**
 * Formatter
 *
 * @var <FormatterInterface>
 */
protected formatter;

/**
 * Tells if there is an active transaction or not
 *
 * @var bool
 */
protected inTransaction = false;

/**
 * Array with messages queued in the transaction
 *
 * @var array
 */
protected queue;

```

## Methods
```php
public function __destruct();
```
Destructor cleanup


```php
public function add( Item $item ): AdapterInterface;
```
Adds a message to the queue


```php
public function begin(): AdapterInterface;
```
Starts a transaction


```php
public function commit(): AdapterInterface;
```
Commits the internal transaction


```php
public function getFormatter(): FormatterInterface;
```
//

```php
public function inTransaction(): bool;
```
Returns the whether the logger is currently in an active transaction or not


```php
abstract public function process( Item $item ): void;
```
 Processes the message in the adapter
 

```php
public function rollback(): AdapterInterface;
```
Rollbacks the internal transaction


```php
public function setFormatter( FormatterInterface $formatter ): AdapterInterface;
```
Sets the message formatter



        
<h1 id="logger-adapter-adapterinterface">Interface Phalcon\Logger\Adapter\AdapterInterface</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/logger/adapter/adapterinterface.zep)

| Namespace  | Phalcon\Logger\Adapter |
| Uses       | Phalcon\Logger\Formatter\FormatterInterface, Phalcon\Logger\Item |

Phalcon\Logger\AdapterInterface

Interface for Phalcon\Logger adapters


## Methods
```php
public function add( Item $item ): void;
```
Adds a message in the queue


```php
public function begin(): AdapterInterface;
```
Starts a transaction


```php
public function close(): bool;
```
Closes the logger


```php
public function commit(): AdapterInterface;
```
Commits the internal transaction


```php
public function getFormatter(): FormatterInterface;
```
Returns the internal formatter


```php
public function process( Item $item ): void;
```
Processes the message in the adapter


```php
public function rollback(): AdapterInterface;
```
Rollbacks the internal transaction


```php
public function setFormatter( FormatterInterface $formatter ): AdapterInterface;
```
Sets the message formatter



        
<h1 id="logger-adapter-noop">Class Phalcon\Logger\Adapter\Noop</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/logger/adapter/noop.zep)

| Namespace  | Phalcon\Logger\Adapter |
| Uses       | Phalcon\Logger\Item |
| Extends    | AbstractAdapter |

Phalcon\Logger\Adapter\Noop

Adapter to store logs in plain text files

```php
$logger = new \Phalcon\Logger\Adapter\Noop();

$logger->log(\Phalcon\Logger::ERROR, "This is an error");
$logger->error("This is another error");

$logger->close();
```


## Methods
```php
public function close(): bool;
```
Closes the stream


```php
public function process( Item $item ): void;
```
Processes the message i.e. writes it to the file



        
<h1 id="logger-adapter-stream">Class Phalcon\Logger\Adapter\Stream</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/logger/adapter/stream.zep)

| Namespace  | Phalcon\Logger\Adapter |
| Uses       | Phalcon\Logger\Adapter, Phalcon\Logger\Exception, Phalcon\Logger\Formatter\FormatterInterface, Phalcon\Logger\Item, UnexpectedValueException |
| Extends    | AbstractAdapter |

Phalcon\Logger\Adapter\Stream

Adapter to store logs in plain text files

```php
$logger = new \Phalcon\Logger\Adapter\Stream("app/logs/test.log");

$logger->log("This is a message");
$logger->log(\Phalcon\Logger::ERROR, "This is an error");
$logger->error("This is another error");

$logger->close();
```


## Properties
```php
/**
 * Stream handler resource
 *
 * @var resource|null
 */
protected handler;

/**
 * The file open mode. Defaults to "ab"
 *
 * @var string
 */
protected mode = ab;

/**
 * Stream name
 *
 * @var string
 */
protected name;

/**
 * Path options
 *
 * @var array
 */
protected options;

```

## Methods
```php
public function __construct( string $name, array $options = [] );
```
Constructor. Accepts the name and some options


```php
public function close(): bool;
```
Closes the stream


```php
public function getName(): string
```


```php
public function process( Item $item ): void;
```
Processes the message i.e. writes it to the file



        
<h1 id="logger-adapter-syslog">Class Phalcon\Logger\Adapter\Syslog</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/logger/adapter/syslog.zep)

| Namespace  | Phalcon\Logger\Adapter |
| Uses       | LogicException, Phalcon\Logger, Phalcon\Logger\Adapter, Phalcon\Logger\Exception, Phalcon\Logger\Formatter\FormatterInterface, Phalcon\Logger\Item |
| Extends    | AbstractAdapter |

Phalcon\Logger\Adapter\Syslog

Sends logs to the system logger

```php
use Phalcon\Logger;
use Phalcon\Logger\Adapter\Syslog;

// LOG_USER is the only valid log type under Windows operating systems
$logger = new Syslog(
    "ident",
    [
        "option"   => LOG_CONS | LOG_NDELAY | LOG_PID,
        "facility" => LOG_USER,
    ]
);

$logger->log("This is a message");
$logger->log(Logger::ERROR, "This is an error");
$logger->error("This is another error");
```


## Properties
```php
/**
 * Name of the default formatter class
 *
 * @var string
 */
protected defaultFormatter = Syslog;

/**
 * @var int
 */
protected facility = 0;

/**
 * @var string
 */
protected name = ;

/**
 * @var bool
 */
protected opened = false;

/**
 * @var int
 */
protected option = 0;

```

## Methods
```php
public function __construct( string $name, array $options = [] );
```
Phalcon\Logger\Adapter\Syslog constructor


```php
public function close(): bool;
```
 Closes the logger
 

```php
public function process( Item $item ): void;
```
Processes the message i.e. writes it to the syslog



        
<h1 id="logger-adapterfactory">Class Phalcon\Logger\AdapterFactory</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/logger/adapterfactory.zep)

| Namespace  | Phalcon\Logger |
| Uses       | Phalcon\Factory\AbstractFactory |
| Extends    | AbstractFactory |

This file is part of the Phalcon Framework.

(c) Phalcon Team <team@phalcon.io>

For the full copyright and license information, please view the LICENSE.txt
file that was distributed with this source code.


## Methods
```php
public function __construct( array $services = [] );
```
AdapterFactory constructor.


```php
public function newInstance( string $name, string $fileName, array $options = [] ): AdapterInterface;
```
Create a new instance of the adapter


```php
protected function getAdapters(): array;
```
//


        
<h1 id="logger-exception">Class Phalcon\Logger\Exception</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/logger/exception.zep)

| Namespace  | Phalcon\Logger |
| Extends    | \Phalcon\Exception |

Phalcon\Logger\Exception

Exceptions thrown in Phalcon\Logger will use this class


        
<h1 id="logger-formatter-abstractformatter">Abstract Class Phalcon\Logger\Formatter\AbstractFormatter</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/logger/formatter/abstractformatter.zep)

| Namespace  | Phalcon\Logger\Formatter |
| Uses       | Phalcon\Logger |
| Implements | FormatterInterface |

This file is part of the Phalcon Framework.

(c) Phalcon Team <team@phalcon.io>

For the full copyright and license information, please view the LICENSE.txt
file that was distributed with this source code.


## Methods
```php
public function interpolate( string $message, mixed $context = null );
```
Interpolates context values into the message placeholders

@see http://www.php-fig.org/psr/psr-3/ Section 1.2 Message
@param string $message
@param array $context



        
<h1 id="logger-formatter-formatterinterface">Interface Phalcon\Logger\Formatter\FormatterInterface</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/logger/formatter/formatterinterface.zep)

| Namespace  | Phalcon\Logger\Formatter |
| Uses       | Phalcon\Logger\Item |

Phalcon\Logger\FormatterInterface

This interface must be implemented by formatters in Phalcon\Logger


## Methods
```php
public function format( Item $item ): string | array;
```
Applies a format to an item



        
<h1 id="logger-formatter-json">Class Phalcon\Logger\Formatter\Json</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/logger/formatter/json.zep)

| Namespace  | Phalcon\Logger\Formatter |
| Uses       | Phalcon\Logger\Formatter\AbstractFormatter, Phalcon\Logger\Item |
| Extends    | AbstractFormatter |

Phalcon\Logger\Formatter\Json

Formats messages using JSON encoding


## Properties
```php
/**
 * Default date format
 *
 * @var string
 */
protected dateFormat;

```

## Methods
```php
public function __construct( string $dateFormat = string ): void;
```
Phalcon\Logger\Formatter\Json construct


```php
public function format( Item $item ): string;
```
Applies a format to a message before sent it to the internal log


```php
public function getDateFormat(): string
```


```php
public function setDateFormat( string $dateFormat )
```



        
<h1 id="logger-formatter-line">Class Phalcon\Logger\Formatter\Line</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/logger/formatter/line.zep)

| Namespace  | Phalcon\Logger\Formatter |
| Uses       | Phalcon\Logger\Formatter\Formatter, Phalcon\Logger\Item |
| Extends    | AbstractFormatter |

Phalcon\Logger\Formatter\Line

Formats messages using an one-line string


## Properties
```php
/**
 * Default date format
 *
 * @var string
 */
protected dateFormat;

/**
 * Format applied to each message
 *
 * @var string
 */
protected format;

```

## Methods
```php
public function __construct( string $format = string, string $dateFormat = string ): void;
```
Phalcon\Logger\Formatter\Line construct


```php
public function format( Item $item ): string;
```
Applies a format to a message before sent it to the internal log


```php
public function getDateFormat(): string
```


```php
public function getFormat(): string
```


```php
public function setDateFormat( string $dateFormat )
```


```php
public function setFormat( string $format )
```



        
<h1 id="logger-formatter-syslog">Class Phalcon\Logger\Formatter\Syslog</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/logger/formatter/syslog.zep)

| Namespace  | Phalcon\Logger\Formatter |
| Uses       | Phalcon\Logger\Formatter\AbstractFormatter, Phalcon\Logger\Item |
| Extends    | AbstractFormatter |

Phalcon\Logger\Formatter\Syslog

Prepares a message to be used in a Syslog backend


## Methods
```php
public function format( Item $item ): array;
```
Applies a format to a message before sent it to the internal log



        
<h1 id="logger-item">Class Phalcon\Logger\Item</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/logger/item.zep)

| Namespace  | Phalcon\Logger |

Phalcon\Logger\Item

Represents each item in a logging transaction



## Properties
```php
//
protected context;

/**
 * Log message
 *
 * @var string
 */
protected message;

/**
 * Log message
 *
 * @var string
 */
protected name;

/**
 * Log timestamp
 *
 * @var integer
 */
protected time;

/**
 * Log type
 *
 * @var integer
 */
protected type;

```

## Methods
```php
public function __construct( string $message, string $name, int $type, int $time = int, mixed $context = [] );
```
Phalcon\Logger\Item constructor


```php
public function getContext()
```


```php
public function getMessage(): string
```


```php
public function getName(): string
```


```php
public function getTime(): integer
```


```php
public function getType(): integer
```



        
<h1 id="logger-loggerfactory">Class Phalcon\Logger\LoggerFactory</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/logger/loggerfactory.zep)

| Namespace  | Phalcon\Logger |
| Uses       | Phalcon\Config, Phalcon\Helper\Arr, Phalcon\Logger, Phalcon\Logger\AdapterFactory |

PhalconNG\Logger\LoggerFactory

Logger factory


## Properties
```php
/**
 * @var AdapterFactory
 */
private adapterFactory;

```

## Methods
```php
public function __construct( AdapterFactory $factory );
```
//

```php
public function load( mixed $config ): mixed;
```
Factory to create an instace from a Config object


```php
public function newInstance( string $name, array $adapters = [] ): Logger;
```
Returns a Logger object

@param string $name
@param array  $adapters

@return Logger


