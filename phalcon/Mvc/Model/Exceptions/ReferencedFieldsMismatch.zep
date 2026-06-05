
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

class ReferencedFieldsMismatch extends Exception
{
    public function __construct(string relationType, string entityName, string referencedEntity)
    {
        parent::__construct(
            "Number of referenced fields are not the same in the " . relationType .
            " relation of model '" . entityName . "' with Reference Model '" . referencedEntity . "'"
        );
    }
}
