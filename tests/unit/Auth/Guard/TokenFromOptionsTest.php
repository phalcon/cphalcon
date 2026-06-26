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

namespace Phalcon\Tests\Unit\Auth\Guard;

use Phalcon\Auth\Adapter\Config\MemoryAdapterConfig;
use Phalcon\Auth\Adapter\Memory;
use Phalcon\Auth\Exception;
use Phalcon\Auth\Guard\Token;
use Phalcon\Container\Container;
use Phalcon\Container\Exceptions\Exception as ContainerException;
use Phalcon\Di\Di;
use Phalcon\Encryption\Security;
use Phalcon\Http\RequestInterface;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Auth\Fake\FakeRequest;

final class TokenFromOptionsTest extends AbstractUnitTestCase
{
    private Memory $adapter;
    private Container $container;

    protected function setUp(): void
    {
        $this->adapter = new Memory(
            new Security(),
            new MemoryAdapterConfig([])
        );

        $this->container = new Container();
        $this->container->set(RequestInterface::class, fn () => new FakeRequest());
    }

    public function testFromOptionsBuildsTokenWithKeys(): void
    {
        $guard = Token::fromOptions(
            $this->adapter,
            $this->container,
            [
                'inputKey'   => 'api_token',
                'storageKey' => 'api_token',
            ]
        );

        $this->assertInstanceOf(Token::class, $guard);
    }

    public function testFromOptionsFallsBackToShortNameRequest(): void
    {
        $di = new Di();
        $di->set('request', fn () => new FakeRequest());

        $guard = Token::fromOptions(
            $this->adapter,
            $di,
            [
                'inputKey'   => 'api_token',
                'storageKey' => 'api_token',
            ]
        );

        $this->assertInstanceOf(Token::class, $guard);
    }

    public function testFromOptionsThrowsWhenInputKeyMissing(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessageMatches('/token guard.*inputKey/');

        Token::fromOptions(
            $this->adapter,
            $this->container,
            ['storageKey' => 'api_token']
        );
    }

    public function testFromOptionsThrowsWhenRequestMissing(): void
    {
        $this->expectException(ContainerException::class);
        $this->expectExceptionMessageMatches('/Token guard requires service/');

        Token::fromOptions(
            $this->adapter,
            new Container(),
            [
                'inputKey'   => 'api_token',
                'storageKey' => 'api_token',
            ]
        );
    }
}
