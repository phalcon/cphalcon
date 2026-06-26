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

use Phalcon\Di\Di;
use Phalcon\Events\Manager;
use Phalcon\Mvc\View;
use Phalcon\Mvc\View\Engine\Php;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Mvc\View\AfterRenderListener;

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
            dataDir('views' . DIRECTORY_SEPARATOR . 'activerender' . DIRECTORY_SEPARATOR . 'index.phtml'),
            $view->getActiveRenderPath()
        );
    }

    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/16614
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-02
     */
    public function testMvcViewGetActiveRenderPathSingleDirMultipleEnginesNotFound(): void
    {
        $container     = new Di();
        $eventsManager = new Manager();

        $view = new View();
        $view->setDI($container);
        $view->setViewsDir(dataDir('views' . DIRECTORY_SEPARATOR));
        $view->setRenderLevel(View::LEVEL_ACTION_VIEW);
        $view->setEventsManager($eventsManager);
        $view->registerEngines(
            [
                '.volt'  => new Php($view),
                '.phtml' => new Php($view),
            ]
        );

        $view->start();
        $view->render('activerender', 'missing_file');
        $view->finish();

        $base   = dataDir('views' . DIRECTORY_SEPARATOR . 'activerender' . DIRECTORY_SEPARATOR . 'missing_file');
        $actual = $view->getActiveRenderPath();

        $this->assertIsArray($actual);
        $this->assertEquals(
            [$base . '.volt', $base . '.phtml'],
            $actual
        );
    }
}
