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

namespace Phalcon\Tests\Unit\Assets\Manager;

use Phalcon\Assets\Asset\Css;
use Phalcon\Assets\Manager;
use Phalcon\Html\Escaper;
use Phalcon\Html\TagFactory;
use Phalcon\Tests\Fixtures\Assets\TrimFilter;
use Phalcon\Tests\Fixtures\Assets\UppercaseFilter;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use UnitTester;

use function outputDir;

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

        $manager = new Manager(new TagFactory(new Escaper()));

        $manager->addCss('css/style1.css');
        $manager->addCss('css/style2.css');
        $manager->addAsset(
            new Css('/css/style.css', false)
        );

        $expected = '<link rel="stylesheet" type="text/css" href="/css/style1.css" />' . PHP_EOL
            . '<link rel="stylesheet" type="text/css" href="/css/style2.css" />' . PHP_EOL
            . '<link rel="stylesheet" type="text/css" href="/css/style.css" />' . PHP_EOL;

        $manager->useImplicitOutput(false);

        $I->assertEquals($expected, $manager->outputCss());
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

        $manager = new Manager(new TagFactory(new Escaper()));

        $manager->addCss('css/style1.css');
        $manager->addCss('css/style2.css');
        $manager->addAsset(new Css('/css/style.css', false));

        $expected = '<link rel="stylesheet" type="text/css" href="/css/style1.css" />' . PHP_EOL
            . '<link rel="stylesheet" type="text/css" href="/css/style2.css" />' . PHP_EOL
            . '<link rel="stylesheet" type="text/css" href="/css/style.css" />' . PHP_EOL;

        ob_start();
        $manager->outputCss();
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
    public function assetsManagerOutputCssFilterChainCustomFilter(UnitTester $I)
    {
        $I->wantToTest(
            'Assets\Manager - outputCss() - filter chain custom filter'
        );

        $fileName = $I->getNewFileName('assets_', 'css');
        $fileName = outputDir('tests/assets/' . $fileName);
        $cssFile  = dataDir('assets/assets/1198.css');
        $manager  = new Manager(new TagFactory(new Escaper()));

        $manager->useImplicitOutput(false);

        $css = $manager->collection('css');

        $css
            ->setTargetPath($fileName)
            ->addCss($cssFile)
            ->addFilter(new UppercaseFilter())
            ->addFilter(new TrimFilter())
            ->join(true)
        ;

        $manager->outputCss('css');

        $expected = 'A{TEXT-DECORATION:NONE;}B{FONT-WEIGHT:BOLD;}';
        $I->openFile($fileName);

        $I->seeFileContentsEqual($expected);

        $I->safeDeleteFile($fileName);
    }
}
