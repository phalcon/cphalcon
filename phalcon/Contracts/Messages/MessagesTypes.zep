/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Contracts\Messages;

use Phalcon\Messages\MessageInterface;

/**
 * Central registry of the array shapes used across the Messages namespace.
 *
 * This is a type registry, not a contract. It declares no members and must
 * not be implemented; it exists only so that every shape below has a single
 * definition, imported where it is needed with a phpstan-import-type tag
 * naming this interface as the source.
 *
 * Alias names are prefixed with `messages_` because PHPStan resolves imported
 * type names per file and has no namespacing for them: the prefix is what
 * keeps generic names such as `metadata` from clashing with an alias imported
 * from another namespace into the same file.
 *
 * @phpstan-type messages_list array<array-key, MessageInterface>
 * @phpstan-type messages_metadata array<array-key, mixed>
 * @phpstan-type messages_message array{
 *     code: int,
 *     field: string,
 *     message: string,
 *     metaData: messages_metadata,
 *     type: string,
 * }
 * @phpstan-type messages_serialized array<array-key, mixed>
 */
interface MessagesTypes
{
}
