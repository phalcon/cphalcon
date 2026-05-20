
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

class DuplicateAlias extends Exception
{
    public function __construct(string name, string phql)
    {
        parent::__construct(
            "Alias '"
            . name
            . "' is used more than once, when preparing: "
            . phql
        );
    }
}
