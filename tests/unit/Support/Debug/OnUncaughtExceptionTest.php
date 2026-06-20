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

use Phalcon\Support\Debug;
use Phalcon\Support\Exception;
use Phalcon\Tests\AbstractUnitTestCase;
use ReflectionProperty;

final class OnUncaughtExceptionTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportDebugOnUncaughtException(): void
    {
        $message = uniqid('var-');
        $debug = new Debug();
        $debug->setShowBackTrace(false);
        $exception = new Exception($message, 1234);

        /**
         * The handler clears one active output-buffer level and echoes the
         * rendered HTML, so wrap the call in two levels and read the outer one.
         */
        ob_start();
        ob_start();
        $result = $debug->onUncaughtException($exception);
        $actual = ob_get_clean();

        $this->assertTrue($result);
        $this->assertStringContainsString('<!DOCTYPE html>', $actual);
        $this->assertStringContainsString($message, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-20
     */
    public function testSupportDebugOnUncaughtExceptionWhenAlreadyActive(): void
    {
        $message   = uniqid('var-');
        $debug     = new Debug();
        $exception = new Exception($message, 1234);

        $isActive = new ReflectionProperty(Debug::class, 'isActive');
        $isActive->setAccessible(true);
        $isActive->setValue(null, true);

        ob_start();
        ob_start();
        $result = $debug->onUncaughtException($exception);
        $actual = ob_get_clean();

        $isActive->setValue(null, false);

        $this->assertFalse($result);
        $this->assertStringContainsString($message, $actual);
    }
}
