
namespace Phalcon\Session\Exceptions;

use Phalcon\Session\Exception;

class InvalidSessionName extends Exception
{
    public function __construct()
    {
        parent::__construct("The name contains non alphanum characters");
    }
}
