
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Html\Exceptions;

use InvalidArgumentException;

class InvalidResultsetValue extends InvalidArgumentException
{
    public function __construct()
    {
        parent::__construct("Resultset returned an invalid value");
    }
}
