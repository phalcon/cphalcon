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
use Phalcon\Http\Response;
use Phalcon\Mvc\Micro;

class ErrorCest
{
    /**
     * Tests Phalcon\Mvc\Micro :: error()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-04-16
     */
    public function mvcMicroError(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Micro - error()');

        $app = new Micro();

        $response = new Response();

        $app->map(
            '/say/hello/{name}',
            function ($name) use ($response) {
                if (is_numeric($name)) {
                    throw new \Exception(
                        'Not a human name.'
                    );
                }

                $response->setContent("Hello {$name}!");
            }
        );

        $app->error(
            function ($exception) use ($response) {
                $response->setContent(
                    'ERROR: ' . $exception->getMessage()
                );

                return false;
            }
        );

        $app->setResponseHandler(
            function () use ($response) {
                return $response->getContent();
            }
        );

        $I->assertEquals(
            'Hello sid!',
            $app->handle('/say/hello/sid')
        );

        $I->assertEquals(
            'ERROR: Not a human name.',
            $app->handle('/say/hello/123')
        );
    }
}
