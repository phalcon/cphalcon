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
 * Class CountCest
 */
class CountCest
{
    use DiTrait;
    use SessionBagTrait;

    /**
     * Tests Phalcon\Session\Bag :: count()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function sessionBagCount(IntegrationTester $I)
    {
        $I->wantToTest("Session\Bag - count()");
        $session        = new Bag("CountTest");
        $session->test1 = "test";
        $session->test2 = "test";
        $session->test3 = "test";

        $expected = 3;
        $I->assertEquals($expected, $session->count());
    }
}
