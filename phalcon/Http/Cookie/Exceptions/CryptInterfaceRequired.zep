
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Http\Cookie\Exceptions;

use Phalcon\Http\Cookie\Exception;

class CryptInterfaceRequired extends Exception
{
    public function __construct()
    {
        parent::__construct(
            "A dependency which implements CryptInterface is required to use encryption"
        );
    }
}
