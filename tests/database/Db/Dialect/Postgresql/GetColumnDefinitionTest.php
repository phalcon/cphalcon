<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Database\Db\Dialect\Postgresql;

use Phalcon\Db\Column;
use Phalcon\Db\Dialect\Postgresql;
use Phalcon\Tests\AbstractDatabaseTestCase;
use PHPUnit\Framework\Attributes\DataProvider;

final class GetColumnDefinitionTest extends AbstractDatabaseTestCase
{
    /**
     * @return array[]
     */
    public static function getPostgresqlData(): array
    {
        return [
            [
                [
                    'type'      => Column::TYPE_UUID,
                    'isNumeric' => false,
                    'size'      => 0,
                    'unsigned'  => false,
                ],
                'UUID',
            ],
        ];
    }

    /**
     * Tests Phalcon\Db\Dialect\Postgresql :: getColumnDefinition - uuid
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2025-04-29
     *
     * @group pgsql
     */
    #[DataProvider('getPostgresqlData')]
    public function testDbDialectPostgresqlGetColumnDefinition(
        array $definition,
        string $expected
    ): void {
        $dialect = new Postgresql();
        $column  = new Column('column_name', $definition);

        $actual = $dialect->getColumnDefinition($column);
        $this->assertSame($expected, $actual);
    }
}
