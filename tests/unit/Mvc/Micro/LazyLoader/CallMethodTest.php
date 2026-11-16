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

namespace Phalcon\Tests\Unit\Mvc\Micro\LazyLoader;

use Phalcon\Mvc\Micro\LazyLoader;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Tests\Support\Micro\LazyLoaderHandler;
use Phalcon\Tests\Support\Traits\ErrorHandlerTrait;

class CallMethodTest extends AbstractUnitTestCase
{
    use ErrorHandlerTrait;

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcMicroLazyloaderCallMethod(): void
    {
        $loader = new LazyLoader(LazyLoaderHandler::class);
        $result = $loader->callMethod('greet', ['name' => 'Phalcon']);
        $this->assertSame('Hello Phalcon', $result);
    }

    /**
     * A method that cannot be called gives a warning and null, the same as
     * cphalcon.
     *
     * @issue  https://github.com/phalcon/phalcon/issues/815
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-16
     */
    public function testMvcMicroLazyloaderCallMethodNotCallable(): void
    {
        $loader = new LazyLoader(LazyLoaderHandler::class);

        [$actual, $messages] = $this->collectErrors(
            static fn () => $loader->callMethod('unknownMethod', [])
        );

        $this->assertNull($actual);
        $this->assertSame(
            ['class ' . LazyLoaderHandler::class . ' does not have a method "unknownMethod"'],
            $messages
        );
    }
}
