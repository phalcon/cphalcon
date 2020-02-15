<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Unit\Assets\Manager;

use Phalcon\Assets\Asset\Css;
use Phalcon\Assets\Manager;
use Phalcon\Test\Fixtures\Assets\CustomTag;
use Phalcon\Test\Fixtures\Assets\TrimFilter;
use Phalcon\Test\Fixtures\Assets\UppercaseFilter;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use UnitTester;

class OutputCssCest
{
    use DiTrait;

    public function _after(UnitTester $I)
    {
        $this->resetDi();
    }

    public function _before(UnitTester $I)
    {
        $this->newDi();
        $this->setDiService('escaper');
        $this->setDiService('url');
    }

    /**
     * Tests Phalcon\Assets\Manager :: outputCss() - implicit
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-13
     */
    public function assetsManagerOutputCssImplicit(UnitTester $I)
    {
        $I->wantToTest('Assets\Manager - outputCss() - implicit');

        $assets = new Manager();

        $assets->addCss('css/style1.css');
        $assets->addCss('css/style2.css');

        $assets->addAsset(
            new Css('/css/style.css', false)
        );

        $expected = '<link rel="stylesheet" type="text/css" href="/css/style1.css" />' . PHP_EOL
            . '<link rel="stylesheet" type="text/css" href="/css/style2.css" />' . PHP_EOL
            . '<link rel="stylesheet" type="text/css" href="/css/style.css" />' . PHP_EOL;

        $assets->useImplicitOutput(false);

        $I->assertEquals(
            $expected,
            $assets->outputCss()
        );
    }

    /**
     * Tests Phalcon\Assets\Manager :: outputCss() - not implicit
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-13
     */
    public function assetsManagerOutputCssNotImplicit(UnitTester $I)
    {
        $I->wantToTest('Assets\Manager - outputCss() - not implicit');

        $assets = new Manager();

        $assets->addCss('css/style1.css');
        $assets->addCss('css/style2.css');

        $assets->addAsset(
            new Css('/css/style.css', false)
        );

        $expected = '<link rel="stylesheet" type="text/css" href="/css/style1.css" />' . PHP_EOL
            . '<link rel="stylesheet" type="text/css" href="/css/style2.css" />' . PHP_EOL
            . '<link rel="stylesheet" type="text/css" href="/css/style.css" />' . PHP_EOL;

        ob_start();
        $assets->outputCss();
        $actual = ob_get_clean();

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Assets\Manager :: outputCss() - filter chain custom filter
     * with cssmin
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/1198
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2013-09-15
     */
    public function assetsManagerOutputCssFilterChainCustomFilterWithCssmin(UnitTester $I)
    {
        $I->wantToTest(
            'Assets\Manager - outputCss() - filter chain custom filter with cssmin'
        );

        $fileName = $I->getNewFileName('assets_', 'css');

        $assets = new Manager();

        $assets->useImplicitOutput(false);

        $css     = $assets->collection('css');
        $cssFile = dataDir('assets/assets/1198.css');

        $css->setTargetPath(
            cacheDir($fileName)
        );

        $css->addCss($cssFile);

        $css->addFilter(
            new UppercaseFilter()
        );

        $css->addFilter(
            new TrimFilter()
        );

        $css->join(true);

        $assets->outputCss('css');

        $I->openFile(
            cacheDir($fileName)
        );

        $I->seeFileContentsEqual(
            'A{TEXT-DECORATION:NONE;}B{FONT-WEIGHT:BOLD;}'
        );

        $I->safeDeleteFile(
            cacheDir($fileName)
        );
    }

    /**
     * Tests Phalcon\Assets\Manager :: outputCss() - custom tag component
     */
    public function assetsManagerOutputCssCustomTag(UnitTester $I)
    {
        $I->wantToTest('Assets\Manager - outputCss() - custom tag component');

        $di = $this->getDi();

        $di->setShared('tag', CustomTag::class);

        $assets = new Manager();

        $assets->setDI($di);

        $assets->addCss('css/style1.css');
        $assets->addCss('/css/style2.css');

        $assets->addAsset(
            new Css('/css/style.css')
        );

        $expected = '<link href="css/style1.css">' . PHP_EOL
            . '<link href="/css/style2.css">' . PHP_EOL
            . '<link href="/css/style.css">' . PHP_EOL;

        $assets->useImplicitOutput(false);

        $I->assertEquals(
            $expected,
            $assets->outputCss()
        );
    }
}
