
namespace Phalcon\Image\Exceptions;

use Phalcon\Image\Exception;

class TextRenderingFailed extends Exception
{
    public function __construct()
    {
        parent::__construct("Call to imagettfbbox() failed");
    }
}
