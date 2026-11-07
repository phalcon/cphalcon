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
        $message   = uniqid('var-');
        $exception = new Exception($message, 1234);

        /**
         * The handler discards only the buffers that start after the object
         * is created. Create the object inside the buffer that the test reads.
         */
        ob_start();
        $debug = new Debug();
        $debug->setShowBackTrace(false);
        $result = $debug->onUncaughtException($exception);
        $actual = ob_get_clean();

        $this->assertTrue($result);
        $this->assertStringContainsString('<!DOCTYPE html>', $actual);
        $this->assertStringContainsString($message, $actual);
    }

    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/17739
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-06
     */
    public function testSupportDebugOnUncaughtExceptionDiscardsNestedBuffers(): void
    {
        $exception = new Exception('boom', 1234);

        ob_start();
        $debug = new Debug();
        $debug->setShowBackTrace(false);

        ob_start();
        echo 'layout-content';
        ob_start();
        echo 'partial-content';
        $result = $debug->onUncaughtException($exception);
        $actual = ob_get_clean();

        $this->assertTrue($result);
        $this->assertStringStartsWith('<!DOCTYPE html>', $actual);
        $this->assertStringNotContainsString('layout-content', $actual);
        $this->assertStringNotContainsString('partial-content', $actual);
    }

    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/17739
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-06
     */
    public function testSupportDebugOnUncaughtExceptionKeepsBufferStartedBeforeDebug(): void
    {
        $exception = new Exception('boom', 1234);

        ob_start();
        echo 'before-debug';
        $debug = new Debug();
        $debug->setShowBackTrace(false);

        ob_start();
        echo 'after-debug';
        $result = $debug->onUncaughtException($exception);
        $actual = ob_get_clean();

        $this->assertTrue($result);
        $this->assertStringStartsWith('before-debug<!DOCTYPE html>', $actual);
        $this->assertStringNotContainsString('after-debug', $actual);
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

        $thrown = null;

        ob_start();
        $debug = new Debug();
        $debug->setRenderer($renderer);
        $debug->setShowBackTrace(false);

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
        $exception = new Exception($message, 1234);

        $isActive = new ReflectionProperty(Debug::class, 'isActive');
        $isActive->setValue(null, true);

        ob_start();
        $debug  = new Debug();
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
        $exception = new Exception('<script>alert("x")</script>', 1234);

        $isActive = new ReflectionProperty(Debug::class, 'isActive');
        $isActive->setValue(null, true);

        ob_start();
        $debug  = new Debug();
        $result = $debug->onUncaughtException($exception);
        $actual = ob_get_clean();

        $isActive->setValue(null, false);

        $this->assertFalse($result);
        $this->assertSame('&lt;script&gt;alert(&quot;x&quot;)&lt;/script&gt;', $actual);
    }
}
