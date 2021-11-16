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

namespace Phalcon\Tests\Integration\Db\Adapter\Pdo\Sqlite;

use IntegrationTester;
use Phalcon\Db\Column;
use Phalcon\Tests\Fixtures\Traits\DiTrait;

class DescribeColumnsCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->newDi();
        $this->setDiModelsManager();
        $this->setDiModelsMetadata();
        $this->setDiSqlite();
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo\Sqlite :: describeColumns()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function dbAdapterPdoSqliteDescribeColumns(IntegrationTester $I)
    {
        $I->wantToTest('Db\Adapter\Pdo\Sqlite - describeColumns()');

        $connection = $this->getService('db');

        $expectedDescribe = $this->getExpectedColumnsSqlite();

        $I->assertEquals(
            $expectedDescribe,
            $connection->describeColumns('personas')
        );

        $I->assertEquals(
            $expectedDescribe,
            $connection->describeColumns('personas', 'main')
        );
    }

    private function getExpectedColumnsSqlite(): array
    {
        return [
            0  => new Column(
                'cedula',
                [
                    'type'          => 5,
                    'isNumeric'     => false,
                    'size'          => 15,
                    'default'       => null,
                    'unsigned'      => false,
                    'notNull'       => true,
                    'autoIncrement' => false,
                    'primary'       => true,
                    'first'         => true,
                    'after'         => null,
                    'bindType'      => 2,
                ]
            ),
            1  => new Column(
                'tipo_documento_id',
                [
                    'type'          => 0,
                    'isNumeric'     => true,
                    'size'          => 3,
                    'scale'         => 0,
                    'default'       => null,
                    'unsigned'      => false,
                    'notNull'       => true,
                    'autoIncrement' => false,
                    'first'         => false,
                    'after'         => 'cedula',
                    'bindType'      => 1,
                ]
            ),
            2  => new Column(
                'nombres',
                [
                    'type'          => 2,
                    'isNumeric'     => false,
                    'size'          => 100,
                    'default'       => '',
                    'unsigned'      => false,
                    'notNull'       => true,
                    'autoIncrement' => false,
                    'first'         => false,
                    'after'         => 'tipo_documento_id',
                    'bindType'      => 2,
                ]
            ),
            3  => new Column(
                'telefono',
                [
                    'type'          => 2,
                    'isNumeric'     => false,
                    'size'          => 20,
                    'default'       => null,
                    'unsigned'      => false,
                    'notNull'       => false,
                    'autoIncrement' => false,
                    'first'         => false,
                    'after'         => 'nombres',
                    'bindType'      => 2,
                ]
            ),
            4  => new Column(
                'direccion',
                [
                    'type'          => 2,
                    'isNumeric'     => false,
                    'size'          => 100,
                    'default'       => null,
                    'unsigned'      => false,
                    'notNull'       => false,
                    'autoIncrement' => false,
                    'first'         => false,
                    'after'         => 'telefono',
                    'bindType'      => 2,
                ]
            ),
            5  => new Column(
                'email',
                [
                    'type'          => 2,
                    'isNumeric'     => false,
                    'size'          => 50,
                    'default'       => null,
                    'unsigned'      => false,
                    'notNull'       => false,
                    'autoIncrement' => false,
                    'first'         => false,
                    'after'         => 'direccion',
                    'bindType'      => 2,
                ]
            ),
            6  => new Column(
                'fecha_nacimiento',
                [
                    'type'          => 1,
                    'isNumeric'     => false,
                    'size'          => 0,
                    'default'       => '1970-01-01',
                    'unsigned'      => false,
                    'notNull'       => false,
                    'autoIncrement' => false,
                    'first'         => false,
                    'after'         => 'email',
                    'bindType'      => 2,
                ]
            ),
            7  => new Column(
                'ciudad_id',
                [
                    'type'          => 0,
                    'isNumeric'     => true,
                    'size'          => 10,
                    'scale'         => 0,
                    'default'       => '0',
                    'unsigned'      => false,
                    'notNull'       => false,
                    'autoIncrement' => false,
                    'first'         => false,
                    'after'         => 'fecha_nacimiento',
                    'bindType'      => 1,
                ]
            ),
            8  => new Column(
                'creado_at',
                [
                    'type'          => 1,
                    'isNumeric'     => false,
                    'size'          => 0,
                    'default'       => null,
                    'unsigned'      => false,
                    'notNull'       => false,
                    'autoIncrement' => false,
                    'first'         => false,
                    'after'         => 'ciudad_id',
                    'bindType'      => 2,
                ]
            ),
            9  => new Column(
                'cupo',
                [
                    'type'          => 3,
                    'isNumeric'     => true,
                    'size'          => 16,
                    'scale'         => 2,
                    'default'       => null,
                    'unsigned'      => false,
                    'notNull'       => true,
                    'autoIncrement' => false,
                    'first'         => false,
                    'after'         => 'creado_at',
                    'bindType'      => 32,
                ]
            ),
            10 => new Column(
                'estado',
                [
                    'type'          => 5,
                    'isNumeric'     => false,
                    'size'          => 1,
                    'default'       => null,
                    'unsigned'      => false,
                    'notNull'       => true,
                    'autoIncrement' => false,
                    'first'         => false,
                    'after'         => 'cupo',
                    'bindType'      => 2,
                ]
            ),
        ];
    }
}
