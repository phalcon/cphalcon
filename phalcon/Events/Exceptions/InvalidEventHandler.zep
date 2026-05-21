
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

class InvalidEventHandler extends Exception
{
    public function __construct()
    {
        parent::__construct("Event handler must be an Object or Callable");
    }
}
