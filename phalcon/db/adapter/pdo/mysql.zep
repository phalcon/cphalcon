
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2017 Phalcon Team (https://phalconphp.com)          |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file LICENSE.txt.                             |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Db\Adapter\Pdo;

use Phalcon\Db;
use Phalcon\Db\Column;
use Phalcon\Db\Index;
use Phalcon\Db\Reference;
use Phalcon\Db\IndexInterface;
use Phalcon\Db\Adapter\Pdo as PdoAdapter;
use Phalcon\Application\Exception;
use Phalcon\Db\ReferenceInterface;

/**
 * Phalcon\Db\Adapter\Pdo\Mysql
 *
 * Specific functions for the Mysql database system
 *
 *<code>
 * use Phalcon\Db\Adapter\Pdo\Mysql;
 *
 * $config = [
 *     "host"     => "localhost",
 *     "dbname"   => "blog",
 *     "port"     => 3306,
 *     "username" => "sigma",
 *     "password" => "secret",
 * ];
 *
 * $connection = new Mysql($config);
 *</code>
 */
class Mysql extends PdoAdapter
{

	protected _type = "mysql";

	protected _dialectType = "mysql";

	/**
	 * Returns an array of Phalcon\Db\Column objects describing a table
	 *
	 * <code>
	 * print_r(
	 *     $connection->describeColumns("posts")
	 * );
	 * </code>
	 */
	public function describeColumns(string! table, string schema = null) -> <\Phalcon\Db\ColumnInterface[]>
	{
		var columns, columnType, field, definition,
			oldColumn, sizePattern, matches, matchOne, matchTwo, columnName;

		let oldColumn = null,
			sizePattern = "#\\(([0-9]+)(?:,\\s*([0-9]+))*\\)#";

		let columns = [];

		/**
		 * Get the SQL to describe a table
		 * We're using FETCH_NUM to fetch the columns
		 * Get the describe
		 * Field Indexes: 0:name, 1:type, 2:not null, 3:key, 4:default, 5:extra
		 */
		for field in this->fetchAll(this->_dialect->describeColumns(table, schema), Db::FETCH_NUM) {

			/**
			 * By default the bind types is two
			 */
			let definition = ["bindType": Column::BIND_PARAM_STR];

			/**
			 * By checking every column type we convert it to a Phalcon\Db\Column
			 */
			let columnType = field[1];

			if memstr(columnType, "enum") {
				/**
				 * Enum are treated as char
				 */
				let definition["type"] = Column::TYPE_CHAR;
			} elseif memstr(columnType, "bigint") {
				/**
				 * Smallint/Bigint/Integers/Int are int
				 */
				let definition["type"] = Column::TYPE_BIGINTEGER,
					definition["isNumeric"] = true,
					definition["bindType"] = Column::BIND_PARAM_INT;
			} elseif memstr(columnType, "int") {
				/**
				 * Smallint/Bigint/Integers/Int are int
				 */
				let definition["type"] = Column::TYPE_INTEGER,
					definition["isNumeric"] = true,
					definition["bindType"] = Column::BIND_PARAM_INT;
			} elseif memstr(columnType, "varchar") {
				/**
				 * Varchar are varchars
				 */
				let definition["type"] = Column::TYPE_VARCHAR;
			} elseif memstr(columnType, "datetime") {
				/**
				 * Special type for datetime
				 */
				let definition["type"] = Column::TYPE_DATETIME;
			} elseif memstr(columnType, "char") {
				/**
				 * Chars are chars
				 */
				let definition["type"] = Column::TYPE_CHAR;
			} elseif memstr(columnType, "date") {
				/**
				 * Date are dates
				 */
				let definition["type"] = Column::TYPE_DATE;
			} elseif memstr(columnType, "timestamp") {
				/**
				 * Timestamp are dates
				 */
				let definition["type"] = Column::TYPE_TIMESTAMP;
			} elseif memstr(columnType, "text") {
				/**
				 * Text are varchars
				 */
				let definition["type"] = Column::TYPE_TEXT;
			} elseif memstr(columnType, "decimal") {
				/**
				 * Decimals are floats
				 */
				let definition["type"] = Column::TYPE_DECIMAL,
					definition["isNumeric"] = true,
					definition["bindType"] = Column::BIND_PARAM_DECIMAL;
			} elseif memstr(columnType, "double") {
				/**
				 * Doubles
				 */
				let definition["type"] = Column::TYPE_DOUBLE,
					definition["isNumeric"] = true,
					definition["bindType"] = Column::BIND_PARAM_DECIMAL;
			} elseif memstr(columnType, "float") {
				/**
				 * Float/Smallfloats/Decimals are float
				 */
				let definition["type"] = Column::TYPE_FLOAT,
					definition["isNumeric"] = true,
					definition["bindType"] = Column::BIND_PARAM_DECIMAL;
			} elseif memstr(columnType, "bit") {
				/**
				 * Boolean
				 */
				let definition["type"] = Column::TYPE_BOOLEAN,
					definition["bindType"] = Column::BIND_PARAM_BOOL;
			} elseif memstr(columnType, "tinyblob") {
				/**
				 * Tinyblob
				 */
				let definition["type"] = Column::TYPE_TINYBLOB;
			} elseif memstr(columnType, "mediumblob") {
				/**
				 * Mediumblob
				 */
				let definition["type"] = Column::TYPE_MEDIUMBLOB;
			} elseif memstr(columnType, "longblob") {
				/**
				 * Longblob
				 */
				let definition["type"] = Column::TYPE_LONGBLOB;
			} elseif memstr(columnType, "blob") {
				/**
				 * Blob
				 */
				let definition["type"] = Column::TYPE_BLOB;
			} else {
				/**
				 * By default is string
				 */
				let definition["type"] = Column::TYPE_VARCHAR;
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
			if field[3] == "PRI" {
				let definition["primary"] = true;
			}

			/**
			 * Check if the column allows null values
			 */
			if field[2] == "NO" {
				let definition["notNull"] = true;
			}

			/**
			 * Check if the column is auto increment
			 */
			if field[5] == "auto_increment" {
				let definition["autoIncrement"] = true;
			}

			/**
			 * Check if the column is default values
			 */
			if typeof field[4] != "null" {
				let definition["default"] = field[4];
			}

			/**
			 * Every route is stored as a Phalcon\Db\Column
			 */
			let columnName = field[0],
				columns[] = new Column(columnName, definition),
				oldColumn = columnName;
		}

		return columns;
	}

	/**
	 * Lists table indexes
	 *
	 * <code>
	 * print_r(
	 *     $connection->describeIndexes("robots_parts")
	 * );
	 * </code>
	 *
	 * @param  string table
	 * @param  string schema
	 * @return \Phalcon\Db\IndexInterface[]
	 */
	public function describeIndexes(string! table, string schema = null) -> <IndexInterface[]>
	{
		var indexes, index, keyName, indexType, indexObjects, columns, name;

		let indexes = [];
		for index in this->fetchAll(this->_dialect->describeIndexes(table, schema), Db::FETCH_ASSOC) {
			let keyName = index["Key_name"];
			let indexType = index["Index_type"];

			if !isset indexes[keyName] {
				let indexes[keyName] = [];
			}

			if !isset indexes[keyName]["columns"] {
				let columns = [];
			} else {
				let columns = indexes[keyName]["columns"];
			}

			let columns[] = index["Column_name"];
			let indexes[keyName]["columns"] = columns;

			if keyName == "PRIMARY" {
				let indexes[keyName]["type"] = "PRIMARY";
			} elseif indexType == "FULLTEXT" {
				let indexes[keyName]["type"] = "FULLTEXT";
			} elseif index["Non_unique"] == 0 {
				let indexes[keyName]["type"] = "UNIQUE";
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
	 *<code>
	 * print_r(
	 *     $connection->describeReferences("robots_parts")
	 * );
	 *</code>
	 */
	public function describeReferences(string! table, string schema = null) -> <ReferenceInterface[]>
	{
		var references, reference,
			arrayReference, constraintName, referenceObjects, name,
			referencedSchema, referencedTable, columns, referencedColumns,
			referenceUpdate, referenceDelete;

		let references = [];

		for reference in this->fetchAll(this->_dialect->describeReferences(table, schema),Db::FETCH_NUM) {

			let constraintName = reference[2];
			if !isset references[constraintName] {
				let referencedSchema  = reference[3];
				let referencedTable   = reference[4];
				let referenceUpdate   = reference[6];
				let referenceDelete   = reference[7];
				let columns           = [];
				let referencedColumns = [];

			} else {
				let referencedSchema  = references[constraintName]["referencedSchema"];
				let referencedTable   = references[constraintName]["referencedTable"];
				let columns           = references[constraintName]["columns"];
				let referencedColumns = references[constraintName]["referencedColumns"];
				let referenceUpdate   = references[constraintName]["onUpdate"];
				let referenceDelete   = references[constraintName]["onDelete"];
			}

			let columns[] = reference[1],
				referencedColumns[] = reference[5];

			let references[constraintName] = [
				"referencedSchema"  : referencedSchema,
				"referencedTable"   : referencedTable,
				"columns"           : columns,
				"referencedColumns" : referencedColumns,
				"onUpdate"          : referenceUpdate,
				"onDelete"          : referenceDelete
			];
		}

		let referenceObjects = [];
		for name, arrayReference in references {
			let referenceObjects[name] = new Reference(name, [
				"referencedSchema"  : arrayReference["referencedSchema"],
				"referencedTable"   : arrayReference["referencedTable"],
				"columns"           : arrayReference["columns"],
				"referencedColumns" : arrayReference["referencedColumns"],
				"onUpdate"          : arrayReference["onUpdate"],
				"onDelete"          : arrayReference["onDelete"]
			]);
		}

		return referenceObjects;
	}

	/**
	 * Adds a foreign key to a table
	 */
	public function addForeignKey(string! tableName, string! schemaName, <ReferenceInterface> reference) -> boolean
	{
		var foreignKeyCheck;

		let foreignKeyCheck = this->{"prepare"}(this->_dialect->getForeignKeyChecks());
		if !foreignKeyCheck->execute() {
			throw new Exception("DATABASE PARAMETER 'FOREIGN_KEY_CHECKS' HAS TO BE 1");
		}

		return this->{"execute"}(this->_dialect->addForeignKey(tableName, schemaName, reference));
	}
}
