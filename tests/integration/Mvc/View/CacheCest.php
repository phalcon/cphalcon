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

use function dataDir;
use IntegrationTester;
use Phalcon\Mvc\View;
use Phalcon\Test\Fixtures\Traits\DiTrait;

/**
 * Class CacheCest
 */
class CacheCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDiView();
    }

    /**
     * Tests Phalcon\Mvc\View :: cache()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcViewCache(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\View - cache()');

        $cache = $this->getAndSetViewCacheStream();

        $date    = date("r");
        $content = '<html>' . $date . '</html>' . PHP_EOL;

        $view = new View();
        $view->setDI($this->container);
        $view->setViewsDir(dataDir('fixtures/views'));
        $view->setVar("date", $date);

        //First hit
        $view->start();
        $view->cache(true);
        $view->render('cache', 'index');
        $view->finish();

        $I->assertEquals($content, $view->getContent());

        $view->reset();

//        //Second hit
//        $view->start();
//        $view->cache(true);
//        $view->render('test8', 'index');
//        $view->finish();
//        expect($view->getContent())->equals($content);
//
//        $view->reset();
//
//        sleep(1);
//
//        $view->setVar("date", date("r"));
//
//        //Third hit after 1 second
//        $view->start();
//        $view->cache(true);
//        $view->render('test8', 'index');
//        $view->finish();
//        expect($view->getContent())->equals($content);
//
//        $view->reset();
//
//        //Four hit
//        $view->start();
//        $view->cache(true);
//        $view->render('test8', 'index');
//        $view->finish();
//        expect($view->getContent())->equals($content);
    }
}
