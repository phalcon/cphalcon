
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

namespace Phalcon\Db\Adapter;

/**
 * Phalcon\Db\Adapter\Pdo
 *
 * Phalcon\Db\Adapter\Pdo is the Phalcon\Db that internally uses PDO to connect to a database
 *
 *<code>
 *	$connection = new Phalcon\Db\Adapter\Pdo\Mysql(array(
 *		'host' => '192.168.0.11',
 *		'username' => 'sigma',
 *		'password' => 'secret',
 *		'dbname' => 'blog',
 *		'port' => '3306'
 *	));
 *</code>
 */
abstract class Pdo extends Phalcon\Db\Adapter
{

	/**
	 * PDO Handler
	 */
	protected _pdo;

	/**
	 * Last affected rows
	 */
	protected _affectedRows;

	/**
	 * Transaction level
	 */
	protected _transactionLevel = 0;

	/**
	 * Constructor for Phalcon\Db\Adapter\Pdo
	 *
	 * @param array descriptor
	 */
	public function __construct(descriptor)
	{

		if typeof descriptor != "array" {
			throw new Phalcon\Db\Exception("The descriptor must be an array");
		}

		this->connect(descriptor);

		parent::__construct(descriptor);
	}

	/**
	 * This method is automatically called in Phalcon\Db\Adapter\Pdo constructor.
	 * Call it when you need to restore a database connection
	 *
	 *<code>
	 * //Make a connection
	 * $connection = new Phalcon\Db\Adapter\Pdo\Mysql(array(
	 *  'host' => '192.168.0.11',
	 *  'username' => 'sigma',
	 *  'password' => 'secret',
	 *  'dbname' => 'blog',
	 * ));
	 *
	 * //Reconnect
	 * $connection->connect();
	 * </code>
	 *
	 * @param 	array descriptor
	 * @return 	boolean
	 */
	public function connect(descriptor=null)
	{
		var username, password, dsnParts, dsnAttributes,
			persistent, options, key, value;

		if descriptor === null {
			let descriptor = this->_descriptor;
		}

		/**
		 * Check for a username or use null as default
		 */
		if fetch username, descriptor["username"] {
			unset descriptor["username"];
		} else {
			let username = null;
		}

		/**
		 * Check for a password or use null as default
		 */
		if fetch password, descriptor["password"] {
			unset descriptor["password"];
		} else {
			let password = null;
		}

		/**
		 * Check if the developer has defined custom options or create one from scratch
		 */
		if fetch options, descriptor["options"] {
			unset descriptor["options"] ;
		} else {
			let options = [];
		}

		/**
		 * Check if the user has defined a custom dsn
		 */
		 if !fetch dsnAttributes, descriptor["dsn"] {
		 	let dsnParts = [];
			for key, value in descriptor {
				let dsnParts[] = key . "=" . value;
			}
			let dsnAttributes = join(";", dsnParts);
		}

		let options[Pdo::ATTR_ERRMODE] = Pdo::ERRMODE_EXCEPTION;

		/**
		 * Check if the connection must be persistent
		 */
		if fetch persistent, descriptor["persistent"] {
			if persistent {
				let options[Pdo::ATTR_PERSISTENT] = true;
			}
		}

		/**
		 * Create the connection using PDO
		 */
		let this->_pdo = new Pdo(this->_type . ":" . dsnAttributes, username, password, options);
	}

	/**
	 * Returns a PDO prepared statement to be executed with 'executePrepared'
	 *
	 *<code>
	 * $statement = $db->prepare('SELECT * FROM robots WHERE name = :name');
	 * $result = $connection->executePrepared($statement, array('name' => 'Voltron'));
	 *</code>
	 *
	 * @param string $sqlStatement
	 * @return \PDOStatement
	 */
	public function prepare(sqlStatement)
	{
		var pdo;
		let pdo = this->_pdo;
		return pdo->prepare(sqlStatement);
	}

	/**
	 * Executes a prepared statement binding. This function uses integer indexes starting from zero
	 *
	 *<code>
	 * $statement = $db->prepare('SELECT * FROM robots WHERE name = :name');
	 * $result = $connection->executePrepared($statement, array('name' => 'Voltron'));
	 *</code>
	 *
	 * @param \PDOStatement statement
	 * @param array placeholders
	 * @param array dataTypes
	 * @return \PDOStatement
	 */
	public function executePrepared(statement, placeholders, dataTypes)
	{
		var wildcard, value, type, castValue, parameter;

		if typeof placeholders != "array" {
			throw new Phalcon\Db\Exception("Placeholders must be an array");
		}

		for wildcard, value in placeholders {

			if typeof wildcard == "integer" {
				let parameter = wildcard + 1;
			} else {
				if typeof wildcard == "string" {
					let parameter = wildcard;
				} else {
					throw new Phalcon\Db\Exception("Invalid bind parameter");
				}
			}

			if typeof dataTypes == "array" {

				if !fetch type, dataTypes[wildcard] {
					throw new Phalcon\Db\Exception("Invalid bind type parameter");
				}

				/**
				 * The bind type is double so we try to get the double value
				 */
				if type == Phalcon\Db\Column::BIND_PARAM_DECIMAL {
					let castValue = doubleval(value),
						type = Phalcon\Db\Column::BIND_SKIP;
				} else {
					let castValue = value;
				}

				/**
				 * 1024 is ignore the bind type
				 */
				if type == Phalcon\Db\Column::BIND_SKIP {
					statement->bindParam(parameter, castValue);
				} else {
					statement->bindParam(parameter, castValue, type);
				}

			} else {
				statement->bindParam(parameter, value);
			}
		}

		statement->execute();
		return statement;
	}

