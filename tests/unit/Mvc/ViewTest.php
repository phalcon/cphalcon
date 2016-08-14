<?php

namespace Phalcon\Test\Unit\Mvc;

use Phalcon\Di;
use Phalcon\Mvc\View;
use Phalcon\Events\Manager;
use Phalcon\Test\Module\UnitTest;
use Phalcon\Test\Module\ViewAfterRenderListener;

/**
 * \Phalcon\Test\Unit\Mvc\ViewTest
 * Tests the Phalcon\Mvc\View component
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Unit\Mvc
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class ViewTest extends UnitTest
{
    /**
     * executed before each test
     */
    protected function _before()
    {
        $di = $this->tester->getApplication()->getDI();

        Di::setDefault($di);
    }

    /**
     * Tests the View::getActiveRenderPath
     *
     * @issue  12139
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2014-08-14
     */
    public function testGetActiveRenderPath()
    {
        $this->specify(
            'The View::getActiveRenderPath returns unexpected result',
            function () {
                $view = new View;

                $eventsManager = new Manager;
                $eventsManager->attach('view', new ViewAfterRenderListener);

                $view->setViewsDir(PATH_DATA . 'views');
                $view->setRenderLevel(View::LEVEL_ACTION_VIEW);
                $view->setEventsManager($eventsManager);

                expect($view->getActiveRenderPath())->equals('');

                $view->start();
                $view->render('test15', 'index');
                $view->finish();

                $view->getContent();

                expect($view->getActiveRenderPath())->equals(
                    PATH_DATA . 'views' . DIRECTORY_SEPARATOR . 'test15' . DIRECTORY_SEPARATOR . 'index.phtml'
                );

                $view->setViewsDir([
                    PATH_DATA . 'views',
                    PATH_DATA . 'views2',
                ]);

                expect($view->getActiveRenderPath())->equals(
                    [PATH_DATA . 'views' . DIRECTORY_SEPARATOR . 'test15' . DIRECTORY_SEPARATOR . 'index.phtml']
                );
            }
        );
    }
}
