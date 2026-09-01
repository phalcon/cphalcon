
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Html\Exceptions;

use Phalcon\Html\Exception;

class ServiceNotRegistered extends Exception
{
    public function __construct(string name)
    {
        parent::__construct("Service " . name . " is not registered");
    }
}
