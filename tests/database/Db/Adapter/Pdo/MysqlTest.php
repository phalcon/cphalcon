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

namespace Phalcon\Tests\Database\Db\Adapter\Pdo;

use PDOException;
use Phalcon\Db\Adapter\Pdo\Mysql;
use Phalcon\Tests\AbstractDatabaseTestCase;

use function env;

final class MysqlTest extends AbstractDatabaseTestCase
{
    private const CHILD  = 'foreign_key_child';
    private const PARENT = 'foreign_key_parent';

    /**
     * @var Mysql|null
     */
    private ?Mysql $connection = null;

    /**
     * Executed before each test
     *
     * @return void
     */
    public function setUp(): void
    {
        try {
            $this->connection = new Mysql(
                [
                    'host'     => env('DATA_MYSQL_HOST'),
                    'username' => env('DATA_MYSQL_USER'),
                    'password' => env('DATA_MYSQL_PASS'),
                    'dbname'   => env('DATA_MYSQL_NAME'),
                    'port'     => env('DATA_MYSQL_PORT'),
                    'charset'  => env('DATA_MYSQL_CHARSET'),
                ]
            );
        } catch (PDOException $e) {
            $this->markTestSkipped(
                'Unable to connect to the database: ' . $e->getMessage()
            );
        }

        $this->dropAllForeignKeys();
    }

    public function tearDown(): void
    {
        if ($this->connection !== null) {
            $this->dropAllForeignKeys();
        }
    }

    /**
     * Tests Mysql::addForeignKey
     *
     * @dataProvider getShouldAddForeignKeyProvider
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/556
     * @author Sergii Svyrydenko <sergey.v.sviridenko@gmail.com>
     * @since  2017-07-03
     * @group  mysql
     */
    public function testDbAdapterPdoMysqlShouldAddForeignKey(
        string $sql,
        bool $expected
    ): void {
        $this->assertEquals(
            $expected,
            $this->connection->execute($sql)
        );
    }

    /**
     * Tests Mysql::getForeignKey via information_schema lookup
     *
     * @dataProvider getShouldCheckAddedForeignKeyProvider
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/556
     * @author Sergii Svyrydenko <sergey.v.sviridenko@gmail.com>
     * @since  2017-07-03
     * @group  mysql
     */
    public function testDbAdapterPdoMysqlShouldCheckAddedForeignKey(
        string $addSql,
        string $checkSql
    ): void {
        // Each row is self-contained: add the FK, then verify it shows up
        // in information_schema.REFERENTIAL_CONSTRAINTS with the expected
        // UPDATE/DELETE rules and name.
        $this->connection->execute($addSql);

        $row = $this->connection->fetchOne($checkSql, \Phalcon\Db\Enum::FETCH_NUM);
        $this->assertSame(1, (int) $row[0]);
    }

    /**
     * Tests Mysql::dropForeignKey
     *
     * @dataProvider getShouldDropForeignKeyProvider
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/556
     * @author Sergii Svyrydenko <sergey.v.sviridenko@gmail.com>
     * @since  2017-07-03
     * @group  mysql
     */
    public function testDbAdapterPdoMysqlShouldDropForeignKey(
        string $addSql,
        string $dropSql
    ): void {
        // Self-contained: add the FK first so the drop has something to
        // remove regardless of test ordering.
        $this->connection->execute($addSql);

        $this->assertTrue($this->connection->execute($dropSql));
    }

    /**
     * @return array<array{0: string, 1: bool}>
     */
    public static function getShouldAddForeignKeyProvider(): array
    {
        return [
            [
                self::addForeignKeySql('test_name_key', 'CASCADE', 'RESTRICT'),
                true,
            ],
            [
                self::addForeignKeySql('', 'CASCADE', 'RESTRICT'),
                true,
            ],
        ];
    }

    /**
     * @return array<array{0: string, 1: string}>
     */
    public static function getShouldCheckAddedForeignKeyProvider(): array
    {
        return [
            [
                self::addForeignKeySql('test_name_key', 'CASCADE', 'RESTRICT'),
                self::getForeignKeySql('test_name_key'),
            ],
            [
                self::addForeignKeySql('', 'CASCADE', 'RESTRICT'),
                self::getForeignKeySql('foreign_key_child_ibfk_1'),
            ],
        ];
    }

    /**
     * @return array<array{0: string, 1: string}>
     */
    public static function getShouldDropForeignKeyProvider(): array
    {
        return [
            [
                self::addForeignKeySql('test_name_key', 'CASCADE', 'RESTRICT'),
                'ALTER TABLE `foreign_key_child` DROP FOREIGN KEY test_name_key',
            ],
            [
                self::addForeignKeySql('', 'CASCADE', 'RESTRICT'),
                'ALTER TABLE `foreign_key_child` DROP FOREIGN KEY foreign_key_child_ibfk_1',
            ],
        ];
    }

    /**
     * @param string $foreignKeyName
     * @param string $onUpdate
     * @param string $onDelete
     *
     * @return string
     */
    private static function addForeignKeySql(
        string $foreignKeyName = '',
        string $onUpdate = '',
        string $onDelete = ''
    ): string {
        $sql = 'ALTER TABLE `foreign_key_child` ADD';

        if ($foreignKeyName) {
            $sql .= ' CONSTRAINT `' . $foreignKeyName . '`';
        }

        $sql .= ' FOREIGN KEY (`child_int`) REFERENCES `foreign_key_parent`(`refer_int`)';

        if ($onDelete) {
            $sql .= ' ON DELETE ' . $onDelete;
        }

        if ($onUpdate) {
            $sql .= ' ON UPDATE ' . $onUpdate;
        }

        return $sql;
    }

    /**
     * @param string $foreignKeyName
     *
     * @return string
     */
    private static function getForeignKeySql(string $foreignKeyName): string
    {
        return "SELECT
                COUNT(`CONSTRAINT_NAME`)
            FROM information_schema.REFERENTIAL_CONSTRAINTS
            WHERE TABLE_NAME = 'foreign_key_child' AND
                `UPDATE_RULE` = 'CASCADE' AND
                `DELETE_RULE` = 'RESTRICT' AND
                `CONSTRAINT_NAME` = '{$foreignKeyName}'";
    }

    /**
     * Drop every FK currently defined on foreign_key_child so each test
     * can rely on a clean slate regardless of what previous tests (or
     * previous runs) left behind.
     */
    private function dropAllForeignKeys(): void
    {
        $rows = $this->connection->fetchAll(
            "SELECT CONSTRAINT_NAME FROM information_schema.KEY_COLUMN_USAGE
             WHERE TABLE_SCHEMA = DATABASE()
               AND TABLE_NAME = '" . self::CHILD . "'
               AND REFERENCED_TABLE_NAME IS NOT NULL"
        );

        foreach ($rows as $row) {
            $name = $row['CONSTRAINT_NAME'];
            $this->connection->execute(
                'ALTER TABLE `' . self::CHILD . '` DROP FOREIGN KEY `' . $name . '`'
            );
        }
    }
}
