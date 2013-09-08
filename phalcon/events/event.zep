
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

	protected _type;

	protected _source;

	protected _data;

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
	public function __construct(type, source, data=null, cancelable=true)
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
	 * Set the event's type
	 *
	 * @param string eventType
	 */
	public function setType(eventType)
	{
		let this->_type = eventType;
	}

	/**
	 * Returns the event's type
	 *
	 * @return string
	 */
	public function getType()
	{
		return this->_type;
	}

	/**
	 * Returns the event's source
	 *
	 * @return object
	 */
	public function getSource()
	{
		return this->_source;
	}

	/**
	 * Set the event's data
	 *
	 * @param string data
	 */
	public function setData(data)
	{
		let this->_data = data;
	}

	/**
	 * Returns the event's data
	 *
	 * @return mixed
	 */
	public function getData()
	{
		return this->_data;
	}

	/**
	 * Sets if the event is cancelable
	 *
	 * @param boolean cancelable
	 */
	public function setCancelable(cancelable)
	{
		let this->_cancelable = cancelable;
	}

	/**
	 * Check whether the event is cancelable
	 *
	 * @return boolean
	 */
	public function getCancelable()
	{
		return this->_cancelable;
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
