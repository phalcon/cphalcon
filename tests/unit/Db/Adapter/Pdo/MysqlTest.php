<?php

namespace Phalcon\Test\Unit\Db\Adapter\Pdo;

use Helper\Dialect\MysqlTrait;
use Phalcon\Db\Adapter\Pdo\Mysql;
use Phalcon\Db\Reference;
use Phalcon\Test\Module\UnitTest;
use PHPUnit\Framework\SkippedTestError;

/**
 * \Phalcon\Test\Unit\Db\Adapter\Pdo\MysqlTest
 * Tests the \Phalcon\Db\Adapter\Pdo\Mysql component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Unit\Db\Adapter\Pdo
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class MysqlTest extends UnitTest
{
    use MysqlTrait;

    /**
     * @var Mysql
     */
    protected $connection;

    public function _before()
    {
        parent::_before();

        try {
            $this->connection = new Mysql([
                'host'     => TEST_DB_MYSQL_HOST,
                'username' => TEST_DB_MYSQL_USER,
                'password' => TEST_DB_MYSQL_PASSWD,
                'dbname'   => TEST_DB_MYSQL_NAME,
                'port'     => TEST_DB_MYSQL_PORT,
                'charset'  => TEST_DB_MYSQL_CHARSET,
            ]);
        } catch (\PDOException $e) {
            throw new SkippedTestError("Unable to connect to the database: " . $e->getMessage());
        }
    }

    /**
     * Tests Mysql::escapeIdentifier
     *
     * @author Sid Roberts <sid@sidroberts.co.uk>
     * @since  2016-11-19
     */
    public function testEscapeIdentifier()
    {
        $this->specify(
            'Identifiers are not properly escaped',
            function ($identifier, $expected) {
                $escapedIdentifier = $this->connection->escapeIdentifier($identifier);

                expect($escapedIdentifier)->equals($expected);
            },
            [
                "examples" => [
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
                ]
            ]
        );
    }

    /**
     * Tests Mysql::addForeignKey
     *
     * @test
     * @issue  https://github.com/phalcon/cphalcon/issues/556
     * @author Sergii Svyrydenko <sergey.v.sviridenko@gmail.com>
     * @since  2017-07-03
     */
    public function shouldAddForeignKey()
    {
        $this->specify(
            "Foreign key hasn't created",
            function ($sql, $expected) {
                expect($this->connection->execute($sql))->equals($expected);
            },
            [
                'examples' => [
                    [$this->addForeignKey('test_name_key', 'CASCADE', 'RESTRICT'), true],
                    [$this->addForeignKey('', 'CASCADE', 'RESTRICT'), true]
                ]
            ]
        );
    }

    /**
     * Tests Mysql::getForeignKey
     *
     * @test
     * @issue  https://github.com/phalcon/cphalcon/issues/556
     * @author Sergii Svyrydenko <sergey.v.sviridenko@gmail.com>
     * @since  2017-07-03
     */
    public function shouldCheckAddedForeignKey()
    {
        $this->specify(
            "Foreign key isn't created",
            function ($sql, $expected) {
                expect($this->connection->execute($sql, ['MYSQL_ATTR_USE_BUFFERED_QUERY']))->equals($expected);
            },
            [
                'examples' => [
                    [$this->getForeignKey('test_name_key'), true],
                    [$this->getForeignKey('foreign_key_child_ibfk_1'), true]
                ]
            ]
        );
    }

     /**
      * Tests Mysql::dropAddForeignKey
      *
      * @test
      * @issue  https://github.com/phalcon/cphalcon/issues/556
      * @author Sergii Svyrydenko <sergey.v.sviridenko@gmail.com>
      * @since  2017-07-03
      */
    public function shouldDropForeignKey()
    {
        $this->specify(
            "Foreign key can't be created",
            function ($sql, $expected) {
                expect($this->connection->execute($sql))->equals($expected);
            },
            [
                'examples' => [
                    [$this->dropForeignKey('test_name_key'), true],
                    [$this->dropForeignKey('foreign_key_child_ibfk_1'), true]
                ]
            ]
        );
    }
}
