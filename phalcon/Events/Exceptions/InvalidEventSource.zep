
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Events\Exceptions;

use Phalcon\Events\Exception;

class InvalidEventSource extends Exception
{
    public function __construct(string type, string sourceType)
    {
        parent::__construct(
            "The source of " . type . " event must be an object, got " . sourceType
        );
    }
}
