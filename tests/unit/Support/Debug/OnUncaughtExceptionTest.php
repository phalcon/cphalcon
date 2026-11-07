<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Support\Debug;

use Phalcon\Support\Debug;
use Phalcon\Support\Debug\Renderer\HtmlRenderer;
use Phalcon\Support\Debug\Report\ExceptionReport;
use Phalcon\Support\Exception;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use ReflectionProperty;
use RuntimeException;

final class OnUncaughtExceptionTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportDebugOnUncaughtException(): void
    {
        $message = uniqid('var-');
        $debug   = new Debug();
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
     * @issue  https://github.com/phalcon/cphalcon/issues/17733
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-06
     */
    public function testSupportDebugOnUncaughtExceptionResetsActiveWhenRenderThrows(): void
    {
        $renderer = new class () extends HtmlRenderer {
            public function render(ExceptionReport $report): string
            {
                throw new RuntimeException('render failed');
            }
        };

        $debug = new Debug();
        $debug->setRenderer($renderer);
        $debug->setShowBackTrace(false);

        $thrown = null;

        /**
         * The handler clears one output-buffer level. Clear the other one here.
         */
        ob_start();
        ob_start();
        try {
            $debug->onUncaughtException(new Exception('boom', 1234));
        } catch (RuntimeException $ex) {
            $thrown = $ex;
        }
        ob_end_clean();

        $isActive = new ReflectionProperty(Debug::class, 'isActive');
        $actual   = $isActive->getValue();
        $isActive->setValue(null, false);

        $this->assertInstanceOf(RuntimeException::class, $thrown);
        $this->assertSame('render failed', $thrown->getMessage());
        $this->assertFalse($actual);
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
        $isActive->setValue(null, true);

        ob_start();
        ob_start();
        $result = $debug->onUncaughtException($exception);
        $actual = ob_get_clean();

        $isActive->setValue(null, false);

        $this->assertFalse($result);
        $this->assertStringContainsString($message, $actual);
    }

    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/17733
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-06
     */
    public function testSupportDebugOnUncaughtExceptionWhenAlreadyActiveEscapesMessage(): void
    {
        $debug     = new Debug();
        $exception = new Exception('<script>alert("x")</script>', 1234);

        $isActive = new ReflectionProperty(Debug::class, 'isActive');
        $isActive->setValue(null, true);

        ob_start();
        ob_start();
        $result = $debug->onUncaughtException($exception);
        $actual = ob_get_clean();

        $isActive->setValue(null, false);

        $this->assertFalse($result);
        $this->assertSame('&lt;script&gt;alert(&quot;x&quot;)&lt;/script&gt;', $actual);
    }
}
