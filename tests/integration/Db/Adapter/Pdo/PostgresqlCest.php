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

use IntegrationTester;
use Phalcon\Db\Dialect\Postgresql as DialectPostgresql;
use Phalcon\Db\Reference;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use function env;

class PostgresqlCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDiPostgresql();
    }

    /**
     * Tests Postgresql::describeReferences
     *
     * @author Sergii Svyrydenko <sergey.v.sviridenko@gmail.com>
     * @since  2017-08-18
     */
    public function shouldCreateReferenceObject(IntegrationTester $I)
    {
        $expected   = $this->getReferenceObject();
        $connection = $this->getService('db');
        $actual     = $connection->describeReferences('foreign_key_child', 'public');

        $I->assertEquals($expected, $actual);
    }

    private function getReferenceObject()
    {
        return [
            'test_describereferences' => new Reference(
                'test_describereferences',
                [
                    'referencedTable'   => 'foreign_key_parent',
                    'referencedSchema'  => env('DATA_POSTGRES_NAME'),
                    'columns'           => ['child_int'],
                    'referencedColumns' => ['refer_int'],
                    'onUpdate'          => 'CASCADE',
                    'onDelete'          => 'RESTRICT',
                ]
            ),
        ];
    }

    /**
     * Tests Postgresql::addForeignKey
     *
     * @author Sergii Svyrydenko <sergey.v.sviridenko@gmail.com>
     * @since  2017-07-05
     */
    public function shouldAddForeignKey(IntegrationTester $I)
    {
        $examples = [
            ['fk1', true],
            ['fk2', true],
        ];

        foreach ($examples as $item) {
            $reference  = $item[0];
            $expected   = $item[1];
            $dialect    = new DialectPostgresql();
            $references = $this->getReferenceAddForeignKey();
            $sql        = $dialect->addForeignKey('foreign_key_child', 'public', $references[$reference]);

            $connection = $this->getService('db');
            $actual     = $connection->execute($sql);
            $I->assertEquals($expected, $actual);
        }
    }

    protected function getReferenceAddForeignKey()
    {
        return [
            'fk1' => new Reference('fk1', [
                'referencedTable'   => 'foreign_key_parent',
                'columns'           => ['child_int'],
                'referencedColumns' => ['refer_int'],
                'onDelete'          => 'CASCADE',
                'onUpdate'          => 'RESTRICT',
            ]),
            'fk2' => new Reference('', [
                'referencedTable'   => 'foreign_key_parent',
                'columns'           => ['child_int'],
                'referencedColumns' => ['refer_int'],
            ]),
        ];
    }

    /**
     * Tests Postgresql::is created
     *
     * @author Sergii Svyrydenko <sergey.v.sviridenko@gmail.com>
     * @since  2017-07-05
     */
    public function shouldCheckAddedForeignKey(IntegrationTester $I)
    {
        $examples = [
            [$this->getForeignKey('fk1'), 1],
            [$this->getForeignKey('foreign_key_child_child_int_fkey'), 1],
        ];

        foreach ($examples as $item) {
            $sql      = $item[0];
            $expected = $item[1];

            $connection = $this->getService('db');
            $actual     = $connection->execute($sql);
            $I->assertEquals($expected, $actual);
        }
    }

    private function getForeignKey($foreignKeyName)
    {
        $sql = rtrim(file_get_contents(dataFolder('fixtures/Db/postgresql/example9.sql')));
        str_replace('%_FK_%', $foreignKeyName, $sql);

        return $sql;
    }

    /**
     * Tests Postgresql::dropAddForeignKey
     *
     * @test
     * @author Sergii Svyrydenko <sergey.v.sviridenko@gmail.com>
     * @since  2017-07-05
     */
    public function shouldDropForeignKey(IntegrationTester $I)
    {
        $examples = [
            ['fk1', true],
            ['foreign_key_child_child_int_fkey', true],
        ];

        foreach ($examples as $item) {
            $reference = $item[0];
            $expected  = $item[1];
            $dialect   = new DialectPostgresql();
            $sql       = $dialect->dropForeignKey('foreign_key_child', 'public', $reference);

            $connection = $this->getService('db');
            $actual     = $connection->execute($sql);
            $I->assertEquals($expected, $actual);
        }
    }
}
