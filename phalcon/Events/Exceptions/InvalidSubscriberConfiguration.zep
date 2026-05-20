
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

class InvalidSubscriberConfiguration extends Exception
{
    public function __construct(string eventName)
    {
        parent::__construct(
            "Invalid event subscriber configuration for " . eventName
        );
    }
}
