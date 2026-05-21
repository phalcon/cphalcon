
namespace Phalcon\Acl\Exceptions;

use Phalcon\Acl\Exception;

class AccessRuleNotFound extends Exception
{
    public function __construct(string accessName, string componentName)
    {
        parent::__construct(
            "Access '" . accessName . "' does not exist in component '" . componentName . "'"
        );
    }
}
