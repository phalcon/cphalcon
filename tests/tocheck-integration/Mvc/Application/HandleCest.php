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

namespace Phalcon\Test\Integration\Mvc\Application;

use IntegrationTester;
use Phalcon\Di\FactoryDefault;
use Phalcon\Mvc\Application;
use Phalcon\Mvc\View;

class HandleCest
{
    public function singleModule(IntegrationTester $I)
    {
        $I->skipTest('TODO - Check me');

        $I->wantTo('handle request and get content by using single modules strategy');

        $di = new FactoryDefault();

        $di->set(
            'view',
            function () {
                $view = new View();

                $view->setViewsDir(
                    dataDir('fixtures/views/')
                );

                return $view;
            },
            true
        );

        $application = new Application();

        $application->setDI($di);

        $response = $application->handle('/micro');

        $I->assertEquals(
            '<html>We are here</html>' . PHP_EOL,
            $response->getContent()
        );
    }
}
