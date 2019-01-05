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

use BadMethodCallException;
use Phalcon\Html\Tag;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Fixtures\Traits\TagSetupTrait;
use UnitTester;
use const PHP_EOL;

/**
 * Class ElementCest
 *
 * @package Phalcon\Test\Unit\Html\Tag
 */
class ElementCest
{
    use DiTrait;
    use TagSetupTrait;

    /**
     * Tests Phalcon\Html\Tag :: element()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function htmlTagElement(UnitTester $I)
    {
        $I->wantToTest('Html\Tag - element()');
        $tag = new Tag();
        $tag->setDI($this->container);
        $name       = 'canvas';
        $parameters = [
            'width'  => 300,
            'height' => 300,
        ];
        $expected   = '<canvas width="300" height="300">';

        $actual = $tag
            ->setDocType(Tag::XHTML10_STRICT)
            ->element($name, $parameters)
        ;
        $I->assertEquals($expected, $actual);

        $parameters = [
            'id'     => 'canvas1',
            'name'   => 'canvas2',
            'width'  => 300,
            'height' => 300,
        ];
        $expected   = '<canvas id="canvas1" name="canvas2" width="300" height="300"></canvas>';
        $actual     = $tag
            ->setDocType(Tag::HTML5)
            ->element($name, $parameters)
        ;
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Html\Tag :: element() - no name
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function htmlTagElementNoName(UnitTester $I)
    {
        $I->wantToTest('Html\Tag - element() - no name');
        $I->expectThrowable(
            new BadMethodCallException('Wrong number of parameters'),
            function () {
                $tag = new Tag();
                $tag->element();
            }
        );
    }

    /**
     * Tests Phalcon\Tag :: element() - self close
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function htmlTagElementSelfClose(UnitTester $I)
    {
        $I->wantToTest("Tag - tagHtml() - self close");
        $tag = new Tag();
        $tag->setDI($this->container);
        $name       = 'aside';
        $parameters = [
            'selfClose' => true,

        ];

        $expected = '<aside />';
        $actual   = $tag
            ->setDocType(Tag::XHTML10_STRICT)
            ->element($name, $parameters)
        ;
        $I->assertEquals($expected, $actual);

        $expected = '<aside></aside>';
        $actual   = $tag
            ->setDocType(Tag::HTML5)
            ->element($name, $parameters)
        ;
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Tag :: element() - only start
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function htmlTagElementOnlyStart(UnitTester $I)
    {
        $I->wantToTest("Tag - tagHtml() - only start");
        $tag = new Tag();
        $tag->setDI($this->container);
        $name       = 'aside';
        $parameters = [
            'onlyStart' => true,

        ];

        $expected = '<aside>';
        $actual   = $tag
            ->setDocType(Tag::XHTML10_STRICT)
            ->element($name, $parameters)
        ;
        $I->assertEquals($expected, $actual);

        $actual = $tag
            ->setDocType(Tag::HTML5)
            ->element($name, $parameters)
        ;
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Tag :: element() - EOL
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function htmlTagElementEol(UnitTester $I)
    {
        $I->wantToTest("Tag - tagHtml() - name parameter EOL");
        $tag = new Tag();
        $tag->setDI($this->container);
        $name       = 'aside';
        $parameters = [
            'useEol' => true,

        ];
        $expected   = '<aside>' . PHP_EOL;

        $actual = $tag
            ->setDocType(Tag::XHTML10_STRICT)
            ->element($name, $parameters)
        ;
        $I->assertEquals($expected, $actual);

        $expected = '<aside></aside>' . PHP_EOL;
        $actual   = $tag
            ->setDocType(Tag::HTML5)
            ->element($name, $parameters)
        ;
        $I->assertEquals($expected, $actual);
    }
}
