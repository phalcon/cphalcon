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

namespace Phalcon\Test\Unit\Html\Tag;

use Phalcon\Html\Tag;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Fixtures\Traits\TagSetupTrait;
use UnitTester;

/**
 * Class TextAreaCest
 *
 * @package Phalcon\Test\Unit\Html\Tag
 */
class TextAreaCest
{
    use DiTrait;
    use TagSetupTrait;

    /**
     * Tests Phalcon\Html\Tag :: textArea()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function htmlTagTextArea(UnitTester $I)
    {
        $I->wantToTest('Html\Tag - textArea()');
        $tag = new Tag();
        $tag->setDI($this->container);
        $expected = '<textarea id="x_name" name="x_name"></textarea';

        $this->testFieldParameter($I, $tag, 'x_name', 'textArea', [], $expected);
    }

    /**
     * Tests Phalcon\Html\Tag :: textArea() - array as a parameters and id in it
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function htmlTagTextAreaWithId(UnitTester $I)
    {
        $I->wantToTest("Html\Tag - textArea() - with id");
        $tag = new Tag();
        $tag->setDI($this->container);
        $options  = [
            'id'    => 'x_id',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<textarea id="x_id" name="x_name" '
            . 'class="x_class" size="10"></textarea';

        $this->testFieldParameter($I, $tag, 'x_name', 'textArea', $options, $expected);
    }

    /**
     * Tests Phalcon\Html\Tag :: textArea() - setAttribute()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function htmlTagTextAreaSetAttribute(UnitTester $I)
    {
        $I->wantToTest('Html\Tag - textArea() - setAttribute()');
        $tag = new Tag();
        $tag->setDI($this->container);
        $options  = [
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<textarea id="x_name" name="x_other" '
            . 'class="x_class" size="10">x_value</textarea';

        $this->testFieldParameter($I, $tag, 'x_name', 'textArea', $options, $expected, false, 'setAttribute');
        $this->testFieldParameter($I, $tag, 'x_name', 'textArea', $options, $expected, true, 'setAttribute');
    }

    /**
     * Tests Phalcon\Html\Tag :: textArea() - setAttribute() element not present
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function htmlTagTextAreaSetAttributeElementNotPresent(UnitTester $I)
    {
        $I->wantToTest("Tag - textArea() - setAttribute() element not present");
        $tag = new Tag();
        $tag->setDI($this->container);
        $options  = [
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<textarea id="x_name" name="x_other" '
            . 'class="x_class" size="10">x_value</textarea';

        $this->testFieldParameter($I, $tag, 'x_name', 'textArea', $options, $expected, false, 'setAttribute');
        $this->testFieldParameter($I, $tag, 'x_name', 'textArea', $options, $expected, true, 'setAttribute');
    }

    /**
     * Tests Phalcon\Html\Tag :: textArea() - setAttribute() with newline
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-03
     */
    public function htmlTagTextAreaSetAttributeNewLine(UnitTester $I)
    {
        $I->wantToTest("Tag - textArea() - setAttribute() with newline");
        $tag = new Tag();
        $tag->setDI($this->container);
        $options  = 'x_name';
        $value    = "\r\nx_content";
        $expected = '<textarea id="x_name" name="x_name">' . $value . '</textarea>';

        $tag->setAttribute('x_name', $value);
        $actual = $tag->textArea($options);
        $tag->setAttribute('x_name', '');

        $I->assertEquals($expected, $actual);
    }
}
