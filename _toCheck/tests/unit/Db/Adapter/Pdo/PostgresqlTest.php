<?php

namespace Phalcon\Test\Unit\Db\Adapter\Pdo;

use Helper\Dialect\PostgresqlTrait;
use Phalcon\Db\Adapter\Pdo\Postgresql;
use Phalcon\Db\Column;
use Phalcon\Db\Dialect\Postgresql as DialectPostgresql;
use Phalcon\Db\Reference;
use Phalcon\Test\Module\UnitTest;
use PHPUnit\Framework\SkippedTestError;

/**
 * \Phalcon\Test\Unit\Db\Adapter\Pdo\PostgresqlTest
 * Tests the \Phalcon\Db\Adapter\Pdo\Postgresql component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Phalcon Team <team@phalconphp.com>
 * @author    Wojciech Ślawski <jurigag@gmail.com>
 * @package   Phalcon\Test\Unit\Db\Adapter\Pdo
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class PostgresqlTest extends UnitTest
{
    use PostgresqlTrait;

    /**
     * @var Postgresql
     */
    protected $connection;


    /**
     * Tests Postgresql::describeReferences
     *
     * @test
     * @author Sergii Svyrydenko <sergey.v.sviridenko@gmail.com>
     * @since  2017-08-18
     */
    public function shouldCreateReferenceObject()
    {
        $this->specify(
            "Created reference object isn't proper",
            function ($expected) {
                $reference = $this->connection->describeReferences('foreign_key_child', 'public');

                expect($reference)->equals($expected);
            },
            [
                'examples' => $this->getReferenceObject()
            ]
        );
    }

    /**
     * Tests Postgresql::addForeignKey
     *
     * @test
     * @author Sergii Svyrydenko <sergey.v.sviridenko@gmail.com>
     * @since  2017-07-05
     */
    public function shouldAddForeignKey()
    {
        $this->specify(
            "Foreign key hasn't created",
            function ($reference, $expected) {
                $dialect = new DialectPostgresql();
                $references = $this->getReferenceAddForeignKey();
                $sql = $dialect->addForeignKey('foreign_key_child', 'public', $references[$reference]);

                expect($this->connection->execute($sql))->equals($expected);
            },
            [
                'examples' => [
                    ['fk1', true],
                    ['fk2', true]
                ]
            ]
        );
    }

    /**
     * Tests Postgresql::is created
     *
     * @test
     * @author Sergii Svyrydenko <sergey.v.sviridenko@gmail.com>
     * @since  2017-07-05
     */
    public function shouldCheckAddedForeignKey()
    {
        $this->specify(
            "Foreign key isn't created",
            function ($sql, $expected) {
                expect($this->connection->execute($sql))->equals($expected);
            },
            [
                'examples' => [
                    [$this->getForeignKey('fk1'), 1],
                    [$this->getForeignKey('foreign_key_child_child_int_fkey'), 1]
                ]
            ]
        );
    }

    /**
     * Tests Postgresql::dropAddForeignKey
     *
     * @test
     * @author Sergii Svyrydenko <sergey.v.sviridenko@gmail.com>
     * @since  2017-07-05
     */
    public function shouldDropForeignKey()
    {
        $this->specify(
            "Foreign key can't be deleted",
            function ($reference, $expected) {
                $dialect = new DialectPostgresql();
                $sql = $dialect->dropForeignKey('foreign_key_child', 'public', $reference);

                expect($this->connection->execute($sql))->equals($expected);
            },
            [
                'examples' => [
                    ['fk1', true],
                    ['foreign_key_child_child_int_fkey', true]
                ]
            ]
        );
    }
}
