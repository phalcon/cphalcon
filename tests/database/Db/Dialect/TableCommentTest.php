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

namespace Phalcon\Tests\Database\Db\Dialect;

use Phalcon\Db\Column;
use Phalcon\Db\Dialect\Mysql;
use Phalcon\Db\Dialect\Postgresql;
use Phalcon\Db\Dialect\Sqlite;
use Phalcon\Tests\AbstractDatabaseTestCase;

final class TableCommentTest extends AbstractDatabaseTestCase
{
    private function definition(array $options = []): array
    {
        return [
            'columns' => [
                new Column('id', ['type' => Column::TYPE_INTEGER, 'notNull' => true]),
            ],
            'options' => $options,
        ];
    }

    /**
     * @group mysql
     */
    public function testMysqlCreateTableComment(): void
    {
        $sql = (new Mysql())->createTable(
            'robots',
            '',
            $this->definition(['TABLE_COMMENT' => "it's a robot"])
        );

        $this->assertStringContainsString("COMMENT='it''s a robot'", $sql);
    }

    /**
     * @group mysql
     */
    public function testMysqlTableOptionsSelectsComment(): void
    {
        $sql = (new Mysql())->tableOptions('robots', 'phalcon');

        $this->assertStringContainsString('TABLES.TABLE_COMMENT AS table_comment', $sql);
    }

    /**
     * @group pgsql
     */
    public function testPostgresqlCreateTableComment(): void
    {
        $sql = (new Postgresql())->createTable(
            'robots',
            '',
            $this->definition(['TABLE_COMMENT' => "it's a robot"])
        );

        $this->assertStringContainsString(
            'COMMENT ON TABLE "robots" IS \'it\'\'s a robot\';',
            $sql
        );
    }

    /**
     * @group pgsql
     */
    public function testPostgresqlTableOptionsObjDescription(): void
    {
        $sql = (new Postgresql())->tableOptions('robots', 'reporting');

        $this->assertStringContainsString("obj_description(c.oid, 'pg_class')", $sql);
        $this->assertStringContainsString("n.nspname = 'reporting'", $sql);
    }

    /**
     * @group pgsql
     */
    public function testPostgresqlColumnCommentEscaped(): void
    {
        $definition = [
            'columns' => [
                new Column(
                    'name',
                    ['type' => Column::TYPE_VARCHAR, 'size' => 70, 'comment' => "it's"]
                ),
            ],
        ];

        $sql = (new Postgresql())->createTable('robots', '', $definition);

        $this->assertStringContainsString("IS 'it''s';", $sql);
    }

    /**
     * @group sqlite
     */
    public function testSqliteIgnoresComment(): void
    {
        $sql = (new Sqlite())->createTable(
            'robots',
            '',
            $this->definition(['TABLE_COMMENT' => 'ignored'])
        );

        $this->assertStringNotContainsString('COMMENT', $sql);
    }
}
