
namespace Phalcon\Acl\Exceptions;

use Phalcon\Acl\Exception;

class InvalidAccessList extends Exception
{
    public function __construct()
    {
        parent::__construct("Invalid value for the accessList");
    }
}
