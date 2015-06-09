
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Db;

use Phalcon\Db;
use Phalcon\Db\ColumnInterface;
use Phalcon\Events\EventsAwareInterface;
use Phalcon\Events\ManagerInterface;

/**
 * Phalcon\Db\Adapter
 *
 * Base class for Phalcon\Db adapters
 */
abstract class Adapter implements EventsAwareInterface
{

	/**
	 * Event Manager
	 *
	 * @var Phalcon\Events\Manager
	 */
	protected _eventsManager;

	/**
	 * Descriptor used to connect to a database
	 *
	 * @var \stdClass
	 */
	protected _descriptor;

	/**
	 * Name of the dialect used
	 */
	protected _dialectType { get };

	/**
	 * Type of database system the adapter is used for
	 */
	protected _type { get };

	/**
	 * Dialect instance
	 */
	protected _dialect;

	/**
	 * Active connection ID
	 *
	 * @var long
	 */
	protected _connectionId;

	/**
	 * Active SQL Statement
	 *
	 * @var string
	 */
	protected _sqlStatement;

	/**
	 * Active SQL bound parameter variables
	 *
	 * @var string
	 */
	protected _sqlVariables { get };

	/**
	 * Active SQL Bind Types
	 *
	 * @var string
	 */
	protected _sqlBindTypes;

	/**
	 * Current transaction level
	 */
	protected _transactionLevel = 0;

	/**
	 * Whether the database supports transactions with save points
	 */
	protected _transactionsWithSavepoints = false;

	/**
	 * Connection ID
	 */
	protected static _connectionConsecutive = 0;

	/**
	 * Phalcon\Db\Adapter constructor
	 */
	public function __construct(array! descriptor)
	{
		var dialectClass, connectionId;

		let connectionId = self::_connectionConsecutive,
			this->_connectionId = connectionId,
			self::_connectionConsecutive = connectionId + 1;

		/**
		 * Dialect class can override the default dialect
		 */
		if !fetch dialectClass, descriptor["dialectClass"] {
			let dialectClass = "phalcon\\db\\dialect\\" . this->_dialectType;
		}

		/**
		 * Create the instance only if the dialect is a string
		 */
		if typeof dialectClass == "string" {
			let this->_dialect = new {dialectClass}();
		} else {
			if typeof dialectClass == "object" {
				let this->_dialect = dialectClass;
			}
		}

		let this->_descriptor = descriptor;
	}

	/**
	 * Sets the event manager
	 */
	public function setEventsManager(<ManagerInterface> eventsManager)
	{
		let this->_eventsManager = eventsManager;
	}

	/**
	 * Returns the internal event manager
	 */
	public function getEventsManager() -> <ManagerInterface>
	{
		return this->_eventsManager;
	}

	/**
	 * Sets the dialect used to produce the SQL
	 */
	public function setDialect(<DialectInterface> dialect)
	{
		let this->_dialect = dialect;
	}

	/**
	 * Returns internal dialect instance
	 */
	public function getDialect() -> <DialectInterface>
	{
		return this->_dialect;
	}

	/**
	 * Returns the first row in a SQL query result
	 *
	 *<code>
	 *	//Getting first robot
	 *	$robot = $connection->fecthOne("SELECT * FROM robots");
	 *	print_r($robot);
	 *
	 *	//Getting first robot with associative indexes only
	 *	$robot = $connection->fecthOne("SELECT * FROM robots", Phalcon\Db::FETCH_ASSOC);
	 *	print_r($robot);
	 *</code>
	 *
	 * @param string sqlQuery
	 * @param int fetchMode
	 * @param array bindParams
	 * @param array bindTypes
	 * @return array
	 */
	public function fetchOne(string! sqlQuery, var fetchMode = Db::FETCH_BOTH, var bindParams = null, var bindTypes = null)
	{
		var result;
		let result = this->{"query"}(sqlQuery, bindParams, bindTypes);
		if typeof result == "object" {
			if typeof fetchMode !== "null" {
				result->setFetchMode(fetchMode);
			}
			return result->$fetch();
		}
		return [];
	}

