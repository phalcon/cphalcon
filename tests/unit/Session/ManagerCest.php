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

namespace Phalcon\Tests\Unit\Session;

use Codeception\Example;
use Phalcon\Session\Adapter\Noop;
use Phalcon\Session\Manager;
use UnitTester;

use function session_abort;
use function session_destroy;
use function session_status;
use function session_name;

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
     * Tests to ensure that the session value is alpha numeric and won't
     * cause undefined behaviour when saving or reading sessions.
     *
     * @example {"session": "valid", "expected": true}
     * @example {"session": "./invalid", "expected": false}
     *
     * @since 2021-02-02
     */
    public function validateSessionValue(UnitTester $I, Example $example)
    {
        $name = session_name();
        $I->wantToTest('Manager - start() on CLI mode w/o session_start');

        if (PHP_SESSION_ACTIVE === session_status()) {
            // Please note: further tests may need $_SESSION variable
            @session_destroy();
            @session_abort();
            unset($_SESSION);
        }

        // Create fake session cookie
        $_COOKIE[$name] = $example["session"];

        // Start Session
        $session = new Manager();
        $session->setAdapter(
            new Noop()
        );

        $session->start();

        // Check if session value has been sanitized
        $I->assertEquals(
            $example["expected"],
            isset($_COOKIE[$name])
        );
    }
}
