
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Contracts\Http;

use Phalcon\Http\Cookie\CookieInterface;
use Phalcon\Http\Request\FileInterface;

/**
 * Central registry of the array shapes used across the Http namespace.
 *
 * @phpstan-type http_bag_items array<array-key, mixed>
 * @phpstan-type http_cookie_options array<string, mixed>
 * @phpstan-type http_cookie_bag array<string, CookieInterface>
 * @phpstan-type http_cookie_definition array{
 *     expire?: int,
 *     path?: string,
 *     domain?: string,
 *     secure?: bool,
 *     httpOnly?: bool,
 *     options?: http_cookie_options,
 * }
 * @phpstan-type http_setcookie_options array{
 *     expires?: int,
 *     path?: string,
 *     domain?: string,
 *     secure?: bool,
 *     httponly?: bool,
 *     samesite?: 'Lax'|'lax'|'None'|'none'|'Strict'|'strict',
 * }
 * @phpstan-type http_response_headers array<string, string|null>
 * @phpstan-type http_request_headers array<string, mixed>
 * @phpstan-type http_basic_auth array{username: string|null, password: string|null}
 * @phpstan-type http_digest_auth array<string, string>
 * @phpstan-type http_quality_part array<string, float|string>
 * @phpstan-type http_parameter_filters array<string, array<string, list<string>>>
 * @phpstan-type http_form_data array<array-key, mixed>
 * @phpstan-type http_php_files array<string, array<string, mixed>>
 * @phpstan-type http_uploaded_file array<string, mixed>
 * @phpstan-type http_uploaded_files array<array-key, FileInterface>
 * @phpstan-type http_smooth_file array{
 *     name: string,
 *     type: mixed,
 *     tmp_name: mixed,
 *     size: mixed,
 *     error: mixed,
 *     key: string,
 * }
 */
interface HttpTypes
{
}
