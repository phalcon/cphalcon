
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
	 *
	 * @return array
	 */
	public function parse();

	/**
	 * Sets the cache parameters of the query
	 *
	 * @param array cacheOptions
	 * @return Phalcon\Mvc\Model\Query
	 */
	public function cache(cacheOptions);

	/**
	 * Returns the current cache options
	 *
	 * @param array
	 */
	public function getCacheOptions();

	/**
	 * Tells to the query if only the first row in the resultset must be returned
	 *
	 * @param boolean uniqueRow
	 * @return Phalcon\Mvc\Model\Query
	 */
	public function setUniqueRow(boolean uniqueRow);

	/**
	 * Check if the query is programmed to get only the first row in the resultset
	 *
	 * @return boolean
	 */
	public function getUniqueRow();

	/**
	 * Executes a parsed PHQL statement
	 *
	 * @param array bindParams
	 * @param array bindTypes
	 * @return mixed
	 */
	public function execute(bindParams = null, bindTypes = null);

}
