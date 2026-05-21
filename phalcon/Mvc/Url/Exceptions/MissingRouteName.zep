
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Url\Exceptions;

use Phalcon\Mvc\Url\Exception;

class MissingRouteName extends Exception
{
    public function __construct()
    {
        parent::__construct(
            "It's necessary to define the route name with the parameter 'for'"
        );
    }
}
