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

use Phalcon\Db\Column;
use Phalcon\Db\ColumnInterface;
use Phalcon\Db\Dialect;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Db\Dialect\Fake\FakeDialect;
use ReflectionMethod;

final class CheckColumnTypeTest extends AbstractUnitTestCase
{
    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/17796
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-25
     */
    public function testDbDialectCheckColumnType(): void
    {
        $dialect = new class () extends FakeDialect {
            public function call(ColumnInterface $column): mixed
            {
                return $this->checkColumnType($column);
            }
        };

        $column = new Column('id', ['type' => Column::TYPE_INTEGER]);
        $this->assertSame(Column::TYPE_INTEGER, $dialect->call($column));

        $method = new ReflectionMethod(Dialect::class, 'checkColumnType');
        $this->assertSame('int', (string) $method->getReturnType());
    }
}
