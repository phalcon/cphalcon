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

namespace Phalcon\Test\Integration\Mvc\View;

use IntegrationTester;
use Phalcon\Mvc\View;
use Phalcon\Test\Fixtures\Traits\ViewTrait;

class SetMainViewCest
{
    use ViewTrait;

    /**
     * Tests Phalcon\Mvc\View :: setMainView()
     *
     * @author Kamil Skowron <git@hedonsoftware.com>
     * @since  2014-05-28
     */
    public function testOverrideMainView(IntegrationTester $I)
    {
        $view = new View();

        $view->setViewsDir(
            dataDir('fixtures/views')
        );

        $view->setMainView('layouts/currentrender');

        $view->start();
        $view->render('simple', 'index');
        $view->finish();

        $I->assertEquals(
            'lolWe are here',
            $view->getContent()
        );
    }
}
