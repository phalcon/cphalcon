<?php
/**
 * TagRadioFieldTest.php
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

class TagRadioFieldTest extends Helper\TagBase
{
    /**
     * Tests radioField with string as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testRadioFieldStringParameter()
    {
        $this->specify(
            "radioField with string parameter returns invalid HTML Strict",
            function () {

                $options  = 'x_name';
                $expected = '<input type="radio" id="x_name" name="x_name"';

                $this->fieldParameter(
                    'radioField',
                    $options,
                    $expected,
                    false
                );
            }
        );

        $this->specify(
            "radioField with string parameter returns invalid HTML XHTML",
            function () {

                $options  = 'x_name';
                $expected = '<input type="radio" id="x_name" name="x_name"';

                $this->fieldParameter(
                    'radioField',
                    $options,
                    $expected,
                    true
                );
            }
        );
    }

    /**
     * Tests radioField with array as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testRadioFieldArrayParameter()
    {
        $this->specify(
            "radioField with array parameter returns invalid HTML Strict",
            function () {

                $options = [
                    'x_name',
                    'class' => 'x_class',
                ];
                $expected = '<input type="radio" id="x_name" name="x_name" '
                          . 'class="x_class"';

                $this->fieldParameter(
                    'radioField',
                    $options,
                    $expected,
                    false
                );
            }
        );

        $this->specify(
            "radioField with array parameter returns invalid HTML XHTML",
            function () {

                $options = [
                    'x_name',
                    'class' => 'x_class',
                ];
                $expected = '<input type="radio" id="x_name" name="x_name" '
                          . 'class="x_class"';

                $this->fieldParameter(
                    'radioField',
                    $options,
                    $expected,
                    true
                );
            }
        );
    }

    /**
     * Tests radioField with array as a parameters and id in it
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testRadioFieldArrayParameterWithId()
    {
        $this->specify(
            "radioField with array parameter with id returns invalid HTML Strict",
            function () {

                $options = [
                    'x_name',
                    'id'    => 'x_id',
                    'class' => 'x_class',
                    'size'  => '10'
                ];
                $expected = '<input type="radio" id="x_id" name="x_name" '
                          . 'class="x_class" size="10"';

                $this->fieldParameter(
                    'radioField',
                    $options,
                    $expected,
                    true
                );
            }
        );

        $this->specify(
            "radioField with array parameter with id returns invalid HTML XHTML",
            function () {

                $options = [
                    'x_name',
                    'id'    => 'x_id',
                    'class' => 'x_class',
                    'size'  => '10'
                ];
                $expected = '<input type="radio" id="x_id" name="x_name" '
                          . 'class="x_class" size="10"';

                $this->fieldParameter(
                    'radioField',
                    $options,
                    $expected,
                    true
                );
            }
        );
    }

    /**
     * Tests radioField with name and no id in parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testRadioFieldArrayParameterWithNameNoId()
    {
        $this->specify(
            "radioField with array parameter with name no id returns invalid HTML Strict",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="radio" id="x_name" '
                          . 'name="x_other" class="x_class" size="10"';

                $this->fieldParameter(
                    'radioField',
                    $options,
                    $expected,
                    false
                );
            }
        );

        $this->specify(
            "radioField with array parameter with name no id returns invalid HTML XHTML",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="radio" id="x_name" '
                          . 'name="x_other" class="x_class" size="10"';

                $this->fieldParameter(
                    'radioField',
                    $options,
                    $expected,
                    false
                );
            }
        );
    }

    /**
     * Tests radioField with setDefault
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testRadioFieldWithSetDefault()
    {
        $this->specify(
            "radioField with setDefault returns invalid HTML Strict",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="radio" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10" checked="checked"';

                $this->fieldParameter(
                    'radioField',
                    $options,
                    $expected,
                    false,
                    'setDefault'
                );
            }
        );

        $this->specify(
            "radioField with setDefault returns invalid HTML XHTML",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="radio" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10" checked="checked"';

                $this->fieldParameter(
                    'radioField',
                    $options,
                    $expected,
                    true,
                    'setDefault'
                );
            }
        );
    }

    /**
     * Tests radioField with displayTo
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testRadioFieldWithDisplayTo()
    {
        $this->specify(
            "radioField with displayTo returns invalid HTML Strict",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="radio" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10" checked="checked"';

                $this->fieldParameter(
                    'radioField',
                    $options,
                    $expected,
                    false,
                    'displayTo'
                );
            }
        );

        $this->specify(
            "radioField with displayTo returns invalid HTML XHTML",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="radio" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10" checked="checked"';

                $this->fieldParameter(
                    'radioField',
                    $options,
                    $expected,
                    true,
                    'displayTo'
                );
            }
        );
    }

    /**
     * Tests radioField with setDefault and element not present
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testRadioFieldWithSetDefaultElementNotPresent()
    {
        $this->specify(
            "radioField with setDefault and element not present returns invalid HTML Strict",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="radio" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10" checked="checked"';

                $this->fieldParameter(
                    'radioField',
                    $options,
                    $expected,
                    false,
                    'setDefault'
                );
            }
        );

        $this->specify(
            "radioField with setDefault and element not present returns invalid HTML XHTML",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="radio" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10" checked="checked"';

                $this->fieldParameter(
                    'radioField',
                    $options,
                    $expected,
                    true,
                    'setDefault'
                );
            }
        );
    }

    /**
     * Tests radioField with displayTo and element not present
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testRadioFieldWithDisplayToElementNotPresent()
    {
        $this->specify(
            "radioField with displayTo and element not present returns invalid HTML Strict",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="radio" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10" checked="checked"';

                $this->fieldParameter(
                    'radioField',
                    $options,
                    $expected,
                    false,
                    'displayTo'
                );
            }
        );

        $this->specify(
            "radioField with displayTo and element not present returns invalid HTML XHTML",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="radio" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10" checked="checked"';

                $this->fieldParameter(
                    'radioField',
                    $options,
                    $expected,
                    true,
                    'displayTo'
                );
            }
        );
    }
}
