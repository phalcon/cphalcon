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

namespace Phalcon\Test\Integration\Mvc\Collection;

use IntegrationTester;
use Phalcon\Mvc\Collection\ManagerInterface;
use Phalcon\Test\Fixtures\Mvc\Collections\Robots;
use Phalcon\Test\Fixtures\Traits\DiTrait;

/**
 * Class GetCollectionManagerCest
 */
class GetCollectionManagerCest
{
    use DiTrait;

    public function _before()
    {
        $this->setNewFactoryDefault();
        $this->setDiCollectionManager();
        $this->setDiMongo();
    }

    /**
     * Tests Phalcon\Mvc\Collection :: getCollectionManager()
     *
     * @param IntegrationTester $I
     * @since  2018-11-13
     * @author Phalcon Team <team@phalconphp.com>
     */
    public function mvcCollectionGetCollectionManager(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Collection - getCollectionManager()');

        $robot = new Robots;
        $I->assertTrue(is_subclass_of($robot->getCollectionManager(), ManagerInterface::class));
    }
}
