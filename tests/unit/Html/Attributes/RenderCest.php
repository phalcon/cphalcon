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

namespace Phalcon\Test\Unit\Html\Attributes;

use Phalcon\Html\Attributes;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use UnitTester;

/**
 * Class RenderCest
 */
class RenderCest
{
    use DiTrait;

    /**
     * Setup
     */
    public function _before()
    {
        $this->setNewFactoryDefault();
    }

    /**
     * Tests Phalcon\Html\Attributes :: render()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-09
     */
    public function htmlAttributesRender(UnitTester $I)
    {
        $I->wantToTest('Html\Attributes - render()');

        $attr = new Attributes();

        // empty
        $actual   = $attr->render();
        $expected = '';
        $I->assertEquals($expected, $actual);

        // add one attribute
        $attr->set('attr1', 'value1');

        // render
        $actual   = $attr->render();
        $expected = ' attr1="value1"';
        $I->assertEquals($expected, $actual);

        // add other attribute
        $attr->set('attr2', 'value2');

        // render
        $actual   = $attr->render();
        $expected = ' attr1="value1" attr2="value2"';
        $I->assertEquals($expected, $actual);

        // remove attribute
        $attr->remove('attr1');

        // render
        $actual   = $attr->render();
        $expected = ' attr2="value2"';
        $I->assertEquals($expected, $actual);

        // add other attribute
        $attr->set('¿?', '¡!');

        // render
        $actual   = $attr->render();
        $expected = ' attr2="value2" ¿?="¡!"';
        $I->assertEquals($expected, $actual);
    }
}
