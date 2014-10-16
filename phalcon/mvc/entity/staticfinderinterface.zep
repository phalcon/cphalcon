
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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

namespace Phalcon\Mvc\Entity;

use Phalcon\Mvc\EntityInterface;

/**
 * Phalcon\Mvc\Entity\StaticFinderInterface
 *
 * Interface provides static methods for find entities.
 */
interface StaticFinderInterface
{
	/**
	 * Allows to fiod a set of entities that match the specified conditions
	 *
	 * @param 	array parameters
	 * @return  Phalcon\Mvc\Entity\ResultsetInterface
	 */
	public static function find(var parameters = null) -> <ResultsetInterface>;

	/**
	 * Allows to query the first entity that match the specified conditions
	 *
	 * @param array parameters
	 * @return Phalcon\Mvc\EntityInterface
	 */
	public static function findFirst(var parameters = null) -> <EntityInterface>;
}
