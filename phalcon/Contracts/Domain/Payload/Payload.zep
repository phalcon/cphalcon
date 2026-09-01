
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by phalcon-api and AuraPHP
 * @link    https://github.com/phalcon/phalcon-api
 * @license https://github.com/phalcon/phalcon-api/blob/master/LICENSE
 * @link    https://github.com/auraphp/Aura.Payload
 * @license https://github.com/auraphp/Aura.Payload/blob/3.x/LICENSE
 *
 * @see Original inspiration for the https://github.com/phalcon/phalcon-api
 */

namespace Phalcon\Contracts\Domain\Payload;

/**
 * Canonical combined read/write contract for a domain payload.
 *
 * `Payload` extends both `Writeable` and `Readable`, exposing the full
 * capability set. The intended convention narrows that surface by which side of
 * the Action-Domain-Responder boundary holds the payload: the domain layer
 * builds the payload through `Writeable` (the setters), while the responder
 * consumes the finished payload through `Readable` (the getters). Type-hinting
 * against the narrower contract at each boundary keeps each side to the
 * capability it needs, even though the concrete payload implements both.
 *
 * @see Readable
 * @see Writeable
 */
interface Payload extends Readable, Writeable
{
}
