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

namespace Phalcon\Test\Integration\Mvc\Model;

use IntegrationTester;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Personas;
use Phalcon\Test\Models\Users;

class AssignCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDiMysql();
    }

    public function _after(IntegrationTester $I)
    {
        $this->container['db']->close();
    }

    /**
     * Tests Phalcon\Mvc\Model :: assign()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-04-18
     */
    public function mvcModelAssign(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model - assign()');

        $user = new Users();

        $user->assign(
            [
                'id'   => 123,
                'name' => 'Sid',
            ]
        );

        $I->assertEquals(
            123,
            $user->readAttribute('id')
        );

        $I->assertEquals(
            'Sid',
            $user->readAttribute('name')
        );

        $I->assertEquals(
            [
                'id'   => 123,
                'name' => 'Sid',
            ],
            $user->toArray()
        );
    }

    public function testAssign(IntegrationTester $I)
    {
        $persona = new Personas();

        $persona->assign(
            [
                'tipo_documento_id' => 1,
                'nombres'           => 'LOST CREATE',
                'telefono'          => '1',
                'cupo'              => 21000,
                'estado'            => 'A',
                'notField'          => 'SOME VALUE',
            ]
        );

        $expected = [
            'cedula'            => null,
            'tipo_documento_id' => 1,
            'nombres'           => 'LOST CREATE',
            'telefono'          => '1',
            'direccion'         => null,
            'email'             => null,
            'fecha_nacimiento'  => null,
            'ciudad_id'         => null,
            'creado_at'         => null,
            'cupo'              => 21000,
            'estado'            => 'A',
        ];

        $I->assertEquals(
            $expected,
            $persona->toArray()
        );
    }
}
