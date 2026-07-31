
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Model\Exceptions;

use Phalcon\Mvc\Model\Exception;

class UnsupportedEagerOption extends Exception
{
    public function __construct(string option)
    {
        parent::__construct(
            "Eager loading does not support the '" . option . "' option: a "
            . "per-parent limit requires a window function, which PHQL cannot "
            . "express"
        );
    }
}
