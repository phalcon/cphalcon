
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
use Phalcon\Db\AdapterInterface;
use Phalcon\Db\RawValue;
use Phalcon\Db\Adapter\Pdo as PdoAdapter;
use Phalcon\Db\Exception;

/**
 * Phalcon\Db\Adapter\Pdo\Postgresql
 *
 * Specific functions for the Postgresql database system
 * <code>
 *
 * $config = array(
 *  "host" => "192.168.0.11",
 *  "dbname" => "blog",
 *  "username" => "postgres",
 *  "password" => ""
 * );
 *
 * $connection = new \Phalcon\Db\Adapter\Pdo\Postgresql($config);
 *
 * </code>
 */
class Postgresql extends PdoAdapter implements AdapterInterface
{

	protected _type = "pgsql";

	protected _dialectType = "postgresql";

	/**
	 * This method is automatically called in Phalcon\Db\Adapter\Pdo constructor.
	 * Call it when you need to restore a database connection.
	 *
	 * @param array $descriptor
	 * @return boolean
	 */
	public function connect(descriptor = null)
	{
		var schema, sql;

		if descriptor === null {
			let descriptor = this->_descriptor;
		}

		if fetch schema, descriptor["schema"] {
			unset descriptor["schema"];
		} else {
			let schema = "";
		}

		if isset descriptor["password"] {
			if typeof descriptor["password"] == "string" && strlen(descriptor["password"]) == 0 {
				let descriptor["password"] = null;
			}
		}

		parent::connect(descriptor);

		if ! empty schema {
			let sql = "SET search_path TO '" . schema . "'";
			this->execute(sql);
		}
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
			oldColumn, columnName, charSize, numericSize, numericScale;

		let oldColumn = null, columns = [];

		/**
		 * We're using FETCH_NUM to fetch the columns
		 * 0:name, 1:type, 2:size, 3:numericsize, 4: numericscale, 5: null, 6: key, 7: extra, 8: position, 9 default
		 */
		for field in this->fetchAll(this->_dialect->describeColumns(table, schema), \Phalcon\Db::FETCH_NUM) {

			/**
			 * By default the bind types is two
			 */
			let definition = ["bindType": Column::BIND_PARAM_STR];

			/**
			 * By checking every column type we convert it to a Phalcon\Db\Column
			 */
			let columnType = field[1],
				charSize = field[2],
				numericSize = field[3],
				numericScale = field[4];

			loop {

				/**
				 * Smallint(1) is boolean
				 */
				if memstr(columnType, "smallint(1)") {
					let definition["type"] = Column::TYPE_BOOLEAN,
						definition["bindType"] = Column::BIND_PARAM_BOOL;
					break;
				}

				/**
				 * Int
				 */
				if memstr(columnType, "int") {
					let definition["type"] = Column::TYPE_INTEGER,
						definition["isNumeric"] = true,
						definition["size"] = numericSize,
						definition["bindType"] = Column::BIND_PARAM_INT;
					break;
				}

				/**
				 * Varchar
				 */
				if memstr(columnType, "varying") {
					let definition["type"] = Column::TYPE_VARCHAR,
						definition["size"] = charSize;
					break;
				}

				/**
				 * Special type for datetime
				 */
				if memstr(columnType, "date") {
					let definition["type"] = Column::TYPE_DATE,
						definition["size"] = 0;
					break;
				}

				/**
				 * Numeric
				 */
				if memstr(columnType, "numeric") {
					let definition["type"] = Column::TYPE_DECIMAL,
						definition["isNumeric"] = true,
						definition["size"] = numericSize,
						definition["scale"] = numericScale,
						definition["bindType"] = Column::BIND_PARAM_DECIMAL;
					break;
				}

				/**
				 * Chars are chars
				 */
				if memstr(columnType, "char") {
					let definition["type"] = Column::TYPE_CHAR,
						definition["size"] = charSize;
					break;
				}

				/**
				 * Date
				 */
				if memstr(columnType, "timestamp") {
					let definition["type"] = Column::TYPE_DATETIME,
						definition["size"] = 0;
					break;
				}

				/**
				 * Text are varchars
				 */
				if memstr(columnType, "text") {
					let definition["type"] = Column::TYPE_TEXT,
						definition["size"] = charSize;
					break;
				}

				/**
				 * Float/Smallfloats/Decimals are float
				 */
				if memstr(columnType, "float") {
					let definition["type"] = Column::TYPE_FLOAT,
						definition["isNumeric"] = true,
						definition["size"] = numericSize,
						definition["bindType"] = Column::BIND_PARAM_DECIMAL;
					break;
				}

				/**
				 * Boolean
				 */
				if memstr(columnType, "bool") {
					let definition["type"] = Column::TYPE_BOOLEAN,
						definition["size"] = 0,
						definition["bindType"] = Column::BIND_PARAM_BOOL;
					break;
				}

				/**
				 * UUID
				 */
				if memstr(columnType, "uuid") {
					let definition["type"] = Column::TYPE_CHAR,
						definition["size"] = 36;
					break;
				}

				/**
				 * By default is string
				 */
				let definition["type"] = Column::TYPE_VARCHAR;
				break;
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
			if field[6] == "PRI" {
				let definition["primary"] = true;
			}

			/**
			 * Check if the column allows null values
			 */
			if field[5] == "NO" {
				let definition["notNull"] = true;
			}

			/**
			 * Check if the column is auto increment
			 */
			if field[7] == "auto_increment" {
				let definition["autoIncrement"] = true;
			}

			/**
			 * Check if the column is default values
			 */
			if typeof field[9] != "null" {
				let definition["default"] = preg_replace("/^'|'?::[[:alnum:][:space:]]+$/", "", field[9]);
				if strcasecmp(definition["default"], "null") == 0 {
					let definition["default"] = null;
				}
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
	 * Creates a table
	 */
	public function createTable(string! tableName, string! schemaName, array! definition) -> boolean
	{
		var sql,queries,query,exception,columns;
		
		if !fetch columns, definition["columns"] {
			throw new Exception("The table must contain at least one column");
		}
		
		if !count(columns) {
			throw new Exception("The table must contain at least one column");
		}
		
		let sql = this->_dialect->createTable(tableName, schemaName, definition);
		
		let queries = explode(";",sql);
		
		if count(queries) > 1 {
			try {
				this->{"begin"}();
				for query in queries {
					if empty query {
						continue;
					}
					this->{"query"}(query . ";");
				}
				return this->{"commit"}();
			} catch \Exception, exception {
			 
				this->{"rollback"}();
				 throw exception;
			 }
			
		} else {
			return this->{"execute"}(queries[0] . ";");
		}
		return true;
	}
	
	/**
	 * Modifies a table column based on a definition
	 */
	public function modifyColumn(string! tableName, string! schemaName, <\Phalcon\Db\ColumnInterface> column, <\Phalcon\Db\ColumnInterface> currentColumn = null) -> boolean
	{
		var sql,queries,query,exception;
		
		let sql = this->_dialect->modifyColumn(tableName, schemaName, column, currentColumn);
		let queries = explode(";",sql);
		
		if count(queries) > 1 {
			try {
				this->{"begin"}();
				for query in queries {
					if empty query {
						continue;
					}
					this->{"query"}(query . ";");
				}
				return this->{"commit"}();
			} catch \Exception, exception {
			 
				this->{"rollback"}();
				 throw exception;
			 }
			
		} else {
			return !empty sql ? this->{"execute"}(queries[0] . ";") : true;
		}
		return true;
	}

	/**
	 * Check whether the database system requires an explicit value for identity columns
	 */
	public function useExplicitIdValue() -> boolean
	{
		return true;
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
