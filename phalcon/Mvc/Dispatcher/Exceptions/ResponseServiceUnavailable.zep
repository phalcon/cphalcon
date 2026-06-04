
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Dispatcher\Exceptions;

use Phalcon\Mvc\Dispatcher\Exception;

class ResponseServiceUnavailable extends Exception
{
    public function __construct()
    {
        parent::__construct(
            "A dependency injection container is required to access the 'response' service",
            Exception::EXCEPTION_NO_DI
        );
    }
}
