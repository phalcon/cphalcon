<?php
declare(strict_types=1);

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
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function tagImageStringParameter(UnitTester $I)
    {
        $I->wantToTest("Tag :: image() - string as a parameter");
        $options  = 'img/hello.gif';
        $expected = '<img src="/img/hello.gif"';

        $this->testFieldParameter($I, 'image', $options, $expected);
        $this->testFieldParameter($I, 'image', $options, $expected, true);
    }

    /**
     * Tests Phalcon\Tag :: image() - array as a parameter
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function tagImageArrayParameter(UnitTester $I)
    {
        $I->wantToTest("Tag :: image() - array as a parameter");
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
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function tagImageArrayParameterWithSrc(UnitTester $I)
    {
        $I->wantToTest("Tag :: image() - array as a parameters and src in it");
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
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function tagImageArrayParameterWithNameNoSrc(UnitTester $I)
    {
        $I->wantToTest("Tag :: image() - name and no src in parameter");
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
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function tagImageWithSetDefault(UnitTester $I)
    {
        $I->wantToTest("Tag :: image() - setDefault()");
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
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function tagImageWithDisplayTo(UnitTester $I)
    {
        $I->wantToTest("Tag :: image() - displayTo()");
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
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function tagImageWithSetDefaultElementNotPresent(UnitTester $I)
    {
        $I->wantToTest("Tag :: image() - setDefault() and element not present");
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
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function tagImageWithDisplayToElementNotPresent(UnitTester $I)
    {
        $I->wantToTest("Tag :: image() - displayTo() and element not present");
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
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function tagImageStringParameterLocalLink(UnitTester $I)
    {
        $I->wantToTest("Tag :: image() - string parameter and local link");
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
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function tagImageStringParameterRemoteLink(UnitTester $I)
    {
        $I->wantToTest("Tag :: image() - string parameter and remote link");
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
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function tagImageArrayParameterLocalLink(UnitTester $I)
    {
        $I->wantToTest("Tag :: image() - array parameter and local link");
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
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function tagImageArrayParameterRemoteLink(UnitTester $I)
    {
        $I->wantToTest("Tag :: image() - array parameter and remote link");
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
