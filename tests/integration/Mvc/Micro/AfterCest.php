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

namespace Phalcon\Test\Integration\Mvc\Micro;

use IntegrationTester;
use Phalcon\Mvc\Micro;

class AfterCest
{
    /**
     * Tests Phalcon\Mvc\Micro :: after()
     */
    public function testMicroAfterHandlers(IntegrationTester $I)
    {
        $trace = [];

        $app = new Micro();

        $app->after(
            function () use (&$trace) {
                $trace[] = 1;
            }
        );

        $app->after(
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
     * Tests Phalcon\Mvc\Micro :: after()
     */
    public function testMicroAfterHandlersIfOneStop(IntegrationTester $I)
    {
        $trace = [];

        $app = new Micro();

        $app->after(
            function () use (&$trace) {
                $trace[] = 1;
            }
        );

        $app->after(
            function () use ($app, &$trace) {
                $trace[] = 1;

                $app->stop();
            }
        );

        $app->after(
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

    public function testMicroResponseAlreadySentError(IntegrationTester $I)
    {
        $app = new Micro();

        $app->after(
            function () use ($app) {
                $content = $app->getReturnedValue();

                $app->response->setJsonContent($content)->send();
            }
        );

        $app->map(
            '/api',
            function () {
                return 'success';
            }
        );

        // Micro echoes out its result as well
        ob_start();
        $actual = $app->handle('/api');
        ob_end_clean();

        $I->assertEquals('success', $actual);
    }
}
