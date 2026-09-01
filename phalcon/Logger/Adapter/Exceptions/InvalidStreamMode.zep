
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

class InvalidStreamMode extends Exception
{
    public function __construct()
    {
        parent::__construct("Adapter cannot be opened in read mode");
    }
}
