
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

class InvalidUserFilterDefinition extends Exception
{
    public function __construct(string name, string file, int line)
    {
        parent::__construct(
            "Invalid definition for user filter '" . name . "' in " . file . " on line " . line
        );
    }
}