	/**
	 * Dumps the complete result of a query into an array
	 *
	 *<code>
	 *	//Getting all robots with associative indexes only
	 *	$robots = $connection->fetchAll("SELECT * FROM robots", Phalcon\Db::FETCH_ASSOC);
	 *	foreach ($robots as $robot) {
	 *		print_r($robot);
	 *	}
	 *
	 *  //Getting all robots that contains word "robot" withing the name
	 *  $robots = $connection->fetchAll("SELECT * FROM robots WHERE name LIKE :name",
	 *		Phalcon\Db::FETCH_ASSOC,
	 *		array('name' => '%robot%')
	 *  );
	 *	foreach($robots as $robot){
	 *		print_r($robot);
	 *	}
	 *</code>
	 *
	 * @param string sqlQuery
	 * @param int fetchMode
	 * @param array bindParams
	 * @param array bindTypes
	 * @return array
	 */
	public function fetchAll(string sqlQuery, var fetchMode = 2, var bindParams = null, var bindTypes = null) -> array
	{
		var results, result, row;
		let results = [],
			result = this->{"query"}(sqlQuery, bindParams, bindTypes);
		if typeof result == "object" {
			if fetchMode !== null {
				result->setFetchMode(fetchMode);
			}
			loop {
				let row = result->$fetch();
				if !row {
					break;
				}

				let results[] = row;
			}
		}
		return results;
	}

	/**
	 * Returns the n'th field of first row in a SQL query result
	 *
	 *<code>
	 *	//Getting count of robots
	 *	$robotsCount = $connection->fetchColumn("SELECT count(*) FROM robots");
	 *	print_r($robotsCount);
	 *
	 *	//Getting name of last edited robot
	 *	$robot = $connection->fetchColumn("SELECT id, name FROM robots order by modified desc");
	 *	print_r($robot);
	 *</code>
	 *
	 * @param  string sqlQuery
	 * @param  array placeholders
	 * @param  int|string column
	 * @return string|
	 */
	public function fetchColumn(var sqlQuery, placeholders = null, column = 0) -> string | boolean
	{
		var row;
		let row = this->fetchOne(sqlQuery, Db::FETCH_BOTH, placeholders);
		if !empty row && isset row[column] {
			return row[column];
		}
		return false;
	}

	/**
	 * Inserts data into a table using custom RBDM SQL syntax
	 *
	 * <code>
	 * //Inserting a new robot
	 * $success = $connection->insert(
	 *	 "robots",
	 *	 array("Astro Boy", 1952),
	 *	 array("name", "year")
	 * );
	 *
	 * //Next SQL sentence is sent to the database system
	 * INSERT INTO `robots` (`name`, `year`) VALUES ("Astro boy", 1952);
	 * </code>
	 *
	 * @param   string|array table
	 * @param 	array values
	 * @param 	array fields
	 * @param 	array dataTypes
	 * @return 	boolean
	 */
	public function insert(var table, array! values, fields = null, dataTypes = null) -> boolean
	{
		var placeholders, insertValues, bindDataTypes, bindType,
			position, value, escapedTable, joinedValues, escapedFields,
			field, insertSql;

		/**
		 * A valid array with more than one element is required
		 */
		if !count(values) {
			throw new Exception("Unable to insert into " . table . " without data");
		}

		let placeholders = [],
			insertValues = [];

		let bindDataTypes = [];

		/**
		 * Objects are casted using __toString, null values are converted to string "null", everything else is passed as "?"
		 */
		for position, value in values {
			if typeof value == "object" {
				let placeholders[] = (string) value;
			} else {
				if typeof value == "null" {
					let placeholders[] = "null";
				} else {
					let placeholders[] = "?";
					let insertValues[] = value;
					if typeof dataTypes == "array" {
						if !fetch bindType, dataTypes[position] {
							throw new Exception("Incomplete number of bind types");
						}
						let bindDataTypes[] = bindType;
					}
				}
			}
		}

		if globals_get("db.escape_identifiers") {
			let escapedTable = this->{"escapeIdentifier"}(table);
		} else {
			let escapedTable = table;
		}

		/**
		 * Build the final SQL INSERT statement
		 */
		let joinedValues = join(", ", placeholders);
		if typeof fields == "array" {

			if globals_get("db.escape_identifiers") {
				let escapedFields = [];
				for field in fields {
					let escapedFields[] = this->{"escapeIdentifier"}(field);
				}
			} else {
				let escapedFields = fields;
			}

			let insertSql = "INSERT INTO " . escapedTable . " (" . join(", ", escapedFields) . ") VALUES (" . joinedValues . ")";
		} else {
			let insertSql = "INSERT INTO " . escapedTable . " VALUES (" . joinedValues . ")";
		}

		/**
		 * Perform the execution via PDO::execute
		 */
		if !count(bindDataTypes) {
			return this->{"execute"}(insertSql, insertValues);
		}

		return this->{"execute"}(insertSql, insertValues, bindDataTypes);
	}

