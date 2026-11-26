<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Support;

use InvalidArgumentException;
use Phalcon\Auth\Adapter\AdapterLocator;
use Phalcon\Db\Adapter\Pdo\Sqlite;
use Phalcon\Db\Dialect\Sqlite as SqliteDialect;
use Phalcon\Support\Collection;
use Phalcon\Support\Debug\Report\BacktraceItem;
use Phalcon\Support\Helper\Arr\Filter;
use Phalcon\Support\Helper\Arr\First;
use Phalcon\Support\Helper\Arr\FirstKey;
use Phalcon\Support\Helper\Arr\Last;
use Phalcon\Support\Helper\Arr\LastKey;
use Phalcon\Support\Helper\Arr\Order;
use Phalcon\Support\Helper\Arr\Set;
use Phalcon\Support\Helper\Arr\ValidateAll;
use Phalcon\Support\Helper\Arr\ValidateAny;
use Phalcon\Support\Helper\Str\Exceptions\InvalidReplaceFormat;
use Phalcon\Support\Helper\Str\Friendly;
use Phalcon\Support\Settings;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use PHPUnit\Framework\Attributes\DataProvider;
use PHPUnit\Framework\Attributes\IgnoreDeprecations;
use stdClass;
use TypeError;

use function restore_error_handler;
use function set_error_handler;

/**
 * cphalcon accepts a value of any type for these parameters. The method body
 * examines the value.
 *
 * @issue https://github.com/phalcon/phalcon/issues/846
 */
final class ParameterTypesTest extends AbstractUnitTestCase
{
    private const LOCATOR_MESSAGE = 'The parameter must be an instance of Collection or DiInterface';

    private const ORDER_ITEMS = [
        ['' => 'e1', 5 => 'b'],
        ['' => 'e2', 5 => 'a'],
    ];

    private const REPLACE_MESSAGE = 'Parameter replace must be an array or a string';

    public function tearDown(): void
    {
        Settings::reset();
    }

    /**
     * @return array<string, array{0: class-string, 1: mixed, 2: mixed}>
     */
    public static function getArrHelpers(): array
    {
        return [
            'Filter string'      => [Filter::class, 'x', [1, 'a', 2]],
            'First string'       => [First::class, 'x', 1],
            'FirstKey string'    => [FirstKey::class, 'x', 0],
            'Last string'        => [Last::class, 'x', 2],
            'LastKey string'     => [LastKey::class, 'x', 2],
            'ValidateAll null'   => [ValidateAll::class, null, true],
            'ValidateAll string' => [ValidateAll::class, 'x', true],
            'ValidateAny null'   => [ValidateAny::class, null, true],
            'ValidateAny string' => [ValidateAny::class, 'x', true],
        ];
    }

    /**
     * @return array<string, array{0: mixed, 1: array<array-key, string>}>
     */
    public static function getSetIndexes(): array
    {
        return [
            'null' => [null, ['a' => 'A', 0 => 'zero', 1 => 'v']],
            'true' => [true, ['a' => 'A', 0 => 'zero', 1 => 'v']],
        ];
    }

