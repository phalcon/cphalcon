
namespace Phalcon\Image\Exceptions;

use Phalcon\Image\Exception;

class ImageLoadFailed extends Exception
{
    public function __construct(string file)
    {
        parent::__construct("Failed to create image from file " . file);
    }
}
