
namespace Phalcon\Image\Exceptions;

use Phalcon\Image\Exception;

class MissingHeight extends Exception
{
    public function __construct()
    {
        parent::__construct("Height must be specified");
    }
}
