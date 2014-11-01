<?php
/**
 * TagImageTest.php
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

class TagImageTest extends Helper\TagBase
{
    /**
     * Tests image with string as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testImageStringParameter()
    {
        $this->specify(
            "image with string parameter returns invalid HTML Strict",
            function () {

                $options  = 'img/hello.gif';
                $expected = '<img src="/img/hello.gif"';

                $this->fieldParameter(
                    'image',
                    $options,
                    $expected,
                    false
                );
            }
        );

        $this->specify(
            "image with string parameter returns invalid HTML XHTML",
            function () {

                $options  = 'img/hello.gif';
                $expected = '<img src="/img/hello.gif"';

                $this->fieldParameter(
                    'image',
                    $options,
                    $expected,
                    true
                );
            }
        );
    }

    /**
     * Tests image with array as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testImageArrayParameter()
    {
        $this->specify(
            "image with array parameter returns invalid HTML Strict",
            function () {

                $options  = [
                    'img/hello.gif',
                    'class' => 'x_class',
                ];
                $expected = '<img src="/img/hello.gif" class="x_class"';

                $this->fieldParameter(
                    'image',
                    $options,
                    $expected,
                    false
                );
            }
        );

        $this->specify(
            "image with array parameter returns invalid HTML XHTML",
            function () {

                $options  = [
                    'img/hello.gif',
                    'class' => 'x_class',
                ];
                $expected = '<img src="/img/hello.gif" class="x_class"';

                $this->fieldParameter(
                    'image',
                    $options,
                    $expected,
                    true
                );
            }
        );
    }

    /**
     * Tests image with array as a parameters and src in it
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testImageArrayParameterWithSrc()
    {
        $this->specify(
            "image with array parameter with src returns invalid HTML Strict",
            function () {

                $options  = [
                    'img/hello.gif',
                    'src'   => 'img/goodbye.gif',
                    'class' => 'x_class',
                ];
                $expected = '<img src="/img/goodbye.gif" class="x_class"';

                $this->fieldParameter(
                    'image',
                    $options,
                    $expected,
                    true
                );
            }
        );

        $this->specify(
            "image with array parameter with src returns invalid HTML XHTML",
            function () {

                $options  = [
                    'img/hello.gif',
                    'src'   => 'img/goodbye.gif',
                    'class' => 'x_class',
                ];
                $expected = '<img src="/img/goodbye.gif" class="x_class"';

                $this->fieldParameter(
                    'image',
                    $options,
                    $expected,
                    true
                );
            }
        );
    }

    /**
     * Tests image with name and no src in parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testImageArrayParameterWithNameNoSrc()
    {
        $this->specify(
            "image with array parameter with name no src returns invalid HTML Strict",
            function () {

                $options  = [
                    'img/hello.gif',
                    'class' => 'x_class',
                ];
                $expected = '<img src="/img/hello.gif" class="x_class"';

                $this->fieldParameter(
                    'image',
                    $options,
                    $expected,
                    false
                );
            }
        );

        $this->specify(
            "image with array parameter with name no src returns invalid HTML XHTML",
            function () {

                $options  = [
                    'img/hello.gif',
                    'class' => 'x_class',
                ];
                $expected = '<img src="/img/hello.gif" class="x_class"';

                $this->fieldParameter(
                    'image',
                    $options,
                    $expected,
                    false
                );
            }
        );
    }

    /**
     * Tests image with setDefault
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testImageWithSetDefault()
    {
        $this->specify(
            "image with setDefault returns invalid HTML Strict",
            function () {

                $options  = [
                    'img/hello.gif',
                    'class' => 'x_class',
                ];
                $expected = '<img src="/img/hello.gif" class="x_class"';

                $this->fieldParameter(
                    'image',
                    $options,
                    $expected,
                    false,
                    'setDefault'
                );
            }
        );

        $this->specify(
            "image with setDefault returns invalid HTML XHTML",
            function () {

                $options  = [
                    'img/hello.gif',
                    'class' => 'x_class',
                ];
                $expected = '<img src="/img/hello.gif" class="x_class"';

                $this->fieldParameter(
                    'image',
                    $options,
                    $expected,
                    true,
                    'setDefault'
                );
            }
        );
    }

    /**
     * Tests image with displayTo
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testImageWithDisplayTo()
    {
        $this->specify(
            "image with displayTo returns invalid HTML Strict",
            function () {

                $options  = [
                    'img/hello.gif',
                    'class' => 'x_class',
                ];
                $expected = '<img src="/img/hello.gif" class="x_class"';

                $this->fieldParameter(
                    'image',
                    $options,
                    $expected,
                    false,
                    'displayTo'
                );
            }
        );

        $this->specify(
            "image with displayTo returns invalid HTML XHTML",
            function () {

                $options  = [
                    'img/hello.gif',
                    'class' => 'x_class',
                ];
                $expected = '<img src="/img/hello.gif" class="x_class"';

                $this->fieldParameter(
                    'image',
                    $options,
                    $expected,
                    true,
                    'displayTo'
                );
            }
        );
    }

    /**
     * Tests image with setDefault and element not present
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testImageWithSetDefaultElementNotPresent()
    {
        $this->specify(
            "image with setDefault and element not present returns invalid HTML Strict",
            function () {

                $options  = [
                    'img/hello.gif',
                    'class' => 'x_class',
                ];
                $expected = '<img src="/img/hello.gif" class="x_class"';

                $this->fieldParameter(
                    'image',
                    $options,
                    $expected,
                    false,
                    'setDefault'
                );
            }
        );

        $this->specify(
            "image with setDefault and element not present returns invalid HTML XHTML",
            function () {

                $options  = [
                    'img/hello.gif',
                    'class' => 'x_class',
                ];
                $expected = '<img src="/img/hello.gif" class="x_class"';

                $this->fieldParameter(
                    'image',
                    $options,
                    $expected,
                    true,
                    'setDefault'
                );
            }
        );
    }

    /**
     * Tests image with displayTo and element not present
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testImageWithDisplayToElementNotPresent()
    {
        $this->specify(
            "image with displayTo and element not present returns invalid HTML Strict",
            function () {

                $options  = [
                    'img/hello.gif',
                    'class' => 'x_class',
                ];
                $expected = '<img src="/img/hello.gif" class="x_class"';

                $this->fieldParameter(
                    'image',
                    $options,
                    $expected,
                    false,
                    'displayTo'
                );
            }
        );

        $this->specify(
            "image with displayTo and element not present returns invalid HTML XHTML",
            function () {

                $options  = [
                    'img/hello.gif',
                    'class' => 'x_class',
                ];
                $expected = '<img src="/img/hello.gif" class="x_class"';

                $this->fieldParameter(
                    'image',
                    $options,
                    $expected,
                    true,
                    'displayTo'
                );
            }
        );
    }

    /**
     * Tests image with string parameter and local link
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testImageStringParameterLocalLink()
    {
        $this->specify(
            "image with string parameter and local link returns invalid HTML Strict",
            function () {

                $options  = 'img/hello.gif';
                $expected = '<img src="/img/hello.gif" />';

                PhTTag::setDocType(PhTTag::XHTML10_STRICT);
                $actual   = PhTTag::image($options, true);

                expect($actual)->equals($expected);
            }
        );

        $this->specify(
            "image with string parameter and local link returns invalid HTML XHTML",
            function () {

                $options  = 'img/hello.gif';
                $expected = '<img src="/img/hello.gif">';

                PhTTag::setDocType(PhTTag::HTML5);
                $actual   = PhTTag::image($options, true);

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests image with string parameter and remote link
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testImageStringParameterRemoteLink()
    {
        $this->specify(
            "image with string parameter and remote link returns invalid HTML Strict",
            function () {

                $options  = 'http://phalconphp.com/img/hello.gif';
                $expected = '<img src="http://phalconphp.com/img/hello.gif" />';

                PhTTag::setDocType(PhTTag::XHTML10_STRICT);
                $actual   = PhTTag::image($options, false);

                expect($actual)->equals($expected);
            }
        );

        $this->specify(
            "image with string parameter and local link returns invalid HTML XHTML",
            function () {

                $options  = 'http://phalconphp.com/img/hello.gif';
                $expected = '<img src="http://phalconphp.com/img/hello.gif">';

                PhTTag::setDocType(PhTTag::HTML5);
                $actual   = PhTTag::image($options, false);

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests image with array parameter and local link
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testImageArrayParameterLocalLink()
    {
        $this->specify(
            "image with array parameter and local link returns invalid HTML Strict",
            function () {

                $options  = [
                    'img/hello.gif',
                    'alt' => 'Hello'
                ];
                $expected = '<img src="/img/hello.gif" alt="Hello" />';

                PhTTag::setDocType(PhTTag::XHTML10_STRICT);
                $actual   = PhTTag::image($options, true);

                expect($actual)->equals($expected);
            }
        );

        $this->specify(
            "image with array parameter and local link returns invalid HTML XHTML",
            function () {

                $options  = [
                    'img/hello.gif',
                    'alt' => 'Hello'
                ];
                $expected = '<img src="/img/hello.gif" alt="Hello">';

                PhTTag::setDocType(PhTTag::HTML5);
                $actual   = PhTTag::image($options, true);

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests image with array parameter and remote link
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testImageArrayParameterRemoteLink()
    {
        $this->specify(
            "image with array parameter and remote link returns invalid HTML Strict",
            function () {

                $options  = [
                    'http://phalconphp.com/img/hello.gif',
                    'alt' => 'Hello'
                ];
                $expected = '<img src="http://phalconphp.com/img/hello.gif" '
                          . 'alt="Hello" />';

                PhTTag::setDocType(PhTTag::XHTML10_STRICT);
                $actual   = PhTTag::image($options, false);

                expect($actual)->equals($expected);
            }
        );

        $this->specify(
            "image with array parameter and local link returns invalid HTML XHTML",
            function () {

                $options  = [
                    'http://phalconphp.com/img/hello.gif',
                    'alt' => 'Hello'
                ];
                $expected = '<img src="http://phalconphp.com/img/hello.gif" '
                          . 'alt="Hello">';

                PhTTag::setDocType(PhTTag::HTML5);
                $actual   = PhTTag::image($options, false);

                expect($actual)->equals($expected);
            }
        );
    }
}
