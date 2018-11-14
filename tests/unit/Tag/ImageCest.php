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

use Phalcon\Tag;
use Phalcon\Test\Fixtures\Helpers\TagSetup;
use UnitTester;

class ImageCest extends TagSetup
{
    /**
     * Tests Phalcon\Tag :: image() - string as a parameter
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function testImageStringParameter(UnitTester $I)
    {
        $options  = 'img/hello.gif';
        $expected = '<img src="/img/hello.gif"';

        $this->testFieldParameter($I, 'image', $options, $expected);
        $this->testFieldParameter($I, 'image', $options, $expected, true);
    }

    /**
     * Tests Phalcon\Tag :: image() - array as a parameter
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function testImageArrayParameter(UnitTester $I)
    {
        $options  = [
            'img/hello.gif',
            'class' => 'x_class',
        ];
        $expected = '<img src="/img/hello.gif" class="x_class"';

        $this->testFieldParameter($I, 'image', $options, $expected);
        $this->testFieldParameter($I, 'image', $options, $expected, true);
    }

    /**
     * Tests Phalcon\Tag :: image() - array as a parameters and src in it
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function testImageArrayParameterWithSrc(UnitTester $I)
    {
        $options  = [
            'img/hello.gif',
            'src'   => 'img/goodbye.gif',
            'class' => 'x_class',
        ];
        $expected = '<img src="/img/goodbye.gif" class="x_class"';

        $this->testFieldParameter($I, 'image', $options, $expected);
        $this->testFieldParameter($I, 'image', $options, $expected, true);
    }

    /**
     * Tests Phalcon\Tag :: image() - name and no src in parameter
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function testImageArrayParameterWithNameNoSrc(UnitTester $I)
    {
        $options  = [
            'img/hello.gif',
            'class' => 'x_class',
        ];
        $expected = '<img src="/img/hello.gif" class="x_class"';

        $this->testFieldParameter($I, 'image', $options, $expected);
        $this->testFieldParameter($I, 'image', $options, $expected, true);
    }

    /**
     * Tests Phalcon\Tag :: image() - setDefault
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function testImageWithSetDefault(UnitTester $I)
    {
        $options  = [
            'img/hello.gif',
            'class' => 'x_class',
        ];
        $expected = '<img src="/img/hello.gif" class="x_class"';

        $this->testFieldParameter($I, 'image', $options, $expected, false, 'setDefault');
        $this->testFieldParameter($I, 'image', $options, $expected, true, 'setDefault');
    }

    /**
     * Tests Phalcon\Tag :: image() - displayTo
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function testImageWithDisplayTo(UnitTester $I)
    {
        $options  = [
            'img/hello.gif',
            'class' => 'x_class',
        ];
        $expected = '<img src="/img/hello.gif" class="x_class"';

        $this->testFieldParameter($I, 'image', $options, $expected, false, 'displayTo');
        $this->testFieldParameter($I, 'image', $options, $expected, true, 'displayTo');
    }

    /**
     * Tests Phalcon\Tag :: image() - setDefault and element not present
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function testImageWithSetDefaultElementNotPresent(UnitTester $I)
    {
        $options  = [
            'img/hello.gif',
            'class' => 'x_class',
        ];
        $expected = '<img src="/img/hello.gif" class="x_class"';

        $this->testFieldParameter($I, 'image', $options, $expected, false, 'setDefault');
        $this->testFieldParameter($I, 'image', $options, $expected, true, 'setDefault');
    }

    /**
     * Tests Phalcon\Tag :: image() - displayTo and element not present
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function testImageWithDisplayToElementNotPresent(UnitTester $I)
    {
        $options  = [
            'img/hello.gif',
            'class' => 'x_class',
        ];
        $expected = '<img src="/img/hello.gif" class="x_class"';

        $this->testFieldParameter($I, 'image', $options, $expected, false, 'displayTo');
        $this->testFieldParameter($I, 'image', $options, $expected, true, 'displayTo');
    }

    /**
     * Tests Phalcon\Tag :: image() - string parameter and local link
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function testImageStringParameterLocalLink(UnitTester $I)
    {
        $options  = 'img/hello.gif';
        $expected = '<img src="/img/hello.gif" />';

        Tag::setDocType(Tag::XHTML10_STRICT);
        $actual = Tag::image($options, true);

        $I->assertEquals($expected, $actual);

        $options  = 'img/hello.gif';
        $expected = '<img src="/img/hello.gif">';

        Tag::setDocType(Tag::HTML5);
        $actual = Tag::image($options, true);

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Tag :: image() - string parameter and remote link
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function testImageStringParameterRemoteLink(UnitTester $I)
    {
        $options  = 'http://phalconphp.com/img/hello.gif';
        $expected = '<img src="http://phalconphp.com/img/hello.gif" />';

        Tag::setDocType(Tag::XHTML10_STRICT);
        $actual = Tag::image($options, false);

        $I->assertEquals($expected, $actual);

        $options  = 'http://phalconphp.com/img/hello.gif';
        $expected = '<img src="http://phalconphp.com/img/hello.gif">';

        Tag::setDocType(Tag::HTML5);
        $actual = Tag::image($options, false);

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Tag :: image() - array parameter and local link
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function testImageArrayParameterLocalLink(UnitTester $I)
    {
        $options  = [
            'img/hello.gif',
            'alt' => 'Hello',
        ];
        $expected = '<img src="/img/hello.gif" alt="Hello" />';

        Tag::setDocType(Tag::XHTML10_STRICT);
        $actual = Tag::image($options, true);

        $I->assertEquals($expected, $actual);

        $options  = [
            'img/hello.gif',
            'alt' => 'Hello',
        ];
        $expected = '<img src="/img/hello.gif" alt="Hello">';

        Tag::setDocType(Tag::HTML5);
        $actual = Tag::image($options, true);

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Tag :: image() - array parameter and remote link
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function testImageArrayParameterRemoteLink(UnitTester $I)
    {
        $options  = [
            'http://phalconphp.com/img/hello.gif',
            'alt' => 'Hello',
        ];
        $expected = '<img src="http://phalconphp.com/img/hello.gif" '
            . 'alt="Hello" />';

        Tag::setDocType(Tag::XHTML10_STRICT);
        $actual = Tag::image($options, false);

        $I->assertEquals($expected, $actual);

        $options  = [
            'http://phalconphp.com/img/hello.gif',
            'alt' => 'Hello',
        ];
        $expected = '<img src="http://phalconphp.com/img/hello.gif" '
            . 'alt="Hello">';

        Tag::setDocType(Tag::HTML5);
        $actual = Tag::image($options, false);

        $I->assertEquals($expected, $actual);
    }
}
