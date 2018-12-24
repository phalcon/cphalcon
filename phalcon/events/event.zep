
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Events;

/**
 * Phalcon\Events\Event
 *
 * This class offers contextual information of a fired event in the EventsManager
 */
class Event implements EventInterface
{
	/**
	 * Event type
	 *
	 * @var string
	 */
	protected _type { get };

	/**
	 * Event source
	 *
	 * @var object
	 */
	protected _source { get };

	/**
	 * Event data
	 *
	 * @var mixed
	 */
	protected _data { get };

	/**
	 * Is event propagation stopped?
	 *
	 * @var bool
	 */
	protected _stopped = false;

	/**
	 * Is event cancelable?
	 *
	 * @var bool
	 */
	protected _cancelable = true;

	/**
	 * Phalcon\Events\Event constructor
	 *
	 * @param object source
	 */
	public function __construct(string! type, source, var data = null, bool cancelable = true)
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
	 * Sets event data.
	 */
	public function setData(var data = null) -> <EventInterface>
	{
		let this->_data = data;

		return this;
	}

	/**
	 * Sets event type.
	 */
	public function setType(string! type) -> <EventInterface>
	{
		let this->_type = type;

		return this;
	}

	/**
	 * Stops the event preventing propagation.
	 *
	 * <code>
	 * if ($event->isCancelable()) {
	 *     $event->stop();
	 * }
	 * </code>
	 */
	public function stop() -> <EventInterface>
	{
		if !this->_cancelable {
			throw new Exception("Trying to cancel a non-cancelable event");
		}

		let this->_stopped = true;

		return this;
	}

	/**
	 * Check whether the event is currently stopped.
	 */
	public function isStopped() -> bool
	{
		return this->_stopped;
	}

	/**
	 * Check whether the event is cancelable.
	 *
	 * <code>
	 * if ($event->isCancelable()) {
	 *     $event->stop();
	 * }
	 * </code>
	 */
	public function isCancelable() -> bool
	{
		return this->_cancelable;
	}
}
