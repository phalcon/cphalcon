
namespace Phalcon\Image\Exceptions;

use Phalcon\Image\Exception;

class CompositeFailed extends Exception
{
    public function __construct()
    {
        parent::__construct("Imagick::compositeImage failed");
    }
}
