
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

class ColumnNotInSelectedModels extends Exception
{
    public function __construct(string name, string tag, string phql)
    {
        parent::__construct(
            "Column '"
            . name
            . "' does not belong to any of the selected models ("
            . tag
            . "), when preparing: "
            . phql
        );
    }
}
