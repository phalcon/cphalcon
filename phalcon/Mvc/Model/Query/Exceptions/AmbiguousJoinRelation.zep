
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

class AmbiguousJoinRelation extends Exception
{
    public function __construct(string from, string join, string phql)
    {
        parent::__construct(
            "There is more than one relation between models '"
            . from
            . "' and '"
            . join
            . "', the join must be done using an alias, when preparing: "
            . phql
        );
    }
}
