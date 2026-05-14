
namespace Phalcon\Session\Exceptions;

use Phalcon\Session\Exception;

class InvalidSessionAdapter extends Exception
{
    public function __construct()
    {
        parent::__construct("The session adapter is not valid");
    }
}
