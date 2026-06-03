
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by sinbadxiii/cphalcon-auth
 * @link    https://github.com/sinbadxiii/cphalcon-auth
 */

namespace Phalcon\Auth\Adapter\Config;

use Phalcon\Auth\Exception;
use Phalcon\Auth\Exceptions\ConfigRequiresNonEmptyValue;

class StreamAdapterConfig extends AbstractAdapterConfig
{
    /**
     * @var string
     */
    protected file;

    /**
     * @throws Exception
     */
    public function __construct(string file, string model = null)
    {
        if (file === "") {
            throw new ConfigRequiresNonEmptyValue(
                "Stream adapter",
                "file",
                " path"
            );
        }

        let this->file = file;

        parent::__construct(model);
    }

    public function getFile() -> string
    {
        return this->file;
    }
}
