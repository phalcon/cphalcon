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

namespace Phalcon\Tests\Unit\Db\Dialect;

use Error;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Db\Dialect\Fake\FakeDialect;
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
 * @issue https://github.com/phalcon/phalcon/issues/847
 */
final class ParameterTypesTest extends AbstractUnitTestCase
{
    /**
     * @return array<string, array{0: string, 1: string}>
     */
    public static function getExpressions(): array
    {
        return [
            'From'    => ['getSqlExpressionFrom', 'FROM '],
            'GroupBy' => ['getSqlExpressionGroupBy', 'GROUP BY '],
            'OrderBy' => ['getSqlExpressionOrderBy', 'ORDER BY '],
            'Where'   => ['getSqlExpressionWhere', 'WHERE '],
        ];
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/847
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-25
     */
    public function testDbDialectColumnAndTableInt(): void
    {
        $dialect = $this->getDialect();

        $this->assertSame('"5"', $dialect->getSqlColumn(5, '"'));
        $this->assertSame('"5"', $dialect->getSqlTable(5, '"'));
    }

    /**
     * cphalcon gives the deprecation "Passing null to parameter #1" of type
     * string for a null value.
     *
     * @issue  https://github.com/phalcon/phalcon/issues/847
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-25
     */
    #[IgnoreDeprecations]
    public function testDbDialectColumnAndTableNull(): void
    {
        $dialect = $this->getDialect();

        $this->assertSame('""', $dialect->getSqlColumn(null, '"'));
        $this->assertSame('""', $dialect->getSqlTable(null, '"'));
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/847
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-25
     */
    public function testDbDialectColumnObject(): void
    {
        $this->expectException(TypeError::class);
        $this->expectExceptionMessage(
            'Phalcon\\Db\\Dialect::prepareQualified(): Argument #1 ($column) '
            . 'must be of type string, stdClass given'
        );

        $this->getDialect()->getSqlColumn(new stdClass());
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/847
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-25
     */
    #[DataProvider('getExpressions')]
    public function testDbDialectExpression(string $method, string $prefix): void
    {
        $dialect = $this->getDialect();

        $this->assertSame($prefix, $dialect->call($method, null));
        $this->assertSame($prefix . '5', $dialect->call($method, 5));
    }

    /**
     * cphalcon gives the warning "Trying to access array offset on value of
     * type null" for a value that is not an array.
     *
     * @issue  https://github.com/phalcon/phalcon/issues/847
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-25
     */
    public function testDbDialectExpressionLimit(): void
    {
        $dialect = $this->getDialect();

        set_error_handler(
            static function (): bool {
                return true;
            }
        );

        try {
            $this->assertSame(' LIMIT 0', $dialect->call('getSqlExpressionLimit', null));
            $this->assertSame(' LIMIT 0', $dialect->call('getSqlExpressionLimit', 5));
        } finally {
            restore_error_handler();
        }
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/847
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-25
     */
    public function testDbDialectExpressionObject(): void
    {
        $this->expectException(Error::class);
        $this->expectExceptionMessage('Object of class stdClass could not be converted to string');

        $this->getDialect()->call('getSqlExpressionWhere', new stdClass());
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/847
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-25
     */
    public function testDbDialectTableObject(): void
    {
        $this->expectException(TypeError::class);
        $this->expectExceptionMessage(
            'Phalcon\\Db\\Dialect::escape(): Argument #1 ($str) '
            . 'must be of type string, stdClass given'
        );

        $this->getDialect()->getSqlTable(new stdClass());
    }

    private function getDialect(): FakeDialect
    {
        return new class () extends FakeDialect {
            public function call(string $method, mixed $expression): string
            {
                return $this->$method($expression);
            }
        };
    }
}
