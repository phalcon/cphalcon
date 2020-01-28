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
use Phalcon\Events\Manager;
use Phalcon\Mvc\View;
use Phalcon\Test\Fixtures\Mvc\View\AfterRenderListener;

use function dataDir;

use const DIRECTORY_SEPARATOR;

/**
 * Class GetSetRenderLevelCest
 */
class GetSetRenderLevelCest
{
    /**
     * Tests Phalcon\Mvc\View :: setRenderLevel()
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/907
     *
     * @author Volodymyr Kolesnykov <volodymyr@wildwolf.name>
     * @since  2013-10-03
     */
    public function mvcViewGetSetRenderLevel(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\View - setRenderLevel()');

        $listener      = new AfterRenderListener();
        $eventsManager = new Manager();
        $eventsManager->attach('view', $listener);

        $view = new View();
        $view->setViewsDir(dataDir('fixtures/views' . DIRECTORY_SEPARATOR));
        $view->setEventsManager($eventsManager);

        $view->start();
        $view->render('currentrender', 'other');
        $view->finish();
//        $I->assertEquals("lolhere\n", $view->getContent());
        $I->assertEquals('lolhere', $view->getContent());
//        $I->assertEquals('1,3,5', $listener->getLevels());
        $I->assertEquals('1,3', $listener->getLevels());

        $listener->reset();
        $view->setTemplateAfter('currentrender-after');
        $view->start();
        $view->render('currentrender', 'other');
        $view->finish();
//        $I->assertEquals("zuplolhere\n", $view->getContent());
        $I->assertEquals('zuplolhere', $view->getContent());
//        $I->assertEquals('1,3,4,5', $listener->getLevels());
        $I->assertEquals('1,3,4', $listener->getLevels());

        $listener->reset();
        $view->cleanTemplateAfter();
        $view->setRenderLevel(View::LEVEL_MAIN_LAYOUT);
        $view->start();
        $view->render('currentrender', 'other');
        $view->finish();

//        $I->assertEquals("lolhere\n", $view->getContent());
        $I->assertEquals('lolhere', $view->getContent());
//        $I->assertEquals('1,3,5', $listener->getLevels());
        $I->assertEquals('1,3', $listener->getLevels());

        $listener->reset();
        $view->setRenderLevel(View::LEVEL_LAYOUT);
        $view->start();
        $view->render('currentrender', 'other');
        $view->finish();
        $I->assertEquals('lolhere', $view->getContent());
        $I->assertEquals('1,3', $listener->getLevels());

        $listener->reset();
        $view->setRenderLevel(View::LEVEL_ACTION_VIEW);
        $view->start();
        $view->render('currentrender', 'other');
        $view->finish();
        $I->assertEquals('here', $view->getContent());
        $I->assertEquals('1', $listener->getLevels());

        $listener->reset();
    }
}
