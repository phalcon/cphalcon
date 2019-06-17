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
 * Class UpdateCest
 */
class UpdateCest
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

        $this->mongo->selectCollection($this->source)->insertOne(
            [
                'first_name' => 'Wall',
                'last_name' => 'E',
            ]
        );
    }

    /**
     * Tests Phalcon\Mvc\Collection :: update()
     *
     * @param IntegrationTester $I
     * @since  2018-11-13
     * @author Phalcon Team <team@phalconphp.com>
     */
    public function mvcCollectionUpdate(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Collection - update()');

        /** @var Robots $robot */
        $robot = Robots::findFirst();
        $I->assertNotFalse($robot);

        $robot->last_name = 'X';
        $I->assertTrue($robot->update());

        $updated = $this->mongo->selectCollection($this->source)->findOne(['_id' => $robot->getId()]);
        $I->assertEquals($updated['last_name'], 'X');
    }

    public function _after()
    {
        $this->mongo->dropCollection($this->source);
    }
}
