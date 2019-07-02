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

namespace Phalcon\Test\Integration\Mvc\Collection\Document;

use IntegrationTester;
use Phalcon\Test\Fixtures\Mvc\Collections\Documents\RobotPart;
use Phalcon\Test\Fixtures\Traits\DiTrait;

/**
 * Class ConstructCest
 */
class ConstructCest
{
    use DiTrait;

    public function _before()
    {
        $this->setNewFactoryDefault();
        $this->setDiCollectionManager();
        $this->setDiMongo();
    }

    /**
     * Tests Phalcon\Mvc\Collection\Document :: __construct()
     *
     * @param IntegrationTester $I
     * @since  2018-11-13
     * @author Phalcon Team <team@phalconphp.com>
     */
    public function mvcCollectionDocumentConstruct(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Collection\Document - offsetExists()');

        $robotPart = new RobotPart;
        $I->assertInstanceOf(RobotPart::class, $robotPart);
    }
}
