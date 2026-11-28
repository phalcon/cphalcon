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

namespace Phalcon\Tests\Unit\Mvc\Micro;

use Phalcon\Mvc\Micro;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

class SetResponseHandlerTest extends AbstractUnitTestCase
{
    /**
     * Tests Phalcon\Mvc\Micro :: setResponseHandler()
     */
    public function testMicroResponseHandler(): void
    {
        $trace = [];

        $app = new Micro();

        $app->setResponseHandler(
            function () use (&$trace) {
                $trace[] = 1;
            }
        );

        $app->map(
            '/blog',
            function () use (&$trace) {
                $trace[] = 1;
            }
        );

        $app->handle('/blog');

        $this->assertCount(2, $trace);
    }

    /**
     * A response handler that is false: handle() uses the default response,
     * the same as cphalcon.
     *
     * @issue  https://github.com/phalcon/phalcon/issues/820
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-17
     */
    public function testMicroResponseHandlerFalse(): void
    {
        $app = new Micro();

        $app->setResponseHandler(false);

        $app->map(
            '/blog',
            function () {
                return 'hello';
            }
        );

        $this->expectOutputString('hello');

        $actual = $app->handle('/blog');
        $this->assertSame('hello', $actual);
    }
}
