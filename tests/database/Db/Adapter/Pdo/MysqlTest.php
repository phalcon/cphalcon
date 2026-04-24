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
     * @group sqlite
     */
    public function testDbAdapterPdoMysqlShouldAddForeignKey(
        string $sql,
        bool $expected
    ): void {
        $this->markTestSkipped('Need implementation - foreign_key_child table not in current schema');

        $this->assertEquals(
            $expected,
            $this->connection->execute($sql)
        );
    }

    /**
     * Tests Mysql::getForeignKey
     *
     * @dataProvider getShouldCheckAddedForeignKeyProvider
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/556
     * @author Sergii Svyrydenko <sergey.v.sviridenko@gmail.com>
     * @since  2017-07-03
     * @group  mysql
     * @group sqlite
     */
    public function testDbAdapterPdoMysqlShouldCheckAddedForeignKey(
        string $sql,
        bool $expected
    ): void {
        $this->markTestSkipped('Need implementation - foreign_key_child table not in current schema');

        $actual = $this->connection->execute(
            $sql,
            [
                'MYSQL_ATTR_USE_BUFFERED_QUERY',
            ]
        );

        $this->assertEquals($expected, $actual);
    }

    /**
     * Tests Mysql::dropAddForeignKey
     *
     * @dataProvider getShouldDropForeignKeyProvider
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/556
     * @author Sergii Svyrydenko <sergey.v.sviridenko@gmail.com>
     * @since  2017-07-03
     * @group  mysql
     * @group sqlite
     */
    public function testDbAdapterPdoMysqlShouldDropForeignKey(
        string $sql,
        bool $expected
    ): void {
        $this->markTestSkipped('Need implementation - foreign_key_child table not in current schema');

        $this->assertEquals(
            $expected,
            $this->connection->execute($sql)
        );
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
     * @return array<array{0: string, 1: bool}>
     */
    public static function getShouldCheckAddedForeignKeyProvider(): array
    {
        return [
            [
                self::getForeignKeySql('test_name_key'),
                true,
            ],
            [
                self::getForeignKeySql('foreign_key_child_ibfk_1'),
                true,
            ],
        ];
    }

    /**
     * @return array<array{0: string, 1: bool}>
     */
    public static function getShouldDropForeignKeyProvider(): array
    {
        return [
            [
                'ALTER TABLE `foreign_key_child` DROP FOREIGN KEY test_name_key',
                true,
            ],
            [
                'ALTER TABLE `foreign_key_child` DROP FOREIGN KEY foreign_key_child_ibfk_1',
                true,
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
}
