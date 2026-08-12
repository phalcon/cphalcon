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

namespace Phalcon\Tests\Unit\Tag\Fake;

use Phalcon\Mvc\Url\UrlInterface;

use function implode;
use function is_array;

/**
 * A `url` service that satisfies UrlInterface and nothing more.
 *
 * `getStatic()` is absent from the interface, so Tag has to fall back to
 * `get()` when resolving an asset URL. Only a service without the method
 * reaches that fallback - Phalcon\Mvc\Url carries it.
 */
final class FakeUrl implements UrlInterface
{
    private string $basePath = '';
    private string $baseUri  = '';

    public function get(
        mixed $uri = null,
        mixed $arguments = null,
        bool | null $local = null,
        mixed $baseUri = null,
        bool $replaceArgs = false
    ): string {
        $path = is_array($uri) ? implode('/', $uri) : (string) $uri;

        return $this->baseUri . $path;
    }

    public function getBasePath(): string | null
    {
        return $this->basePath;
    }

    public function getBaseUri(): string
    {
        return $this->baseUri;
    }

    public function path(string | null $path = null): string
    {
        return $this->basePath . (string) $path;
    }

    public function setBasePath(string $basePath): UrlInterface
    {
        $this->basePath = $basePath;

        return $this;
    }

    public function setBaseUri(string $baseUri): UrlInterface
    {
        $this->baseUri = $baseUri;

        return $this;
    }
}
