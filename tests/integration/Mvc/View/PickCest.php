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
use Phalcon\Mvc\View;
use Phalcon\Tests\Fixtures\Traits\DiTrait;

use function dataDir;

class PickCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Mvc\View :: pick()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2013-01-07
     */
    public function mvcViewPick(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\View - pick()');

        $container = new Di();

        $view = new View();

        $view->setViewsDir(
            $I->getDirSeparator(dataDir('fixtures/views'))
        );

        $view->setDI($container);

        $view->start();
        $view->setLayout('pick');
        $view->pick('currentrender/other');
        $view->render('currentrender', 'another');
        $view->finish();

        $I->assertEquals(
            'Well, this is the view content: here.',
            $view->getContent()
        );


        $view->start();
        $view->setLayout('pick');
        $view->pick(['currentrender/other']);
        $view->render('currentrender', 'another');
        $view->finish();

        $I->assertEquals(
            'Well, this is the view content: here.',
            $view->getContent()
        );
    }
}
