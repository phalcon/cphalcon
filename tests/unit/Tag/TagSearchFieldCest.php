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
 * \Phalcon\Test\Unit\Tag\TagSearchFieldTest
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
class TagSearchFieldTest extends TagBase
{
    /**
     * Tests searchField with string as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSearchFieldStringParameter(UnitTester $I)
    {
        $this->specify(
            "searchField with string parameter returns invalid HTML Strict",
            function (UnitTester $I) {
                $options  = 'x_name';
                $expected = '<input type="search" id="x_name" name="x_name"';

                $this->testFieldParameter(
            $I,
            'searchField',
                    $options,
                    $expected,
                    false
                );
            }
        );

        $this->specify(
            "searchField with string parameter returns invalid HTML XHTML",
            function (UnitTester $I) {
                $options  = 'x_name';
                $expected = '<input type="search" id="x_name" name="x_name"';

                $this->testFieldParameter(
            $I,
            'searchField',
                    $options,
                    $expected,
                    true
                );
            }
        );
    }

    /**
     * Tests searchField with array as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSearchFieldArrayParameter(UnitTester $I)
    {
        $this->specify(
            "searchField with array parameter returns invalid HTML Strict",
            function (UnitTester $I) {
                $options = [
                    'x_name',
                    'class' => 'x_class',
                ];
                $expected = '<input type="search" id="x_name" name="x_name" '
                          . 'class="x_class"';

                $this->testFieldParameter(
            $I,
            'searchField',
                    $options,
                    $expected,
                    false
                );
            }
        );

        $this->specify(
            "searchField with array parameter returns invalid HTML XHTML",
            function (UnitTester $I) {
                $options = [
                    'x_name',
                    'class' => 'x_class',
                ];
                $expected = '<input type="search" id="x_name" name="x_name" '
                          . 'class="x_class"';

                $this->testFieldParameter(
            $I,
            'searchField',
                    $options,
                    $expected,
                    true
                );
            }
        );
    }

    /**
     * Tests searchField with array as a parameters and id in it
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSearchFieldArrayParameterWithId(UnitTester $I)
    {
        $this->specify(
            "searchField with array parameter with id returns invalid HTML Strict",
            function (UnitTester $I) {
                $options = [
                    'x_name',
                    'id'    => 'x_id',
                    'class' => 'x_class',
                    'size'  => '10'
                ];
                $expected = '<input type="search" id="x_id" name="x_name" '
                          . 'class="x_class" size="10"';

                $this->testFieldParameter(
            $I,
            'searchField',
                    $options,
                    $expected,
                    true
                );
            }
        );

        $this->specify(
            "searchField with array parameter with id returns invalid HTML XHTML",
            function (UnitTester $I) {
                $options = [
                    'x_name',
                    'id'    => 'x_id',
                    'class' => 'x_class',
                    'size'  => '10'
                ];
                $expected = '<input type="search" id="x_id" name="x_name" '
                          . 'class="x_class" size="10"';

                $this->testFieldParameter(
            $I,
            'searchField',
                    $options,
                    $expected,
                    true
                );
            }
        );
    }

    /**
     * Tests searchField with name and no id in parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSearchFieldArrayParameterWithNameNoId(UnitTester $I)
    {
        $this->specify(
            "searchField with array parameter with name no id returns invalid HTML Strict",
            function (UnitTester $I) {
                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="search" id="x_name" '
                          . 'name="x_other" class="x_class" size="10"';

                $this->testFieldParameter(
            $I,
            'searchField',
                    $options,
                    $expected,
                    false
                );
            }
        );

        $this->specify(
            "searchField with array parameter with name no id returns invalid HTML XHTML",
            function (UnitTester $I) {
                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="search" id="x_name" '
                          . 'name="x_other" class="x_class" size="10"';

                $this->testFieldParameter(
            $I,
            'searchField',
                    $options,
                    $expected,
                    false
                );
            }
        );
    }

    /**
     * Tests searchField with setDefault
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSearchFieldWithSetDefault(UnitTester $I)
    {
        $this->specify(
            "searchField with setDefault returns invalid HTML Strict",
            function (UnitTester $I) {
                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="search" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->testFieldParameter(
            $I,
            'searchField',
                    $options,
                    $expected,
                    false,
                    'setDefault'
                );
            }
        );

        $this->specify(
            "searchField with setDefault returns invalid HTML XHTML",
            function (UnitTester $I) {
                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="search" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->testFieldParameter(
            $I,
            'searchField',
                    $options,
                    $expected,
                    true,
                    'setDefault'
                );
            }
        );
    }

    /**
     * Tests searchField with displayTo
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSearchFieldWithDisplayTo(UnitTester $I)
    {
        $this->specify(
            "searchField with displayTo returns invalid HTML Strict",
            function (UnitTester $I) {
                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="search" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->testFieldParameter(
            $I,
            'searchField',
                    $options,
                    $expected,
                    false,
                    'displayTo'
                );
            }
        );

        $this->specify(
            "searchField with displayTo returns invalid HTML XHTML",
            function (UnitTester $I) {
                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="search" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->testFieldParameter(
            $I,
            'searchField',
                    $options,
                    $expected,
                    true,
                    'displayTo'
                );
            }
        );
    }

    /**
     * Tests searchField with setDefault and element not present
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSearchFieldWithSetDefaultElementNotPresent(UnitTester $I)
    {
        $this->specify(
            "searchField with setDefault and element not present returns invalid HTML Strict",
            function (UnitTester $I) {
                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="search" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->testFieldParameter(
            $I,
            'searchField',
                    $options,
                    $expected,
                    false,
                    'setDefault'
                );
            }
        );

        $this->specify(
            "searchField with setDefault and element not present returns invalid HTML XHTML",
            function (UnitTester $I) {
                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="search" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->testFieldParameter(
            $I,
            'searchField',
                    $options,
                    $expected,
                    true,
                    'setDefault'
                );
            }
        );
    }

    /**
     * Tests searchField with displayTo and element not present
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSearchFieldWithDisplayToElementNotPresent(UnitTester $I)
    {
        $this->specify(
            "searchField with displayTo and element not present returns invalid HTML Strict",
            function (UnitTester $I) {
                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="search" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->testFieldParameter(
            $I,
            'searchField',
                    $options,
                    $expected,
                    false,
                    'displayTo'
                );
            }
        );

        $this->specify(
            "searchField with displayTo and element not present returns invalid HTML XHTML",
            function (UnitTester $I) {
                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="search" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->testFieldParameter(
            $I,
            'searchField',
                    $options,
                    $expected,
                    true,
                    'displayTo'
                );
            }
        );
    }
}
