
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

class PrimaryKeyAttributeNotSet extends Exception
{
    public function __construct(string attribute, string className)
    {
        parent::__construct(
            "Cannot delete the record because the primary key attribute: '" . attribute . "' was not set in '" . className . "'"
        );
    }
}
