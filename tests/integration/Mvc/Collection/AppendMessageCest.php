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
use Phalcon\Messages\MessageInterface;
use Phalcon\Test\Fixtures\Mvc\Collections\Robots;
use Phalcon\Test\Fixtures\Traits\DiTrait;

/**
 * Class AppendMessageCest
 */
class AppendMessageCest
{
    use DiTrait;

    public function _before()
    {
        $this->setNewFactoryDefault();
        $this->setDiCollectionManager();
        $this->setDiMongo();
    }

    /**
     * Tests Phalcon\Mvc\Collection :: appendMessage()
     *
     * @param IntegrationTester $I
     * @since  2018-11-13
     * @author Phalcon Team <team@phalconphp.com>
     */
    public function mvcCollectionAppendMessage(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Collection - appendMessage()');

        $robot = new Robots;
        $robot->version = 0; // If version < 0, message appened !

        $I->assertFalse($robot->save());
        $I->assertNotEmpty($robot->getMessages());
        $I->assertInstanceOf(MessageInterface::class, $robot->getMessages()[0]);
    }
}