	/**
	 * Inserts data into a table using custom RBDM SQL syntax
	 * Another, more convenient syntax
	 *
	 * <code>
	 * //Inserting a new robot
	 * $success = $connection->insert(
	 *	 "robots",
	 *	 array(
	 *		  "name" => "Astro Boy",
	 *		  "year" => 1952
	 *	  )
	 * );
	 *
	 * //Next SQL sentence is sent to the database system
	 * INSERT INTO `robots` (`name`, `year`) VALUES ("Astro boy", 1952);
	 * </code>
	 *
	 * @param 	string table
	 * @param 	array data
	 * @param 	array dataTypes
	 * @return 	boolean
	 */
	public function insertAsDict(var table, data, var dataTypes = null) -> boolean
	{
		var values = [], fields = [];
		var field, value;

		if typeof data != "array" || empty data {
			return false;
		}

		for field, value in data {
			let fields[] = field;
			let values[] = value;
		}

		return this->insert(table, values, fields, dataTypes);
	}

	/**
	 * Updates data on a table using custom RBDM SQL syntax
	 *
	 * <code>
	 * //Updating existing robot
	 * $success = $connection->update(
	 *	 "robots",
	 *	 array("name"),
	 *	 array("New Astro Boy"),
	 *	 "id = 101"
	 * );
	 *
	 * //Next SQL sentence is sent to the database system
	 * UPDATE `robots` SET `name` = "Astro boy" WHERE id = 101
	 *
	 * //Updating existing robot with array condition and $dataTypes
	 * $success = $connection->update(
	 *	 "robots",
	 *	 array("name"),
	 *	 array("New Astro Boy"),
	 *	 array(
	 *		 'conditions' => "id = ?",
	 *		 'bind' => array($some_unsafe_id),
	 *		 'bindTypes' => array(PDO::PARAM_INT) //use only if you use $dataTypes param
	 *	 ),
	 *	 array(PDO::PARAM_STR)
	 * );
	 *
	 * </code>
	 *
	 * Warning! If $whereCondition is string it not escaped.
	 *
	 * @param   string|array table
	 * @param 	array fields
	 * @param 	array values
	 * @param 	string|array whereCondition
	 * @param 	array dataTypes
	 * @return 	boolean
	 */
	public function update(var table, fields, values, whereCondition = null, dataTypes = null) -> boolean
	{
		var placeholders, updateValues, position, value,
			field, bindDataTypes, escapedField, bindType, escapedTable,
			setClause, updateSql, conditions, whereBind, whereTypes;

		let placeholders = [],
			updateValues = [];

		let bindDataTypes = [];

		/**
		 * Objects are casted using __toString, null values are converted to string 'null', everything else is passed as '?'
		 */
		for position, value in values {

			if !fetch field, fields[position] {
				throw new Exception("The number of values in the update is not the same as fields");
			}

			if globals_get("db.escape_identifiers") {
				let escapedField = this->{"escapeIdentifier"}(field);
			} else {
				let escapedField = field;
			}

			if typeof value == "object" {
				let placeholders[] = escapedField . " = " . value;
			} else {
				if typeof value == "null" {
					let placeholders[] = escapedField . " = null";
				} else {
					let updateValues[] = value;
					if typeof dataTypes == "array" {
						if !fetch bindType, dataTypes[position] {
							throw new Exception("Incomplete number of bind types");
						}
						let bindDataTypes[] = bindType;
					}
					let placeholders[] = escapedField . " = ?";
				}
			}
		}

		if globals_get("db.escape_identifiers") {
			let escapedTable = this->{"escapeIdentifier"}(table);
		} else {
			let escapedTable = table;
		}

		let setClause = join(", ", placeholders);

		if whereCondition !== null {

			let updateSql = "UPDATE " . escapedTable . " SET " . setClause . " WHERE ";

			/**
			 * String conditions are simply appended to the SQL
			 */
			if typeof whereCondition == "string" {
				let updateSql .= whereCondition;
			} else {

				/**
				 * Array conditions may have bound params and bound types
				 */
				if typeof whereCondition != "array" {
					throw new Exception("Invalid WHERE clause conditions");
				}

				/**
				 * If an index 'conditions' is present it contains string where conditions that are appended to the UPDATE sql
				 */
				if fetch conditions, whereCondition["conditions"] {
					let updateSql .= conditions;
				}

				/**
				 * Bound parameters are arbitrary values that are passed by separate
				 */
				if fetch whereBind, whereCondition["bind"] {
					merge_append(updateValues, whereBind);
				}

				/**
				 * Bind types is how the bound parameters must be casted before be sent to the database system
				 */
				if fetch whereTypes, whereCondition["bindTypes"] {
					merge_append(bindDataTypes, whereTypes);
				}
			}
		} else {
			let updateSql = "UPDATE " . escapedTable . " SET " . setClause;
		}

		/**
		 * Perform the update via PDO::execute
		 */
		if !count(bindDataTypes) {
			return this->{"execute"}(updateSql, updateValues);
		}

		return this->{"execute"}(updateSql, updateValues, bindDataTypes);
	}

