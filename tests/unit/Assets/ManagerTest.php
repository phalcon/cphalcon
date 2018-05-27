<?php

namespace Phalcon\Test\Unit\Assets;

use Phalcon\Tag;
use Phalcon\Assets\Manager;
use Phalcon\Assets\Exception;
use Phalcon\Assets\Resource\Js;
use Phalcon\Assets\Resource\Css;
use Phalcon\Assets\Filters\None;
use Phalcon\Test\Module\UnitTest;
use Phalcon\Assets\Filters\Jsmin;

/**
 * \Phalcon\Test\Unit\Assets\ManagerTest
 * Tests the \Phalcon\Assets\Manager component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Unit\Assets
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class ManagerTest extends UnitTest
{
    /**
     * executed after each test
     */
    protected function _after()
    {
        // Setting the doctype to XHTML5 for other tests to run smoothly
        Tag::setDocType(Tag::XHTML5);
    }

    /**
     * Test Manager::get
     *
     * @test
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2017-06-04
     */
    public function assetsManagerShouldThrowExceptionIfThereIsNoCollection()
    {
        $this->specify(
            'The Assets Manager does not throw exception in case of absence of a collection',
            function () {
                $assets = new Manager();
                $assets->get('some-non-existent-collection');
            },
            [
                'throws' => [
                    Exception::class,
                    'The collection does not exist in the manager'
                ]
            ]
        );
    }

    /**
     * Test Manager::exists
     *
     * @test
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-03-16
     */
    public function assetsManagerShouldDetectAbsenceOfACollection()
    {
        $this->specify(
            'The Assets Manager does not return valid status case of absence of a collection',
            function () {
                $assets = new Manager();
                expect($assets->exists('some-non-existent-collection'))->false();
            }
        );
    }

    /**
     * Test Manager::exists
     *
     * @test
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-03-16
     */
    public function assetsManagerShouldDetectCollection()
    {
        $this->specify(
            'The Assets Manager does not return valid status case of presence of a collection',
            function () {
                $assets = new Manager();

                $assets->addCss('/css/style1.css');
                $assets->addCss('/css/style2.css');

                expect($assets->exists('css'))->true();
            }
        );
    }

    /**
     * Tests addCss
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-13
     */
    public function testAssetsManagerAddingCss()
    {
        $this->specify(
            "The addCss on assets manager does add resources correctly",
            function () {
                $assets = new Manager();

                $assets->addCss('/css/style1.css');
                $assets->addCss('/css/style2.css');

                $collection = $assets->get('css');

                $number = 0;
                foreach ($collection as $resource) {
                    expect('css')->equals($resource->getType());
                    $number++;
                }

                expect($number)->equals(2);
            }
        );
    }

    /**
     * Tests addCss and addJs
     *
     * @author Paul Scarrone <paul@savvysoftworks.com>
     * @since  2017-06-20
     */
    public function testAssetsManagerAddingCssAndJs()
    {
        $this->specify(
            "The combination of addCss and addJs on assets manager does add resources correctly",
            function () {
                $assets = new Manager();

                $assets->addCss('/css/style1.css');
                $assets->addCss('/css/style2.css');
                $assets->addJs('/js/script1.js');
                $assets->addJs('/js/script2.js');

                $collectionCss = $assets->get('css');
                $collectionJs = $assets->get('js');

                $CSSnumber = 0;
                foreach ($collectionCss as $resource) {
                    expect('css')->equals($resource->getType());
                    $CSSnumber++;
                }
                expect($CSSnumber)->equals(2);

                $JSnumber = 0;
                foreach ($collectionJs as $resource) {
                    expect('js')->equals($resource->getType());
                    $JSnumber++;
                }
                expect($JSnumber)->equals(2);
            }
        );
    }

    /**
     * Tests addJs
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-13
     */
    public function testAssetsManagerAddingJs()
    {
        $this->specify(
            "The addJs on assets manager does add resources correctly",
            function () {
                $assets = new Manager();

                $assets->addJs('/js/script1.js');
                $assets->addJs('/js/script2.js');

                $collection = $assets->get('js');

                $number = 0;
                foreach ($collection as $resource) {
                    expect('js')->equals($resource->getType());
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
                $assets = new Manager();

                $assets->addCss('/css/style1.css');
                $assets->addCss('/css/style2.css');
                $assets->addResource(new Css('/css/style.css', false));

                $actual = count($assets->get('css'));

                expect($actual)->equals(3);
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
        $this->specify(
            "The outputCss with implicitOutput does not produce the correct result",
            function () {
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

                expect(ob_get_clean())->equals($expected);
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
        $this->specify(
            "The outputJs with implicitOutput does not produce the correct result",
            function () {
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

                expect(ob_get_clean())->equals($expected);
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
        $this->specify(
            "The outputCss with implicitOutput does not produce the correct result",
            function () {
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

                expect($assets->outputCss())->equals($expected);
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
        $this->specify(
            "The outputJs with implicitOutput does not produce the correct result",
            function () {
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

                expect($assets->outputJs())->equals($expected);
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
        $this->specify(
            "The outputCss using a collection does not produce the correct result",
            function () {
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

                expect($assets->outputCss('footer'))->equals($expected);
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
        $this->specify(
            "The outputJs using a collection does not produce the correct result",
            function () {
                $assets = new Manager();

                $assets->collection('header')
                    ->setPrefix('http:://cdn.example.com/')
                    ->setLocal(false)
                    ->addJs('js/script1.js')
                    ->addJs('js/script2.js');

                $assets->useImplicitOutput(false);
                $actual = $assets->outputJs('header');

                $expected = sprintf(
                    "%s\n%s\n",
                    '<script type="text/javascript" src="http:://cdn.example.com/js/script1.js"></script>',
                    '<script type="text/javascript" src="http:://cdn.example.com/js/script2.js"></script>'
                );

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests collection with mixed resources
     *
     * @author Paul Scarrone <paul@savvysoftworks.com>
     * @since  2017-06-20
     */
    public function testAssetsManagerOutputJsWithMixedResourceCollection()
    {
        $this->specify(
            "The outputJs using a mixed resource collection returns only JS resources",
            function () {
                $assets = new Manager();

                $assets->collection('header')
                    ->setPrefix('http:://cdn.example.com/')
                    ->setLocal(false)
                    ->addJs('js/script1.js')
                    ->addJs('js/script2.js')
                    ->addCss('css/styles1.css')
                    ->addCss('css/styles2.css');
                $assets->useImplicitOutput(false);

                $actualJS = $assets->outputJs('header');
                $expectedJS = sprintf(
                    "%s\n%s\n",
                    '<script type="text/javascript" src="http:://cdn.example.com/js/script1.js"></script>',
                    '<script type="text/javascript" src="http:://cdn.example.com/js/script2.js"></script>'
                );
                expect($actualJS)->equals($expectedJS);

                $actualCSS = $assets->outputCss('header');
                $expectedCSS = sprintf(
                    "%s\n%s\n",
                    '<link rel="stylesheet" type="text/css" href="http:://cdn.example.com/css/styles1.css" />',
                    '<link rel="stylesheet" type="text/css" href="http:://cdn.example.com/css/styles2.css" />'
                );
                expect($actualCSS)->equals($expectedCSS);
            }
        );
    }


    /**
     * Tests setting local target
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/1532
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @author Dreamszhu <dreamsxin@qq.com>
     * @since  2013-10-25
     */
    public function testTargetLocal()
    {
        $this->specify(
            "Setting local target does not works correctly",
            function () {
                $I      = $this->tester;
                $file   = md5(microtime(true)) . '.js';
                $assets = new Manager();

                $assets->useImplicitOutput(false);
                $assets->collection('js')
                    ->addJs(PATH_DATA. 'assets/jquery.js')
                    ->join(true)
                    ->addFilter(new Jsmin())
                    ->setTargetPath(PATH_OUTPUT . "tests/assets/{$file}")
                    ->setTargetLocal(false)
                    ->setPrefix('//phalconphp.com/')
                    ->setTargetUri('js/jquery.js');

                expect($assets->outputJs('js'))->equals('<script type="text/javascript" src="//phalconphp.com/js/jquery.js"></script>' . PHP_EOL);

                $I->seeFileFound(PATH_OUTPUT . "tests/assets/{$file}");
                $I->deleteFile(PATH_OUTPUT . "tests/assets/{$file}");
            }
        );
    }

    /**
     * Tests basic output
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-01-24
     */
    public function testBasicOutput()
    {
        $this->specify(
            "The outputJs using a collection does not produce the correct result",
            function () {
                $assets = new Manager();

                $assets->useImplicitOutput(false);
                $assets->collection('js')
                    ->addJs(PATH_DATA. 'assets/jquery.js', false, false)
                    ->setTargetPath(PATH_OUTPUT . "tests/assets/combined.js")
                    ->setTargetUri('production/combined.js');

                $expected = sprintf(
                    '<script type="text/javascript" src="%s"></script>%s',
                    PATH_DATA. 'assets/jquery.js',
                    PHP_EOL
                );

                expect($assets->outputJs('js'))->equals($expected);
            }
        );
    }

    /**
     * Tests output with enabled join
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-01-24
     */
    public function testOutputWithEnabledJoin()
    {
        $this->specify(
            "The outputJs using a collection and with enabled join does not produce the correct result",
            function () {
                $assets = new Manager();

                $assets->useImplicitOutput(false);
                $assets->collection('js')
                    ->addJs(PATH_DATA. 'assets/jquery.js', false, false)
                    ->setTargetPath(PATH_OUTPUT . "tests/assets/combined.js")
                    ->setTargetUri('production/combined.js')
                    ->join(true);

                $expected = sprintf(
                    '<script type="text/javascript" src="%s"></script>%s',
                    PATH_DATA. 'assets/jquery.js',
                    PHP_EOL
                );

                expect($assets->outputJs('js'))->equals($expected);
            }
        );
    }

    /**
     * Tests output with disabled join
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-01-24
     */
    public function testOutputWithDisabledJoin()
    {
        $this->specify(
            "The outputJs using a collection and with disabled join does not produce the correct result",
            function () {
                $assets = new Manager();

                $assets->useImplicitOutput(false);
                $assets->collection('js')
                    ->addJs(PATH_DATA. 'assets/jquery.js', false, false)
                    ->setTargetPath(PATH_OUTPUT . "tests/assets/combined.js")
                    ->setTargetUri('production/combined.js')
                    ->join(false);

                $expected = sprintf(
                    '<script type="text/javascript" src="%s"></script>%s',
                    PATH_DATA. 'assets/jquery.js',
                    PHP_EOL
                );

                expect($assets->outputJs('js'))->equals($expected);
            }
        );
    }

    /**
     * Tests output with disabled join
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-01-24
     */
    public function testOutputWithJoinAndFilter()
    {
        $this->specify(
            "The outputJs using a collection and with enabled join and filter does not produce the correct result",
            function () {
                $assets = new Manager();

                $assets->useImplicitOutput(false);
                $assets->collection('js')
                    ->addJs(PATH_DATA. 'assets/jquery.js', false, false)
                    ->setTargetPath(PATH_OUTPUT . "tests/assets/combined.js")
                    ->setTargetUri('production/combined.js')
                    ->join(false)
                    ->addFilter(new None());

                $expected = sprintf(
                    '<script type="text/javascript" src="%s"></script>%s',
                    PATH_DATA. 'assets/jquery.js',
                    PHP_EOL
                );

                expect($assets->outputJs('js'))->equals($expected);
            }
        );
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
    public function doNotAddTheSameRecources()
    {
        $this->specify(
            "The assets collection incorrectly stores resources",
            function () {
                $assets = new Manager();

                for ($i = 0; $i < 10; $i++) {
                    $assets
                        ->addCss('css/style.css')
                        ->addJs('script.js');
                }

                expect($assets->getCss())->count(1);
                expect($assets->getJs())->count(1);

                for ($i = 0; $i < 2; $i++) {
                    $assets
                        ->addCss('style_' . $i . '.css')
                        ->addJs('script_' . $i . '.js');
                }

                expect($assets->getCss())->count(3);
                expect($assets->getJs())->count(3);
            }
        );
    }
}
