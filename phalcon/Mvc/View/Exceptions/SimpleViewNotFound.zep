
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\View\Exceptions;

use Phalcon\Mvc\View\Exception;

class SimpleViewNotFound extends Exception
{
    public function __construct(string viewsDirPath)
    {
        parent::__construct(
            "View '" . viewsDirPath . "' was not found in the views directory"
        );
    }
}
