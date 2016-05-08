
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2016 Phalcon Team (https://phalconphp.com)       |
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
 |          Rack Lin <racklin@gmail.com>                                  |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Db\Adapter\Pdo;

use Phalcon\Db;
use Phalcon\Db\Column;
use Phalcon\Db\Exception;
use Phalcon\Db\RawValue;
use Phalcon\Db\Reference;
use Phalcon\Db\ReferenceInterface;
use Phalcon\Db\Index;
use Phalcon\Db\IndexInterface;
use Phalcon\Db\AdapterInterface;
use Phalcon\Db\Adapter\Pdo as PdoAdapter;

/**
 * Phalcon\Db\Adapter\Pdo\Sqlite
 *
 * Specific functions for the Sqlite database system
 * <code>
 *
 * $config = array(
 *  "dbname" => "/tmp/test.sqlite"
 * );
 *
 * $connection = new \Phalcon\Db\Adapter\Pdo\Sqlite($config);
 * </code>
 */
class Sqlite extends PdoAdapter implements AdapterInterface
{

	protected _type = "sqlite";

	protected _dialectType = "sqlite";

	/**
	 * This method is automatically called in Phalcon\Db\Adapter\Pdo constructor.
	 * Call it when you need to restore a database connection.
	 *
	 * @param array $descriptor
	 * @return boolean
	 */
	public function connect(descriptor = null)
	{
		var dbname;

		if descriptor === null {
			let descriptor = this->_descriptor;
		}

		if !fetch dbname, descriptor["dbname"] {
			throw new Exception("dbname must be specified");
		}

		let descriptor["dsn"] = dbname;

		parent::connect(descriptor);
	}

	/**
	 * Returns an array of Phalcon\Db\Column objects describing a table
	 *
	 * <code>
	 * print_r($connection->describeColumns("posts"));
	 * </code>
	 */
	public function describeColumns(string table, string schema = null) -> <Column[]>
	{
		var columns, columnType, field, definition,
			oldColumn, sizePattern, matches, matchOne, matchTwo, columnName;

		let oldColumn = null,
			sizePattern = "#\\(([0-9]+)(?:,\\s*([0-9]+))*\\)#";

		let columns = [];

		/**
		 * We're using FETCH_NUM to fetch the columns
		 */
		for field in this->fetchAll(this->_dialect->describeColumns(table, schema), Db::FETCH_NUM) {

			/**
			 * By default the bind types is two
			 */
			let definition = ["bindType": Column::BIND_PARAM_STR];

			/**
			 * By checking every column type we convert it to a Phalcon\Db\Column
			 */
			let columnType = field[2];

			loop {

				/**
				 * Tinyint(1) is boolean
				 */
				if memstr(columnType, "tinyint(1)") {
					let definition["type"] = Column::TYPE_BOOLEAN,
						definition["bindType"] = Column::BIND_PARAM_BOOL,
						columnType = "boolean"; // Change column type to skip size check
					break;
				}

				/**
				 * Bigint are int
				 */
				if memstr(columnType, "bigint") {
					let definition["type"] = Column::TYPE_BIGINTEGER,
						definition["isNumeric"] = true,
						definition["bindType"] = Column::BIND_PARAM_INT;
					break;
				}

				/**
				 * Smallint/Integers/Int are int
				 */
				if memstr(columnType, "int") || memstr(columnType, "INT") {

					let definition["type"] = Column::TYPE_INTEGER,
						definition["isNumeric"] = true,
						definition["bindType"] = Column::BIND_PARAM_INT;

					if field[5] {
						let definition["autoIncrement"] = true;
					}
					break;
				}

				/**
				 * Varchar are varchars
				 */
				if memstr(columnType, "varchar") {
					let definition["type"] = Column::TYPE_VARCHAR;
					break;
				}

				/**
				 * Date/Datetime are varchars
				 */
				if memstr(columnType, "date") {
					let definition["type"] = Column::TYPE_DATE;
					break;
				}

				/**
				 * Timestamp as date
				 */
				if memstr(columnType, "timestamp") {
					let definition["type"] = Column::TYPE_TIMESTAMP;
					break;
				}

				/**
				 * Decimals are floats
				 */
				if memstr(columnType, "decimal") {
					let definition["type"] = Column::TYPE_DECIMAL,
						definition["isNumeric"] = true,
						definition["bindType"] = Column::BIND_PARAM_DECIMAL;
					break;
				}

				/**
				 * Chars are chars
				 */
				if memstr(columnType, "char") {
					let definition["type"] = Column::TYPE_CHAR;
					break;
				}

				/**
				 * Special type for datetime
				 */
				if memstr(columnType, "datetime") {
					let definition["type"] = Column::TYPE_DATETIME;
					break;
				}

				/**
				 * Text are varchars
				 */
				if memstr(columnType, "text") {
					let definition["type"] = Column::TYPE_TEXT;
					break;
				}

				/**
				 * Float/Smallfloats/Decimals are float
				 */
				if memstr(columnType, "float") {
					let definition["type"] = Column::TYPE_FLOAT,
						definition["isNumeric"] = true,
						definition["bindType"] = Column::TYPE_DECIMAL;
					break;
				}

				/**
				 * Enum are treated as char
				 */
				if memstr(columnType, "enum") {
					let definition["type"] = Column::TYPE_CHAR;
					break;
				}

				/**
				 * By default is string
				 */
				let definition["type"] = Column::TYPE_VARCHAR;
				break;
			}

			/**
			 * If the column type has a parentheses we try to get the column size from it
			 */
			if memstr(columnType, "(") {
				let matches = null;
				if preg_match(sizePattern, columnType, matches) {
					if fetch matchOne, matches[1] {
						let definition["size"] = (int) matchOne;
					}
					if fetch matchTwo, matches[2] {
						let definition["scale"] = (int) matchTwo;
					}
				}
			}

			/**
			 * Check if the column is unsigned, only MySQL support this
			 */
			if memstr(columnType, "unsigned") {
				let definition["unsigned"] = true;
			}

			/**
			 * Positions
			 */
			if oldColumn == null {
				let definition["first"] = true;
			} else {
				let definition["after"] = oldColumn;
			}

			/**
			 * Check if the field is primary key
			 */
			if field[5] {
				let definition["primary"] = true;
			}

			/**
			 * Check if the column allows null values
			 */
			if field[3] {
				let definition["notNull"] = true;
			}

			/**
			 * Check if the column is default values
			 * When field is empty default value is null
			 */
			if strcasecmp(field[4], "null") != 0 && field[4] != "" {
				let definition["default"] = preg_replace("/^'|'$/", "", field[4]);
			}

			/**
			 * Every route is stored as a Phalcon\Db\Column
			 */
			let columnName = field[1],
				columns[] = new Column(columnName, definition),
				oldColumn = columnName;
		}

		return columns;
	}

	/**
	 * Lists table indexes
	 *
	 * <code>
	 *   print_r($connection->describeIndexes('robots_parts'));
	 * </code>
	 *
	 * @param  string table
	 * @param  string schema
	 * @return \Phalcon\Db\IndexInterface[]
	 */
	public function describeIndexes(table, schema = null) -> <IndexInterface[]>
	{
		var indexes, index, keyName, indexObjects, name, columns, describeIndex, indexSql;

		let indexes = [];
		for index in this->fetchAll(this->_dialect->describeIndexes(table, schema), Db::FETCH_ASSOC) {
			let keyName = index["name"];

			if !isset indexes[keyName] {
				let indexes[keyName] = [];
			}

			if !isset indexes[keyName]["columns"] {
				let columns = [];
			} else {
				let columns = indexes[keyName]["columns"];
			}

			for describeIndex in this->fetchAll(this->_dialect->describeIndex(keyName), Db::FETCH_ASSOC) {
				let columns[] = describeIndex["name"];
			}

			let indexes[keyName]["columns"] = columns;
			let indexSql = this->fetchColumn(this->_dialect->listIndexesSql(table, schema, keyName));

			if index["unique"] {
				if preg_match("# UNIQUE #i", indexSql) {
					let indexes[keyName]["type"] = "UNIQUE";
				} else {
					let indexes[keyName]["type"] = "PRIMARY";
				}
			} else {
				let indexes[keyName]["type"] = null;
			}
		}

		let indexObjects = [];
		for name, index in indexes {
			let indexObjects[name] = new Index(name, index["columns"], index["type"]);
		}

		return indexObjects;
	}

	/**
	 * Lists table references
	 *
	 * @param	string table
	 * @param	string schema
	 * @return	Phalcon\Db\ReferenceInterface[]
	 */
	public function describeReferences(table, schema = null) -> <ReferenceInterface[]>
	{
		var references, reference,
			arrayReference, constraintName, referenceObjects, name,
			referencedSchema, referencedTable, columns, referencedColumns,
			number;

		let references = [];

		for number, reference in this->fetchAll(this->_dialect->describeReferences(table, schema), Db::FETCH_NUM) {

			let constraintName = "foreign_key_" . number;
			if !isset references[constraintName] {
				let referencedSchema = null;
				let referencedTable = reference[2];
				let columns = [];
				let referencedColumns = [];
			} else {
				let referencedSchema = references[constraintName]["referencedSchema"];
				let referencedTable = references[constraintName]["referencedTable"];
				let columns = references[constraintName]["columns"];
				let referencedColumns = references[constraintName]["referencedColumns"];
			}

			let columns[] = reference[3],
				referencedColumns[] = reference[4];

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
				"referencedSchema"	: arrayReference["referencedSchema"],
				"referencedTable"	: arrayReference["referencedTable"],
				"columns"			: arrayReference["columns"],
				"referencedColumns" : arrayReference["referencedColumns"]
			]);
		}

		return referenceObjects;
	}

	/**
	 * Check whether the database system requires an explicit value for identity columns
	 */
	public function useExplicitIdValue() -> boolean
	{
		return true;
	}

	/**
	 * Returns the default value to make the RBDM use the default value declared in the table definition
	 *
	 *<code>
	 * //Inserting a new robot with a valid default value for the column 'year'
	 * $success = $connection->insert(
	 *	 "robots",
	 *	 array("Astro Boy", $connection->getDefaultValue()),
	 *	 array("name", "year")
	 * );
	 *</code>
	 */
	public function getDefaultValue() -> <RawValue>
	{
		return new RawValue("NULL");
	}
}
