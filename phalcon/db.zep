
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
 +------------------------------------------------------------------------+
 */

namespace Phalcon;

/**
 * Phalcon\Db
 *
 * Phalcon\Db and its related classes provide a simple SQL database interface for Phalcon Framework.
 * The Phalcon\Db is the basic class you use to connect your PHP application to an RDBMS.
 * There is a different adapter class for each brand of RDBMS.
 *
 * This component is intended to lower level database operations. If you want to interact with databases using
 * higher level of abstraction use Phalcon\Mvc\Model.
 *
 * Phalcon\Db is an abstract class. You only can use it with a database adapter like Phalcon\Db\Adapter\Pdo
 *
 * <code>
 *
 *try {
 *
 *  $connection = new \Phalcon\Db\Adapter\Pdo\Mysql(array(
 *     'host' => '192.168.0.11',
 *     'username' => 'sigma',
 *     'password' => 'secret',
 *     'dbname' => 'blog',
 *     'port' => '3306',
 *  ));
 *
 *  $result = $connection->query("SELECT * FROM robots LIMIT 5");
 *  $result->setFetchMode(Phalcon\Db::FETCH_NUM);
 *  while ($robot = $result->fetch()) {
 *    print_r($robot);
 *  }
 *
 *} catch (Phalcon\Db\Exception $e) {
 *	echo $e->getMessage(), PHP_EOL;
 *}
 *
 * </code>
 */
abstract class Db
{

	const FETCH_LAZY = \PDO::FETCH_LAZY;

	const FETCH_ASSOC = \PDO::FETCH_ASSOC;

	const FETCH_NAMED = \PDO::FETCH_NAMED;

	const FETCH_NUM = \PDO::FETCH_NUM;

	const FETCH_BOTH = \PDO::FETCH_BOTH;

	const FETCH_OBJ = \PDO::FETCH_OBJ;

	const FETCH_BOUND = \PDO::FETCH_BOUND;

	const FETCH_COLUMN = \PDO::FETCH_COLUMN;

	const FETCH_CLASS = \PDO::FETCH_CLASS;

	const FETCH_INTO = \PDO::FETCH_INTO;

	const FETCH_FUNC = \PDO::FETCH_FUNC;

	const FETCH_GROUP = \PDO::FETCH_GROUP;

	const FETCH_UNIQUE = \PDO::FETCH_UNIQUE;

	const FETCH_KEY_PAIR = \PDO::FETCH_KEY_PAIR;

	const FETCH_CLASSTYPE = \PDO::FETCH_CLASSTYPE;

	const FETCH_SERIALIZE = \PDO::FETCH_SERIALIZE;

	const FETCH_PROPS_LATE = \PDO::FETCH_PROPS_LATE;

	/**
	 * Enables/disables options in the Database component
	 */
	public static function setup(array! options) -> void
	{
		var escapeIdentifiers;

		/**
		 * Enables/Disables globally the escaping of SQL identifiers
		 */
		if fetch escapeIdentifiers, options["escapeSqlIdentifiers"] {
			globals_set("db.escape_identifiers", escapeIdentifiers);
		}
	}
}
