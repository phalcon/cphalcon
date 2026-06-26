
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Cli\Console\Exceptions;

use Phalcon\Cli\Console\Exception;

class InvalidModuleDefinition extends Exception
{
    public function __construct(string name = null, string reason = null)
    {
        var message;

        let message = "Invalid module definition";

        if name !== null {
            let message .= " for module '" . name . "'";
        }

        if reason !== null {
            let message .= ": " . reason;
        }

        parent::__construct(message);
    }
}
