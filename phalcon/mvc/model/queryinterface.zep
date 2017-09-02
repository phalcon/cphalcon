
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

namespace Phalcon\Mvc\Model;

/**
 * Phalcon\Mvc\Model\QueryInterface
 *
 * Interface for Phalcon\Mvc\Model\Query
 */
interface QueryInterface
{

	/**
	 * Parses the intermediate code produced by Phalcon\Mvc\Model\Query\Lang generating another
	 * intermediate representation that could be executed by Phalcon\Mvc\Model\Query
	 */
	public function parse() -> array;

	/**
	 * Sets the cache parameters of the query
	 */
	public function cache(array cacheOptions) -> <QueryInterface>;

	/**
	 * Returns the current cache options
	 */
	public function getCacheOptions() -> array;

	/**
	 * Tells to the query if only the first row in the resultset must be returned
	 */
	public function setUniqueRow(boolean uniqueRow) -> <QueryInterface>;

	/**
	 * Check if the query is programmed to get only the first row in the resultset
	 */
	public function getUniqueRow() -> boolean;

	/**
	 * Executes a parsed PHQL statement
	 *
	 * @param array bindParams
	 * @param array bindTypes
	 * @return mixed
	 */
	public function execute(bindParams = null, bindTypes = null);
}
