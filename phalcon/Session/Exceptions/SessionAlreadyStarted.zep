
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

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
