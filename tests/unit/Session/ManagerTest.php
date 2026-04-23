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

use Phalcon\Session\Adapter\Noop;
use Phalcon\Session\Manager;
use Phalcon\Tests\AbstractUnitTestCase;
use PHPUnit\Framework\Attributes\DataProvider;

use function session_abort;
use function session_destroy;
use function session_name;
use function session_status;

use const PHP_SESSION_ACTIVE;

final class ManagerTest extends AbstractUnitTestCase
{
    /**
     * @return array[]
     */
    public static function providerSessionValues(): array
    {
        return [
            ['valid', true],
            ['./invalid', false],
        ];
    }

    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/13718
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-01-09
     */
    public function testSessionManagerStart(): void
    {
        $session = new Manager();
        $session->setAdapter(new Noop());

        if (PHP_SESSION_ACTIVE === session_status()) {
            // Please note: further tests may need $_SESSION variable
            @session_destroy();
            unset($_SESSION);
        }

        $actual = $session->start();
        $this->assertTrue($actual);
        $session->destroy();
    }

    /**
     * @dataProvider providerSessionValues
     *
     * @since   2021-02-02
     */
    #[DataProvider('providerSessionValues')]
    public function testValidateSessionValue(
        string $session,
        bool $expected
    ): void {
        $name = session_name();
        if (PHP_SESSION_ACTIVE === session_status()) {
            // Please note: further tests may need $_SESSION variable
            @session_destroy();
            @session_abort();
            unset($_SESSION);
        }

        // Create fake session cookie
        $_COOKIE[$name] = $session;

        // Start Session
        $session = new Manager();
        $session->setAdapter(new Noop());
        $session->start();

        // Check if session value has been sanitized
        $actual = isset($_COOKIE[$name]);
        $this->assertSame($expected, $actual);
        $session->destroy();
    }
}
