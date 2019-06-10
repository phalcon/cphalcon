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
 * Class CountCest
 */
class CountCest
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

        $this->mongo->selectCollection($this->source)->insertMany(
            [
                [
                    'first_name' => 'Termi',
                    'last_name' => 'Nator',
                ],
                [
                    'first_name' => 'Wall',
                    'last_name' => 'E',
                ],
                [
                    'first_name' => 'Termi',
                    'last_name' => 'Nator2',
                ],
                [
                    'first_name' => 'Termi',
                    'last_name' => 'Nator3',
                ],
                [
                    'first_name' => 'Unknown',
                    'last_name' => 'Nobody',
                ]
            ]
        );
    }

    /**
     * Tests Phalcon\Mvc\Collection :: count()
     *
     * @param IntegrationTester $I
     * @since  2018-11-13
     * @author Phalcon Team <team@phalconphp.com>
     */
    public function mvcCollectionCount(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Collection - count()');

        $countAll = Robots::count();
        $countTermi = Robots::count(
            [
                [
                    'first_name' => 'Termi'
                ]
            ]
        );

        $I->assertEquals(3, $countTermi);
        $I->assertEquals(5, $countAll);
    }

    public function _after()
    {
        $this->mongo->dropCollection($this->source);
    }
}
