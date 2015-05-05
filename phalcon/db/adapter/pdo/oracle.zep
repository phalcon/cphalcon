
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
 |          Marcio Paiva <mpaivabarbosa@gmail.com>                        |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Db\Adapter\Pdo;

use Phalcon\Db\Column;
use Phalcon\Db\RawValue;
use Phalcon\Db\AdapterInterface;
use Phalcon\Db\Adapter\Pdo as PdoAdapter;

/**
 * Phalcon\Db\Adapter\Pdo\Oracle
 *
 * Specific functions for the Oracle database system
 * <code>
 *
 * $config = array(
 *  "dbname" => "//localhost/dbname",
 *  "username" => "oracle",
 *  "password" => "oracle"
 * );
 *
 * $connection = new \Phalcon\Db\Adapter\Pdo\Oracle($config);
 *
 * </code>
 */
class Oracle extends PdoAdapter implements AdapterInterface
{

	protected _type = "oci";

	protected _dialectType = "oracle";

	/**
	 * This method is automatically called in Phalcon\Db\Adapter\Pdo constructor.
	 * Call it when you need to restore a database connection.
	 *
	 * @param array descriptor
	 * @return boolean
	 */
	public function connect(descriptor = null) -> boolean
	{
		var startup, value, status;

		if !descriptor {
			let descriptor = this->_descriptor;
		}

		let status = parent::connect(descriptor);

		/**
		 * Database session settings initiated with each HTTP request. Oracle behaviour depends on particular NLS* parameter. Check if the developer has defined custom startup or create one from scratch
		 */
		if fetch startup, descriptor["startup"] {
			if typeof startup == "array" {
				for value in startup {
					this->execute(value);
				}
			}
		}

		return status;
	}

	/**
	 * Returns an array of Phalcon\Db\Column objects describing a table
	 *
	 * <code>print_r($connection->describeColumns("posts")); ?></code>
	 */
	public function describeColumns(string! table, string schema = null) -> <Column[]>
	{
		var columns, oldColumn, field, definition, columnSize,
			columnPrecision, columnScale, columnType, columnName;

		let columns = [];

		/**
		 *  0:column_name, 1:data_type, 2:data_length, 3:data_precision, 4:data_scale, 5:nullable, 6:constraint_type, 7:default, 8:position;
		 */
		let oldColumn = null;
		for field in this->fetchAll(this->_dialect->describeColumns(table, schema), \Phalcon\Db::FETCH_NUM) {

			let definition = ["bindType" : 2];

			let columnSize = field[2],
				columnPrecision = field[3],
				columnScale = field[4],
				columnType = field[1];

			loop {

				/**
				 * Check the column type to get the correct Phalcon type
				 */
				if memstr(columnType, "NUMBER") {
					let definition["type"]      = Column::TYPE_DECIMAL,
						definition["isNumeric"] = true,
						definition["size"]      = columnPrecision,
						definition["scale"]     = columnScale,
						definition["bindType"]  = 32;
					break;
				}

				if memstr(columnType, "INTEGER") {
					let definition["type"]       = Column::TYPE_INTEGER,
						definition["isNumeric"]  = true,
						definition["size"]       = columnPrecision,
						definition["bindType"]   = 1;
					break;
				}

				if memstr(columnType, "VARCHAR2") {
					let definition["type"] = Column::TYPE_VARCHAR,
						definition["size"] = columnSize;
						break;
				}

				if memstr(columnType, "FLOAT") {
					let definition["type"]      = Column::TYPE_FLOAT,
						definition["isNumeric"] = true,
						definition["size"]      = columnSize,
						definition["scale"]     = columnScale,
						definition["bindType"]  = 32;
					break;
				}

				if memstr(columnType, "TIMESTAMP") {
					let definition["type"] = Column::TYPE_INTEGER;
					break;
				}

				if memstr(columnType, "RAW") {
					let definition["type"] = Column::TYPE_TEXT;
					break;
				}

				if memstr(columnType, "BLOB") {
					let definition["type"] = Column::TYPE_TEXT;
					break;
				}

				if memstr(columnType, "CLOB") {
					let definition["type"] = Column::TYPE_TEXT;
					break;
				}

				if memstr(columnType, "CHAR") {
					let definition["type"] = Column::TYPE_CHAR,
						definition["size"] = columnSize;
					break;
				}

				let definition["type"] = Column::TYPE_TEXT;
				break;
			}

			if oldColumn === null {
				let definition["first"] = true;
			} else {
				let definition["after"] = oldColumn;
			}

			/**
			 * Check if the field is primary key
			 */
			if field[6] == "P" {
				let definition["primary"] = true;
			}

			/**
			 * Check if the column allows null values
			 */
			if field[5] == "N" {
				let definition["notNull"] = true;
			}

			let columnName = field[0];

			/**
			 * Create a Phalcon\Db\Column to abstract the column
			 */
			let columns[] = new Column(columnName, definition),
				oldColumn = columnName;
		}

		return columns;
	}

	/**
	 * Returns the insert id for the auto_increment/serial column inserted in the lastest executed SQL statement
	 *
	 *<code>
	 * //Inserting a new robot
	 * $success = $connection->insert(
	 *     "robots",
	 *     array("Astro Boy", 1952),
	 *     array("name", "year")
	 * );
	 *
	 * //Getting the generated id
	 * $id = $connection->lastInsertId();
	 *</code>
	 */
	public function lastInsertId(string sequenceName = null) -> int
	{
		return this->fetchAll("SELECT " . sequenceName . ".CURRVAL FROM dual", \Phalcon\Db::FETCH_NUM)[0];
	}

	/**
	 * Check whether the database system requires an explicit value for identity columns
	 */
	public function useExplicitIdValue() -> boolean
	{
		return false;
	}

	/**
	 * Return the default identity value to insert in an identity column
	 */
	public function getDefaultIdValue() -> <RawValue>
	{
		return new RawValue("default");
	}

	/**
	 * Check whether the database system requires a sequence to produce auto-numeric values
	 */
	public function supportSequences() -> boolean
	{
		return true;
	}
}
