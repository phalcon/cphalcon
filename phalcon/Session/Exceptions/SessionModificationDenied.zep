
namespace Phalcon\Session\Exceptions;

use Phalcon\Session\Exception;

class SessionModificationDenied extends Exception
{
    public function __construct()
    {
        parent::__construct("Cannot set session name after a session has started");
    }
}
