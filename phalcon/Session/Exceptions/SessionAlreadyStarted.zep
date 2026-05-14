
namespace Phalcon\Session\Exceptions;

use Phalcon\Session\Exception;

class SessionAlreadyStarted extends Exception
{
    public function __construct()
    {
        parent::__construct(
            "The session has already been started. To change the id, use regenerateId()"
        );
    }
}