	/**
	 * Updates data on a table using custom RBDM SQL syntax
	 * Another, more convenient syntax
	 *
	 * <code>
	 * //Updating existing robot
	 * $success = $connection->update(
	 *	 "robots",
	 *	 array(
	 *		  "name" => "New Astro Boy"
	 *	  ),
	 *	 "id = 101"
	 * );
	 *
	 * //Next SQL sentence is sent to the database system
	 * UPDATE `robots` SET `name` = "Astro boy" WHERE id = 101
	 * </code>
	 *
	 * @param 	string table
	 * @param 	array data
	 * @param 	string whereCondition
	 * @param 	array dataTypes
	 * @return 	boolean
	 */
	public function updateAsDict(var table, data, whereCondition = null, dataTypes = null) -> boolean
	{
		var values = [], fields = [];
		var field, value;

		if typeof data != "array" || empty data {
			return false;
		}

		for field, value in data {
			let fields[] = field;
			let values[] = value;
		}

		return this->update(table, fields, values, whereCondition, dataTypes);
	}

	/**
	 * Deletes data from a table using custom RBDM SQL syntax
	 *
	 * <code>
	 * //Deleting existing robot
	 * $success = $connection->delete(
	 *	 "robots",
	 *	 "id = 101"
	 * );
	 *
	 * //Next SQL sentence is generated
	 * DELETE FROM `robots` WHERE `id` = 101
	 * </code>
	 *
	 * @param  string|array table
	 * @param  string whereCondition
	 * @param  array placeholders
	 * @param  array dataTypes
	 * @return boolean
	 */
	public function delete(var table, whereCondition = null, placeholders = null, dataTypes = null) -> boolean
	{
		var sql, escapedTable;

		if globals_get("db.escape_identifiers") {
			let escapedTable = this->{"escapeIdentifier"}(table);
		} else {
			let escapedTable = table;
		}

		if !empty whereCondition {
			let sql = "DELETE FROM " . escapedTable . " WHERE " . whereCondition;
		} else {
			let sql = "DELETE FROM " . escapedTable;
		}

		/**
		 * Perform the update via PDO::execute
		 */
		return this->{"execute"}(sql, placeholders, dataTypes);
	}

	/**
	 * Gets a list of columns
	 *
	 * @param	array columnList
	 * @return	string
	 */
	public function getColumnList(var columnList) -> string
	{
		return this->_dialect->getColumnList(columnList);
	}

	/**
	 * Appends a LIMIT clause to $sqlQuery argument
	 *
	 * <code>
	 * 	echo $connection->limit("SELECT * FROM robots", 5);
	 * </code>
	 */
	public function limit(string! sqlQuery, int number) -> string
	{
		return this->_dialect->limit(sqlQuery, number);
	}

