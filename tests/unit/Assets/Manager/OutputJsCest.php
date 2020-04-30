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

use Phalcon\Assets\Asset\Js;
use Phalcon\Assets\Filters\Jsmin;
use Phalcon\Assets\Filters\None;
use Phalcon\Assets\Manager;
use Phalcon\Test\Fixtures\Assets\CustomTag;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use UnitTester;

use function dataDir;
use function ob_get_clean;
use function ob_start;
use function outputDir;
use function sprintf;
use function uniqid;

use const PHP_EOL;

class OutputJsCest
{
    use DiTrait;

    public function _before(UnitTester $I)
    {
        $this->newDi();
        $this->setDiService('escaper');
        $this->setDiService('url');
    }

    public function _after(UnitTester $I)
    {
        $this->resetDi();
    }

    /**
     * Tests Phalcon\Assets\Manager :: outputJs() - implicit
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-13
     */
    public function assetsManagerOutputJsImplicit(UnitTester $I)
    {
        $I->wantToTest('Assets\Manager - outputJs() - implicit');

        $assets = new Manager();

        $assets->addJs('js/script1.js');
        $assets->addJs('js/script2.js');

        $assets->addAsset(
            new Js('/js/script3.js', false)
        );

        $assets->useImplicitOutput(false);

        $expected = '<script src="/js/script1.js"></script>' . PHP_EOL
            . '<script src="/js/script2.js"></script>' . PHP_EOL
            . '<script src="/js/script3.js"></script>' . PHP_EOL;

        $I->assertEquals(
            $expected,
            $actual = $assets->outputJs()
        );
    }

