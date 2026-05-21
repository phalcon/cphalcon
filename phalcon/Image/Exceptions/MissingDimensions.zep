
namespace Phalcon\Image\Exceptions;

use Phalcon\Image\Exception;

class MissingDimensions extends Exception
{
    public function __construct()
    {
        parent::__construct("Width and height must be specified");
    }
}