	/**
	 * Generates SQL checking for the existence of a schema.table
	 *
	 * <code>
	 * 	var_dump($connection->tableExists("blog", "posts"));
	 * </code>
	 */
	public function tableExists(string! tableName, string! schemaName = null) -> boolean
	{
		return this->fetchOne(this->_dialect->tableExists(tableName, schemaName), Db::FETCH_NUM)[0] > 0;
	}

	/**
	 * Generates SQL checking for the existence of a schema.view
	 *
	 *<code>
	 * var_dump($connection->viewExists("active_users", "posts"));
	 *</code>
	 */
	public function viewExists(string! viewName, string! schemaName = null) -> boolean
	{
		return this->fetchOne(this->_dialect->viewExists(viewName, schemaName), Db::FETCH_NUM)[0] > 0;
	}

	/**
	 * Returns a SQL modified with a FOR UPDATE clause
	 */
	public function forUpdate(string! sqlQuery) -> string
	{
		return this->_dialect->forUpdate(sqlQuery);
	}

	/**
	 * Returns a SQL modified with a LOCK IN SHARE MODE clause
	 */
	public function sharedLock(string! sqlQuery) -> string
	{
		return this->_dialect->sharedLock(sqlQuery);
	}

	/**
	 * Creates a table
	 */
	public function createTable(string! tableName, string! schemaName, array! definition) -> boolean
	{
		var columns;

		if !fetch columns, definition["columns"] {
			throw new Exception("The table must contain at least one column");
		}

		if !count(columns) {
			throw new Exception("The table must contain at least one column");
		}

		return this->{"execute"}(this->_dialect->createTable(tableName, schemaName, definition));
	}

	/**
	 * Drops a table from a schema/database
	 */
	public function dropTable(string! tableName, string! schemaName = null, boolean ifExists = true) -> boolean
	{
		return this->{"execute"}(this->_dialect->dropTable(tableName, schemaName, ifExists));
	}

	/**
	 * Creates a view
	 *
	 * @param	string tableName
	 * @param	array definition
	 * @param	string schemaName
	 * @return	boolean
	 */
	public function createView(string! viewName, array! definition, schemaName = null) -> boolean
	{
		if !isset definition["sql"] {
			throw new Exception("The table must contain at least one column");
		}

		return this->{"execute"}(this->_dialect->createView(viewName, definition, schemaName));
	}

	/**
	 * Drops a view
	 */
	public function dropView(string! viewName, string! schemaName = null, boolean ifExists = true) -> boolean
	{
		return this->{"execute"}(this->_dialect->dropView(viewName, schemaName, ifExists));
	}

	/**
	 * Adds a column to a table
	 */
	public function addColumn(string! tableName, string! schemaName, <ColumnInterface> column) -> boolean
	{
		return this->{"execute"}(this->_dialect->addColumn(tableName, schemaName, column));
	}

	/**
	 * Modifies a table column based on a definition
	 */
	public function modifyColumn(string! tableName, string! schemaName, <ColumnInterface> column, <ColumnInterface> currentColumn = null) -> boolean
	{
		return this->{"execute"}(this->_dialect->modifyColumn(tableName, schemaName, column, currentColumn));
	}

	/**
	 * Drops a column from a table
	 */
	public function dropColumn(string! tableName, string! schemaName, string columnName) -> boolean
	{
		return this->{"execute"}(this->_dialect->dropColumn(tableName, schemaName, columnName));
	}

	/**
	 * Adds an index to a table
	 */
	public function addIndex(string! tableName, string! schemaName, <IndexInterface> index) -> boolean
	{
		return this->{"execute"}(this->_dialect->addIndex(tableName, schemaName, index));
	}

	/**
	 * Drop an index from a table
	 */
	public function dropIndex(string! tableName, string! schemaName, indexName) -> boolean
	{
		return this->{"execute"}(this->_dialect->dropIndex(tableName, schemaName, indexName));
	}

	/**
	 * Adds a primary key to a table
	 */
	public function addPrimaryKey(string! tableName, string! schemaName, <IndexInterface> index) -> boolean
	{
		return this->{"execute"}(this->_dialect->addPrimaryKey(tableName, schemaName, index));
	}

	/**
	 * Drops a table's primary key
	 */
	public function dropPrimaryKey(string! tableName, string! schemaName) -> boolean
	{
		return this->{"execute"}(this->_dialect->dropPrimaryKey(tableName, schemaName));
	}

