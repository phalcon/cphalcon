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
 * Class FindByIdCest
 */
class FindByIdCest
{
    use DiTrait;

    /** @var string $source */
    private $source;

    /** @var Database $mongo */
    private $mongo;

    /** @var ObjectId $tmpId */
    private $tmpId;

    public function _before()
    {
        $this->setNewFactoryDefault();
        $this->setDiCollectionManager();
        $this->setDiMongo();

        $this->source = (new Robots)->getSource();
        $this->mongo = $this->getDi()->get('mongo');
        $this->tmpId = new ObjectId;

        $this->mongo->selectCollection($this->source)->insertMany(
            [
                [
                    'first_name' => 'Wall',
                    'last_name' => 'E',
                ],
                [
                    '_id' => $this->tmpId,
                    'first_name' => 'Unknown',
                    'last_name' => 'Nobody',
                ]
            ]
        );
    }

    /**
     * Tests Phalcon\Mvc\Collection :: findById()
     *
     * @param IntegrationTester $I
     * @since  2018-11-13
     * @author Phalcon Team <team@phalconphp.com>
     */
    public function mvcCollectionFindById(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Collection - findById()');

        $I->assertFalse(Robots::findById(new ObjectId));
        $I->assertInstanceOf(Robots::class, Robots::findById($this->tmpId));
        $I->assertInstanceOf(Robots::class, Robots::findById((string)$this->tmpId));
    }

    public function _after()
    {
        $this->mongo->dropCollection($this->source);
    }
}
