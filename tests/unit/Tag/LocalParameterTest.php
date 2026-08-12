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

namespace Phalcon\Tests\Unit\Tag;

use Phalcon\Di\Di;
use Phalcon\Mvc\Url;
use Phalcon\Tag;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use ReflectionProperty;

use const PHP_EOL;

/**
 * Characterizes how every `local` channel behaves on the current code base:
 *
 *  - the dedicated `$local` method argument
 *  - a positional index inside the `$parameters` array
 *  - a `"local"` key inside the `$parameters` array
 *
 * These assertions describe the CURRENT (pre-change) behavior so that the
 * impact of removing the array based `local` handling can be measured.
 */
final class LocalParameterTest extends AbstractUnitTestCase
{
    private const BASE = 'https://phalcon.io/';

    public function setUp(): void
    {
        $url = new Url();
        $url->setBaseUri(self::BASE);

        $container = new Di();
        $container->setShared('url', $url);

        Tag::setDI($container);
        Tag::setDocType(Tag::HTML5);
        Tag::setAutoescape(false);

        $this->setStaticProperty('urlService', null);
    }

    public function tearDown(): void
    {
        Tag::setAutoescape(true);
        Tag::setDocType(Tag::XHTML5);

        $this->setStaticProperty('urlService', null);
        $this->setStaticProperty('container', null);
    }

    public function testImageDefaultIsLocal(): void
    {
        $this->assertSame(
            '<img src="https://phalcon.io/img/logo.png">',
            Tag::image('img/logo.png')
        );
    }

    public function testImageMethodArgFalseArray(): void
    {
        $this->assertSame(
            '<img src="img/logo.png">',
            Tag::image(['img/logo.png'], false)
        );
    }

    public function testImageMethodArgFalseString(): void
    {
        $this->assertSame(
            '<img src="img/logo.png">',
            Tag::image('img/logo.png', false)
        );
    }

    public function testImagePositionalLocalFalse(): void
    {
        /**
         * `local` is read from the positional index 1 of the array.
         */
        $this->assertSame(
            '<img src="img/logo.png">',
            Tag::image(['img/logo.png', false])
        );
    }

    public function testJavascriptIncludeDefaultIsLocal(): void
    {
        $this->assertSame(
            '<script src="https://phalcon.io/js/app.js"></script>' . PHP_EOL,
            Tag::javascriptInclude('js/app.js')
        );
    }

    public function testJavascriptIncludeLocalKeyFalse(): void
    {
        /**
         * `local` is read from the "local" key, which is also removed from the
         * rendered attributes.
         */
        $this->assertSame(
            '<script src="js/app.js"></script>' . PHP_EOL,
            Tag::javascriptInclude(['src' => 'js/app.js', 'local' => false])
        );
    }

    public function testJavascriptIncludeMethodArgFalseArray(): void
    {
        $this->assertSame(
            '<script src="js/app.js"></script>' . PHP_EOL,
            Tag::javascriptInclude(['js/app.js'], false)
        );
    }

    public function testJavascriptIncludeMethodArgFalseString(): void
    {
        $this->assertSame(
            '<script src="js/app.js"></script>' . PHP_EOL,
            Tag::javascriptInclude('js/app.js', false)
        );
    }

    public function testJavascriptIncludePositionalLocalFalse(): void
    {
        /**
         * `local` is read from the positional index 1 of the array.
         */
        $this->assertSame(
            '<script src="js/app.js"></script>' . PHP_EOL,
            Tag::javascriptInclude(['js/app.js', false])
        );
    }

    public function testLinkToDefaultIsLocal(): void
    {
        $this->assertSame(
            '<a href="https://phalcon.io/admin/products">Products</a>',
            Tag::linkTo('admin/products', 'Products')
        );
    }

    public function testLinkToIgnoresEveryLocalChannel(): void
    {
        /**
         * None of the `local` channels reaches the generated URL. linkTo()
         * hands `local` to Url::get(), where the parameter cannot tell an
         * explicit false from an omitted argument, so it is always resolved
         * from the URI instead. The "local" key is still removed from the
         * rendered attributes.
         */
        $expected = '<a href="https://phalcon.io/admin/products">Products</a>';

        $this->assertSame(
            $expected,
            Tag::linkTo('admin/products', 'Products', false)
        );
        $this->assertSame(
            $expected,
            Tag::linkTo(['admin/products', 'Products', false])
        );
        $this->assertSame(
            $expected,
            Tag::linkTo(['admin/products', 'Products', 'local' => false])
        );
        $this->assertSame(
            $expected,
            Tag::linkTo(['admin/products', 'Products'], null, false)
        );
    }

    public function testStylesheetLinkDefaultIsLocal(): void
    {
        $this->assertSame(
            '<link rel="stylesheet" type="text/css" href="https://phalcon.io/css/style.css">' . PHP_EOL,
            Tag::stylesheetLink('css/style.css')
        );
    }

    public function testStylesheetLinkLocalKeyFalse(): void
    {
        /**
         * `local` is read from the "local" key, which is also removed from the
         * rendered attributes.
         */
        $this->assertSame(
            '<link rel="stylesheet" type="text/css" href="css/style.css">' . PHP_EOL,
            Tag::stylesheetLink(['href' => 'css/style.css', 'local' => false])
        );
    }

    public function testStylesheetLinkMethodArgFalseArray(): void
    {
        /**
         * For array input the `$local` method argument still applies, because
         * nothing in the array overrides it - the same as javascriptInclude().
         */
        $this->assertSame(
            '<link rel="stylesheet" type="text/css" href="css/style.css">' . PHP_EOL,
            Tag::stylesheetLink(['css/style.css'], false)
        );
    }

    public function testStylesheetLinkMethodArgFalseString(): void
    {
        $this->assertSame(
            '<link rel="stylesheet" type="text/css" href="css/style.css">' . PHP_EOL,
            Tag::stylesheetLink('css/style.css', false)
        );
    }

    public function testStylesheetLinkNull(): void
    {
        $this->assertSame(
            '<link rel="stylesheet" type="text/css" href="https://phalcon.io/">' . PHP_EOL,
            Tag::stylesheetLink()
        );
    }

    public function testStylesheetLinkPositionalLocalFalse(): void
    {
        /**
         * `local` is read from the positional index 1 of the array.
         */
        $this->assertSame(
            '<link rel="stylesheet" type="text/css" href="css/style.css">' . PHP_EOL,
            Tag::stylesheetLink(['css/style.css', false])
        );
    }

    private function setStaticProperty(string $property, mixed $value): void
    {
        $reflection = new ReflectionProperty(Tag::class, $property);
        $reflection->setValue(null, $value);
    }
}
