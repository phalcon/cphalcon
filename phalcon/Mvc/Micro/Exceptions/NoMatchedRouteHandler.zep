
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

class NoMatchedRouteHandler extends Exception
{
    public function __construct()
    {
        parent::__construct("Matched route does not have an associated handler");
    }
}
