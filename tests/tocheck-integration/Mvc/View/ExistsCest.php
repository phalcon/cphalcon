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

namespace Phalcon\Test\Integration\Mvc\View;

use IntegrationTester;
use Phalcon\Di;
use Phalcon\Helper\Str;
use Phalcon\Mvc\View;

use function dataDir;

class ExistsCest
{
    /**
     * Tests Phalcon\Mvc\View :: exists()
     *
     * @author Kamil Skowron <git@hedonsoftware.com>
     * @since  2014-05-28
     */
    public function mvcViewExists(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\View - exists()');

        $container = new Di();

        $view = new View();

        $view->setViewsDir(
            Str::dirSeparator(dataDir('fixtures/views'))
        );

        $view->setDI($container);

        $I->assertTrue(
            $view->exists('currentrender/query')
        );

        $I->assertTrue(
            $view->exists('currentrender/yup')
        );

        $I->assertFalse(
            $view->exists('currentrender/nope')
        );
    }
}
