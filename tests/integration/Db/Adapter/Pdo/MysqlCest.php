<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Db\Adapter\Pdo;

use Codeception\Example;
use IntegrationTester;
use PDOException;
use Phalcon\Db\Adapter\Pdo\Mysql;
use Phalcon\Db\Reference;
use Phalcon\Test\Integration\Db\Dialect\Helper\MysqlHelper;

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
     * Tests Mysql::listTables
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-08-03
     */
    public function testListTables(IntegrationTester $I)
    {
        $expected = [
            'albums',
            'artists',
            'childs',
            'customers',
            'dialect_table',
            'dialect_table_intermediate',
            'dialect_table_remote',
            'foreign_key_child',
            'foreign_key_parent',
            'identityless_requests',
            'issue12071_body',
            'issue12071_head',
            'issue_11036',
            'issue_1534',
            'issue_2019',
            'm2m_parts',
            'm2m_robots',
            'm2m_robots_parts',
            'package_details',
            'packages',
            'parts',
            'personas',
            'personnes',
            'ph_select',
            'prueba',
            'robots',
            'robots_parts',
            'songs',
            'stats',
            'stock',
            'subscriptores',
            'table_with_string_field',
            'tipo_documento',
            'users',
        ];


        $I->assertEquals(
            $expected,
            $this->connection->listTables()
        );


        $dbName = env('DATA_MYSQL_NAME', 'phalcon_test');

        $I->assertEquals(
            $expected,
            $this->connection->listTables($dbName)
        );
    }

    /**
     * Tests Mysql::describeReferences
     *
     * @author Wojciechj Ślawski <jurigag@gmail.com>
     * @since  2016-09-28
     */
    public function testDescribeReferencesColumnsCount(IntegrationTester $I)
    {
        $actual = $this->connection->describeReferences(
            'robots_parts',
            env('DATA_MYSQL_NAME')
        );

        $I->assertCount(2, $actual);


        $I->assertCount(
            2,
            $this->connection->describeReferences('robots_parts', null)
        );


        $references = $actual;

        /** @var Reference $reference */
        foreach ($references as $reference) {
            $I->assertCount(
                1,
                $reference->getColumns()
            );
        }
    }

    /**
     * Tests Mysql::escapeIdentifier
     *
     * @author       Sid Roberts <https://github.com/SidRoberts>
     * @since        2016-11-19
     *
     * @dataProvider testEscapeIdentifierProvider
     */
    public function testEscapeIdentifier(IntegrationTester $I, Example $example)
    {
        $identifier = $example['identifier'];
        $expected   = $example['expected'];

        $I->assertEquals(
            $expected,
            $this->connection->escapeIdentifier($identifier)
        );
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

    private function testEscapeIdentifierProvider(): array
    {
        return [
            [
                'identifier' => 'robots',
                'expected'   => '`robots`',
            ],

            [
                'identifier' => ['schema', 'robots'],
                'expected'   => '`schema`.`robots`',
            ],

            [
                'identifier' => '`robots`',
                'expected'   => '```robots```',
            ],

            [
                'identifier' => ['`schema`', 'rob`ots'],
                'expected'   => '```schema```.`rob``ots`',
            ],
        ];
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
                'sql'      => $this->dropForeignKeySql('test_name_key'),
                'expected' => true,
            ],

            [
                'sql'      => $this->dropForeignKeySql('foreign_key_child_ibfk_1'),
                'expected' => true,
            ],
        ];
    }
}
