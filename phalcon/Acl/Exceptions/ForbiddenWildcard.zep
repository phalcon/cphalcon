
namespace Phalcon\Acl\Exceptions;

use Phalcon\Acl\Exception;

class ForbiddenWildcard extends Exception
{
    public function __construct(string elementType)
    {
        parent::__construct("The " . elementType . " name cannot be '*'");
    }
}
