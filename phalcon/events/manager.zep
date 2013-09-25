
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
 * Phalcon\Events\Manager
 *
 * Phalcon Events Manager, offers an easy way to intercept and manipulate, if needed,
 * the normal flow of operation. With the EventsManager the developer can create hooks or
 * plugins that will offer monitoring of data, manipulation, conditional execution and much more.
 *
 */
class Manager //implements Phalcon\Events\ManagerInterface
{

	protected _events = null;

	protected _collect = false;

	protected _enablePriorities = false;

	protected _responses;

	/**
	 * Fires an event in the events manager causing that active listeners be notified about it
	 *
	 *<code>
	 *	$eventsManager->fire('db', $connection);
	 *</code>
	 *
	 * @param string eventType
	 * @param object source
	 * @param mixed  data
	 * @param int cancelable
	 * @return mixed
	 */
	public function fire(string eventType, source, data=null, boolean cancelable=true)
	{

	}

}