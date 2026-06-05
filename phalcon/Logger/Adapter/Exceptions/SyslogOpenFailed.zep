
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Logger\Adapter\Exceptions;

use Phalcon\Logger\Exception;

class SyslogOpenFailed extends Exception
{
    public function __construct(string name, int facility)
    {
        parent::__construct(
            "Cannot open syslog for name [" . name . "] and facility [" . facility . "]"
        );
    }
}
