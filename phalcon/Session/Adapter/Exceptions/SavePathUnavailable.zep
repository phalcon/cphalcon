
namespace Phalcon\Session\Adapter\Exceptions;

use Phalcon\Session\Exception;

class SavePathUnavailable extends Exception
{
    public function __construct(string path)
    {
        parent::__construct("The session save path [" . path . "] is not writable");
    }
}
