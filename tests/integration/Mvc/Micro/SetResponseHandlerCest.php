<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Mvc\Micro;

use IntegrationTester;
use Phalcon\Mvc\Micro;

/**
 * Class SetResponseHandlerCest
 */
class SetResponseHandlerCest
{
    /**
     * Tests Phalcon\Mvc\Micro :: setResponseHandler()
     *
     * @param IntegrationTester $I
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
            "/blog",
            function () use (&$trace) {
                $trace[] = 1;
            }
        );

        $app->handle("/blog");

        $I->assertCount(2, $trace);
    }
}
