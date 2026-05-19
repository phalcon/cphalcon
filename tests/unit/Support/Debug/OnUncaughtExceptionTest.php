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

        // onUncaughtException internally calls ob_end_clean() if any
        // output buffer is active, so we cannot capture its output here
        // without triggering PHPUnit's "closed unrelated buffer" check.
        // Verify the return contract only.
        $this->expectOutputRegex('/test exception message/');

        $this->assertTrue($debug->onUncaughtException($exception));
    }
}
