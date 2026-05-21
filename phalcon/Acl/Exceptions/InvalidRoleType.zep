
namespace Phalcon\Acl\Exceptions;

use Phalcon\Acl\Exception;

class InvalidRoleType extends Exception
{
    public function __construct()
    {
        parent::__construct("Role must be either a string or implement RoleInterface");
    }
}