    /**
     * Tests Phalcon\Assets\Manager :: outputJs() - not implicit
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-13
     */
    public function assetsManagerOutputJsNotImplicit(UnitTester $I)
    {
        $I->wantToTest('Assets\Manager - outputJs() - not implicit');

        $assets = new Manager();

        $assets->addJs('js/script1.js');
        $assets->addJs('js/script2.js');

        $assets->addAsset(
            new Js(
                '/js/script3.js',
                false
            )
        );

        $expected = '<script src="/js/script1.js"></script>' . PHP_EOL .
            '<script src="/js/script2.js"></script>' . PHP_EOL .
            '<script src="/js/script3.js"></script>' . PHP_EOL;

        ob_start();
        $assets->outputJs();
        $actual = ob_get_clean();

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Assets\Manager :: outputJs - custom tag component
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-13
     */
    public function assetsManagerOutputJsCustomTag(UnitTester $I)
    {
        $I->wantToTest('Asset/Manager - outputJs() - custom tag component');

        $di = $this->getDi();

        $di->setShared(
            'tag',
            CustomTag::class
        );

        $assets = new Manager();

        $assets->setDI($di);

        $assets->addJs('js/script1.js');
        $assets->addJs('/js/script2.js');

        $assets->addAsset(
            new Js('/js/script3.js')
        );

        $expected = '<script src="js/script1.js" type="application/javascript"></script>' . PHP_EOL
            . '<script src="/js/script2.js" type="application/javascript"></script>' . PHP_EOL
            . '<script src="/js/script3.js" type="application/javascript"></script>' . PHP_EOL;

        ob_start();
        $assets->outputJs();
        $actual = ob_get_clean();

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Assets\Manager :: outputJs - basic
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-13
     */
    public function assetsManagerOutputJsBasic(UnitTester $I)
    {
        $I->wantToTest('Asset/Manager - outputJs() - basic');
        $assets = new Manager();

        $assets->useImplicitOutput(false);

        $assets->collection('js')
               ->addJs(dataDir('assets/assets/jquery.js'), false, false)
               ->setTargetPath(outputDir('tests/assets/combined.js'))
               ->setTargetUri('production/combined.js')
        ;

        $expected = sprintf(
            '<script src="%s"></script>%s',
            dataDir('assets/assets/jquery.js'),
            PHP_EOL
        );

        $I->assertEquals(
            $expected,
            $assets->outputJs('js')
        );
    }

    /**
     * Tests Phalcon\Assets\Manager :: outputJs - enabled join
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-13
     */
    public function assetsManagerOutputJsEnabledJoin(UnitTester $I)
    {
        $I->wantToTest('Asset/Manager - outputJs() - enabled join');
        /**
         * Tests output with enabled join
         *
         * @author Phalcon Team <team@phalcon.io>
         * @since  2016-01-24
         */
        $assets = new Manager();

        $assets->useImplicitOutput(false);

        $assets->collection('js')
               ->addJs(dataDir('assets/assets/jquery.js'), false, false)
               ->setTargetPath(outputDir('tests/assets/combined.js'))
               ->setTargetUri('production/combined.js')
               ->join(true)
        ;

        $expected = sprintf(
            '<script src="%s"></script>%s',
            dataDir('assets/assets/jquery.js'),
            PHP_EOL
        );

        $I->assertEquals(
            $expected,
            $assets->outputJs('js')
        );
    }

    /**
     * Tests Phalcon\Assets\Manager :: outputJs - disabled join
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-13
     */
    public function assetsManagerOutputJsDisabledJoin(UnitTester $I)
    {
        $I->wantToTest('Asset/Manager - outputJs() - disabled join');

        $assets = new Manager();

        $assets->useImplicitOutput(false);

        $assets->collection('js')
               ->addJs(dataDir('assets/assets/jquery.js'), false, false)
               ->setTargetPath(outputDir('assets/combined.js'))
               ->setTargetUri('production/combined.js')
               ->join(false)
        ;

        $expected = sprintf(
            '<script src="%s"></script>%s',
            dataDir('assets/assets/jquery.js'),
            PHP_EOL
        );

        $I->assertEquals(
            $expected,
            $assets->outputJs('js')
        );
    }

    /**
     * Tests Phalcon\Assets\Manager :: outputJs - join and filter
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-13
     */
    public function assetsManagerOutputJsJoinAndFilter(UnitTester $I)
    {
        $I->wantToTest('Asset/Manager - outputJs() - join and filter');

        $assets = new Manager();

        $jsFile = dataDir('assets/assets/jquery.js');

        $assets->useImplicitOutput(false);

        $assets->collection('js')
               ->addJs($jsFile, false, false)
               ->setTargetPath(outputDir('assets/combined.js'))
               ->setTargetUri('production/combined.js')
               ->join(false)
               ->addFilter(new None())
        ;

        $expected = sprintf(
            '<script src="%s"></script>%s',
            dataDir('assets/assets/jquery.js'),
            PHP_EOL
        );

        $I->assertEquals(
            $expected,
            $assets->outputJs('js')
        );
    }

    /**
     * Tests Phalcon\Assets\Manager :: outputJs - mixed resources
     *
     * @author Paul Scarrone <paul@savvysoftworks.com>
     * @since  2017-06-20
     */
    public function assetsManagerOutputJsMixedResources(UnitTester $I)
    {
        $I->wantToTest('Asset/Manager - outputJs() - mixed resources');

        $assets = new Manager();

        $assets
            ->collection('header')
            ->setPrefix('http:://cdn.example.com/')
            ->setLocal(false)
            ->addJs('js/script1.js')
            ->addJs('js/script2.js')
            ->addCss('css/styles1.css')
            ->addCss('css/styles2.css')
        ;

        $assets->useImplicitOutput(false);


        $expectedJS = sprintf(
            "%s" . PHP_EOL . "%s" . PHP_EOL,
            '<script src="http:://cdn.example.com/js/script1.js"></script>',
            '<script src="http:://cdn.example.com/js/script2.js"></script>'
        );

        $I->assertEquals(
            $expectedJS,
            $assets->outputJs('header')
        );


        $expectedCSS = sprintf(
            "%s" . PHP_EOL . "%s" . PHP_EOL,
            '<link rel="stylesheet" type="text/css" href="http:://cdn.example.com/css/styles1.css" />',
            '<link rel="stylesheet" type="text/css" href="http:://cdn.example.com/css/styles2.css" />'
        );

        $I->assertEquals(
            $expectedCSS,
            $assets->outputCss('header')
        );
    }

    /**
     * Tests Phalcon\Assets\Manager :: outputJs - target local
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/1532
     * @author Phalcon Team <team@phalcon.io>
     * @author Dreamszhu <dreamsxin@qq.com>
     * @since  2013-10-25
     */
    public function assetsManagerOutputJsTargetLocal(UnitTester $I)
    {
        $I->wantToTest('Asset/Manager - outputJs() - target local');

        $file = uniqid() . '.js';

        $assets = new Manager();

        $jsFile = dataDir('assets/assets/jquery.js');

        $assets->useImplicitOutput(false);

        $assets->collection('js')
               ->addJs($jsFile)
               ->join(true)
               ->addFilter(new Jsmin())
               ->setTargetPath(outputDir("tests/assets/{$file}"))
               ->setTargetLocal(false)
               ->setPrefix('//phalcon.io/')
               ->setTargetUri('js/jquery.js')
        ;

        $I->assertEquals(
            '<script src="//phalcon.io/js/jquery.js"></script>' . PHP_EOL,
            $assets->outputJs('js')
        );

        $I->seeFileFound(
            outputDir("tests/assets/{$file}")
        );

        $I->safeDeleteFile(
            outputDir("tests/assets/{$file}")
        );
    }
}
