
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Http\Cookie\Exceptions;

use Phalcon\Http\Cookie\Exception;

class CookieKeyTooShort extends Exception
{
    public function __construct(int length)
    {
        parent::__construct(
            "The cookie's key should be at least 32 characters long. Current length is " . length . "."
        );
    }
}
