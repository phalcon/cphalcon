
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

class ColumnNotInMap extends Exception
{
    public function __construct(string column, string className)
    {
        parent::__construct(
            "Column '" . column . "' does not make part of the column map in '" . className . "'"
        );
    }
}
