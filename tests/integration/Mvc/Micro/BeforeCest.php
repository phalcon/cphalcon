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

/**
 * Class BeforeCest
 */
class BeforeCest
{
    /**
     * Tests Phalcon\Mvc\Micro :: before()
     */
    public function testMicroBeforeHandlers(IntegrationTester $I)
    {
        $trace = [];

        $app = new Micro();

        $app->before(
            function () use ($app, &$trace) {
                $trace[] = 1;

                $app->stop();

                return false;
            }
        );

        $app->before(
            function () use ($app, &$trace) {
                $trace[] = 1;

                $app->stop();

                return false;
            }
        );

        $app->map(
            '/blog',
            function () use (&$trace) {
                $trace[] = 1;
            }
        );

        $app->handle('/blog');

        $I->assertCount(1, $trace);
    }
}
