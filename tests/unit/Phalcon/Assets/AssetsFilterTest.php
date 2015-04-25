<?php
/**
 * AssetsFilterTest.php
 * \Phalcon\Resource\AssetsFilterTest
 *
 * Tests the Phalcon\Assets\Filter component
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

use \Phalcon\Assets\Exception as PhAssetsException;

use \PhalconTest\Assets\Manager as PhTAssetsManager;
use \PhalconTest\Assets\Filters\Cssmin as PhTFilterCssmin;
use \PhalconTest\Assets\Filters\None as PhTFilterNone;

use \Phalcon\Tests\unit\Phalcon\_Helper\TestsBase as TBase;

class AssetsFilterTest extends TBase
{
    /**
     * Tests cssmin filter with empty parameters
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-10
     */
    public function testAssetsFilterCssmin()
    {
        $this->specify(
            "The cssmin filter needs a string parameter",
            function () {

                $cssmin = new PhTFilterCssmin();
                try {
                    $actual = $cssmin->filter(null);
                } catch (\Exception $e) {
                    $actual   = $e->getMessage();
                    $expected = 'Style must by a string';
                    expect($actual)->equals($expected);
                }
            }
        );

        $this->specify(
            "The cssmin filter with empty parameter does not return empty back",
            function () {

                $cssmin = new PhTFilterCssmin();
                $actual = $cssmin->filter('');
                expect($actual)->isEmpty();
            }
        );

        $this->specify(
            "The cssmin filter with space as parameter does not return correct results",
            function () {

                $cssmin   = new PhTFilterCssmin();
                $actual   = $cssmin->filter(' ');
                $expected = ' ';
                expect($actual)->equals($expected);
            }
        );

        $this->specify(
            "The cssmin filter with brackets does not return correct results",
            function () {

                $cssmin   = new PhTFilterCssmin();
                $actual   = $cssmin->filter('{}}');
                $expected = '{}}';
                expect($actual)->equals($expected);
            }
        );

        $this->specify(
            "The cssmin filter with brackets and spaces does not return correct results",
            function () {

                $cssmin   = new PhTFilterCssmin();
                $actual   = $cssmin->filter('.s { d     :        b; }');
                $expected = '.s{d : b;}';
                expect($actual)->equals($expected);
            }
        );

        $this->specify(
            "The cssmin filter with proper CSS does not compress the contents",
            function () {

                $cssmin   = new PhTFilterCssmin();
                $source   = ".social-link {display: inline-block; width: 44px; "
                          . "height: 44px; text-align: left; text-indent: "
                          . "-9999px; overflow: hidden; background: "
                          . "url('../images/social-links.png'); }";
                $actual   = $cssmin->filter($source);
                $expected = ".social-link{display: inline-block;width: 44px;"
                          . "height: 44px;text-align: left;text-indent: "
                          . "-9999px;overflow: hidden;background: "
                          . "url('../images/social-links.png');}";
                expect($actual)->equals($expected);
            }
        );

        $this->specify(
            "The cssmin filter with a lot of spaces does not compress the contents",
            function () {

                $cssmin   = new PhTFilterCssmin();
                $source   = "h2:after         { border-width:         1px; }";
                $actual   = $cssmin->filter($source);
                $expected = "h2:after{border-width: 1px;}";
                expect($actual)->equals($expected);
            }
        );

        $this->specify(
            "The cssmin filter with complex CSS does not compress the contents",
            function () {

                $cssmin   = new PhTFilterCssmin();
                $source   = "h1 > p { font-family: 'Helvetica Neue'; }";
                $actual   = $cssmin->filter($source);
                $expected = "h1> p{font-family: 'Helvetica Neue';}";
                expect($actual)->equals($expected);
            }
        );

        $this->specify(
            "The cssmin filter with complex CSS does not compress the contents",
            function () {

                $cssmin   = new PhTFilterCssmin();
                $source   = "h1 > p { font-family: 'Helvetica Neue'; }";
                $actual   = $cssmin->filter($source);
                $expected = "h1> p{font-family: 'Helvetica Neue';}";
                expect($actual)->equals($expected);
            }
        );

        $this->specify(
            "The cssmin filter with complex nested CSS does not compress the contents",
            function () {

                $cssmin   = new PhTFilterCssmin();
                $source   = ".navbar .nav>li>a { color: #111; "
                          . "text-decoration: underline; }";
                $actual   = $cssmin->filter($source);
                $expected = ".navbar .nav>li>a{color: #111;"
                          . "text-decoration: underline;}";
                expect($actual)->equals($expected);
            }
        );

        $this->specify(
            "The cssmin filter with complex CSS (line breaks) does not compress the contents",
            function () {

                $cssmin   = new PhTFilterCssmin();
                $sourceFile = PATH_DATA . '/assets/cssmin-01.css';
                $targetFile = PATH_DATA . '/assets/cssmin-01-result.css';

                if (!file_exists($sourceFile) || !file_exists($targetFile)) {
                    $this->markTestIncomplete('Source files missing for this test');
                }

                $source   = file_get_contents($sourceFile);
                $expected = file_get_contents($targetFile);
                $actual   = $cssmin->filter($source);

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests none filter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-10
     */
    public function testAssetsFilterNone()
    {
        $this->specify(
            "The none filter does not return the correct results",
            function () {

                $cssmin   = new PhTFilterNone();
                $actual   = $cssmin->filter(' ');
                $expected = ' ';
                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests none filter
     *
     * @issue   1198
     * @author  Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since   2014-10-10
     */
    public function testAssetsFilterChainCustomFilterWithCssmin()
    {
        $this->markTestSkipped('To be tested');
        $this->specify(
            "The chaining a custom filter with cssmin does not return the correct results",
            function () {

                $fileName = newFileName('assets_', 'css');
                $this->prepareDI();

                $assets = new PhTAssetsManager();
                $assets->useImplicitOutput(false);
                $css = $assets->collection('css');

                $css->setTargetPath(PATH_CACHE . $fileName);
                $css->addCss(PATH_DATA . '/assets/1198.css');
                $css->addFilter(new Helper\UppercaseFilter());
                $css->addFilter(new Helper\TrimFilter());
                $css->join(true);
                $assets->outputCss('css');

                $expected = 'A{TEXT-DECORATION:NONE;}B{FONT-WEIGHT:BOLD;}';
                $actual   = file_get_contents(PATH_CACHE . $fileName);

                cleanFile(PATH_CACHE, $fileName);

                expect($actual)->equals($expected);
            }
        );
    }

    public function testFilterSimpleNoJoin()
    {
        $this->markTestSkipped('To be tested');
        $this->specify(
            "The simple filter without join does not return the correct results",
            function () {

                $fileName = newFileName('assets_', 'js');

                $this->prepareDI(true);

                $assets = new PhTAssetsManager();

                $assets->useImplicitOutput(false);
                $js = $assets->collection('js');

                $js->setTargetPath(PATH_CACHE . $fileName);
                $js->setTargetUri('production/combined.js');
                $js->addJs('assets/assets-multiple-01.js', false, false);

                $actual   = $assets->outputJs('js');
                $expected = '<script type="text/javascript" '
                          . 'src="assets/assets-multiple-01.js"></script>'
                          . PHP_EOL;

                expect($actual)->equals($expected);
            }
        );

	//Enabling join
	$js->join(true);
	$this->assertEquals(
		$assets->outputJs('js'),
		'<script type="text/javascript" src="unit-tests/assets/jquery.js"></script>' . 
		PHP_EOL
	);

	//Disabling join
	$js->join(false);
	$this->assertEquals(
		$assets->outputJs('js'),
		'<script type="text/javascript" src="unit-tests/assets/jquery.js"></script>' .
		PHP_EOL
	);

	//Filter - Join
	$js->join(false);
	$js->addFilter(new Phalcon\Assets\Filters\None());
	$this->assertEquals(
		$assets->outputJs('js'),
		'<script type="text/javascript" src="/unit-tests/assets/jquery.js"></script>' .
		PHP_EOL
	);
    }

    public function testFilterSimpleJoin()
    {
        $this->markTestIncomplete('To be checked');
        @unlink('unit-tests/assets/production/combined.js');

        Phalcon\DI::reset();

        $di = new Phalcon\DI();

        $di['url'] = function () {
            $url = new Phalcon\Mvc\Url();
            $url->setStaticBaseUri('/');
            return $url;
        };

        $di->set(
            'escaper',
            function () {
                return new \Phalcon\Escaper();
            }
        );

        $assets = new PhTAssetsManager();

        $assets->useImplicitOutput(false);

        $js = $assets->collection('js');

        $js->setTargetPath('unit-tests/assets/production/combined.js');

        $js->setTargetUri('production/combined.js');

        $js->addJs('unit-tests/assets/jquery.js', false, false);

        //Basic output
        $this->assertEquals(
            $assets->outputJs('js'),
            '<script type="text/javascript" src="unit-tests/assets/jquery.js"></script>' .
            PHP_EOL
        );

        //Enabling join
        $js->join(true);
        $this->assertEquals(
            $assets->outputJs('js'),
            '<script type="text/javascript" src="unit-tests/assets/jquery.js"></script>' .
            PHP_EOL
        );

        //Disabling join
        $js->join(false);
        $this->assertEquals(
            $assets->outputJs('js'),
            '<script type="text/javascript" src="unit-tests/assets/jquery.js"></script>' .
            PHP_EOL
        );

        //Filter + Join
        $js->join(true);
        $js->addFilter(new Phalcon\Assets\Filters\None());
        $this->assertEquals(
            $assets->outputJs('js'),
            '<script type="text/javascript" src="/production/combined.js"></script>' .
            PHP_EOL
        );
    }


    public function testIssue1532()
    {
        $this->markTestIncomplete('To be checked');
        @unlink(__DIR__ . '/assets/production/1532.js');
        $di = new \Phalcon\DI\FactoryDefault();
        $assets = new \PhTAssetsManager();
        $assets->useImplicitOutput(false);
        $assets->collection('js')
            ->addJs('unit-tests/assets/jquery.js')
            ->join(true)
            ->addFilter(new Phalcon\Assets\Filters\Jsmin())
            ->setTargetPath(__DIR__ .'/assets/production/1532.js')
            ->setTargetLocal(false)
            ->setPrefix('//phalconphp.com/')
            ->setTargetUri('js/jquery.js');

        $this->assertEquals(
            $assets->outputJs('js'),
            '<script type="text/javascript" src="//phalconphp.com/js/jquery.js"></script>' .
            PHP_EOL
        );
    }

    public function testJsminFilter()
    {
        $this->markTestIncomplete('To be checked');
        $jsmin = new Phalcon\Assets\Filters\Jsmin();

        try {
            $filtered = $jsmin->filter(null);
        } catch (Exception $e) {
            $this->assertEquals($e->getMessage(), 'Script must be a string');
        }

        try {
            $filtered = $jsmin->filter('/*');
        } catch (Exception $e) {
            $this->assertEquals($e->getMessage(), 'Unterminated comment.');
        }

        try {
            $filtered = $jsmin->filter('a = "');
        } catch (Exception $e) {
            $this->assertEquals($e->getMessage(), 'Unterminated string literal.');
        }

        try {
            $filtered = $jsmin->filter('b = /[a-z]+');
        } catch (Exception $e) {
            $this->assertEquals($e->getMessage(), 'Unterminated Regular Expression literal.');
        }

        $filtered = $jsmin->filter('');
        $this->assertEquals($filtered, '');

        $filtered = $jsmin->filter('{}}');
        $this->assertEquals($filtered, "\n" . '{}}');

        $filtered = $jsmin->filter('if ( a == b ) {    document . writeln("hello") ; }');
        $this->assertEquals($filtered, "\n" . 'if(a==b){document.writeln("hello");}');

        $filtered = $jsmin->filter("if ( a == b ) {    document . writeln('\t') ; }");
        $this->assertEquals($filtered, "\n" . "if(a==b){document.writeln('\t');}");

        $filtered = $jsmin->filter(
            "/** this is a comment */ if ( a == b ) {    document . writeln('\t') ; /** this is a comment */ }"
        );
        $this->assertEquals($filtered, "\n" . "if(a==b){document.writeln('\t');}");

        $filtered = $jsmin->filter("\t\ta\t\r\n= \n \r\n100;\t");
        $this->assertEquals($filtered, "\n" . 'a=100;');
    }
}
