
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Encryption\Crypt\Exception;

class InvalidDecryptLength extends Exception
{
    public function __construct()
    {
        parent::__construct(
            "The provided input is too short for the selected cipher."
        );
    }
}
