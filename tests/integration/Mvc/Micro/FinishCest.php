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

namespace Phalcon\Tests\Integration\Mvc\Micro;

use IntegrationTester;
use Phalcon\Mvc\Micro;

/**
 * Class FinishCest
 */
class FinishCest
{
    /**
     * Tests Phalcon\Mvc\Micro :: finish()
     */
    public function testMicroFinishHandlers(IntegrationTester $I)
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

        $I->assertCount(3, $trace);
    }

    /**
     * Tests Phalcon\Mvc\Micro :: finish()
     */
    public function testMicroFinishHandlersIfOneStop(IntegrationTester $I)
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

        $I->assertCount(3, $trace);
    }
}
