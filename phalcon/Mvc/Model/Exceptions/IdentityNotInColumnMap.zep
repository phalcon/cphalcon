
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

class IdentityNotInColumnMap extends Exception
{
    public function __construct(string identityField, string className)
    {
        parent::__construct(
            "Identity column '" . identityField . "' isn't part of the column map in '" . className . "'"
        );
    }
}
