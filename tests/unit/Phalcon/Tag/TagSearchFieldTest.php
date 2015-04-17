<?php
/**
 * TagSearchFieldTest.php
 * \Phalcon\Tag
 *
 * Tests the \Phalcon\Tag component
 *
 * Phalcon Framework
 *
 * @copyright (c) 2011-2014 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

namespace Phalcon\Tests\unit\Phalcon\Tag;

class TagSearchFieldTest extends Helper\TagBase
{
    /**
     * Tests searchField with string as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSearchFieldStringParameter()
    {
        $this->specify(
            "searchField with string parameter returns invalid HTML Strict",
            function () {

                $options  = 'x_name';
                $expected = '<input type="search" id="x_name" name="x_name"';

                $this->fieldParameter(
                    'searchField',
                    $options,
                    $expected,
                    false
                );
            }
        );

        $this->specify(
            "searchField with string parameter returns invalid HTML XHTML",
            function () {

                $options  = 'x_name';
                $expected = '<input type="search" id="x_name" name="x_name"';

                $this->fieldParameter(
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
    public function testSearchFieldArrayParameter()
    {
        $this->specify(
            "searchField with array parameter returns invalid HTML Strict",
            function () {

                $options = [
                    'x_name',
                    'class' => 'x_class',
                ];
                $expected = '<input type="search" id="x_name" name="x_name" '
                          . 'class="x_class"';

                $this->fieldParameter(
                    'searchField',
                    $options,
                    $expected,
                    false
                );
            }
        );

        $this->specify(
            "searchField with array parameter returns invalid HTML XHTML",
            function () {

                $options = [
                    'x_name',
                    'class' => 'x_class',
                ];
                $expected = '<input type="search" id="x_name" name="x_name" '
                          . 'class="x_class"';

                $this->fieldParameter(
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
    public function testSearchFieldArrayParameterWithId()
    {
        $this->specify(
            "searchField with array parameter with id returns invalid HTML Strict",
            function () {

                $options = [
                    'x_name',
                    'id'    => 'x_id',
                    'class' => 'x_class',
                    'size'  => '10'
                ];
                $expected = '<input type="search" id="x_id" name="x_name" '
                          . 'class="x_class" size="10"';

                $this->fieldParameter(
                    'searchField',
                    $options,
                    $expected,
                    true
                );
            }
        );

        $this->specify(
            "searchField with array parameter with id returns invalid HTML XHTML",
            function () {

                $options = [
                    'x_name',
                    'id'    => 'x_id',
                    'class' => 'x_class',
                    'size'  => '10'
                ];
                $expected = '<input type="search" id="x_id" name="x_name" '
                          . 'class="x_class" size="10"';

                $this->fieldParameter(
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
    public function testSearchFieldArrayParameterWithNameNoId()
    {
        $this->specify(
            "searchField with array parameter with name no id returns invalid HTML Strict",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="search" id="x_name" '
                          . 'name="x_other" class="x_class" size="10"';

                $this->fieldParameter(
                    'searchField',
                    $options,
                    $expected,
                    false
                );
            }
        );

        $this->specify(
            "searchField with array parameter with name no id returns invalid HTML XHTML",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="search" id="x_name" '
                          . 'name="x_other" class="x_class" size="10"';

                $this->fieldParameter(
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
    public function testSearchFieldWithSetDefault()
    {
        $this->specify(
            "searchField with setDefault returns invalid HTML Strict",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="search" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->fieldParameter(
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
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="search" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->fieldParameter(
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
    public function testSearchFieldWithDisplayTo()
    {
        $this->specify(
            "searchField with displayTo returns invalid HTML Strict",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="search" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->fieldParameter(
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
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="search" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->fieldParameter(
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
    public function testSearchFieldWithSetDefaultElementNotPresent()
    {
        $this->specify(
            "searchField with setDefault and element not present returns invalid HTML Strict",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="search" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->fieldParameter(
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
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="search" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->fieldParameter(
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
    public function testSearchFieldWithDisplayToElementNotPresent()
    {
        $this->specify(
            "searchField with displayTo and element not present returns invalid HTML Strict",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="search" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->fieldParameter(
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
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="search" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->fieldParameter(
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
