
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

namespace Phalcon\Mvc\Model;

/**
 * Phalcon\Mvc\Model\BehaviorInterface
 *
 * Interface for Phalcon\Mvc\Model\Behavior
 */
interface BehaviorInterface
{

	/**
	 * Phalcon\Mvc\Model\Behavior
	 *
	 * @param array options
	 */
	public function __construct(options=null);

	/**
	 * This method receives the notifications from the EventsManager
	 *
	 * @param string type
	 * @param Phalcon\Mvc\ModelInterface model
	 */
	public function notify(string! type, <Phalcon\Mvc\ModelInterface> model);

	/**
	 * Calls a method when it's missing in the model
	 *
	 * @param Phalcon\Mvc\ModelInterface model
	 * @param string method
	 * @param array arguments
	 */
	public function missingMethod(string !model, string !method, arguments=null);

}
