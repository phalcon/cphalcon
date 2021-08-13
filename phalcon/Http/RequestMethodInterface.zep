
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Http;

/**
 * Interface for Request methods
 *
 * Implementation of this file has been influenced by PHP FIG
 * @link    https://github.com/php-fig/http-message-util/
 * @license https://github.com/php-fig/http-message-util/blob/master/LICENSE
 */
interface RequestMethodInterface
{
    const METHOD_CONNECT = "CONNECT";
    const METHOD_DELETE  = "DELETE";
    const METHOD_GET     = "GET";
    const METHOD_HEAD    = "HEAD";
    const METHOD_OPTIONS = "OPTIONS";
    const METHOD_PATCH   = "PATCH";
    const METHOD_POST    = "POST";
    const METHOD_PURGE   = "PURGE";
    const METHOD_PUT     = "PUT";
    const METHOD_TRACE   = "TRACE";
}
