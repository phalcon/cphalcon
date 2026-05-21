
namespace Phalcon\Session\Adapter\Exceptions;

use Phalcon\Session\Exception;

class InvalidSavePath extends Exception
{
    public function __construct()
    {
        parent::__construct("The session save path cannot be empty");
    }
}
