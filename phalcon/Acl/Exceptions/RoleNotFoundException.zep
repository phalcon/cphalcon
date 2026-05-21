
namespace Phalcon\Acl\Exceptions;

use Phalcon\Acl\Exception;

class RoleNotFoundException extends Exception
{
    public function __construct(string roleName)
    {
        parent::__construct(
            "Role '" . roleName . "' (to inherit) does not exist in the role list"
        );
    }
}
