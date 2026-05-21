
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

class RelationshipNotFound extends Exception
{
    public function __construct(string model, string relationship, string phql)
    {
        parent::__construct(
            "Cannot find a relationship between '"
            . model
            . "' and '"
            . relationship
            . "' when preparing: "
            . phql
        );
    }
}
