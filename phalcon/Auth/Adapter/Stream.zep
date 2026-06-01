
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

namespace Phalcon\Auth\Adapter;

use InvalidArgumentException;
use Phalcon\Auth\Adapter\Config\StreamAdapterConfig;
use Phalcon\Auth\Exception;
use Phalcon\Auth\Exceptions\FileCannotRead;
use Phalcon\Auth\Exceptions\FileDoesNotContainJson;
use Phalcon\Auth\Exceptions\FileDoesNotExist;
use Phalcon\Auth\Exceptions\FileNotValidJson;
use Phalcon\Auth\Internal\Options;
use Phalcon\Contracts\Encryption\Security\Security;
use Phalcon\Support\Helper\Json\Decode;

/**
 * JSON file-backed adapter.
 *
 * The file must contain a JSON array of user records:
 *   [{"id":1,"email":"a@b","password":"<hashed>"}, ...]
 *
 * @phpstan-import-type AuthUserRow from AbstractArrayAdapter
 *
 * @extends AbstractArrayAdapter<StreamAdapterConfig>
 */
class Stream extends AbstractArrayAdapter
{
    public function __construct(<Security> hasher, <StreamAdapterConfig> config)
    {
        parent::__construct(hasher, config);
    }

    public static function fromOptions(<Security> hasher, array options) -> <static>
    {
        return new static(
            hasher,
            new StreamAdapterConfig(
                Options::requireString(options, "file", "stream adapter"),
                Options::stringOrNull(options, "model")
            )
        );
    }

    /**
     * Loads and decodes the JSON users file. Re-read on every call — if you
     * need caching, wrap it.
     *
     * @phpstan-return list<AuthUserRow>
     *
     * @throws Exception
     */
    protected function loadUsers() -> array
    {
        var contents, data, path, rows;

        let path = this->config->getFile();

        if (!this->phpFileExists(path)) {
            throw new FileDoesNotExist(path);
        }

        let contents = this->phpFileGetContents(path);

        if (contents === false) {
            throw new FileCannotRead(path);
        }

        try {
            let data = (new Decode())->__invoke(contents, true);
        } catch InvalidArgumentException, ex {
            throw new FileNotValidJson(path, ex);
        }

        if (typeof data !== "array") {
            throw new FileDoesNotContainJson(path);
        }

        /** @var list<AuthUserRow> $rows */
        let rows = array_values(data);

        return rows;
    }

    protected function phpFileExists(string filename) -> bool
    {
        return file_exists(filename);
    }
}
