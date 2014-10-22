<?php
/**
 * TagTextAreaTest.php
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

use \PhalconTest\Tag as PhTTag;

class TagTextAreaTest extends Helper\TagBase
{
    /**
     * Tests textArea with string as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testTextAreaStringParameter()
    {
        $this->specify(
            "textArea with string parameter returns invalid",
            function () {

                $options  = 'x_name';
                $expected = '<textarea id="x_name" name="x_name">'
                          . '</textarea';

                $this->fieldParameter(
                    'textArea',
                    $options,
                    $expected,
                    false
                );
            }
        );
    }

    /**
     * Tests textArea with array as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testTextAreaArrayParameter()
    {
        $this->specify(
            "textArea with array parameter returns invalid",
            function () {

                $options = [
                    'x_name',
                    'class' => 'x_class',
                ];
                $expected = '<textarea id="x_name" name="x_name" '
                          . 'class="x_class"></textarea';

                $this->fieldParameter(
                    'textArea',
                    $options,
                    $expected,
                    false
                );
            }
        );
    }

    /**
     * Tests textArea with array as a parameters and id in it
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testTextAreaArrayParameterWithId()
    {
        $this->specify(
            "textArea with array parameter with id returns invalid",
            function () {

                $options = [
                    'x_name',
                    'id'    => 'x_id',
                    'class' => 'x_class',
                    'size'  => '10'
                ];
                $expected = '<textarea id="x_id" name="x_name" '
                          . 'class="x_class" size="10"></textarea';

                $this->fieldParameter(
                    'textArea',
                    $options,
                    $expected,
                    false
                );
            }
        );
    }

    /**
     * Tests textArea with name and no id in parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testTextAreaArrayParameterWithNameNoId()
    {
        $this->specify(
            "textArea with array parameter with name no id returns invalid",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<textarea id="x_name" name="x_other" '
                          . 'class="x_class" size="10"></textarea';

                $this->fieldParameter(
                    'textArea',
                    $options,
                    $expected,
                    false
                );
            }
        );
    }

    /**
     * Tests textArea with setDefault
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testTextAreaWithSetDefault()
    {
        $this->specify(
            "textArea with setDefault returns invalid",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<textarea id="x_name" name="x_other" '
                          . 'class="x_class" size="10">x_value</textarea';

                $this->fieldParameter(
                    'textArea',
                    $options,
                    $expected,
                    false,
                    'setDefault'
                );
            }
        );
    }

    /**
     * Tests textArea with displayTo
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testTextAreaWithDisplayTo()
    {
        $this->specify(
            "textArea with displayTo returns invalid",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<textarea id="x_name" name="x_other" '
                          . 'class="x_class" size="10">x_value</textarea';

                $this->fieldParameter(
                    'textArea',
                    $options,
                    $expected,
                    false,
                    'displayTo'
                );
            }
        );
    }

    /**
     * Tests textArea with setDefault and element not present
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testTextAreaWithSetDefaultElementNotPresent()
    {
        $this->specify(
            "textArea with setDefault and element not present returns invalid",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<textarea id="x_name" name="x_other" '
                          . 'class="x_class" size="10">x_value</textarea';

                $this->fieldParameter(
                    'textArea',
                    $options,
                    $expected,
                    false,
                    'setDefault'
                );
            }
        );
    }

    /**
     * Tests textArea with displayTo and element not present
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testTextAreaWithDisplayToElementNotPresent()
    {
        $this->specify(
            "textArea with displayTo and element not present returns invalid",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<textarea id="x_name" name="x_other" '
                          . 'class="x_class" size="10">x_value</textarea';

                $this->fieldParameter(
                    'textArea',
                    $options,
                    $expected,
                    false,
                    'displayTo'
                );
            }
        );
    }

    /**
     * Tests textArea with displayTo and newline in value
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-03
     */
    public function testTextAreaWithDisplayToAndNewlineInValue()
    {
        $this->specify(
            "textArea with displayTo and newline in value",
            function () {

                $options  = 'x_name';
                $value    = "\r\nx_content";
                $expected = '<textarea id="x_name" name="x_name">'
                          . $value
                          . '</textarea>';

                PhTTag::setDefault('x_name', $value);
                $actual = PhTTag::textArea($options);
                PhTTag::setDefault('x_name', '');

                expect($actual)->equals($expected);
            }
        );
    }
}
