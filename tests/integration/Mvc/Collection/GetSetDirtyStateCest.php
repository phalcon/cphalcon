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
use MongoDB\Database;
use Phalcon\Test\Fixtures\Mvc\Collections\Robots;
use Phalcon\Test\Fixtures\Traits\DiTrait;

/**
 * Class GetSetDirtyStateCest
 */
class GetSetDirtyStateCest
{
    use DiTrait;

    /** @var string $source */
    private $source;

    /** @var Database $mongo */
    private $mongo;

    public function _before()
    {
        $this->setNewFactoryDefault();
        $this->setDiCollectionManager();
        $this->setDiMongo();

        $this->source = (new Robots)->getSource();
        $this->mongo = $this->getDi()->get('mongo');
    }

    /**
     * Tests Phalcon\Mvc\Collection :: getDirtyState()
     * Tests Phalcon\Mvc\Collection :: setDirtyState()
     *
     * @param IntegrationTester $I
     * @since  2018-11-13
     * @author Phalcon Team <team@phalconphp.com>
     */
    public function mvcCollectionGetSetDirtyState(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Collection - getDirtyState()');
        $I->wantToTest('Mvc\Collection - setDirtyState()');

        $robot = new Robots;
        $I->assertEquals(Robots::DIRTY_STATE_TRANSIENT, $robot->getDirtyState());

        $robot->first_name = "wall";
        $I->assertTrue($robot->save());
        $I->assertEquals(Robots::DIRTY_STATE_PERSISTENT, $robot->getDirtyState());

        $I->assertTrue($robot->delete());
        $I->assertEquals(Robots::DIRTY_STATE_DETACHED, $robot->getDirtyState());

        $robot->setDirtyState(Robots::DIRTY_STATE_TRANSIENT);
        $I->assertEquals(Robots::DIRTY_STATE_TRANSIENT, $robot->getDirtyState());
    }

    public function _after()
    {
        $this->mongo->dropCollection($this->source);
    }
}
