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

namespace Phalcon\Test\Unit\Assets;

use Phalcon\Assets\Filters\Jsmin;
use Phalcon\Assets\Filters\None;
use Phalcon\Assets\Manager;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use UnitTester;

use function dataDir;
use function uniqid;

class ManagerCest
{
    use DiTrait;

    /**
     * executed before each test
     */
    public function _before(UnitTester $I)
    {
        $this->newDi();
        $this->setDiService('escaper');
        $this->setDiService('url');
    }

    /**
     * executed after each test
     */
    public function _after(UnitTester $I)
    {
        $this->resetDi();
//        // Setting the doctype to XHTML5 for other tests to run smoothly
//        Tag::setDocType(Tag::XHTML5);
    }


    /**
     * collection tests
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-13
     */
    public function testAssetsManagerOutputCssWithoutImplicitOutputFromCollection(UnitTester $I)
    {
        $assets = new Manager();

        $assets->collection('footer')->addCss('css/style1.css');

        $footer = $assets->collection('footer');

        $footer->addCss('css/style2.css');

        $expected = sprintf(
            "%s" . PHP_EOL . "%s" . PHP_EOL,
            '<link rel="stylesheet" type="text/css" href="/css/style1.css" />',
            '<link rel="stylesheet" type="text/css" href="/css/style2.css" />'
        );

        $assets->useImplicitOutput(false);

        $I->assertEquals(
            $expected,
            $assets->outputCss('footer')
        );
    }

    /**
     * collection tests
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-13
     */
    public function testAssetsManagerOutputJsWithoutImplicitOutputFromCollectionRemote(UnitTester $I)
    {
        $assets = new Manager();

        $assets
            ->collection('header')
            ->setPrefix('http:://cdn.example.com/')
            ->setLocal(false)
            ->addJs('js/script1.js')
            ->addJs('js/script2.js')
        ;

        $assets->useImplicitOutput(false);

        $expected = sprintf(
            "%s" . PHP_EOL . "%s" . PHP_EOL,
            '<script src="http:://cdn.example.com/js/script1.js"></script>',
            '<script src="http:://cdn.example.com/js/script2.js"></script>'
        );

        $I->assertEquals(
            $expected,
            $assets->outputJs('header')
        );
    }

    /**
     * Tests collection with mixed resources
     *
     * @author Paul Scarrone <paul@savvysoftworks.com>
     * @since  2017-06-20
     */
    public function testAssetsManagerOutputJsWithMixedAssetCollection(UnitTester $I)
    {
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
     * Tests setting local target
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/1532
     * @author Phalcon Team <team@phalcon.io>
     * @author Dreamszhu <dreamsxin@qq.com>
     * @since  2013-10-25
     */
    public function testTargetLocal(UnitTester $I)
    {
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

    /**
     * Tests basic output
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2016-01-24
     */
    public function testBasicOutput(UnitTester $I)
    {
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
     * Tests output with enabled join
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2016-01-24
     */
    public function testOutputWithEnabledJoin(UnitTester $I)
    {
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
     * Tests output with disabled join
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2016-01-24
     */
    public function testOutputWithDisabledJoin(UnitTester $I)
    {
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
     * Tests output with disabled join
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2016-01-24
     */
    public function testOutputWithJoinAndFilter(UnitTester $I)
    {
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
}
