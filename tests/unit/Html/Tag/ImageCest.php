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

namespace Phalcon\Test\Unit\Html\Tag;

use Phalcon\Html\Tag;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Fixtures\Traits\TagSetupTrait;
use UnitTester;

/**
 * Class ImageCest
 *
 * @package Phalcon\Test\Unit\Html\Tag
 */
class ImageCest
{
    use DiTrait;
    use TagSetupTrait;

    /**
     * Tests Phalcon\Html\Tag :: image()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function htmlTagImage(UnitTester $I)
    {
        $I->wantToTest('Html\Tag - image()');
        $tag = new Tag();
        $tag->setDI($this->container);

        $name     = 'img/hello.gif';
        $options  = [];
        $expected = '<img src="/img/hello.gif"';

        $this->testFieldParameter($I, $tag, $name, 'image', $options, $expected);
        $this->testFieldParameter($I, $tag, $name, 'image', $options, $expected, true);
    }

    /**
     * Tests Phalcon\Html\Tag :: image() - remote
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function htmlTagImageRemote(UnitTester $I)
    {
        $I->wantToTest('Html\Tag - image() - remote');
        $tag = new Tag();
        $tag->setDI($this->container);

        $name     = 'http://phalconphp.com/img/hello.gif';
        $options  = [
            'local' => false,
            'alt'   => 'picture',
        ];
        $expected = '<img src="http://phalconphp.com/img/hello.gif" alt="picture"';

        $this->testFieldParameter($I, $tag, $name, 'image', $options, $expected);
        $this->testFieldParameter($I, $tag, $name, 'image', $options, $expected, true);
    }

    /**
     * Tests Phalcon\Html\Tag :: image() - params
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function htmlTagImageParameters(UnitTester $I)
    {
        $I->wantToTest('Html\Tag - image() - params');
        $tag = new Tag();
        $tag->setDI($this->container);

        $name     = 'img/hello.gif';
        $options  = [
            'class' => 'x_class',
        ];
        $expected = '<img src="/img/hello.gif" class="x_class"';

        $this->testFieldParameter($I, $tag, $name, 'image', $options, $expected);
        $this->testFieldParameter($I, $tag, $name, 'image', $options, $expected, true);
    }

    /**
     * Tests Phalcon\Html\Tag :: image() - params src
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function htmlTagImageParametersSrc(UnitTester $I)
    {
        $I->wantToTest('Html\Tag - image() - params src');
        $tag = new Tag();
        $tag->setDI($this->container);

        $name     = 'img/hello.gif';
        $options  = [
            'class' => 'x_class',
            'src'   => 'img/goodbye.gif',
        ];
        $expected = '<img src="/img/hello.gif" class="x_class"';

        $this->testFieldParameter($I, $tag, $name, 'image', $options, $expected);
        $this->testFieldParameter($I, $tag, $name, 'image', $options, $expected, true);
    }

    /**
     * Tests Phalcon\Html\Tag :: image() - setAttribute()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function htmlTagImageSetAttribute(UnitTester $I)
    {
        $I->wantToTest('Html\Tag - image() - setAttribute()');
        $tag = new Tag();
        $tag->setDI($this->container);

        $name     = 'img/hello.gif';
        $options  = [
            'class' => 'x_class',
        ];
        $expected = '<img src="/img/hello.gif" class="x_class"';

        $this->testFieldParameter($I, $tag, $name, 'image', $options, $expected, false, 'setAttribute');
        $this->testFieldParameter($I, $tag, $name, 'image', $options, $expected, true, 'setAttribute');
    }

    /**
     * Tests Phalcon\Html\Tag :: image() - setAttribute() element not present
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function htmlTagImageSetAttributeElementNotPresent(UnitTester $I)
    {
        $I->wantToTest('Html\Tag - image() - setAttribute() element not present');
        $tag = new Tag();
        $tag->setDI($this->container);

        $name     = 'img/hello.gif';
        $options  = [
            'class' => 'x_class',
        ];
        $expected = '<img src="/img/hello.gif" class="x_class"';

        $this->testFieldParameter($I, $tag, $name, 'image', $options, $expected, false, 'setAttribute');
        $this->testFieldParameter($I, $tag, $name, 'image', $options, $expected, true, 'setAttribute');
    }
}
