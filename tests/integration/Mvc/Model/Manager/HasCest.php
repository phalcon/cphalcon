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
use Phalcon\Mvc\Model;
use Phalcon\Mvc\Model\MetaData;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\AlbumORama\Albums;
use Phalcon\Test\Models\AlbumORama\Artists;
use Phalcon\Test\Models\Parts;
use Phalcon\Test\Models\Robots;
use Phalcon\Test\Models\RobotsParts;
use Phalcon\Test\Models\Users;

class HasCest
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
     * Tests Phalcon\Mvc\Model\Manager :: has()
     */
    public function mvcModelManagerHas(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Manager - has()');

        $modelsManager = $this->container['modelsManager'];

        /**
         * New model
         */
        $user = new Users();

        $user->id   = 54321;
        $user->name = 'New User';

        $I->assertFalse(
            $modelsManager->has($user)
        );

        $I->assertTrue(
            $modelsManager->save($user)
        );

        $I->assertTrue(
            $modelsManager->has($user)
        );

        /**
         * Deleting is necessary because other tests may rely on specific row count
         */
        $I->assertTrue(
            $modelsManager->delete($user)
        );
    }
}
