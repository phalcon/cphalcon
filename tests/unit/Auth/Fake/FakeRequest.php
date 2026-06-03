<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by sinbadxiii/cphalcon-auth
 * @link    https://github.com/sinbadxiii/cphalcon-auth
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Auth\Fake;

use Phalcon\Http\Request\FileInterface;
use Phalcon\Http\RequestInterface;

final class FakeRequest implements RequestInterface
{
    /**
     * @var array<string, mixed>
     */
    private array $query = [];

    /**
     * @var array<string, string>
     */
    private array $headers = [];

    /**
     * @var array<string, string>|null
     */
    private ?array $basicAuth = null;

    private string $userAgent = '';

    // -------------------------------------------------------------------------
    // Test helper setters
    // -------------------------------------------------------------------------

    public function setBasicAuthFake(?array $value): void
    {
        $this->basicAuth = $value;
    }

    public function setHeaderFake(string $key, string $value): void
    {
        $this->headers[$key] = $value;
    }

    public function setQueryFake(string $key, mixed $value): void
    {
        $this->query[$key] = $value;
    }

    public function setUserAgentFake(string $value): void
    {
        $this->userAgent = $value;
    }

    // -------------------------------------------------------------------------
    // RequestInterface — methods with real behaviour
    // -------------------------------------------------------------------------

    public function get(
        ?string $name = null,
        mixed $filters = null,
        mixed $defaultValue = null,
        bool $notAllowEmpty = false,
        bool $noRecursive = false
    ): mixed {
        if ($name === null) {
            return $this->query;
        }

        return $this->query[$name] ?? $defaultValue;
    }

    public function getBasicAuth(): ?array
    {
        return $this->basicAuth;
    }

    public function getHeader(string $header): string
    {
        return $this->headers[$header] ?? '';
    }

    public function getUserAgent(): string
    {
        return $this->userAgent;
    }

    // -------------------------------------------------------------------------
    // RequestInterface — stub methods (not needed by tests)
    // -------------------------------------------------------------------------

    public function getAcceptableContent(): array
    {
        throw new \LogicException('not implemented in test fake');
    }

    public function getBestAccept(): string
    {
        throw new \LogicException('not implemented in test fake');
    }

    public function getBestCharset(): string
    {
        throw new \LogicException('not implemented in test fake');
    }

    public function getBestLanguage(): string
    {
        throw new \LogicException('not implemented in test fake');
    }

    public function getClientAddress(bool $trustForwardedHeader = false): string|bool
    {
        throw new \LogicException('not implemented in test fake');
    }

    public function getClientCharsets(): array
    {
        throw new \LogicException('not implemented in test fake');
    }

    public function getContentType(): ?string
    {
        throw new \LogicException('not implemented in test fake');
    }

    public function getDigestAuth(): array
    {
        throw new \LogicException('not implemented in test fake');
    }

    public function getHeaders(): array
    {
        throw new \LogicException('not implemented in test fake');
    }

    public function getHttpHost(): string
    {
        throw new \LogicException('not implemented in test fake');
    }

    public function getHTTPReferer(): string
    {
        throw new \LogicException('not implemented in test fake');
    }

    public function getJsonRawBody(bool $associative = false): \stdClass|array|bool
    {
        throw new \LogicException('not implemented in test fake');
    }

    public function getLanguages(): array
    {
        throw new \LogicException('not implemented in test fake');
    }

    public function getMethod(): string
    {
        throw new \LogicException('not implemented in test fake');
    }

    public function getPort(): int
    {
        throw new \LogicException('not implemented in test fake');
    }

    public function getPost(
        ?string $name = null,
        mixed $filters = null,
        mixed $defaultValue = null,
        bool $notAllowEmpty = false,
        bool $noRecursive = false
    ): mixed {
        throw new \LogicException('not implemented in test fake');
    }

    public function getPut(
        ?string $name = null,
        mixed $filters = null,
        mixed $defaultValue = null,
        bool $notAllowEmpty = false,
        bool $noRecursive = false
    ): mixed {
        throw new \LogicException('not implemented in test fake');
    }

    public function getQuery(
        ?string $name = null,
        mixed $filters = null,
        mixed $defaultValue = null,
        bool $notAllowEmpty = false,
        bool $noRecursive = false
    ): mixed {
        throw new \LogicException('not implemented in test fake');
    }

    public function getRawBody(): string
    {
        throw new \LogicException('not implemented in test fake');
    }

    public function getScheme(): string
    {
        throw new \LogicException('not implemented in test fake');
    }

    public function getServer(string $name): ?string
    {
        throw new \LogicException('not implemented in test fake');
    }

    public function getServerAddress(): string
    {
        throw new \LogicException('not implemented in test fake');
    }

    public function getServerName(): string
    {
        throw new \LogicException('not implemented in test fake');
    }

    /**
     * @return FileInterface[]
     */
    public function getUploadedFiles(bool $onlySuccessful = false, bool $namedKeys = false): array
    {
        throw new \LogicException('not implemented in test fake');
    }

    public function getURI(bool $onlyPath = false): string
    {
        throw new \LogicException('not implemented in test fake');
    }

    public function has(string $name): bool
    {
        throw new \LogicException('not implemented in test fake');
    }

    public function hasFiles(): bool
    {
        throw new \LogicException('not implemented in test fake');
    }

    public function hasHeader(string $header): bool
    {
        throw new \LogicException('not implemented in test fake');
    }

    public function hasPost(string $name): bool
    {
        throw new \LogicException('not implemented in test fake');
    }

    public function hasPut(string $name): bool
    {
        throw new \LogicException('not implemented in test fake');
    }

    public function hasQuery(string $name): bool
    {
        throw new \LogicException('not implemented in test fake');
    }

    public function hasServer(string $name): bool
    {
        throw new \LogicException('not implemented in test fake');
    }

    public function isAjax(): bool
    {
        throw new \LogicException('not implemented in test fake');
    }

    public function isConnect(): bool
    {
        throw new \LogicException('not implemented in test fake');
    }

    public function isDelete(): bool
    {
        throw new \LogicException('not implemented in test fake');
    }

    public function isGet(): bool
    {
        throw new \LogicException('not implemented in test fake');
    }

    public function isHead(): bool
    {
        throw new \LogicException('not implemented in test fake');
    }

    public function isMethod(mixed $methods, bool $strict = false): bool
    {
        throw new \LogicException('not implemented in test fake');
    }

    public function isOptions(): bool
    {
        throw new \LogicException('not implemented in test fake');
    }

    public function isPost(): bool
    {
        throw new \LogicException('not implemented in test fake');
    }

    public function isPurge(): bool
    {
        throw new \LogicException('not implemented in test fake');
    }

    public function isPut(): bool
    {
        throw new \LogicException('not implemented in test fake');
    }

    public function isSecure(): bool
    {
        throw new \LogicException('not implemented in test fake');
    }

    public function isSoap(): bool
    {
        throw new \LogicException('not implemented in test fake');
    }

    public function isTrace(): bool
    {
        throw new \LogicException('not implemented in test fake');
    }

    public function numFiles(bool $onlySuccessful = false): int
    {
        throw new \LogicException('not implemented in test fake');
    }
}
