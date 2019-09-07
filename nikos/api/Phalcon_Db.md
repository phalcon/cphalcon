---
layout: default
language: 'en'
version: '4.0'
title: 'Phalcon\Db'
---

* [Phalcon\Db\AbstractDb](#db-abstractdb)
* [Phalcon\Db\Adapter\AbstractAdapter](#db-adapter-abstractadapter)
* [Phalcon\Db\Adapter\AdapterInterface](#db-adapter-adapterinterface)
* [Phalcon\Db\Adapter\Pdo\AbstractPdo](#db-adapter-pdo-abstractpdo)
* [Phalcon\Db\Adapter\Pdo\Mysql](#db-adapter-pdo-mysql)
* [Phalcon\Db\Adapter\Pdo\Postgresql](#db-adapter-pdo-postgresql)
* [Phalcon\Db\Adapter\Pdo\Sqlite](#db-adapter-pdo-sqlite)
* [Phalcon\Db\Adapter\PdoFactory](#db-adapter-pdofactory)
* [Phalcon\Db\Column](#db-column)
* [Phalcon\Db\ColumnInterface](#db-columninterface)
* [Phalcon\Db\Dialect](#db-dialect)
* [Phalcon\Db\Dialect\Mysql](#db-dialect-mysql)
* [Phalcon\Db\Dialect\Postgresql](#db-dialect-postgresql)
* [Phalcon\Db\Dialect\Sqlite](#db-dialect-sqlite)
* [Phalcon\Db\DialectInterface](#db-dialectinterface)
* [Phalcon\Db\Enum](#db-enum)
* [Phalcon\Db\Exception](#db-exception)
* [Phalcon\Db\Index](#db-index)
* [Phalcon\Db\IndexInterface](#db-indexinterface)
* [Phalcon\Db\Profiler](#db-profiler)
* [Phalcon\Db\Profiler\Item](#db-profiler-item)
* [Phalcon\Db\RawValue](#db-rawvalue)
* [Phalcon\Db\Reference](#db-reference)
* [Phalcon\Db\ReferenceInterface](#db-referenceinterface)
* [Phalcon\Db\Result\Pdo](#db-result-pdo)
* [Phalcon\Db\ResultInterface](#db-resultinterface)
        
<h1 id="db-abstractdb">Abstract Class Phalcon\Db\AbstractDb</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/db/abstractdb.zep)

| Namespace  | Phalcon\Db |
| Uses       | \PDO |

Phalcon\Db and its related classes provide a simple SQL database interface
for Phalcon Framework. The Phalcon\Db is the basic class you use to connect
your PHP application to an RDBMS. There is a different adapter class for each
brand of RDBMS.

This component is intended to lower level database operations. If you want to
interact with databases using higher level of abstraction use
Phalcon\Mvc\Model.

Phalcon\Db\AbstractDb is an abstract class. You only can use it with a
database adapter like Phalcon\Db\Adapter\Pdo

```php
use Phalcon\Db;
use Phalcon\Db\Exception;
use Phalcon\Db\Adapter\Pdo\Mysql as MysqlConnection;

try {
    $connection = new MysqlConnection(
        [
            "host"     => "192.168.0.11",
            "username" => "sigma",
            "password" => "secret",
            "dbname"   => "blog",
            "port"     => "3306",
        ]
    );

    $result = $connection->query(
        "SELECTFROM robots LIMIT 5"
    );

    $result->setFetchMode(Enum::FETCH_NUM);

    while ($robot = $result->fetch()) {
        print_r($robot);
    }
} catch (Exception $e) {
    echo $e->getMessage(), PHP_EOL;
}
```


        
<h1 id="db-adapter-abstractadapter">Abstract Class Phalcon\Db\Adapter\AbstractAdapter</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/db/adapter/abstractadapter.zep)

| Namespace  | Phalcon\Db\Adapter |
| Uses       | Phalcon\Db\DialectInterface, Phalcon\Db\Adapter\AdapterInterface, Phalcon\Db\ColumnInterface, Phalcon\Db\Enum, Phalcon\Db\Exception, Phalcon\Db\Index, Phalcon\Db\IndexInterface, Phalcon\Db\Reference, Phalcon\Db\ReferenceInterface, Phalcon\Db\RawValue, Phalcon\Events\EventsAwareInterface, Phalcon\Events\ManagerInterface |
| Implements | AdapterInterface, EventsAwareInterface |

Base class for Phalcon\Db adapters


## Properties
```php
/**
 * Connection ID
 */
protected static connectionConsecutive = 0;

/**
 * Active connection ID
 *
 * @var long
 */
protected connectionId;

/**
 * Descriptor used to connect to a database
 */
protected descriptor;

/**
 * Dialect instance
 */
protected dialect;

/**
 * Name of the dialect used
 *
 * @var string
 */
protected dialectType;

/**
 * Event Manager
 *
 * @var Phalcon\Events\Manager
 */
protected eventsManager;

/**
 * Active SQL Bind Types
 *
 * @var array
 */
protected sqlBindTypes;

/**
 * Active SQL Statement
 *
 * @var string
 */
protected sqlStatement;

/**
 * Active SQL bound parameter variables
 *
 * @var array
 */
protected sqlVariables;

/**
 * Current transaction level
 */
protected transactionLevel = 0;

/**
 * Whether the database supports transactions with save points
 */
protected transactionsWithSavepoints = false;

/**
 * Type of database system the adapter is used for
 *
 * @var string
 */
protected type;

```

## Methods
```php
public function __construct( array $descriptor );
```
Phalcon\Db\Adapter constructor


```php
public function addColumn( string $tableName, string $schemaName, ColumnInterface $column ): bool;
```
Adds a column to a table


```php
public function addForeignKey( string $tableName, string $schemaName, ReferenceInterface $reference ): bool;
```
Adds a foreign key to a table


```php
public function addIndex( string $tableName, string $schemaName, IndexInterface $index ): bool;
```
Adds an index to a table


```php
public function addPrimaryKey( string $tableName, string $schemaName, IndexInterface $index ): bool;
```
Adds a primary key to a table


```php
public function createSavepoint( string $name ): bool;
```
Creates a new savepoint


```php
public function createTable( string $tableName, string $schemaName, array $definition ): bool;
```
Creates a table


```php
public function createView( string $viewName, array $definition, string $schemaName = null ): bool;
```
Creates a view


```php
public function delete( mixed $table, mixed $whereCondition = null, mixed $placeholders = null, mixed $dataTypes = null ): bool;
```
Deletes data from a table using custom RBDM SQL syntax

```php
// Deleting existing robot
$success = $connection->delete(
    "robots",
    "id = 101"
);

// Next SQL sentence is generated
DELETE FROM `robots` WHERE `id` = 101
```


```php
public function describeIndexes( string $table, string $schema = null ): IndexInterface[];
```
Lists table indexes

```php
print_r(
    $connection->describeIndexes("robots_parts")
);
```


```php
public function describeReferences( string $table, string $schema = null ): ReferenceInterface[];
```
Lists table references

```php
print_r(
    $connection->describeReferences("robots_parts")
);
```


```php
public function dropColumn( string $tableName, string $schemaName, string $columnName ): bool;
```
Drops a column from a table


```php
public function dropForeignKey( string $tableName, string $schemaName, string $referenceName ): bool;
```
Drops a foreign key from a table


```php
public function dropIndex( string $tableName, string $schemaName, mixed $indexName ): bool;
```
Drop an index from a table


```php
public function dropPrimaryKey( string $tableName, string $schemaName ): bool;
```
Drops a table's primary key


```php
public function dropTable( string $tableName, string $schemaName = null, bool $ifExists = bool ): bool;
```
Drops a table from a schema/database


```php
public function dropView( string $viewName, string $schemaName = null, bool $ifExists = bool ): bool;
```
Drops a view


```php
public function escapeIdentifier( mixed $identifier ): string;
```
Escapes a column/table/schema name

```php
$escapedTable = $connection->escapeIdentifier(
    "robots"
);

$escapedTable = $connection->escapeIdentifier(
    [
        "store",
        "robots",
    ]
);
```


```php
public function fetchAll( string $sqlQuery, int $fetchMode = static-constant-access, mixed $bindParams = null, mixed $bindTypes = null ): array;
```
Dumps the complete result of a query into an array

```php
// Getting all robots with associative indexes only
$robots = $connection->fetchAll(
    "SELECTFROM robots",
    \Phalcon\Db\Enum::FETCH_ASSOC
);

foreach ($robots as $robot) {
    print_r($robot);
}

 // Getting all robots that contains word "robot" withing the name
$robots = $connection->fetchAll(
    "SELECTFROM robots WHERE name LIKE :name",
    \Phalcon\Db\Enum::FETCH_ASSOC,
    [
        "name" => "%robot%",
    ]
);
foreach($robots as $robot) {
    print_r($robot);
}
```


```php
public function fetchColumn( string $sqlQuery, array $placeholders = [], mixed $column = int ): string | bool;
```
Returns the n'th field of first row in a SQL query result

```php
// Getting count of robots
$robotsCount = $connection->fetchColumn("SELECT count(*) FROM robots");
print_r($robotsCount);

// Getting name of last edited robot
$robot = $connection->fetchColumn(
    "SELECT id, name FROM robots order by modified desc",
    1
);
print_r($robot);
```


```php
public function fetchOne( string $sqlQuery, mixed $fetchMode = static-constant-access, mixed $bindParams = null, mixed $bindTypes = null ): array;
```
Returns the first row in a SQL query result

```php
// Getting first robot
$robot = $connection->fetchOne("SELECTFROM robots");
print_r($robot);

// Getting first robot with associative indexes only
$robot = $connection->fetchOne(
    "SELECTFROM robots",
    \Phalcon\Db\Enum::FETCH_ASSOC
);
print_r($robot);
```


```php
public function forUpdate( string $sqlQuery ): string;
```
Returns a SQL modified with a FOR UPDATE clause


```php
public function getColumnDefinition( ColumnInterface $column ): string;
```
Returns the SQL column definition from a column


```php
public function getColumnList( mixed $columnList ): string;
```
Gets a list of columns


```php
public function getConnectionId(): string;
```
Gets the active connection unique identifier


```php
public function getDefaultIdValue(): RawValue;
```
Returns the default identity value to be inserted in an identity column

```php
// Inserting a new robot with a valid default value for the column 'id'
$success = $connection->insert(
    "robots",
    [
        $connection->getDefaultIdValue(),
        "Astro Boy",
        1952,
    ],
    [
        "id",
        "name",
        "year",
    ]
);
```


```php
public function getDefaultValue(): RawValue;
```
Returns the default value to make the RBDM use the default value declared
in the table definition

```php
// Inserting a new robot with a valid default value for the column 'year'
$success = $connection->insert(
    "robots",
    [
        "Astro Boy",
        $connection->getDefaultValue()
    ],
    [
        "name",
        "year",
    ]
);
```


```php
public function getDescriptor(): array;
```
Return descriptor used to connect to the active database


```php
public function getDialect(): DialectInterface;
```
Returns internal dialect instance


```php
public function getDialectType(): string
```


```php
public function getEventsManager(): ManagerInterface;
```
Returns the internal event manager


```php
public function getNestedTransactionSavepointName(): string;
```
Returns the savepoint name to use for nested transactions


```php
public function getRealSQLStatement(): string;
```
Active SQL statement in the object without replace bound parameters


```php
public function getSQLBindTypes(): array;
```
Active SQL statement in the object


```php
public function getSQLStatement(): string;
```
Active SQL statement in the object


```php
public function getSqlVariables(): array
```


```php
public function getType(): string
```


```php
public function insert( string $table, array $values, mixed $fields = null, mixed $dataTypes = null ): bool;
```
Inserts data into a table using custom RDBMS SQL syntax

```php
// Inserting a new robot
$success = $connection->insert(
    "robots",
    ["Astro Boy", 1952],
    ["name", "year"]
);

// Next SQL sentence is sent to the database system
INSERT INTO `robots` (`name`, `year`) VALUES ("Astro boy", 1952);
```


```php
public function insertAsDict( string $table, mixed $data, mixed $dataTypes = null ): bool;
```
Inserts data into a table using custom RBDM SQL syntax

```php
// Inserting a new robot
$success = $connection->insertAsDict(
    "robots",
    [
        "name" => "Astro Boy",
        "year" => 1952,
    ]
);

// Next SQL sentence is sent to the database system
INSERT INTO `robots` (`name`, `year`) VALUES ("Astro boy", 1952);
```


```php
public function isNestedTransactionsWithSavepoints(): bool;
```
Returns if nested transactions should use savepoints


```php
public function limit( string $sqlQuery, int $number ): string;
```
Appends a LIMIT clause to $sqlQuery argument

```php
echo $connection->limit("SELECTFROM robots", 5);
```


```php
public function listTables( string $schemaName = null ): array;
```
List all tables on a database

```php
print_r(
    $connection->listTables("blog")
);
```


```php
public function listViews( string $schemaName = null ): array;
```
List all views on a database

```php
print_r(
    $connection->listViews("blog")
);
```


```php
public function modifyColumn( string $tableName, string $schemaName, ColumnInterface $column, ColumnInterface $currentColumn = null ): bool;
```
Modifies a table column based on a definition


```php
public function releaseSavepoint( string $name ): bool;
```
Releases given savepoint


```php
public function rollbackSavepoint( string $name ): bool;
```
Rollbacks given savepoint


```php
public function setDialect( DialectInterface $dialect );
```
Sets the dialect used to produce the SQL


```php
public function setEventsManager( ManagerInterface $eventsManager ): void;
```
Sets the event manager


```php
public function setNestedTransactionsWithSavepoints( bool $nestedTransactionsWithSavepoints ): AdapterInterface;
```
Set if nested transactions should use savepoints


```php
public function sharedLock( string $sqlQuery ): string;
```
Returns a SQL modified with a LOCK IN SHARE MODE clause


```php
public function supportSequences(): bool;
```
Check whether the database system requires a sequence to produce
auto-numeric values


```php
public function tableExists( string $tableName, string $schemaName = null ): bool;
```
Generates SQL checking for the existence of a schema.table

```php
var_dump(
    $connection->tableExists("blog", "posts")
);
```


```php
public function tableOptions( string $tableName, string $schemaName = null ): array;
```
Gets creation options from a table

```php
print_r(
    $connection->tableOptions("robots")
);
```


```php
public function update( string $table, mixed $fields, mixed $values, mixed $whereCondition = null, mixed $dataTypes = null ): bool;
```
Updates data on a table using custom RBDM SQL syntax

```php
// Updating existing robot
$success = $connection->update(
    "robots",
    ["name"],
    ["New Astro Boy"],
    "id = 101"
);

// Next SQL sentence is sent to the database system
UPDATE `robots` SET `name` = "Astro boy" WHERE id = 101

// Updating existing robot with array condition and $dataTypes
$success = $connection->update(
    "robots",
    ["name"],
    ["New Astro Boy"],
    [
        "conditions" => "id = ?",
        "bind"       => [$some_unsafe_id],
        "bindTypes"  => [PDO::PARAM_INT], // use only if you use $dataTypes param
    ],
    [
        PDO::PARAM_STR
    ]
);

```

Warning! If $whereCondition is string it not escaped.


```php
public function updateAsDict( string $table, mixed $data, mixed $whereCondition = null, mixed $dataTypes = null ): bool;
```
Updates data on a table using custom RBDM SQL syntax
Another, more convenient syntax

```php
// Updating existing robot
$success = $connection->updateAsDict(
    "robots",
    [
        "name" => "New Astro Boy",
    ],
    "id = 101"
);

// Next SQL sentence is sent to the database system
UPDATE `robots` SET `name` = "Astro boy" WHERE id = 101
```


```php
public function useExplicitIdValue(): bool;
```
Check whether the database system requires an explicit value for identity
columns


```php
public function viewExists( string $viewName, string $schemaName = null ): bool;
```
Generates SQL checking for the existence of a schema.view

```php
var_dump(
    $connection->viewExists("active_users", "posts")
);
```



        
<h1 id="db-adapter-adapterinterface">Interface Phalcon\Db\Adapter\AdapterInterface</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/db/adapter/adapterinterface.zep)

| Namespace  | Phalcon\Db\Adapter |
| Uses       | Phalcon\Db\DialectInterface, Phalcon\Db\ResultInterface, Phalcon\Db\ColumnInterface, Phalcon\Db\IndexInterface, Phalcon\Db\RawValue, Phalcon\Db\ReferenceInterface |

Interface for Phalcon\Db adapters


## Methods
```php
public function addColumn( string $tableName, string $schemaName, ColumnInterface $column ): bool;
```
Adds a column to a table


```php
public function addForeignKey( string $tableName, string $schemaName, ReferenceInterface $reference ): bool;
```
Adds a foreign key to a table


```php
public function addIndex( string $tableName, string $schemaName, IndexInterface $index ): bool;
```
Adds an index to a table


```php
public function addPrimaryKey( string $tableName, string $schemaName, IndexInterface $index ): bool;
```
Adds a primary key to a table


```php
public function affectedRows(): int;
```
Returns the number of affected rows by the last INSERT/UPDATE/DELETE
reported by the database system


```php
public function begin( bool $nesting = bool ): bool;
```
Starts a transaction in the connection


```php
public function close(): bool;
```
Closes active connection returning success. Phalcon automatically closes
and destroys active connections within Phalcon\Db\Pool


```php
public function commit( bool $nesting = bool ): bool;
```
Commits the active transaction in the connection


```php
public function connect( array $descriptor = null ): bool;
```
This method is automatically called in \Phalcon\Db\Adapter\Pdo
constructor. Call it when you need to restore a database connection


```php
public function createSavepoint( string $name ): bool;
```
Creates a new savepoint


```php
public function createTable( string $tableName, string $schemaName, array $definition ): bool;
```
Creates a table


```php
public function createView( string $viewName, array $definition, string $schemaName = null ): bool;
```
Creates a view


```php
public function delete( mixed $table, mixed $whereCondition = null, mixed $placeholders = null, mixed $dataTypes = null ): bool;
```
Deletes data from a table using custom RDBMS SQL syntax


```php
public function describeColumns( string $table, string $schema = null ): ColumnInterface[];
```
Returns an array of Phalcon\Db\Column objects describing a table


```php
public function describeIndexes( string $table, string $schema = null ): IndexInterface[];
```
Lists table indexes


```php
public function describeReferences( string $table, string $schema = null ): ReferenceInterface[];
```
Lists table references


```php
public function dropColumn( string $tableName, string $schemaName, string $columnName ): bool;
```
Drops a column from a table


```php
public function dropForeignKey( string $tableName, string $schemaName, string $referenceName ): bool;
```
Drops a foreign key from a table


```php
public function dropIndex( string $tableName, string $schemaName, string $indexName ): bool;
```
Drop an index from a table


```php
public function dropPrimaryKey( string $tableName, string $schemaName ): bool;
```
Drops primary key from a table


```php
public function dropTable( string $tableName, string $schemaName = null, bool $ifExists = bool ): bool;
```
Drops a table from a schema/database


```php
public function dropView( string $viewName, string $schemaName = null, bool $ifExists = bool ): bool;
```
Drops a view


```php
public function escapeIdentifier( mixed $identifier ): string;
```
Escapes a column/table/schema name


```php
public function escapeString( string $str ): string;
```
Escapes a value to avoid SQL injections


```php
public function execute( string $sqlStatement, mixed $placeholders = null, mixed $dataTypes = null ): bool;
```
Sends SQL statements to the database server returning the success state.
Use this method only when the SQL statement sent to the server doesn't
return any rows


```php
public function fetchAll( string $sqlQuery, int $fetchMode = int, mixed $placeholders = null ): array;
```
Dumps the complete result of a query into an array


```php
public function fetchColumn( string $sqlQuery, array $placeholders = [], mixed $column = int ): string | bool;
```
Returns the n'th field of first row in a SQL query result

```php
// Getting count of robots
$robotsCount = $connection->fetchColumn("SELECT count(*) FROM robots");
print_r($robotsCount);

// Getting name of last edited robot
$robot = $connection->fetchColumn(
    "SELECT id, name FROM robots order by modified desc",
    1
);
print_r($robot);
```


```php
public function fetchOne( string $sqlQuery, int $fetchMode = int, mixed $placeholders = null ): array;
```
Returns the first row in a SQL query result


```php
public function forUpdate( string $sqlQuery ): string;
```
Returns a SQL modified with a FOR UPDATE clause


```php
public function getColumnDefinition( ColumnInterface $column ): string;
```
Returns the SQL column definition from a column


```php
public function getColumnList( mixed $columnList ): string;
```
Gets a list of columns


```php
public function getConnectionId(): string;
```
Gets the active connection unique identifier


```php
public function getDefaultIdValue(): RawValue;
```
Return the default identity value to insert in an identity column


```php
public function getDescriptor(): array;
```
Return descriptor used to connect to the active database


```php
public function getDialect(): DialectInterface;
```
Returns internal dialect instance


```php
public function getDialectType(): string;
```
Returns the name of the dialect used


```php
public function getInternalHandler(): \Pdo;
```
Return internal PDO handler


```php
public function getNestedTransactionSavepointName(): string;
```
Returns the savepoint name to use for nested transactions


```php
public function getRealSQLStatement(): string;
```
Active SQL statement in the object without replace bound parameters


```php
public function getSQLBindTypes(): array;
```
Active SQL statement in the object


```php
public function getSQLStatement(): string;
```
Active SQL statement in the object


```php
public function getSQLVariables(): array;
```
Active SQL statement in the object


```php
public function getType(): string;
```
Returns type of database system the adapter is used for


```php
public function insert( string $table, array $values, mixed $fields = null, mixed $dataTypes = null ): bool;
```
Inserts data into a table using custom RDBMS SQL syntax


```php
public function insertAsDict( string $table, mixed $data, mixed $dataTypes = null ): bool;
```
Inserts data into a table using custom RBDM SQL syntax

```php
// Inserting a new robot
$success = $connection->insertAsDict(
    "robots",
    [
        "name" => "Astro Boy",
        "year" => 1952,
    ]
);

// Next SQL sentence is sent to the database system
INSERT INTO `robots` (`name`, `year`) VALUES ("Astro boy", 1952);
```


```php
public function isNestedTransactionsWithSavepoints(): bool;
```
Returns if nested transactions should use savepoints


```php
public function isUnderTransaction(): bool;
```
Checks whether connection is under database transaction


```php
public function lastInsertId( mixed $sequenceName = null );
```
Returns insert id for the auto_increment column inserted in the last SQL
statement


```php
public function limit( string $sqlQuery, int $number ): string;
```
Appends a LIMIT clause to sqlQuery argument


```php
public function listTables( string $schemaName = null ): array;
```
List all tables on a database


```php
public function listViews( string $schemaName = null ): array;
```
List all views on a database


```php
public function modifyColumn( string $tableName, string $schemaName, ColumnInterface $column, ColumnInterface $currentColumn = null ): bool;
```
Modifies a table column based on a definition


```php
public function query( string $sqlStatement, mixed $placeholders = null, mixed $dataTypes = null ): ResultInterface | bool;
```
Sends SQL statements to the database server returning the success state.
Use this method only when the SQL statement sent to the server returns
rows


```php
public function releaseSavepoint( string $name ): bool;
```
Releases given savepoint


```php
public function rollback( bool $nesting = bool ): bool;
```
Rollbacks the active transaction in the connection


```php
public function rollbackSavepoint( string $name ): bool;
```
Rollbacks given savepoint


```php
public function setNestedTransactionsWithSavepoints( bool $nestedTransactionsWithSavepoints ): AdapterInterface;
```
Set if nested transactions should use savepoints


```php
public function sharedLock( string $sqlQuery ): string;
```
Returns a SQL modified with a LOCK IN SHARE MODE clause


```php
public function supportSequences(): bool;
```
Check whether the database system requires a sequence to produce
auto-numeric values


```php
public function tableExists( string $tableName, string $schemaName = null ): bool;
```
Generates SQL checking for the existence of a schema.table


```php
public function tableOptions( string $tableName, string $schemaName = null ): array;
```
Gets creation options from a table


```php
public function update( string $table, mixed $fields, mixed $values, mixed $whereCondition = null, mixed $dataTypes = null ): bool;
```
Updates data on a table using custom RDBMS SQL syntax


```php
public function updateAsDict( string $table, mixed $data, mixed $whereCondition = null, mixed $dataTypes = null ): bool;
```
Updates data on a table using custom RBDM SQL syntax
Another, more convenient syntax

```php
// Updating existing robot
$success = $connection->updateAsDict(
    "robots",
    [
        "name" => "New Astro Boy",
    ],
    "id = 101"
);

// Next SQL sentence is sent to the database system
UPDATE `robots` SET `name` = "Astro boy" WHERE id = 101
```


```php
public function useExplicitIdValue(): bool;
```
Check whether the database system requires an explicit value for identity
columns


```php
public function viewExists( string $viewName, string $schemaName = null ): bool;
```
Generates SQL checking for the existence of a schema.view



        
<h1 id="db-adapter-pdo-abstractpdo">Abstract Class Phalcon\Db\Adapter\Pdo\AbstractPdo</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/db/adapter/pdo/abstractpdo.zep)

| Namespace  | Phalcon\Db\Adapter\Pdo |
| Uses       | Phalcon\Db\Adapter\AbstractAdapter, Phalcon\Db\Column, Phalcon\Db\Exception, Phalcon\Db\Result\Pdo, Phalcon\Db\ResultInterface, Phalcon\Events\ManagerInterface |
| Extends    | AbstractAdapter |

Phalcon\Db\Adapter\Pdo is the Phalcon\Db that internally uses PDO to connect
to a database

```php
use Phalcon\Db\Adapter\Pdo\Mysql;

$config = [
    "host"     => "localhost",
    "dbname"   => "blog",
    "port"     => 3306,
    "username" => "sigma",
    "password" => "secret",
];

$connection = new Mysql($config);
```


## Properties
```php
/**
 * Last affected rows
 */
protected affectedRows;

/**
 * PDO Handler
 *
 * @var \Pdo
 */
protected pdo;

```

## Methods
```php
public function __construct( array $descriptor ): void;
```
Constructor for Phalcon\Db\Adapter\Pdo


```php
public function affectedRows(): int;
```
Returns the number of affected rows by the latest INSERT/UPDATE/DELETE
executed in the database system

```php
$connection->execute(
    "DELETE FROM robots"
);

echo $connection->affectedRows(), " were deleted";
```


```php
public function begin( bool $nesting = bool ): bool;
```
Starts a transaction in the connection


```php
public function close(): bool;
```
Closes the active connection returning success. Phalcon automatically
closes and destroys active connections when the request ends


```php
public function commit( bool $nesting = bool ): bool;
```
Commits the active transaction in the connection


```php
public function connect( array $descriptor = null ): bool;
```
This method is automatically called in \Phalcon\Db\Adapter\Pdo
constructor.

Call it when you need to restore a database connection.

```php
use Phalcon\Db\Adapter\Pdo\Mysql;

// Make a connection
$connection = new Mysql(
    [
        "host"     => "localhost",
        "username" => "sigma",
        "password" => "secret",
        "dbname"   => "blog",
        "port"     => 3306,
    ]
);

// Reconnect
$connection->connect();
```


```php
public function convertBoundParams( string $sql, array $params = [] ): array;
```
Converts bound parameters such as :name: or ?1 into PDO bind params ?

```php
print_r(
    $connection->convertBoundParams(
        "SELECTFROM robots WHERE name = :name:",
        [
            "Bender",
        ]
    )
);
```


```php
public function escapeString( string $str ): string;
```
Escapes a value to avoid SQL injections according to the active charset
in the connection

```php
$escapedStr = $connection->escapeString("some dangerous value");
```


```php
public function execute( string $sqlStatement, mixed $bindParams = null, mixed $bindTypes = null ): bool;
```
Sends SQL statements to the database server returning the success state.
Use this method only when the SQL statement sent to the server doesn't
return any rows

```php
// Inserting data
$success = $connection->execute(
    "INSERT INTO robots VALUES (1, 'Astro Boy')"
);

$success = $connection->execute(
    "INSERT INTO robots VALUES (?, ?)",
    [
        1,
        "Astro Boy",
    ]
);
```


```php
public function executePrepared( \PDOStatement $statement, array $placeholders, mixed $dataTypes ): \PDOStatement;
```
Executes a prepared statement binding. This function uses integer indexes
starting from zero

```php
use Phalcon\Db\Column;

$statement = $db->prepare(
    "SELECTFROM robots WHERE name = :name"
);

$result = $connection->executePrepared(
    $statement,
    [
        "name" => "Voltron",
    ],
    [
        "name" => Column::BIND_PARAM_INT,
    ]
);
```


```php
public function getErrorInfo();
```
Return the error info, if any


```php
public function getInternalHandler(): \Pdo;
```
Return internal PDO handler


```php
public function getTransactionLevel(): int;
```
Returns the current transaction nesting level


```php
public function isUnderTransaction(): bool;
```
Checks whether the connection is under a transaction

```php
$connection->begin();

// true
var_dump(
    $connection->isUnderTransaction()
);
```


```php
public function lastInsertId( mixed $sequenceName = null ): int | bool;
```
Returns the insert id for the auto_increment/serial column inserted in
the latest executed SQL statement

```php
// Inserting a new robot
$success = $connection->insert(
    "robots",
    [
        "Astro Boy",
        1952,
    ],
    [
        "name",
        "year",
    ]
);

// Getting the generated id
$id = $connection->lastInsertId();
```


```php
public function prepare( string $sqlStatement ): \PDOStatement;
```
Returns a PDO prepared statement to be executed with 'executePrepared'

```php
use Phalcon\Db\Column;

$statement = $db->prepare(
    "SELECTFROM robots WHERE name = :name"
);

$result = $connection->executePrepared(
    $statement,
    [
        "name" => "Voltron",
    ],
    [
        "name" => Column::BIND_PARAM_INT,
    ]
);
```


```php
public function query( string $sqlStatement, mixed $bindParams = null, mixed $bindTypes = null ): ResultInterface | bool;
```
Sends SQL statements to the database server returning the success state.
Use this method only when the SQL statement sent to the server is
returning rows

```php
// Querying data
$resultset = $connection->query(
    "SELECTFROM robots WHERE type = 'mechanical'"
);

$resultset = $connection->query(
    "SELECTFROM robots WHERE type = ?",
    [
        "mechanical",
    ]
);
```


```php
public function rollback( bool $nesting = bool ): bool;
```
Rollbacks the active transaction in the connection


```php
abstract protected function getDsnDefaults(): array;
```
Returns PDO adapter DSN defaults as a key-value map.



        
<h1 id="db-adapter-pdo-mysql">Class Phalcon\Db\Adapter\Pdo\Mysql</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/db/adapter/pdo/mysql.zep)

| Namespace  | Phalcon\Db\Adapter\Pdo |
| Uses       | Phalcon\Db\Adapter\Pdo\AbstractPdo, Phalcon\Db\Column, Phalcon\Db\ColumnInterface, Phalcon\Db\Enum, Phalcon\Db\Exception, Phalcon\Db\Index, Phalcon\Db\IndexInterface, Phalcon\Db\Reference, Phalcon\Db\ReferenceInterface |
| Extends    | PdoAdapter |

Specific functions for the Mysql database system

```php
use Phalcon\Db\Adapter\Pdo\Mysql;

$config = [
    "host"     => "localhost",
    "dbname"   => "blog",
    "port"     => 3306,
    "username" => "sigma",
    "password" => "secret",
];

$connection = new Mysql($config);
```


## Properties
```php
/**
 * @var string
 */
protected dialectType = mysql;

/**
 * @var string
 */
protected type = mysql;

```

## Methods
```php
public function addForeignKey( string $tableName, string $schemaName, ReferenceInterface $reference ): bool;
```
Adds a foreign key to a table


```php
public function describeColumns( string $table, string $schema = null ): ColumnInterface[];
```
Returns an array of Phalcon\Db\Column objects describing a table

```php
print_r(
    $connection->describeColumns("posts")
);
```


```php
public function describeIndexes( string $table, string $schema = null ): IndexInterface[];
```
Lists table indexes

```php
print_r(
    $connection->describeIndexes("robots_parts")
);
```


```php
public function describeReferences( string $table, string $schema = null ): ReferenceInterface[];
```
Lists table references

```php
print_r(
    $connection->describeReferences("robots_parts")
);
```


```php
protected function getDsnDefaults(): array;
```
Returns PDO adapter DSN defaults as a key-value map.



        
<h1 id="db-adapter-pdo-postgresql">Class Phalcon\Db\Adapter\Pdo\Postgresql</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/db/adapter/pdo/postgresql.zep)

| Namespace  | Phalcon\Db\Adapter\Pdo |
| Uses       | Phalcon\Db\Adapter\Pdo\AbstractPdo, Phalcon\Db\Column, Phalcon\Db\ColumnInterface, Phalcon\Db\Enum, Phalcon\Db\Exception, Phalcon\Db\RawValue, Phalcon\Db\Reference, Phalcon\Db\ReferenceInterface, Throwable |
| Extends    | PdoAdapter |

Specific functions for the Postgresql database system

```php
use Phalcon\Db\Adapter\Pdo\Postgresql;

$config = [
    "host"     => "localhost",
    "dbname"   => "blog",
    "port"     => 5432,
    "username" => "postgres",
    "password" => "secret",
];

$connection = new Postgresql($config);
```


## Properties
```php
/**
 * @var string
 */
protected dialectType = postgresql;

/**
 * @var string
 */
protected type = pgsql;

```

## Methods
```php
public function __construct( array $descriptor ): void;
```
Constructor for Phalcon\Db\Adapter\Pdo\Postgresql


```php
public function connect( array $descriptor = null ): bool;
```
This method is automatically called in Phalcon\Db\Adapter\Pdo
constructor. Call it when you need to restore a database connection.


```php
public function createTable( string $tableName, string $schemaName, array $definition ): bool;
```
Creates a table


```php
public function describeColumns( string $table, string $schema = null ): ColumnInterface[];
```
Returns an array of Phalcon\Db\Column objects describing a table

```php
print_r(
    $connection->describeColumns("posts")
);
```


```php
public function describeReferences( string $table, string $schema = null ): ReferenceInterface[];
```
Lists table references

```php
print_r(
    $connection->describeReferences("robots_parts")
);
```


```php
public function getDefaultIdValue(): RawValue;
```
Returns the default identity value to be inserted in an identity column

```php
// Inserting a new robot with a valid default value for the column 'id'
$success = $connection->insert(
    "robots",
    [
        $connection->getDefaultIdValue(),
        "Astro Boy",
        1952,
    ],
    [
        "id",
        "name",
        "year",
    ]
);
```


```php
public function modifyColumn( string $tableName, string $schemaName, ColumnInterface $column, ColumnInterface $currentColumn = null ): bool;
```
Modifies a table column based on a definition


```php
public function supportSequences(): bool;
```
Check whether the database system requires a sequence to produce
auto-numeric values


```php
public function useExplicitIdValue(): bool;
```
Check whether the database system requires an explicit value for identity
columns


```php
protected function getDsnDefaults(): array;
```
Returns PDO adapter DSN defaults as a key-value map.



        
<h1 id="db-adapter-pdo-sqlite">Class Phalcon\Db\Adapter\Pdo\Sqlite</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/db/adapter/pdo/sqlite.zep)

| Namespace  | Phalcon\Db\Adapter\Pdo |
| Uses       | Phalcon\Db\Adapter\Pdo\AbstractPdo, Phalcon\Db\Column, Phalcon\Db\ColumnInterface, Phalcon\Db\Enum, Phalcon\Db\Exception, Phalcon\Db\Index, Phalcon\Db\IndexInterface, Phalcon\Db\RawValue, Phalcon\Db\Reference, Phalcon\Db\ReferenceInterface |
| Extends    | PdoAdapter |

Specific functions for the Sqlite database system

```php
use Phalcon\Db\Adapter\Pdo\Sqlite;

$connection = new Sqlite(
    [
        "dbname" => "/tmp/test.sqlite",
    ]
);
```


## Properties
```php
/**
 * @var string
 */
protected dialectType = sqlite;

/**
 * @var string
 */
protected type = sqlite;

```

## Methods
```php
public function __construct( array $descriptor ): void;
```
Constructor for Phalcon\Db\Adapter\Pdo\Sqlite


```php
public function connect( array $descriptor = null ): bool;
```
This method is automatically called in Phalcon\Db\Adapter\Pdo
constructor. Call it when you need to restore a database connection.


```php
public function describeColumns( string $table, string $schema = null ): ColumnInterface[];
```
Returns an array of Phalcon\Db\Column objects describing a table

```php
print_r(
    $connection->describeColumns("posts")
);
```


```php
public function describeIndexes( string $table, string $schema = null ): IndexInterface[];
```
Lists table indexes

```php
print_r(
    $connection->describeIndexes("robots_parts")
);
```


```php
public function describeReferences( string $table, string $schema = null ): ReferenceInterface[];
```
Lists table references


```php
public function getDefaultValue(): RawValue;
```
Returns the default value to make the RBDM use the default value declared
in the table definition

```php
// Inserting a new robot with a valid default value for the column 'year'
$success = $connection->insert(
    "robots",
    [
        "Astro Boy",
        $connection->getDefaultValue(),
    ],
    [
        "name",
        "year",
    ]
);
```


```php
public function useExplicitIdValue(): bool;
```
Check whether the database system requires an explicit value for identity
columns


```php
protected function getDsnDefaults(): array;
```
Returns PDO adapter DSN defaults as a key-value map.



        
<h1 id="db-adapter-pdofactory">Class Phalcon\Db\Adapter\PdoFactory</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/db/adapter/pdofactory.zep)

| Namespace  | Phalcon\Db\Adapter |
| Uses       | Phalcon\Annotations\Adapter\AbstractAdapter, Phalcon\Factory\AbstractFactory, Phalcon\Helper\Arr |
| Extends    | AbstractFactory |

This file is part of the Phalcon Framework.

(c) Phalcon Team <team@phalcon.io>

For the full copyright and license information, please view the LICENSE.txt
file that was distributed with this source code.


## Methods
```php
public function __construct( array $services = [] );
```
Constructor


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
Returns the available adapters



        
<h1 id="db-column">Class Phalcon\Db\Column</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/db/column.zep)

| Namespace  | Phalcon\Db |
| Uses       | Phalcon\Db\Exception, Phalcon\Db\ColumnInterface |
| Implements | ColumnInterface |

Allows to define columns to be used on create or alter table operations

```php
use Phalcon\Db\Column as Column;

// Column definition
$column = new Column(
    "id",
    [
        "type"          => Column::TYPE_INTEGER,
        "size"          => 10,
        "unsigned"      => true,
        "notNull"       => true,
        "autoIncrement" => true,
        "first"         => true,
    ]
);

// Add column to existing table
$connection->addColumn("robots", null, $column);
```


## Constants
```php
const BIND_PARAM_BLOB = 3;
const BIND_PARAM_BOOL = 5;
const BIND_PARAM_DECIMAL = 32;
const BIND_PARAM_INT = 1;
const BIND_PARAM_NULL = 0;
const BIND_PARAM_STR = 2;
const BIND_SKIP = 1024;
const TYPE_BIGINTEGER = 14;
const TYPE_BIT = 19;
const TYPE_BLOB = 11;
const TYPE_BOOLEAN = 8;
const TYPE_CHAR = 5;
const TYPE_DATE = 1;
const TYPE_DATETIME = 4;
const TYPE_DECIMAL = 3;
const TYPE_DOUBLE = 9;
const TYPE_ENUM = 18;
const TYPE_FLOAT = 7;
const TYPE_INTEGER = 0;
const TYPE_JSON = 15;
const TYPE_JSONB = 16;
const TYPE_LONGBLOB = 13;
const TYPE_LONGTEXT = 24;
const TYPE_MEDIUMBLOB = 12;
const TYPE_MEDIUMINTEGER = 21;
const TYPE_MEDIUMTEXT = 23;
const TYPE_SMALLINTEGER = 22;
const TYPE_TEXT = 6;
const TYPE_TIME = 20;
const TYPE_TIMESTAMP = 17;
const TYPE_TINYBLOB = 10;
const TYPE_TINYINTEGER = 26;
const TYPE_TINYTEXT = 25;
const TYPE_VARCHAR = 2;
```

## Properties
```php
/**
 * Column Position
 *
 * @var string
 */
protected after;

/**
 * Column is autoIncrement?
 *
 * @var bool
 */
protected autoIncrement = false;

/**
 * Bind Type
 */
protected bindType = 2;

/**
 * Default column value
 */
protected _default;

/**
 * Position is first
 *
 * @var bool
 */
protected first = false;

/**
 * The column have some numeric type?
 */
protected isNumeric = false;

/**
 * Column's name
 *
 * @var string
 */
protected name;

/**
 * Column not nullable?
 *
 * @var bool
 */
protected notNull = false;

/**
 * Column is part of the primary key?
 */
protected primary = false;

/**
 * Integer column number scale
 *
 * @var int
 */
protected scale = 0;

/**
 * Integer column size
 *
 * @var int
 */
protected size = 0;

/**
 * Column data type
 *
 * @var int
 */
protected type;

/**
 * Column data type reference
 *
 * @var int
 */
protected typeReference = -1;

/**
 * Column data type values
 *
 * @var array|string
 */
protected typeValues;

/**
 * Integer column unsigned?
 *
 * @var bool
 */
protected unsigned = false;

```

## Methods
```php
public function __construct( string $name, array $definition ): void;
```
Phalcon\Db\Column constructor


```php
public function getAfterPosition(): string;
```
Check whether field absolute to position in table


```php
public function getBindType(): int;
```
Returns the type of bind handling


```php
public function getName(): string
```


```php
public function getScale(): int
```


```php
public function getSize(): int
```


```php
public function getType(): int
```


```php
public function getTypeReference(): int
```


```php
public function getTypeValues(): array|string
```


```php
public function get_default()
```


```php
public function hasDefault(): bool;
```
Check whether column has default value


```php
public function isAutoIncrement(): bool;
```
Auto-Increment


```php
public function isFirst(): bool;
```
Check whether column have first position in table


```php
public function isNotNull(): bool;
```
Not null


```php
public function isNumeric(): bool;
```
Check whether column have an numeric type


```php
public function isPrimary(): bool;
```
Column is part of the primary key?


```php
public function isUnsigned(): bool;
```
Returns true if number column is unsigned



        
<h1 id="db-columninterface">Interface Phalcon\Db\ColumnInterface</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/db/columninterface.zep)

| Namespace  | Phalcon\Db |

Interface for Phalcon\Db\Column


## Methods
```php
public function getAfterPosition(): string;
```
Check whether field absolute to position in table


```php
public function getBindType(): int;
```
Returns the type of bind handling


```php
public function getDefault(): mixed;
```
Returns default value of column


```php
public function getName(): string;
```
Returns column name


```php
public function getScale(): int;
```
Returns column scale


```php
public function getSize(): int;
```
Returns column size


```php
public function getType(): int;
```
Returns column type


```php
public function getTypeReference(): int;
```
Returns column type reference


```php
public function getTypeValues(): array | string;
```
Returns column type values


```php
public function hasDefault(): bool;
```
Check whether column has default value


```php
public function isAutoIncrement(): bool;
```
Auto-Increment


```php
public function isFirst(): bool;
```
Check whether column have first position in table


```php
public function isNotNull(): bool;
```
Not null


```php
public function isNumeric(): bool;
```
Check whether column have an numeric type


```php
public function isPrimary(): bool;
```
Column is part of the primary key?


```php
public function isUnsigned(): bool;
```
Returns true if number column is unsigned



        
<h1 id="db-dialect">Abstract Class Phalcon\Db\Dialect</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/db/dialect.zep)

| Namespace  | Phalcon\Db |
| Implements | DialectInterface |

This is the base class to each database dialect. This implements
common methods to transform intermediate code into its RDBMS related syntax


## Properties
```php
//
protected escapeChar;

//
protected customFunctions;

```

## Methods
```php
public function createSavepoint( string $name ): string;
```
Generate SQL to create a new savepoint


```php
final public function escape( string $str, string $escapeChar = null ): string;
```
Escape identifiers


```php
final public function escapeSchema( string $str, string $escapeChar = null ): string;
```
Escape Schema


```php
public function forUpdate( string $sqlQuery ): string;
```
Returns a SQL modified with a FOR UPDATE clause

```php
$sql = $dialect->forUpdate("SELECTFROM robots");

echo $sql; // SELECTFROM robots FOR UPDATE
```


```php
final public function getColumnList( array $columnList, string $escapeChar = null, mixed $bindCounts = null ): string;
```
Gets a list of columns with escaped identifiers

```php
echo $dialect->getColumnList(
    [
        "column1",
        "column",
    ]
);
```


```php
public function getCustomFunctions(): array;
```
Returns registered functions


```php
final public function getSqlColumn( mixed $column, string $escapeChar = null, mixed $bindCounts = null ): string;
```
Resolve Column expressions


```php
public function getSqlExpression( array $expression, string $escapeChar = null, mixed $bindCounts = null ): string;
```
Transforms an intermediate representation for an expression into a database system valid expression


```php
final public function getSqlTable( mixed $table, string $escapeChar = null ): string;
```
Transform an intermediate representation of a schema/table into a
database system valid expression


```php
public function limit( string $sqlQuery, mixed $number ): string;
```
Generates the SQL for LIMIT clause

```php
// SELECTFROM robots LIMIT 10
echo $dialect->limit(
    "SELECTFROM robots",
    10
);

// SELECTFROM robots LIMIT 10 OFFSET 50
echo $dialect->limit(
    "SELECTFROM robots",
    [10, 50]
);
```


```php
public function registerCustomFunction( string $name, callable $customFunction ): Dialect;
```
Registers custom SQL functions


```php
public function releaseSavepoint( string $name ): string;
```
Generate SQL to release a savepoint


```php
public function rollbackSavepoint( string $name ): string;
```
Generate SQL to rollback a savepoint


```php
public function select( array $definition ): string;
```
Builds a SELECT statement


```php
public function supportsReleaseSavepoints(): bool;
```
Checks whether the platform supports releasing savepoints.


```php
public function supportsSavepoints(): bool;
```
Checks whether the platform supports savepoints


```php
protected function checkColumnType( ColumnInterface $column ): string;
```
Checks the column type and if not string it returns the type reference


```php
protected function checkColumnTypeSql( ColumnInterface $column ): string;
```
Checks the column type and returns the updated SQL statement


```php
protected function getColumnSize( ColumnInterface $column ): string;
```
Returns the size of the column enclosed in parentheses


```php
protected function getColumnSizeAndScale( ColumnInterface $column ): string;
```
Returns the column size and scale enclosed in parentheses


```php
final protected function getSqlExpressionAll( array $expression, string $escapeChar = null ): string;
```
Resolve


```php
final protected function getSqlExpressionBinaryOperations( array $expression, string $escapeChar = null, mixed $bindCounts = null ): string;
```
Resolve binary operations expressions


```php
final protected function getSqlExpressionCase( array $expression, string $escapeChar = null, mixed $bindCounts = null ): string;
```
Resolve CASE expressions


```php
final protected function getSqlExpressionCastValue( array $expression, string $escapeChar = null, mixed $bindCounts = null ): string;
```
Resolve CAST of values


```php
final protected function getSqlExpressionConvertValue( array $expression, string $escapeChar = null, mixed $bindCounts = null ): string;
```
Resolve CONVERT of values encodings


```php
final protected function getSqlExpressionFrom( mixed $expression, string $escapeChar = null ): string;
```
Resolve a FROM clause


```php
final protected function getSqlExpressionFunctionCall( array $expression, string $escapeChar = null, mixed $bindCounts ): string;
```
Resolve function calls


```php
final protected function getSqlExpressionGroupBy( mixed $expression, string $escapeChar = null, mixed $bindCounts = null ): string;
```
Resolve a GROUP BY clause


```php
final protected function getSqlExpressionHaving( array $expression, string $escapeChar = null, mixed $bindCounts = null ): string;
```
Resolve a HAVING clause


```php
final protected function getSqlExpressionJoins( mixed $expression, string $escapeChar = null, mixed $bindCounts = null ): string;
```
Resolve a JOINs clause


```php
final protected function getSqlExpressionLimit( mixed $expression, string $escapeChar = null, mixed $bindCounts = null ): string;
```
Resolve a LIMIT clause


```php
final protected function getSqlExpressionList( array $expression, string $escapeChar = null, mixed $bindCounts = null ): string;
```
Resolve Lists


```php
final protected function getSqlExpressionObject( array $expression, string $escapeChar = null, mixed $bindCounts = null ): string;
```
Resolve object expressions


```php
final protected function getSqlExpressionOrderBy( mixed $expression, string $escapeChar = null, mixed $bindCounts = null ): string;
```
Resolve an ORDER BY clause


```php
final protected function getSqlExpressionQualified( array $expression, string $escapeChar = null ): string;
```
Resolve qualified expressions


```php
final protected function getSqlExpressionScalar( array $expression, string $escapeChar = null, mixed $bindCounts = null ): string;
```
Resolve Column expressions


```php
final protected function getSqlExpressionUnaryOperations( array $expression, string $escapeChar = null, mixed $bindCounts = null ): string;
```
Resolve unary operations expressions


```php
final protected function getSqlExpressionWhere( mixed $expression, string $escapeChar = null, mixed $bindCounts = null ): string;
```
Resolve a WHERE clause


```php
protected function prepareColumnAlias( string $qualified, string $alias = null, string $escapeChar = null ): string;
```
Prepares column for this RDBMS


```php
protected function prepareQualified( string $column, string $domain = null, string $escapeChar = null ): string;
```
Prepares qualified for this RDBMS


```php
protected function prepareTable( string $table, string $schema = null, string $alias = null, string $escapeChar = null ): string;
```
Prepares table for this RDBMS



        
<h1 id="db-dialect-mysql">Class Phalcon\Db\Dialect\Mysql</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/db/dialect/mysql.zep)

| Namespace  | Phalcon\Db\Dialect |
| Uses       | Phalcon\Db\Dialect, Phalcon\Db\Column, Phalcon\Db\Exception, Phalcon\Db\IndexInterface, Phalcon\Db\ColumnInterface, Phalcon\Db\ReferenceInterface, Phalcon\Db\DialectInterface |
| Extends    | Dialect |

Generates database specific SQL for the MySQL RDBMS


## Properties
```php
/**
 * @var string
 */
protected escapeChar = `;

```

## Methods
```php
public function addColumn( string $tableName, string $schemaName, ColumnInterface $column ): string;
```
Generates SQL to add a column to a table


```php
public function addForeignKey( string $tableName, string $schemaName, ReferenceInterface $reference ): string;
```
Generates SQL to add an index to a table


```php
public function addIndex( string $tableName, string $schemaName, IndexInterface $index ): string;
```
Generates SQL to add an index to a table


```php
public function addPrimaryKey( string $tableName, string $schemaName, IndexInterface $index ): string;
```
Generates SQL to add the primary key to a table


```php
public function createTable( string $tableName, string $schemaName, array $definition ): string;
```
Generates SQL to create a table


```php
public function createView( string $viewName, array $definition, string $schemaName = null ): string;
```
Generates SQL to create a view


```php
public function describeColumns( string $table, string $schema = null ): string;
```
Generates SQL describing a table

```php
print_r(
    $dialect->describeColumns("posts")
);
```


```php
public function describeIndexes( string $table, string $schema = null ): string;
```
Generates SQL to query indexes on a table


```php
public function describeReferences( string $table, string $schema = null ): string;
```
Generates SQL to query foreign keys on a table


```php
public function dropColumn( string $tableName, string $schemaName, string $columnName ): string;
```
Generates SQL to delete a column from a table


```php
public function dropForeignKey( string $tableName, string $schemaName, string $referenceName ): string;
```
Generates SQL to delete a foreign key from a table


```php
public function dropIndex( string $tableName, string $schemaName, string $indexName ): string;
```
Generates SQL to delete an index from a table


```php
public function dropPrimaryKey( string $tableName, string $schemaName ): string;
```
Generates SQL to delete primary key from a table


```php
public function dropTable( string $tableName, string $schemaName = null, bool $ifExists = bool ): string;
```
Generates SQL to drop a table


```php
public function dropView( string $viewName, string $schemaName = null, bool $ifExists = bool ): string;
```
Generates SQL to drop a view


```php
public function getColumnDefinition( ColumnInterface $column ): string;
```
Gets the column name in MySQL


```php
public function getForeignKeyChecks(): string;
```
Generates SQL to check DB parameter FOREIGN_KEY_CHECKS.


```php
public function listTables( string $schemaName = null ): string;
```
List all tables in database

```php
print_r(
    $dialect->listTables("blog")
);
```


```php
public function listViews( string $schemaName = null ): string;
```
Generates the SQL to list all views of a schema or user


```php
public function modifyColumn( string $tableName, string $schemaName, ColumnInterface $column, ColumnInterface $currentColumn = null ): string;
```
Generates SQL to modify a column in a table


```php
public function sharedLock( string $sqlQuery ): string;
```
Returns a SQL modified with a LOCK IN SHARE MODE clause

```php
$sql = $dialect->sharedLock("SELECTFROM robots");

echo $sql; // SELECTFROM robots LOCK IN SHARE MODE
```


```php
public function tableExists( string $tableName, string $schemaName = null ): string;
```
Generates SQL checking for the existence of a schema.table

```php
echo $dialect->tableExists("posts", "blog");

echo $dialect->tableExists("posts");
```


```php
public function tableOptions( string $table, string $schema = null ): string;
```
Generates the SQL to describe the table creation options


```php
public function truncateTable( string $tableName, string $schemaName ): string;
```
Generates SQL to truncate a table


```php
public function viewExists( string $viewName, string $schemaName = null ): string;
```
Generates SQL checking for the existence of a schema.view


```php
protected function getTableOptions( array $definition ): string;
```
Generates SQL to add the table creation options



        
<h1 id="db-dialect-postgresql">Class Phalcon\Db\Dialect\Postgresql</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/db/dialect/postgresql.zep)

| Namespace  | Phalcon\Db\Dialect |
| Uses       | Phalcon\Db\Dialect, Phalcon\Db\Column, Phalcon\Db\Exception, Phalcon\Db\IndexInterface, Phalcon\Db\ColumnInterface, Phalcon\Db\ReferenceInterface, Phalcon\Db\DialectInterface |
| Extends    | Dialect |

Generates database specific SQL for the PostgreSQL RDBMS


## Properties
```php
/**
 * @var string
 */
protected escapeChar = \";

```

## Methods
```php
public function addColumn( string $tableName, string $schemaName, ColumnInterface $column ): string;
```
Generates SQL to add a column to a table


```php
public function addForeignKey( string $tableName, string $schemaName, ReferenceInterface $reference ): string;
```
Generates SQL to add an index to a table


```php
public function addIndex( string $tableName, string $schemaName, IndexInterface $index ): string;
```
Generates SQL to add an index to a table


```php
public function addPrimaryKey( string $tableName, string $schemaName, IndexInterface $index ): string;
```
Generates SQL to add the primary key to a table


```php
public function createTable( string $tableName, string $schemaName, array $definition ): string;
```
Generates SQL to create a table


```php
public function createView( string $viewName, array $definition, string $schemaName = null ): string;
```
Generates SQL to create a view


```php
public function describeColumns( string $table, string $schema = null ): string;
```
Generates SQL describing a table

```php
print_r(
    $dialect->describeColumns("posts")
);
```


```php
public function describeIndexes( string $table, string $schema = null ): string;
```
Generates SQL to query indexes on a table


```php
public function describeReferences( string $table, string $schema = null ): string;
```
Generates SQL to query foreign keys on a table


```php
public function dropColumn( string $tableName, string $schemaName, string $columnName ): string;
```
Generates SQL to delete a column from a table


```php
public function dropForeignKey( string $tableName, string $schemaName, string $referenceName ): string;
```
Generates SQL to delete a foreign key from a table


```php
public function dropIndex( string $tableName, string $schemaName, string $indexName ): string;
```
Generates SQL to delete an index from a table


```php
public function dropPrimaryKey( string $tableName, string $schemaName ): string;
```
Generates SQL to delete primary key from a table


```php
public function dropTable( string $tableName, string $schemaName = null, bool $ifExists = bool ): string;
```
Generates SQL to drop a table


```php
public function dropView( string $viewName, string $schemaName = null, bool $ifExists = bool ): string;
```
Generates SQL to drop a view


```php
public function getColumnDefinition( ColumnInterface $column ): string;
```
Gets the column name in PostgreSQL


```php
public function listTables( string $schemaName = null ): string;
```
List all tables in database

```php
print_r(
    $dialect->listTables("blog")
);
```


```php
public function listViews( string $schemaName = null ): string;
```
Generates the SQL to list all views of a schema or user


```php
public function modifyColumn( string $tableName, string $schemaName, ColumnInterface $column, ColumnInterface $currentColumn = null ): string;
```
Generates SQL to modify a column in a table


```php
public function sharedLock( string $sqlQuery ): string;
```
Returns a SQL modified a shared lock statement. For now this method
returns the original query


```php
public function tableExists( string $tableName, string $schemaName = null ): string;
```
Generates SQL checking for the existence of a schema.table

```php
echo $dialect->tableExists("posts", "blog");

echo $dialect->tableExists("posts");
```


```php
public function tableOptions( string $table, string $schema = null ): string;
```
Generates the SQL to describe the table creation options


```php
public function truncateTable( string $tableName, string $schemaName ): string;
```
Generates SQL to truncate a table


```php
public function viewExists( string $viewName, string $schemaName = null ): string;
```
Generates SQL checking for the existence of a schema.view


```php
protected function castDefault( ColumnInterface $column ): string;
```
//

```php
protected function getTableOptions( array $definition ): string;
```
//


        
<h1 id="db-dialect-sqlite">Class Phalcon\Db\Dialect\Sqlite</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/db/dialect/sqlite.zep)

| Namespace  | Phalcon\Db\Dialect |
| Uses       | Phalcon\Db\Column, Phalcon\Db\Exception, Phalcon\Db\IndexInterface, Phalcon\Db\Dialect, Phalcon\Db\DialectInterface, Phalcon\Db\ColumnInterface, Phalcon\Db\ReferenceInterface |
| Extends    | Dialect |

Generates database specific SQL for the SQLite RDBMS


## Properties
```php
/**
 * @var string
 */
protected escapeChar = \";

```

## Methods
```php
public function addColumn( string $tableName, string $schemaName, ColumnInterface $column ): string;
```
Generates SQL to add a column to a table


```php
public function addForeignKey( string $tableName, string $schemaName, ReferenceInterface $reference ): string;
```
Generates SQL to add an index to a table


```php
public function addIndex( string $tableName, string $schemaName, IndexInterface $index ): string;
```
Generates SQL to add an index to a table


```php
public function addPrimaryKey( string $tableName, string $schemaName, IndexInterface $index ): string;
```
Generates SQL to add the primary key to a table


```php
public function createTable( string $tableName, string $schemaName, array $definition ): string;
```
Generates SQL to create a table


```php
public function createView( string $viewName, array $definition, string $schemaName = null ): string;
```
Generates SQL to create a view


```php
public function describeColumns( string $table, string $schema = null ): string;
```
Generates SQL describing a table

```php
print_r(
    $dialect->describeColumns("posts")
);
```


```php
public function describeIndex( string $index ): string;
```
Generates SQL to query indexes detail on a table


```php
public function describeIndexes( string $table, string $schema = null ): string;
```
Generates SQL to query indexes on a table


```php
public function describeReferences( string $table, string $schema = null ): string;
```
Generates SQL to query foreign keys on a table


```php
public function dropColumn( string $tableName, string $schemaName, string $columnName ): string;
```
Generates SQL to delete a column from a table


```php
public function dropForeignKey( string $tableName, string $schemaName, string $referenceName ): string;
```
Generates SQL to delete a foreign key from a table


```php
public function dropIndex( string $tableName, string $schemaName, string $indexName ): string;
```
Generates SQL to delete an index from a table


```php
public function dropPrimaryKey( string $tableName, string $schemaName ): string;
```
Generates SQL to delete primary key from a table


```php
public function dropTable( string $tableName, string $schemaName = null, bool $ifExists = bool ): string;
```
Generates SQL to drop a table


```php
public function dropView( string $viewName, string $schemaName = null, bool $ifExists = bool ): string;
```
Generates SQL to drop a view


```php
public function forUpdate( string $sqlQuery ): string;
```
Returns a SQL modified with a FOR UPDATE clause. For SQLite it returns
the original query


```php
public function getColumnDefinition( ColumnInterface $column ): string;
```
Gets the column name in SQLite


```php
public function listIndexesSql( string $table, string $schema = null, string $keyName = null ): string;
```
Generates the SQL to get query list of indexes

```php
print_r(
    $dialect->listIndexesSql("blog")
);
```


```php
public function listTables( string $schemaName = null ): string;
```
List all tables in database

```php
print_r(
    $dialect->listTables("blog")
);
```


```php
public function listViews( string $schemaName = null ): string;
```
Generates the SQL to list all views of a schema or user


```php
public function modifyColumn( string $tableName, string $schemaName, ColumnInterface $column, ColumnInterface $currentColumn = null ): string;
```
Generates SQL to modify a column in a table


```php
public function sharedLock( string $sqlQuery ): string;
```
Returns a SQL modified a shared lock statement. For now this method
returns the original query


```php
public function tableExists( string $tableName, string $schemaName = null ): string;
```
Generates SQL checking for the existence of a schema.table

```php
echo $dialect->tableExists("posts", "blog");

echo $dialect->tableExists("posts");
```


```php
public function tableOptions( string $table, string $schema = null ): string;
```
Generates the SQL to describe the table creation options


```php
public function truncateTable( string $tableName, string $schemaName ): string;
```
Generates SQL to truncate a table


```php
public function viewExists( string $viewName, string $schemaName = null ): string;
```
Generates SQL checking for the existence of a schema.view



        
<h1 id="db-dialectinterface">Interface Phalcon\Db\DialectInterface</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/db/dialectinterface.zep)

| Namespace  | Phalcon\Db |
| Uses       | Phalcon\Db\ColumnInterface, Phalcon\Db\ReferenceInterface, Phalcon\Db\IndexInterface |

Interface for Phalcon\Db dialects


## Methods
```php
public function addColumn( string $tableName, string $schemaName, ColumnInterface $column ): string;
```
Generates SQL to add a column to a table


```php
public function addForeignKey( string $tableName, string $schemaName, ReferenceInterface $reference ): string;
```
Generates SQL to add an index to a table


```php
public function addIndex( string $tableName, string $schemaName, IndexInterface $index ): string;
```
Generates SQL to add an index to a table


```php
public function addPrimaryKey( string $tableName, string $schemaName, IndexInterface $index ): string;
```
Generates SQL to add the primary key to a table


```php
public function createSavepoint( string $name ): string;
```
Generate SQL to create a new savepoint


```php
public function createTable( string $tableName, string $schemaName, array $definition ): string;
```
Generates SQL to create a table


```php
public function createView( string $viewName, array $definition, string $schemaName = null ): string;
```
Generates SQL to create a view


```php
public function describeColumns( string $table, string $schema = null ): string;
```
Generates SQL to describe a table


```php
public function describeIndexes( string $table, string $schema = null ): string;
```
Generates SQL to query indexes on a table


```php
public function describeReferences( string $table, string $schema = null ): string;
```
Generates SQL to query foreign keys on a table


```php
public function dropColumn( string $tableName, string $schemaName, string $columnName ): string;
```
Generates SQL to delete a column from a table


```php
public function dropForeignKey( string $tableName, string $schemaName, string $referenceName ): string;
```
Generates SQL to delete a foreign key from a table


```php
public function dropIndex( string $tableName, string $schemaName, string $indexName ): string;
```
 Generates SQL to delete an index from a table


```php
public function dropPrimaryKey( string $tableName, string $schemaName ): string;
```
Generates SQL to delete primary key from a table


```php
public function dropTable( string $tableName, string $schemaName ): string;
```
Generates SQL to drop a table


```php
public function dropView( string $viewName, string $schemaName = null, bool $ifExists = bool ): string;
```
Generates SQL to drop a view


```php
public function forUpdate( string $sqlQuery ): string;
```
Returns a SQL modified with a FOR UPDATE clause


```php
public function getColumnDefinition( ColumnInterface $column ): string;
```
Gets the column name in RDBMS


```php
public function getColumnList( array $columnList ): string;
```
Gets a list of columns


```php
public function getCustomFunctions(): array;
```
Returns registered functions


```php
public function getSqlExpression( array $expression, string $escapeChar = null, mixed $bindCounts = null ): string;
```
Transforms an intermediate representation for an expression into a
database system valid expression


```php
public function limit( string $sqlQuery, mixed $number ): string;
```
Generates the SQL for LIMIT clause


```php
public function listTables( string $schemaName = null ): string;
```
List all tables in database


```php
public function modifyColumn( string $tableName, string $schemaName, ColumnInterface $column, ColumnInterface $currentColumn = null ): string;
```
Generates SQL to modify a column in a table


```php
public function registerCustomFunction( string $name, callable $customFunction ): Dialect;
```
Registers custom SQL functions


```php
public function releaseSavepoint( string $name ): string;
```
Generate SQL to release a savepoint


```php
public function rollbackSavepoint( string $name ): string;
```
Generate SQL to rollback a savepoint


```php
public function select( array $definition ): string;
```
Builds a SELECT statement


```php
public function sharedLock( string $sqlQuery ): string;
```
Returns a SQL modified with a LOCK IN SHARE MODE clause


```php
public function supportsReleaseSavepoints(): bool;
```
Checks whether the platform supports releasing savepoints.


```php
public function supportsSavepoints(): bool;
```
Checks whether the platform supports savepoints


```php
public function tableExists( string $tableName, string $schemaName = null ): string;
```
Generates SQL checking for the existence of a schema.table


```php
public function tableOptions( string $table, string $schema = null ): string;
```
Generates the SQL to describe the table creation options


```php
public function viewExists( string $viewName, string $schemaName = null ): string;
```
Generates SQL checking for the existence of a schema.view



        
<h1 id="db-enum">Class Phalcon\Db\Enum</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/db/enum.zep)

| Namespace  | Phalcon\Db |

Constants for Phalcon\Db


## Constants
```php
const FETCH_ASSOC;
const FETCH_BOTH;
const FETCH_BOUND;
const FETCH_CLASS;
const FETCH_CLASSTYPE;
const FETCH_COLUMN;
const FETCH_FUNC;
const FETCH_GROUP;
const FETCH_INTO;
const FETCH_KEY_PAIR;
const FETCH_LAZY;
const FETCH_NAMED;
const FETCH_NUM;
const FETCH_OBJ;
const FETCH_PROPS_LATE;
const FETCH_SERIALIZE;
const FETCH_UNIQUE;
```

        
<h1 id="db-exception">Class Phalcon\Db\Exception</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/db/exception.zep)

| Namespace  | Phalcon\Db |
| Extends    | \Phalcon\Exception |

Exceptions thrown in Phalcon\Db will use this class


        
<h1 id="db-index">Class Phalcon\Db\Index</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/db/index.zep)

| Namespace  | Phalcon\Db |
| Implements | IndexInterface |

Allows to define indexes to be used on tables. Indexes are a common way
to enhance database performance. An index allows the database server to find
and retrieve specific rows much faster than it could do without an index

```php
// Define new unique index
$index_unique = new \Phalcon\Db\Index(
    'column_UNIQUE',
    [
        'column',
        'column',
    ],
    'UNIQUE'
);

// Define new primary index
$index_primary = new \Phalcon\Db\Index(
    'PRIMARY',
    [
        'column',
    ]
);

// Add index to existing table
$connection->addIndex("robots", null, $index_unique);
$connection->addIndex("robots", null, $index_primary);
```


## Properties
```php
/**
 * Index columns
 *
 * @var array
 */
protected columns;

/**
 * Index name
 *
 * @var string
 */
protected name;

/**
 * Index type
 *
 * @var string
 */
protected type;

```

## Methods
```php
public function __construct( string $name, array $columns, string $type = string ): void;
```
Phalcon\Db\Index constructor


```php
public function getColumns(): array
```


```php
public function getName(): string
```


```php
public function getType(): string
```



        
<h1 id="db-indexinterface">Interface Phalcon\Db\IndexInterface</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/db/indexinterface.zep)

| Namespace  | Phalcon\Db |

Interface for Phalcon\Db\Index


## Methods
```php
public function getColumns(): array;
```
Gets the columns that corresponds the index


```php
public function getName(): string;
```
Gets the index name


```php
public function getType(): string;
```
Gets the index type



        
<h1 id="db-profiler">Class Phalcon\Db\Profiler</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/db/profiler.zep)

| Namespace  | Phalcon\Db |
| Uses       | Phalcon\Db\Profiler\Item |

Instances of Phalcon\Db can generate execution profiles
on SQL statements sent to the relational database. Profiled
information includes execution time in milliseconds.
This helps you to identify bottlenecks in your applications.

```php
use Phalcon\Db\Profiler;
use Phalcon\Events\Event;
use Phalcon\Events\Manager;

$profiler = new Profiler();
$eventsManager = new Manager();

$eventsManager->attach(
    "db",
    function (Event $event, $connection) use ($profiler) {
        if ($event->getType() === "beforeQuery") {
            $sql = $connection->getSQLStatement();

            // Start a profile with the active connection
            $profiler->startProfile($sql);
        }

        if ($event->getType() === "afterQuery") {
            // Stop the active profile
            $profiler->stopProfile();
        }
    }
);

// Set the event manager on the connection
$connection->setEventsManager($eventsManager);


$sql = "SELECT buyer_name, quantity, product_name
FROM buyers LEFT JOIN products ON
buyers.pid=products.id";

// Execute a SQL statement
$connection->query($sql);

// Get the last profile in the profiler
$profile = $profiler->getLastProfile();

echo "SQL Statement: ", $profile->getSQLStatement(), "\n";
echo "Start Time: ", $profile->getInitialTime(), "\n";
echo "Final Time: ", $profile->getFinalTime(), "\n";
echo "Total Elapsed Time: ", $profile->getTotalElapsedSeconds(), "\n";
```


## Properties
```php
/**
 * Active Phalcon\Db\Profiler\Item
 *
 * @var Phalcon\Db\Profiler\Item
 */
protected activeProfile;

/**
 * All the Phalcon\Db\Profiler\Item in the active profile
 *
 * @var \Phalcon\Db\Profiler\Item[]
 */
protected allProfiles;

/**
 * Total time spent by all profiles to complete
 *
 * @var float
 */
protected totalSeconds = 0;

```

## Methods
```php
public function getLastProfile(): Item;
```
Returns the last profile executed in the profiler


```php
public function getNumberTotalStatements(): int;
```
Returns the total number of SQL statements processed


```php
public function getProfiles(): Item[];
```
Returns all the processed profiles


```php
public function getTotalElapsedSeconds(): double;
```
Returns the total time in seconds spent by the profiles


```php
public function reset(): Profiler;
```
Resets the profiler, cleaning up all the profiles


```php
public function startProfile( string $sqlStatement, mixed $sqlVariables = null, mixed $sqlBindTypes = null ): Profiler;
```
Starts the profile of a SQL sentence


```php
public function stopProfile(): Profiler;
```
Stops the active profile



        
<h1 id="db-profiler-item">Class Phalcon\Db\Profiler\Item</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/db/profiler/item.zep)

| Namespace  | Phalcon\Db\Profiler |

This class identifies each profile in a Phalcon\Db\Profiler


## Properties
```php
/**
 * Timestamp when the profile ended
 *
 * @var double
 */
protected finalTime;

/**
 * Timestamp when the profile started
 *
 * @var double
 */
protected initialTime;

/**
 * SQL bind types related to the profile
 *
 * @var array
 */
protected sqlBindTypes;

/**
 * SQL statement related to the profile
 *
 * @var string
 */
protected sqlStatement;

/**
 * SQL variables related to the profile
 *
 * @var array
 */
protected sqlVariables;

```

## Methods
```php
public function getFinalTime(): double
```


```php
public function getInitialTime(): double
```


```php
public function getSqlBindTypes(): array
```


```php
public function getSqlStatement(): string
```


```php
public function getSqlVariables(): array
```


```php
public function getTotalElapsedSeconds(): double;
```
Returns the total time in seconds spent by the profile


```php
public function setFinalTime( double $finalTime )
```


```php
public function setInitialTime( double $initialTime )
```


```php
public function setSqlBindTypes( array $sqlBindTypes )
```


```php
public function setSqlStatement( string $sqlStatement )
```


```php
public function setSqlVariables( array $sqlVariables )
```



        
<h1 id="db-rawvalue">Class Phalcon\Db\RawValue</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/db/rawvalue.zep)

| Namespace  | Phalcon\Db |

This class allows to insert/update raw data without quoting or formatting.

The next example shows how to use the MySQL now() function as a field value.

```php
$subscriber = new Subscribers();

$subscriber->email     = "andres@phalcon.io";
$subscriber->createdAt = new \Phalcon\Db\RawValue("now()");

$subscriber->save();
```


## Properties
```php
/**
 * Raw value without quoting or formatting
 *
 * @var string
 */
protected value;

```

## Methods
```php
public function __construct( mixed $value ): void;
```
Phalcon\Db\RawValue constructor


```php
public function __toString(): string
```


```php
public function getValue(): string
```



        
<h1 id="db-reference">Class Phalcon\Db\Reference</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/db/reference.zep)

| Namespace  | Phalcon\Db |
| Implements | ReferenceInterface |

Allows to define reference constraints on tables

```php
$reference = new \Phalcon\Db\Reference(
    "field_fk",
    [
        "referencedSchema"  => "invoicing",
        "referencedTable"   => "products",
        "columns"           => [
            "producttype",
            "product_code",
        ],
        "referencedColumns" => [
            "type",
            "code",
        ],
    ]
);
```


## Properties
```php
/**
 * Local reference columns
 *
 * @var array
 */
protected columns;

/**
 * Constraint name
 *
 * @var string
 */
protected name;

/**
 * Referenced Columns
 *
 * @var array
 */
protected referencedColumns;

/**
 * Referenced Schema
 *
 * @var string
 */
protected referencedSchema;

/**
 * Referenced Table
 *
 * @var string
 */
protected referencedTable;

/**
 * Schema name
 *
 * @var string
 */
protected schemaName;

/**
 * ON DELETE
 *
 * @var string
 */
protected onDelete;

/**
 * ON UPDATE
 *
 * @var string
 */
protected onUpdate;

```

## Methods
```php
public function __construct( string $name, array $definition ): void;
```
Phalcon\Db\Reference constructor


```php
public function getColumns(): array
```


```php
public function getName(): string
```


```php
public function getOnDelete(): string
```


```php
public function getOnUpdate(): string
```


```php
public function getReferencedColumns(): array
```


```php
public function getReferencedSchema(): string
```


```php
public function getReferencedTable(): string
```


```php
public function getSchemaName(): string
```



        
<h1 id="db-referenceinterface">Interface Phalcon\Db\ReferenceInterface</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/db/referenceinterface.zep)

| Namespace  | Phalcon\Db |

Interface for Phalcon\Db\Reference


## Methods
```php
public function getColumns(): array;
```
Gets local columns which reference is based


```php
public function getName(): string;
```
Gets the index name


```php
public function getOnDelete(): string;
```
Gets the referenced on delete


```php
public function getOnUpdate(): string;
```
Gets the referenced on update


```php
public function getReferencedColumns(): array;
```
Gets referenced columns


```php
public function getReferencedSchema(): string;
```
Gets the schema where referenced table is


```php
public function getReferencedTable(): string;
```
Gets the referenced table


```php
public function getSchemaName(): string;
```
Gets the schema where referenced table is



        
<h1 id="db-result-pdo">Class Phalcon\Db\Result\Pdo</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/db/result/pdo.zep)

| Namespace  | Phalcon\Db\Result |
| Uses       | Phalcon\Db\Enum, Phalcon\Db\ResultInterface, Phalcon\Db\Adapter\AdapterInterface |
| Implements | ResultInterface |

Encapsulates the resultset internals

```php
$result = $connection->query("SELECTFROM robots ORDER BY name");

$result->setFetchMode(
    \Phalcon\Db\Enum::FETCH_NUM
);

while ($robot = $result->fetchArray()) {
    print_r($robot);
}
```


## Properties
```php
//
protected bindParams;

//
protected bindTypes;

//
protected connection;

/**
 * Active fetch mode
 */
protected fetchMode;

/**
 * Internal resultset
 *
 * @var \PDOStatement
 */
protected pdoStatement;

//
protected result;

//
protected rowCount = false;

//
protected sqlStatement;

```

## Methods
```php
public function __construct( AdapterInterface $connection, \PDOStatement $result, mixed $sqlStatement = null, mixed $bindParams = null, mixed $bindTypes = null ): void;
```
Phalcon\Db\Result\Pdo constructor


```php
public function dataSeek( long $number ): void;
```
Moves internal resultset cursor to another position letting us to fetch a
certain row

```php
$result = $connection->query(
    "SELECTFROM robots ORDER BY name"
);

// Move to third row on result
$result->dataSeek(2);

// Fetch third row
$row = $result->fetch();
```


```php
public function execute(): bool;
```
Allows to execute the statement again. Some database systems don't
support scrollable cursors. So, as cursors are forward only, we need to
execute the cursor again to fetch rows from the begining


```php
public function fetch( mixed $fetchStyle = null, mixed $cursorOrientation = null, mixed $cursorOffset = null );
```
Fetches an array/object of strings that corresponds to the fetched row,
or FALSE if there are no more rows. This method is affected by the active
fetch flag set using `Phalcon\Db\Result\Pdo::setFetchMode()`

```php
$result = $connection->query("SELECTFROM robots ORDER BY name");

$result->setFetchMode(
    \Phalcon\Enum::FETCH_OBJ
);

while ($robot = $result->fetch()) {
    echo $robot->name;
}
```


```php
public function fetchAll( mixed $fetchStyle = null, mixed $fetchArgument = null, mixed $ctorArgs = null ): array;
```
Returns an array of arrays containing all the records in the result
This method is affected by the active fetch flag set using
`Phalcon\Db\Result\Pdo::setFetchMode()`

```php
$result = $connection->query(
    "SELECTFROM robots ORDER BY name"
);

$robots = $result->fetchAll();
```


```php
public function fetchArray();
```
Returns an array of strings that corresponds to the fetched row, or FALSE
if there are no more rows. This method is affected by the active fetch
flag set using `Phalcon\Db\Result\Pdo::setFetchMode()`

```php
$result = $connection->query("SELECTFROM robots ORDER BY name");

$result->setFetchMode(
    \Phalcon\Enum::FETCH_NUM
);

while ($robot = result->fetchArray()) {
    print_r($robot);
}
```


```php
public function getInternalResult(): \PDOStatement;
```
Gets the internal PDO result object


```php
public function numRows(): int;
```
Gets number of rows returned by a resultset

```php
$result = $connection->query(
    "SELECTFROM robots ORDER BY name"
);

echo "There are ", $result->numRows(), " rows in the resultset";
```


```php
public function setFetchMode( int $fetchMode, mixed $colNoOrClassNameOrObject = null, mixed $ctorargs = null ): bool;
```
Changes the fetching mode affecting Phalcon\Db\Result\Pdo::fetch()

```php
// Return array with integer indexes
$result->setFetchMode(
    \Phalcon\Enum::FETCH_NUM
);

// Return associative array without integer indexes
$result->setFetchMode(
    \Phalcon\Enum::FETCH_ASSOC
);

// Return associative array together with integer indexes
$result->setFetchMode(
    \Phalcon\Enum::FETCH_BOTH
);

// Return an object
$result->setFetchMode(
    \Phalcon\Enum::FETCH_OBJ
);
```



        
<h1 id="db-resultinterface">Interface Phalcon\Db\ResultInterface</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/db/resultinterface.zep)

| Namespace  | Phalcon\Db |

Interface for Phalcon\Db\Result objects


## Methods
```php
public function dataSeek( long $number );
```
Moves internal resultset cursor to another position letting us to fetch a
certain row


```php
public function execute(): bool;
```
Allows to executes the statement again. Some database systems don't
support scrollable cursors. So, as cursors are forward only, we need to
execute the cursor again to fetch rows from the begining


```php
public function fetch(): mixed;
```
Fetches an array/object of strings that corresponds to the fetched row,
or FALSE if there are no more rows. This method is affected by the active
fetch flag set using `Phalcon\Db\Result\Pdo::setFetchMode()`


```php
public function fetchAll(): array;
```
Returns an array of arrays containing all the records in the result. This
method is affected by the active fetch flag set using
`Phalcon\Db\Result\Pdo::setFetchMode()`


```php
public function fetchArray(): mixed;
```
Returns an array of strings that corresponds to the fetched row, or FALSE
if there are no more rows. This method is affected by the active fetch
flag set using `Phalcon\Db\Result\Pdo::setFetchMode()`


```php
public function getInternalResult(): \PDOStatement;
```
Gets the internal PDO result object


```php
public function numRows(): int;
```
Gets number of rows returned by a resultset


```php
public function setFetchMode( int $fetchMode ): bool;
```
Changes the fetching mode affecting Phalcon\Db\Result\Pdo::fetch()


