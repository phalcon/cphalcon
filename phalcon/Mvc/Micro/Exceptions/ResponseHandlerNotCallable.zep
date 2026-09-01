
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

class ResponseHandlerNotCallable extends Exception
{
    public function __construct()
    {
        parent::__construct("Response handler is not callable or is not defined");
    }
}
