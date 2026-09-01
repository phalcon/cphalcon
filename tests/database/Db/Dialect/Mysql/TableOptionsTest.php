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

namespace Phalcon\Tests\Database\Db\Dialect\Mysql;

use Phalcon\Db\Dialect\Mysql;
use Phalcon\Tests\AbstractDatabaseTestCase;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class TableOptionsTest extends AbstractDatabaseTestCase
{
    /**
     * Tests Phalcon\Db\Dialect\Mysql :: tableOptions()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testDbDialectMysqlTableOptions(): void
    {
        $dialect = new Mysql();

        $prefix = 'SELECT TABLES.TABLE_TYPE AS table_type,'
            . 'TABLES.AUTO_INCREMENT AS auto_increment,'
            . 'TABLES.ENGINE AS engine,'
            . 'TABLES.TABLE_COLLATION AS table_collation,'
            . 'TABLES.TABLE_COMMENT AS table_comment '
            . 'FROM INFORMATION_SCHEMA.TABLES WHERE ';

        $this->assertSame(
            $prefix
            . "TABLES.TABLE_SCHEMA = 'schema' AND TABLES.TABLE_NAME = 'robots'",
            $dialect->tableOptions('robots', 'schema')
        );

        $this->assertSame(
            $prefix
            . "TABLES.TABLE_SCHEMA = DATABASE() AND TABLES.TABLE_NAME = 'robots'",
            $dialect->tableOptions('robots')
        );
    }
}
