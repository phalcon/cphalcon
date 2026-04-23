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

namespace Phalcon\Tests\Database\Mvc;

use Phalcon\Tests\AbstractDatabaseTestCase;

final class ViewTest extends AbstractDatabaseTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2013-01-07
     */
    public function testOverrideLayout(): void
    {
        $this->markTestSkipped('Needs review - tocheck after migration');

        // $view = new View;
        // $view->setDI(Di::getDefault());
        // $view->setViewsDir(PATH_DATA . 'views' . DIRECTORY_SEPARATOR);
        // $view->start();
        // $view->setLayout('test6');
        // $view->render('test3', 'other');
        // $view->finish();
        // $this->assertEquals("<html>Well, this is the view content: here.</html>\n", $view->getContent());
    }

    /**
     * @author Kamil Skowron <git@hedonsoftware.com>
     * @since  2014-05-28
     */
    public function testMissingPartial(): void
    {
        $this->markTestSkipped('Needs review - tocheck after migration');

        // $view = new View;
        // $view->setDI(Di::getDefault());
        // $view->setViewsDir(PATH_DATA . 'views' . DIRECTORY_SEPARATOR);
        // $view->start();
        // $view->render('test5', 'missing');
        // $view->finish();
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2012-03-05
     */
    public function testStandardRender(): void
    {
        $this->markTestSkipped('Needs review - tocheck after migration');

        // $view = new View;
        // $view->setViewsDir(PATH_DATA . 'views' . DIRECTORY_SEPARATOR);
        // $view->start();
        // $view->render('test2', 'index');
        // $view->finish();
        // $this->assertEquals("<html>We are here</html>\n", $view->getContent());
        // ... (additional render assertions omitted)
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2012-05-28
     */
    public function testRenderingWithPartials(): void
    {
        $this->markTestSkipped('Needs review - tocheck after migration');

        // $view = new View;
        // $view->setViewsDir(PATH_DATA . 'views' . DIRECTORY_SEPARATOR);
        // $view->setParamToView('cool_var', 'le-this');
        // $view->start();
        // $view->render('test5', 'index');
        // $view->finish();
        // $this->assertEquals("<html>Hey, this is a partial, also le-this</html>\n", $view->getContent());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-02
     */
    public function testSettersAndGetters(): void
    {
        $this->markTestSkipped('Needs review - tocheck after migration');

        // $view = new View();
        // $this->assertEquals($view, $view->setBasePath(PATH_DATA));
        // ... (setter/getter assertions omitted)
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-02
     */
    public function testDisableLevels(): void
    {
        $this->markTestSkipped('Needs review - tocheck after migration');

        // $view = $this->getViewDisabled();
        // $this->assertEquals(
        //     '<html><div class="after-layout">...</div></html>' . PHP_EOL,
        //     $view->getContent()
        // );
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-02
     */
    public function testViewOptions(): void
    {
        $this->markTestSkipped('Needs review - tocheck after migration');

        // $config = ['cache' => ['service' => 'otherCache']];
        // $view = new View($config);
        // ... (cache assertions omitted)
    }

    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/12648
     * @issue  https://github.com/phalcon/cphalcon/pull/13288
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-17
     */
    public function testIssue12648(): void
    {
        $this->markTestSkipped('Needs review - tocheck after migration');

        // $view = new View();
        // $view->setDI($di);
        // $view->setViewsDir(PATH_DATA . 'views' . DIRECTORY_SEPARATOR);
        // $view->setParamToView('a_cool_var', 'test');
        // $content = $view->setRenderLevel(View::LEVEL_ACTION_VIEW)->getRender('test3', 'another');
        // $this->assertEquals("<html>lol<p>test</p></html>\n", $content);
    }
}
