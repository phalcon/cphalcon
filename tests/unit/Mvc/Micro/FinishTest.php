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

namespace Phalcon\Tests\Unit\Mvc\Micro;

use Phalcon\Mvc\Micro;
use Phalcon\Tests\AbstractUnitTestCase;

class FinishTest extends AbstractUnitTestCase
{
    /**
     * Tests Phalcon\Mvc\Micro :: finish()
     */
    public function testMicroFinishHandlers(): void
    {
        $trace = [];

        $app = new Micro();

        $app->finish(
            function () use (&$trace) {
                $trace[] = 1;
            }
        );

        $app->finish(
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

        $this->assertCount(3, $trace);
    }

    /**
     * Tests Phalcon\Mvc\Micro :: finish()
     */
    public function testMicroFinishHandlersIfOneStop(): void
    {
        $trace = [];

        $app = new Micro();

        $app->finish(
            function () use (&$trace) {
                $trace[] = 1;
            }
        );

        $app->finish(
            function () use ($app, &$trace) {
                $trace[] = 1;

                $app->stop();
            }
        );

        $app->finish(
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

        $this->assertCount(3, $trace);
    }
}
