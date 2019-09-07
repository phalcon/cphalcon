---
layout: default
language: 'en'
version: '4.0'
title: 'Phalcon\Messages'
---

* [Phalcon\Messages\Exception](#messages-exception)
* [Phalcon\Messages\Message](#messages-message)
* [Phalcon\Messages\MessageInterface](#messages-messageinterface)
* [Phalcon\Messages\Messages](#messages-messages)
        
<h1 id="messages-exception">Class Phalcon\Messages\Exception</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/messages/exception.zep)

| Namespace  | Phalcon\Messages |
| Extends    | \Phalcon\Exception |

Phalcon\Validation\Exception

Exceptions thrown in Phalcon\Messages\* classes will use this class


        
<h1 id="messages-message">Class Phalcon\Messages\Message</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/messages/message.zep)

| Namespace  | Phalcon\Messages |
| Uses       | JsonSerializable, Phalcon\Messages\MessageInterface |
| Implements | MessageInterface, JsonSerializable |

Phalcon\Messages\Message

Stores a message from various components


## Properties
```php
/**
 * @var int
 */
protected code;

/**
 * @var string
 */
protected field;

/**
 * @var string
 */
protected message;

/**
 * @var string
 */
protected type;

/**
 * @var array
 */
protected metaData;

```

## Methods
```php
public function __construct( string $message, mixed $field = string, string $type = string, int $code = int, array $metaData = [] ): void;
```
Phalcon\Messages\Message constructor


```php
public function __toString(): string;
```
Magic __toString method returns verbose message


```php
public function getCode(): int
```


```php
public function getField(): string
```


```php
public function getMessage(): string
```


```php
public function getMetaData(): array
```


```php
public function getType(): string
```


```php
public function jsonSerialize(): array;
```
Serializes the object for json_encode


```php
public function setCode( int $code ): MessageInterface;
```
Sets code for the message


```php
public function setField( mixed $field ): MessageInterface;
```
Sets field name related to message


```php
public function setMessage( string $message ): MessageInterface;
```
Sets verbose message


```php
public function setMetaData( array $metaData ): MessageInterface;
```
Sets message metadata


```php
public function setType( string $type ): MessageInterface;
```
Sets message type



        
<h1 id="messages-messageinterface">Interface Phalcon\Messages\MessageInterface</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/messages/messageinterface.zep)

| Namespace  | Phalcon\Messages |
| Uses       | Phalcon\Messages\Message |

Phalcon\Messages\MessageInterface

Interface for Phalcon\Messages\MessageInterface


## Methods
```php
public function __toString(): string;
```
Magic __toString method returns verbose message


```php
public function getCode();
```
Returns the message code related to this message

@return int


```php
public function getField();
```
Returns field name related to message

@return string


```php
public function getMessage(): string;
```
Returns verbose message


```php
public function getMetaData(): array;
```
Returns message metadata


```php
public function getType(): string;
```
Returns message type


```php
public function setCode( int $code ): MessageInterface;
```
Sets code for the message


```php
public function setField( string $field ): MessageInterface;
```
Sets field name related to message


```php
public function setMessage( string $message ): MessageInterface;
```
Sets verbose message


```php
public function setMetaData( array $metaData ): MessageInterface;
```
Sets message metadata


```php
public function setType( string $type ): MessageInterface;
```
Sets message type



        
<h1 id="messages-messages">Class Phalcon\Messages\Messages</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/messages/messages.zep)

| Namespace  | Phalcon\Messages |
| Uses       | ArrayAccess, Countable, Iterator, JsonSerializable, Phalcon\Messages\Message, Phalcon\Messages\Exception, Phalcon\Messages\MessageInterface |
| Implements | ArrayAccess, Countable, Iterator, JsonSerializable |

Represents a collection of messages


## Properties
```php
/**
 * @var int
 */
protected position = 0;

/**
 * @var array
 */
protected messages;

```

## Methods
```php
public function __construct( array $messages = [] ): void;
```
Phalcon\Messages\Messages constructor


```php
public function appendMessage( MessageInterface $message );
```
Appends a message to the collection

```php
$messages->appendMessage(
    new \Phalcon\Messages\Message("This is a message")
);
```


```php
public function appendMessages( mixed $messages );
```
Appends an array of messages to the collection

```php
$messages->appendMessages($messagesArray);
```

@param \Phalcon\Messages\MessageInterface[] messages


```php
public function count(): int;
```
Returns the number of messages in the list


```php
public function current(): MessageInterface;
```
Returns the current message in the iterator


```php
public function filter( string $fieldName ): array;
```
Filters the message collection by field name


```php
public function jsonSerialize(): array;
```
Returns serialised message objects as array for json_encode. Calls
jsonSerialize on each object if present

```php
$data = $messages->jsonSerialize();
echo json_encode($data);
```


```php
public function key(): int;
```
Returns the current position/key in the iterator


```php
public function next(): void;
```
Moves the internal iteration pointer to the next position


```php
public function offsetExists( mixed $index ): bool;
```
Checks if an index exists

```php
var_dump(
    isset($message["database"])
);
```

@param int index


```php
public function offsetGet( mixed $index ): mixed;
```
Gets an attribute a message using the array syntax

```php
print_r(
    $messages[0]
);
```


```php
public function offsetSet( mixed $index, mixed $message ): void;
```
Sets an attribute using the array-syntax

```php
$messages[0] = new \Phalcon\Messages\Message("This is a message");
```

@param \Phalcon\Messages\Message message


```php
public function offsetUnset( mixed $index ): void;
```
Removes a message from the list

```php
unset($message["database"]);
```


```php
public function rewind(): void;
```
Rewinds the internal iterator


```php
public function valid(): bool;
```
Check if the current message in the iterator is valid


