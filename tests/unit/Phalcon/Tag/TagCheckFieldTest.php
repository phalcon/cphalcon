<?php
/**
 * TagCheckFieldTest.php
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

class TagCheckFieldTest extends Helper\TagBase
{
    /**
     * Tests checkField with string as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testCheckFieldStringParameter()
    {
        $this->specify(
            "checkField with string parameter returns invalid HTML Strict",
            function () {

                $options  = 'x_name';
                $expected = '<input type="checkbox" id="x_name" name="x_name"';

                $this->fieldParameter(
                    'checkField',
                    $options,
                    $expected,
                    false
                );
            }
        );

        $this->specify(
            "checkField with string parameter returns invalid HTML XHTML",
            function () {

                $options  = 'x_name';
                $expected = '<input type="checkbox" id="x_name" name="x_name"';

                $this->fieldParameter(
                    'checkField',
                    $options,
                    $expected,
                    true
                );
            }
        );
    }

    /**
     * Tests checkField with array as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testCheckFieldArrayParameter()
    {
        $this->specify(
            "checkField with array parameter returns invalid HTML Strict",
            function () {

                $options = [
                    'x_name',
                    'class' => 'x_class',
                ];
                $expected = '<input type="checkbox" id="x_name" name="x_name" '
                          . 'class="x_class"';

                $this->fieldParameter(
                    'checkField',
                    $options,
                    $expected,
                    false
                );
            }
        );

        $this->specify(
            "checkField with array parameter returns invalid HTML XHTML",
            function () {

                $options = [
                    'x_name',
                    'class' => 'x_class',
                ];
                $expected = '<input type="checkbox" id="x_name" name="x_name" '
                          . 'class="x_class"';

                $this->fieldParameter(
                    'checkField',
                    $options,
                    $expected,
                    true
                );
            }
        );
    }

    /**
     * Tests checkField with array as a parameters and id in it
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testCheckFieldArrayParameterWithId()
    {
        $this->specify(
            "checkField with array parameter with id returns invalid HTML Strict",
            function () {

                $options = [
                    'x_name',
                    'id'    => 'x_id',
                    'class' => 'x_class',
                    'size'  => '10'
                ];
                $expected = '<input type="checkbox" id="x_id" name="x_name" '
                          . 'class="x_class" size="10"';

                $this->fieldParameter(
                    'checkField',
                    $options,
                    $expected,
                    true
                );
            }
        );

        $this->specify(
            "checkField with array parameter with id returns invalid HTML XHTML",
            function () {

                $options = [
                    'x_name',
                    'id'    => 'x_id',
                    'class' => 'x_class',
                    'size'  => '10'
                ];
                $expected = '<input type="checkbox" id="x_id" name="x_name" '
                          . 'class="x_class" size="10"';

                $this->fieldParameter(
                    'checkField',
                    $options,
                    $expected,
                    true
                );
            }
        );
    }

    /**
     * Tests checkField with name and no id in parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testCheckFieldArrayParameterWithNameNoId()
    {
        $this->specify(
            "checkField with array parameter with name no id returns invalid HTML Strict",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="checkbox" id="x_name" name="x_other" '
                          . 'class="x_class" size="10"';

                $this->fieldParameter(
                    'checkField',
                    $options,
                    $expected,
                    false
                );
            }
        );

        $this->specify(
            "checkField with array parameter with name no id returns invalid HTML XHTML",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="checkbox" id="x_name" name="x_other" '
                          . 'class="x_class" size="10"';

                $this->fieldParameter(
                    'checkField',
                    $options,
                    $expected,
                    false
                );
            }
        );
    }

    /**
     * Tests checkField with setDefault
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testCheckFieldWithSetDefault()
    {
        $this->specify(
            "checkField with setDefault returns invalid HTML Strict",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="checkbox" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10" checked="checked"';

                $this->fieldParameter(
                    'checkField',
                    $options,
                    $expected,
                    false,
                    'setDefault'
                );
            }
        );

        $this->specify(
            "checkField with setDefault returns invalid HTML XHTML",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="checkbox" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10" checked="checked"';

                $this->fieldParameter(
                    'checkField',
                    $options,
                    $expected,
                    true,
                    'setDefault'
                );
            }
        );
    }

    /**
     * Tests checkField with displayTo
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testCheckFieldWithDisplayTo()
    {
        $this->specify(
            "checkField with displayTo returns invalid HTML Strict",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="checkbox" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10" checked="checked"';

                $this->fieldParameter(
                    'checkField',
                    $options,
                    $expected,
                    false,
                    'displayTo'
                );
            }
        );

        $this->specify(
            "checkField with displayTo returns invalid HTML XHTML",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="checkbox" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10" checked="checked"';

                $this->fieldParameter(
                    'checkField',
                    $options,
                    $expected,
                    true,
                    'displayTo'
                );
            }
        );
    }

    /**
     * Tests checkField with setDefault and element not present
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testCheckFieldWithSetDefaultElementNotPresent()
    {
        $this->specify(
            "checkField with setDefault and element not present returns invalid HTML Strict",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="checkbox" id="x_name" name="x_other" '
                          . 'value="x_value" class="x_class" size="10" '
                          . 'checked="checked"';

                $this->fieldParameter(
                    'checkField',
                    $options,
                    $expected,
                    false,
                    'setDefault'
                );
            }
        );

        $this->specify(
            "checkField with setDefault and element not present returns invalid HTML XHTML",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="checkbox" id="x_name" name="x_other" '
                          . 'value="x_value" class="x_class" size="10" '
                          . 'checked="checked"';

                $this->fieldParameter(
                    'checkField',
                    $options,
                    $expected,
                    true,
                    'setDefault'
                );
            }
        );
    }

    /**
     * Tests checkField with displayTo and element not present
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testCheckFieldWithDisplayToElementNotPresent()
    {
        $this->specify(
            "checkField with displayTo and element not present returns invalid HTML Strict",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="checkbox" id="x_name" name="x_other" '
                          . 'value="x_value" class="x_class" size="10" '
                          . 'checked="checked"';

                $this->fieldParameter(
                    'checkField',
                    $options,
                    $expected,
                    false,
                    'displayTo'
                );
            }
        );

        $this->specify(
            "checkField with displayTo and element not present returns invalid HTML XHTML",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="checkbox" id="x_name" name="x_other" '
                          . 'value="x_value" class="x_class" size="10" '
                          . 'checked="checked"';

                $this->fieldParameter(
                    'checkField',
                    $options,
                    $expected,
                    true,
                    'displayTo'
                );
            }
        );
    }
}
