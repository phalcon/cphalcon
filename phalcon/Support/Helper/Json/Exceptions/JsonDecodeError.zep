
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Support\Helper\Json\Exceptions;

use InvalidArgumentException;
use Throwable;

class JsonDecodeError extends InvalidArgumentException
{
    public function __construct(string message = "", int code = 0, <Throwable> previous = null)
    {
        parent::__construct("json_decode error: " . message, code, previous);
    }
}
