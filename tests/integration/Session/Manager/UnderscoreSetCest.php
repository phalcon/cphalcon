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

namespace Phalcon\Test\Integration\Session\Manager;

use IntegrationTester;

/**
 * Class __setCest
 *
 * @package Phalcon\Test\Integration\Session\Manager
 */
class UnderscoreSetCest
{
    /**
     * Tests Phalcon\Session\Manager :: __set()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function sessionManagerUnderscoreSet(IntegrationTester $I)
    {
        $I->wantToTest('Session\Manager - __set()');
        $I->skipTest('Need implementation');
    }
}
