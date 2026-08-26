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

namespace Phalcon\Tests\Unit\Mvc\Micro;

use Phalcon\Di\FactoryDefault;
use Phalcon\Events\Manager;
use Phalcon\Mvc\Micro;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use PHPUnit\Framework\Attributes\BackupGlobals;

/**
 * A `false` from a `micro:beforeHandleRoute` listener is final: a later
 * listener returning `true` cannot re-open the request.
 */
#[BackupGlobals(true)]
final class BeforeHandleRouteDenyTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-26
     */
    public function testMvcMicroBeforeHandleRouteDenyIsFinal(): void
    {
        $di      = new FactoryDefault();
        $micro   = new Micro($di);
        $manager = new Manager();
        $manager->attach('micro:beforeHandleRoute', function () {
            return false;
        });
        $manager->attach('micro:beforeHandleRoute', function () {
            return true;
        });
        $micro->setEventsManager($manager);

        $handled = false;
        $micro->get(
            '/test',
            function () use (&$handled) {
                $handled = true;

                return 'test';
            }
        );

        $_SERVER['REQUEST_METHOD'] = 'GET';

        $actual = $micro->handle('/test');

        $this->assertFalse($actual);
        $this->assertFalse($handled);
    }
}
