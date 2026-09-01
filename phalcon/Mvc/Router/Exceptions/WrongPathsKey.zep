
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

class WrongPathsKey extends Exception
{
    public function __construct(string part)
    {
        parent::__construct("Wrong key in paths: " . part);
    }
}
