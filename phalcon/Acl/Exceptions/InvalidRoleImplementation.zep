
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

class InvalidRoleImplementation extends Exception
{
    public function __construct()
    {
        parent::__construct(
            "Object passed as roleName must implement " .
            "Phalcon\\Acl\\RoleAwareInterface or Phalcon\\Acl\\RoleInterface"
        );
    }
}
