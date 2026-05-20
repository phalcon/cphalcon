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

namespace Phalcon\Tests\Unit\Support\Debug;

use Exception;
use Phalcon\Support\Debug;
use Phalcon\Tests\AbstractUnitTestCase;

final class OnUncaughtExceptionTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportDebugOnUncaughtException(): void
    {
        $debug = new Debug();
        $debug->setShowBackTrace(false);
        $debug->setShowFiles(false);

        $exception = new Exception('test exception message');

        // onUncaughtException unconditionally closes whatever output
        // buffer is active before echoing its render — including
        // PHPUnit's per-test capture. PHPUnit flags this as a "risky"
        // test because the production code closed a buffer it didn't
        // own, but the assertion below still runs and passes. There
        // is no portable way to exercise this method from a phpunit
        // context without that warning; the render output itself is
        // covered by RenderHtmlTest.
        $this->expectOutputRegex('/test exception message/');

        $this->assertTrue($debug->onUncaughtException($exception));
    }
}
