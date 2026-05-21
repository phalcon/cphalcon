
namespace Phalcon\Image\Exceptions;

use Phalcon\Image\Exception;

class MissingWidth extends Exception
{
    public function __construct()
    {
        parent::__construct("Width must be specified");
    }
}
