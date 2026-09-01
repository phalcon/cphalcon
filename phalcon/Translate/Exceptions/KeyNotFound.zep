
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Translate\Exceptions;

use Phalcon\Translate\Exception;

class KeyNotFound extends Exception
{
    public function __construct(string key)
    {
        parent::__construct(
            "Cannot find translation key: " . key
        );
    }
}
