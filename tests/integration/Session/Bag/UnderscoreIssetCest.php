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
 * Class UnderscoreIssetCest
 */
class UnderscoreIssetCest
{
    use DiTrait;
    use SessionBagTrait;

    /**
     * Tests Phalcon\Session\Bag :: __isset()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function sessionBagUnderscoreIsset(IntegrationTester $I)
    {
        $I->wantToTest("Session\Bag - __isset()");
        $session = new Bag("SetterTest");

        $testValue = "TestValue";
        $session->set("test", $testValue);

        $I->assertTrue(isset($session->test));
        $I->assertFalse(isset($session->unknown));
    }
}
