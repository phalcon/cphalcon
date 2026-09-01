
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Di\Exceptions;

use Phalcon\Di\Exception;

class MethodCallMustBeArray extends Exception
{
    public function __construct(int position)
    {
        parent::__construct(
            "Method call must be an array on position " . position
        );
    }
}
