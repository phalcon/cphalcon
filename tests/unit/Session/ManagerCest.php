<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Unit\Session\Adapter;

use Phalcon\Session\Adapter\Noop;
use Phalcon\Session\Manager;
use Phalcon\Test\Fixtures\Session\NoopManager;
use UnitTester;

use function session_destroy;
use function session_status;

class ManagerCest
{
    /**
     * Tests Phalcon\Session\Manager :: start()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @issue  https://github.com/phalcon/cphalcon/issues/13718
     * @since  2019-01-09
     */
    public function managerStart(UnitTester $I)
    {
        $I->wantToTest('Manager - start() on CLI mode w/o session_start');

        $session = new Manager();

        $session->setAdapter(
            new Noop()
        );

        if (PHP_SESSION_ACTIVE === session_status()) {
            // Please note: further tests may need $_SESSION variable
            @session_destroy();
            unset($_SESSION);
        }

        $I->assertTrue(
            $session->start()
        );
    }

    /**
     * Tests Phalcon\Session\Manager :: start()
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @issue  https://github.com/phalcon/cphalcon/issues/14933
     * @since  2020-07-29
     */
    public function extendedManagerStart(UnitTester $I)
    {
        $I->wantToTest('Manager - start() on CLI mode w/o session_start with extending manager');

        $session = new NoopManager();

        if (PHP_SESSION_ACTIVE === session_status()) {
            // Please note: further tests may need $_SESSION variable
            @session_destroy();
            unset($_SESSION);
        }

        $I->assertInstanceOf(Noop::class, $session->getAdapter());
        $I->assertTrue($session->start());
    }
}
