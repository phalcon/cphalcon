
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Cli\Router\Exceptions;

use Phalcon\Cli\Router\Exception;

class RouterArgumentsInvalidType extends Exception
{
    public function __construct()
    {
        parent::__construct("Arguments must be an array or string");
    }
}
