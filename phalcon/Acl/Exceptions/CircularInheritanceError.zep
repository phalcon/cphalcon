
namespace Phalcon\Acl\Exceptions;

use Phalcon\Acl\Exception;

class CircularInheritanceError extends Exception
{
    public function __construct(string roleName)
    {
        parent::__construct(
            "Role '" . roleName . "' (to inherit) produces an infinite loop"
        );
    }
}
