<?php
/**
 * TagSubmitButtonTest.php
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

class TagSubmitButtonTest extends Helper\TagBase
{
    /**
     * Tests submitField with string as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSubmitButtonStringParameter()
    {
        $this->specify(
            "submitButton with string parameter returns invalid HTML Strict",
            function () {

                $options  = 'x_name';
                $expected = '<input type="submit" value="x_name"';

                $this->fieldParameter(
                    'submitButton',
                    $options,
                    $expected,
                    false
                );
            }
        );

        $this->specify(
            "submitButton with string parameter returns invalid HTML XHTML",
            function () {

                $options  = 'x_name';
                $expected = '<input type="submit" value="x_name"';

                $this->fieldParameter(
                    'submitButton',
                    $options,
                    $expected,
                    true
                );
            }
        );
    }

    /**
     * Tests submitButton with array as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSubmitButtonArrayParameter()
    {
        $this->specify(
            "submitButton with array parameter returns invalid HTML Strict",
            function () {

                $options = [
                    'x_name',
                    'class' => 'x_class',
                ];
                $expected = '<input type="submit" value="x_name" '
                          . 'class="x_class"';

                $this->fieldParameter(
                    'submitButton',
                    $options,
                    $expected,
                    false
                );
            }
        );

        $this->specify(
            "submitButton with array parameter returns invalid HTML XHTML",
            function () {

                $options = [
                    'x_name',
                    'class' => 'x_class',
                ];
                $expected = '<input type="submit" value="x_name" '
                          . 'class="x_class"';

                $this->fieldParameter(
                    'submitButton',
                    $options,
                    $expected,
                    true
                );
            }
        );
    }

    /**
     * Tests submitButton with array as a parameters and id in it
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSubmitButtonArrayParameterWithId()
    {
        $this->specify(
            "submitButton with array parameter with id returns invalid HTML Strict",
            function () {

                $options = [
                    'x_name',
                    'id'    => 'x_id',
                    'class' => 'x_class',
                    'size'  => '10'
                ];
                $expected = '<input type="submit" id="x_id" value="x_name" '
                          . 'class="x_class" size="10"';

                $this->fieldParameter(
                    'submitButton',
                    $options,
                    $expected,
                    true
                );
            }
        );

        $this->specify(
            "submitButton with array parameter with id returns invalid HTML XHTML",
            function () {

                $options = [
                    'x_name',
                    'id'    => 'x_id',
                    'class' => 'x_class',
                    'size'  => '10'
                ];
                $expected = '<input type="submit" id="x_id" value="x_name" '
                          . 'class="x_class" size="10"';

                $this->fieldParameter(
                    'submitButton',
                    $options,
                    $expected,
                    true
                );
            }
        );
    }

    /**
     * Tests submitButton with name and no id in parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSubmitButtonArrayParameterWithNameNoId()
    {
        $this->specify(
            "submitButton with array parameter with name no id returns invalid HTML Strict",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="submit" name="x_other" '
                          . 'value="x_name" class="x_class" size="10"';

                $this->fieldParameter(
                    'submitButton',
                    $options,
                    $expected,
                    false
                );
            }
        );

        $this->specify(
            "submitButton with array parameter with name no id returns invalid HTML XHTML",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="submit" name="x_other" '
                          . 'value="x_name" class="x_class" size="10"';

                $this->fieldParameter(
                    'submitButton',
                    $options,
                    $expected,
                    false
                );
            }
        );
    }

    /**
     * Tests submitButton with setDefault
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSubmitButtonWithSetDefault()
    {
        $this->specify(
            "submitButton with setDefault returns invalid HTML Strict",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="submit" name="x_other" '
                          . 'value="x_name" class="x_class" size="10"';

                $this->fieldParameter(
                    'submitButton',
                    $options,
                    $expected,
                    false,
                    'setDefault'
                );
            }
        );

        $this->specify(
            "submitButton with setDefault returns invalid HTML XHTML",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="submit" name="x_other" '
                          . 'value="x_name" class="x_class" size="10"';

                $this->fieldParameter(
                    'submitButton',
                    $options,
                    $expected,
                    true,
                    'setDefault'
                );
            }
        );
    }

    /**
     * Tests submitButton with displayTo
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSubmitButtonWithDisplayTo()
    {
        $this->specify(
            "submitButton with displayTo returns invalid HTML Strict",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="submit" name="x_other" '
                          . 'value="x_name" class="x_class" size="10"';

                $this->fieldParameter(
                    'submitButton',
                    $options,
                    $expected,
                    false,
                    'displayTo'
                );
            }
        );

        $this->specify(
            "submitButton with displayTo returns invalid HTML XHTML",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="submit" name="x_other" '
                          . 'value="x_name" class="x_class" size="10"';

                $this->fieldParameter(
                    'submitButton',
                    $options,
                    $expected,
                    true,
                    'displayTo'
                );
            }
        );
    }

    /**
     * Tests submitButton with setDefault and element not present
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSubmitButtonWithSetDefaultElementNotPresent()
    {
        $this->specify(
            "submitButton with setDefault and element not present returns invalid HTML Strict",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="submit" name="x_other" '
                          . 'value="x_name" class="x_class" size="10"';

                $this->fieldParameter(
                    'submitButton',
                    $options,
                    $expected,
                    false,
                    'setDefault'
                );
            }
        );

        $this->specify(
            "submitButton with setDefault and element not present returns invalid HTML XHTML",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="submit" name="x_other" '
                          . 'value="x_name" class="x_class" size="10"';

                $this->fieldParameter(
                    'submitButton',
                    $options,
                    $expected,
                    true,
                    'setDefault'
                );
            }
        );
    }

    /**
     * Tests submitButton with displayTo and element not present
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSubmitButtonWithDisplayToElementNotPresent()
    {
        $this->specify(
            "submitButton with displayTo and element not present returns invalid HTML Strict",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="submit" name="x_other" '
                          . 'value="x_name" class="x_class" size="10"';

                $this->fieldParameter(
                    'submitButton',
                    $options,
                    $expected,
                    false,
                    'displayTo'
                );
            }
        );

        $this->specify(
            "submitButton with displayTo and element not present returns invalid HTML XHTML",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="submit" name="x_other" '
                          . 'value="x_name" class="x_class" size="10"';

                $this->fieldParameter(
                    'submitButton',
                    $options,
                    $expected,
                    true,
                    'displayTo'
                );
            }
        );
    }
}
