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
 * Class SetConnectionServiceCest
 */
class SetConnectionServiceCest
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
        $this->getDi()->setShared('otherMongo', $this->mongo);
    }

    /**
     * Tests Phalcon\Mvc\Collection :: setConnectionService()
     *
     * @param IntegrationTester $I
     * @since  2018-11-13
     * @author Phalcon Team <team@phalconphp.com>
     */
    public function mvcCollectionSetConnectionService(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Collection - setConnectionService()');

        $robotOne = new Robots;
        $robotOne->first_name = 'One';

        $robotOne->setConnectionService('otherMongo');
        $I->assertEquals('otherMongo', $robotOne->getConnectionService());

        $I->assertTrue($robotOne->save());

        /** @var Robots $robot */
        $robot = Robots::findFirst();

        $I->assertNotFalse($robot);
        $I->assertInstanceOf(Robots::class, $robot);
        $I->assertEquals($robotOne->first_name, $robot->first_name);

    }

    public function _after()
    {
        $this->mongo->dropCollection($this->source);
        $this->mongo->dropCollection('otherMongo');
    }
}
