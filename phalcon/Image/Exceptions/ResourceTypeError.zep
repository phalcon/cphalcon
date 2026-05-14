
namespace Phalcon\Image\Exceptions;

use Phalcon\Image\Exception;

class ResourceTypeError extends Exception
{
    public function __construct()
    {
        parent::__construct("Cannot set the Resource Type for this image");
    }
}
