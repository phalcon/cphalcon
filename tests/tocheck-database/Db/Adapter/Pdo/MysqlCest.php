<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Tests\Integration\Db\Adapter\Pdo;

use Codeception\Example;
use IntegrationTester;
use PDOException;
use Phalcon\Db\Adapter\Pdo\Mysql;
use Phalcon\Tests\Integration\Db\Dialect\Helper\MysqlHelper;

class MysqlCest extends MysqlHelper
{
    /**
     * @var Mysql
     */
    protected $connection;

    public function _before(IntegrationTester $I)
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
            $I->skipTest(
                'Unable to connect to the database: ' . $e->getMessage()
            );
        }
    }

    /**
     * Tests Mysql::addForeignKey
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/556
     * @author       Sergii Svyrydenko <sergey.v.sviridenko@gmail.com>
     * @since        2017-07-03
     *
     * @dataProvider shouldAddForeignKeyProvider
     */
    public function shouldAddForeignKey(IntegrationTester $I, Example $example)
    {
        $I->assertEquals(
            $example['expected'],
            $this->connection->execute(
                $example['sql']
            )
        );
    }

    /**
     * Tests Mysql::getForeignKey
     *
     * @test
     * @issue  https://github.com/phalcon/cphalcon/issues/556
     * @author       Sergii Svyrydenko <sergey.v.sviridenko@gmail.com>
     * @since        2017-07-03
     *
     * @dataProvider shouldCheckAddedForeignKeyProvider
     */
    public function shouldCheckAddedForeignKey(IntegrationTester $I, Example $example)
    {
        $actual = $this->connection->execute(
            $example['sql'],
            [
                'MYSQL_ATTR_USE_BUFFERED_QUERY',
            ]
        );

        $I->assertEquals(
            $example['expected'],
            $actual
        );
    }

    /**
     * Tests Mysql::dropAddForeignKey
     *
     * @test
     * @issue  https://github.com/phalcon/cphalcon/issues/556
     * @author       Sergii Svyrydenko <sergey.v.sviridenko@gmail.com>
     * @since        2017-07-03
     *
     * @dataProvider shouldDropForeignKeyProvider
     */
    public function shouldDropForeignKey(IntegrationTester $I, Example $example)
    {
        $I->assertEquals(
            $example['expected'],
            $this->connection->execute(
                $example['sql']
            )
        );
    }

    private function shouldAddForeignKeyProvider(): array
    {
        return [
            [
                'sql'      => $this->addForeignKeySql('test_name_key', 'CASCADE', 'RESTRICT'),
                'expected' => true,
            ],

            [
                'sql'      => $this->addForeignKeySql('', 'CASCADE', 'RESTRICT'),
                'expected' => true,
            ],
        ];
    }

    private function shouldCheckAddedForeignKeyProvider(): array
    {
        return [
            [
                'sql'      => $this->getForeignKeySql('test_name_key'),
                'expected' => true,
            ],

            [
                'sql'      => $this->getForeignKeySql('foreign_key_child_ibfk_1'),
                'expected' => true,
            ],
        ];
    }

    private function shouldDropForeignKeyProvider(): array
    {
        return [
            [
                'sql'      => 'ALTER TABLE `foreign_key_child` DROP FOREIGN KEY test_name_key',
                'expected' => true,
            ],

            [
                'sql'      => 'ALTER TABLE `foreign_key_child` DROP FOREIGN KEY foreign_key_child_ibfk_1',
                'expected' => true,
            ],
        ];
    }
}
