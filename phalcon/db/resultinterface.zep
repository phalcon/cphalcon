
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2017 Phalcon Team (http://www.phalconphp.com)       |
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

namespace Phalcon\Db;

/**
 * Phalcon\Db\ResultInterface
 *
 * Interface for Phalcon\Db\Result objects
 */
interface ResultInterface
{
	/**
	 * Allows to executes the statement again. Some database systems don't support scrollable cursors,
	 * So, as cursors are forward only, we need to execute the cursor again to fetch rows from the begining
	 *
	 * @return boolean
	 */
	public function execute();

	/**
	 * Fetches an array/object of strings that corresponds to the fetched row, or FALSE if there are no more rows.
	 * This method is affected by the active fetch flag set using Phalcon\Db\Result\Pdo::setFetchMode
	 *
	 * @return mixed
	 */
	public function $fetch();

	/**
	 * Returns an array of strings that corresponds to the fetched row, or FALSE if there are no more rows.
	 * This method is affected by the active fetch flag set using Phalcon\Db\Result\Pdo::setFetchMode
	 *
	 * @return mixed
	 */
	public function fetchArray();

	/**
	 * Returns an array of arrays containing all the records in the result
	 * This method is affected by the active fetch flag set using Phalcon\Db\Result\Pdo::setFetchMode
	 *
	 * @return array
	 */
	public function fetchAll();

	/**
	 * Gets number of rows returned by a resultset
	 *
	 * @return int
	 */
	public function numRows();

	/**
	 * Moves internal resultset cursor to another position letting us to fetch a certain row
	 *
	 * @param int number
	 */
	public function dataSeek(long number) -> void;

	/**
	 * Changes the fetching mode affecting Phalcon\Db\Result\Pdo::fetch()
	 *
	 * @param int fetchMode
	 */
	public function setFetchMode(int fetchMode, var colNoOrClassNameOrObject = null, var ctorargs = null) -> boolean;

	/**
	 * Gets the internal PDO result object
	 *
	 * @return \PDOStatement
	 */
	public function getInternalResult();

}
