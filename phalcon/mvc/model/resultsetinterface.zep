
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

use Phalcon\Cache\BackendInterface;

/**
 * Phalcon\Mvc\Model\ResultsetInterface
 *
 * Interface for Phalcon\Mvc\Model\Resultset
 */
interface ResultsetInterface
{

	/**
	 * Returns the internal type of data retrieval that the resultset is using
	 */
	public function getType() -> int;

	/**
	 * Get first row in the resultset
	 */
	public function getFirst() -> <ModelInterface> | bool;

	/**
	 * Get last row in the resultset
	 */
	public function getLast() -> <ModelInterface> | bool;

	/**
	 * Set if the resultset is fresh or an old one cached
	 */
	public function setIsFresh(bool isFresh);

	/**
	 * Tell if the resultset if fresh or an old one cached
	 */
	public function isFresh() -> bool;

	/**
	 * Returns the associated cache for the resultset
	 */
	public function getCache() -> <BackendInterface>;

	/**
	 * Returns a complete resultset as an array, if the resultset has a big number of rows
	 * it could consume more memory than currently it does.
	 */
	public function toArray() -> array;
}
