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
 * Class JavascriptCest
 *
 * @package Phalcon\Test\Unit\Html\Tag
 */
class JavascriptCest
{
    use DiTrait;
    use TagSetupTrait;

    /**
     * Tests Phalcon\Tag :: javascript() - local
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-29
     */
    public function htmlTagJavascriptLocal(UnitTester $I)
    {
        $I->wantToTest("Tag - javascript() - local");
        $tag = new Tag();
        $tag->setDI($this->container);

        $url      = 'js/phalcon.js';
        $expected = '<script src="/js/phalcon.js"></script>' . PHP_EOL;
        $actual   = $tag->javascript($url);
        $I->assertEquals($expected, $actual);
    }


    /**
     * Tests Phalcon\Tag :: javascript() - remote
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-29
     */
    public function htmlTagJavascriptRemote(UnitTester $I)
    {
        $I->wantToTest("Tag - javascript() - remote link");
        $tag = new Tag();
        $tag->setDI($this->container);

        $url      = 'http://my.local.com/js/phalcon.js';
        $options  = ['local' => false];
        $expected = '<script src="http://my.local.com/js/phalcon.js"></script>' . PHP_EOL;
        $actual   = $tag->javascript($url, $options);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Tag :: javascript() - HTML5
     *
     * @param UnitTester $I
     *
     * @issue https://github.com/phalcon/cphalcon/issues/13341
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-12-22
     */
    public function htmlTagJavascriptHtml5(UnitTester $I)
    {
        $I->wantToTest("Tag - javascript() - HTML5");
        $tag = new Tag();
        $tag->setDI($this->container);
        $tag->setDocType(Tag::HTML32);

        $url      = 'js/phalcon.js';
        $expected = '<script type="text/javascript" src="/js/phalcon.js"></script>' . PHP_EOL;
        $actual   = $tag->javascript($url);
        $I->assertEquals($expected, $actual);
    }
}
