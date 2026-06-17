
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

namespace Phalcon\Domain\Payload;

/**
 * This interface is used for consumers
 *
 * `PayloadInterface` extends both `WriteableInterface` and `ReadableInterface`,
 * exposing the full capability set. The intended convention narrows that
 * surface by which side of the Action-Domain-Responder boundary holds the
 * payload: the domain layer builds the payload through `WriteableInterface`
 * (the setters), while the responder consumes the finished payload through
 * `ReadableInterface` (the getters). Type-hinting against the narrower
 * interface at each boundary keeps each side to the capability it needs, even
 * though `Payload` implements both.
 *
 * @see ReadableInterface
 * @see WriteableInterface
 */
interface PayloadInterface extends ReadableInterface, WriteableInterface
{
}
