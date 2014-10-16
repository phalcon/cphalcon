<?php
/**
 * TagImageInputTest.php
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

class TagImageInputTest extends Helper\TagBase
{
    /**
     * Tests imageInput with string as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testImageInputStringParameter()
    {
        $this->specify(
            "imageInput with string parameter returns invalid HTML Strict",
            function () {

                $options  = 'x_name';
                $expected = '<input type="image" value="x_name"';

                $this->fieldParameter(
                    'imageInput',
                    $options,
                    $expected,
                    false
                );
            }
        );

        $this->specify(
            "imageInput with string parameter returns invalid HTML XHTML",
            function () {

                $options  = 'x_name';
                $expected = '<input type="image" value="x_name"';

                $this->fieldParameter(
                    'imageInput',
                    $options,
                    $expected,
                    true
                );
            }
        );
    }

    /**
     * Tests imageInput with array as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testImageInputArrayParameter()
    {
        $this->specify(
            "imageInput with array parameter returns invalid HTML Strict",
            function () {

                $options = [
                    'x_name',
                    'class' => 'x_class',
                ];
                $expected = '<input type="image" value="x_name" '
                          . 'class="x_class"';

                $this->fieldParameter(
                    'imageInput',
                    $options,
                    $expected,
                    false
                );
            }
        );

        $this->specify(
            "imageInput with array parameter returns invalid HTML XHTML",
            function () {

                $options = [
                    'x_name',
                    'class' => 'x_class',
                ];
                $expected = '<input type="image" value="x_name" '
                          . 'class="x_class"';

                $this->fieldParameter(
                    'imageInput',
                    $options,
                    $expected,
                    true
                );
            }
        );
    }

    /**
     * Tests imageInput with array as a parameters and id in it
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testImageInputArrayParameterWithId()
    {
        $this->specify(
            "imageInput with array parameter with id returns invalid HTML Strict",
            function () {

                $options = [
                    'x_name',
                    'id'    => 'x_id',
                    'class' => 'x_class',
                    'size'  => '10'
                ];
                $expected = '<input type="image" id="x_id" value="x_name" '
                          . 'class="x_class" size="10"';

                $this->fieldParameter(
                    'imageInput',
                    $options,
                    $expected,
                    true
                );
            }
        );

        $this->specify(
            "imageInput with array parameter with id returns invalid HTML XHTML",
            function () {

                $options = [
                    'x_name',
                    'id'    => 'x_id',
                    'class' => 'x_class',
                    'size'  => '10'
                ];
                $expected = '<input type="image" id="x_id" value="x_name" '
                          . 'class="x_class" size="10"';

                $this->fieldParameter(
                    'imageInput',
                    $options,
                    $expected,
                    true
                );
            }
        );
    }

    /**
     * Tests imageInput with name and no id in parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testImageInputArrayParameterWithNameNoId()
    {
        $this->specify(
            "imageInput with array parameter with name no id returns invalid HTML Strict",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="image" name="x_other" value="x_name" '
                          . 'class="x_class" size="10"';

                $this->fieldParameter(
                    'imageInput',
                    $options,
                    $expected,
                    false
                );
            }
        );

        $this->specify(
            "imageInput with array parameter with name no id returns invalid HTML XHTML",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="image" name="x_other" value="x_name" '
                          . 'class="x_class" size="10"';

                $this->fieldParameter(
                    'imageInput',
                    $options,
                    $expected,
                    false
                );
            }
        );
    }

    /**
     * Tests imageInput with setDefault
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testImageInputWithSetDefault()
    {
        $this->specify(
            "imageInput with setDefault returns invalid HTML Strict",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="image" name="x_other" '
                          . 'value="x_name" class="x_class" size="10"';

                $this->fieldParameter(
                    'imageInput',
                    $options,
                    $expected,
                    false,
                    'setDefault'
                );
            }
        );

        $this->specify(
            "imageInput with setDefault returns invalid HTML XHTML",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="image" name="x_other" '
                          . 'value="x_name" class="x_class" size="10"';

                $this->fieldParameter(
                    'imageInput',
                    $options,
                    $expected,
                    true,
                    'setDefault'
                );
            }
        );
    }

    /**
     * Tests imageInput with displayTo
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testImageInputWithDisplayTo()
    {
        $this->specify(
            "imageInput with displayTo returns invalid HTML Strict",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="image" name="x_other" '
                          . 'value="x_name" class="x_class" size="10"';

                $this->fieldParameter(
                    'imageInput',
                    $options,
                    $expected,
                    false,
                    'displayTo'
                );
            }
        );

        $this->specify(
            "imageInput with displayTo returns invalid HTML XHTML",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="image" name="x_other" '
                          . 'value="x_name" class="x_class" size="10"';

                $this->fieldParameter(
                    'imageInput',
                    $options,
                    $expected,
                    true,
                    'displayTo'
                );
            }
        );
    }

    /**
     * Tests imageInput with setDefault and element not present
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testImageInputWithSetDefaultElementNotPresent()
    {
        $this->specify(
            "imageInput with setDefault and element not present returns invalid HTML Strict",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="image" name="x_other" '
                          . 'value="x_name" class="x_class" size="10"';

                $this->fieldParameter(
                    'imageInput',
                    $options,
                    $expected,
                    false,
                    'setDefault'
                );
            }
        );

        $this->specify(
            "imageInput with setDefault and element not present returns invalid HTML XHTML",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="image" name="x_other" '
                          . 'value="x_name" class="x_class" size="10"';

                $this->fieldParameter(
                    'imageInput',
                    $options,
                    $expected,
                    true,
                    'setDefault'
                );
            }
        );
    }

    /**
     * Tests imageInput with displayTo and element not present
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testImageInputWithDisplayToElementNotPresent()
    {
        $this->specify(
            "imageInput with displayTo and element not present returns invalid HTML Strict",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="image" name="x_other" '
                          . 'value="x_name" class="x_class" size="10"';

                $this->fieldParameter(
                    'imageInput',
                    $options,
                    $expected,
                    false,
                    'displayTo'
                );
            }
        );

        $this->specify(
            "imageInput with displayTo and element not present returns invalid HTML XHTML",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="image" name="x_other" '
                          . 'value="x_name" class="x_class" size="10"';

                $this->fieldParameter(
                    'imageInput',
                    $options,
                    $expected,
                    true,
                    'displayTo'
                );
            }
        );
    }
}
