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

namespace Phalcon\Test\Unit\Assets;

use Phalcon\Assets\Filters\Jsmin;
use Phalcon\Assets\Filters\None;
use Phalcon\Assets\Manager;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use UnitTester;
use function dataFolder;
use function uniqid;

class ManagerCest
{
    use DiTrait;

    /**
     * executed before each test
     */
    public function _before(UnitTester $I)
    {
//        $this->newDi();
//        $this->setDiEscaper();
//        $this->setDiUrl();
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

        foreach ($collectionCss as $resource) {
            $actual = $resource->getType();

            $I->assertEquals('css', $actual);

            $CSSnumber++;
        }

        $I->assertEquals(
            2,
            $CSSnumber
        );



        $JSnumber = 0;

        foreach ($collectionJs as $resource) {
            $actual = $resource->getType();

            $I->assertEquals('js', $actual);

            $JSnumber++;
        }

        $I->assertEquals(
            2,
            $JSnumber
        );
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

        $I->assertEquals(
            $expected,
            $assets->outputCss('footer')
        );
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

        $expected = sprintf(
            "%s\n%s\n",
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
            "%s\n%s\n",
            '<script src="http:://cdn.example.com/js/script1.js"></script>',
            '<script src="http:://cdn.example.com/js/script2.js"></script>'
        );

        $I->assertEquals(
            $expectedJS,
            $assets->outputJs('header')
        );



        $expectedCSS = sprintf(
            "%s\n%s\n",
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
     * @author Phalcon Team <team@phalconphp.com>
     * @author Dreamszhu <dreamsxin@qq.com>
     * @since  2013-10-25
     */
    public function testTargetLocal(UnitTester $I)
    {
        $file = uniqid() . '.js';

        $assets = new Manager();

        $jsFile = dataFolder('assets/assets/jquery.js');

        $assets->useImplicitOutput(false);

        $assets->collection('js')
               ->addJs($jsFile)
               ->join(true)
               ->addFilter(new Jsmin())
               ->setTargetPath(outputFolder("tests/assets/{$file}"))
               ->setTargetLocal(false)
               ->setPrefix('//phalconphp.com/')
               ->setTargetUri('js/jquery.js')
        ;

        $I->assertEquals(
            '<script src="//phalconphp.com/js/jquery.js"></script>' . PHP_EOL,
            $assets->outputJs('js')
        );

        $I->seeFileFound(
            outputFolder("tests/assets/{$file}")
        );

        $I->safeDeleteFile(
            outputFolder("tests/assets/{$file}")
        );
    }

    /**
     * Tests basic output
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-01-24
     */
    public function testBasicOutput(UnitTester $I)
    {
        $assets = new Manager();

        $assets->useImplicitOutput(false);

        $assets->collection('js')
               ->addJs(dataFolder('assets/assets/jquery.js'), false, false)
               ->setTargetPath(outputFolder("tests/assets/combined.js"))
               ->setTargetUri('production/combined.js')
        ;

        $expected = sprintf(
            '<script src="%s"></script>%s',
            dataFolder('assets/assets/jquery.js'),
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
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-01-24
     */
    public function testOutputWithEnabledJoin(UnitTester $I)
    {
        $assets = new Manager();

        $assets->useImplicitOutput(false);

        $assets->collection('js')
               ->addJs(dataFolder('assets/assets/jquery.js'), false, false)
               ->setTargetPath(outputFolder("tests/assets/combined.js"))
               ->setTargetUri('production/combined.js')
               ->join(true)
        ;

        $expected = sprintf(
            '<script src="%s"></script>%s',
            dataFolder('assets/assets/jquery.js'),
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
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-01-24
     */
    public function testOutputWithDisabledJoin(UnitTester $I)
    {
        $assets = new Manager();

        $assets->useImplicitOutput(false);

        $assets->collection('js')
               ->addJs(dataFolder('assets/assets/jquery.js'), false, false)
               ->setTargetPath(outputFolder("assets/combined.js"))
               ->setTargetUri('production/combined.js')
               ->join(false)
        ;

        $expected = sprintf(
            '<script src="%s"></script>%s',
            dataFolder('assets/assets/jquery.js'),
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
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-01-24
     */
    public function testOutputWithJoinAndFilter(UnitTester $I)
    {
        $assets = new Manager();

        $jsFile = dataFolder('assets/assets/jquery.js');

        $assets->useImplicitOutput(false);

        $assets->collection('js')
               ->addJs($jsFile, false, false)
               ->setTargetPath(outputFolder("assets/combined.js"))
               ->setTargetUri('production/combined.js')
               ->join(false)
               ->addFilter(new None())
        ;

        $expected = sprintf(
            '<script src="%s"></script>%s',
            dataFolder('assets/assets/jquery.js'),
            PHP_EOL
        );

        $I->assertEquals(
            $expected,
            $assets->outputJs('js')
        );
    }

    /**
     * @issue https://github.com/phalcon/cphalcon/issues/11409
     * @param UnitTester $I
     */
    public function addInlineJs(UnitTester $I)
    {
        $manager = new Manager();
        $jsFile  = dataFolder('assets/assets/signup.js');
        $js      = file_get_contents($jsFile);

        $manager->addInlineJs($js);

        ob_start();
        $manager->outputInlineJs();
        $actual = ob_get_contents();
        ob_end_clean();

        $I->assertEquals(
            "<script type=\"text/javascript\">{$js}</script>\n",
            $actual
        );
    }
}
