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

namespace Phalcon\Test\Integration\Session\Bag;

use IntegrationTester;
use Phalcon\Session\Bag;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Fixtures\Traits\SessionBagTrait;

/**
 * Class OffsetExistsCest
 */
class OffsetExistsCest
{
    use DiTrait;
    use SessionBagTrait;

    /**
     * Tests Phalcon\Session\Bag :: offsetExists()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function sessionBagOffsetExists(IntegrationTester $I)
    {
        $I->wantToTest("Session\Bag - offsetExists()");
        $session = new Bag("SetTest");

        $testValue = "TestValue";
        $session->set("test", $testValue);

        $I->assertTrue($session->offsetExists("test"));
        $I->assertFalse($session->offsetExists("unknown"));
    }
}
