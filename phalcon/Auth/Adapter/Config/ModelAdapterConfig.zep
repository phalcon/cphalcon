
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

use Phalcon\Auth\Adapter\Config\Traits\ModelConfigTrait;
use Phalcon\Auth\Exception;
use Phalcon\Auth\Exceptions\ConfigRequiresNonEmptyValue;
use Phalcon\Contracts\Auth\Adapter\AdapterConfig;

class ModelAdapterConfig implements AdapterConfig
{
    use ModelConfigTrait;

    /**
     * @var string
     */
    protected idColumn = "id";

    /**
     * @throws Exception
     */
    public function __construct(string model, string idColumn = "id")
    {
        if (model === "") {
            throw new ConfigRequiresNonEmptyValue(
                "Model adapter",
                "model",
                " class name"
            );
        }

        if (idColumn === "") {
            throw new ConfigRequiresNonEmptyValue(
                "Model adapter",
                "idColumn"
            );
        }

        let this->idColumn = idColumn,
            this->model    = model;
    }

    public function getIdColumn() -> string
    {
        return this->idColumn;
    }

    public function getModel() -> string
    {
        /** @var string */
        return this->model;
    }
}
