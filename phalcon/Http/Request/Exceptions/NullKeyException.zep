
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Http\Request\Exceptions;

use Phalcon\Http\Request\Exception;

/**
 * Thrown by AbstractBag::offsetSet() when a null offset is used (the
 * ArrayAccess append form). Bags are always string-keyed, so an
 * auto-indexed write could never be addressed by the caller.
 */
class NullKeyException extends Exception
{
    public function __construct()
    {
        parent::__construct(
            "A null key is not allowed; bag elements must be written with a string key."
        );
    }
}
