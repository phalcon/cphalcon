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

namespace Phalcon\Tests\Unit\Auth\Adapter;

use Phalcon\Auth\Adapter\Stream;
use Phalcon\Auth\Exception;
use Phalcon\Encryption\Security;
use Phalcon\Tests\AbstractUnitTestCase;

final class StreamFromOptionsTest extends AbstractUnitTestCase
{
    private Security $security;

    protected function setUp(): void
    {
        $this->security = new Security();
    }

    public function testFromOptionsBuildsStreamWithFile(): void
    {
        $adapter = Stream::fromOptions(
            $this->security,
            ['file' => '/some/path/users.json']
        );

        $this->assertInstanceOf(Stream::class, $adapter);
    }

    public function testFromOptionsThrowsWhenFileMissing(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessageMatches('/stream adapter/');

        Stream::fromOptions($this->security, []);
    }
}
