
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\DataMapper\Pdo\Exception;

use BadMethodCallException;

class UnknownQueryMethod extends BadMethodCallException
{
    public function __construct(string method)
    {
        parent::__construct("Unknown method: [" . method . "]");
    }
}
