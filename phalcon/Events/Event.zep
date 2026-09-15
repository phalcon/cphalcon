
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Events;

use Phalcon\Contracts\Events\Stoppable;
use Phalcon\Events\Exceptions\EventNotCancelable;
use Phalcon\Events\Exceptions\InvalidEventSource;

/**
 * This class offers contextual information of a fired event in the
 * EventsManager
 *
 *```php
 * Phalcon\Events\Event;
 *
 * $event = new Event("db:afterQuery", $this, ["data" => "mydata"], true);
 * if ($event->isCancelable()) {
 *     $event->stop();
 * }
 * ```
 */
class Event implements EventInterface, Stoppable
{
    /**
     * Is event cancelable?
     */
    protected bool cancelable;

    /**
     * Event data
     *
     * @var mixed
     */
    protected data;

    /**
     * Event source
     *
     * @var object|null
     */
    protected source = null;

    /**
     * Is event propagation stopped?
     */
    protected bool stopped = false;

    /**
     * Event type
     */
    protected string type;

    /**
     * Event constructor.
     *
     * @throws InvalidEventSource
     */
    public function __construct(
        string type,
        var source = null,
        var data = null,
        bool cancelable = true
    ) {
        if unlikely null !== source && typeof source !== "object" {
            throw new InvalidEventSource(type, (typeof source));
        }

        let this->type       = type,
            this->source     = source,
            this->data       = data,
            this->cancelable = cancelable;
    }

    public function getData() -> var
    {
        return this->data;
    }

    public function getSource() -> object | null
    {
        return this->source;
    }

    public function getType() -> string
    {
        return this->type;
    }

    /**
     * Check whether the event is cancelable.
     *
     * ```php
     * if ($event->isCancelable()) {
     *     $event->stop();
     * }
     * ```
     */
    public function isCancelable() -> bool
    {
        return this->cancelable;
    }

    /**
     * Returns whether propagation must stop. PSR-14 alias backed by the same
     * `stopped` flag as `isStopped()`; calling `stop()` flips both.
     */
    public function isPropagationStopped() -> bool
    {
        return this->stopped;
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
    public function setType(string type) -> <EventInterface>
    {
        let this->type = type;

        return this;
    }

    /**
     * Stops the event preventing propagation.
     *
     * ```php
     * if ($event->isCancelable()) {
     *     $event->stop();
     * }
     * ```
     *
     * @throws EventNotCancelable
     */
    public function stop() -> <EventInterface>
    {
        if unlikely !this->cancelable {
            throw new EventNotCancelable();
        }

        let this->stopped = true;

        return this;
    }
}
