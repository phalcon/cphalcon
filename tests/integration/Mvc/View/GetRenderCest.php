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

namespace Phalcon\Tests\Integration\Mvc\View;

use IntegrationTester;
use Phalcon\Di;
use Phalcon\Helper\Str;
use Phalcon\Mvc\View;

use function dataDir;

class GetRenderCest
{
    /**
     * Tests Phalcon\Mvc\View :: getRender()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcViewGetRender(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\View - getRender()');

        $container = new Di();

        $view = new View();

        $view->setViewsDir(
            $I->getDirSeparator(dataDir('fixtures/views'))
        );

        $view->setDI($container);

        $actual = $view->getRender(
            'partials',
            'partial',
            [
                'cool_var' => 'abcde',
            ]
        );

        $I->assertEquals(
            'Hey, this is a partial, also abcde',
            $actual
        );
    }
}
