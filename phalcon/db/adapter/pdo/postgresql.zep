
/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */


namespace Phalcon\Db\Adapter\Pdo;

use Phalcon\Db;
use Phalcon\Db\Adapter\Pdo as PdoAdapter;
use Phalcon\Db\Column;
use Phalcon\Db\Exception;
use Phalcon\Db\RawValue;
use Phalcon\Db\Reference;
use Phalcon\Db\ReferenceInterface;

/**
 * Phalcon\Db\Adapter\Pdo\Postgresql
 *
 * Specific functions for the Postgresql database system
 *
 * <code>
 * use Phalcon\Db\Adapter\Pdo\Postgresql;
 *
 * $config = [
 *     "host"     => "localhost",
 *     "dbname"   => "blog",
 *     "port"     => 5432,
 *     "username" => "postgres",
 *     "password" => "secret",
 * ];
 *
 * $connection = new Postgresql($config);
 * </code>
 */
class Postgresql extends PdoAdapter
{

	protected _dialectType = "postgresql";

	protected _type = "pgsql";

	/**
	 * This method is automatically called in Phalcon\Db\Adapter\Pdo constructor.
	 * Call it when you need to restore a database connection.
	 */
	public function connect(array descriptor = null) -> boolean
	{
		var schema, sql, status;

		if empty descriptor {
			let descriptor = (array) this->_descriptor;
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

		let status = parent::connect(descriptor);

		if ! empty schema {
			let sql = "SET search_path TO '" . schema . "'";
			this->execute(sql);
		}

		return status;
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
			} catch \Throwable, exception {

				this->{"rollback"}();
				 throw exception;
			 }
		} else {
			return this->{"execute"}(queries[0] . ";");
		}
		return true;
	}

	/**
	 * Returns an array of Phalcon\Db\Column objects describing a table
	 *
	 * <code>
	 * print_r(
	 *     $connection->describeColumns("posts")
	 * );
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
		for field in this->fetchAll(this->_dialect->describeColumns(table, schema), Db::FETCH_NUM) {

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

			if memstr(columnType, "smallint(1)") {
				/**
				 * Smallint(1) is boolean
				 */
				let definition["type"] = Column::TYPE_BOOLEAN,
					definition["bindType"] = Column::BIND_PARAM_BOOL;
			} elseif memstr(columnType, "bigint") {
				/**
				 * Bigint
				 */
				let definition["type"] = Column::TYPE_BIGINTEGER,
					definition["isNumeric"] = true,
					definition["bindType"] = Column::BIND_PARAM_INT;
			} elseif memstr(columnType, "int") {
				/**
				 * Int
				 */
				let definition["type"] = Column::TYPE_INTEGER,
					definition["isNumeric"] = true,
					definition["size"] = numericSize,
					definition["bindType"] = Column::BIND_PARAM_INT;
			} elseif memstr(columnType, "double precision") {
				/**
				 * Double Precision
				 */
				let definition["type"] = Column::TYPE_DOUBLE,
					definition["isNumeric"] = true,
					definition["size"] = numericSize,
					definition["bindType"] = Column::BIND_PARAM_DECIMAL;
            } elseif memstr(columnType, "real") {
				/**
				 * Real
				 */
				let definition["type"] = Column::TYPE_FLOAT,
					definition["isNumeric"] = true,
					definition["size"] = numericSize,
					definition["bindType"] = Column::BIND_PARAM_DECIMAL;
			} elseif memstr(columnType, "varying") {
				/**
				 * Varchar
				 */
				let definition["type"] = Column::TYPE_VARCHAR,
					definition["size"] = charSize;
			} elseif memstr(columnType, "date") {
				/**
				 * Special type for datetime
				 */
				let definition["type"] = Column::TYPE_DATE,
					definition["size"] = 0;
			} elseif memstr(columnType, "timestamp") {
				/**
				 * Timestamp
				 */
				let definition["type"] = Column::TYPE_TIMESTAMP;
			} elseif memstr(columnType, "numeric") {
				/**
				 * Numeric
				 */
				let definition["type"] = Column::TYPE_DECIMAL,
					definition["isNumeric"] = true,
					definition["size"] = numericSize,
					definition["scale"] = numericScale,
					definition["bindType"] = Column::BIND_PARAM_DECIMAL;
			} elseif memstr(columnType, "char") {
				/**
				 * Chars are chars
				 */
				let definition["type"] = Column::TYPE_CHAR,
					definition["size"] = charSize;
			} elseif memstr(columnType, "text") {
				/**
				 * Text are varchars
				 */
				let definition["type"] = Column::TYPE_TEXT,
					definition["size"] = charSize;
			} elseif memstr(columnType, "float") {
				/**
				 * Float/Smallfloats/Decimals are float
				 */
				let definition["type"] = Column::TYPE_FLOAT,
					definition["isNumeric"] = true,
					definition["size"] = numericSize,
					definition["bindType"] = Column::BIND_PARAM_DECIMAL;
			} elseif memstr(columnType, "bool") {
				/**
				 * Boolean
				 */
				let definition["type"] = Column::TYPE_BOOLEAN,
					definition["size"] = 0,
					definition["bindType"] = Column::BIND_PARAM_BOOL;
			} elseif memstr(columnType, "jsonb") {
				/**
				 * Jsonb
				 */
				let definition["type"] = Column::TYPE_JSONB;
			} elseif memstr(columnType, "json") {
				/**
				 * Json
				 */
				let definition["type"] = Column::TYPE_JSON;
			} elseif memstr(columnType, "uuid") {
				/**
				 * UUID
				 */
				let definition["type"] = Column::TYPE_CHAR,
					definition["size"] = 36;
			} else {
				/**
				 * By default is string
				 */
				let definition["type"] = Column::TYPE_VARCHAR;
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
			 * Check if the column has default values
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
	 * Lists table references
	 *
	 *<code>
	 * print_r(
	 *     $connection->describeReferences("robots_parts")
	 * );
	 *</code>
	 */
	public function describeReferences(string! table, string! schema = null) -> <ReferenceInterface[]>
	{
		var references, reference,
			arrayReference, constraintName, referenceObjects, name,
			referencedSchema, referencedTable, columns, referencedColumns,
			referenceUpdate, referenceDelete;

		let references = [];

		for reference in this->fetchAll(this->_dialect->describeReferences(table, schema), Db::FETCH_NUM) {

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
	 * Returns the default identity value to be inserted in an identity column
	 *
	 *<code>
	 * // Inserting a new robot with a valid default value for the column 'id'
	 * $success = $connection->insert(
	 *     "robots",
	 *     [
	 *         $connection->getDefaultIdValue(),
	 *         "Astro Boy",
	 *         1952,
	 *     ],
	 *     [
	 *         "id",
	 *         "name",
	 *         "year",
	 *     ]
	 * );
	 *</code>
	 */
	public function getDefaultIdValue() -> <RawValue>
	{
		return new RawValue("DEFAULT");
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

			} catch \Throwable, exception {

				this->{"rollback"}();
				 throw exception;
			 }

		} else {
			return !empty sql ? this->{"execute"}(queries[0] . ";") : true;
		}
		return true;
	}

	/**
	 * Check whether the database system requires a sequence to produce auto-numeric values
	 */
	public function supportSequences() -> boolean
	{
		return true;
	}

	/**
	 * Check whether the database system requires an explicit value for identity columns
	 */
	public function useExplicitIdValue() -> boolean
	{
		return true;
	}
}
