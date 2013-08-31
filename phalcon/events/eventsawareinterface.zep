
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

namespace Phalcon\Events;

/**
 * Phalcon\Events\EventsAwareInterface
 *
 * This interface must for those classes that accept an EventsManager and dispatch events
 */
interface EventsAwareInterface
{

	/**
	 * Sets the events manager
	 *
	 * @param Phalcon\Events\ManagerInterface eventsManager
	 */
	public function setEventsManager(eventsManager);

	/**
	 * Returns the internal event manager
	 *
	 * @return Phalcon\Events\ManagerInterface
	 */
	public function getEventsManager();

}
