
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Model\Query\Exceptions;

use Phalcon\Mvc\Model\Exception;

class AmbiguousColumn extends Exception
{
    public function __construct(string name, string phql)
    {
        parent::__construct(
            "The column '"
            . name
            . "' is ambiguous, when preparing: "
            . phql
        );
    }
}
