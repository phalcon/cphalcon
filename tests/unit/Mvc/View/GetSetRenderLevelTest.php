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

namespace Phalcon\Tests\Unit\Mvc\View;

use Phalcon\Events\Manager;
use Phalcon\Mvc\View;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Mvc\View\AfterRenderListener;
use Phalcon\Tests\Support\Traits\DiTrait;

use const DIRECTORY_SEPARATOR;

class GetSetRenderLevelTest extends AbstractUnitTestCase
{
    use DiTrait;

    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/907
     * @author Volodymyr Kolesnykov <volodymyr@wildwolf.name>
     * @since  2013-10-03
     */
    public function testMvcViewGetSetRenderLevel(): void
    {
        $listener      = new AfterRenderListener();
        $eventsManager = new Manager();
        $eventsManager->attach('view', $listener);

        $this->setNewFactoryDefault();
        $this->setDiService('view');
        $view = $this->getService('view');

        $view->setViewsDir(supportDir('assets/views' . DIRECTORY_SEPARATOR));
        $view->setEventsManager($eventsManager);

        $view->start();
        $view->render('currentrender', 'other');
        $view->finish();
//         $this->assertEquals("lolhere\n", $view->getContent());
        $this->assertEquals('lolhere', $view->getContent());
//         $this->assertEquals('1,3,5', $listener->getLevels());
        $this->assertEquals('1,3', $listener->getLevels());

        $listener->reset();
        $view->setTemplateAfter('currentrender-after');
        $view->start();
        $view->render('currentrender', 'other');
        $view->finish();
//         $this->assertEquals("zuplolhere\n", $view->getContent());
        $this->assertEquals('zuplolhere', $view->getContent());
//         $this->assertEquals('1,3,4,5', $listener->getLevels());
        $this->assertEquals('1,3,4', $listener->getLevels());

        $listener->reset();
        $view->cleanTemplateAfter();
        $view->setRenderLevel(View::LEVEL_MAIN_LAYOUT);
        $view->start();
        $view->render('currentrender', 'other');
        $view->finish();

//         $this->assertEquals("lolhere\n", $view->getContent());
        $this->assertEquals('lolhere', $view->getContent());
//         $this->assertEquals('1,3,5', $listener->getLevels());
        $this->assertEquals('1,3', $listener->getLevels());

        $listener->reset();
        $view->setRenderLevel(View::LEVEL_LAYOUT);
        $view->start();
        $view->render('currentrender', 'other');
        $view->finish();
        $this->assertEquals('lolhere', $view->getContent());
        $this->assertEquals('1,3', $listener->getLevels());

        $listener->reset();
        $view->setRenderLevel(View::LEVEL_ACTION_VIEW);
        $view->start();
        $view->render('currentrender', 'other');
        $view->finish();
        $this->assertEquals('here', $view->getContent());
        $this->assertEquals('1', $listener->getLevels());

        $listener->reset();
    }
}
