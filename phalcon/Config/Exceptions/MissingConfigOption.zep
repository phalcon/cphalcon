
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

class MissingConfigOption extends Exception
{
    /**
     * @var string
     */
    private option;

    public function __construct(string option)
    {
        let this->option = option;

        parent::__construct(
            "You must provide '" . option . "' option in factory config parameter."
        );
    }

    public function getOption() -> string
    {
        return this->option;
    }
}
