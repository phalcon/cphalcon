
namespace Phalcon\Image\Exceptions;

use Phalcon\Image\Exception;

class ResizeFailed extends Exception
{
    public function __construct()
    {
        parent::__construct("Imagick::liquidRescale failed");
    }
}
