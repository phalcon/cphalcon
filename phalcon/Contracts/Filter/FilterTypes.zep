
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Contracts\Filter;

use Phalcon\Filter\Validation\ValidatorInterface;

/**
 * Central registry of the array shapes used across the Filter namespace.
 *
 * @phpstan-type filter_mapper array<string, class-string<Sanitizer>|Sanitizer>
 * @phpstan-type filter_sanitizer_params array<array-key, mixed>
 * @phpstan-type filter_sanitizers array<array-key, array<array-key, mixed>|string>
 * @phpstan-type filter_sanitizer_split array{0: string, 1: filter_sanitizer_params}
 * @phpstan-type filter_services array<string, Sanitizer>
 * @phpstan-type filter_values array<array-key, mixed>
 * @phpstan-type filter_uploaded_file array{
 *     name: string,
 *     type: string,
 *     tmp_name: string,
 *     error: int,
 *     size: int,
 * }
 * @phpstan-type filter_validation_combined_validators array<array-key, mixed>
 * @phpstan-type filter_validation_data array<array-key, mixed>|object|null
 * @phpstan-type filter_validation_default_messages array<string, string>
 * @phpstan-type filter_validation_filters array<string, mixed>
 * @phpstan-type filter_validation_labels array<string, string>
 * @phpstan-type filter_validation_validators array<array-key, array<array-key, mixed>>
 * @phpstan-type filter_validation_values array<string, mixed>
 * @phpstan-type filter_validation_whitelist array<array-key, string>
 * @phpstan-type filter_validator_options array<array-key, mixed>
 * @phpstan-type filter_validator_replacements array<string, mixed>
 * @phpstan-type filter_validator_services array<string, string>
 * @phpstan-type filter_validator_templates array<string, string>
 * @phpstan-type filter_validators list<ValidatorInterface>
 * @phpstan-type filter_uniqueness_column_map array<string, string>
 * @phpstan-type filter_uniqueness_fields array<array-key, string>
 * @phpstan-type filter_uniqueness_params array{conditions: string, bind: list<mixed>}
 * @phpstan-type filter_uniqueness_values array<string, mixed>
 */
interface FilterTypes
{
}
