<?php
namespace Phalcon;
use Codeception\Util\Stub;

class TagTest extends \Codeception\TestCase\Test
{
   /**
    * @var \CodeGuy
    */
    protected $codeGuy;

    public function _before()
    {
        Tag::setDoctype('');
    }

    public function testDoctypeSet()
    {
        Tag::setDoctype(Tag::HTML5);
        expect(Tag::getDoctype(Tag::HTML5))->equals("<!DOCTYPE html>" . PHP_EOL);
    }
    public function testImageTag()
    {
        expect(
            Tag::image('img/hello.gif')
        )->equals('<img src="/img/hello.gif">');

        expect(Tag::image(array('img/hello.gif', 'class' => 'some_class'))
        )->equals('<img class="some_class" src="/img/hello.gif">');

        expect('image path can be redefined by src parameter',
            Tag::image(array('img/hello.gif', 'src'   => 'img/goodbye.gif', 'class' => 'some_class'))
        )->equals('<img src="/img/goodbye.gif" class="some_class">');
    }

    public function testImageTagWithXHTML()
    {
        Tag::setDoctype(Tag::XHTML10_STRICT);

        expect(
            Tag::image('img/hello.gif')
        )->equals('<img src="/img/hello.gif" />');

        expect(
            Tag::image(array('img/hello.gif', 'class' => 'some_class'))
        )->equals('<img class="some_class" src="/img/hello.gif" />');

        expect('image path can be redefined by src parameter',
            Tag::image(array('img/hello.gif', 'src'   => 'img/goodbye.gif', 'class' => 'some_class'))
        )->equals('<img src="/img/goodbye.gif" class="some_class" />');
    }

    public function testStylesheet()
    {
        expect(
            Tag::stylesheetLink('css/phalcon.css')
        )->equals('<link rel="stylesheet" href="/css/phalcon.css" type="text/css">' . PHP_EOL);

        expect("stylesheet with array link is local",
            Tag::stylesheetLink(array('css/phalcon.css'))
        )->equals('<link rel="stylesheet" href="css/phalcon.css" type="text/css">' . PHP_EOL);

        expect("stylesheet is local when second parameter set",
            Tag::stylesheetLink(array('css/phalcon.css'), 'hello')
        )->equals('<link rel="stylesheet" href="css/phalcon.css" type="text/css">' . PHP_EOL);

        expect(
            Tag::stylesheetLink('http://fonts.googleapis.com/css?family=Rosario')
        )->equals('<link rel="stylesheet" href="http://fonts.googleapis.com/css?family=Rosario" type="text/css">' . PHP_EOL);

        expect(
            Tag::stylesheetLink(array('http://fonts.googleapis.com/css?family=Rosario'))
        )->equals('<link rel="stylesheet" href="http://fonts.googleapis.com/css?family=Rosario" type="text/css">' . PHP_EOL);

        expect("stylesheet is still remote even when second parameter set",
            Tag::stylesheetLink('http://fonts.googleapis.com/css?family=Rosario', '0')
        )->equals('<link rel="stylesheet" href="http://fonts.googleapis.com/css?family=Rosario" type="text/css">' . PHP_EOL);

    }


    public function testStylesheetWithXHTML()
    {
        Tag::setDoctype(Tag::XHTML10_STRICT);

        expect(
            Tag::stylesheetLink('css/phalcon.css')
        )->equals('<link rel="stylesheet" href="/css/phalcon.css" type="text/css" />' . PHP_EOL);

        expect("stylesheet with array link is local",
            Tag::stylesheetLink(array('css/phalcon.css'))
        )->equals('<link rel="stylesheet" href="css/phalcon.css" type="text/css" />' . PHP_EOL);

        expect("stylesheet is local when second parameter set",
            Tag::stylesheetLink(array('css/phalcon.css'), 'hello')
        )->equals('<link rel="stylesheet" href="css/phalcon.css" type="text/css" />' . PHP_EOL);

        expect(
            Tag::stylesheetLink('http://fonts.googleapis.com/css?family=Rosario')
        )->equals('<link rel="stylesheet" href="http://fonts.googleapis.com/css?family=Rosario" type="text/css" />' . PHP_EOL);

        expect(
            Tag::stylesheetLink(array('http://fonts.googleapis.com/css?family=Rosario'))
        )->equals('<link rel="stylesheet" href="http://fonts.googleapis.com/css?family=Rosario" type="text/css" />' . PHP_EOL);

        expect("stylesheet is still remote even when second parameter set",
            Tag::stylesheetLink('http://fonts.googleapis.com/css?family=Rosario', '0')
        )->equals('<link rel="stylesheet" href="http://fonts.googleapis.com/css?family=Rosario" type="text/css" />' . PHP_EOL);

    }

    public function testJavascriptInclude()
    {
        expect(
            Tag::javascriptInclude('js/phalcon.js')
        )->equals('<script src="/js/phalcon.js" type="text/javascript"></script>' . PHP_EOL);

        expect("script with array link is local",
            Tag::javascriptInclude(array('js/phalcon.js'))
        )->equals('<script src="js/phalcon.js" type="text/javascript"></script>' . PHP_EOL);

        expect(
            Tag::javascriptInclude('js/phalcon.js', 'hello')
        )->equals('<script src="/js/phalcon.js" type="text/javascript"></script>' . PHP_EOL);

        expect(
            Tag::javascriptInclude('http://my.local.com/js/phalcon.js', false)
        )->equals('<script src="http://my.local.com/js/phalcon.js" type="text/javascript"></script>' . PHP_EOL);

        expect(
            Tag::javascriptInclude(array('http://my.local.com/js/phalcon.js'), false)
        )->equals('<script src="http://my.local.com/js/phalcon.js" type="text/javascript"></script>' . PHP_EOL);

        expect('remote link even with second parameter',
            Tag::javascriptInclude(array('http://my.local.com/js/phalcon.js'), '0')
        )->equals('<script src="http://my.local.com/js/phalcon.js" type="text/javascript"></script>' . PHP_EOL);
    }

    public function testJavascriptIncludeWithXHTML()
    {
        Tag::setDoctype(Tag::XHTML10_STRICT);

        expect(
            Tag::javascriptInclude('js/phalcon.js')
        )->equals('<script src="/js/phalcon.js" type="text/javascript"></script>' . PHP_EOL);

        expect("script with array link is local",
            Tag::javascriptInclude(array('js/phalcon.js'))
        )->equals('<script src="js/phalcon.js" type="text/javascript"></script>' . PHP_EOL);

        expect(
            Tag::javascriptInclude('js/phalcon.js', 'hello')
        )->equals('<script src="/js/phalcon.js" type="text/javascript"></script>' . PHP_EOL);

        expect(
            Tag::javascriptInclude('http://my.local.com/js/phalcon.js', false)
        )->equals('<script src="http://my.local.com/js/phalcon.js" type="text/javascript"></script>' . PHP_EOL);

        expect(
            Tag::javascriptInclude(array('http://my.local.com/js/phalcon.js'), false)
        )->equals('<script src="http://my.local.com/js/phalcon.js" type="text/javascript"></script>' . PHP_EOL);

        expect('remote link even with second parameter',
            Tag::javascriptInclude(array('http://my.local.com/js/phalcon.js'), '0')
        )->equals('<script src="http://my.local.com/js/phalcon.js" type="text/javascript"></script>' . PHP_EOL);
    }
    // TODO: port all tests from Tag\UnitTest.php

}