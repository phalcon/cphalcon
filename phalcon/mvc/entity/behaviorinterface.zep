
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
 * Phalcon\Mvc\Entity\BehaviorInterface
 *
 * Interface for Phalcon\Mvc\Entity\Behavior
 */
interface BehaviorInterface
{

	/**
	 * Phalcon\Mvc\Entity\Behavior
	 *
	 * @param array options
	 */
	public function __construct(options=null);

	/**
	 * This method receives the notifications from the EventsManager
	 *
	 * @param string type
	 * @param Phalcon\Mvc\EntityInterface entity
	 */
	public function notify(string! type, <EntityInterface> entity);

	/**
	 * Calls a method when it's missing in the entity
	 *
	 * @param Phalcon\Mvc\EntityInterface entity
	 * @param string method
	 * @param array arguments
	 */
	public function missingMethod(<EntityInterface> entity, string! method, var arguments = null);

}
