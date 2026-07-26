
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

class MissingEagerKeyColumn extends Exception
{
    public function __construct(string alias, string column)
    {
        parent::__construct(
            "Eager loading the relation '" . alias . "' requires the column '"
            . column . "' to be present in the selected columns"
        );
    }
}
