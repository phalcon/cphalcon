
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Config\Exceptions;

use Phalcon\Config\Exception;

class GroupedAdapterRequiresArray extends Exception
{
    public function __construct()
    {
        parent::__construct(
            "To use 'array' adapter you have to specify the 'config' as an array."
        );
    }
}
