
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

class PropertyNotAccessible extends Exception
{
    public function __construct(string property, string className)
    {
        parent::__construct(
            "Cannot access property '" . property . "' (not public) in '" . className . "'"
        );
    }
}