	/**
	 * Sends SQL statements to the database server returning the success state.
	 * Use this method only when the SQL statement sent to the server is returning rows
	 *
     *<code>
	 *	//Querying data
	 *	$resultset = $connection->query("SELECT * FROM robots WHERE type='mechanical'");
	 *	$resultset = $connection->query("SELECT * FROM robots WHERE type=?", array("mechanical"));
	 *</code>
	 *
	 * @param  string sqlStatement
	 * @param  array bindParams
	 * @param  array bindTypes
	 * @return Phalcon\Db\ResultInterface
	 */
	public function query(sqlStatement, bindParams=null, bindTypes=null)
	{
		var eventsManager, pdo, statement;

		let eventsManager = <Phalcon\Events\Manager> this->_eventsManager;

		/**
		 * Execute the beforeQuery event if a EventsManager is available
		 */
		if typeof eventsManager == "object" {
			let this->_sqlStatement = sqlStatement,
				this->_sqlVariables = bindParams,
				this->_sqlBindTypes = bindTypes;
			if eventsManager->fire("db:beforeQuery", this, bindParams) == false {
				return false;
			}
		}

		let pdo = <Pdo> this->_pdo;
		if typeof bindParams == "array" {
			let statement = pdo->prepare(sqlStatement);
			if typeof statement == "object" {
				let statement = this->executePrepared(statement, bindParams, bindTypes);
			}
		} else {
			let statement = pdo->query(sqlStatement);
		}

		/**
		 * Execute the afterQuery event if a EventsManager is available
		 */
		if typeof statement == "object" {
			if typeof eventsManager == "object" {
				eventsManager->fire("db:afterQuery", this, bindParams);
			}
			return new Phalcon\Db\Result\Pdo(this, statement, sqlStatement, bindParams, bindTypes);
		}

		return statement;
	}

