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
use TypeError;

class HandleTest extends AbstractUnitTestCase
{
    /**
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-04-17
     */
    public function testMvcMicroHandle(): void
    {
        $micro = new Micro();

        $micro->map(
            '/test',
            function () {
                return 'this is a test';
            }
        );

        $micro->map(
            '/hello/{name}',
            function ($name) {
                return 'Hi ' . ucfirst($name) . '!';
            }
        );


        // Micro echoes out its result as well
        ob_start();
        $testResult = $micro->handle('/test');
        ob_end_clean();

        $this->assertEquals(
            'this is a test',
            $testResult
        );


        // Micro echoes out its result as well
        ob_start();
        $helloSidResult = $micro->handle('/hello/sid');
        ob_end_clean();

        $this->assertEquals(
            'Hi Sid!',
            $helloSidResult
        );
    }

    /**
     * A handler that cannot be called throws the TypeError of
     * call_user_func_array(). The finish handlers do not run.
     *
     * @issue  https://github.com/phalcon/phalcon/issues/815
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-16
     */
    public function testMvcMicroHandleNotCallable(): void
    {
        $micro    = new Micro();
        $finished = false;

        $micro->map('/fail', 'unknownHandlerFunction');
        $micro->finish(
            function () use (&$finished) {
                $finished = true;
            }
        );

        try {
            $micro->handle('/fail');
            $this->fail('No TypeError');
        } catch (TypeError $ex) {
            $this->assertSame(
                'call_user_func_array(): Argument #1 ($callback) must be a valid callback, '
                . 'function "unknownHandlerFunction" not found or invalid function name',
                $ex->getMessage()
            );
        }

        $this->assertFalse($finished);
    }
}
