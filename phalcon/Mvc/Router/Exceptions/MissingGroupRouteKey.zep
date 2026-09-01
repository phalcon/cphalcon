
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

class MissingGroupRouteKey extends Exception
{
    public function __construct(string key)
    {
        parent::__construct("Group route entry is missing '" . key . "'");
    }
}
