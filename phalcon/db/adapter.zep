
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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

/**
 * Phalcon\Db\Adapter
 *
 * Base class for Phalcon\Db adapters
 */
abstract class Adapter implements Phalcon\Events\EventsAwareInterface
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
	 * @var stdClass
	 */
	protected _descriptor;

	/**
	 * Dialect Type
	 */
	protected _dialectType;

	/**
	 * Type of database backend
	 */
	protected _type;

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
	 * Active SQL Variables
	 *
	 * @var string
	 */
	protected _sqlVariables;

	/**
	 * Active SQL Bind Types
	 *
	 * @var string
	 */
	protected _sqlBindTypes;

	protected _transactionLevel = 0;

	protected _transactionsWithSavepoints = 0;

	/**
	 * Connection ID
	 */
	protected static _connectionConsecutive = 0;

	/**
	 * Phalcon\Db\Adapter constructor
	 *
	 * @param array descriptor
	 */
	public function __construct(descriptor)
	{
		var dialectClass;

		let this->_connectionId = 0;

		/**
		 * Dialect class can override the default dialect
		 */
		if fetch dialectClass, descriptor["dialectClass"] {
			let dialectClass = "phalcon\\db\\dialect\\" . this->_dialectType;
		}

		/**
		 * Create the instance only if the dialect is a string
		 */
		if typeof dialectClass == "string" {
			//let this->_dialect = new {dialectClass}();
		}

		let this->_descriptor = descriptor;
	}

	/**
	 * Sets the event manager
	 *
	 * @param Phalcon\Events\ManagerInterface eventsManager
	 */
	public function setEventsManager(<Phalcon\Events\ManagerInterface> eventsManager)
	{
		let this->_eventsManager = eventsManager;
	}

	/**
	 * Returns the internal event manager
	 *
	 * @return Phalcon\Events\ManagerInterface
	 */
	public function getEventsManager()
	{
		return this->_eventsManager;
	}

	/**
	 * Sets the dialect used to produce the SQL
	 *
	 * @param Phalcon\Db\DialectInterface
	 */
	public function setDialect(dialect)
	{
		let this->_dialect = dialect;
	}

	/**
	 * Returns internal dialect instance
	 *
	 * @return Phalcon\Db\DialectInterface
	 */
	public function getDialect()
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
	public function fetchOne(sqlQuery, fetchMode=2, bindParams=null, bindTypes=null)
	{
		var result;
		let result = this->{"query"}(sqlQuery, bindParams, bindTypes);
		if typeof result == "object" {
			if typeof fetchMode !== null {
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
	public function fetchAll(sqlQuery, fetchMode=2, bindParams=null, bindTypes=null)
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
				} else {
					let results[] = row;
				}
			}
		}
		return results;
	}

	/**
	 * Inserts data into a table using custom RBDM SQL syntax
	 *
	 * <code>
	 * //Inserting a new robot
	 * $success = $connection->insert(
	 *     "robots",
	 *     array("Astro Boy", 1952),
	 *     array("name", "year")
	 * );
	 *
	 * //Next SQL sentence is sent to the database system
	 * INSERT INTO `robots` (`name`, `year`) VALUES ("Astro boy", 1952);
	 * </code>
	 *
	 * @param 	string table
	 * @param 	array values
	 * @param 	array fields
	 * @param 	array dataTypes
	 * @return 	boolean
	 */
	public function insert(table, values, fields=null, dataTypes=null)
	{
		var placeholders, insertValues, bindDataTypes, bindType,
			position, value, escapedTable, joinedValues, escapedFields,
			field, insertSql;

		if typeof values != "array" {
			throw new Phalcon\Db\Exception("The second parameter for insert isn't an Array");
		}

		/**
		 * A valid array with more than one element is required
		 */
		if !count(values) {
			throw new Phalcon\Db\Exception("Unable to insert into " . table . " without data");
		}

		let placeholders = [],
			insertValues = [];

		if typeof dataTypes != "array" {
			let bindDataTypes = [];
		} else {
			let bindDataTypes = dataTypes;
		}

		/**
		 * Objects are casted using __toString, null values are converted to string "null", everything else is passed as "?"
		 */
		for position, value in values {
			if typeof value == "object" {
				//let placeholders[] = (string) value;
			} else {
				if typeof value == "null" {
					let placeholders[] = "null";
				} else {
					let placeholders[] = "?";
					let insertValues[] = value;
					if typeof dataTypes == "array" {
						if !fetch bindType, dataTypes[position] {
							throw new Phalcon\Db\Exception("Incomplete number of bind types");
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
		return this->{"execute"}(insertSql, insertValues, bindDataTypes);
	}

	/**
	 * Updates data on a table using custom RBDM SQL syntax
	 *
	 * <code>
	 * //Updating existing robot
	 * $success = $connection->update(
	 *     "robots",
	 *     array("name"),
	 *     array("New Astro Boy"),
	 *     "id = 101"
	 * );
	 *
	 * //Next SQL sentence is sent to the database system
	 * UPDATE `robots` SET `name` = "Astro boy" WHERE id = 101
	 * </code>
	 *
	 * @param 	string table
	 * @param 	array fields
	 * @param 	array values
	 * @param 	string whereCondition
	 * @param 	array dataTypes
	 * @return 	boolean
	 */
	public function update(table, fields, values, whereCondition=null, dataTypes=null)
	{
		var placeholders, updateValues, position, value,
			field, bindDataTypes, escapedField, bindType, escapedTable,
			setClause, updateSql, conditions, whereBind, whereTypes;

		let placeholders = [],
			updateValues = [];

		if typeof dataTypes == "array" {
			let bindDataTypes = [];
		} else {
			let bindDataTypes = dataTypes;
		}

		/**
		 * Objects are casted using __toString, null values are converted to string 'null', everything else is passed as '?'
		 */
		for position, value in values {

			if !fetch field, fields[position] {
				throw new Phalcon\Db\Exception("The number of values in the update is not the same as fields");
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
							throw new Phalcon\Db\Exception("Incomplete number of bind types");
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
			if typeof whereCondition == "array" {
				let updateSql .= whereCondition;
			} else {

				/**
				 * Array conditions may have bound params and bound types
				 */
				if typeof whereCondition != "array" {
					throw new Phalcon\Db\Exception("Invalid WHERE clause conditions");
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
		return this->{"execute"}(updateSql, updateValues, bindDataTypes);
	}

	/**
	 * Deletes data from a table using custom RBDM SQL syntax
	 *
	 * <code>
	 * //Deleting existing robot
	 * $success = $connection->delete(
	 *     "robots",
	 *     "id = 101"
	 * );
	 *
	 * //Next SQL sentence is generated
	 * DELETE FROM `robots` WHERE `id` = 101
	 * </code>
	 *
	 * @param  string table
	 * @param  string whereCondition
	 * @param  array placeholders
	 * @param  array dataTypes
	 * @return boolean
	 */
	public function delete(table, whereCondition=null, placeholders=null, dataTypes=null)
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
	public function getColumnList(columnList)
	{
		var dialect;
		let dialect = this->_dialect;
		return dialect->getColumnList(columnList);
	}

	/**
	 * Appends a LIMIT clause to $sqlQuery argument
	 *
	 * <code>
	 * 	echo $connection->limit("SELECT * FROM robots", 5);
	 * </code>
	 *
	 * @param  	string sqlQuery
	 * @param 	int number
	 * @return 	string
	 */
	public function limit(sqlQuery, number)
	{
		var dialect;
		let dialect = this->_dialect;
		return dialect->limit(sqlQuery, number);
	}

	/**
	 * Generates SQL checking for the existence of a schema.table
	 *
	 * <code>
	 * 	var_dump($connection->tableExists("blog", "posts"));
	 * </code>
	 *
	 * @param string tableName
	 * @param string schemaName
	 * @return string
	 */
	public function tableExists(tableName, schemaName=null)
	{
		var dialect, num;
		let dialect = this->_dialect;
		let num = this->fetchOne(dialect->tableExists(tableName, schemaName), Phalcon\DB::FETCH_NUM);
		return num[0];
	}

	/**
	 * Generates SQL checking for the existence of a schema.view
	 *
	 *<code>
	 * var_dump($connection->viewExists("active_users", "posts"));
	 *</code>
	 *
	 * @param string viewName
	 * @param string schemaName
	 * @return string
	 */
	public function viewExists(viewName, schemaName=null)
	{
		var dialect, num;
		let dialect = this->_dialect;
		let num = this->fetchOne(dialect->viewExists(viewName, schemaName), Phalcon\Db::FETCH_NUM);
		return num[0];
	}

	/**
	 * Returns a SQL modified with a FOR UPDATE clause
	 *
	 * @param	string sqlQuery
	 * @return	string
	 */
	public function forUpdate(sqlQuery)
	{
		var dialect;
		let dialect = this->_dialect;
		return dialect->forUpdate(sqlQuery);
	}

	/**
	 * Returns a SQL modified with a LOCK IN SHARE MODE clause
	 *
	 * @param	string sqlQuery
	 * @return	string
	 */
	public function sharedLock(sqlQuery)
	{
		var dialect;
		let dialect = this->_dialect;
		return dialect->sharedLock(sqlQuery);
	}

	/**
	 * Creates a table
	 *
	 * @param	string tableName
	 * @param	string schemaName
	 * @param	array definition
	 * @return	boolean
	 */
	public function createTable(tableName, schemaName, definition)
	{
		var dialect, columns;

		if typeof definition != "array" {
			throw new Phalcon\Db\Exception("Invalid definition to create the table '" . tableName . "'");
		}

		if !fetch columns, definition["columns"] {
			throw new Phalcon\Db\Exception("The table must contain at least one column");
		}

		if !count(columns) {
			throw new Phalcon\Db\Exception("The table must contain at least one column");
		}

		let dialect = this->_dialect;
		return this->{"execute"}(dialect->createTable(tableName, schemaName, definition));
	}

	/**
	 * Drops a table from a schema/database
	 *
	 * @param	string tableName
	 * @param   string schemaName
	 * @param	boolean ifExists
	 * @return	boolean
	 */
	public function dropTable(tableName, schemaName=null, ifExists=true)
	{
		var dialect;
		let dialect = this->_dialect;
		return this->{"execute"}(dialect->dropTable(tableName, schemaName, ifExists));
	}

	/**
	 * Creates a view
	 *
	 * @param	string tableName
	 * @param	array definition
	 * @param	string schemaName
	 * @return	boolean
	 */
	public function createView(viewName, definition, schemaName=null)
	{
		var dialect;

		if typeof definition != "array" {
			throw new Phalcon\Db\Exception("Invalid definition to create the view '" . viewName . "'");
		}

		if !isset definition["sql"] {
			throw new Phalcon\Db\Exception("The table must contain at least one column");
		}

		let dialect = this->_dialect;
		return this->{"execute"}(dialect->createView(viewName, definition, schemaName));
	}

	/**
	 * Drops a view
	 *
	 * @param	string viewName
	 * @param   string schemaName
	 * @param	boolean ifExists
	 * @return	boolean
	 */
	public function dropView(viewName, schemaName=null, ifExists=true)
	{
		var dialect;
		let dialect = this->_dialect;
		return this->{"execute"}(dialect->dropView(viewName, schemaName, ifExists));
	}

	/**
	 * Adds a column to a table
	 *
	 * @param	string tableName
	 * @param 	string schemaName
	 * @param	Phalcon\Db\ColumnInterface column
	 * @return	boolean
	 */
	public function addColumn(tableName, schemaName, <Phalcon\Db\ColumnInterface> column)
	{
		var dialect;
		let dialect = this->_dialect;
		return this->{"execute"}(dialect->addColumn(tableName, schemaName, column));
	}

	/**
	 * Modifies a table column based on a definition
	 *
	 * @param	string tableName
	 * @param	string schemaName
	 * @param	Phalcon\Db\ColumnInterface column
	 * @return 	boolean
	 */
	public function modifyColumn(tableName, schemaName, <Phalcon\Db\ColumnInterface> column)
	{
		var dialect;
		let dialect = this->_dialect;
		return this->{"execute"}(dialect->modifyColumn(tableName, schemaName, column));
	}

	/**
	 * Drops a column from a table
	 *
	 * @param	string tableName
	 * @param	string schemaName
	 * @param	string columnName
	 * @return 	boolean
	 */
	public function dropColumn(tableName, schemaName, columnName)
	{
		var dialect;
		let dialect = this->_dialect;
		return this->{"execute"}(dialect->dropColumn(tableName, schemaName, columnName));
	}

	/**
	 * Adds an index to a table
	 *
	 * @param	string tableName
	 * @param	string schemaName
	 * @param	Phalcon\Db\IndexInterface index
	 * @return 	boolean
	 */
	public function addIndex(tableName, schemaName, index)
	{
		var dialect;
		let dialect = this->_dialect;
		return this->{"execute"}(dialect->addIndex(tableName, schemaName, index));
	}

	/**
	 * Drop an index from a table
	 *
	 * @param	string tableName
	 * @param	string schemaName
	 * @param	string indexName
	 * @return 	boolean
	 */
	public function dropIndex(tableName, schemaName, indexName)
	{
		var dialect;
		let dialect = this->_dialect;
		return this->{"execute"}(dialect->dropIndex(tableName, schemaName, indexName));
	}

	/**
	 * Adds a primary key to a table
	 *
	 * @param	string tableName
	 * @param	string schemaName
	 * @param	Phalcon\Db\IndexInterface index
	 * @return 	boolean
	 */
	public function addPrimaryKey(tableName, schemaName, <Phalcon\Db\IndexInterface> index)
	{
		var dialect;
		let dialect = this->_dialect;
		return this->{"execute"}(dialect->addPrimaryKey(tableName, schemaName, index));
	}

	/**
	 * Drops a table's primary key
	 *
	 * @param	string tableName
	 * @param	string schemaName
	 * @return 	boolean
	 */
	public function dropPrimaryKey(tableName, schemaName)
	{
		var dialect;
		let dialect = this->_dialect;
		return this->{"execute"}(dialect->dropPrimaryKey(tableName, schemaName));
	}

	/**
	 * Adds a foreign key to a table
	 *
	 * @param	string $tableName
	 * @param	string $schemaName
	 * @param	Phalcon\Db\ReferenceInterface $reference
	 * @return	boolean true
	 */
	public function addForeignKey($tableName, $schemaName, $reference)
	{
		var dialect;
		let dialect = this->_dialect;
		return this->{"execute"}(dialect->addForeignKey(tableName, schemaName, reference));
	}

	/**
	 * Drops a foreign key from a table
	 *
	 * @param	string $tableName
	 * @param	string $schemaName
	 * @param	string $referenceName
	 * @return	boolean true
	 */
	public function dropForeignKey(tableName, schemaName, referenceName)
	{
		var dialect;
		let dialect = this->_dialect;
		return this->{"execute"}(dialect->dropForeignKey(tableName, schemaName, referenceName));
	}

	/**
	 * Returns the SQL column definition from a column
	 *
	 * @param	Phalcon\Db\ColumnInterface column
	 * @return	string
	 */
	public function getColumnDefinition(<Phalcon\Db\ColumnInterface> column)
	{
		var dialect;
		let dialect = this->_dialect;
		return dialect->getColumnDefinition(column);
	}

	/**
	 * List all tables on a database
	 *
	 *<code>
	 * 	print_r($connection->listTables("blog"));
	 *</code>
	 *
	 * @param string schemaName
	 * @return array
	 */
	public function listTables($schemaName=null)
	{
		var dialect, table, allTables;

		let dialect = this->_dialect;

		let allTables = [];
		for table in this->fetchAll(dialect->listTables(schemaName), Phalcon\Db::FETCH_NUM) {
			let allTables[] = table[0];
		}
		return allTables;
	}

	/**
	 * List all views on a database
	 *
	 *<code>
	 *	print_r($connection->listViews("blog")); ?>
	 *</code>
	 *
	 * @param string schemaName
	 * @return array
	 */
	public function listViews(schemaName=null)
	{
		var dialect, table, allTables;

		let dialect = this->_dialect;

		let allTables = [];
		for table in this->fetchAll(dialect->listViews(schemaName), Phalcon\Db::FETCH_NUM) {
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
	public function describeIndexes(table, schema=null)
	{
		var dialect, indexes, index, keyName, indexObjects,
			name, indexColumns;

		let dialect = this->_dialect;

		let indexes = [];
		for index in this->fetchAll(dialect->describeIndexes(table, schema), Phalcon\Db::FETCH_NUM) {

			let keyName = index[2];
			if !isset indexes[keyName] {
				let indexes[keyName] = [];
			}

			//let indexes[keyName][] = index[4];
		}

		let indexObjects = [];
		for name, indexColumns in indexes {

			/**
			 * Every index is abstracted using a Phalcon\Db\Index instance
			 */
			let indexObjects[name] = new Phalcon\Db\Index(name, indexColumns);
		}

		return indexObjects;
	}

	/**
	 * Lists table references
	 *
	 *<code>
	 * print_r($connection->describeReferences('robots_parts'));
	 *</code>
	 *
	 * @param	string table
	 * @param	string schema
	 * @return	Phalcon\Db\Reference[]
	 */
	public function describeReferences(table, schema=null)
	{
		var dialect, emptyArr, references, reference,
			arrayReference, constraintName, referenceObjects, name;

		let dialect = this->_dialect;

		let emptyArr = [],
			references = [];

		for reference in this->fetchAll(dialect->describeReferences(table, schema), Phalcon\Db::FETCH_NUM) {

			let constraintName = reference[2];
			if !isset references[constraintName] {
				let references[constraintName] = [
					"referencedSchema"  : reference[3],
					"referencedTable"   : reference[4],
					"columns"           : emptyArr,
					"referencedColumns" : emptyArr
				];
			}

			//let references[constraintName]["columns"][] = reference[1],
			//	references[constraintName]["referencedColumns"][] = reference[5];
		}

		let referenceObjects = [];
		for name, arrayReference in references {
			let referenceObjects[name] = new Phalcon\Db\Reference(name, [
				"referencedSchema"	: arrayReference["referencedSchema"],
				"referencedTable"	: arrayReference["referencedTable"],
				"columns"			: arrayReference["columns"],
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
	 *
	 * @param	string tableName
	 * @param	string schemaName
	 * @return	array
	 */
	public function tableOptions(tableName, schemaName=null)
	{
		var dialect, describe, sql;
		let dialect = this->_dialect, sql = dialect->tableOptions(tableName, schemaName);
		if sql {
			let describe = this->fetchAll(sql, Phalcon\DB::FETCH_NUM);
			return describe[0];
		}
		return [];
	}

	/**
	 * Creates a new savepoint
	 *
	 * @param string name
	 * @return boolean
	 */
	public function createSavepoint(name)
	{
		var dialect;

		let dialect = this->_dialect;

		if !dialect->supportsSavePoints() {
			throw new Phalcon\Db\Exception("Savepoints are not supported by this database adapter.");
		}

		return this->{"execute"}(dialect->createSavepoint(name));
	}

	/**
	 * Releases given savepoint
	 *
	 * @param string name
	 * @return boolean
	 */
	public function releaseSavepoint(name)
	{
		var dialect;

		let dialect = this->_dialect;

		if dialect->supportsSavePoints() {
			throw new Phalcon\Db\Exception("Savepoints are not supported by this database adapter");
		}

		if dialect->supportsReleaseSavePoints() {
			return false;
		}

		return this->{"execute"}(dialect->releaseSavepoint(name));
	}

	/**
	 * Rollbacks given savepoint
	 *
	 * @param string name
	 * @return boolean
	 */
	public function rollbackSavepoint(name)
	{
		var dialect;

		let dialect = this->_dialect;

		if dialect->supportsSavePoints() {
			throw new Phalcon\Db\Exception("Savepoints are not supported by this database adapter");
		}

		return this->{"execute"}(dialect->rollbackSavepoint(name));
	}

	/**
	 * Set if nested transactions should use savepoints
	 *
	 * @param boolean nestedTransactionsWithSavepoints
	 * @return Phalcon\Db\AdapterInterface
	 */
	public function setNestedTransactionsWithSavepoints($nestedTransactionsWithSavepoints)
	{
		var dialect;

		if this->_transactionLevel > 0 {
			throw new Phalcon\Db\Exception("Nested transaction with savepoints behavior cannot be changed while a transaction is open");
		}

		let dialect = this->_dialect;
		if !dialect->supportsSavePoints() {
			throw new Phalcon\Db\Exception("Savepoints are not supported by this database adapter");
		}

		let this->_transactionsWithSavepoints = nestedTransactionsWithSavepoints;
		return this;
	}

	/**
	 * Returns if nested transactions should use savepoints
	 *
	 * @return boolean
	 */
	public function isNestedTransactionsWithSavepoints()
	{
		return this->_transactionsWithSavepoints;
	}

	/**
	 * Returns the savepoint name to use for nested transactions
	 *
	 * @return string
	 */
	public function getNestedTransactionSavepointName()
	{
		return "PHALCON_SAVEPOINT_" . this->_transactionLevel;
	}

	/**
	 * Returns the default identity value to be inserted in an identity column
	 *
	 *<code>
	 * //Inserting a new robot with a valid default value for the column 'id'
	 * $success = $connection->insert(
	 *     "robots",
	 *     array($connection->getDefaultIdValue(), "Astro Boy", 1952),
	 *     array("id", "name", "year")
	 * );
	 *</code>
	 *
	 * @return Phalcon\Db\RawValue
	 */
	public function getDefaultIdValue()
	{
		return new Phalcon\Db\RawValue("null");
	}

	/**
	 * Check whether the database system requires a sequence to produce auto-numeric values
	 *
	 * @return boolean
	 */
	public function supportSequences()
	{
		return false;
	}

	/**
	 * Check whether the database system requires an explicit value for identity columns
	 *
	 * @return boolean
	 */
	public function useExplicitIdValue()
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
	 *
	 * @return string
	 */
	public function getSQLStatement()
	{
		return this->_sqlStatement;
	}

	/**
	 * Active SQL statement in the object without replace bound paramters
	 *
	 * @return string
	 */
	public function getRealSQLStatement()
	{
		return this->_sqlStatement;
	}

	/**
	 * Active SQL statement in the object
	 *
	 * @return array
	 */
	public function getSQLVariables()
	{
		return this->_sqlVariables;
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

	/**
	 * Returns type of database system the adapter is used for
	 *
	 * @return string
	 */
	public function getType()
	{
		return this->_type;
	}

	/**
	 * Returns the name of the dialect used
	 *
	 * @return string
	 */
	public function getDialectType()
	{
		return this->_dialectType;
	}

}
