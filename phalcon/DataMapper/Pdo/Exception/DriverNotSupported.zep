
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\DataMapper\Pdo\Exception;

use InvalidArgumentException;

class DriverNotSupported extends InvalidArgumentException
{
    public function __construct(string driver)
    {
        parent::__construct("Driver not supported [" . driver . "]");
    }
}
