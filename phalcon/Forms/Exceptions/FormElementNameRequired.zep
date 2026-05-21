
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Forms\Exceptions;

use InvalidArgumentException;

class FormElementNameRequired extends InvalidArgumentException
{
    public function __construct()
    {
        parent::__construct("Form element name is required");
    }
}
