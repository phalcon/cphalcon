
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
