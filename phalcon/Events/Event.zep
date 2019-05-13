
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
 * This class offers contextual information of a fired event in the
 * EventsManager
 */
class Event implements EventInterface
{
    /**
     * Is event cancelable?
     *
     * @var bool
     */
    protected cancelable;

    /**
     * Event data
     *
     * @var mixed
     */
    protected data { get };

    /**
     * Event source
     *
     * @var object
     */
    protected source { get };

    /**
     * Is event propagation stopped?
     *
     * @var bool
     */
    protected stopped = false;

    /**
     * Event type
     *
     * @var string
     */
    protected type { get };

    /**
     * Phalcon\Events\Event constructor
     *
     * @param object source
     */
    public function __construct(string! type, source, var data = null, bool cancelable = true) -> void
    {
        let this->type = type,
            this->source = source,
            this->data = data,
            this->cancelable = cancelable;
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
        return this->cancelable;
    }
    
    /**
     * Check whether the event is currently stopped.
     */
    public function isStopped() -> bool
    {
        return this->stopped;
    }

    /**
     * Sets event data.
     */
    public function setData(var data = null) -> <EventInterface>
    {
        let this->data = data;

        return this;
    }

    /**
     * Sets event type.
     */
    public function setType(string! type) -> <EventInterface>
    {
        let this->type = type;

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
        if unlikely !this->cancelable {
            throw new Exception("Trying to cancel a non-cancelable event");
        }

        let this->stopped = true;

        return this;
    }
}
