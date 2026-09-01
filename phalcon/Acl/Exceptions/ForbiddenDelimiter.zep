/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Acl\Exceptions;

use Phalcon\Acl\Exception;

/**
 * The "!" character separates the role, component and access parts of the
 * internal ACL keys, so a name that contains it would make two different
 * tuples share one key.
 */
class ForbiddenDelimiter extends Exception
{
    public function __construct(string elementType)
    {
        parent::__construct("The " . elementType . " name cannot contain '!'");
    }
}
