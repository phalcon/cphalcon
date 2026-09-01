
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Logger\Exceptions;

use Phalcon\Logger\Exception;

class AdapterNotFound extends Exception
{
    public function __construct(string name)
    {
        parent::__construct("Adapter does not exist for this logger: " . name);
    }
}