    /**
     * @return array<string, array{0: string, 1: mixed, 2: mixed}>
     */
    public static function getSettings(): array
    {
        return [
            'force casting string'   => ['db.force_casting', '1', '1'],
            'force casting null'     => ['db.force_casting', null, false],
            'escape string'          => ['db.escape_identifiers', '0', '0'],
            'cache level string'     => ['orm.cache_level', 'abc', 'abc'],
            'events null'            => ['orm.events', null, true],
            'unknown key string'     => ['unknown.key', '1', null],
        ];
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/846
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-25
     */
    #[DataProvider('getArrHelpers')]
    public function testSupportArrHelpers(string $class, mixed $method, mixed $expected): void
    {
        $helper = new $class();

        $this->assertSame($expected, $helper([1, 'a', 2], $method));
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/846
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-25
     */
    public function testSupportArrOrderArray(): void
    {
        $this->expectException(TypeError::class);
        $this->expectExceptionMessage(
            'Phalcon\\Support\\Helper\\Arr\\Order::checkObject(): Argument #2 ($attribute) '
            . 'must be of type string, array given'
        );

        (new Order())(self::ORDER_ITEMS, ['a']);
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/846
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-25
     */
    public function testSupportArrOrderInt(): void
    {
        $this->assertSame(
            [self::ORDER_ITEMS[1], self::ORDER_ITEMS[0]],
            (new Order())(self::ORDER_ITEMS, 5)
        );
    }

    /**
     * cphalcon gives the deprecation "Passing null to parameter #2
     * ($attribute) of type string" for a null attribute.
     *
     * @issue  https://github.com/phalcon/phalcon/issues/846
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-25
     */
    #[IgnoreDeprecations]
    public function testSupportArrOrderNull(): void
    {
        $this->assertSame(self::ORDER_ITEMS, (new Order())(self::ORDER_ITEMS, null));
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/846
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-25
     *
     * @param array<array-key, string> $expected
     */
    #[DataProvider('getSetIndexes')]
    public function testSupportArrSet(mixed $index, array $expected): void
    {
        $this->assertSame(
            $expected,
            (new Set())(['a' => 'A', 0 => 'zero'], 'v', $index)
        );
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/846
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-25
     */
    public function testSupportArrSetObject(): void
    {
        $this->expectException(TypeError::class);

        (new Set())([], 'v', new stdClass());
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/846
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-25
     */
    public function testSupportBacktraceItemFragment(): void
    {
        $item = new BacktraceItem('f', null, null, null, null, false, [], null, null, null);
        $this->assertNull($item->getFragment());

        $this->expectException(TypeError::class);
        $this->expectExceptionMessage(
            'Cannot assign string to property '
            . 'Phalcon\\Support\\Debug\\Report\\BacktraceItem::$fragment of type ?array'
        );

        new BacktraceItem('f', null, null, null, null, false, [], null, null, 'x');
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/846
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-25
     */
    public function testSupportCollectionSort(): void
    {
        $collection = new Collection(['b' => 2, 'a' => 1]);

        $this->assertSame(['a' => 1, 'b' => 2], $collection->sort(null)->toArray());

        $this->expectException(InvalidArgumentException::class);
        $this->expectExceptionMessage('The sort callback must be callable or null');

        $collection->sort('x');
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/846
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-25
     */
    public function testSupportDbSetupString(): void
    {
        Sqlite::setup(['forceCasting' => '1', 'escapeSqlIdentifiers' => '0']);

        $this->assertSame('1', Settings::get('db.force_casting'));
        $this->assertSame('0', Settings::get('db.escape_identifiers'));
        $this->assertSame('a', (new SqliteDialect())->escape('a'));

        Settings::set('db.escape_identifiers', 1);

        $this->assertSame('"a"', (new SqliteDialect())->escape('a'));
        $this->assertSame('"a"', (new SqliteDialect())->escapeSchema('a'));
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/846
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-25
     */
    public function testSupportFriendlyReplace(): void
    {
        $friendly = new Friendly();

        $this->assertSame('hello-world-5', $friendly('Hello World 5', '-', true, null));
        $this->assertSame('hello-world-5', $friendly('Hello World 5', '-', true, false));

        $this->expectException(InvalidReplaceFormat::class);
        $this->expectExceptionMessage(self::REPLACE_MESSAGE);

        $friendly('Hello World 5', '-', true, 5);
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/846
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-25
     */
    public function testSupportLocatorNull(): void
    {
        $this->expectException(TypeError::class);
        $this->expectExceptionMessage(self::LOCATOR_MESSAGE);

        /**
         * cphalcon also gives the warning "instanceof expects an object
         * instance" for a value that is not an object
         */
        set_error_handler(
            static function (): bool {
                return true;
            }
        );

        try {
            new AdapterLocator(null);
        } finally {
            restore_error_handler();
        }
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/846
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-25
     */
    public function testSupportLocatorObject(): void
    {
        $this->expectException(TypeError::class);
        $this->expectExceptionMessage(self::LOCATOR_MESSAGE);

        new AdapterLocator(new stdClass());
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/846
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-25
     */
    #[DataProvider('getSettings')]
    public function testSupportSettings(string $key, mixed $value, mixed $expected): void
    {
        Settings::set($key, $value);

        $this->assertSame($expected, Settings::get($key));
    }
}
