
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Messages\Exceptions;

use Phalcon\Messages\Exception;

class MessageNotObject extends Exception
{
    public function __construct()
    {
        parent::__construct("The message must be an instance of MessageInterface");
    }
}
