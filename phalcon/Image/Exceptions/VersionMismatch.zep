
namespace Phalcon\Image\Exceptions;

use Phalcon\Image\Exception;

class VersionMismatch extends Exception
{
    public function __construct(string version)
    {
        parent::__construct(
            "Phalcon\\Image\\Adapter\\GD requires GD version '2.0.1' or greater, you have " . version
        );
    }
}
