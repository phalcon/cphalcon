
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

namespace Phalcon\Dispatcher\Exceptions;

use Phalcon\Dispatcher\Exception;

class ForwardInInitializeForbidden extends Exception
{
    public function __construct()
    {
        parent::__construct(
            "Forwarding inside a controller's initialize() method is forbidden"
        );
    }
}
