
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

}