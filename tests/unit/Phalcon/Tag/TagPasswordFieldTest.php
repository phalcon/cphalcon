<?php
/**
 * TagPasswordFieldTest.php
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

class TagPasswordFieldTest extends Helper\TagBase
{
    /**
     * Tests passwordField with string as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testPasswordFieldStringParameter()
    {
        $this->specify(
            "passwordField with string parameter returns invalid HTML Strict",
            function () {

                $options  = 'x_name';
                $expected = '<input type="password" id="x_name" name="x_name"';

                $this->fieldParameter(
                    'passwordField',
                    $options,
                    $expected,
                    false
                );
            }
        );

        $this->specify(
            "passwordField with string parameter returns invalid HTML XHTML",
            function () {

                $options  = 'x_name';
                $expected = '<input type="password" id="x_name" name="x_name"';

                $this->fieldParameter(
                    'passwordField',
                    $options,
                    $expected,
                    true
                );
            }
        );
    }

    /**
     * Tests passwordField with array as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testPasswordFieldArrayParameter()
    {
        $this->specify(
            "passwordField with array parameter returns invalid HTML Strict",
            function () {

                $options = [
                    'x_name',
                    'class' => 'x_class',
                ];
                $expected = '<input type="password" id="x_name" name="x_name" '
                          . 'class="x_class"';

                $this->fieldParameter(
                    'passwordField',
                    $options,
                    $expected,
                    false
                );
            }
        );

        $this->specify(
            "passwordField with array parameter returns invalid HTML XHTML",
            function () {

                $options = [
                    'x_name',
                    'class' => 'x_class',
                ];
                $expected = '<input type="password" id="x_name" name="x_name" '
                          . 'class="x_class"';

                $this->fieldParameter(
                    'passwordField',
                    $options,
                    $expected,
                    true
                );
            }
        );
    }

    /**
     * Tests passwordField with array as a parameters and id in it
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testPasswordFieldArrayParameterWithId()
    {
        $this->specify(
            "passwordField with array parameter with id returns invalid HTML Strict",
            function () {

                $options = [
                    'x_name',
                    'id'    => 'x_id',
                    'class' => 'x_class',
                    'size'  => '10'
                ];
                $expected = '<input type="password" id="x_id" name="x_name" '
                          . 'class="x_class" size="10"';

                $this->fieldParameter(
                    'passwordField',
                    $options,
                    $expected,
                    true
                );
            }
        );

        $this->specify(
            "passwordField with array parameter with id returns invalid HTML XHTML",
            function () {

                $options = [
                    'x_name',
                    'id'    => 'x_id',
                    'class' => 'x_class',
                    'size'  => '10'
                ];
                $expected = '<input type="password" id="x_id" name="x_name" '
                          . 'class="x_class" size="10"';

                $this->fieldParameter(
                    'passwordField',
                    $options,
                    $expected,
                    true
                );
            }
        );
    }

    /**
     * Tests passwordField with name and no id in parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testPasswordFieldArrayParameterWithNameNoId()
    {
        $this->specify(
            "passwordField with array parameter with name no id returns invalid HTML Strict",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="password" id="x_name" '
                          . 'name="x_other" class="x_class" size="10"';

                $this->fieldParameter(
                    'passwordField',
                    $options,
                    $expected,
                    false
                );
            }
        );

        $this->specify(
            "passwordField with array parameter with name no id returns invalid HTML XHTML",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="password" id="x_name" '
                          . 'name="x_other" class="x_class" size="10"';

                $this->fieldParameter(
                    'passwordField',
                    $options,
                    $expected,
                    false
                );
            }
        );
    }

    /**
     * Tests passwordField with setDefault
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testPasswordFieldWithSetDefault()
    {
        $this->specify(
            "passwordField with setDefault returns invalid HTML Strict",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="password" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->fieldParameter(
                    'passwordField',
                    $options,
                    $expected,
                    false,
                    'setDefault'
                );
            }
        );

        $this->specify(
            "passwordField with setDefault returns invalid HTML XHTML",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="password" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->fieldParameter(
                    'passwordField',
                    $options,
                    $expected,
                    true,
                    'setDefault'
                );
            }
        );
    }

    /**
     * Tests passwordField with displayTo
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testPasswordFieldWithDisplayTo()
    {
        $this->specify(
            "passwordField with displayTo returns invalid HTML Strict",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="password" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->fieldParameter(
                    'passwordField',
                    $options,
                    $expected,
                    false,
                    'displayTo'
                );
            }
        );

        $this->specify(
            "passwordField with displayTo returns invalid HTML XHTML",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="password" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->fieldParameter(
                    'passwordField',
                    $options,
                    $expected,
                    true,
                    'displayTo'
                );
            }
        );
    }

    /**
     * Tests passwordField with setDefault and element not present
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testPasswordFieldWithSetDefaultElementNotPresent()
    {
        $this->specify(
            "passwordField with setDefault and element not present returns invalid HTML Strict",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="password" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->fieldParameter(
                    'passwordField',
                    $options,
                    $expected,
                    false,
                    'setDefault'
                );
            }
        );

        $this->specify(
            "passwordField with setDefault and element not present returns invalid HTML XHTML",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="password" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->fieldParameter(
                    'passwordField',
                    $options,
                    $expected,
                    true,
                    'setDefault'
                );
            }
        );
    }

    /**
     * Tests passwordField with displayTo and element not present
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testPasswordFieldWithDisplayToElementNotPresent()
    {
        $this->specify(
            "passwordField with displayTo and element not present returns invalid HTML Strict",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="password" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->fieldParameter(
                    'passwordField',
                    $options,
                    $expected,
                    false,
                    'displayTo'
                );
            }
        );

        $this->specify(
            "passwordField with displayTo and element not present returns invalid HTML XHTML",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="password" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->fieldParameter(
                    'passwordField',
                    $options,
                    $expected,
                    true,
                    'displayTo'
                );
            }
        );
    }
}
