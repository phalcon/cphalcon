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
use MongoDB\InsertOneResult;
use Phalcon\Test\Fixtures\Mvc\Collections\Robots;
use Phalcon\Test\Fixtures\Traits\DiTrait;

/**
 * Class GetIdCest
 */
class GetIdCest
{
    use DiTrait;

    /** @var string $source */
    private $source;

    /** @var Database $mongo */
    private $mongo;

    /** @var mixed $id */
    private $id;

    public function _before()
    {
        $this->setNewFactoryDefault();
        $this->setDiCollectionManager();
        $this->setDiMongo();

        $this->source = (new Robots)->getSource();
        $this->mongo = $this->getDi()->get('mongo');

        /** @var InsertOneResult $return */
        $return = $this->mongo->selectCollection($this->source)->insertOne(
            [
                'first_name' => 'Wall',
                'last_name' => 'E',
            ]
        );

        $this->id = $return->getInsertedId();
    }

    /**
     * Tests Phalcon\Mvc\Collection :: getId()
     *
     * @param IntegrationTester $I
     * @since  2018-11-13
     * @author Phalcon Team <team@phalconphp.com>
     */
    public function mvcCollectionGetId(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Collection - getId()');

        $robot = Robots::findFirst();

        $I->assertNotFalse($robot);
        $I->assertEquals($robot->getId(), $this->id);
    }

    public function _after()
    {
        $this->mongo->dropCollection($this->source);
    }
}
