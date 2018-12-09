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

use Helper\Dialect\MysqlTrait;
use IntegrationTester;
use Phalcon\Db\Adapter\Pdo\Mysql;
use Phalcon\Db\Reference;
use Phalcon\Test\Integration\Db\Dialect\Helper\MysqlHelper;

class MysqlCest extends MysqlHelper
{
    /**
     * @var Mysql
     */
    protected $connection;

    /**
     * @param IntegrationTester $I
     */
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
        } catch (\PDOException $e) {
            $I->skipTest("Unable to connect to the database: " . $e->getMessage());
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

        $actual = $this->connection->listTables();
        $I->assertEquals($expected, $actual);

        $dbName = env('DATA_MYSQL_NAME', 'phalcon_test');
        $actual = $this->connection->listTables($dbName);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Mysql::describeReferences
     *
     * @author Wojciechj Ślawski <jurigag@gmail.com>
     * @since  2016-09-28
     */
    public function testDescribeReferencesColumnsCount(IntegrationTester $I)
    {

        $expected = 2;
        $actual   = $this->connection->describeReferences('robots_parts', env('DATA_MYSQL_NAME'));
        $I->assertCount($expected, $actual);

        $expected = 2;
        $actual   = $this->connection->describeReferences('robots_parts', null);
        $I->assertCount($expected, $actual);

        $references = $actual;
        /** @var Reference $reference */
        foreach ($references as $reference) {
            $expected = 1;
            $actual   = count($reference->getColumns());
            $I->assertEquals($expected, $actual);
        }
    }

    /**
     * Tests Mysql::escapeIdentifier
     *
     * @author Sid Roberts <sid@sidroberts.co.uk>
     * @since  2016-11-19
     */
    public function testEscapeIdentifier(IntegrationTester $I)
    {
        $examples = [
            [
                "identifier" => "robots",
                "expected"   => "`robots`",
            ],
            [
                "identifier" => ["schema", "robots"],
                "expected"   => "`schema`.`robots`",
            ],
            [
                "identifier" => "`robots`",
                "expected"   => "```robots```",
            ],
            [
                "identifier" => ["`schema`", "rob`ots"],
                "expected"   => "```schema```.`rob``ots`",
            ],
        ];

        foreach ($examples as $item) {
            $identifier = $item['identifier'];
            $expected   = $item['expected'];

            $actual = $this->connection->escapeIdentifier($identifier);
            $I->assertEquals($expected, $actual);
        }
    }

    /**
     * Tests Mysql::addForeignKey
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/556
     * @author Sergii Svyrydenko <sergey.v.sviridenko@gmail.com>
     * @since  2017-07-03
     */
    public function shouldAddForeignKey(IntegrationTester $I)
    {
        $examples = [
            [$this->addForeignKeySql('test_name_key', 'CASCADE', 'RESTRICT'), true],
            [$this->addForeignKeySql('', 'CASCADE', 'RESTRICT'), true],
        ];

        foreach ($examples as $item) {
            $sql      = $item[0];
            $expected = $item[1];
            $actual   = $this->connection->execute($sql);
            $I->assertEquals($expected, $actual);
        }
    }

    /**
     * Tests Mysql::getForeignKey
     *
     * @test
     * @issue  https://github.com/phalcon/cphalcon/issues/556
     * @author Sergii Svyrydenko <sergey.v.sviridenko@gmail.com>
     * @since  2017-07-03
     */
    public function shouldCheckAddedForeignKey(IntegrationTester $I)
    {
        $examples = [
            [$this->getForeignKeySql('test_name_key'), true],
            [$this->getForeignKeySql('foreign_key_child_ibfk_1'), true],
        ];

        foreach ($examples as $item) {
            $sql      = $item[0];
            $expected = $item[1];
            $actual   = $this->connection->execute($sql, ['MYSQL_ATTR_USE_BUFFERED_QUERY']);
            $I->assertEquals($expected, $actual);
        }
    }

    /**
     * Tests Mysql::dropAddForeignKey
     *
     * @test
     * @issue  https://github.com/phalcon/cphalcon/issues/556
     * @author Sergii Svyrydenko <sergey.v.sviridenko@gmail.com>
     * @since  2017-07-03
     */
    public function shouldDropForeignKey(IntegrationTester $I)
    {
        $examples = [
            [$this->dropForeignKeySql('test_name_key'), true],
            [$this->dropForeignKeySql('foreign_key_child_ibfk_1'), true],
        ];

        foreach ($examples as $item) {
            $sql      = $item[0];
            $expected = $item[1];
            $actual   = $this->connection->execute($sql);
            $I->assertEquals($expected, $actual);
        }
    }
}
