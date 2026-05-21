
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Encryption\Crypt\Exception;

class UnsupportedAlgorithm extends Exception
{
    public function __construct(string type, string cipher)
    {
        parent::__construct(
            "The " . type . " algorithm '" . cipher . "' is not supported on this system."
        );
    }
}
