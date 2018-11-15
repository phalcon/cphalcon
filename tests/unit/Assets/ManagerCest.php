<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Assets;

use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Assets\Exception;
use Phalcon\Assets\Filters\Jsmin;
use Phalcon\Assets\Filters\None;
use Phalcon\Assets\Manager;
use Phalcon\Assets\Resource\Css;
use Phalcon\Assets\Resource\Js;
use Phalcon\Tag;
use UnitTester;

class ManagerCest
{
    use DiTrait;

    /**
     * executed before each test
     */
    public function _before(UnitTester $I, $scenario)
    {
        @mkdir(PATH_OUTPUT . 'assets/', 0777, true);
        $this->resetDi();
        $this->newDi();
        $this->setDiEscaper();
        $this->setDiUrl();
    }

    /**
     * executed after each test
     */
    public function _after(UnitTester $I)
    {
        // Setting the doctype to XHTML5 for other tests to run smoothly
        Tag::setDocType(Tag::XHTML5);
    }

    /**
     * Test Manager::get
     *
     * @test
     * @author                   Serghei Iakovlev <serghei@phalconphp.com>
     * @since                    2017-06-04
     *
     * @expectedException        \Phalcon\Assets\Exception
     * @expectedExceptionMessage The collection does not exist in the manager
     */
    public function assetsManagerShouldThrowExceptionIfThereIsNoCollection(UnitTester $I)
    {
        $I->expectThrowable(
            new Exception('The collection does not exist in the manager'),
            function () {
                $assets = new Manager();
                $assets->get('some-non-existent-collection');
            }
        );
    }

    /**
     * Test Manager::exists
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-03-16
     */
    public function assetsManagerShouldDetectAbsenceOfACollection(UnitTester $I)
    {
        $assets = new Manager();
        $actual = $assets->exists('some-non-existent-collection');
        $I->assertFalse($actual);
    }

    /**
     * Test Manager::exists
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-03-16
     */
    public function assetsManagerShouldDetectCollection(UnitTester $I)
    {
        $assets = new Manager();

        $assets->addCss('/css/style1.css');
        $assets->addCss('/css/style2.css');

        $actual = $assets->exists('css');
        $I->assertTrue($actual);
    }

