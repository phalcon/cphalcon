
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Assets\Exceptions;

use Phalcon\Assets\Exception;

class CollectionNotFound extends Exception
{
    public function __construct(string name = "")
    {
        var message;

        let message = "The collection does not exist in the manager";

        if (name !== "") {
            let message = "The collection '" . name . "' does not exist in the manager";
        }

        parent::__construct(message);
    }
}
