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

use ErrorException;
use Phalcon\Support\Debug;
use Phalcon\Tests\AbstractUnitTestCase;

final class OnUncaughtLowSeverityTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportDebugOnUncaughtLowSeverity(): void
    {
        $this->expectException(ErrorException::class);
        $this->expectExceptionMessage('Test warning message');

        $debug = new Debug();

        /**
         * PHPUnit lowers error_reporting() to unhandleable levels while a test
         * runs, which masks out E_WARNING. Add it back so the handler guard
         * (error_reporting() & severity) is satisfied, then restore the level.
         */
        $previous = error_reporting(error_reporting() | E_WARNING);

        try {
            $debug->onUncaughtLowSeverity(E_WARNING, 'Test warning message', __FILE__, __LINE__);
        } finally {
            error_reporting($previous);
        }
    }
}
