
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Encryption\Security\Exceptions;

use Phalcon\Encryption\Security\Exception;

class UnknownHashAlgorithm extends Exception
{
    public function __construct(string algo)
    {
        parent::__construct("Unknown hashing algorithm: " . algo);
    }
}
