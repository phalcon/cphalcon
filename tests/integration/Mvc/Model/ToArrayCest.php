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
use Phalcon\Test\Models\Personers;

class ToArrayCest
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
     * Tests Phalcon\Mvc\Model :: toArray()
     */
    public function mvcModelToArray(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model - toArray()');

        //toArray with params must return only mapped fields if exists columnMap

        $persona = new Personers();

        $persona->assign(
            [
                'slagBorgerId'    => 1,
                'navnes'          => 'LOST CREATE',
                'teletelefonfono' => '1',
                'kredit'          => 21000,
                'status'          => 'A',
                'notField'        => 'SOME VALUE',
            ]
        );

        $expected = [
            'navnes' => 'LOST CREATE',
            'kredit' => 21000,
            'status' => 'A',
        ];

        // db fields names
        $I->assertEquals(
            [],
            $persona->toArray(
                [
                    'nombres',
                    'cupo',
                    'estado',
                ]
            )
        );

        // mapped fields names
        $I->assertEquals(
            $expected,
            $persona->toArray(
                [
                    'navnes',
                    'kredit',
                    'status',
                ]
            )
        );
    }
}
