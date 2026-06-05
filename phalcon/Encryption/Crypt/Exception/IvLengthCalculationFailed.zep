
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Encryption\Crypt\Exception;

class IvLengthCalculationFailed extends Exception
{
    public function __construct()
    {
        parent::__construct(
            "Cannot calculate the initialization vector (IV) length of the cipher"
        );
    }
}
