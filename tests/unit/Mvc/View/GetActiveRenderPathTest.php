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
use Phalcon\Tests\Support\Mvc\View\AfterRenderListener;
use Phalcon\Tests\AbstractUnitTestCase;

use function dataDir;

use const DIRECTORY_SEPARATOR;

class GetActiveRenderPathTest extends AbstractUnitTestCase
{
    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/12139
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-08-14
     */
    public function testMvcViewGetActiveRenderPath(): void
    {
        $eventsManager = new Manager();
        $eventsManager->attach('view', new AfterRenderListener());

        $view = new View();
        $view->setViewsDir(dataDir('views' . DIRECTORY_SEPARATOR));
        $view->setRenderLevel(View::LEVEL_ACTION_VIEW);
        $view->setEventsManager($eventsManager);

        $expected = '';
        $actual   = $view->getActiveRenderPath();
        $this->assertEquals($expected, $actual);

        $view->start();
        $view->render('activerender', 'index');
        $view->finish();

        $view->getContent();

        $this->assertEquals(
            dataDir('views' . DIRECTORY_SEPARATOR . 'activerender' . DIRECTORY_SEPARATOR . 'index.phtml'),
            $view->getActiveRenderPath()
        );

        $view->setViewsDir([
            dataDir('views' . DIRECTORY_SEPARATOR),
            dataDir('views2' . DIRECTORY_SEPARATOR),
        ]);

        $this->assertEquals(
            [dataDir('views' . DIRECTORY_SEPARATOR . 'activerender' . DIRECTORY_SEPARATOR . 'index.phtml')],
            $view->getActiveRenderPath()
        );
    }
}
