<?php
/**
 * AssetsManagerTest.php
 * \Phalcon\Resource\AssetsManagerTest
 *
 * Tests the Phalcon\Assets\Manager component
 *
 * PhalconPHP Framework
 *
 * @copyright (c) 2011-2014 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

namespace Phalcon\Tests\unit\Phalcon\Assets;

use \Phalcon\Assets\Resource as PhAssetsResource;

use \Phalcon\Assets\Resource\Css as PhAssetsResourceCss;
use \Phalcon\Assets\Resource\Js as PhAssetsResourceJs;

use \PhalconTest\Assets\Manager as PhTAssetsManager;
use \PhalconTest\Assets\Resource as PhTAssetsResource;

use \Phalcon\Tests\unit\Phalcon\_Helper\TestsBase as TBase;

class AssetsManagerTest extends TBase
{
    /**
     * addCss tests
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-13
     */
    public function testAssetsManagerAddingCss()
    {
        $this->specify(
            "The addCss on assets manager does add resources correctly",
            function () {

                $assets = new PhTAssetsManager();

                $assets->addCss('/css/style1.css');
                $assets->addCss('/css/style2.css');

                $collection = $assets->get('css');

                $number = 0;
                foreach ($collection as $resource) {
                    $this->assertEquals($resource->getType(), 'css');
                    $number++;
                }

                expect($number)->equals(2);
            }
        );
    }

    /**
     * addJs tests
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-13
     */
    public function testAssetsManagerAddingJs()
    {
        $this->specify(
            "The addJs on assets manager does add resources correctly",
            function () {

                $assets = new PhTAssetsManager();

                $assets->addJs('/js/script1.js');
                $assets->addJs('/js/script2.js');

                $collection = $assets->get('js');

                $number = 0;
                foreach ($collection as $resource) {
                    $this->assertEquals($resource->getType(), 'js');
                    $number++;
                }

                expect($number)->equals(2);
            }
        );
    }

    /**
     * addResource tests
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-13
     */
    public function testAssetsManagerAddingCssWithAddResource()
    {
        $this->specify(
            "The addResource on assets manager does add resources correctly",
            function () {

                $assets = new PhTAssetsManager();

                $assets->addCss('/css/style1.css');
                $assets->addCss('/css/style2.css');

                $assets->addResource(new PhAssetsResourceCss('/css/style.css', false));

                $actual = count($assets->get('css'));

                expect($actual)->equals(3);
            }
        );
    }

    /**
     * outputCss tests
     */
    public function testAssetsManagerOutputCssWithoutJoin()
    {
        $this->specify(
            "The output of css collection fails if join is false",
            function () {

                $this->prepareDI();

                $assets = new PhTAssetsManager();
                $assets->useImplicitOutput(false);
                $css = $assets->collection('css');

                $css->addCss(PATH_DATA . 'assets/1198.css');
                $css->join(false);
                $output = trim($assets->outputCss());

                $expected = 'assets/1198.css';

                $this->assertContains(
                    $expected,
                    $output
                );
            }
        );
    }

    /**
     * outputCss - implicitOutput tests
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-13
     */
    public function testAssetsManagerOutputCssWithImplicitOutput()
    {
        $this->markTestSkipped('To be tested');
        $this->specify(
            "The outputCss with implicitOutput does not produce the correct result",
            function () {

                $this->prepareDI();

                $assets = new PhTAssetsManager();

                $assets->addCss('css/style1.css');
                $assets->addCss('css/style2.css');

                $assets->addResource(new PhAssetsResourceCss('/css/style.css', false));

                ob_start();
                $assets->outputCss();
                $actual   = ob_get_clean();
                $expected = '<link rel="stylesheet" type="text/css" href="/css/style1.css" />'
                          . PHP_EOL
                          . '<link rel="stylesheet" type="text/css" href="/css/style2.css" />'
                          . PHP_EOL
                          . '<link rel="stylesheet" type="text/css" href="/css/style.css" />'
                          . PHP_EOL;

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * outputJs - implicitOutput tests
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-13
     */
    public function testAssetsManagerOutputJsWithImplicitOutput()
    {
        $this->markTestSkipped('To be tested');
        $this->specify(
            "The outputJs with implicitOutput does not produce the correct result",
            function () {

                $this->prepareDI();

                $assets = new PhTAssetsManager();

                $assets->addJs('js/script1.js');
                $assets->addJs('js/script2.js');

                $assets->addResource(new PhAssetsResourceJs('/js/script3.js', false));

                ob_start();
                $assets->outputJs();
                $actual   = ob_get_clean();
                $expected = '<script type="text/javascript" src="/js/script1.js"></script>'
                          . PHP_EOL
                          . '<script type="text/javascript" src="/js/script2.js"></script>'
                          . PHP_EOL
                          . '<script type="text/javascript" src="/js/script3.js"></script>'
                          . PHP_EOL;

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * outputCss - without implicitOutput tests
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-13
     */
    public function testAssetsManagerOutputCssWithoutImplicitOutput()
    {
        $this->markTestSkipped('To be tested');
        $this->specify(
            "The outputCss with implicitOutput does not produce the correct result",
            function () {

                $this->prepareDI();

                $assets = new PhTAssetsManager();

                $assets->addCss('css/style1.css');
                $assets->addCss('css/style2.css');

                $assets->addResource(new PhAssetsResourceCss('/css/style.css', false));

                $assets->useImplicitOutput(false);
                $actual   = $assets->outputCss();
                $expected = '<link rel="stylesheet" type="text/css" href="/css/style1.css" />'
                          . PHP_EOL
                          . '<link rel="stylesheet" type="text/css" href="/css/style2.css" />'
                          . PHP_EOL
                          . '<link rel="stylesheet" type="text/css" href="/css/style.css" />'
                          . PHP_EOL;

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * outputJs - without implicitOutput tests
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-13
     */
    public function testAssetsManagerOutputJsWithoutImplicitOutput()
    {
        $this->markTestSkipped('To be tested');
        $this->specify(
            "The outputJs with implicitOutput does not produce the correct result",
            function () {

                $this->prepareDI();

                $assets = new PhTAssetsManager();

                $assets->addJs('js/script1.js');
                $assets->addJs('js/script2.js');

                $assets->addResource(new PhAssetsResourceJs('/js/script3.js', false));

                $assets->useImplicitOutput(false);
                $actual   = $assets->outputJs();
                $expected = '<script type="text/javascript" src="/js/script1.js"></script>'
                          . PHP_EOL
                          . '<script type="text/javascript" src="/js/script2.js"></script>'
                          . PHP_EOL
                          . '<script type="text/javascript" src="/js/script3.js"></script>'
                          . PHP_EOL;

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * collection tests
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-13
     */
    public function testAssetsManagerOutputCssWithoutImplicitOutputFromCollection()
    {
        $this->markTestSkipped('To be tested');
        $this->specify(
            "The outputCss using a collection does not produce the correct result",
            function () {

                $this->prepareDI();

                $assets = new PhTAssetsManager();

                $assets->collection('footer')
                       ->addCss('css/style1.css');

                $footer = $assets->collection('footer');
                $footer->addCss('css/style2.css');

                $assets->useImplicitOutput(false);
                $actual   = $assets->outputCss('footer');
                $expected = '<link rel="stylesheet" type="text/css" href="/css/style1.css" />'
                          . PHP_EOL
                          . '<link rel="stylesheet" type="text/css" href="/css/style2.css" />'
                          . PHP_EOL;

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * collection tests
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-13
     */
    public function testAssetsManagerOutputJsWithoutImplicitOutputFromCollectionRemote()
    {
        $this->markTestSkipped('To be tested');
        $this->specify(
            "The outputJs using a collection does not produce the correct result",
            function () {

                $this->prepareDI();

                $assets = new PhTAssetsManager();

                $assets->collection('header')
                       ->setPrefix('http:://cdn.example.com/')
                       ->setLocal(false)
                       ->addJs('js/script1.js')
                       ->addJs('js/script2.js');

                $assets->useImplicitOutput(false);
                $actual   = $assets->outputJs('header');
                $expected = '<script type="text/javascript" src="http:://cdn.example.com/js/script1.js"></script>'
                          . PHP_EOL
                          . '<script type="text/javascript" src="http:://cdn.example.com/js/script2.js"></script>'
                          . PHP_EOL;

                expect($actual)->equals($expected);
            }
        );
    }
}