	/**
	 * Adds a foreign key to a table
	 */
	public function addForeignKey(string! tableName, string! schemaName, <ReferenceInterface> reference) -> boolean
	{
		return this->{"execute"}(this->_dialect->addForeignKey(tableName, schemaName, reference));
	}

	/**
	 * Drops a foreign key from a table
	 */
	public function dropForeignKey(string! tableName, string! schemaName, string! referenceName) -> boolean
	{
		return this->{"execute"}(this->_dialect->dropForeignKey(tableName, schemaName, referenceName));
	}

	/**
	 * Returns the SQL column definition from a column
	 */
	public function getColumnDefinition(<ColumnInterface> column) -> string
	{
		return this->_dialect->getColumnDefinition(column);
	}

	/**
	 * List all tables on a database
	 *
	 *<code>
	 * 	print_r($connection->listTables("blog"));
	 *</code>
	 */
	public function listTables(string! schemaName = null) -> array
	{
		var table, allTables;

		let allTables = [];
		for table in this->fetchAll(this->_dialect->listTables(schemaName), Db::FETCH_NUM) {
			let allTables[] = table[0];
		}
		return allTables;
	}

	/**
	 * List all views on a database
	 *
	 *<code>
	 *	print_r($connection->listViews("blog"));
	 *</code>
	 */
	public function listViews(string! schemaName = null) -> array
	{
		var table, allTables;

		let allTables = [];
		for table in this->fetchAll(this->_dialect->listViews(schemaName), Db::FETCH_NUM) {
			let allTables[] = table[0];
		}
		return allTables;
	}

	/**
	 * Lists table indexes
	 *
	 *<code>
	 *	print_r($connection->describeIndexes('robots_parts'));
	 *</code>
	 *
	 * @param	string table
	 * @param	string schema
	 * @return	Phalcon\Db\Index[]
	 */
	public function describeIndexes(string! table, schema = null) -> <Index[]>
	{
		var indexes, index, keyName, indexObjects, name, indexColumns, columns;

		let indexes = [];
		for index in this->fetchAll(this->_dialect->describeIndexes(table, schema), Db::FETCH_NUM) {

			let keyName = index[2];
			if !isset indexes[keyName] {
				let columns = [];
			} else {
				let columns = indexes[keyName];
			}

			let columns[] = index[4];
			let indexes[keyName] = columns;
		}

		let indexObjects = [];
		for name, indexColumns in indexes {

			/**
			 * Every index is abstracted using a Phalcon\Db\Index instance
			 */
			let indexObjects[name] = new Index(name, indexColumns);
		}

		return indexObjects;
	}

	/**
	 * Lists table references
	 *
	 *<code>
	 * print_r($connection->describeReferences('robots_parts'));
	 *</code>
	 */
	public function describeReferences(string! table, string! schema = null) -> <Reference[]>
	{
		var references, reference,
			arrayReference, constraintName, referenceObjects, name,
			referencedSchema, referencedTable, columns, referencedColumns;

		let references = [];

		for reference in this->fetchAll(this->_dialect->describeReferences(table, schema),Db::FETCH_NUM) {

			let constraintName = reference[2];
			if !isset references[constraintName] {
				let referencedSchema = reference[3];
				let referencedTable = reference[4];
				let columns = [];
				let referencedColumns = [];
			} else {
				let referencedSchema = references[constraintName]["referencedSchema"];
				let referencedTable = references[constraintName]["referencedTable"];
				let columns = references[constraintName]["columns"];
				let referencedColumns = references[constraintName]["referencedColumns"];
			}

			let columns[] = reference[1],
				referencedColumns[] = reference[5];

			let references[constraintName] = [
				"referencedSchema"  : referencedSchema,
				"referencedTable"   : referencedTable,
				"columns"           : columns,
				"referencedColumns" : referencedColumns
			];
		}

		let referenceObjects = [];
		for name, arrayReference in references {
			let referenceObjects[name] = new Reference(name, [
				"referencedSchema"  : arrayReference["referencedSchema"],
				"referencedTable"   : arrayReference["referencedTable"],
				"columns"           : arrayReference["columns"],
				"referencedColumns" : arrayReference["referencedColumns"]
			]);
		}

		return referenceObjects;
	}

