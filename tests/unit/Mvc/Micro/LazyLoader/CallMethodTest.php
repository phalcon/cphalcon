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
use TypeError;

class CallMethodTest extends AbstractUnitTestCase
{
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
     * A method that cannot be called throws the TypeError of
     * call_user_func_array().
     *
     * @issue  https://github.com/phalcon/phalcon/issues/815
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-16
     */
    public function testMvcMicroLazyloaderCallMethodNotCallable(): void
    {
        $loader = new LazyLoader(LazyLoaderHandler::class);

        $this->expectException(TypeError::class);
        $this->expectExceptionMessage(
            'call_user_func_array(): Argument #1 ($callback) must be a valid callback, '
            . 'class ' . LazyLoaderHandler::class . ' does not have a method "unknownMethod"'
        );

        $loader->callMethod('unknownMethod', []);
    }
}
