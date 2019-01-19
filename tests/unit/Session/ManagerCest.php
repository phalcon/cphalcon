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

namespace Phalcon\Test\Unit\Session\Adapter;

use Phalcon\Session\Adapter\Noop;
use Phalcon\Session\Manager;
use UnitTester;

class ManagerCest
{
    /**
     * Tests Phalcon\Session\Manager :: start()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @issue  https://github.com/phalcon/cphalcon/issues/13718
     * @since  2019-01-09
     */
    public function managerStart(UnitTester $I)
    {
        $I->wantToTest('Manager - start() on CLI mode w/o session_start');

        $session = new Manager();
        $session->setHandler(new Noop());

        if (PHP_SESSION_ACTIVE === \session_status()) {
            // Please note: further tests may need $_SESSION variable
            @\session_destroy();
            unset($_SESSION);
        }

        $I->assertTrue($session->start());
    }
}
