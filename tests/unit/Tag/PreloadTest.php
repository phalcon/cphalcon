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

use Phalcon\Http\Response;
use Phalcon\Tag;

use function array_keys;

/**
 * Covers Tag::preload(), which returns the element it was handed and, as a
 * side effect, adds a `Link` header to the response.
 *
 * The header is only added when the container carries a `response` service;
 * without one the helper is a pass-through. The `as` attribute defaults to
 * "style" both when it is missing and when the second parameter is not an
 * array at all.
 */
final class PreloadTest extends AbstractTagTestCase
{
    public function testPreloadDefaultsTheAttributesWhenNotAnArray(): void
    {
        $response = $this->registerResponse();

        Tag::preload(['css/style.css', 'not-an-array']);

        $this->assertSame(
            ['Link: <css/style.css>; rel="preload"; as="style"'],
            array_keys($response->getHeaders()->toArray())
        );
    }

    public function testPreloadReturnsTheElement(): void
    {
        $this->registerResponse();

        $this->assertSame('css/style.css', Tag::preload('css/style.css'));
    }

    public function testPreloadSetsTheLinkHeader(): void
    {
        $response = $this->registerResponse();

        Tag::preload('css/style.css');

        $this->assertSame(
            ['Link: <css/style.css>; rel="preload"; as="style"'],
            array_keys($response->getHeaders()->toArray())
        );
    }

    public function testPreloadStripsSingleQuotesFromTheElement(): void
    {
        $response = $this->registerResponse();

        $this->assertSame("'css/style.css'", Tag::preload("'css/style.css'"));
        $this->assertSame(
            ['Link: <css/style.css>; rel="preload"; as="style"'],
            array_keys($response->getHeaders()->toArray())
        );
    }

    public function testPreloadUsesTheProvidedAttributes(): void
    {
        $response = $this->registerResponse();

        Tag::preload(['js/app.js', ['as' => 'script']]);

        $this->assertSame(
            ['Link: <js/app.js>; rel="preload"; as="script"'],
            array_keys($response->getHeaders()->toArray())
        );
    }

    public function testPreloadWithoutAResponseServiceIsAPassThrough(): void
    {
        $this->assertFalse(Tag::getDI()->has('response'));
        $this->assertSame('css/style.css', Tag::preload('css/style.css'));
    }

    private function registerResponse(): Response
    {
        $response = new Response();

        $container = $this->newContainer();
        $container->setShared('response', $response);

        Tag::setDI($container);

        return $response;
    }
}
