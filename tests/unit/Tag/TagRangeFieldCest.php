<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Tag;

use Phalcon\Test\Unit\Tag\Helper\TagBase;
use UnitTester;

/**
 * \Phalcon\Test\Unit\Tag\TagRangeFieldTest
 * Tests the \Phalcon\Tag component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Unit\Tag
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class TagRangeFieldTest extends TagBase
{
    /**
     * Tests rangeField with string as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testRangeFieldStringParameter(UnitTester $I)
    {
        $this->specify(
            "rangeField with string parameter returns invalid HTML Strict",
            function (UnitTester $I) {
                $options  = 'x_name';
                $expected = '<input type="range" id="x_name" name="x_name"';

                $this->testFieldParameter(
            $I,
            'rangeField',
                    $options,
                    $expected,
                    false
                );
            }
        );

        $this->specify(
            "rangeField with string parameter returns invalid HTML XHTML",
            function (UnitTester $I) {
                $options  = 'x_name';
                $expected = '<input type="range" id="x_name" name="x_name"';

                $this->testFieldParameter(
            $I,
            'rangeField',
                    $options,
                    $expected,
                    true
                );
            }
        );
    }

    /**
     * Tests rangeField with array as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testRangeFieldArrayParameter(UnitTester $I)
    {
        $this->specify(
            "rangeField with array parameter returns invalid HTML Strict",
            function (UnitTester $I) {
                $options = [
                    'x_name',
                    'class' => 'x_class',
                ];
                $expected = '<input type="range" id="x_name" name="x_name" '
                          . 'class="x_class"';

                $this->testFieldParameter(
            $I,
            'rangeField',
                    $options,
                    $expected,
                    false
                );
            }
        );

        $this->specify(
            "rangeField with array parameter returns invalid HTML XHTML",
            function (UnitTester $I) {
                $options = [
                    'x_name',
                    'class' => 'x_class',
                ];
                $expected = '<input type="range" id="x_name" name="x_name" '
                          . 'class="x_class"';

                $this->testFieldParameter(
            $I,
            'rangeField',
                    $options,
                    $expected,
                    true
                );
            }
        );
    }

    /**
     * Tests rangeField with array as a parameters and id in it
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testRangeFieldArrayParameterWithId(UnitTester $I)
    {
        $this->specify(
            "rangeField with array parameter with id returns invalid HTML Strict",
            function (UnitTester $I) {
                $options = [
                    'x_name',
                    'id'    => 'x_id',
                    'class' => 'x_class',
                    'size'  => '10'
                ];
                $expected = '<input type="range" id="x_id" name="x_name" '
                          . 'class="x_class" size="10"';

                $this->testFieldParameter(
            $I,
            'rangeField',
                    $options,
                    $expected,
                    true
                );
            }
        );

        $this->specify(
            "rangeField with array parameter with id returns invalid HTML XHTML",
            function (UnitTester $I) {
                $options = [
                    'x_name',
                    'id'    => 'x_id',
                    'class' => 'x_class',
                    'size'  => '10'
                ];
                $expected = '<input type="range" id="x_id" name="x_name" '
                          . 'class="x_class" size="10"';

                $this->testFieldParameter(
            $I,
            'rangeField',
                    $options,
                    $expected,
                    true
                );
            }
        );
    }

    /**
     * Tests rangeField with name and no id in parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testRangeFieldArrayParameterWithNameNoId(UnitTester $I)
    {
        $this->specify(
            "rangeField with array parameter with name no id returns invalid HTML Strict",
            function (UnitTester $I) {
                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="range" id="x_name" '
                          . 'name="x_other" class="x_class" size="10"';

                $this->testFieldParameter(
            $I,
            'rangeField',
                    $options,
                    $expected,
                    false
                );
            }
        );

        $this->specify(
            "rangeField with array parameter with name no id returns invalid HTML XHTML",
            function (UnitTester $I) {
                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="range" id="x_name" '
                          . 'name="x_other" class="x_class" size="10"';

                $this->testFieldParameter(
            $I,
            'rangeField',
                    $options,
                    $expected,
                    false
                );
            }
        );
    }

    /**
     * Tests rangeField with setDefault
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testRangeFieldWithSetDefault(UnitTester $I)
    {
        $this->specify(
            "rangeField with setDefault returns invalid HTML Strict",
            function (UnitTester $I) {
                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="range" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->testFieldParameter(
            $I,
            'rangeField',
                    $options,
                    $expected,
                    false,
                    'setDefault'
                );
            }
        );

        $this->specify(
            "rangeField with setDefault returns invalid HTML XHTML",
            function (UnitTester $I) {
                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="range" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->testFieldParameter(
            $I,
            'rangeField',
                    $options,
                    $expected,
                    true,
                    'setDefault'
                );
            }
        );
    }

    /**
     * Tests rangeField with displayTo
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testRangeFieldWithDisplayTo(UnitTester $I)
    {
        $this->specify(
            "rangeField with displayTo returns invalid HTML Strict",
            function (UnitTester $I) {
                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="range" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->testFieldParameter(
            $I,
            'rangeField',
                    $options,
                    $expected,
                    false,
                    'displayTo'
                );
            }
        );

        $this->specify(
            "rangeField with displayTo returns invalid HTML XHTML",
            function (UnitTester $I) {
                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="range" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->testFieldParameter(
            $I,
            'rangeField',
                    $options,
                    $expected,
                    true,
                    'displayTo'
                );
            }
        );
    }

    /**
     * Tests rangeField with setDefault and element not present
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testRangeFieldWithSetDefaultElementNotPresent(UnitTester $I)
    {
        $this->specify(
            "rangeField with setDefault and element not present returns invalid HTML Strict",
            function (UnitTester $I) {
                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="range" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->testFieldParameter(
            $I,
            'rangeField',
                    $options,
                    $expected,
                    false,
                    'setDefault'
                );
            }
        );

        $this->specify(
            "rangeField with setDefault and element not present returns invalid HTML XHTML",
            function (UnitTester $I) {
                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="range" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->testFieldParameter(
            $I,
            'rangeField',
                    $options,
                    $expected,
                    true,
                    'setDefault'
                );
            }
        );
    }

    /**
     * Tests rangeField with displayTo and element not present
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testRangeFieldWithDisplayToElementNotPresent(UnitTester $I)
    {
        $this->specify(
            "rangeField with displayTo and element not present returns invalid HTML Strict",
            function (UnitTester $I) {
                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="range" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->testFieldParameter(
            $I,
            'rangeField',
                    $options,
                    $expected,
                    false,
                    'displayTo'
                );
            }
        );

        $this->specify(
            "rangeField with displayTo and element not present returns invalid HTML XHTML",
            function (UnitTester $I) {
                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="range" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->testFieldParameter(
            $I,
            'rangeField',
                    $options,
                    $expected,
                    true,
                    'displayTo'
                );
            }
        );
    }
}