	/**
	 * Sends SQL statements to the database server returning the success state.
	 * Use this method only when the SQL statement sent to the server doesn't return any row
	 *
	 *<code>
	 *	//Inserting data
	 *	$success = $connection->execute("INSERT INTO robots VALUES (1, 'Astro Boy')");
	 *	$success = $connection->execute("INSERT INTO robots VALUES (?, ?)", array(1, 'Astro Boy'));
	 *</code>
	 *
	 * @param  string sqlStatement
	 * @param  array bindParams
	 * @param  array bindTypes
	 * @return boolean
	 */
	public function execute(sqlStatement, bindParams=null, bindTypes=null)
	{
		var eventsManager, affectedRows, pdo, newStatement, statement;

		/**
		 * Execute the beforeQuery event if a EventsManager is available
		 */
		let eventsManager = <Phalcon\Events\Manager> this->_eventsManager;
		if typeof eventsManager == "object" {
			let this->_sqlStatement = sqlStatement,
				this->_sqlVariables = bindParams,
				this->_sqlBindTypes = bindTypes;
			if eventsManager->fire("db:beforeQuery", this, bindParams) === false {
				return false;
			}
		}

		/**
		 * Initialize affectedRows to 0
		 */
		let affectedRows = 0;

		let pdo = this->_pdo;
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
				eventsManager->fire("db:afterQuery", this, bindParams);
			}
		}

		return true;
	}

	/**
	 * Returns the number of affected rows by the lastest INSERT/UPDATE/DELETE executed in the database system
	 *
	 *<code>
	 *	$connection->execute("DELETE FROM robots");
	 *	echo $connection->affectedRows(), ' were deleted';
	 *</code>
	 *
	 * @return int
	 */
	public function affectedRows()
	{
		return this->_affectedRows;
	}

	/**
	 * Closes the active connection returning success. Phalcon automatically closes and destroys
	 * active connections when the request ends
	 *
	 * @return boolean
	 */
	public function close()
	{
		var pdo;
		let pdo = this->_pdo;
		if typeof pdo == "object" {
			let this->_pdo = null;
			return true;
		}
		return true;
	}

	/**
	 * Escapes a column/table/schema name
	 *
	 *<code>
	 *	$escapedTable = $connection->escapeIdentifier('robots');
	 *	$escapedTable = $connection->escapeIdentifier(array('store', 'robots'));
	 *</code>
	 *
	 * @param string identifier
	 * @return string
	 */
	public function escapeIdentifier(identifier)
	{
		if typeof identifier == "array" {
			return "\"" . identifier[0] . "\".\"" . identifier[1] . "\"";
		}
		return "\"" . identifier . "\"";
	}

	/**
	 * Escapes a value to avoid SQL injections according to the active charset in the connection
	 *
	 *<code>
	 *	$escapedStr = $connection->escapeString('some dangerous value');
	 *</code>
	 *
	 * @param string str
	 * @return string
	 */
	public function escapeString(str)
	{
		var pdo;
		let pdo = this->_pdo;
		return pdo->quote(str);
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
	 *
	 * @param string sequenceName
	 * @return int
	 */
	public function lastInsertId(sequenceName=null)
	{
		var pdo;
		let pdo = this->_pdo;
		if typeof pdo != "object" {
			return false;
		}
		return pdo->lastInsertId(sequenceName);
	}

	/**
     * Starts a transaction in the connection
     *
     * @param boolean nesting
     * @return boolean
     */
	public function begin(nesting=true)
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
		let transactionLevel = this->_transactionLevel;

		if transactionLevel == 1 {

			/**
			 * Notify the events manager about the started transaction
			 */
			let eventsManager = <Phalcon\Events\Manager> this->_eventsManager;
			if typeof eventsManager == "object" {
				eventsManager->fire("db:beginTransaction", this);
			}

			return pdo->beginTransaction();
		} else {

			if transactionLevel {

				if nesting {
					if this->isNestedTransactionsWithSavepoints() {

						let eventsManager = <Phalcon\Events\Manager> this->_eventsManager,
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
			}

		}

		return false;
	}

    /**
     * Rollbacks the active transaction in the connection
     *
     * @param boolean nesting
     * @return boolean
     */
	public function rollback(nesting=true)
	{
		var pdo, transactionLevel, eventsManager, savepointName;

		let pdo = this->_pdo;
		if typeof pdo != "object" {
			return false;
		}

		/**
		 * Check the transaction nesting level
		 */
		let transactionLevel = this->_transactionLevel;
		if !transactionLevel {
			throw new Phalcon\Db\Exception("There is no active transaction");
		}

		if transactionLevel == 1 {

			/**
			 * Notify the events manager about the rollbacked transaction
			 */
			let eventsManager = <Phalcon\Events\Manager> this->_eventsManager;
			if typeof eventsManager == "object" {
				eventsManager->fire("db:rollbackTransaction", this);
			}

			/**
			 * Reduce the transaction nesting level
			 */
			let this->_transactionLevel--;

			return pdo->rollback();

		} else {

			if transactionLevel {

				if nesting {
					if this->isNestedTransactionsWithSavepoints() {

						let savepointName = this->getNestedTransactionSavepointName();

						/**
						 * Notify the events manager about the rolled back savepoint
						 */
						let eventsManager = <Phalcon\Events\Manager> this->_eventsManager;
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
     * Commits the active transaction in the connection
     *
     * @param boolean nesting
     * @return boolean
     */
	public function commit(nesting=true)
	{
		var pdo, transactionLevel, eventsManager, savepointName;

		let pdo = this->_pdo;
		if typeof pdo != "object" {
			return false;
		}

		/**
		 * Check the transaction nesting level
		 */
		let transactionLevel = this->_transactionLevel;
		if !transactionLevel {
			throw new Phalcon\Db\Exception("There is no active transaction");
		}

		if transactionLevel == 1 {

			/**
			 * Notify the events manager about the commited transaction
			 */
			let eventsManager = <Phalcon\Events\Manager> this->_eventsManager;
			if typeof eventsManager == "object" {
				eventsManager->fire("db:commitTransaction", this);
			}

			/**
			 * Reduce the transaction nesting level
			 */
			let this->_transactionLevel--;

			return pdo->commit();
		} else {

			if transactionLevel {

				if nesting {

					/**
					 * Check if the current database system supports nested transactions
					 */
					if this->isNestedTransactionsWithSavepoints() {

						/**
						 * Notify the events manager about the commited savepoint
						 */
						let eventsManager = <Phalcon\Events\Manager> this->_eventsManager,
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
	 * Returns the current transaction nesting level
	 *
	 * @return int
	 */
	public function getTransactionLevel()
	{
		return this->_transactionLevel;
	}

	/**
	 * Checks whether the connection is under a transaction
	 *
	 *<code>
	 *	$connection->begin();
	 *	var_dump($connection->isUnderTransaction()); //true
	 *</code>
	 *
	 * @return boolean
	 */
	public function isUnderTransaction()
	{
		var pdo;
		let pdo = this->_pdo;
		if typeof pdo == "object" {
			return pdo->inTransaction();
		}
		return false;
	}

	/**
	 * Return internal PDO handler
	 *
	 * @return \PDO
	 */
	public function getInternalHandler()
	{
		return this->_pdo;
	}

}
