
namespace Phalcon\Acl\Exceptions;

use Phalcon\Acl\Exception;

class InvalidComponentImplementation extends Exception
{
    public function __construct()
    {
        parent::__construct(
            "Object passed as componentName must implement " .
            "Phalcon\\Acl\\ComponentAwareInterface or Phalcon\\Acl\\ComponentInterface"
        );
    }
}
