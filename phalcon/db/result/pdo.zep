
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

namespace Phalcon\Db\Result;

/**
 * Phalcon\Db\Result\Pdo
 *
 * Encapsulates the resultset internals
 *
 * <code>
 *	result = connection->query("SELECT * FROM robots ORDER BY name");
 *	result->setFetchMode(Phalcon\Db::FETCH_NUM);
 *	while (robot = result->fetchArray()) {
 *		print_r(robot);
 *	}
 * </code>
 */
class Pdo
{

	protected _connection;

	protected _result;

	/**
	 * Active fetch mode
	 */
	protected _fetchMode = 4;

	/**
	 * Internal resultset
	 *
	 * @var PDOStatement
	 */
	protected _pdoStatement;

	protected _sqlStatement;

	protected _bindParams;

	protected _bindTypes;

	protected _rowCount = false;

}