    /**
     * Tests addCss
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-13
     */
    public function testAssetsManagerAddingCss(UnitTester $I)
    {
        $assets = new Manager();

        $assets->addCss('/css/style1.css');
        $assets->addCss('/css/style2.css');

        $collection = $assets->get('css');

        $number   = 0;
        $expected = 'css';
        foreach ($collection as $resource) {
            $actual = $resource->getType();
            $I->assertEquals($expected, $actual);
            $number++;
        }

        $expected = 2;
        $actual   = $number;
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests addCss and addJs
     *
     * @author Paul Scarrone <paul@savvysoftworks.com>
     * @since  2017-06-20
     */
    public function testAssetsManagerAddingCssAndJs(UnitTester $I)
    {
        $assets = new Manager();

        $assets->addCss('/css/style1.css');
        $assets->addCss('/css/style2.css');
        $assets->addJs('/js/script1.js');
        $assets->addJs('/js/script2.js');

        $collectionCss = $assets->get('css');
        $collectionJs  = $assets->get('js');

        $CSSnumber = 0;
        $expected  = 'css';
        foreach ($collectionCss as $resource) {
            $actual = $resource->getType();
            $I->assertEquals($expected, $actual);
            $CSSnumber++;
        }

        $expected = 2;
        $actual   = $CSSnumber;
        $I->assertEquals($expected, $actual);

        $JSnumber = 0;
        $expected = 'js';
        foreach ($collectionJs as $resource) {
            $actual = $resource->getType();
            $I->assertEquals($expected, $actual);
            $JSnumber++;
        }

        $expected = 2;
        $actual   = $JSnumber;
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests addJs
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-13
     */
    public function testAssetsManagerAddingJs(UnitTester $I)
    {
        $assets = new Manager();

        $assets->addJs('/js/script1.js');
        $assets->addJs('/js/script2.js');

        $collection = $assets->get('js');

        $number   = 0;
        $expected = 'js';
        foreach ($collection as $resource) {
            $actual = $resource->getType();
            $I->assertEquals($expected, $actual);
            $number++;
        }

        $expected = 2;
        $actual   = $number;
        $I->assertEquals($expected, $actual);
    }

    /**
     * addResource tests
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-13
     */
    public function testAssetsManagerAddingCssWithAddResource(UnitTester $I)
    {
        $assets = new Manager();

        $assets->addCss('/css/style1.css');
        $assets->addCss('/css/style2.css');
        $assets->addResource(new Css('/css/style.css', false));

        $expected = 3;
        $actual   = count($assets->get('css'));
        $I->assertEquals($expected, $actual);
    }

    /**
     * outputCss - implicitOutput tests
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-13
     */
    public function testAssetsManagerOutputCssWithImplicitOutput(UnitTester $I)
    {
        $assets = new Manager();

        $assets->addCss('css/style1.css');
        $assets->addCss('css/style2.css');
        $assets->addResource(new Css('/css/style.css', false));

        $expected = sprintf(
            "%s\n%s\n%s\n",
            '<link rel="stylesheet" type="text/css" href="/css/style1.css" />',
            '<link rel="stylesheet" type="text/css" href="/css/style2.css" />',
            '<link rel="stylesheet" type="text/css" href="/css/style.css" />'
        );

        ob_start();
        $assets->outputCss();
        $actual = ob_get_clean();
        $I->assertEquals($expected, $actual);
    }

    /**
     * outputJs - implicitOutput tests
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-13
     */
    public function testAssetsManagerOutputJsWithImplicitOutput(UnitTester $I)
    {
        $assets = new Manager();

        $assets->addJs('js/script1.js');
        $assets->addJs('js/script2.js');
        $assets->addResource(new Js('/js/script3.js', false));

        $expected = sprintf(
            "%s\n%s\n%s\n",
            '<script type="text/javascript" src="/js/script1.js"></script>',
            '<script type="text/javascript" src="/js/script2.js"></script>',
            '<script type="text/javascript" src="/js/script3.js"></script>'
        );

        ob_start();
        $assets->outputJs();
        $actual = ob_get_clean();
        $I->assertEquals($expected, $actual);
    }

    /**
     * outputCss - without implicitOutput tests
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-13
     */
    public function testAssetsManagerOutputCssWithoutImplicitOutput(UnitTester $I)
    {
        $assets = new Manager();

        $assets->addCss('css/style1.css');
        $assets->addCss('css/style2.css');
        $assets->addResource(new Css('/css/style.css', false));

        $expected = sprintf(
            "%s\n%s\n%s\n",
            '<link rel="stylesheet" type="text/css" href="/css/style1.css" />',
            '<link rel="stylesheet" type="text/css" href="/css/style2.css" />',
            '<link rel="stylesheet" type="text/css" href="/css/style.css" />'
        );

        $assets->useImplicitOutput(false);
        $actual = $assets->outputCss();
        $I->assertEquals($expected, $actual);
    }

    /**
     * outputJs - without implicitOutput tests
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-13
     */
    public function testAssetsManagerOutputJsWithoutImplicitOutput(UnitTester $I)
    {
        $assets = new Manager();

        $assets->addJs('js/script1.js');
        $assets->addJs('js/script2.js');
        $assets->addResource(new Js('/js/script3.js', false));

        $expected = sprintf(
            "%s\n%s\n%s\n",
            '<script type="text/javascript" src="/js/script1.js"></script>',
            '<script type="text/javascript" src="/js/script2.js"></script>',
            '<script type="text/javascript" src="/js/script3.js"></script>'
        );

        $assets->useImplicitOutput(false);
        $actual = $assets->outputJs();
        $I->assertEquals($expected, $actual);
    }

    /**
     * collection tests
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-13
     */
    public function testAssetsManagerOutputCssWithoutImplicitOutputFromCollection(UnitTester $I)
    {
        $assets = new Manager();
        $assets->collection('footer')->addCss('css/style1.css');

        $footer = $assets->collection('footer');
        $footer->addCss('css/style2.css');

        $expected = sprintf(
            "%s\n%s\n",
            '<link rel="stylesheet" type="text/css" href="/css/style1.css" />',
            '<link rel="stylesheet" type="text/css" href="/css/style2.css" />'
        );

        $assets->useImplicitOutput(false);
        $actual = $assets->outputCss('footer');
        $I->assertEquals($expected, $actual);
    }

    /**
     * collection tests
     *
     * @author Phalcon Team <team@phalconphp.com>
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
        $actual = $assets->outputJs('header');

        $expected = sprintf(
            "%s\n%s\n",
            '<script type="text/javascript" src="http:://cdn.example.com/js/script1.js"></script>',
            '<script type="text/javascript" src="http:://cdn.example.com/js/script2.js"></script>'
        );
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests collection with mixed resources
     *
     * @author Paul Scarrone <paul@savvysoftworks.com>
     * @since  2017-06-20
     */
    public function testAssetsManagerOutputJsWithMixedResourceCollection(UnitTester $I)
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

        $actualJS   = $assets->outputJs('header');
        $expectedJS = sprintf(
            "%s\n%s\n",
            '<script type="text/javascript" src="http:://cdn.example.com/js/script1.js"></script>',
            '<script type="text/javascript" src="http:://cdn.example.com/js/script2.js"></script>'
        );
        $I->assertEquals($expectedJS, $actualJS);

        $actualCSS   = $assets->outputCss('header');
        $expectedCSS = sprintf(
            "%s\n%s\n",
            '<link rel="stylesheet" type="text/css" href="http:://cdn.example.com/css/styles1.css" />',
            '<link rel="stylesheet" type="text/css" href="http:://cdn.example.com/css/styles2.css" />'
        );
        $I->assertEquals($expectedCSS, $actualCSS);
    }

    /**
     * Tests setting local target
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/1532
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @author Dreamszhu <dreamsxin@qq.com>
     * @since  2013-10-25
     */
    public function testTargetLocal(UnitTester $I)
    {
        $file   = md5(microtime(true)) . '.js';
        $assets = new Manager();

        $assets->useImplicitOutput(false);
        $assets->collection('js')
               ->addJs(PATH_DATA . 'assets/assets/jquery.js')
               ->join(true)
               ->addFilter(new Jsmin())
               ->setTargetPath(PATH_OUTPUT . "tests/assets/{$file}")
               ->setTargetLocal(false)
               ->setPrefix('//phalconphp.com/')
               ->setTargetUri('js/jquery.js')
        ;

        $expected = '<script type="text/javascript" src="//phalconphp.com/js/jquery.js"></script>' . PHP_EOL;
        $actual   = $assets->outputJs('js');
        $I->assertEquals($expected, $actual);

        $I->seeFileFound(PATH_OUTPUT . "tests/assets/{$file}");
        $I->deleteFile(PATH_OUTPUT . "tests/assets/{$file}");
    }

    /**
     * Tests basic output
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-01-24
     */
    public function testBasicOutput(UnitTester $I)
    {
        $assets = new Manager();

        $assets->useImplicitOutput(false);
        $assets->collection('js')
               ->addJs(PATH_DATA . 'assets/assets/jquery.js', false, false)
               ->setTargetPath(PATH_OUTPUT . "tests/assets/combined.js")
               ->setTargetUri('production/combined.js')
        ;

        $expected = sprintf(
            '<script type="text/javascript" src="%s"></script>%s',
            PATH_DATA . 'assets/assets/jquery.js',
            PHP_EOL
        );
        $actual   = $assets->outputJs('js');
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests output with enabled join
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-01-24
     */
    public function testOutputWithEnabledJoin(UnitTester $I)
    {
        $assets = new Manager();

        $assets->useImplicitOutput(false);
        $assets->collection('js')
               ->addJs(PATH_DATA . 'assets/assets/jquery.js', false, false)
               ->setTargetPath(PATH_OUTPUT . "tests/assets/combined.js")
               ->setTargetUri('production/combined.js')
               ->join(true)
        ;

        $expected = sprintf(
            '<script type="text/javascript" src="%s"></script>%s',
            PATH_DATA . 'assets/assets/jquery.js',
            PHP_EOL
        );
        $actual   = $assets->outputJs('js');
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests output with disabled join
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-01-24
     */
    public function testOutputWithDisabledJoin(UnitTester $I)
    {
        $assets = new Manager();

        $assets->useImplicitOutput(false);
        $assets->collection('js')
               ->addJs(PATH_DATA . 'assets/assets/jquery.js', false, false)
               ->setTargetPath(PATH_OUTPUT . "assets/combined.js")
               ->setTargetUri('production/combined.js')
               ->join(false)
        ;

        $expected = sprintf(
            '<script type="text/javascript" src="%s"></script>%s',
            PATH_DATA . 'assets/assets/jquery.js',
            PHP_EOL
        );
        $actual   = $assets->outputJs('js');
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests output with disabled join
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-01-24
     */
    public function testOutputWithJoinAndFilter(UnitTester $I)
    {
        $assets = new Manager();

        $assets->useImplicitOutput(false);
        $assets->collection('js')
               ->addJs(PATH_DATA . 'assets/assets/jquery.js', false, false)
               ->setTargetPath(PATH_OUTPUT . "assets/combined.js")
               ->setTargetUri('production/combined.js')
               ->join(false)
               ->addFilter(new None())
        ;

        $expected = sprintf(
            '<script type="text/javascript" src="%s"></script>%s',
            PATH_DATA . 'assets/assets/jquery.js',
            PHP_EOL
        );
        $actual   = $assets->outputJs('js');
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests avoid duplication of resources when adding a
     * new one with existing name
     *
     * @test
     * @issue  https://github.com/phalcon/cphalcon/issues/10938
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2017-06-02
     */
    public function doNotAddTheSameRecources(UnitTester $I)
    {
        $assets = new Manager();

        for ($i = 0; $i < 10; $i++) {
            $assets
                ->addCss('css/style.css')
                ->addJs('script.js')
            ;
        }

        $expected = 1;
        $actual   = count($assets->getCss());
        $I->assertEquals($expected, $actual);
        $expected = 1;
        $actual   = count($assets->getJs());
        $I->assertEquals($expected, $actual);

        for ($i = 0; $i < 2; $i++) {
            $assets
                ->addCss('style_' . $i . '.css')
                ->addJs('script_' . $i . '.js')
            ;
        }

        $expected = 3;
        $actual   = count($assets->getCss());
        $I->assertEquals($expected, $actual);
        $expected = 3;
        $actual   = count($assets->getJs());
        $I->assertEquals($expected, $actual);
    }

    /**
     * @issue https://github.com/phalcon/cphalcon/issues/11409
     * @param UnitTester $I
     */
    public function addInlineJs(UnitTester $I)
    {
        $manager = new Manager();

        $js = file_get_contents(PATH_DATA . 'assets/assets/signup.js');
        $manager->addInlineJs($js);
        $expected = "<script type=\"text/javascript\">{$js}</script>\n";

        ob_start();
        $manager->outputInlineJs();
        $actual = ob_get_contents();
        ob_end_clean();

        $I->assertSame($expected, $actual);
    }
}
