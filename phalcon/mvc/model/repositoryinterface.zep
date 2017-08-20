
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

use Phalcon\Mvc\ModelInterface;

/**
 * Phalcon\Mvc\RepositoryInterface
 *
 * Interface for Phalcon\Mvc\Model\Repository
 */
interface RepositoryInterface
{
	/**
	 * Allows to query a set of records that match the specified conditions
	 */
	public function find(var parameters = null) -> <ResultsetInterface>;

	/**
	 * Allows to query the first record that match the specified conditions
	 *
	 * @param array parameters
	 */
	public function findFirst(parameters = null) -> <ModelInterface>;
}
