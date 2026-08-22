
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Contracts\Html;

use Closure;

/**
 * Central registry of the array shapes used across the Html namespace.
 *
 * Attribute values stay scalar here. The array member that PSR-13 allows for
 * link attributes lives in the Link registry instead, because the helper
 * pipeline concatenates and escapes every value as a string.
 *
 * @phpstan-type html_attribute_value string|bool|int|float|null
 * @phpstan-type html_attributes array<array-key, html_attribute_value>
 * @phpstan-type html_escaper_attributes array<string, array<array-key, string>|html_attribute_value>
 * @phpstan-type html_escaper_input html_escaper_attributes|string|bool|int|float|null
 * @phpstan-type html_element_arguments array<int, mixed>
 * @phpstan-type html_element_entry array{
 *     0: string,
 *     1: html_element_arguments,
 *     2: string,
 * }
 * @phpstan-type html_element_store array<int, html_element_entry>
 * @phpstan-type html_breadcrumb_attributes array<string, string>
 * @phpstan-type html_breadcrumb_element array{
 *     attributes: html_breadcrumb_attributes,
 *     icon: string,
 *     link: string,
 *     text: string,
 * }
 * @phpstan-type html_breadcrumb_data array<int, html_breadcrumb_element>
 * @phpstan-type html_breadcrumb_elements array<string, string>
 * @phpstan-type html_breadcrumb_template array{
 *     main: string,
 *     line: string,
 *     last: string,
 * }
 * @phpstan-type html_checked_label array{
 *     start: string,
 *     text: html_attribute_value,
 *     end: string,
 * }
 * @phpstan-type html_group_definition html_attributes|string
 * @phpstan-type html_group_options array<array-key, mixed>
 * @phpstan-type html_select_options array<array-key, array<array-key, string>|string>
 * @phpstan-type html_select_attributes array<array-key, html_attributes>
 * @phpstan-type html_select_using array<array-key, string>
 * @phpstan-type html_select_attributes_map array<string, mixed>
 * @phpstan-type html_factory_services array<string, Closure(): object>
 * @phpstan-type html_factory_instances array<string, object>
 */
interface HtmlTypes
{
}
