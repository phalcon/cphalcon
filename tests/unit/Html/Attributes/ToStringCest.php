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
 * Class ToStringCest
 */
class ToStringCest
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
     * Tests Phalcon\Html\Attributes :: __toString()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-09
     */
    public function htmlAttributesToString(UnitTester $I)
    {
        $I->wantToTest('Html\Attributes - __toString()');

        $attr = new Attributes();

        // empty
        $actual = $attr->__toString();
        $expected = '';
        $I->assertEquals($expected, $actual);

        // add one attribute
        $attr->set('attr1', 'value1');

        // render
        $actual = $attr->__toString();
        $expected = ' attr1="value1"';
        $I->assertEquals($expected, $actual);

        // add other attribute
        $attr->set('attr2', 'value2');

        // render
        $actual = $attr->__toString();
        $expected = ' attr1="value1" attr2="value2"';
        $I->assertEquals($expected, $actual);

        // remove attribute
        $attr->remove('attr1');

        // render
        $actual = $attr->__toString();
        $expected = ' attr2="value2"';
        $I->assertEquals($expected, $actual);

        // add other attribute
        $attr->set('¿?', '¡!');

        // render
        $actual = $attr->__toString();
        $expected = ' attr2="value2" ¿?="¡!"';
        $I->assertEquals($expected, $actual);

        // add existing attribute
        $attr->set('¿?', '¡!');

        // render forcing type
        $actual = (string) $attr;
        $expected = ' attr2="value2" ¿?="¡!"';
        $I->assertEquals($expected, $actual);
    }
}
