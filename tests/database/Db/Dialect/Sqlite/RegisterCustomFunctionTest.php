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

namespace Phalcon\Tests\Database\Db\Dialect\Sqlite;

use Error;
use Phalcon\Db\Dialect\Sqlite;
use Phalcon\Tests\AbstractDatabaseTestCase;
use PHPUnit\Framework\Attributes\DataProvider;
use PHPUnit\Framework\Attributes\Group;
use stdClass;
use Throwable;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class RegisterCustomFunctionTest extends AbstractDatabaseTestCase
{
    /**
     * A value that cannot be called and the cphalcon message.
     *
     * @return array<string, array{0: mixed, 1: string}>
     */
    public static function getNotCallableValues(): array
    {
        return [
            'string' => ['nope', 'Call to undefined function nope()'],
            'array'  => [[new stdClass(), 'missing'], 'Call to undefined method stdClass::missing()'],
            'object' => [new stdClass(), 'Call to undefined function undefined()'],
            'int'    => [5, 'Call to undefined function undefined()'],
        ];
    }

    /**
     * Tests Phalcon\Db\Dialect\Sqlite :: registerCustomFunction()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testDbDialectSqliteRegisterCustomFunction(): void
    {
        $dialect = new Sqlite();

        $returned = $dialect->registerCustomFunction(
            'MYFUNC',
            function ($dialect, $expression) {
                return 'MYFUNC()';
            }
        );

        $this->assertSame($dialect, $returned);

        $functions = $dialect->getCustomFunctions();

        $this->assertArrayHasKey('MYFUNC', $functions);
        $this->assertIsCallable($functions['MYFUNC']);
    }

    /**
     * A custom function that cannot be called is registered. The SQL of the
     * function call throws Error with the cphalcon message.
     *
     * @issue  https://github.com/phalcon/phalcon/issues/818
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-16
     */
    #[DataProvider('getNotCallableValues')]
    public function testDbDialectSqliteRegisterCustomFunctionNotCallable(
        mixed $value,
        string $expected
    ): void {
        $dialect = new Sqlite();
        $dialect->registerCustomFunction('FOO', $value);

        $actual = null;
        try {
            $dialect->getSqlExpression(['type' => 'functionCall', 'name' => 'FOO']);
        } catch (Throwable $ex) {
            $actual = [$ex::class, $ex->getMessage()];
        }

        $this->assertSame([Error::class, $expected], $actual);
    }
}
