
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

namespace Phalcon\Mvc\Collection;

use Phalcon\Mvc\CollectionInterface;

/**
 * Phalcon\Mvc\Collection\BehaviorInterface
 *
 * Interface for Phalcon\Mvc\Collection\Behavior
 */
interface BehaviorInterface
{
	/**
	 * This method receives the notifications from the EventsManager
	 */
	public function notify(string! type, <CollectionInterface> collection);

	/**
	 * Calls a method when it's missing in the collection
	 */
	public function missingMethod(<CollectionInterface> collection, string !method, arguments = null);

}