	/**
	 * Gets creation options from a table
	 *
	 *<code>
	 * print_r($connection->tableOptions('robots'));
	 *</code>
	 */
	public function tableOptions(string! tableName, string schemaName = null) -> array
	{
		var sql;

		let sql = this->_dialect->tableOptions(tableName, schemaName);
		if sql {
			return this->fetchAll(sql, Db::FETCH_ASSOC)[0];
		}
		return [];
	}

	/**
	 * Creates a new savepoint
	 */
	public function createSavepoint(string! name) -> boolean
	{
		var dialect;

		let dialect = this->_dialect;

		if !dialect->supportsSavePoints() {
			throw new Exception("Savepoints are not supported by this database adapter.");
		}

		return this->{"execute"}(dialect->createSavepoint(name));
	}

	/**
	 * Releases given savepoint
	 */
	public function releaseSavepoint(string! name) -> boolean
	{
		var dialect;

		let dialect = this->_dialect;

		if !dialect->supportsSavePoints() {
			throw new Exception("Savepoints are not supported by this database adapter");
		}

		if !dialect->supportsReleaseSavePoints() {
			return false;
		}

		return this->{"execute"}(dialect->releaseSavepoint(name));
	}

	/**
	 * Rollbacks given savepoint
	 */
	public function rollbackSavepoint(string! name) -> boolean
	{
		var dialect;

		let dialect = this->_dialect;

		if !dialect->supportsSavePoints() {
			throw new Exception("Savepoints are not supported by this database adapter");
		}

		return this->{"execute"}(dialect->rollbackSavepoint(name));
	}

	/**
	 * Set if nested transactions should use savepoints
	 */
	public function setNestedTransactionsWithSavepoints(boolean nestedTransactionsWithSavepoints) -> <AdapterInterface>
	{

		if this->_transactionLevel > 0 {
			throw new Exception("Nested transaction with savepoints behavior cannot be changed while a transaction is open");
		}

		if !this->_dialect->supportsSavePoints() {
			throw new Exception("Savepoints are not supported by this database adapter");
		}

		let this->_transactionsWithSavepoints = nestedTransactionsWithSavepoints;
		return this;
	}

	/**
	 * Returns if nested transactions should use savepoints
	 */
	public function isNestedTransactionsWithSavepoints() -> boolean
	{
		return this->_transactionsWithSavepoints;
	}

	/**
	 * Returns the savepoint name to use for nested transactions
	 */
	public function getNestedTransactionSavepointName() -> string
	{
		return "PHALCON_SAVEPOINT_" . this->_transactionLevel;
	}

	/**
	 * Returns the default identity value to be inserted in an identity column
	 *
	 *<code>
	 * //Inserting a new robot with a valid default value for the column 'id'
	 * $success = $connection->insert(
	 *	 "robots",
	 *	 array($connection->getDefaultIdValue(), "Astro Boy", 1952),
	 *	 array("id", "name", "year")
	 * );
	 *</code>
	 */
	public function getDefaultIdValue() -> <RawValue>
	{
		return new RawValue("null");
	}

	/**
	 * Check whether the database system requires a sequence to produce auto-numeric values
	 */
	public function supportSequences() -> boolean
	{
		return false;
	}

	/**
	 * Check whether the database system requires an explicit value for identity columns
	 */
	public function useExplicitIdValue() -> boolean
	{
		return false;
	}

	/**
	 * Return descriptor used to connect to the active database
	 *
	 * @return array
	 */
	public function getDescriptor()
	{
		return this->_descriptor;
	}

	/**
	 * Gets the active connection unique identifier
	 *
	 * @return string
	 */
	public function getConnectionId()
	{
		return this->_connectionId;
	}

	/**
	 * Active SQL statement in the object
	 */
	public function getSQLStatement() -> string
	{
		return this->_sqlStatement;
	}

	/**
	 * Active SQL statement in the object without replace bound paramters
	 */
	public function getRealSQLStatement() -> string
	{
		return this->_sqlStatement;
	}

	/**
	 * Active SQL statement in the object
	 *
	 * @return array
	 */
	public function getSQLBindTypes()
	{
		return this->_sqlBindTypes;
	}
}
