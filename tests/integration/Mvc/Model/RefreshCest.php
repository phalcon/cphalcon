<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Mvc\Model;

use IntegrationTester;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Personas;

class RefreshCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDiMysql();
    }
 
    /**
     * Tests Phalcon\Mvc\Model :: refresh()
     */
    public function mvcModelRefresh(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model - refresh()');

        $persona = Personas::findFirst();

        $personaData = $persona->toArray();

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

        $persona->refresh();

        $I->assertEquals(
            $personaData,
            $persona->toArray()
        );
    }
}
