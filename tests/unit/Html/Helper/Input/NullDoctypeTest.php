<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Html\Helper\Input;

use Phalcon\Html\Escaper;
use Phalcon\Html\Helper\Doctype;
use Phalcon\Html\Helper\Input\Checkbox;
use Phalcon\Html\Helper\Input\Generic;
use Phalcon\Html\Helper\Input\Radio;
use Phalcon\Html\Helper\Input\Textarea;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

/**
 * The doctype is optional in AbstractHelper.__construct(). Helpers built
 * directly, i.e. not through the TagFactory, therefore hold a null doctype.
 * AbstractInput.__toString() must not dereference it. A null doctype renders
 * as HTML5, which is what the default Doctype reports.
 */
final class NullDoctypeTest extends AbstractUnitTestCase
{
    public function testCheckboxWithoutDoctypeRendersHtml5(): void
    {
        $helper = new Checkbox(new Escaper());

        $expected = '<input type="checkbox" id="x_name" name="x_name" '
            . 'value="test">';
        $actual   = (string) $helper('x_name', 'test');
        $this->assertSame($expected, $actual);
    }

    public function testGenericWithoutDoctypeMatchesDefaultDoctype(): void
    {
        $escaper   = new Escaper();
        $withNull  = new Generic($escaper);
        $withHtml5 = new Generic($escaper, new Doctype());

        $expected = (string) $withHtml5('x_name', 'test');
        $actual   = (string) $withNull('x_name', 'test');
        $this->assertSame($expected, $actual);
    }

    public function testGenericWithoutDoctypeRendersHtml5(): void
    {
        $helper = new Generic(new Escaper());

        $expected = '<input type="text" id="x_name" name="x_name">';
        $actual   = (string) $helper('x_name');
        $this->assertSame($expected, $actual);
    }

    public function testRadioWithoutDoctypeRendersHtml5(): void
    {
        $helper = new Radio(new Escaper());

        $expected = '<input type="radio" id="x_name" name="x_name" '
            . 'value="test">';
        $actual   = (string) $helper('x_name', 'test');
        $this->assertSame($expected, $actual);
    }

    public function testTextareaWithoutDoctypeRendersHtml5(): void
    {
        $helper = new Textarea(new Escaper());

        $expected = '<textarea id="x_name" name="x_name">test</textarea>';
        $actual   = (string) $helper('x_name', 'test');
        $this->assertSame($expected, $actual);
    }

    public function testXhtmlDoctypeStillSelfCloses(): void
    {
        $doctype = new Doctype();
        $doctype(Doctype::XHTML5);

        $helper = new Generic(new Escaper(), $doctype);

        $expected = '<input type="text" id="x_name" name="x_name" />';
        $actual   = (string) $helper('x_name');
        $this->assertSame($expected, $actual);
    }
}
