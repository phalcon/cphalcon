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
use MongoDB\Driver\Cursor;
use Phalcon\Test\Fixtures\Mvc\Collections\Robots;
use Phalcon\Test\Fixtures\Traits\DiTrait;

/**
 * Class AggregateCest
 */
class AggregateCest
{
    use DiTrait;

    private $source;

    /** @var Database $mongo */
    private $mongo;

    public function _before(IntegrationTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDiCollectionManager();
        $this->setDiMongo();

        $this->source = (new Robots)->getSource();
        $this->mongo = $this->getDi()->get('mongo');

        $this->mongo->selectCollection($this->source)->insertMany(
            [
                [
                    'first_name' => 'Wall',
                    'last_name' => 'E',
                ],
                [
                    'first_name' => 'Unknown',
                    'last_name' => 'Nobody',
                ]
            ]
        );
    }

    /**
     * Tests Phalcon\Mvc\Collection :: aggregate()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcCollectionAggregate(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Collection - aggregate()');

        /** @var Cursor $robots */
        $robots = Robots::aggregate(
            [
                [
                    '$match' => [
                        'first_name' => 'Wall'
                    ]
                ]
            ]
        );

        $I->assertNotEmpty($robots->toArray());
    }

    public function _after(IntegrationTester $I)
    {
        $this->mongo->dropCollection($this->source);
    }
}
