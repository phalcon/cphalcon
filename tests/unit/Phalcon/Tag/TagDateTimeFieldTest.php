<?php
/**
 * TagDateTimeFieldTest.php
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

class TagDateTimeFieldTest extends Helper\TagBase
{
    /**
     * Tests dateTimeField with string as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testDateTimeFieldStringParameter()
    {
        $this->specify(
            "dateTimeField with string parameter returns invalid HTML Strict",
            function () {

                $options  = 'x_name';
                $expected = '<input type="datetime" id="x_name" name="x_name"';

                $this->fieldParameter(
                    'dateTimeField',
                    $options,
                    $expected,
                    false
                );
            }
        );

        $this->specify(
            "dateTimeField with string parameter returns invalid HTML XHTML",
            function () {

                $options  = 'x_name';
                $expected = '<input type="datetime" id="x_name" name="x_name"';

                $this->fieldParameter(
                    'dateTimeField',
                    $options,
                    $expected,
                    true
                );
            }
        );
    }

    /**
     * Tests dateTimeField with array as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testDateTimeFieldArrayParameter()
    {
        $this->specify(
            "dateTimeField with array parameter returns invalid HTML Strict",
            function () {

                $options = [
                    'x_name',
                    'class' => 'x_class',
                ];
                $expected = '<input type="datetime" id="x_name" name="x_name" '
                          . 'class="x_class"';

                $this->fieldParameter(
                    'dateTimeField',
                    $options,
                    $expected,
                    false
                );
            }
        );

        $this->specify(
            "dateTimeField with array parameter returns invalid HTML XHTML",
            function () {

                $options = [
                    'x_name',
                    'class' => 'x_class',
                ];
                $expected = '<input type="datetime" id="x_name" name="x_name" '
                          . 'class="x_class"';

                $this->fieldParameter(
                    'dateTimeField',
                    $options,
                    $expected,
                    true
                );
            }
        );
    }

    /**
     * Tests dateTimeField with array as a parameters and id in it
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testDateTimeFieldArrayParameterWithId()
    {
        $this->specify(
            "dateTimeField with array parameter with id returns invalid HTML Strict",
            function () {

                $options = [
                    'x_name',
                    'id'    => 'x_id',
                    'class' => 'x_class',
                    'size'  => '10'
                ];
                $expected = '<input type="datetime" id="x_id" name="x_name" '
                          . 'class="x_class" size="10"';

                $this->fieldParameter(
                    'dateTimeField',
                    $options,
                    $expected,
                    true
                );
            }
        );

        $this->specify(
            "dateTimeField with array parameter with id returns invalid HTML XHTML",
            function () {

                $options = [
                    'x_name',
                    'id'    => 'x_id',
                    'class' => 'x_class',
                    'size'  => '10'
                ];
                $expected = '<input type="datetime" id="x_id" name="x_name" '
                          . 'class="x_class" size="10"';

                $this->fieldParameter(
                    'dateTimeField',
                    $options,
                    $expected,
                    true
                );
            }
        );
    }

    /**
     * Tests dateTimeField with name and no id in parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testDateTimeFieldArrayParameterWithNameNoId()
    {
        $this->specify(
            "dateTimeField with array parameter with name no id returns invalid HTML Strict",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="datetime" id="x_name" '
                          . 'name="x_other" class="x_class" size="10"';

                $this->fieldParameter(
                    'dateTimeField',
                    $options,
                    $expected,
                    false
                );
            }
        );

        $this->specify(
            "dateTimeField with array parameter with name no id returns invalid HTML XHTML",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="datetime" id="x_name" '
                          . 'name="x_other" class="x_class" size="10"';

                $this->fieldParameter(
                    'dateTimeField',
                    $options,
                    $expected,
                    false
                );
            }
        );
    }

    /**
     * Tests dateTimeField with setDefault
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testDateTimeFieldWithSetDefault()
    {
        $this->specify(
            "dateTimeField with setDefault returns invalid HTML Strict",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="datetime" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->fieldParameter(
                    'dateTimeField',
                    $options,
                    $expected,
                    false,
                    'setDefault'
                );
            }
        );

        $this->specify(
            "dateTimeField with setDefault returns invalid HTML XHTML",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="datetime" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->fieldParameter(
                    'dateTimeField',
                    $options,
                    $expected,
                    true,
                    'setDefault'
                );
            }
        );
    }

    /**
     * Tests dateTimeField with displayTo
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testDateTimeFieldWithDisplayTo()
    {
        $this->specify(
            "dateTimeField with displayTo returns invalid HTML Strict",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="datetime" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->fieldParameter(
                    'dateTimeField',
                    $options,
                    $expected,
                    false,
                    'displayTo'
                );
            }
        );

        $this->specify(
            "dateTimeField with displayTo returns invalid HTML XHTML",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="datetime" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->fieldParameter(
                    'dateTimeField',
                    $options,
                    $expected,
                    true,
                    'displayTo'
                );
            }
        );
    }

    /**
     * Tests dateTimeField with setDefault and element not present
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testDateTimeFieldWithSetDefaultElementNotPresent()
    {
        $this->specify(
            "dateTimeField with setDefault and element not present returns invalid HTML Strict",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="datetime" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->fieldParameter(
                    'dateTimeField',
                    $options,
                    $expected,
                    false,
                    'setDefault'
                );
            }
        );

        $this->specify(
            "dateTimeField with setDefault and element not present returns invalid HTML XHTML",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="datetime" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->fieldParameter(
                    'dateTimeField',
                    $options,
                    $expected,
                    true,
                    'setDefault'
                );
            }
        );
    }

    /**
     * Tests dateTimeField with displayTo and element not present
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testDateTimeFieldWithDisplayToElementNotPresent()
    {
        $this->specify(
            "dateTimeField with displayTo and element not present returns invalid HTML Strict",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="datetime" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->fieldParameter(
                    'dateTimeField',
                    $options,
                    $expected,
                    false,
                    'displayTo'
                );
            }
        );

        $this->specify(
            "dateTimeField with displayTo and element not present returns invalid HTML XHTML",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="datetime" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->fieldParameter(
                    'dateTimeField',
                    $options,
                    $expected,
                    true,
                    'displayTo'
                );
            }
        );
    }
}
