<?php

namespace Phalcon\Test\Unit\Assets;

use Phalcon\Test\Proxy\Assets\Manager;
use Phalcon\Test\Module\UnitTest;
use Phalcon\Assets\Resource\Js;
use Phalcon\Assets\Resource\Css;
use Phalcon\Assets\Filters\Jsmin;
use Phalcon\Assets\Filters\None;

/**
 * \Phalcon\Test\Unit\Assets\ManagerTest
 * Tests the \Phalcon\Assets\Manager component
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Unit\Assets
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class ManagerTest extends UnitTest
{
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
     * Tests setting local target
     *
     * @issue  1532
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
     * exists tests
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-03-16
     */
    public function testAssetsExistsCollection()
    {
        $this->specify(
            "The exists method in assets does not return correct value",
            function () {

                $assets = new Manager();

                $assets->collection('footer')
                    ->addCss('/css/style1.css');

                $footer = $assets->exists('footer');
                $header = $assets->exists('header');

                expect($footer)->true();
                expect($header)->false();
            }
        );
    }
}
