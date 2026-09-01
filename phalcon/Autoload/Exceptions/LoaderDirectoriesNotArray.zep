
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Autoload\Exceptions;

use Phalcon\Autoload\Exception;

class LoaderDirectoriesNotArray extends Exception
{
    public function __construct(string name = "")
    {
        var message;

        let message = "The directories parameter is not a string or array";

        if ("" !== name) {
            let message .= " for the '" . name . "' namespace";
        }

        parent::__construct(message);
    }
}
