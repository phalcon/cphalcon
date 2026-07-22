
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Based on the Action Domain Responder pattern
 * @link    https://pmjones.io/adr/
 *
 * Implementation of this file has been influenced by phalcon-api and AuraPHP
 * @link    https://github.com/phalcon/phalcon-api
 * @license https://github.com/phalcon/phalcon-api/blob/master/LICENSE
 * @link    https://github.com/auraphp/Aura.Payload
 * @license https://github.com/auraphp/Aura.Payload/blob/3.x/LICENSE
 *
 * @see Original inspiration for the https://github.com/phalcon/phalcon-api
 */

namespace Phalcon\ADR\Payload;

use Phalcon\Contracts\ADR\Payload\Payload as PayloadContract;
use Throwable;

/**
 * Immutable payload produced by the domain layer.
 *
 * Every `with*()` method returns a new instance, leaving the receiver
 * unchanged. Named factories provide a concise way to create a payload for the
 * commonly used statuses.
 */
class Payload implements PayloadContract
{
    /**
     * @var Throwable|null
     */
    protected exception = null;

    /**
     * @var mixed
     */
    protected extras = null;

    /**
     * @var mixed
     */
    protected input = null;

    /**
     * @var mixed
     */
    protected messages = null;

    /**
     * @var mixed
     */
    protected result = null;

    /**
     * @var mixed
     */
    protected status = null;

    /**
     * Creates a payload with the `ACCEPTED` status.
     */
    public static function accepted(var result = null) -> <PayloadContract>
    {
        return (new static())->withStatus(Status::ACCEPTED)->withResult(result);
    }

    /**
     * Creates a payload with the `AUTHENTICATED` status.
     */
    public static function authenticated(var result = null) -> <PayloadContract>
    {
        return (new static())->withStatus(Status::AUTHENTICATED)->withResult(result);
    }

    /**
     * Creates a payload with the `AUTHORIZED` status.
     */
    public static function authorized(var result = null) -> <PayloadContract>
    {
        return (new static())->withStatus(Status::AUTHORIZED)->withResult(result);
    }

    /**
     * Creates a payload with the `CREATED` status.
     */
    public static function created(var result = null) -> <PayloadContract>
    {
        return (new static())->withStatus(Status::CREATED)->withResult(result);
    }

    /**
     * Creates a payload with the `DELETED` status.
     */
    public static function deleted(var result = null) -> <PayloadContract>
    {
        return (new static())->withStatus(Status::DELETED)->withResult(result);
    }

    /**
     * Creates a payload with the `ERROR` status.
     */
    public static function error(var messages = null) -> <PayloadContract>
    {
        return (new static())->withStatus(Status::ERROR)->withMessages(messages);
    }

    /**
     * Creates a payload with the `NOT_AUTHORIZED` status (authenticated but
     * not allowed - HTTP 403).
     */
    public static function forbidden(var messages = null) -> <PayloadContract>
    {
        return (new static())->withStatus(Status::NOT_AUTHORIZED)->withMessages(messages);
    }

    /**
     * Creates a payload with the `FOUND` status.
     */
    public static function found(var result = null) -> <PayloadContract>
    {
        return (new static())->withStatus(Status::FOUND)->withResult(result);
    }

    /**
     * Gets the exception thrown in the domain layer, if any.
     */
    public function getException() -> <Throwable> | null
    {
        return this->exception;
    }

    /**
     * Gets the arbitrary extra domain information.
     */
    public function getExtras() -> var
    {
        return this->extras;
    }

    /**
     * Gets the domain input.
     */
    public function getInput() -> var
    {
        return this->input;
    }

    /**
     * Gets the domain messages.
     */
    public function getMessages() -> var
    {
        return this->messages;
    }

    /**
     * Gets the domain result.
     */
    public function getResult() -> var
    {
        return this->result;
    }

    /**
     * Gets the payload status.
     */
    public function getStatus() -> var
    {
        return this->status;
    }

