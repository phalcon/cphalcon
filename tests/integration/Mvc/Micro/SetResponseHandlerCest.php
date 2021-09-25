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
 * Class SetResponseHandlerCest
 */
class SetResponseHandlerCest
{
    /**
     * Tests Phalcon\Mvc\Micro :: setResponseHandler()
     */
    public function testMicroResponseHandler(IntegrationTester $I)
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

        $I->assertCount(2, $trace);
    }
}
