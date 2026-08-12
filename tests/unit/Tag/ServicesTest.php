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
use Phalcon\Html\Escaper;
use Phalcon\Html\Escaper\EscaperInterface;
use Phalcon\Mvc\Url;
use Phalcon\Mvc\Url\UrlInterface;
use Phalcon\Tag;
use Phalcon\Tests\Unit\Tag\Fake\FakeUrl;

/**
 * Covers how Tag reaches the container and the two services it resolves from
 * it, including the caching that makes the second call cheap.
 */
final class ServicesTest extends AbstractTagTestCase
{
    public function testGetDiFallsBackToTheDefaultContainer(): void
    {
        Di::reset();

        $this->setProtectedProperty(Tag::class, 'container', null);

        $container = new Di();

        $this->assertSame($container, Tag::getDI());
    }

    public function testGetDiReturnsTheAssignedContainer(): void
    {
        $container = new Di();

        Tag::setDI($container);

        $this->assertSame($container, Tag::getDI());
    }

    public function testGetEscaperReturnsNullWhenAutoescapeIsOff(): void
    {
        Tag::setAutoescape(false);

        $this->assertNull(Tag::getEscaper([]));
    }

    public function testGetEscaperReturnsNullWhenEscapeIsFalse(): void
    {
        Tag::setAutoescape(true);

        $this->assertNull(Tag::getEscaper(['escape' => false]));
    }

    public function testGetEscaperReturnsTheServiceWhenAutoescapeIsOn(): void
    {
        Tag::setAutoescape(true);

        $this->assertInstanceOf(EscaperInterface::class, Tag::getEscaper([]));
    }

    public function testGetEscaperReturnsTheServiceWhenEscapeIsTrue(): void
    {
        Tag::setAutoescape(false);

        $this->assertInstanceOf(
            EscaperInterface::class,
            Tag::getEscaper(['escape' => true])
        );
    }

    public function testGetEscaperServiceIsResolvedOnce(): void
    {
        $escaper = new Escaper();

        $container = new Di();
        $container->setShared('escaper', $escaper);

        Tag::setDI($container);

        $this->assertSame($escaper, Tag::getEscaperService());
        $this->assertSame($escaper, Tag::getEscaperService());
    }

    public function testGetUrlServiceIsResolvedOnce(): void
    {
        $url = new Url();

        $container = new Di();
        $container->setShared('url', $url);

        Tag::setDI($container);

        $this->assertSame($url, Tag::getUrlService());
        $this->assertSame($url, Tag::getUrlService());
    }

    public function testStaticUrlCastsANonStringUri(): void
    {
        $this->assertSame(
            '<img src="https://phalcon.io/42">',
            Tag::image(['src' => 42])
        );
    }

    public function testStaticUrlFallsBackToGetWithoutGetStatic(): void
    {
        $url = new FakeUrl();
        $url->setBaseUri(self::BASE_URI);

        $container = new Di();
        $container->setShared('url', $url);

        Tag::setDI($container);

        $this->assertInstanceOf(UrlInterface::class, Tag::getUrlService());
        $this->assertSame(
            '<img src="https://phalcon.io/img/logo.png">',
            Tag::image('img/logo.png')
        );
    }
}
