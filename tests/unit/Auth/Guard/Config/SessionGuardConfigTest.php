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

namespace Phalcon\Tests\Unit\Auth\Guard\Config;

use Phalcon\Auth\Exception;
use Phalcon\Auth\Guard\Config\SessionGuardConfig;
use Phalcon\Tests\AbstractUnitTestCase;

final class SessionGuardConfigTest extends AbstractUnitTestCase
{
    public function testCollidingNamesThrow(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessageMatches('/must differ/');

        new SessionGuardConfig(name: 'x', rememberName: 'x');
    }

    public function testDefaultsBuildAuthAndRemember(): void
    {
        $config = new SessionGuardConfig();

        $this->assertSame('auth', $config->getName());
        $this->assertSame('remember', $config->getRememberName());
    }

    public function testEmptyNameThrows(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessageMatches('/name/');

        new SessionGuardConfig(name: '');
    }

    public function testEmptyRememberNameThrows(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessageMatches('/rememberName/');

        new SessionGuardConfig(rememberName: '');
    }

    public function testEmptySuffixThrows(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessageMatches('/suffix/');

        new SessionGuardConfig('');
    }

    public function testNameOverrideWinsOverSuffix(): void
    {
        $config = new SessionGuardConfig('web', name: 'foo');

        $this->assertSame('foo', $config->getName());
        $this->assertSame('remember_web', $config->getRememberName());
    }

    public function testRememberNameOverrideWinsOverSuffix(): void
    {
        $config = new SessionGuardConfig('web', rememberName: 'rmem');

        $this->assertSame('auth_web', $config->getName());
        $this->assertSame('rmem', $config->getRememberName());
    }

    public function testSuffixDerivesBothNames(): void
    {
        $config = new SessionGuardConfig('web');

        $this->assertSame('auth_web', $config->getName());
        $this->assertSame('remember_web', $config->getRememberName());
    }
}
