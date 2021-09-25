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
use Phalcon\Db\Dialect\Postgresql as DialectPostgresql;
use Phalcon\Db\Reference;
use Phalcon\Tests\Fixtures\Traits\DiTrait;

use function env;

class PostgresqlCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDiPostgresql();
    }

    public function _after(IntegrationTester $I)
    {
        $this->container['db']->close();
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

        $I->assertEquals(
            $expected,
            $connection->describeReferences('foreign_key_child', 'public')
        );
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
     * @author       Sergii Svyrydenko <sergey.v.sviridenko@gmail.com>
     * @since        2017-07-05
     *
     * @dataProvider shouldAddForeignKeyProvider
     */
    public function shouldAddForeignKey(IntegrationTester $I, Example $example)
    {
        $reference = $example['reference'];

        $dialect = new DialectPostgresql();

        $references = $this->getReferenceAddForeignKey();

        $sql = $dialect->addForeignKey(
            'foreign_key_child',
            'public',
            $references[$reference]
        );

        $connection = $this->getService('db');

        $I->assertEquals(
            $example['expected'],
            $connection->execute($sql)
        );
    }

    private function shouldAddForeignKeyProvider(): array
    {
        return [
            [
                'reference' => 'fk1',
                'expected'  => true,
            ],

            [
                'reference' => 'fk2',
                'expected'  => true,
            ],
        ];
    }

    protected function getReferenceAddForeignKey()
    {
        return [
            'fk1' => new Reference(
                'fk1',
                [
                    'referencedTable'   => 'foreign_key_parent',
                    'columns'           => ['child_int'],
                    'referencedColumns' => ['refer_int'],
                    'onDelete'          => 'CASCADE',
                    'onUpdate'          => 'RESTRICT',
                ]
            ),
            'fk2' => new Reference(
                '',
                [
                    'referencedTable'   => 'foreign_key_parent',
                    'columns'           => ['child_int'],
                    'referencedColumns' => ['refer_int'],
                ]
            ),
        ];
    }

    /**
     * Tests Postgresql::is created
     *
     * @author       Sergii Svyrydenko <sergey.v.sviridenko@gmail.com>
     * @since        2017-07-05
     *
     * @dataProvider shouldCheckAddedForeignKeyProvider
     */
    public function shouldCheckAddedForeignKey(IntegrationTester $I, Example $example)
    {
        $connection = $this->getService('db');

        $actual = $connection->execute(
            $example['sql']
        );

        $I->assertEquals(
            $example['expected'],
            $actual
        );
    }

    private function shouldCheckAddedForeignKeyProvider(): array
    {
        return [
            [
                'sql'      => $this->getForeignKey('fk1'),
                'expected' => 1,
            ],

            [
                'sql'      => $this->getForeignKey('foreign_key_child_child_int_fkey'),
                'expected' => 1,
            ],
        ];
    }

    private function getForeignKey($foreignKeyName)
    {
        $sql = rtrim(
            file_get_contents(
                dataDir('fixtures/Db/postgresql/example9.sql')
            )
        );

        str_replace(
            '%_FK_%',
            $foreignKeyName,
            $sql
        );

        return $sql;
    }

    /**
     * Tests Postgresql::dropAddForeignKey
     *
     * @test
     * @author       Sergii Svyrydenko <sergey.v.sviridenko@gmail.com>
     * @since        2017-07-05
     *
     * @dataProvider shouldDropForeignKeyProvider
     */
    public function shouldDropForeignKey(IntegrationTester $I, Example $example)
    {
        $dialect = new DialectPostgresql();

        $sql = $dialect->dropForeignKey(
            'foreign_key_child',
            'public',
            $example['reference']
        );

        $connection = $this->getService('db');

        $I->assertEquals(
            $example['expected'],
            $connection->execute($sql)
        );
    }

    private function shouldDropForeignKeyProvider(): array
    {
        return [
            [
                'reference' => 'fk1',
                'expected'  => true,
            ],

            [
                'reference' => 'foreign_key_child_child_int_fkey',
                'expected'  => true,
            ],
        ];
    }
}
