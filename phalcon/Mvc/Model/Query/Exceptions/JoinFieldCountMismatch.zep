
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

class JoinFieldCountMismatch extends Exception
{
    public function __construct(string model, string join, string phql)
    {
        parent::__construct(
            "The number of fields must be equal to the number of "
            . "referenced fields in join "
            . model
            . "-"
            . join
            . ", when preparing: "
            . phql
        );
    }
}
