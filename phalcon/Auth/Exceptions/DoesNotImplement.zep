
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by sinbadxiii/cphalcon-auth
 * @link    https://github.com/sinbadxiii/cphalcon-auth
 */

namespace Phalcon\Auth\Exceptions;

use Phalcon\Auth\Exception;

/**
 * Does not implement interface
 */
class DoesNotImplement extends Exception
{
    public function __construct(string type, string name)
    {
        parent::__construct(
            type . " does not implement '" . name . "'"
        );
    }

    /**
     * Throws when value is not an instance of the given interface. Keeps the
     * "must implement" guard shared across adapters, guards and the manager
     * in one place.
     *
     * @throws self
     */
    public static function assert(var value, var interfaceName, string type, string name) -> void
    {
        if (!is_object(value) || !(value instanceof interfaceName)) {
            throw new self(type, name);
        }
    }
}
