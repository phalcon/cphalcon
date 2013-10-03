
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
 * Phalcon\Events\Event
 *
 * This class offers contextual information of a fired event in the EventsManager
 */
class Event
{

	protected _type { set, get };

	protected _source { get };

	protected _data { set, get };

	protected _stopped = false;

	protected _cancelable = true;

	/**
	 * Phalcon\Events\Event constructor
	 *
	 * @param string type
	 * @param object source
	 * @param mixed data
	 * @param boolean cancelable
	 */
	public function __construct(string! type, source, data=null, cancelable=true)
	{

		let this->_type = type,
			this->_source = source;

		if data !== null {
			let this->_data = data;
		}

		if cancelable !== true {
			let this->_cancelable = cancelable;
		}
	}

	/**
	 * Stops the event preventing propagation
	 */
	public function stop()
	{
		if this->_cancelable {
			let this->_stopped = true;
		} else {
			throw new Phalcon\Events\Exception("Trying to cancel a non-cancelable event");
		}
	}

	/**
	 * Check whether the event is currently stopped
	 *
	 * @return boolean
	 */
	public function isStopped()
	{
		return this->_stopped;
	}

}
