
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

use Phalcon\Contracts\ADR\Payload\Payload as PayloadInterface;

/**
 * Thin, injectable factory mirroring the `Payload` named factories.
 *
 * It exists so that payload creation can be registered as a service in the DI
 * container and substituted in tests, rather than calling the static factories
 * directly.
 */
class PayloadFactory
{
    /**
     * Creates a payload with the `ACCEPTED` status.
     */
    public function accepted(var result = null) -> <PayloadInterface>
    {
        return Payload::accepted(result);
    }

    /**
     * Creates a payload with the `CREATED` status.
     */
    public function created(var result = null) -> <PayloadInterface>
    {
        return Payload::created(result);
    }

    /**
     * Creates a payload with the `DELETED` status.
     */
    public function deleted(var result = null) -> <PayloadInterface>
    {
        return Payload::deleted(result);
    }

    /**
     * Creates a payload with the `ERROR` status.
     */
    public function error(var messages = null) -> <PayloadInterface>
    {
        return Payload::error(messages);
    }

    /**
     * Creates a payload with the `NOT_AUTHORIZED` status (HTTP 403).
     */
    public function forbidden(var messages = null) -> <PayloadInterface>
    {
        return Payload::forbidden(messages);
    }

    /**
     * Creates a payload with the `FOUND` status.
     */
    public function found(var result = null) -> <PayloadInterface>
    {
        return Payload::found(result);
    }

    /**
     * Creates a payload with the `NOT_VALID` status.
     */
    public function invalid(var messages = null) -> <PayloadInterface>
    {
        return Payload::invalid(messages);
    }

    /**
     * Creates a payload with the `NOT_FOUND` status.
     */
    public function notFound(var messages = null) -> <PayloadInterface>
    {
        return Payload::notFound(messages);
    }

    /**
     * Creates a payload with the `PROCESSING` status.
     */
    public function processing(var result = null) -> <PayloadInterface>
    {
        return Payload::processing(result);
    }

    /**
     * Creates a payload with the `SUCCESS` status.
     */
    public function success(var result = null) -> <PayloadInterface>
    {
        return Payload::success(result);
    }

    /**
     * Creates a payload with the `NOT_AUTHENTICATED` status (HTTP 401).
     */
    public function unauthenticated(var messages = null) -> <PayloadInterface>
    {
        return Payload::unauthenticated(messages);
    }

    /**
     * Creates a payload with the `UPDATED` status.
     */
    public function updated(var result = null) -> <PayloadInterface>
    {
        return Payload::updated(result);
    }
}
