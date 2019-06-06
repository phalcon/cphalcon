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

namespace Phalcon\Test\Integration\Mvc\Model\Manager;

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
 
    public function _after(IntegrationTester $I)
    {
        $this->container['db']->close();
    }

    /**
     * Tests Phalcon\Mvc\Model\Manager :: refresh()
     */
    public function mvcModelManagerRefresh(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Manager - refresh()');

        $modelsManager = $this->container['modelsManager'];

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

        $modelsManager->refresh($persona);

        $I->assertEquals(
            $personaData,
            $persona->toArray()
        );
    }
}
