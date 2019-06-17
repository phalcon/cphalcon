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
use MongoDB\BSON\ObjectId;
use MongoDB\Database;
use Phalcon\Test\Fixtures\Mvc\Collections\Robots;
use Phalcon\Test\Fixtures\Traits\DiTrait;

/**
 * Class SetIdCest
 */
class SetIdCest
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
     * Tests Phalcon\Mvc\Collection :: setId()
     *
     * @param IntegrationTester $I
     * @since  2018-11-13
     * @author Phalcon Team <team@phalconphp.com>
     */
    public function mvcCollectionSetId(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Collection - setId()');

        $robot = new Robots;
        $robot->setId("5d07dc17a4881ea56c727b2f");
        $I->assertTrue($robot->save());

        $customRobot = $this->mongo->selectCollection($this->source)->findOne(
            [
                '_id' => new ObjectId("5d07dc17a4881ea56c727b2f")
            ]
        );

        $I->assertNotNull($customRobot);
    }

    public function _after()
    {
        $this->mongo->dropCollection($this->source);
    }
}
