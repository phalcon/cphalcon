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
 * Class FindFirstCest
 */
class FindFirstCest
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
     * Tests Phalcon\Mvc\Collection :: findFirst()
     *
     * @param IntegrationTester $I
     * @since  2018-11-13
     * @author Phalcon Team <team@phalconphp.com>
     */
    public function mvcCollectionFindFirst(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Collection - findFirst()');

        /** @var Robots|bool $firstRobot */
        $firstRobot = Robots::findFirst();

        /** @var Robots|bool $robot */
        $robot = Robots::findFirst([['last_name' => 'Nobody']]);

        /** @var Robots|bool $noRobot */
        $noRobot = Robots::findFirst([['last_name' => 'Unknown']]);

        $I->assertEquals('Wall', $firstRobot->first_name);
        $I->assertInstanceOf(Robots::class, $robot);
        $I->assertEquals('Nobody', $robot->last_name);
        $I->assertFalse($noRobot);
    }

    public function _after()
    {
        $this->mongo->dropCollection($this->source);
    }
}
