
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Micro\Exceptions;

use Phalcon\Mvc\Micro\Exception;

class LazyHandlerNotFound extends Exception
{
    public function __construct(string definition)
    {
        parent::__construct("Handler '" . definition . "' does not exist");
    }
}
