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

namespace Phalcon\Test\Unit\Assets\Manager;

use Phalcon\Assets\Asset\Css;
use Phalcon\Assets\Manager;
use Phalcon\Test\Fixtures\Assets\TrimFilter;
use Phalcon\Test\Fixtures\Assets\UppercaseFilter;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use UnitTester;

/**
 * Class OutputCssCest
 */
class OutputCssCest
{
    use DiTrait;

    /**
     * @param UnitTester $I
     */
    public function _after(UnitTester $I)
    {
        $this->resetDi();
    }

    /**
     * @param UnitTester $I
     */
    public function _before(UnitTester $I)
    {
        $this->newDi();
        $this->setDiEscaper();
        $this->setDiUrl();
    }

    /**
     * Tests Phalcon\Assets\Manager :: outputCss() - implicit
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-13
     */
    public function assetsManagerOutputCssImplicit(UnitTester $I)
    {
        $I->wantToTest('Assets\Manager - outputCss() - implicit');
        $assets = new Manager();

        $assets->addCss('css/style1.css');
        $assets->addCss('css/style2.css');
        $assets->addAsset(new Css('/css/style.css', false));

        $expected = '<link rel="stylesheet" type="text/css" href="/css/style1.css" />' . PHP_EOL
            . '<link rel="stylesheet" type="text/css" href="/css/style2.css" />' . PHP_EOL
            . '<link rel="stylesheet" type="text/css" href="/css/style.css" />' . PHP_EOL;

        $assets->useImplicitOutput(false);
        $actual = $assets->outputCss();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Assets\Manager :: outputCss() - not implicit
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-13
     */
    public function assetsManagerOutputCssNotImplicit(UnitTester $I)
    {
        $I->wantToTest('Assets\Manager - outputCss() - not implicit');
        $assets = new Manager();

        $assets->addCss('css/style1.css');
        $assets->addCss('css/style2.css');
        $assets->addAsset(new Css('/css/style.css', false));

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
     * @param UnitTester $I
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/1198
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2013-09-15
     */
    public function assetsManagerOutputCssFilterChainCustomFilterWithCssmin(UnitTester $I)
    {
        $I->wantToTest('Assets\Manager - outputCss() - filter chain custom filter with cssmin');
        $fileName = $I->getNewFileName('assets_', 'css');
        $assets   = new Manager();
        $assets->useImplicitOutput(false);
        $css     = $assets->collection('css');
        $cssFile = dataFolder('assets/assets/1198.css');

        $css->setTargetPath(cacheFolder($fileName));
        $css->addCss($cssFile);
        $css->addFilter(new UppercaseFilter());
        $css->addFilter(new TrimFilter());
        $css->join(true);
        $assets->outputCss('css');

        $expected = 'A{TEXT-DECORATION:NONE;}B{FONT-WEIGHT:BOLD;}';
        $actual   = file_get_contents(cacheFolder($fileName));

        $I->safeDeleteFile(cacheFolder($fileName));

        $I->assertEquals($expected, $actual);
    }
}
