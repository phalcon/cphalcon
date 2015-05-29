
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
 |          Rack Lin <racklin@gmail.com>                                  |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Db\Adapter\Pdo;

use Phalcon\Db\Column;
use Phalcon\Db\Exception;
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
 *
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
			oldColumn, sizePattern, matches, matchOne, matchTwo, columnName,pregMatches,columnTypeObject,columnTypeClass;

		let oldColumn = null,
			sizePattern = "#\\(([0-9]+)(?:,\\s*([0-9]+))*\\)#";

		let columns = [];

		/**
		 * We're using FETCH_NUM to fetch the columns
		 */
		for field in this->fetchAll(this->_dialect->describeColumns(table, schema), \Phalcon\Db::FETCH_NUM) {

			/**
			 * By default the bind types is two
			 */
			let definition = ["bindType": Column::BIND_PARAM_STR];

			/**
			 * By checking every column type we convert it to a Phalcon\Db\Column
			 */
			let columnType = field[2];

			preg_match("#[^(]*#",columnType,pregMatches);
			let definition["type"] = Column::getColumnTypeByDialectKeyword("sqlite",pregMatches[0]);
			
			let columnTypeClass = Column::getColumnTypes(definition["type"]);
			let columnTypeObject = new {columnTypeClass}();
			
			if columnTypeObject->isNumeric() {
				let definition["isNumeric"] = true;
			}
            let definition["bindType"] = columnTypeObject->getBindType();


			

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
	 * @param	string table
	 * @param	string schema
	 * @return	Phalcon\Db\IndexInterface[]
	 */
	public function describeIndexes(table, schema = null) -> <IndexInterface[]>
	{
		var indexes, index, keyName, indexObjects, name, indexColumns, columns,
			describe_index;

		let indexes = [];
		for index in this->fetchAll(this->_dialect->describeIndexes(table, schema), \Phalcon\Db::FETCH_NUM) {

			let keyName = index[1];
			if !isset indexes[keyName] {
				let columns = [];
			} else {
				let columns = indexes[keyName];
			}

			for describe_index in this->fetchAll(this->_dialect->describeIndex(keyName), \Phalcon\Db::FETCH_NUM) {
				let columns[] = describe_index[2];
			}

			let indexes[keyName] = columns;
		}

		let indexObjects = [];
		for name, indexColumns in indexes {
			let indexObjects[name] = new Index(name, indexColumns);
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

		for number, reference in this->fetchAll(this->_dialect->describeReferences(table, schema), \Phalcon\Db::FETCH_NUM) {

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
}
