
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Model\Exceptions;

use Phalcon\Mvc\Model\Exception;

class StaticMethodRequiresOneArgument extends Exception
{
    public function __construct(string method, string className)
    {
        parent::__construct(
            "The static method '" . method . "' in '" . className . "' requires one argument"
        );
    }
}
