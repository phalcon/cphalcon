
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\View\Engine\Volt\Exceptions;

use Phalcon\Mvc\View\Engine\Volt\Exception;

class InvalidStatement extends Exception
{
    public function __construct(string file, int line, array statement)
    {
        parent::__construct(
            "Invalid statement in " . file . " on line " . line,
            statement
        );
    }
}