    /**
     * Creates a payload with the `NOT_VALID` status.
     */
    public static function invalid(var messages = null) -> <PayloadContract>
    {
        return (new static())->withStatus(Status::NOT_VALID)->withMessages(messages);
    }

    /**
     * Creates a payload with the `NOT_ACCEPTED` status.
     */
    public static function notAccepted(var messages = null) -> <PayloadContract>
    {
        return (new static())->withStatus(Status::NOT_ACCEPTED)->withMessages(messages);
    }

    /**
     * Creates a payload with the `NOT_CREATED` status.
     */
    public static function notCreated(var messages = null) -> <PayloadContract>
    {
        return (new static())->withStatus(Status::NOT_CREATED)->withMessages(messages);
    }

    /**
     * Creates a payload with the `NOT_DELETED` status.
     */
    public static function notDeleted(var messages = null) -> <PayloadContract>
    {
        return (new static())->withStatus(Status::NOT_DELETED)->withMessages(messages);
    }

    /**
     * Creates a payload with the `NOT_FOUND` status.
     */
    public static function notFound(var messages = null) -> <PayloadContract>
    {
        return (new static())->withStatus(Status::NOT_FOUND)->withMessages(messages);
    }

    /**
     * Creates a payload with the `NOT_UPDATED` status.
     */
    public static function notUpdated(var messages = null) -> <PayloadContract>
    {
        return (new static())->withStatus(Status::NOT_UPDATED)->withMessages(messages);
    }

    /**
     * Creates a payload with the `PROCESSING` status.
     */
    public static function processing(var result = null) -> <PayloadContract>
    {
        return (new static())->withStatus(Status::PROCESSING)->withResult(result);
    }

    /**
     * Creates a payload with the `SUCCESS` status.
     */
    public static function success(var result = null) -> <PayloadContract>
    {
        return (new static())->withStatus(Status::SUCCESS)->withResult(result);
    }

    /**
     * Creates a payload with the `NOT_AUTHENTICATED` status (identity not
     * established - HTTP 401).
     */
    public static function unauthenticated(var messages = null) -> <PayloadContract>
    {
        return (new static())->withStatus(Status::NOT_AUTHENTICATED)->withMessages(messages);
    }

    /**
     * Creates a payload with the `UPDATED` status.
     */
    public static function updated(var result = null) -> <PayloadContract>
    {
        return (new static())->withStatus(Status::UPDATED)->withResult(result);
    }

    /**
     * Creates a payload with the `VALID` status.
     */
    public static function valid(var result = null) -> <PayloadContract>
    {
        return (new static())->withStatus(Status::VALID)->withResult(result);
    }

    /**
     * Returns a copy of the payload with the given exception.
     */
    public function withException(<Throwable> exception) -> <PayloadContract>
    {
        var cloned;

        let cloned            = clone this;
        let cloned->exception = exception;

        return cloned;
    }

    /**
     * Returns a copy of the payload with the given extras.
     */
    public function withExtras(var extras) -> <PayloadContract>
    {
        var cloned;

        let cloned         = clone this;
        let cloned->extras = extras;

        return cloned;
    }

    /**
     * Returns a copy of the payload with the given input.
     */
    public function withInput(var input) -> <PayloadContract>
    {
        var cloned;

        let cloned        = clone this;
        let cloned->input = input;

        return cloned;
    }

    /**
     * Returns a copy of the payload with the given messages.
     */
    public function withMessages(var messages) -> <PayloadContract>
    {
        var cloned;

        let cloned           = clone this;
        let cloned->messages = messages;

        return cloned;
    }

    /**
     * Returns a copy of the payload with the given result.
     */
    public function withResult(var result) -> <PayloadContract>
    {
        var cloned;

        let cloned         = clone this;
        let cloned->result = result;

        return cloned;
    }

    /**
     * Returns a copy of the payload with the given status.
     */
    public function withStatus(var status) -> <PayloadContract>
    {
        var cloned;

        let cloned         = clone this;
        let cloned->status = status;

        return cloned;
    }
}
