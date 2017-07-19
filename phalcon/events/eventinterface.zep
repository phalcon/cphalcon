
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

namespace Phalcon\Events;

/**
 * Phalcon\Events\EventInterface
 *
 * Interface for Phalcon\Events\Event class
 */
interface EventInterface
{
	/**
	 * Gets event data
	 */
	public function getData() -> var;

	/**
	 * Sets event data
	 * @param mixed data
	 */
	public function setData(data = null) -> <EventInterface>;

	/**
	 * Gets event type
	 */
	public function getType() -> var;

	/**
	 * Sets event type
	 */
	public function setType(string! type) -> <EventInterface>;

	/**
	 * Stops the event preventing propagation
	 */
	public function stop() -> <EventInterface>;

	/**
	 * Check whether the event is currently stopped
	 */
	public function isStopped() -> boolean;

	/**
	 * Check whether the event is cancelable
	 */
	public function isCancelable() -> boolean;
}
