
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Router\Exceptions;

use Phalcon\Mvc\Router\Exception;

class BeforeMatchNotCallable extends Exception
{
    public function __construct()
    {
        parent::__construct(
            "Before-Match callback is not callable in matched route"
        );
    }
}
