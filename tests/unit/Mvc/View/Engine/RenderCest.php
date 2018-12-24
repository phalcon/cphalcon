<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Mvc\View\Engine;

use Phalcon\Mvc\View\Engine\Volt;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use stdClass;
use UnitTester;

class RenderCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Mvc\View\Engine :: render()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcViewEngineRender(UnitTester $I)
    {
        $I->wantToTest("Mvc\View\Engine - render()");
        $I->skipTest("Need implementation");
    }

    /**
     * Tests Phalcon\Mvc\View\Engine :: render() - macro with null value
     *
     * @param UnitTester $I
     *
     * @issue https://github.com/phalcon/cphalcon/issues/13660
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcViewEngineRenderMacroWithNullValue(UnitTester $I)
    {
        $I->wantToTest("Mvc\View\Engine - render() - macro with null value");
        $I->safeDeleteFile(dataFolder('fixtures/views/macro/null-value.volt.php'));

        $this->newDi();
        $this->setDiView();
        $this->setDiEscaper();
        $this->setDiUrl();

        $view = $this->container->get('view');
        $view->registerEngines(
            [
                '.volt' => new Volt($view, $this->container),
            ]
        );
        $object = new stdClass();
        $object->notNullValue = 'Text';
        $object->nullValue    = null;

        $view->setVar('object', $object);
        $view->start();
        $view->render('macro', 'null-value');
        $view->finish();
        ob_start();
        echo 'Not Null: Text - Null: ';
        $actual = ob_get_clean();

        $expected = $view->getContent();
        $I->assertEquals($expected, $actual);

        $I->safeDeleteFile(dataFolder('fixtures/views/macro/null-value.volt.php'));
    }
}
