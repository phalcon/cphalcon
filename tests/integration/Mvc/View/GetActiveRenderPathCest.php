<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Mvc\View;

use function dataDir;
use const DIRECTORY_SEPARATOR;
use IntegrationTester;
use Phalcon\Events\Manager;
use Phalcon\Mvc\View;
use Phalcon\Test\Fixtures\Mvc\View\AfterRenderListener;

/**
 * Class GetActiveRenderPathCest
 */
class GetActiveRenderPathCest
{
    /**
     * Tests Phalcon\Mvc\View :: getActiveRenderPath()
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/12139
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-08-14
     */
    public function mvcViewGetActiveRenderPath(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\View - getActiveRenderPath()');

        $eventsManager = new Manager();
        $eventsManager->attach('view', new AfterRenderListener());

        $view = new View();
        $view->setViewsDir(dataDir('views' . DIRECTORY_SEPARATOR));
        $view->setRenderLevel(View::LEVEL_ACTION_VIEW);
        $view->setEventsManager($eventsManager);

        $expected = '';
        $actual   = $view->getActiveRenderPath();
        $I->assertEquals($expected, $actual);

        $view->start();
        $view->render('activerender', 'index');
        $view->finish();

        $view->getContent();

        $I->assertEquals(
            dataDir('views' . DIRECTORY_SEPARATOR . 'activerender' . DIRECTORY_SEPARATOR . 'index.phtml'),
            $view->getActiveRenderPath()
        );

        $view->setViewsDir([
            dataDir('views' . DIRECTORY_SEPARATOR),
            dataDir('views2' . DIRECTORY_SEPARATOR),
        ]);

        $I->assertEquals(
            [dataDir('views' . DIRECTORY_SEPARATOR . 'activerender' . DIRECTORY_SEPARATOR . 'index.phtml')],
            $view->getActiveRenderPath()
        );
    }
}
