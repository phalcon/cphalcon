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

use Phalcon\Test\Fixtures\Assets\TrimFilter;
use Phalcon\Test\Fixtures\Assets\UppercaseFilter;
use Phalcon\Assets\Manager;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use UnitTester;

/**
 * Class OutputCssCest
 *
 * @package Phalcon\Test\Unit\Assets\Manager
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
     * Tests Phalcon\Assets\Manager :: outputCss()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsManagerOutputCss(UnitTester $I)
    {
        $I->wantToTest('Assets\Manager - outputCss()');
        $I->skipTest('Need implementation');
    }

    /**
     * Tests Phalcon\Assets\Manager :: outputCss() - filter chain custom filter with cssmin
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
