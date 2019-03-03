
/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Db\Adapter;

use Phalcon\Db\Adapter;
use Phalcon\Db\Column;
use Phalcon\Db\Exception;
use Phalcon\Db\Result\Pdo as ResultPdo;
use Phalcon\Db\ResultInterface;
use Phalcon\Events\ManagerInterface;

/**
 * Phalcon\Db\Adapter\Pdo
 *
 * Phalcon\Db\Adapter\Pdo is the Phalcon\Db that internally uses PDO to connect to a database
 *
 * <code>
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
abstract class Pdo extends Adapter
{

	/**
	 * Last affected rows
	 */
	protected _affectedRows;

	/**
	 * PDO Handler
	 *
	 * @var \Pdo
	 */
	protected _pdo;

	/**
	 * Returns PDO adapter DSN defaults as a key-value map.
	 */
	abstract protected function getDsnDefaults() -> array;

	/**
	 * Constructor for Phalcon\Db\Adapter\Pdo
	 */
	public function __construct(array! descriptor)
	{
		this->connect(descriptor);
		parent::__construct(descriptor);
	}

	/**
	 * Returns the number of affected rows by the latest INSERT/UPDATE/DELETE executed in the database system
	 *
	 *<code>
	 * $connection->execute(
	 *     "DELETE FROM robots"
	 * );
	 *
	 * echo $connection->affectedRows(), " were deleted";
	 *</code>
	 */
	public function affectedRows() -> int
	{
		return this->_affectedRows;
	}

	/**
	 * Starts a transaction in the connection
	 */
	public function begin(bool nesting = true) -> bool
	{
		var pdo, transactionLevel, eventsManager, savepointName;

		let pdo = this->_pdo;
		if typeof pdo != "object" {
			return false;
		}

		/**
		 * Increase the transaction nesting level
		 */
		let this->_transactionLevel++;

		/**
		 * Check the transaction nesting level
		 */
		let transactionLevel = (int) this->_transactionLevel;

		if transactionLevel == 1 {

			/**
			 * Notify the events manager about the started transaction
			 */
			let eventsManager = <ManagerInterface> this->_eventsManager;
			if typeof eventsManager == "object" {
				eventsManager->fire("db:beginTransaction", this);
			}

			return pdo->beginTransaction();
		} else {

			/**
			 * Check if the current database system supports nested transactions
			 */
			if transactionLevel && nesting && this->isNestedTransactionsWithSavepoints() {

				let eventsManager = <ManagerInterface> this->_eventsManager,
					savepointName = this->getNestedTransactionSavepointName();

				/**
				 * Notify the events manager about the created savepoint
				 */
				if typeof eventsManager == "object" {
					eventsManager->fire("db:createSavepoint", this, savepointName);
				}

				return this->createSavepoint(savepointName);
			}

		}

		return false;
	}

	/**
	 * Commits the active transaction in the connection
	 */
	public function commit(bool nesting = true) -> bool
	{
		var pdo, transactionLevel, eventsManager, savepointName;

		let pdo = this->_pdo;
		if typeof pdo != "object" {
			return false;
		}

		/**
		 * Check the transaction nesting level
		 */
		let transactionLevel = (int) this->_transactionLevel;
		if !transactionLevel {
			throw new Exception("There is no active transaction");
		}

		if transactionLevel == 1 {

			/**
			 * Notify the events manager about the committed transaction
			 */
			let eventsManager = <ManagerInterface> this->_eventsManager;
			if typeof eventsManager == "object" {
				eventsManager->fire("db:commitTransaction", this);
			}

			/**
			 * Reduce the transaction nesting level
			 */
			let this->_transactionLevel--;

			return pdo->commit();
		} else {

			/**
			 * Check if the current database system supports nested transactions
			 */
			if transactionLevel && nesting && this->isNestedTransactionsWithSavepoints() {

				/**
				 * Notify the events manager about the committed savepoint
				 */
				let eventsManager = <ManagerInterface> this->_eventsManager,
					savepointName = this->getNestedTransactionSavepointName();
				if typeof eventsManager == "object" {
					eventsManager->fire("db:releaseSavepoint", this, savepointName);
				}

				/**
				 * Reduce the transaction nesting level
				 */
				let this->_transactionLevel--;

				return this->releaseSavepoint(savepointName);
			}

		}

		/**
		 * Reduce the transaction nesting level
		 */
		if transactionLevel > 0 {
			let this->_transactionLevel--;
		}

		return false;
	}

	/**
	 * Closes the active connection returning success. Phalcon automatically closes and destroys
	 * active connections when the request ends
	 */
	public function close() -> bool
	{
		var pdo;
		let pdo = this->_pdo;
		if typeof pdo == "object" {
			let this->_pdo = null;
		}
		return true;
	}

	/**
	 * This method is automatically called in \Phalcon\Db\Adapter\Pdo constructor.
	 *
	 * Call it when you need to restore a database connection.
	 *
	 *<code>
	 * use Phalcon\Db\Adapter\Pdo\Mysql;
	 *
	 * // Make a connection
	 * $connection = new Mysql(
	 *     [
	 *         "host"     => "localhost",
	 *         "username" => "sigma",
	 *         "password" => "secret",
	 *         "dbname"   => "blog",
	 *         "port"     => 3306,
	 *     ]
	 * );
	 *
	 * // Reconnect
	 * $connection->connect();
	 * </code>
	 */
	public function connect(array descriptor = null) -> bool
	{
		var username, password, dsnParts, dsnAttributes, dsnAttributesCustomRaw, dsnAttributesMap,
			options, key, value;

		if empty descriptor {
			let descriptor = (array) this->_descriptor;
		}

		// Check for a username or use null as default
		if fetch username, descriptor["username"] {
			unset descriptor["username"];
		}

		// Check for a password or use null as default
		if fetch password, descriptor["password"] {
			unset descriptor["password"];
		}

		// Remove the dialect class so that it does become a dsn setting.
		if isset descriptor["dialectClass"] {
			unset descriptor["dialectClass"];
		}

		// Check if the developer has defined custom options or create one from scratch
		if fetch options, descriptor["options"] {
			unset descriptor["options"];
		} else {
			let options = [];
		}

		// Set PDO to throw exceptions when an error is encountered.
		let options[\Pdo::ATTR_ERRMODE] = \Pdo::ERRMODE_EXCEPTION;

		let dsnParts = [];

		// Check if the user has defined a custom dsn string. It should be in
		// the form of key=value with semicolons delineating sections.
		if fetch dsnAttributesCustomRaw, descriptor["dsn"] {
			let dsnParts[] = dsnAttributesCustomRaw;
			unset descriptor["dsn"];
		}

		// Start with the dsn defaults and then write over it with the descriptor.
		// At this point the descriptor should be a valid DSN key-value map due to
		// all other values having been removed.
		let dsnAttributesMap = array_merge(this->getDsnDefaults(), descriptor);

		for key, value in dsnAttributesMap {
			let dsnParts[] = key . "=" . value;
		}

		// Create the dsn attributes string.
		let dsnAttributes = join(";", dsnParts);

		// Create the connection using PDO
		let this->_pdo = new \Pdo(this->_type . ":" . dsnAttributes, username, password, options);

		return true;
	}

	/**
	 * Converts bound parameters such as :name: or ?1 into PDO bind params ?
	 *
	 *<code>
	 * print_r(
	 *     $connection->convertBoundParams(
	 *         "SELECT * FROM robots WHERE name = :name:",
	 *         [
	 *             "Bender",
	 *         ]
	 *     )
	 * );
	 *</code>
	 */
	public function convertBoundParams(string! sql, array params = []) -> array
	{
		var boundSql, placeHolders, bindPattern, matches,
			setOrder, placeMatch, value;

		let placeHolders = [],
			bindPattern = "/\\?([0-9]+)|:([a-zA-Z0-9_]+):/",
			matches = null, setOrder = 2;

		if preg_match_all(bindPattern, sql, matches, setOrder) {
			for placeMatch in matches {

				if !fetch value, params[placeMatch[1]] {
					if isset placeMatch[2] {
						if !fetch value, params[placeMatch[2]] {
							throw new Exception("Matched parameter wasn't found in parameters list");
						}
					} else {
						throw new Exception("Matched parameter wasn't found in parameters list");
					}
				}

				let placeHolders[] = value;
			}

			let boundSql = preg_replace(bindPattern, "?", sql);
		} else {
			let boundSql = sql;
		}

		return [
			"sql"    : boundSql,
			"params" : placeHolders
		];
	}

	/**
	 * Escapes a value to avoid SQL injections according to the active charset in the connection
	 *
	 *<code>
	 * $escapedStr = $connection->escapeString("some dangerous value");
	 *</code>
	 */
	public function escapeString(string str) -> string
	{
		return this->_pdo->quote(str);
	}

	/**
	 * Sends SQL statements to the database server returning the success state.
	 * Use this method only when the SQL statement sent to the server doesn't return any rows
	 *
	 *<code>
	 * // Inserting data
	 * $success = $connection->execute(
	 *     "INSERT INTO robots VALUES (1, 'Astro Boy')"
	 * );
	 *
	 * $success = $connection->execute(
	 *     "INSERT INTO robots VALUES (?, ?)",
	 *     [
	 *         1,
	 *         "Astro Boy",
	 *     ]
	 * );
	 *</code>
	 */
	public function execute(string! sqlStatement, var bindParams = null, var bindTypes = null) -> bool
	{
		var eventsManager, affectedRows, pdo, newStatement, statement;

		/**
		 * Execute the beforeQuery event if an EventsManager is available
		 */
		let eventsManager = <ManagerInterface> this->_eventsManager;
		if typeof eventsManager == "object" {
			let this->_sqlStatement = sqlStatement,
				this->_sqlVariables = bindParams,
				this->_sqlBindTypes = bindTypes;
			if eventsManager->fire("db:beforeQuery", this) === false {
				return false;
			}
		}

		/**
		 * Initialize affectedRows to 0
		 */
		let affectedRows = 0;

		let pdo = <\Pdo> this->_pdo;
		if typeof bindParams == "array" {
			let statement = pdo->prepare(sqlStatement);
			if typeof statement == "object" {
				let newStatement = this->executePrepared(statement, bindParams, bindTypes),
					affectedRows = newStatement->rowCount();
			}
		} else {
			let affectedRows = pdo->exec(sqlStatement);
		}

		/**
		 * Execute the afterQuery event if an EventsManager is available
		 */
		if typeof affectedRows == "integer" {
			let this->_affectedRows = affectedRows;
			if typeof eventsManager == "object" {
				eventsManager->fire("db:afterQuery", this);
			}
		}

		return true;
	}

	/**
	 * Executes a prepared statement binding. This function uses integer indexes starting from zero
	 *
	 *<code>
	 * use Phalcon\Db\Column;
	 *
	 * $statement = $db->prepare(
	 *     "SELECT * FROM robots WHERE name = :name"
	 * );
	 *
	 * $result = $connection->executePrepared(
	 *     $statement,
	 *     [
	 *         "name" => "Voltron",
	 *     ],
	 *     [
	 *         "name" => Column::BIND_PARAM_INT,
	 *     ]
	 * );
	 *</code>
	 *
	 * @param array dataTypes
	 */
	public function executePrepared(<\PDOStatement> statement, array! placeholders, dataTypes) -> <\PDOStatement>
	{
		var wildcard, value, type, castValue,
			parameter, position, itemValue;

		for wildcard, value in placeholders {

			if typeof wildcard == "integer" {
				let parameter = wildcard + 1;
			} elseif typeof wildcard == "string" {
				let parameter = wildcard;
			} else {
				throw new Exception("Invalid bind parameter (1)");
			}

			if typeof dataTypes == "array" && fetch type, dataTypes[wildcard] {

				/**
				 * The bind type needs to be string because the precision
				 * is lost if it is casted as a double
				 */
				if type == Column::BIND_PARAM_DECIMAL {
					let castValue = (string) value,
						type = Column::BIND_SKIP;
				} else {
					if globals_get("db.force_casting") {
						if typeof value != "array" {
							switch type {

								case Column::BIND_PARAM_INT:
									let castValue = intval(value, 10);
									break;

								case Column::BIND_PARAM_STR:
									let castValue = (string) value;
									break;

								case Column::BIND_PARAM_NULL:
									let castValue = null;
									break;

								case Column::BIND_PARAM_BOOL:
									let castValue = (bool) value;
									break;

								default:
									let castValue = value;
									break;
							}
						} else {
							let castValue = value;
						}
					} else {
						let castValue = value;
					}
				}

				/**
				 * 1024 is ignore the bind type
				 */
				if typeof castValue != "array" {
					if type == Column::BIND_SKIP {
						statement->bindValue(parameter, castValue);
					} else {
						statement->bindValue(parameter, castValue, type);
					}
				} else {
					for position, itemValue in castValue {
						if type == Column::BIND_SKIP {
							statement->bindValue(parameter . position, itemValue);
						} else {
							statement->bindValue(parameter . position, itemValue, type);
						}
					}
				}
			} else {
				if typeof value != "array" {
					statement->bindValue(parameter, value);
				} else {
					for position, itemValue in value {
						statement->bindValue(parameter . position, itemValue);
					}
				}
			}
		}

		statement->execute();
		return statement;
	}

	/**
	 * Return the error info, if any
	 *
	 * @return array
	 */
	public function getErrorInfo()
	{
		return this->_pdo->errorInfo();
	}

	/**
	 * Return internal PDO handler
	 */
	public function getInternalHandler() -> <\Pdo>
	{
		return this->_pdo;
	}

	/**
	 * Returns the current transaction nesting level
	 */
	public function getTransactionLevel() -> int
	{
		return this->_transactionLevel;
	}

	/**
	 * Checks whether the connection is under a transaction
	 *
	 *<code>
	 * $connection->begin();
	 *
	 * // true
	 * var_dump(
	 *     $connection->isUnderTransaction()
	 * );
	 *</code>
	 */
	public function isUnderTransaction() -> bool
	{
		var pdo;
		let pdo = this->_pdo;
		if typeof pdo == "object" {
			return pdo->inTransaction();
		}
		return false;
	}

	/**
	 * Returns the insert id for the auto_increment/serial column inserted in the latest executed SQL statement
	 *
	 *<code>
	 * // Inserting a new robot
	 * $success = $connection->insert(
	 *     "robots",
	 *     [
	 *         "Astro Boy",
	 *         1952,
	 *     ],
	 *     [
	 *         "name",
	 *         "year",
	 *     ]
	 * );
	 *
	 * // Getting the generated id
	 * $id = $connection->lastInsertId();
	 *</code>
	 *
	 * @param string sequenceName
	 */
	public function lastInsertId(sequenceName = null) -> int | bool
	{
		var pdo;
		let pdo = this->_pdo;
		if typeof pdo != "object" {
			return false;
		}
		return pdo->lastInsertId(sequenceName);
	}

	/**
	 * Returns a PDO prepared statement to be executed with 'executePrepared'
	 *
	 *<code>
	 * use Phalcon\Db\Column;
	 *
	 * $statement = $db->prepare(
	 *     "SELECT * FROM robots WHERE name = :name"
	 * );
	 *
	 * $result = $connection->executePrepared(
	 *     $statement,
	 *     [
	 *         "name" => "Voltron",
	 *     ],
	 *     [
	 *         "name" => Column::BIND_PARAM_INT,
	 *     ]
	 * );
	 *</code>
	 */
	public function prepare(string! sqlStatement) -> <\PDOStatement>
	{
		return this->_pdo->prepare(sqlStatement);
	}

	/**
	 * Sends SQL statements to the database server returning the success state.
	 * Use this method only when the SQL statement sent to the server is returning rows
	 *
	 *<code>
	 * // Querying data
	 * $resultset = $connection->query(
	 *     "SELECT * FROM robots WHERE type = 'mechanical'"
	 * );
	 *
	 * $resultset = $connection->query(
	 *     "SELECT * FROM robots WHERE type = ?",
	 *     [
	 *         "mechanical",
	 *     ]
	 * );
	 *</code>
	 */
	public function query(string! sqlStatement, var bindParams = null, var bindTypes = null) -> <ResultInterface> | bool
	{
		var eventsManager, pdo, statement, params, types;

		let eventsManager = <ManagerInterface> this->_eventsManager;

		/**
		 * Execute the beforeQuery event if an EventsManager is available
		 */
		if typeof eventsManager == "object" {
			let this->_sqlStatement = sqlStatement,
				this->_sqlVariables = bindParams,
				this->_sqlBindTypes = bindTypes;
			if eventsManager->fire("db:beforeQuery", this) === false {
				return false;
			}
		}

		let pdo = <\Pdo> this->_pdo;
		if typeof bindParams == "array" {
            let params = bindParams;
            let types = bindTypes;
        } else {
            let params = [];
            let types = [];
        }

        let statement = pdo->prepare(sqlStatement);
        if typeof statement == "object" {
            let statement = this->executePrepared(statement, params, types);
        } else {
            throw new Exception("Cannot prepare statement");
        }

		/**
		 * Execute the afterQuery event if an EventsManager is available
		 */
		if typeof statement == "object" {
			if typeof eventsManager == "object" {
				eventsManager->fire("db:afterQuery", this);
			}
			return new ResultPdo(this, statement, sqlStatement, bindParams, bindTypes);
		}

		return statement;
	}

	/**
	 * Rollbacks the active transaction in the connection
	 */
	public function rollback(bool nesting = true) -> bool
	{
		var pdo, transactionLevel, eventsManager, savepointName;

		let pdo = this->_pdo;
		if typeof pdo != "object" {
			return false;
		}

		/**
		 * Check the transaction nesting level
		 */
		let transactionLevel = (int) this->_transactionLevel;
		if !transactionLevel {
			throw new Exception("There is no active transaction");
		}

		if transactionLevel == 1 {

			/**
			 * Notify the events manager about the rollbacked transaction
			 */
			let eventsManager = <ManagerInterface> this->_eventsManager;
			if typeof eventsManager == "object" {
				eventsManager->fire("db:rollbackTransaction", this);
			}

			/**
			 * Reduce the transaction nesting level
			 */
			let this->_transactionLevel--;

			return pdo->rollback();

		} else {

			/**
			 * Check if the current database system supports nested transactions
			 */
			if transactionLevel && nesting && this->isNestedTransactionsWithSavepoints() {

				let savepointName = this->getNestedTransactionSavepointName();

				/**
				 * Notify the events manager about the rolled back savepoint
				 */
				let eventsManager = <ManagerInterface> this->_eventsManager;
				if typeof eventsManager == "object" {
					eventsManager->fire("db:rollbackSavepoint", this, savepointName);
				}

				/**
				 * Reduce the transaction nesting level
				 */
				let this->_transactionLevel--;

				return this->rollbackSavepoint(savepointName);
			}
		}

		/**
		 * Reduce the transaction nesting level
		 */
		if transactionLevel > 0 {
			let this->_transactionLevel--;
		}

		return false;
	}
}
